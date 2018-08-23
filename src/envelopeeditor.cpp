#include "envelopeeditor.h"

//(*InternalHeaders(EnvelopeEditor)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(EnvelopeEditor)
//*)

BEGIN_EVENT_TABLE(EnvelopeEditor,wxPanel)
	//(*EventTable(EnvelopeEditor)
	//*)
END_EVENT_TABLE()

EnvelopeEditor::EnvelopeEditor(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(EnvelopeEditor)
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//*)
}

EnvelopeEditor::~EnvelopeEditor()
{
	//(*Destroy(EnvelopeEditor)
	//*)
}

