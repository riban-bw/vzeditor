/***************************************************************
 * Name:      vzeditormain.h
 * Purpose:   Defines main application frame VZEditorFrame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

//(*Headers(VZEditorFrame)
#include "envelopegraph.h"
#include "keyboard.h"
#include "vzline.h"
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/splitter.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)
#include "wxMidi.h"
#include "vzvoice.h"
#include "vzoperation.h"
#include "vzlibrary.h"
#include "vzsave.h"
#include <wx/dnd.h>

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

class VZEditorFrame: public wxFrame
{
public:

    VZEditorFrame(wxWindow* parent,wxWindowID id = -1);
    virtual ~VZEditorFrame();
    wxString OnGetItemText(long item, long column) const;
    bool LoadFile(wxString sFilename = wxEmptyString);
    bool SetConfigVoice(unsigned int nIndex, wxString sFilename);
    bool SetConfigOperation(unsigned int nIndex, wxString sFilename);

private:

    //(*Handlers(VZEditorFrame)
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
    void OnChkKeyboard(wxCommandEvent& event);
    void OnKeyChan(wxSpinEvent& event);
    void OnKeyProgram(wxSpinEvent& event);
    void Onm_pChkKeyboardClick(wxCommandEvent& event);
    void Onm_pCmbOutPortSelect(wxCommandEvent& event);
    void OnTimer1s(wxTimerEvent& event);
    void OnTxtLibEntryDescription(wxCommandEvent& event);
    void OnCmbLibEntryGroup(wxCommandEvent& event);
    void OnLibToolAdd(wxCommandEvent& event);
    void OnLibToolDelete(wxCommandEvent& event);
    void OnCmbLibEntryGroupDropdown(wxCommandEvent& event);
    void OnMenuShow(wxCommandEvent& event);
    void OnMasterVolume(wxScrollEvent& event);
    void OnMasterTune(wxScrollEvent& event);
    void OnTranspose(wxScrollEvent& event);
    void OnCzBendRange(wxScrollEvent& event);
    void OnMode(wxCommandEvent& event);
    void OnCardBank(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
    void OnToneGridDClick(wxGridEvent& event);
    void OnLibDClick(wxCommandEvent& event);
    void OnLstLibrary(wxCommandEvent& event);
    //*)
    void OnGridSort(wxCommandEvent& event);

    //(*Identifiers(VZEditorFrame)
    static const long ID_STATICTEXTMIDIINPUT;
    static const long ID_CMBINPORT;
    static const long ID_STATICTEXTMIDIOUTPUT;
    static const long ID_CMBOUTPORT;
    static const long ID_CHECKBOXKEYBOARD;
    static const long ID_CHKAUTOUPDATE;
    static const long ID_BTNSEND;
    static const long ID_BTNGETVOICE;
    static const long ID_BTNGETOPERATION;
    static const long ID_BTNSAVEDUMP;
    static const long ID_PANEL1;
    static const long ID_BITMAPBUTTONLIBTOOLADD;
    static const long ID_BITMAPBUTTONLIBTOOLDELETE;
    static const long ID_BITMAPBUTTONLIBTOOLSAVE;
    static const long ID_BITMAPBUTTONLIBTOOLSAVEAS;
    static const long ID_BITMAPBUTTONLIBTOOLOPRN;
    static const long ID_LISTBOXLIBRARY;
    static const long ID_GRIDCONFIG;
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
    static const long ID_ENVELOPEDCO;
    static const long ID_SLIDERDCOENVDEPTH;
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
    static const long ID_PANELMULTICHANNEL;
    static const long ID_SLIDERVOLUME;
    static const long ID_SLIDERMASTERTUNE;
    static const long ID_SLIDERTRANSPOSE;
    static const long ID_SLIDERCZBENDRANGE;
    static const long ID_CHOICEMODE;
    static const long ID_RADIOBOXCARDBANK;
    static const long ID_PANELMISC;
    static const long ID_NOTEBOOK;
    static const long ID_STATICTEXT14;
    static const long ID_SPIN_KEYCHAN;
    static const long ID_STATICTEXT15;
    static const long ID_SPINCTRL1;
    static const long ID_PANEL2;
    static const long ID_KBD;
    static const long idMenuOpen;
    static const long idMenuSave;
    static const long ID_MENU_SAVEAS;
    static const long idMenuQuit;
    static const long ID_MENU_HEADER;
    static const long ID_MENU_LIBRARY;
    static const long ID_MENU_VOICE;
    static const long ID_MENU_OPERATION;
    static const long ID_MENU_MULTICHANNEL;
    static const long ID_MENU_MISC;
    static const long ID_MENU_KEYBOARD;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_TIMER1S;
    //*)

    //(*Declarations(VZEditorFrame)
    EnvelopeGraph* m_pGraphDCO;
    Keyboard* m_pKeyboard;
    VZLine* m_pLine1;
    VZLine* m_pLine2;
    VZLine* m_pLine3;
    VZLine* m_pLine4;
    wxBitmapButton* m_pBtnLibToolAdd;
    wxBitmapButton* m_pBtnLibToolDelete;
    wxBitmapButton* m_pBtnLibToolOpen;
    wxBitmapButton* m_pBtnLibToolSave;
    wxBitmapButton* m_pBtnLibToolSaveAs;
    wxBoxSizer* m_pFlexgridGlobalParameters;
    wxBoxSizer* m_pSizerKeyboard;
    wxBoxSizer* m_pSizerLines;
    wxBoxSizer* m_pSizerMain;
    wxButton* m_pBtnGetOperation;
    wxButton* m_pBtnGetVoice;
    wxButton* m_pBtnSaveDump;
    wxButton* m_pBtnSend;
    wxCheckBox* m_pChkAutoUpdate;
    wxCheckBox* m_pChkKeyboard;
    wxChoice* m_pChoiceInPort;
    wxChoice* m_pChoiceMode;
    wxChoice* m_pChoiceOutPort;
    wxChoice* m_pChoiceVelCurve;
    wxGrid* m_pGridConfig;
    wxListBox* m_pLstLibrary;
    wxMenu* Menu3;
    wxMenuItem* Menu4;
    wxMenuItem* MenuItem10;
    wxMenuItem* MenuItem11;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem5;
    wxMenuItem* MenuItem6;
    wxMenuItem* MenuItem7;
    wxMenuItem* MenuItem8;
    wxMenuItem* MenuItem9;
    wxNotebook* m_pNotebook;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxPanel* m_pPnlLibrary;
    wxPanel* m_pPnlMisc;
    wxPanel* m_pPnlMultichannel;
    wxPanel* m_pPnlOperation;
    wxPanel* m_pPnlVoice;
    wxRadioBox* m_pRadioCardbank;
    wxRadioBox* m_pRadioTremeloMulti;
    wxRadioBox* m_pRadioTremeloWaveform;
    wxRadioBox* m_pRadioVibratoMulti;
    wxRadioBox* m_pRadioVibratoWaveform;
    wxScrolledWindow* ScrolledWindow1;
    wxScrolledWindow* ScrolledWindow2;
    wxScrolledWindow* m_pScrollWinVoiceEditor;
    wxScrolledWindow* m_pScrollwindowGlobalParameters;
    wxSlider* m_pSliderCZBendRange;
    wxSlider* m_pSliderDCOEnvDepth;
    wxSlider* m_pSliderLevel;
    wxSlider* m_pSliderMasterTune;
    wxSlider* m_pSliderOctave;
    wxSlider* m_pSliderTranspose;
    wxSlider* m_pSliderTremeloDelay;
    wxSlider* m_pSliderTremeloDepth;
    wxSlider* m_pSliderTremeloRate;
    wxSlider* m_pSliderVelSens;
    wxSlider* m_pSliderVibratoDelay;
    wxSlider* m_pSliderVibratoDepth;
    wxSlider* m_pSliderVibratoRate;
    wxSlider* m_pSliderVolume;
    wxSpinCtrl* m_pSpnKeyChannel;
    wxSpinCtrl* m_pSpnProgram;
    wxSplitterWindow* SplitterWindow2;
    wxSplitterWindow* m_pSplitterMain;
    wxStaticText* StaticText10;
    wxStaticText* StaticText11;
    wxStaticText* StaticText12;
    wxStaticText* StaticText13;
    wxStaticText* StaticText14;
    wxStaticText* StaticText30;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText6;
    wxStaticText* StaticText7;
    wxStaticText* StaticText8;
    wxStaticText* StaticText9;
    wxStaticText* m_pLblMidiInputPort;
    wxStaticText* m_pLblMidiOutputPort;
    wxStaticText* m_pLblVelCurve;
    wxStatusBar* m_pStatusbar;
    wxTextCtrl* m_pTxtOperationName;
    wxTextCtrl* m_pTxtVoiceName;
    wxTimer m_timer1s;
    //*)

    void CloseInput(); //!< Open MIDI input port
    void CloseOutput(); //!< Close MIDI input port
    void Save(unsigned int nType, wxString sFilename = wxEmptyString); //!< Save file (nType = type of file to save)
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
    void OnKeyboardNoteOn(wxCommandEvent& event); // Handle on-screen MIDI keyboard note-on events
    void OnKeyboardNoteOff(wxCommandEvent& event); // Handle on-screen MIDI keyboard note-off events
    void OnModuleEvent(wxCommandEvent& event); // Handle module change events
    void PopulateLibraryGroups();
    bool CheckHostError(); //Handles host errors and returns true on error
    void OnGridStartDrag(wxGridEvent& event); //Handle start of drag and drop within grid
    void LoadLibrary(); // Populate library list from .vzt & .vzo filenames
    void onLstLibLeftDown(wxMouseEvent& event);
    void onLstLibLeftUp(wxMouseEvent& event);

    void OnMidiReceive(wxCommandEvent& event); //!< Handle MIDI receive events
    wxMidiSystem* m_pMidi;
    wxMidiInDevice* m_pMidiIn;
    wxMidiOutDevice* m_pMidiOut;
    bool m_bNoteOn;
    bool m_bInhibitUpdate = true; // True to avoid updating controls, e.g. whilst updating interface with saved values
    VZVoice* m_pVoice; //Currently edited voice
    VZVoice* m_pVoiceMidi; //Last voice received via MIDI
    VZOperation* m_pOperation; //Currently edited operational memory
    VZOperation* m_pOperationMidi; //Last operation data received via MIDI
    VZSave m_vzSave; //Object to handle save and load functions
    wxByte m_acRawVoiceMidi[VZ_HEADER_SIZE + VZ_VOICE_PAYLOAD_SIZE + 1]; //Buffer to hold raw sysex voice received via MIDI
    wxByte m_acRawOperationMidi[VZ_HEADER_SIZE + VZ_OPERATION_PAYLOAD_SIZE + 1]; //Buffer to hold raw sysex operation data received via MIDI
    VZLibrary* m_pvzLib; //Library
    unsigned int m_anProgram[16]; //Last selected MIDI program for each MIDI channel
    unsigned int m_nDragSource; //Index of drag source

    DECLARE_EVENT_TABLE()
};


class VZDropTarget: public wxFileDropTarget
{
public:
    VZDropTarget(wxGrid* pGrid) :
        m_pGrid(pGrid)
    {
    }

    bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
    {
        if(!filenames.GetCount())
            return false;
        VZEditorFrame* pFrame = dynamic_cast<VZEditorFrame*>(wxTheApp->GetTopWindow());
        if(!pFrame)
            return false;
        int nRow = m_pGrid->YToRow(y);
        int nCol = m_pGrid->XToCol(x);
        if(nRow < 8)
            pFrame->SetConfigVoice(nRow + nCol * 8, filenames[0]);
        else
            pFrame->SetConfigOperation(nRow - 8 + nCol * 8, filenames[0]);
        return true;
    };
private:
    wxGrid* m_pGrid;
};
