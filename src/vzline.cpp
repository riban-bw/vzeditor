#include "vzline.h"

//(*InternalHeaders(VZLine)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZLine)
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
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_pVzModule1 = new VZModule(this,ID_VZMODULE1,wxDefaultPosition,wxDefaultSize);
	BoxSizer1->Add(m_pVzModule1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pVzModule2 = new VZModule(this,ID_VZMODULE2,wxDefaultPosition,wxDefaultSize);
	BoxSizer1->Add(m_pVzModule2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
	m_pVzModule1->SetModule(m_nLine * 2);
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
}
