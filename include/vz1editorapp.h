/***************************************************************
 * Name:      sysexApp.h
 * Purpose:   Defines Application Class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2014-12-15
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#ifndef SYSEXAPP_H
#define SYSEXAPP_H

#include <wx/app.h>

class sysexApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SYSEXAPP_H
