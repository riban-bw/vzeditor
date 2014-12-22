#include "envelopeeditor.h"

BEGIN_EVENT_TABLE(EnvelopeEditor, wxScrolledWindow)
    EVT_PAINT       (EnvelopeEditor::OnPaint)
    EVT_LEFT_DOWN   (EnvelopeEditor::OnLeftDown)
    EVT_LEFT_UP     (EnvelopeEditor::OnLeftUp)
    EVT_MOTION      (EnvelopeEditor::OnMouseMotion)
    EVT_SIZE        (EnvelopeEditor::OnSize)
    EVT_LEFT_DCLICK (EnvelopeEditor::OnLeftDoubleClick)
END_EVENT_TABLE()

static const int NODE_RADIUS = 4;

EnvelopeEditor::EnvelopeEditor(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, long style, const wxString& name) :
    wxScrolledWindow(parent, winid, pos, size, style, name),
    m_nSelectedNode(-1),
    m_nMaxNodes(8)
{
    switch(style)
    {
        case ENV_STYLE_DCA_ENV:
            m_nMaxNodes = 8;
            m_nAxisScaler = 1;
            break;
        case ENV_STYLE_DCA_KF:
            m_nMaxNodes = 6;
            m_nAxisScaler = 2;
            break;
        case ENV_STYLE_DCO_ENV:
            m_nMaxNodes = 8;
            m_nAxisScaler = 1;
            break;
        case ENV_STYLE_DCO_KF:
            m_nMaxNodes = 6;
            m_nAxisScaler = 2;
            break;
    }
    m_vNodes.push_back(new wxPoint(0, 10));
//    m_vNodes.push_back(new wxPoint(20, 10));
//    m_vNodes.push_back(new wxPoint(20, 10));
//    m_vNodes.push_back(new wxPoint(20, 0));
}

EnvelopeEditor::~EnvelopeEditor()
{
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
        delete m_vNodes[nNode];
}

void EnvelopeEditor::PlotGraph(wxDC& dc)
{
    //!@todo Add sustain level
    //!@todo Add Velocity rate (additional parameter for each node)
    //!@todo Map data to graph
    //!@todo Make graph scaleable, with values relative to data
    m_nAxis = dc.GetSize().y / m_nAxisScaler;
    wxPen pen1(*wxBLACK, 1);
    wxPen pen2(*wxGREEN, 2);
    dc.SetPen(pen1);
    int x, y;

    wxPoint ptLast(0, m_nAxis);
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        x = ptLast.x + m_vNodes[nNode]->x;
        y = m_nAxis - m_vNodes[nNode]->y;
        dc.DrawLine(ptLast.x, ptLast.y, x,  y);
        ptLast = wxPoint(x, y);
    }
    dc.DrawLine(ptLast.x, ptLast.y, GetVirtualSize().x, y);
    ptLast = wxPoint(0, m_nAxis);
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        int x = ptLast.x + m_vNodes[nNode]->x;
        int y = m_nAxis - m_vNodes[nNode]->y;
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
    PlotGraph(dc);
}

void EnvelopeEditor::OnLeftDown(wxMouseEvent& event)
{
    m_nSelectedNode = -1;
    wxPoint ptLast(0, 0);
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        ptLast = wxPoint(ptLast.x + m_vNodes[nNode]->x, m_nAxis - m_vNodes[nNode]->y);
        wxPoint ptWindow = event.GetPosition() - ptLast;
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
    m_nSelectedNode = -1;
    Refresh();
}

void EnvelopeEditor::OnMouseMotion(wxMouseEvent& event)
{
    if(-1 == m_nSelectedNode)
        return; //No node selected
    if(event.GetPosition().x > GetVirtualSize().x || event.GetPosition().x < 0 || event.GetPosition().y > GetVirtualSize().y || event.GetPosition().y < 0)
        return; //Moved outside window

    int x = 0;
    for(int nNode = 0; nNode < m_nSelectedNode; ++ nNode)
        x += m_vNodes[nNode]->x;
    if(event.GetPosition().x < x)
        return; //Can't drag curve behind previous node
    m_vNodes[m_nSelectedNode]->x = event.GetPosition().x - x;
    m_vNodes[m_nSelectedNode]->y = m_nAxis - event.GetPosition().y;
    Refresh();
}

void EnvelopeEditor::OnSize(wxSizeEvent& event)
{
    Refresh();
}

void EnvelopeEditor::OnLeftDoubleClick(wxMouseEvent& event)
{
    int nDelete = -1;
    int nInsert = -1;
    wxPoint ptLast(0, 0);
    int nInsertX = 0;
    for(unsigned int nNode = 0; nNode < m_vNodes.size(); ++nNode)
    {
        if(-1 != nDelete)
        {
            delete(m_vNodes[nNode]);
        }
        else
        {
            ptLast = wxPoint(ptLast.x + m_vNodes[nNode]->x, m_nAxis - m_vNodes[nNode]->y);
            wxPoint ptWindow = event.GetPosition() - ptLast;
            if(((abs(ptWindow.x) <= NODE_RADIUS)) && ((abs(ptWindow.y) <= NODE_RADIUS)))
            {
                delete(m_vNodes[nNode]);
                nDelete = nNode;
            }
            else if(ptLast.x < event.GetPosition().x)
            {
                nInsert = nNode;
                nInsertX = ptLast.x;
            }
        }
    }

    if(-1 == nDelete)
    {
        //Add a node
        if(m_vNodes.size() >= m_nMaxNodes)
            return;
        int x = event.GetPosition().x - nInsertX;
        int y = m_nAxis - event.GetPosition().y;
        std::vector<wxPoint*>::iterator it = m_vNodes.begin() + nInsert + 1;
        m_vNodes.insert(it, new wxPoint(x, y));
    }
    else
    {
        //Delete all nodes from one clicked on
        std::vector<wxPoint*>::iterator it = m_vNodes.begin() + nDelete;
        m_vNodes.erase(it, m_vNodes.end());
    }
    Refresh();

}
