/***************************************************************
 * Name:      vzeditorapp.cpp
 * Purpose:   Implements top level application VZEditor class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "vzeditorapp.h"

//(*AppHeaders
#include "vzeditormain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(VZEditorApp);

bool VZEditorApp::OnInit()
{
    if(LoadLibraryA("exchndl.dll"))
        wxLogDebug("Loaded JIT excetion handler");
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        VZEditorFrame* Frame = new VZEditorFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
        if(argc > 1)
        {
            wxString sFilename = argv[1];
            Frame->LoadFile(sFilename);
        }
    }
    //*)

    return wxsOK;

}
