/***************************************************************
 * Name:      VZ_EditorApp.h
 * Purpose:   Defines top level application VZEditor class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

#include <wx/app.h>

class VZEditorApp : public wxApp
{
public:
    virtual bool OnInit();
};

