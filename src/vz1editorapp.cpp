/***************************************************************
 * Name:      sysexApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2014-12-15
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#include "vz1editorapp.h"

//(*AppHeaders
#include "vz1editormain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(sysexApp);

bool sysexApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	sysexFrame* Frame = new sysexFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
