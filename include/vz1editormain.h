/***************************************************************
 * Name:      sysexMain.h
 * Purpose:   Defines Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2014-12-15
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#pragma once

//(*Headers(sysexFrame)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/radiobox.h>
#include "vzvoicemodule.h"
//*)
#include <portmidi.h>
#include "wxMidi.h"

class sysexFrame: public wxFrame
{
    public:

        sysexFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~sysexFrame();

    private:

        //(*Handlers(sysexFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnOutPortSelect(wxCommandEvent& event);
        void OnInPortSelect(wxCommandEvent& event);
        void OnBtnSendClick(wxCommandEvent& event);
        void OnTxtVoiceNameText(wxCommandEvent& event);
        void OnSliderTremeloDelayCmdScrollChanged(wxScrollEvent& event);
        void OnSliderTremeloDepthCmdScrollChanged(wxScrollEvent& event);
        void OnSliderTremeloRateCmdScrollChanged(wxScrollEvent& event);
        void OnRadioTremeloMultiSelect(wxCommandEvent& event);
        void OnRadioTremeloWaveformSelect(wxCommandEvent& event);
        void OnChkAutoUpdateClick(wxCommandEvent& event);
        void OnmenuSaveSelected(wxCommandEvent& event);
        void OnmenuOpenSelected(wxCommandEvent& event);
        void OnSliderLevelCmdScrollChanged(wxScrollEvent& event);
        void OnSliderOctaveCmdScrollChanged(wxScrollEvent& event);
        void OnSliderVelSensCmdScrollChanged(wxScrollEvent& event);
        void OnCmbVelCurveSelect(wxCommandEvent& event);
        void OnRadioVibratoMultiSelect(wxCommandEvent& event);
        void OnRadioVibratoWaveformSelect(wxCommandEvent& event);
        void OnSliderVibratoDepthCmdScrollChanged(wxScrollEvent& event);
        void OnSliderVibratoRateCmdScrollChanged(wxScrollEvent& event);
        void OnSliderVibratoDelayCmdScrollChanged(wxScrollEvent& event);
        //*)

        //(*Identifiers(sysexFrame)
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE2;
        static const long ID_CHECKBOX1;
        static const long ID_BUTTON1;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT30;
        static const long ID_SLIDER26;
        static const long ID_STATICTEXT10;
        static const long ID_SLIDER7;
        static const long ID_STATICTEXT11;
        static const long ID_SLIDER8;
        static const long ID_STATICTEXT12;
        static const long ID_CHOICE4;
        static const long ID_RADIOBOX2;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT4;
        static const long ID_RADIOBOX1;
        static const long ID_SLIDER3;
        static const long ID_SLIDER2;
        static const long ID_SLIDER1;
        static const long ID_RADIOBOX3;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_RADIOBOX4;
        static const long ID_SLIDER5;
        static const long ID_SLIDER4;
        static const long ID_SLIDER6;
        static const long ID_PANEL1;
        static const long idMenuOpen;
        static const long idMenuSave;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(sysexFrame)
        wxRadioBox* m_pRadioVibratoWaveform;
        wxTextCtrl* m_pTxtVoiceName;
        wxPanel* Panel1;
        vzVoiceModule* m_pModule6;
        wxStaticText* m_pLblVelCurve;
        wxChoice* m_pCmbVelCurve;
        wxStatusBar* StatusBar1;
        wxSlider* m_pSliderVelSens;
        vzVoiceModule* m_pModule7;
        wxSlider* m_pSliderVibratoDelay;
        vzVoiceModule* m_pModule8;
        wxRadioBox* m_pRadioTremeloWaveform;
        wxSlider* m_pSliderTremeloRate;
        wxStaticText* StaticText1;
        wxStaticText* StaticText10;
        wxFlexGridSizer* m_pSizerMain;
        wxSlider* m_pSliderTremeloDepth;
        wxSlider* m_pSliderLevel;
        wxStaticText* StaticText3;
        wxScrolledWindow* m_pScrollWinVoiceEditor;
        vzVoiceModule* m_pModule1;
        wxMenuItem* menuOpen;
        wxCheckBox* m_pChkAutoUpdate;
        wxSlider* m_pSliderOctave;
        vzVoiceModule* m_pModule4;
        vzVoiceModule* m_pModule2;
        wxStaticText* StaticText8;
        vzVoiceModule* m_pModule5;
        wxStaticText* StaticText7;
        wxButton* m_pBtnSend;
        vzVoiceModule* m_pModule3;
        wxSlider* m_pSliderVibratoDepth;
        wxMenuItem* menuSave;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxChoice* m_pCmbOutPort;
        wxSlider* m_pSliderTremeloDelay;
        wxStaticText* StaticText30;
        wxStaticText* StaticText2;
        wxRadioBox* m_pRadioVibratoMulti;
        wxStaticText* StaticText6;
        wxChoice* m_pCmbInPort;
        wxRadioBox* m_pRadioTremeloMulti;
        wxStaticText* StaticText9;
        wxSlider* m_pSliderVibratoRate;
        wxStaticText* StaticText11;
        //*)

        void OnMidiReceive(wxCommandEvent &event);
        void OnModuleEvent(wxCommandEvent &event);
        void CloseInput();
        void CloseOutput();
        void SendVoice(); //Sends voice data via sysex message
        void SendOk(); //Sends sysex message OK
        void UpdateVoice();
        void AutoUpdateVoice();
        void SetVzMode(unsigned int nMode); //Send sysex message to set VZ operational mode
        void OpenPatch(wxString sFilename = wxEmptyString);
        void SavePatch(wxString sFilename = wxEmptyString);

        wxMidiSystem* m_pMidi;
        wxMidiInDevice* m_pMidiIn;
        wxMidiOutDevice* m_pMidiOut;
        bool m_bAutoUpdate;

        wxByte m_aVoice[336];
        wxByte m_aOp[100];

        DECLARE_EVENT_TABLE()
};

