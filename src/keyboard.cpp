#include "keyboard.h"

IMPLEMENT_DYNAMIC_CLASS(Keyboard, wxControl);

//wxWidgets Event table
BEGIN_EVENT_TABLE(Keyboard, wxWindow)
    EVT_PAINT           (Keyboard::OnPaint)
    EVT_LEFT_DOWN       (Keyboard::OnMouseLeftDown)
    EVT_LEFT_UP         (Keyboard::OnMouseLeftUp)
    EVT_MOTION          (Keyboard::OnMotion)
    EVT_LEAVE_WINDOW    (Keyboard::OnExitWindow)
    EVT_SIZE            (Keyboard::OnSize)
END_EVENT_TABLE()

wxDEFINE_EVENT(KEYBOARD_NOTE_ON_EVENT, wxCommandEvent);
wxDEFINE_EVENT(KEYBOARD_NOTE_OFF_EVENT, wxCommandEvent);

Keyboard::Keyboard()
{
}

Keyboard::Keyboard(wxWindow* parent, wxWindowID id) :
    wxControl(parent, id)
{
    SetFirstNote(m_nFirstNote);
}

Keyboard::~Keyboard()
{
}

wxSize Keyboard::DoGetBestSize() const
{
    return wxSize(7 * m_nNotes * m_nKeyWidth / 12, m_nKeyLength); //!@todo DoGetBestSize is only an approximation
}

void Keyboard::OnPaint(wxPaintEvent &WXUNUSED(event) )
{
    wxPaintDC dc(this);
    PrepareDC(dc);
    dc.Clear();
    dc.SetPen(wxPen(*wxBLACK, 1));
    wxPoint pt(0,0);
    wxSize sz(m_nKeyWidth + 1, m_nKeyLength);
    dc.SetBrush(*wxWHITE);
    for(unsigned int nKey = m_nFirstNote; nKey < m_nFirstNote + m_nNotes; ++nKey)
    {
        switch(nKey % 12)
        {
        case 0:
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
        case 11:
            if(nKey == m_nCurrentNote)
                dc.SetBrush(*wxGREY_BRUSH);
            dc.DrawRectangle(pt, sz);
            pt += wxPoint(m_nKeyWidth, 0);
            if(nKey == m_nCurrentNote)
                dc.SetBrush(*wxWHITE);
        }
    }
    dc.SetBrush(*wxBLACK);
    pt = wxPoint(m_nKeyWidth * -0.25, 0);
    sz = wxSize(m_nKeyWidth * 0.5, m_nKeyLength * 0.6);
    for(unsigned int nKey = m_nFirstNote; nKey < m_nFirstNote + m_nNotes; ++nKey)
    {
        switch(nKey % 12)
        {
        case 1:
        case 3:
        case 6:
        case 8:
        case 10:
            if(nKey == m_nCurrentNote)
                dc.SetBrush(*wxGREY_BRUSH);
            dc.DrawRectangle(pt, sz);
            if(nKey == m_nCurrentNote)
                dc.SetBrush(*wxBLACK);
            break;
        default:
            pt += wxPoint(m_nKeyWidth, 0);
        }
    }
}

void Keyboard::SetNotes(unsigned int nNotes)
{
    m_nNotes = nNotes;
    m_nKeyWidth = GetSize().x / m_nNotes;
}

unsigned int Keyboard::GetNotes()
{
    return m_nNotes;
}

void Keyboard::SetFirstNote(unsigned int nNote)
{
    if(nNote > m_nNotes)
        m_nFirstNote = m_nNotes;
    else
        m_nFirstNote = nNote;
    SetOffset();
    Refresh();
}

unsigned int Keyboard::GetFirstNote()
{
    return m_nFirstNote;
}

unsigned int Keyboard::GetVelocity(wxPoint pt)
{
    if(pt.x < 0 || pt.x > GetVirtualSize().x || pt.y < 0 || pt.y > GetVirtualSize().y)
        return 0;
    return 127 * pt.y / m_nKeyLength;
}

unsigned int Keyboard::GetNote(wxPoint pt)
{
    if(pt.x < 0 || pt.x > GetVirtualSize().x || pt.y < 0 || pt.y > GetVirtualSize().y)
        return 255;
    unsigned int nWhiteKeyOffset = pt.x / m_nKeyWidth;
    unsigned int nOctave = nWhiteKeyOffset / 7;
    unsigned int nNote = m_nFirstNote + nOctave * 12;

    bool bBlackNoteRegion = (pt.y < GetVirtualSize().y * 0.6);
    {
        switch((4 * pt.x / m_nKeyWidth + m_nOffset) % 28)
        {
        case 3:
            if(bBlackNoteRegion)
                ++nNote; //C#
        case 0: //C
        case 1: //C
        case 2: //C
            if(m_nFirstNote % 12 > 0)
                nNote += 12;
            return nNote - m_nFirstNote % 12;
        case 4: //Db
            if(bBlackNoteRegion)
                nNote -= 2;
        case 7: //D#
            if(bBlackNoteRegion)
                ++nNote;
        case 5: //D
        case 6: //D
            if(m_nFirstNote % 12 > 2)
                nNote += 12;
            return nNote + 2 - m_nFirstNote % 12;
        case 8: //Eb
            if(bBlackNoteRegion)
                --nNote;
        case 9: //E
        case 10: //E
        case 11: //E
            if(m_nFirstNote % 12 > 4)
                nNote += 12;
            return nNote + 4 - m_nFirstNote % 12;
        case 12: //Fb
            if(bBlackNoteRegion)
                nNote -= 2;
        case 15: //F#
            if(bBlackNoteRegion)
                ++nNote;
        case 13: //F
        case 14: //F
            if(m_nFirstNote % 12 > 5)
                nNote += 12;
            return nNote + 5 - m_nFirstNote % 12;
        case 16: //Gb
            if(bBlackNoteRegion)
                nNote -= 2;
        case 19: //G#
            if(bBlackNoteRegion)
                ++nNote;
        case 17: //G
        case 18: //G
            if(m_nFirstNote % 12 > 7)
                nNote += 12;
            return nNote + 7 - m_nFirstNote % 12;
        case 20: //Ab
            if(bBlackNoteRegion)
                nNote -= 2;
        case 23: //A#
            if(bBlackNoteRegion)
                ++nNote;
        case 21: //A
        case 22: //A
            if(m_nFirstNote % 12 > 9)
                nNote += 12;
            return nNote + 9 - m_nFirstNote % 12;
        case 24: //Bb
            if(bBlackNoteRegion)
                --nNote;
        case 25: //B
        case 26: //B
        case 27: //B
            if(m_nFirstNote % 12 > 11)
                nNote += 12;
            return nNote + 11 - m_nFirstNote % 12;
        }
    }
    return 255;
}

void Keyboard::SendNoteOn(unsigned int nChannel, unsigned int nNote, unsigned int nVelocity)
{
    if(nNote > 127 || nChannel > 15 || nVelocity > 127)
        return;
    if(m_nCurrentNote < 128)
        SendNoteOff(m_nTxChannel, m_nCurrentNote);
    m_nCurrentNote = nNote;
    wxCommandEvent event(KEYBOARD_NOTE_ON_EVENT, GetId());
    event.SetEventObject(this);
    event.SetInt(nNote);
    event.SetClientData(&m_clientData);
    m_clientData.channel = nChannel;
    m_clientData.note = nNote;
    m_clientData.velocity = nVelocity;
    ProcessWindowEvent(event);
    Refresh();
}

void Keyboard::SendNoteOff(unsigned int nChannel, unsigned int nNote, unsigned int nVelocity)
{
    if(nNote < 0 || nNote > 127)
        return;
    if(nChannel > 15)
        return;
    if (nVelocity > 128)
        return;
    m_nCurrentNote = 255;
    wxCommandEvent event(KEYBOARD_NOTE_OFF_EVENT, GetId());
    event.SetEventObject(this);
    event.SetInt(nNote);
    event.SetClientData(&m_clientData);
    m_clientData.channel = nChannel;
    m_clientData.note = nNote;
    m_clientData.velocity = nVelocity;
    ProcessWindowEvent(event);
    Refresh();
}

void Keyboard::OnMouseLeftDown(wxMouseEvent &event)
{
    SendNoteOn(m_nTxChannel, GetNote(event.GetPosition()), GetVelocity(event.GetPosition()));
}

void Keyboard::OnMouseLeftUp(wxMouseEvent &event)
{
    if(m_nCurrentNote == 255)
        return;
    SendNoteOff(m_nTxChannel, GetNote(event.GetPosition()));
}

void Keyboard::OnMotion(wxMouseEvent &event)
{
    // Handle glissando
    if(m_nCurrentNote == 255)
        return;
    unsigned int nNote = GetNote(event.GetPosition());
    if(nNote != m_nCurrentNote)
        SendNoteOn(m_nTxChannel, nNote, GetVelocity(event.GetPosition()));
}

void Keyboard::OnExitWindow(wxMouseEvent &event)
{
    SendNoteOff(m_nTxChannel, m_nCurrentNote);
}

void Keyboard::SetMinSize(const wxSize& size)
{
    m_nMinKeyWidth = 12 * size.x / (m_nNotes * 7);
    m_nMinKeyLength = size.y;
    wxControl::SetMinSize(size);
}

void Keyboard::OnSize(wxSizeEvent &event)
{
    m_nKeyWidth = 12 * event.GetSize().x / (m_nNotes * 7);
    if(m_nKeyWidth < m_nMinKeyWidth)
        m_nKeyWidth = m_nMinKeyWidth;
    m_nKeyLength = event.GetSize().y;
    if(m_nKeyLength < m_nMinKeyLength)
        m_nKeyLength = m_nMinKeyLength;
    Refresh();
}

void Keyboard::SetOffset()
{
    switch(m_nFirstNote % 12)
    {
    case 0:
        m_nOffset = 0;
        break;
    case 1:
        m_nOffset = 3;
        break;
    case 2:
        m_nOffset = 4;
        break;
    case 3:
        m_nOffset = 7;
        break;
    case 4:
        m_nOffset = 8;
        break;
    case 5:
        m_nOffset = 12;
        break;
    case 6:
        m_nOffset = 15;
        break;
    case 7:
        m_nOffset = 16;
        break;
    case 8:
        m_nOffset = 19;
        break;
    case 9:
        m_nOffset = 20;
        break;
    case 10:
        m_nOffset = 23;
        break;
    case 11:
        m_nOffset = 24;
        break;
    }
}

void Keyboard::SetSendChannel(unsigned int nChannel)
{
    if(m_nCurrentNote < 128)
        SendNoteOff(m_nTxChannel, m_nCurrentNote);
    if(nChannel < 16)
        m_nTxChannel = nChannel;
}

unsigned int Keyboard::GetSendChannel()
{
    return m_nTxChannel;
}
