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
#include "keyboardoctave.h"
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
#include <wx/splitter.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)
#include "wxMidi.h"
#include "vzvoice.h"
#include "vzoperation.h"
#include "vzlibrary.h"
#include "vzsave.h"

static const unsigned int MESSAGE_TYPE_VOICE            = 0;
static const unsigned int MESSAGE_TYPE_OPERATION        = 1;
static const unsigned int MESSAGE_TYPE_MULTI            = 2;
static const unsigned int MESSAGE_TYPE_PITCH            = 0x40;
static const unsigned int MESSAGE_TYPE_MODE             = 0x50;
static const unsigned int MESSAGE_TYPE_BANK             = 0x51;
static const unsigned int MESSAGE_TYPE_OPEN             = 0x70;
static const unsigned int MESSAGE_TYPE_CLOSE            = 0x71;
static const unsigned int MESSAGE_TYPE_OK               = 0x72;
static const unsigned int MESSAGE_TYPE_ERROR            = 0x73;
static const unsigned int MESSAGE_TYPE_DATA             = 0x74;

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
        void OnBtnSendClick(wxCommandEvent& event);
        void OnTxtVoiceNameText(wxCommandEvent& event);
        void OnRadioTremeloMultiSelect(wxCommandEvent& event);
        void OnCmbVelCurveSelect(wxCommandEvent& event);
        void OnRadioTremeloWaveformSelect(wxCommandEvent& event);
        void OnRadioVibratoMultiSelect(wxCommandEvent& event);
        void OnRadioVibratoWaveformSelect(wxCommandEvent& event);
        void OnOpenFile(wxCommandEvent& event);
        void OnListCtrl1ColumnClick(wxListEvent& event);
        void OnBtnGetVoice(wxCommandEvent& event);
        void OnSaveFile(wxCommandEvent& event);
        void OnLevelChanged(wxScrollEvent& event);
        void OnOctaveChanged(wxScrollEvent& event);
        void OnDcoVelSensChange(wxScrollEvent& event);
        void OnTremeloDepthChanged(wxScrollEvent& event);
        void OnTremeloRateChanged(wxScrollEvent& event);
        void OnTremeloDelayChanged(wxScrollEvent& event);
        void OnVibratoDepthChanged(wxScrollEvent& event);
        void OnVibratoRateChanged(wxScrollEvent& event);
        void OnVibratoDelayChanged(wxScrollEvent& event);
        void OnBtnGetOperation(wxCommandEvent& event);
        void OnBtnSaveDump(wxCommandEvent& event);
        //*)
        void OnGridSort(wxCommandEvent& event);
        void OnLibSort(wxListEvent& event);
        void OnLibActivate(wxListEvent& event);

        //(*Identifiers(VZ_EditorFrame)
        static const long ID_STATICTEXT2;
        static const long ID_CMBINPORT;
        static const long ID_STATICTEXT1;
        static const long ID_CMBOUTPORT;
        static const long ID_CHKAUTOUPDATE;
        static const long ID_BTNSEND;
        static const long ID_BTNGETVOICE;
        static const long IID_BTNGETOPERATION;
        static const long ID_BTNSAVEDUMP;
        static const long ID_LSTLIB;
        static const long ID_PNLLIBRARY;
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
        static const long ID_RADIOTREMELOWAVEFORM;
        static const long ID_STATICTEXT6;
        static const long ID_SLIDERTREMELODEPTH;
        static const long ID_STATICTEXT5;
        static const long ID_SLIDERTREMELORATE;
        static const long ID_STATICTEXT4;
        static const long ID_SLIDERTREMELODELAY;
        static const long ID_RADIOBOX3;
        static const long ID_RADIOBOX4;
        static const long ID_STATICTEXT7;
        static const long ID_SLIDER5;
        static const long ID_STATICTEXT8;
        static const long ID_SLIDER4;
        static const long ID_STATICTEXT9;
        static const long ID_SLIDER6;
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_SPLITTERWINDOW1;
        static const long ID_PNLVOICE;
        static const long ID_SCROLLEDWINDOW3;
        static const long ID_STATICTEXT13;
        static const long ID_TXTOPERATIONNAME;
        static const long ID_SCROLLEDWINDOW4;
        static const long ID_SPLITTERWINDOW2;
        static const long ID_PNLOPERATION;
        static const long ID_NOTEBOOK;
        static const long ID_KBD;
        static const long idMenuOpen;
        static const long idMenuSave;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(VZ_EditorFrame)
        KeyboardOctave* m_pKeyboard;
        SortableList* m_pLstLib;
        VZLine* m_pLine1;
        VZLine* m_pLine2;
        VZLine* m_pLine3;
        VZLine* m_pLine4;
        wxBoxSizer* m_pFlexgridGlobalParameters;
        wxButton* m_pBtnGetOperation;
        wxButton* m_pBtnGetVoice;
        wxButton* m_pBtnSaveDump;
        wxButton* m_pBtnSend;
        wxCheckBox* m_pChkAutoUpdate;
        wxChoice* m_pCmbInPort;
        wxChoice* m_pCmbOutPort;
        wxChoice* m_pCmbVelCurve;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* m_pNotebook;
        wxPanel* m_pPnlLibrary;
        wxPanel* m_pPnlOperation;
        wxPanel* m_pPnlVoice;
        wxRadioBox* m_pRadioTremeloMulti;
        wxRadioBox* m_pRadioTremeloWaveform;
        wxRadioBox* m_pRadioVibratoMulti;
        wxRadioBox* m_pRadioVibratoWaveform;
        wxScrolledWindow* ScrolledWindow1;
        wxScrolledWindow* ScrolledWindow2;
        wxScrolledWindow* m_pScrollWinVoiceEditor;
        wxScrolledWindow* m_pScrollwindowGlobalParameters;
        wxSlider* m_pSliderLevel;
        wxSlider* m_pSliderOctave;
        wxSlider* m_pSliderTremeloDelay;
        wxSlider* m_pSliderTremeloDepth;
        wxSlider* m_pSliderTremeloRate;
        wxSlider* m_pSliderVelSens;
        wxSlider* m_pSliderVibratoDelay;
        wxSlider* m_pSliderVibratoDepth;
        wxSlider* m_pSliderVibratoRate;
        wxSplitterWindow* SplitterWindow1;
        wxSplitterWindow* SplitterWindow2;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
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
        wxTextCtrl* m_pTxtOperationName;
        wxTextCtrl* m_pTxtVoiceName;
        //*)

        void CloseInput(); //!< Open MIDI input port
        void CloseOutput(); //!< Close MIDI input port
        void Save(unsigned int nType); //!< Save file (nType = type of file to save)
        bool LoadFile(wxString sFilename = wxEmptyString);
        void Send();
        void GetVoice();
        void GetOperation();
        void UpdateMidiPorts();
        void OnClose(wxCloseEvent& event);
        void AutoSend(); //!< Send voice data after each parameter change
        int GetPortId(PmDeviceInfo* pInfo); //!< Get MIDI port ID from device info pointer (-1 if not found)

        //!@todo Add function to play MIDI notes / CC

        void UpdateVoiceGui(); //!< Update voice editor GUI
        void UpdateOperationGui(); //!< Update operation data editor GUI
        void OnVzSave();

        void OnMidiReceive(wxCommandEvent& event); //!< Handle MIDI receive events
        wxMidiSystem* m_pMidi;
        wxMidiInDevice* m_pMidiIn;
        wxMidiOutDevice* m_pMidiOut;
        bool m_bNoteOn;
        vzvoice* m_pVoice; //Currently edited voice
        vzvoice* m_pVoiceMidi; //Last voice received via MIDI
        vzoperation* m_pOperation; //Currently edited operational memory
        vzoperation* m_pOperationMidi; //Last operation data received via MIDI
        vzsave m_vzSave; //Object to handle save and load functions
        wxByte m_acRawVoiceMidi[VZ_HEADER_SIZE + VZ_VOICE_PAYLOAD_SIZE + 1]; //Buffer to hold raw sysex voice received via MIDI
        wxByte m_acRawOperationMidi[VZ_HEADER_SIZE + VZ_OPERATION_PAYLOAD_SIZE + 1]; //Buffer to hold raw sysex operation data received via MIDI
        VZLibrary* m_pvzLib; //Library

        DECLARE_EVENT_TABLE()
};

#endif // VZ_EDITORMAIN_H
