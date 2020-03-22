/***************************************************************
 * Name:      vzlne.h
 * Purpose:   Defines VZLine class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once


//(*Headers(VZLine)
#include "vzmodule.h"
#include <wx/choice.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)
#include "vzvoice.h"

class VZLine: public wxPanel
{
public:

    /** @brief  Construct a VZ Internal Line GUI object
    *   @param  parent Pointer to the parent window
    *   @param  line Index of this line [0..3]
    */
    VZLine(wxWindow* parent, wxByte line);

    /** @brief  Destruct a VZ Internal Line GUI object
    */
    virtual ~VZLine();

    /** @brief  Set the vzvoice data
    *   @param  pVoice Pointer to the voice data
    */
    void SetVoice(VZVoice* pVoice);

    /** @brief  Update the GUI from voice data
    */
    void UpdateGui();

    //(*Declarations(VZLine)
    VZModule* m_pVzModule1;
    VZModule* m_pVzModule2;
    wxChoice* m_pChoiceLine;
    wxStaticBoxSizer* m_pSizerLine;
    //*)

protected:

    //(*Identifiers(VZLine)
    static const long ID_CHOICE1;
    static const long ID_VZMODULE1;
    static const long ID_VZMODULE2;
    //*)

private:

    wxByte m_nLine;
    VZVoice* m_pvzVoice;

    //(*Handlers(VZLine)
    void OnLine(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};
