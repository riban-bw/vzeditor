#include "envelopeeditor.h"

wxDEFINE_EVENT(wxEVT_ENVED, wxCommandEvent);

BEGIN_EVENT_TABLE(EnvelopeEditor, wxScrolledWindow)
    EVT_PAINT       (EnvelopeEditor::OnPaint)
    EVT_LEFT_DOWN   (EnvelopeEditor::OnLeftDown)
    EVT_LEFT_UP     (EnvelopeEditor::OnLeftUp)
    EVT_MOTION      (EnvelopeEditor::OnMouseMotion)
    EVT_SIZE        (EnvelopeEditor::OnSize)
    EVT_LEFT_DCLICK (EnvelopeEditor::OnLeftDoubleClick)
END_EVENT_TABLE()

static const int NODE_RADIUS = 4;
static const int MAX_RATE = 80; //quantity of seconds for maximum fade

EnvelopeEditor::EnvelopeEditor(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, long style, const wxString& name) :
    wxScrolledWindow(parent, winid, pos, size, style, name),
    m_nSelectedNode(-1),
    m_nStyle(style)
{
    SetMinY(0);
    SetMaxY(0x7F);
    switch(style)
    {
        case ENV_STYLE_DCA_ENV:
            m_nMaxNodes = 8;
            break;
        case ENV_STYLE_DCA_KF:
            m_nMaxNodes = 6;
            break;
        case ENV_STYLE_DCO_ENV:
            m_nMaxNodes = 8;
            break;
        case ENV_STYLE_DCO_KF:
            m_nMaxNodes = 6;
            break;
    }
}

EnvelopeEditor::~EnvelopeEditor()
{
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
        delete m_vNodes[nNode];
}

void EnvelopeEditor::PlotEnvelope(wxDC& dc)
{
    //!@todo Add sustain level
    //!@todo Add Velocity position (additional parameter for each node)

    wxPen pen1(*wxBLACK, 1);
    wxPen pen2(*wxGREEN, 2);
    dc.SetPen(pen1);
    int x = 0;
    int y = dc.GetSize().y;
    m_fScaleY = float(y) / m_nRange; //!@todo Put this in resize handler

    wxPoint ptLast(x, y); //x value is absoulte x postition, y value is level
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        x = m_vNodes[nNode]->GetPosition();
        y = m_fScaleY * (m_nMaxY - m_vNodes[nNode]->GetValue());
        dc.DrawLine(ptLast.x, ptLast.y, x,  y);
        ptLast = wxPoint(x, y);
    }
    dc.DrawLine(ptLast.x, ptLast.y, dc.GetSize().x, y);

    ptLast = wxPoint(0, 0);
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        x = m_vNodes[nNode]->GetPosition();
        y = m_fScaleY * (m_nMaxY - m_vNodes[nNode]->GetValue());
        dc.SetPen((m_nSelectedNode == (int)nNode)?pen2:pen1);
        dc.DrawCircle(x, y, NODE_RADIUS);
        ptLast = wxPoint(x, y);
    }
    dc.SetPen(wxNullPen);
}

void EnvelopeEditor::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    DoPrepareDC(dc);
    dc.Clear();
    PlotEnvelope(dc);
}

void EnvelopeEditor::OnLeftDown(wxMouseEvent& event)
{
    m_nSelectedNode = -1;
    wxPoint ptNode(0, 0);
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        ptNode = wxPoint(m_vNodes[nNode]->GetPosition(), (m_nRange - m_vNodes[nNode]->GetValue()) * m_fScaleY);
        wxPoint ptWindow = event.GetPosition() - ptNode;
        if(((abs(ptWindow.x) <= NODE_RADIUS)) && ((abs(ptWindow.y) <= NODE_RADIUS)))
        {
            m_nSelectedNode = nNode;
            break;
        }
    }
    Refresh();
}

void EnvelopeEditor::OnLeftUp(wxMouseEvent& event)
{
    if(-1 == m_nSelectedNode)
        return;
    Refresh();
    SendUpdate(m_nSelectedNode);
    m_nSelectedNode = -1;
}

void EnvelopeEditor::OnMouseMotion(wxMouseEvent& event)
{
    if(-1 == m_nSelectedNode)
        return; //No node selected
    if(event.GetPosition().x > GetVirtualSize().x || event.GetPosition().x < 0 || event.GetPosition().y > GetVirtualSize().y || event.GetPosition().y < 0)
        return; //Moved outside window

    int nMinX = 0;
    int nMaxX = GetVirtualSize().x;
    if(m_nSelectedNode > 0)
        nMinX = GetPosition(m_nSelectedNode - 1);
    if(m_nSelectedNode < (int)GetNodeCount() - 1)
        nMaxX = GetPosition(m_nSelectedNode + 1);
    if((event.GetPosition().x < nMinX) || (event.GetPosition().x > nMaxX) || (((ENV_STYLE_DCA_ENV == m_nStyle) | (ENV_STYLE_DCO_ENV == m_nStyle)) & (event.GetPosition().x > nMinX + m_nMaxY)))
        return; //Can't drag curve behind previous or after next node
    m_vNodes[m_nSelectedNode]->SetPosition(event.GetPosition().x);
    m_vNodes[m_nSelectedNode]->SetValue(m_nMinY + (m_nRange - event.GetPosition().y / m_fScaleY));
    Refresh();
}

void EnvelopeEditor::OnSize(wxSizeEvent& event)
{
    Refresh();
}

void EnvelopeEditor::OnLeftDoubleClick(wxMouseEvent& event)
{
    if(ENV_STYLE_DCA_KF == m_nStyle || ENV_STYLE_DCO_KF == m_nStyle)
        return; //Always 6 nodes for key follow
    wxPoint ptNode(0, 0);
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        ptNode = wxPoint(m_vNodes[nNode]->GetPosition(), (m_nRange - m_vNodes[nNode]->GetValue()) * m_fScaleY);
        wxPoint ptWindow = event.GetPosition() - ptNode;
        if(((abs(ptWindow.x) <= NODE_RADIUS)) && ((abs(ptWindow.y) <= NODE_RADIUS)))
        {
            //Clicked within range of existing node
            delete m_vNodes[nNode];
            std::vector<EnvelopeNode*>::iterator it = m_vNodes.begin() + nNode;
            m_vNodes.erase(it);
            Refresh();
            return;
        }
    }
    int nLevel = m_nRange - event.GetPosition().y / m_fScaleY;
    int nPosition = event.GetPosition().x;
    AddNode(nPosition, nLevel);
    Refresh();
}

void EnvelopeEditor::SendUpdate(int nIndex)
{
    wxCommandEvent event(wxEVT_ENVED, GetId());
    event.SetInt(nIndex);
    event.SetEventObject(this);
    ProcessWindowEvent(event);
}

void EnvelopeEditor::SetMinY(int nMin)
{
    m_nMinY = nMin;
    m_nRange = abs(m_nMaxY - m_nMinY);
}

void EnvelopeEditor::SetMaxY(int nMax)
{
    m_nMaxY = nMax;
    m_nRange = abs(m_nMaxY - m_nMinY);
}

int EnvelopeEditor::GetRate(unsigned int nNode)
{
    if(nNode + 1 > GetNodeCount())
        return 0;
    int nLastX = 0;
    if(nNode > 0)
        nLastX = GetPosition(nNode - 1);
    return 0x7F - (GetPosition(nNode) - nLastX);
}

int EnvelopeEditor::GetPosition(unsigned int nNode)
{
    if(nNode > GetNodeCount() - 1)
        return 0;
    return m_vNodes[nNode]->GetPosition();
}

int EnvelopeEditor::GetValue(unsigned int nNode)
{
    if(nNode > GetNodeCount() - 1)
        return 0;
    return m_vNodes[nNode]->GetValue();
}

void EnvelopeEditor::AddNode(int nPosition, int nValue, bool bVelocity, bool bSustain)
{
    if(m_vNodes.size() >= m_nMaxNodes)
        return; //Can't add more nodes

    bool bAdd = true;
    for(unsigned int nNode = 0; nNode < GetNodeCount(); ++nNode)
    {
        if(m_vNodes[nNode]->GetPosition() < nPosition)
            continue;
        if(bAdd)
        {
            m_vNodes.insert(m_vNodes.begin() + nNode, new EnvelopeNode(nPosition, nValue, bVelocity, bSustain));
            bAdd = false;
        }
        SendUpdate(nNode);
    }
    if(bAdd)
    {
        m_vNodes.push_back(new EnvelopeNode(nPosition, nValue, bVelocity, bSustain)); //If we are here then we are at end of nodes
        SendUpdate(GetNodeCount() - 1);
    }
}

void EnvelopeEditor::AddNodeRate(int nRate, int nValue, bool bVelocity, bool bSustain)
{
    if(m_vNodes.size() >= m_nMaxNodes)
        return; //Can't add more nodes
//    wxLogDebug("EnvelopeEditor::AddNodeRate nRate=%d, nValue=%d", nRate, nValue);
    int nLastX = 0;
    if(GetNodeCount() > 0)
        nLastX = GetPosition(GetNodeCount() - 1);
    int nNewX = nLastX + m_nMaxY - nRate;
    AddNode(nNewX, nValue, bVelocity, bSustain);
}

bool EnvelopeEditor::IsVelocity(unsigned int nNode)
{
    if(nNode >= GetNodeCount())
        return false;
    return m_vNodes[nNode]->IsVelocity();
}

bool EnvelopeEditor::IsSustain(unsigned int nNode)
{
    if(nNode >= GetNodeCount())
        return false;
    return m_vNodes[nNode]->IsSustain();
}

void EnvelopeEditor::Clear()
{
    for(unsigned int nNode = 0; nNode < GetNodeCount(); ++nNode)
        delete m_vNodes[nNode];
    m_vNodes.clear();
}
