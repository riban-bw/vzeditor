#include "keyboardoctave.h"

//(*InternalHeaders(KeyboardOctave)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(KeyboardOctave)
const long KeyboardOctave::ID_PNLKEYC = wxNewId();
const long KeyboardOctave::ID_PNLKEYD = wxNewId();
const long KeyboardOctave::ID_PNLKEYE = wxNewId();
const long KeyboardOctave::ID_PNLKEYF = wxNewId();
const long KeyboardOctave::ID_PNLKEYG = wxNewId();
const long KeyboardOctave::ID_PNLKEYA = wxNewId();
const long KeyboardOctave::ID_PNLKEYB = wxNewId();
//*)

BEGIN_EVENT_TABLE(KeyboardOctave,wxPanel)
	//(*EventTable(KeyboardOctave)
	//*)
END_EVENT_TABLE()

KeyboardOctave::KeyboardOctave(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(KeyboardOctave)
	wxBoxSizer* BoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	m_pPnlKeyC = new wxPanel(this, ID_PNLKEYC, wxDefaultPosition, wxSize(20,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYC"));
	m_pPnlKeyC->SetMinSize(wxSize(-1,50));
	m_pPnlKeyC->SetBackgroundColour(wxColour(255,255,255));
	BoxSizer1->Add(m_pPnlKeyC, 1, wxALL|wxEXPAND, 0);
	m_pPnlKeyD = new wxPanel(this, ID_PNLKEYD, wxDefaultPosition, wxSize(100,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYD"));
	m_pPnlKeyD->SetMinSize(wxSize(-1,50));
	m_pPnlKeyD->SetBackgroundColour(wxColour(128,0,255));
	BoxSizer1->Add(m_pPnlKeyD, 1, wxALL|wxEXPAND, 0);
	m_pPnlKeyE = new wxPanel(this, ID_PNLKEYE, wxDefaultPosition, wxSize(20,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYE"));
	m_pPnlKeyE->SetMinSize(wxSize(-1,50));
	m_pPnlKeyE->SetBackgroundColour(wxColour(255,255,255));
	BoxSizer1->Add(m_pPnlKeyE, 1, wxALL|wxEXPAND, 0);
	m_pPnlKeyF = new wxPanel(this, ID_PNLKEYF, wxDefaultPosition, wxSize(20,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYF"));
	m_pPnlKeyF->SetMinSize(wxSize(-1,50));
	m_pPnlKeyF->SetBackgroundColour(wxColour(255,255,255));
	BoxSizer1->Add(m_pPnlKeyF, 1, wxALL|wxEXPAND, 0);
	m_pPnlKeyG = new wxPanel(this, ID_PNLKEYG, wxDefaultPosition, wxSize(20,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYG"));
	m_pPnlKeyG->SetBackgroundColour(wxColour(255,255,255));
	BoxSizer1->Add(m_pPnlKeyG, 1, wxALL|wxEXPAND, 0);
	m_pPnlKeyA = new wxPanel(this, ID_PNLKEYA, wxDefaultPosition, wxSize(20,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYA"));
	m_pPnlKeyA->SetMinSize(wxSize(-1,50));
	m_pPnlKeyA->SetBackgroundColour(wxColour(255,255,255));
	BoxSizer1->Add(m_pPnlKeyA, 1, wxALL|wxEXPAND, 0);
	m_pPnlKeyB = new wxPanel(this, ID_PNLKEYB, wxDefaultPosition, wxSize(20,98), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PNLKEYB"));
	m_pPnlKeyB->SetMinSize(wxSize(-1,50));
	m_pPnlKeyB->SetBackgroundColour(wxColour(255,255,255));
	BoxSizer1->Add(m_pPnlKeyB, 1, wxALL|wxEXPAND, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	m_pPnlKeyC->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyC->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	m_pPnlKeyD->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyD->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	m_pPnlKeyE->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyE->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	m_pPnlKeyF->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyF->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	m_pPnlKeyG->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyG->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	m_pPnlKeyA->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyA->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	m_pPnlKeyB->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&KeyboardOctave::OnKeyDown,0,this);
	m_pPnlKeyB->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&KeyboardOctave::OnKeyUp,0,this);
	//*)
	m_pPnlKeyC->SetClientData(0);
	m_pPnlKeyD->SetClientData(0);
	m_pPnlKeyE->SetClientData(0);
	m_pPnlKeyF->SetClientData(0);
	m_pPnlKeyG->SetClientData(0);
	m_pPnlKeyA->SetClientData(0);
	m_pPnlKeyB->SetClientData(0);
}

KeyboardOctave::~KeyboardOctave()
{
	//(*Destroy(KeyboardOctave)
	//*)
}


void KeyboardOctave::OnKeyDown(wxMouseEvent& event)
{
}

void KeyboardOctave::OnKeyUp(wxMouseEvent& event)
{
}
