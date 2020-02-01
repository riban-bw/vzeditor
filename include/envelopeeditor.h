/***************************************************************
 * Name:      envelopeeditor.h
 * Purpose:   Defines EnvelopeEditor class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

//(*Headers(EnvelopeEditor)
#include <wx/panel.h>
//*)
static const long ENV_STYLE_DCA_ENV = 0;
static const long ENV_STYLE_DCO_ENV = 1;
static const long ENV_STYLE_DCA_KF  = 2;
static const long ENV_STYLE_DCO_KF  = 3;

class EnvelopeEditor: public wxPanel
{
public:

    EnvelopeEditor(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~EnvelopeEditor();

    //(*Declarations(EnvelopeEditor)
    //*)

protected:

    //(*Identifiers(EnvelopeEditor)
    //*)

private:

    //(*Handlers(EnvelopeEditor)
    //*)

    DECLARE_EVENT_TABLE()
};
