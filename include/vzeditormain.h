/***************************************************************
 * Name:      VZ_EditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#ifndef VZ_EDITORMAIN_H
#define VZ_EDITORMAIN_H

//(*Headers(VZ_EditorFrame)
#include "sortablelist.h"
#include "vzline.h"
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)
#include "wxMidi.h"
#include "vzvoice.h"
#include "vzlibrary.h"

class VZ_EditorFrame: public wxFrame
{
    public:

        VZ_EditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~VZ_EditorFrame();
        wxString OnGetItemText(long item, long column) const;

    private:

        //(*Handlers(VZ_EditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnInPortSelect(wxCommandEvent& event);
        void OnOutPortSelect(wxCommandEvent& event);
        void OnChkAutoUpdateClick(wxCommandEvent& event);
        void OnBtnSendClick(wxCommandEvent& event);
        void OnTxtVoiceNameText(wxCommandEvent& event);
        void OnRadioTremeloMultiSelect(wxCommandEvent& event);
        void OnSliderLevelCmdScroll(wxScrollEvent& event);
        void OSliderOctaveCmdScroll(wxScrollEvent& event);
        void OSliderVelSensCmdScroll(wxScrollEvent& event);
        void OnCmbVelCurveSelect(wxCommandEvent& event);
        void OnRadioTremeloWaveformSelect(wxCommandEvent& event);
        void OnSliderTremeloDepthCmdScroll(wxScrollEvent& event);
        void OnSliderTremeloRateCmdScroll(wxScrollEvent& event);
        void OnSliderTremeloDelayCmdScroll(wxScrollEvent& event);
        void OnRadioVibratoMultiSelect(wxCommandEvent& event);
        void OnRadioVibratoWaveformSelect(wxCommandEvent& event);
        void OnSliderVibratoDepthCmdScroll(wxScrollEvent& event);
        void OnSliderVibratoRateCmdScroll(wxScrollEvent& event);
        void OnSliderVibratoDelayCmdScroll(wxScrollEvent& event);
        void OnOpenFile(wxCommandEvent& event);
        void OnListCtrl1ColumnClick(wxListEvent& event);
        void OnBtnGetVoice(wxCommandEvent& event);
        void OnSaveFile(wxCommandEvent& event);
        void OnLoadFile(wxCommandEvent& event);
        //*)
        void OnGridSort(wxCommandEvent& event);
        void OnLibSort(wxListEvent& event);

        //(*Identifiers(VZ_EditorFrame)
        static const long ID_STATICTEXT2;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE2;
        static const long ID_CHECKBOX1;
        static const long ID_BUTTON1;
        static const long ID_BTNGETVOICE;
        static const long ID_LINE1;
        static const long ID_LINE2;
        static const long ID_LINE3;
        static const long ID_LINE4;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT30;
        static const long ID_SLIDERLEVEL;
        static const long ID_STATICTEXT10;
        static const long ID_SLIDEROCTAVE;
        static const long ID_STATICTEXT11;
        static const long ID_SLIDERVELSENS;
        static const long ID_STATICTEXT12;
        static const long ID_CMBVELCURVE;
        static const long ID_RADIOTREMELOMULTI;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT4;
        static const long ID_RADIOTREMELOWAVEFORM;
        static const long ID_SLIDERTREMELODEPTH;
        static const long ID_SLIDERTREMELORATE;
        static const long ID_SLIDERTREMELODELAY;
        static const long ID_RADIOBOX3;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_RADIOBOX4;
        static const long ID_SLIDER5;
        static const long ID_SLIDER4;
        static const long ID_SLIDER6;
        static const long ID_PNLVOICE;
        static const long ID_LSTLIB;
        static const long ID_PANEL1;
        static const long ID_NOTEBOOK;
        static const long idMenuOpen;
        static const long idMenuSave;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(VZ_EditorFrame)
        SortableList* m_pLstLib;
        VZLine* m_pLine1;
        VZLine* m_pLine2;
        VZLine* m_pLine3;
        VZLine* m_pLine4;
        wxButton* m_pBtnGetVoice;
        wxButton* m_pBtnSend;
        wxCheckBox* m_pChkAutoUpdate;
        wxChoice* m_pCmbInPort;
        wxChoice* m_pCmbOutPort;
        wxChoice* m_pCmbVelCurve;
        wxFlexGridSizer* m_pSizerMain;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* m_pNotebook;
        wxPanel* Panel1;
        wxPanel* m_pPnlVoice;
        wxRadioBox* m_pRadioTremeloMulti;
        wxRadioBox* m_pRadioTremeloWaveform;
        wxRadioBox* m_pRadioVibratoMulti;
        wxRadioBox* m_pRadioVibratoWaveform;
        wxScrolledWindow* m_pScrollWinVoiceEditor;
        wxSlider* m_pSliderLevel;
        wxSlider* m_pSliderOctave;
        wxSlider* m_pSliderTremeloDelay;
        wxSlider* m_pSliderTremeloDepth;
        wxSlider* m_pSliderTremeloRate;
        wxSlider* m_pSliderVelSens;
        wxSlider* m_pSliderVibratoDelay;
        wxSlider* m_pSliderVibratoDepth;
        wxSlider* m_pSliderVibratoRate;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText30;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStaticText* m_pLblVelCurve;
        wxStatusBar* StatusBar1;
        wxTextCtrl* m_pTxtVoiceName;
        //*)

        void CloseInput(); //!< Open MIDI input port
        void CloseOutput(); //!< Close MIDI input port
        void SaveVoice();
        void LoadVoice();
        void SendVoice();
        void GetVoice();


        //!@todo Add function to play MIDI notes / CC

        void UpdateGui();

        void OnMidiReceive(wxCommandEvent& event); //!< Handle MIDI receive events
        wxMidiSystem* m_pMidi;
        wxMidiInDevice* m_pMidiIn;
        wxMidiOutDevice* m_pMidiOut;
        bool m_bNoteOn;
        vzvoice m_vzVoice; //Buffer to hold currently edited voice
        vzvoice m_vzVoiceMidi; //Buffer to hold last voice received via MIDI
        wxByte m_acRawVoiceMidi[VZ_VOICE_SIZE]; //Buffer to hold raw sysex voice received via MIDI
        VZLibrary* m_pvzLib; //Library


        DECLARE_EVENT_TABLE()
};

#endif // VZ_EDITORMAIN_H
