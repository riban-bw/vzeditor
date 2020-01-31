#include "vzline.h"

//(*InternalHeaders(VZLine)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZLine)
const long VZLine::ID_CHOICE1 = wxNewId();
const long VZLine::ID_VZMODULE1 = wxNewId();
const long VZLine::ID_VZMODULE2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZLine,wxPanel)
	//(*EventTable(VZLine)
	//*)
END_EVENT_TABLE()

VZLine::VZLine(wxWindow* parent, wxByte line) :
    m_nLine(line),
    m_pvzVoice(NULL)
{
	//(*Initialize(VZLine)
	wxBoxSizer* BoxSizer2;

	Create(parent, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	SetMinSize(wxSize(-1,-1));
	m_pSizerLine = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Internal Line"));
	m_pCmbLine = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	m_pCmbLine->Append(_("MIX"));
	m_pCmbLine->Append(_("RING"));
	m_pCmbLine->Append(_("PHASE"));
	m_pSizerLine->Add(m_pCmbLine, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	m_pVzModule1 = new VZModule(this,ID_VZMODULE1,wxDefaultPosition,wxDefaultSize);
	BoxSizer2->Add(m_pVzModule1, 1, wxALL|wxEXPAND, 5);
	m_pVzModule2 = new VZModule(this,ID_VZMODULE2,wxDefaultPosition,wxDefaultSize);
	BoxSizer2->Add(m_pVzModule2, 1, wxALL|wxEXPAND, 5);
	m_pSizerLine->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(m_pSizerLine);
	SetSizer(m_pSizerLine);
	Layout();

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZLine::OnLine);
	//*)
	m_pVzModule1->SetModule(m_nLine * 2);
	m_pSizerLine->GetStaticBox()->SetLabel(wxString::Format("Internal Line %c", 'A' + m_nLine));
	m_pVzModule2->SetModule(m_nLine * 2 + 1);
}

VZLine::~VZLine()
{
	//(*Destroy(VZLine)
	//*)
}

void VZLine::SetVoice(vzvoice* pVoice)
{
    m_pvzVoice = pVoice;
    m_pVzModule1->SetVoice(pVoice);
    m_pVzModule2->SetVoice(pVoice);
}

void VZLine::UpdateGui()
{
    m_pVzModule1->UpdateGui();
    m_pVzModule2->UpdateGui();
    if(m_pvzVoice)
        m_pCmbLine->SetSelection(m_pvzVoice->GetLine(m_nLine));
}

void VZLine::OnLine(wxCommandEvent& event)
{
    if(!m_pvzVoice)
        return;
    m_pvzVoice->SetLine(m_nLine, (VZ_LINE)event.GetSelection());
}
