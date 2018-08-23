/***************************************************************
 * Name:      VZ_EditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#include "vzeditorapp.h"

//(*AppHeaders
#include "vzeditormain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(VZ_EditorApp);

bool VZ_EditorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	VZ_EditorFrame* Frame = new VZ_EditorFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
