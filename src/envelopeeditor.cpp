/***************************************************************
 * Name:      envelopeeditor.cpp
 * Purpose:   Implements EnvelopeEditor class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

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

