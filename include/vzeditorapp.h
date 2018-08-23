/***************************************************************
 * Name:      VZ_EditorApp.h
 * Purpose:   Defines Application Class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#ifndef VZ_EDITORAPP_H
#define VZ_EDITORAPP_H

#include <wx/app.h>

class VZ_EditorApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // VZ_EDITORAPP_H
