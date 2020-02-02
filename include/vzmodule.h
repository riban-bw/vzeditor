/***************************************************************
 * Name:      vzmodule.h
 * Purpose:   Defines VZModule class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-31
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

//(*Headers(VZModule)
#include "envelopegraph.h"
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
//*)
#include "VZVoice.h"

class VZModule: public wxPanel
{
public:

    VZModule(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~VZModule();

    /** @brief  Set the voice data to which this module belongs
    *   @param  pVoice Pointer to voice data
    */
    void SetVoice(VZVoice* pVoice);

    /** @brief  Set the module index
    *   @param  nModule Index of this module [0..7]
    */
    void SetModule(wxByte nModule);

    /** @brief  Update the GUI from the voice data
    */
    void UpdateGui();


    //(*Declarations(VZModule)
    EnvelopeGraph* m_pGraphDCA;
    EnvelopeGraph* m_pGraphKeyfollow;
    wxCheckBox* m_pChkEnable;
    wxCheckBox* m_pChkExtPhase;
    wxCheckBox* m_pChkFixedFreq;
    wxCheckBox* m_pChkX16;
    wxChoice* m_pCmbKeyVelCurve;
    wxChoice* m_pCmbWaveform;
    wxSlider* m_pSliderAmpSens;
    wxSlider* m_pSliderDetuneFine;
    wxSlider* m_pSliderDetuneOctave;
    wxSlider* m_pSliderEnvDepth;
    wxSlider* m_pSliderVelSensitivity;
    wxStaticBitmap* m_pBmpKeyboard;
    wxStaticBoxSizer* m_pSizerModule;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* m_pLblWaveform;
    //*)

protected:

    //(*Identifiers(VZModule)
    static const long ID_CHKENABLE;
    static const long ID_CHKEXTPHASE;
    static const long ID_STATICTEXT4;
    static const long ID_CMBWAVEFORM;
    static const long ID_STATICTEXT5;
    static const long ID_SLIDERDETUNEOCTAVE;
    static const long ID_STATICTEXT6;
    static const long ID_SLIDERDETUNEFINE;
    static const long ID_CHKFIXEDFREQ;
    static const long ID_CHKX16;
    static const long ID_ENVELOPEAMP;
    static const long ID_SLIDERENVDEPTH;
    static const long ID_BMPKEYBOARD;
    static const long ID_ENVELOPEKEY;
    static const long ID_CMBKEYVELCURVE;
    static const long ID_SLIDERVELSENSITIVITY;
    static const long ID_SLIDERAMPSENS;
    //*)

private:

    wxByte m_nModule;
    VZVoice* m_pVoice;

    //(*Handlers(VZModule)
    void OnEnable(wxCommandEvent& event);
    void OnExtPhase(wxCommandEvent& event);
    void OnWaveform(wxCommandEvent& event);
    void OnDetuneCourse(wxScrollEvent& event);
    void OnDetuneFine(wxScrollEvent& event);
    void OnFixedFreq(wxCommandEvent& event);
    void OnX16(wxCommandEvent& event);
    void OnEnvDepth(wxScrollEvent& event);
    void OnKeyVelCurve(wxCommandEvent& event);
    void OnKeyVelSens(wxScrollEvent& event);
    void OnSensitivity(wxScrollEvent& event);
    //*)
    void EnableControls(bool bEnable);
    void OnAmpEnvChange(wxCommandEvent& event);
    void OnKeyEnvChange(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};

