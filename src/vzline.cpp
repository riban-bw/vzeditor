#include "vzline.h"

//(*InternalHeaders(VZLine)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZLine)
const long VZLine::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZLine,wxPanel)
	//(*EventTable(VZLine)
	//*)
END_EVENT_TABLE()

VZLine::VZLine(wxWindow* parent)
{
	//(*Initialize(VZLine)
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 0, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("LINE WIDGET"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxSIMPLE_BORDER, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)
}

VZLine::~VZLine()
{
	//(*Destroy(VZLine)
	//*)
}

