/***************************************************************
 * Name:      VZ_EditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#include "vzeditormain.h"
#include "../media/icon.xpm"
#include <wx/msgdlg.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/config.h>
#include <wx/display.h>

//(*InternalHeaders(VZ_EditorFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZ_EditorFrame)
const long VZ_EditorFrame::ID_STATICTEXT2 = wxNewId();
const long VZ_EditorFrame::ID_CMBINPORT = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT1 = wxNewId();
const long VZ_EditorFrame::ID_CMBOUTPORT = wxNewId();
const long VZ_EditorFrame::ID_CHKAUTOUPDATE = wxNewId();
const long VZ_EditorFrame::ID_BTNSEND = wxNewId();
const long VZ_EditorFrame::ID_BTNGETVOICE = wxNewId();
const long VZ_EditorFrame::IID_BTNGETOPERATION = wxNewId();
const long VZ_EditorFrame::ID_BTNSAVEDUMP = wxNewId();
const long VZ_EditorFrame::ID_LSTLIB = wxNewId();
const long VZ_EditorFrame::ID_PNLLIBRARY = wxNewId();
const long VZ_EditorFrame::ID_LINE1 = wxNewId();
const long VZ_EditorFrame::ID_LINE2 = wxNewId();
const long VZ_EditorFrame::ID_LINE3 = wxNewId();
const long VZ_EditorFrame::ID_LINE4 = wxNewId();
const long VZ_EditorFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT3 = wxNewId();
const long VZ_EditorFrame::ID_TEXTCTRL1 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT30 = wxNewId();
const long VZ_EditorFrame::ID_SLIDERLEVEL = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT10 = wxNewId();
const long VZ_EditorFrame::ID_SLIDEROCTAVE = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT11 = wxNewId();
const long VZ_EditorFrame::ID_SLIDERVELSENS = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT12 = wxNewId();
const long VZ_EditorFrame::ID_CMBVELCURVE = wxNewId();
const long VZ_EditorFrame::ID_RADIOTREMELOMULTI = wxNewId();
const long VZ_EditorFrame::ID_RADIOTREMELOWAVEFORM = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT6 = wxNewId();
const long VZ_EditorFrame::ID_SLIDERTREMELODEPTH = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT5 = wxNewId();
const long VZ_EditorFrame::ID_SLIDERTREMELORATE = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT4 = wxNewId();
const long VZ_EditorFrame::ID_SLIDERTREMELODELAY = wxNewId();
const long VZ_EditorFrame::ID_RADIOBOX3 = wxNewId();
const long VZ_EditorFrame::ID_RADIOBOX4 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT7 = wxNewId();
const long VZ_EditorFrame::ID_SLIDER5 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT8 = wxNewId();
const long VZ_EditorFrame::ID_SLIDER4 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT9 = wxNewId();
const long VZ_EditorFrame::ID_SLIDER6 = wxNewId();
const long VZ_EditorFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long VZ_EditorFrame::ID_SPLITTERWINDOW1 = wxNewId();
const long VZ_EditorFrame::ID_PNLVOICE = wxNewId();
const long VZ_EditorFrame::ID_SCROLLEDWINDOW3 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT13 = wxNewId();
const long VZ_EditorFrame::ID_TXTOPERATIONNAME = wxNewId();
const long VZ_EditorFrame::ID_SCROLLEDWINDOW4 = wxNewId();
const long VZ_EditorFrame::ID_SPLITTERWINDOW2 = wxNewId();
const long VZ_EditorFrame::ID_PNLOPERATION = wxNewId();
const long VZ_EditorFrame::ID_NOTEBOOK = wxNewId();
const long VZ_EditorFrame::ID_KBD = wxNewId();
const long VZ_EditorFrame::idMenuOpen = wxNewId();
const long VZ_EditorFrame::idMenuSave = wxNewId();
const long VZ_EditorFrame::idMenuQuit = wxNewId();
const long VZ_EditorFrame::idMenuAbout = wxNewId();
const long VZ_EditorFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZ_EditorFrame,wxFrame)
    //(*EventTable(VZ_EditorFrame)
    //*)
END_EVENT_TABLE()

VZ_EditorFrame::VZ_EditorFrame(wxWindow* parent,wxWindowID id)
{
    wxTextValidator m_validateVoiceName;
    wxArrayString asValidate;
    m_validateVoiceName.SetStyle(wxFILTER_INCLUDE_CHAR_LIST);
    for(char c = 'A'; c <= 'Z'; ++c)
        asValidate.Add(wxString::Format(wxT("%c"), c));
    for(char c = '0'; c <= '9'; ++c)
        asValidate.Add(wxString::Format(wxT("%c"), c));
    asValidate.Add(wxT(" "));
    asValidate.Add(wxT("-"));
    asValidate.Add(wxT("/"));
    asValidate.Add(wxT("."));
    m_validateVoiceName.SetIncludes(wxArrayString(asValidate));

    //(*Initialize(VZ_EditorFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxFlexGridSizer* FlexGridSizer10;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer12;
    wxFlexGridSizer* FlexGridSizer13;
    wxFlexGridSizer* FlexGridSizer14;
    wxFlexGridSizer* FlexGridSizer15;
    wxFlexGridSizer* FlexGridSizer16;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer9;
    wxFlexGridSizer* m_pFlexgridGlobalParameters;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;

    Create(parent, wxID_ANY, _("riban Casio VZ-x Voice Editor and Library"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(icon_xpm));
    	SetIcon(FrameIcon);
    }
    m_pSizerMain = new wxFlexGridSizer(0, 1, 0, 0);
    m_pSizerMain->AddGrowableCol(0);
    m_pSizerMain->AddGrowableRow(1);
    FlexGridSizer1 = new wxFlexGridSizer(0, 0, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("MIDI Input Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbInPort = new wxChoice(this, ID_CMBINPORT, wxDefaultPosition, wxSize(181,27), 0, 0, 0, wxDefaultValidator, _T("ID_CMBINPORT"));
    FlexGridSizer1->Add(m_pCmbInPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("MIDI Output Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbOutPort = new wxChoice(this, ID_CMBOUTPORT, wxDefaultPosition, wxSize(181,27), 0, 0, 0, wxDefaultValidator, _T("ID_CMBOUTPORT"));
    FlexGridSizer1->Add(m_pCmbOutPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkAutoUpdate = new wxCheckBox(this, ID_CHKAUTOUPDATE, _("Auto Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKAUTOUPDATE"));
    m_pChkAutoUpdate->SetValue(false);
    FlexGridSizer1->Add(m_pChkAutoUpdate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSend = new wxButton(this, ID_BTNSEND, _("Send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSEND"));
    FlexGridSizer1->Add(m_pBtnSend, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetVoice = new wxButton(this, ID_BTNGETVOICE, _("Get Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETVOICE"));
    m_pBtnGetVoice->Disable();
    FlexGridSizer1->Add(m_pBtnGetVoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetOperation = new wxButton(this, IID_BTNGETOPERATION, _("Get Operation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("IID_BTNGETOPERATION"));
    m_pBtnGetOperation->Disable();
    FlexGridSizer1->Add(m_pBtnGetOperation, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSaveDump = new wxButton(this, ID_BTNSAVEDUMP, _("Save Dump"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSAVEDUMP"));
    FlexGridSizer1->Add(m_pBtnSaveDump, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSizerMain->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    m_pNotebook = new wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_NOPAGETHEME, _T("ID_NOTEBOOK"));
    m_pPnlLibrary = new wxPanel(m_pNotebook, ID_PNLLIBRARY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLLIBRARY"));
    FlexGridSizer9 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer9->AddGrowableCol(0);
    FlexGridSizer9->AddGrowableRow(1);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer9->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    m_pLstLib = new SortableList(m_pPnlLibrary,ID_LSTLIB);
    FlexGridSizer9->Add(m_pLstLib, 1, wxALL|wxEXPAND, 5);
    m_pPnlLibrary->SetSizer(FlexGridSizer9);
    FlexGridSizer9->Fit(m_pPnlLibrary);
    FlexGridSizer9->SetSizeHints(m_pPnlLibrary);
    m_pPnlVoice = new wxPanel(m_pNotebook, ID_PNLVOICE, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLVOICE"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    SplitterWindow1 = new wxSplitterWindow(m_pPnlVoice, ID_SPLITTERWINDOW1, wxDefaultPosition, wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    SplitterWindow1->SetMinimumPaneSize(10);
    SplitterWindow1->SetSashGravity(1);
    m_pScrollWinVoiceEditor = new wxScrolledWindow(SplitterWindow1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    m_pLine1 = new VZLine(m_pScrollWinVoiceEditor, 0);
    BoxSizer3->Add(m_pLine1, 1, wxALL|wxEXPAND, 5);
    m_pLine2 = new VZLine(m_pScrollWinVoiceEditor, 1);
    BoxSizer3->Add(m_pLine2, 1, wxALL|wxEXPAND, 5);
    m_pLine3 = new VZLine(m_pScrollWinVoiceEditor, 2);
    BoxSizer3->Add(m_pLine3, 1, wxALL|wxEXPAND, 5);
    m_pLine4 = new VZLine(m_pScrollWinVoiceEditor, 3);
    BoxSizer3->Add(m_pLine4, 1, wxALL|wxEXPAND, 5);
    m_pScrollWinVoiceEditor->SetSizer(BoxSizer3);
    BoxSizer3->Fit(m_pScrollWinVoiceEditor);
    BoxSizer3->SetSizeHints(m_pScrollWinVoiceEditor);
    m_pScrollwindowGlobalParameters = new wxScrolledWindow(SplitterWindow1, ID_SCROLLEDWINDOW2, wxDefaultPosition, wxDefaultSize, wxVSCROLL, _T("ID_SCROLLEDWINDOW2"));
    m_pFlexgridGlobalParameters = new wxFlexGridSizer(0, 1, 0, 0);
    m_pFlexgridGlobalParameters->AddGrowableCol(0);
    m_pFlexgridGlobalParameters->AddGrowableRow(3);
    m_pFlexgridGlobalParameters->AddGrowableRow(4);
    FlexGridSizer4 = new wxFlexGridSizer(0, 0, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    StaticText3 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT3, _("Voice Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtVoiceName = new wxTextCtrl(m_pScrollwindowGlobalParameters, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, m_validateVoiceName, _T("ID_TEXTCTRL1"));
    m_pTxtVoiceName->SetMaxLength(12);
    FlexGridSizer4->Add(m_pTxtVoiceName, 1, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer7->AddGrowableCol(1);
    StaticText30 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT30, _("Level"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer7->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderLevel = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERLEVEL, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERLEVEL"));
    FlexGridSizer7->Add(m_pSliderLevel, 1, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(FlexGridSizer7, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("DCO"));
    FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer6->AddGrowableCol(1);
    StaticText10 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT10, _("Octave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer6->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderOctave = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDEROCTAVE, 0, -2, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDEROCTAVE"));
    FlexGridSizer6->Add(m_pSliderOctave, 1, wxALL|wxEXPAND, 5);
    StaticText11 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT11, _("Velocity\nSensitivity"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT11"));
    FlexGridSizer6->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVelSens = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERVELSENS, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDERVELSENS"));
    FlexGridSizer6->Add(m_pSliderVelSens, 1, wxALL|wxEXPAND, 5);
    m_pLblVelCurve = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT12, _("Curve"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer6->Add(m_pLblVelCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbVelCurve = new wxChoice(m_pScrollwindowGlobalParameters, ID_CMBVELCURVE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBVELCURVE"));
    m_pCmbVelCurve->SetSelection( m_pCmbVelCurve->Append(_("Curve 1")) );
    m_pCmbVelCurve->Append(_("Curve 2"));
    m_pCmbVelCurve->Append(_("Curve 3"));
    m_pCmbVelCurve->Append(_("Curve 4"));
    m_pCmbVelCurve->Append(_("Curve 5"));
    m_pCmbVelCurve->Append(_("Curve 6"));
    m_pCmbVelCurve->Append(_("Curve 7"));
    m_pCmbVelCurve->Append(_("Curve 8"));
    FlexGridSizer6->Add(m_pCmbVelCurve, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pFlexgridGlobalParameters->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("Tremelo"));
    FlexGridSizer3 = new wxFlexGridSizer(1, 0, 0, 0);
    FlexGridSizer3->AddGrowableRow(0);
    FlexGridSizer15 = new wxFlexGridSizer(0, 1, 0, 0);
    wxString __wxRadioBoxChoices_1[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioTremeloMulti = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOTREMELOMULTI, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOTREMELOMULTI"));
    FlexGridSizer15->Add(m_pRadioTremeloMulti, 1, wxALL|wxEXPAND, 5);
    wxString __wxRadioBoxChoices_2[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioTremeloWaveform = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOTREMELOWAVEFORM, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_2, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOTREMELOWAVEFORM"));
    FlexGridSizer15->Add(m_pRadioTremeloWaveform, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3->Add(FlexGridSizer15, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer12 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer12->AddGrowableRow(1);
    StaticText6 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT6, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer12->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloDepth = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERTREMELODEPTH, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELODEPTH"));
    FlexGridSizer12->Add(m_pSliderTremeloDepth, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3->Add(FlexGridSizer12, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer13 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer13->AddGrowableRow(1);
    StaticText5 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT5, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer13->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloRate = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERTREMELORATE, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELORATE"));
    m_pSliderTremeloRate->SetMinSize(wxSize(0,0));
    FlexGridSizer13->Add(m_pSliderTremeloRate, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3->Add(FlexGridSizer13, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer14 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer14->AddGrowableRow(1);
    StaticText4 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT4, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer14->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloDelay = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERTREMELODELAY, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELODELAY"));
    FlexGridSizer14->Add(m_pSliderTremeloDelay, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3->Add(FlexGridSizer14, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(FlexGridSizer3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("Vibrato"));
    FlexGridSizer5 = new wxFlexGridSizer(1, 0, 0, 0);
    FlexGridSizer5->AddGrowableRow(0);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    wxString __wxRadioBoxChoices_3[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioVibratoMulti = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOBOX3, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX3"));
    BoxSizer4->Add(m_pRadioVibratoMulti, 1, wxALL|wxEXPAND, 5);
    wxString __wxRadioBoxChoices_4[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioVibratoWaveform = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOBOX4, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_4, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX4"));
    BoxSizer4->Add(m_pRadioVibratoWaveform, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer5->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer8->AddGrowableRow(1);
    StaticText7 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT7, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer8->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoDepth = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDER5, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER5"));
    FlexGridSizer8->Add(m_pSliderVibratoDepth, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer5->Add(FlexGridSizer8, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer10 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer10->AddGrowableRow(1);
    StaticText8 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT8, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer10->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoRate = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDER4, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER4"));
    FlexGridSizer10->Add(m_pSliderVibratoRate, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer5->Add(FlexGridSizer10, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer11 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer11->AddGrowableRow(1);
    StaticText9 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT9, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer11->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoDelay = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDER6, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER6"));
    FlexGridSizer11->Add(m_pSliderVibratoDelay, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer5->Add(FlexGridSizer11, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2->Add(FlexGridSizer5, 1, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    m_pScrollwindowGlobalParameters->SetSizer(m_pFlexgridGlobalParameters);
    m_pFlexgridGlobalParameters->Fit(m_pScrollwindowGlobalParameters);
    m_pFlexgridGlobalParameters->SetSizeHints(m_pScrollwindowGlobalParameters);
    SplitterWindow1->SplitVertically(m_pScrollWinVoiceEditor, m_pScrollwindowGlobalParameters);
    BoxSizer1->Add(SplitterWindow1, 1, wxALL|wxEXPAND, 5);
    m_pPnlVoice->SetSizer(BoxSizer1);
    BoxSizer1->Fit(m_pPnlVoice);
    BoxSizer1->SetSizeHints(m_pPnlVoice);
    m_pPnlOperation = new wxPanel(m_pNotebook, ID_PNLOPERATION, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLOPERATION"));
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    SplitterWindow2 = new wxSplitterWindow(m_pPnlOperation, ID_SPLITTERWINDOW2, wxDefaultPosition, wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW2"));
    SplitterWindow2->SetMinimumPaneSize(10);
    SplitterWindow2->SetSashGravity(1);
    ScrolledWindow1 = new wxScrolledWindow(SplitterWindow2, ID_SCROLLEDWINDOW3, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW3"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    ScrolledWindow1->SetSizer(BoxSizer6);
    BoxSizer6->Fit(ScrolledWindow1);
    BoxSizer6->SetSizeHints(ScrolledWindow1);
    ScrolledWindow2 = new wxScrolledWindow(SplitterWindow2, ID_SCROLLEDWINDOW4, wxDefaultPosition, wxDefaultSize, wxVSCROLL, _T("ID_SCROLLEDWINDOW4"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    FlexGridSizer16 = new wxFlexGridSizer(0, 0, 0, 0);
    FlexGridSizer16->AddGrowableCol(1);
    StaticText12 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT13, _("Voice Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer16->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtOperationName = new wxTextCtrl(ScrolledWindow2, ID_TXTOPERATIONNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, m_validateVoiceName, _T("ID_TXTOPERATIONNAME"));
    m_pTxtOperationName->SetMaxLength(12);
    FlexGridSizer16->Add(m_pTxtOperationName, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2->Add(FlexGridSizer16, 1, wxALL|wxEXPAND, 5);
    ScrolledWindow2->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(ScrolledWindow2);
    FlexGridSizer2->SetSizeHints(ScrolledWindow2);
    SplitterWindow2->SplitVertically(ScrolledWindow1, ScrolledWindow2);
    BoxSizer5->Add(SplitterWindow2, 1, wxALL|wxEXPAND, 5);
    m_pPnlOperation->SetSizer(BoxSizer5);
    BoxSizer5->Fit(m_pPnlOperation);
    BoxSizer5->SetSizeHints(m_pPnlOperation);
    m_pNotebook->AddPage(m_pPnlLibrary, _("Voice Library"), false);
    m_pNotebook->AddPage(m_pPnlVoice, _("Voice Editor"), false);
    m_pNotebook->AddPage(m_pPnlOperation, _("Operation Editor"), false);
    m_pSizerMain->Add(m_pNotebook, 1, wxALL|wxEXPAND, 5);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    m_pKeyboard = new KeyboardOctave(this,ID_KBD);
    BoxSizer7->Add(m_pKeyboard, 1, wxALL|wxEXPAND, 5);
    m_pSizerMain->Add(BoxSizer7, 1, wxALL|wxEXPAND, 5);
    SetSizer(m_pSizerMain);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpen, _("&Open\tCtrl+O"), _("Open file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuSave, _("&Save\tCtrl+S"), _("Save voice data to file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    m_pSizerMain->Fit(this);
    m_pSizerMain->SetSizeHints(this);
    Center();

    Connect(ID_CMBINPORT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnInPortSelect);
    Connect(ID_CMBOUTPORT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnOutPortSelect);
    Connect(ID_BTNSEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZ_EditorFrame::OnBtnSendClick);
    Connect(ID_BTNGETVOICE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZ_EditorFrame::OnBtnGetVoice);
    Connect(IID_BTNGETOPERATION,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZ_EditorFrame::OnBtnGetOperation);
    Connect(ID_BTNSAVEDUMP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZ_EditorFrame::OnBtnSaveDump);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZ_EditorFrame::OnTxtVoiceNameText);
    Connect(ID_SLIDERLEVEL,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnLevelChanged);
    Connect(ID_SLIDEROCTAVE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnOctaveChanged);
    Connect(ID_SLIDERVELSENS,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnDcoVelSensChange);
    Connect(ID_CMBVELCURVE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnCmbVelCurveSelect);
    Connect(ID_RADIOTREMELOMULTI,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioTremeloMultiSelect);
    Connect(ID_RADIOTREMELOWAVEFORM,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioTremeloWaveformSelect);
    Connect(ID_SLIDERTREMELODEPTH,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnTremeloDepthChanged);
    Connect(ID_SLIDERTREMELORATE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnTremeloRateChanged);
    Connect(ID_SLIDERTREMELODELAY,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnTremeloDelayChanged);
    Connect(ID_RADIOBOX3,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioVibratoMultiSelect);
    Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioVibratoWaveformSelect);
    Connect(ID_SLIDER5,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnVibratoDepthChanged);
    Connect(ID_SLIDER4,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnVibratoRateChanged);
    Connect(ID_SLIDER6,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnVibratoDelayChanged);
    Connect(ID_TXTOPERATIONNAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZ_EditorFrame::OnTxtVoiceNameText);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnOpenFile);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnSaveFile);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnAbout);
    //*)
    m_pScrollWinVoiceEditor->SetScrollRate(10,10);
    m_pScrollwindowGlobalParameters->SetScrollRate(0, 10);
    Connect(ID_LSTLIB,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&VZ_EditorFrame::OnLibSort);
    Connect(ID_LSTLIB,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&VZ_EditorFrame::OnLibActivate);
    Connect(wxID_ANY, wxEVT_MIDI_INPUT,(wxObjectEventFunction)&VZ_EditorFrame::OnMidiReceive);
    Connect(wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&VZ_EditorFrame::OnClose);

    wxConfig configPersist(wxTheApp->GetAppName(), wxT("riban"),wxEmptyString, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
    int nX, nY, nWidth, nHeight;
    bool bX;
    //Position window
    configPersist.Read(wxT("persist/left"), &nX, 0);
    configPersist.Read(wxT("persist/top"), &nY, 0);
    configPersist.Read(wxT("persist/width"), &nWidth, 800);
    configPersist.Read(wxT("persist/height"), &nHeight, 600);
    configPersist.Read(wxT("persist/maximised"), &bX, false);
    Maximize(bX);
    SetSize(nWidth, nHeight);
      //Check saved location is visible
    bool bCanSee = false;
	for(unsigned int nDisplay = 0; nDisplay < wxDisplay::GetCount(); nDisplay++)
    {
        bCanSee |= wxDisplay(nDisplay).GetGeometry().Intersects(wxRect(nX, nY, nWidth, nHeight));
    }
    if(bCanSee)
        Move(nX, nY);


    //Get MIDI interfaces
    //!@todo React to MIDI ports appearing and disappearing, e.g. USB plugged in - maybe using wxMidiDevice::HasHostError()
    m_pMidi = wxMidiSystem::GetInstance();
    m_pMidiOut = (wxMidiOutDevice*)NULL;
    m_pMidiIn = (wxMidiInDevice*)NULL;
    UpdateMidiPorts();

    configPersist.Read(wxT("persist/midi_in"), &nX, 0);
    if(m_pCmbInPort->GetCount())
    {
        if((int)m_pCmbInPort->GetCount() - 1 < nX)
            nX = m_pCmbInPort->GetCount() - 1;
        wxCommandEvent event;
        m_pCmbInPort->Select(nX);
        event.SetClientData(m_pCmbInPort->GetClientData(0));
        OnInPortSelect(event);
    }
    configPersist.Read(wxT("persist/midi_out"), &nX, 0);
    if(m_pCmbOutPort->GetCount())
    {
        if((int)m_pCmbOutPort->GetCount() - 1 < nX)
            nX = m_pCmbOutPort->GetCount() - 1;
        wxCommandEvent event;
        m_pCmbOutPort->Select(nX);
        event.SetClientData(m_pCmbOutPort->GetClientData(0));
        OnOutPortSelect(event);
    }
    bool bAuto;
    configPersist.Read(wxT("persist/auto_update"), &bAuto, false);
    m_pChkAutoUpdate->SetValue(bAuto);
    m_pvzLib = new VZLibrary();
    m_pLstLib->SetData(m_pvzLib);

    m_pVoice = new vzvoice();
    m_pVoiceMidi = new vzvoice();
    m_pOperation = new vzoperation();
    m_pOperationMidi = new vzoperation();

    m_pLine1->SetVoice(m_pVoice);
    m_pLine2->SetVoice(m_pVoice);
    m_pLine3->SetVoice(m_pVoice);
    m_pLine4->SetVoice(m_pVoice);
}

VZ_EditorFrame::~VZ_EditorFrame()
{
}

void VZ_EditorFrame::OnClose(wxCloseEvent& event)
{
    wxConfig configPersist(wxTheApp->GetAppName(), wxT("riban"),wxEmptyString, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
    configPersist.Write(wxT("persist/midi_out"), m_pCmbOutPort->GetSelection());
    configPersist.Write(wxT("persist/auto_update"), m_pChkAutoUpdate->IsChecked());
    configPersist.Write(wxT("persist/midi_in"), m_pCmbInPort->GetSelection());
    configPersist.Write(wxT("persist/maximised"), IsMaximized());
	if(!IsMaximized() && !IsIconized())
	{
        configPersist.Write(wxT("persist/width"), GetSize().GetWidth());
        configPersist.Write(wxT("persist/height"), GetSize().GetHeight());
        configPersist.Write(wxT("persist/left"), GetPosition().x);
        configPersist.Write(wxT("persist/top"), GetPosition().y);
	}
	CloseInput();
	CloseOutput();
    delete m_pvzLib;
    delete m_pVoice;
    delete m_pVoiceMidi;
    delete m_pOperation;
    delete m_pOperationMidi;
    event.Skip();
}

void VZ_EditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void VZ_EditorFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("riban 2014-2020", _("Casio VZ-1 / VZ-10M / VZ-8 Library and editor"));
}

int VZ_EditorFrame::GetPortId(PmDeviceInfo* pInfo)
{
    for(int nPort = 0; nPort < Pm_CountDevices(); ++nPort)
        if(pInfo == Pm_GetDeviceInfo(nPort))
            return nPort;
    return -1;
}

void VZ_EditorFrame::OnInPortSelect(wxCommandEvent& event)
{
    CloseInput();
    int nPort = GetPortId((PmDeviceInfo*)event.GetClientData());
    if(nPort < 0)
        return;
    m_pMidiIn = new wxMidiInDevice(nPort);
    m_pMidiIn->Open();
    m_pMidiIn->StartListening(this);
}

void VZ_EditorFrame::OnOutPortSelect(wxCommandEvent& event)
{
    CloseOutput();
    int nPort = GetPortId((PmDeviceInfo*)event.GetClientData());
    if(nPort < 0)
        return;
    m_pMidiOut = new wxMidiOutDevice(nPort);
    m_pMidiOut->Open(0);
    m_pBtnSend->Enable();
}

void VZ_EditorFrame::CloseInput()
{
    if(!m_pMidiIn)
        return;
    m_pMidiIn->StopListening();
    m_pMidiIn->Close();
    delete m_pMidiIn;
    m_pMidiIn = (wxMidiInDevice*)NULL;
}

void VZ_EditorFrame::CloseOutput()
{
    if(!m_pMidiOut)
        return;
    m_pMidiOut->Close();
    delete m_pMidiOut;
    m_pMidiOut = (wxMidiOutDevice*)NULL;
}

void VZ_EditorFrame::OnMidiReceive(wxCommandEvent &event)
{
    wxMidiError nError;
    wxMidiMessage* pMsg;
    while(m_pMidiIn->Poll())
    {
        pMsg = m_pMidiIn->Read(&nError);
        if(nError || (pMsg->GetType() != wxMIDI_SYSEX_MSG))
        {
            //Only interested in valid SysEx messages
            delete pMsg;
            return;
        }
        wxMidiSysExMessage* pSysEx = (wxMidiSysExMessage*)pMsg;
        long lLength = pSysEx->Length();
        wxByte* pSysExMsg = pSysEx->GetMessage();
        if(lLength < 7 || *(pSysExMsg) != 0xF0 || *(pSysExMsg+1) != 0x44 || *(pSysExMsg+2) != 0x03 || *(pSysExMsg+3) != 0x00 || (*(pSysExMsg+4) & 0xF0) != 0x70 || (*(pSysExMsg+lLength-1) != 0xF7))
        {
            delete pMsg;
            return; //Not a VZ SysEx message
        }
//        unsigned int nChannel = (*(pSysExMsg + 4) & 0x0F);
        unsigned int nType = *(pSysExMsg + 5);
//        m_pLstLog->Append(wxString::Format(wxT("VZ-1/VZ-10 SysEx message. Length %ld. Channel %d. Type %d"), lLength, nChannel + 1, nType));
        switch(nType)
        {
            case MESSAGE_TYPE_VOICE:
            {
                if(lLength != (long)m_pVoiceMidi->GetSize())
                    break;
                m_pVoiceMidi->SetSysEx(pSysExMsg);
                m_pBtnGetVoice->Enable();
                break;
            }
            case MESSAGE_TYPE_OPERATION:
            {
                if(lLength != (long)m_pOperationMidi->GetSize())
                    break;
                m_pOperationMidi->SetSysEx(pSysExMsg);
                m_pBtnGetOperation->Enable();
                break;
            }
            case MESSAGE_TYPE_MULTI:
            case MESSAGE_TYPE_PITCH:
            case MESSAGE_TYPE_MODE:
            case MESSAGE_TYPE_BANK:
                break; //Not implemented
            case MESSAGE_TYPE_OPEN:
                //Start of bulk transfer from VZ device - defines transfer type
                if(lLength != 8)
                    break;
                m_vzSave.OnOpen(*(pSysExMsg + 6));
                break;
            case MESSAGE_TYPE_CLOSE:
                //End of bulk transfer from VZ device
                m_vzSave.OnClose();
                OnVzSave();
                break;
            case MESSAGE_TYPE_OK:
                //Acknowledge of request to start bulk transfer to VZ device
                m_vzSave.OnOk();
                break;
            case MESSAGE_TYPE_ERROR:
                //Error during bulk transfer to VZ device
                m_vzSave.OnError();
                break;
            case MESSAGE_TYPE_DATA:
                //Received bulk transfer data from VZ device
                m_vzSave.OnData(pSysExMsg, lLength);
                break;
            }
        //delete message when no longer needed
        delete pMsg;
    }
}

void VZ_EditorFrame::OnVzSave()
{
    //!@todo What to do when save message received?
    if(m_vzSave.GetAvailable() == VZSAVE_DATATYPE_NONE)
        return;
    for(unsigned int i = 0; i < 64; ++i)
    {
        vzvoice* pVoice = m_vzSave.GetVoice(i);
        if(pVoice)
        {
            wxString sName = pVoice->GetName();
        }
        vzoperation* pOperation = m_vzSave.GetOperation(i);
        if(pOperation)
        {
            wxString sName = pOperation->GetName();
        }
    }
}

void VZ_EditorFrame::Save(unsigned int nType)
{
    wxString sType;
    wxFileDialog dlg(this, wxEmptyString, wxEmptyString, wxEmptyString, wxEmptyString, wxFD_SAVE);
    switch(nType)
    {
        case 0:
            //Library
            dlg.SetWildcard(wxT("Library files (*.xml)|*.xml|All files (*.*)|*.*"));
            break;
        case 1:
            //Voice
            dlg.SetFilename(wxString::Format(wxT("%s.vzt"), m_pVoice->GetName().c_str()));
            dlg.SetWildcard(wxT("VZ tone files (*.vzt)|*.vzt|All files (*.*)|*.*"));
            break;
        case 2:
            //Operation data
            dlg.SetFilename(wxString::Format(wxT("%s.vzo"), m_pOperation->GetName().c_str()));
            dlg.SetWildcard(wxT("VZ operation files (*.vzo)|*.vzo|All files (*.*)|*.*"));
            break;
        default:
            return;
    }
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    if(wxFileExists(dlg.GetPath()) && wxMessageBox(wxT("Do you want to overwrite exiting file?"), wxT("Warning"), wxYES_NO|wxICON_WARNING) != wxYES)
            return;
    wxFile file(dlg.GetPath(), wxFile::write);
    if(!file.IsOpened())
    {
        wxMessageBox(wxT("Failed to save file"), wxT("Error"), wxICON_ERROR);
        return;
    }
    vzsysex* pSysex = NULL;
    switch(nType)
    {
        case 0:
            //Library
            break;
        case 1:
            //Voice
            pSysex = (vzvoice*)m_pVoice;
            break;
        case 2:
            //Operation data
            pSysex = (vzoperation*)m_pOperation;
            break;
        default:
            return;
    }
    if(pSysex)
    {
        pSysex->Validate(true);
        if(file.Write(pSysex->GetSysEx(), pSysex->GetSize()) != pSysex->GetSize())
            wxMessageBox(wxT("Error - corrupt file"), wxT("Error"), wxICON_ERROR);
    }
    file.Close();
}

bool VZ_EditorFrame::LoadFile(wxString sFilename)
{
    if(!wxFileExists(sFilename)) {
        wxMessageBox(wxT("File does not exist"), wxT("Error"), wxICON_ERROR);
        return false;
    }
    wxFile file(sFilename, wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox(wxT("Failed to open file"), wxT("Error"), wxICON_ERROR);
        return false;
    }
    wxByte acSysex[file.Length()];
    if(file.Length() < VZ_HEADER_SIZE || file.Length() != file.Read(acSysex, file.Length()))
    {
        wxMessageBox(wxT("Failed to read file"), wxT("Error"), wxICON_ERROR);
        file.Close();
        return false;
    }
    file.Close();
    bool bFail = true;
    switch(acSysex[VZ_HEADER_TYPE])
    {
        case VZ_TYPE_TONE:
            if(!m_pVoice->SetSysEx(acSysex))
            {
                UpdateVoiceGui();
                m_pNotebook->SetSelection(1);
                bFail = false;
            }
            break;
        case VZ_TYPE_OPERATION:
            if(!m_pOperation->SetSysEx(acSysex))
            {
                UpdateOperationGui();
                m_pNotebook->SetSelection(2);
                bFail = false;
            }
            break;
        default:
            bFail = true;
    }
    if(bFail)
    {
        wxMessageBox(wxT("This does not appear to be a valid VZ file"), wxT("Error"), wxICON_ERROR);
        return false;
    }
    return true;
}

void VZ_EditorFrame::Send()
{
    if(!m_pMidiOut)
        return;
    vzsysex* pSysex = NULL;
    switch(m_pNotebook->GetSelection())
    {
        case 0: //Library
            return;
            break;
        case 1: //Voice
            pSysex = (vzvoice*)m_pVoice;
            break;
        case 2: //Operation data
            pSysex = (vzoperation*)m_pOperation;
            break;
        default:
            return;
    }
    pSysex->Validate(true);
    wxMidiSysExMessage sysExMsg(pSysex->GetSysEx());
    m_pMidiOut->Write(&sysExMsg);
}

void VZ_EditorFrame::GetVoice()
{
    m_pVoice->SetSysEx(m_pVoiceMidi->GetSysEx());
    UpdateVoiceGui();
}

void VZ_EditorFrame::GetOperation()
{
    m_pOperation->SetSysEx(m_pOperationMidi->GetSysEx());
    UpdateOperationGui();
}

void VZ_EditorFrame::UpdateVoiceGui()
{
    m_pTxtVoiceName->SetValue(m_pVoice->GetName());
    m_pSliderLevel->SetValue(m_pVoice->GetLevel());
    m_pSliderOctave->SetValue(m_pVoice->GetOctave());
    m_pSliderVelSens->SetValue(m_pVoice->GetPitchVelSens());
    m_pCmbVelCurve->SetSelection(m_pVoice->GetPitchVelCurve());
    m_pRadioTremeloMulti->SetSelection(m_pVoice->IsTremeloMulti()?1:0);
    m_pRadioTremeloWaveform->SetSelection(m_pVoice->GetTremeloWaveform());
    m_pSliderTremeloDepth->SetValue(m_pVoice->GetTremeloDepth());
    m_pSliderTremeloRate->SetValue(m_pVoice->GetTremeloRate());
    m_pSliderTremeloDelay->SetValue(m_pVoice->GetTremeloDelay());
    m_pRadioVibratoMulti->SetSelection(m_pVoice->IsVibratoMulti()?1:0);
    m_pRadioVibratoWaveform->SetSelection(m_pVoice->GetVibratoWaveform());
    m_pSliderVibratoDepth->SetValue(m_pVoice->GetVibratoDepth());
    m_pSliderVibratoRate->SetValue(m_pVoice->GetVibratoRate());
    m_pSliderVibratoDelay->SetValue(m_pVoice->GetVibratoDelay());
    m_pLine1->UpdateGui();
    m_pLine2->UpdateGui();
    m_pLine3->UpdateGui();
    m_pLine4->UpdateGui();
}

void VZ_EditorFrame::UpdateOperationGui()
{
    m_pTxtOperationName->SetValue(m_pOperation->GetName());
}

void VZ_EditorFrame::OnBtnSendClick(wxCommandEvent& event)
{
    Send();
}

void VZ_EditorFrame::OnTxtVoiceNameText(wxCommandEvent& event)
{
    m_pVoice->SetName(m_pTxtVoiceName->GetValue());
    AutoSend();
}

void VZ_EditorFrame::OnRadioTremeloMultiSelect(wxCommandEvent& event)
{
    m_pVoice->EnableTremeloMulti(event.GetInt() == 1);
    AutoSend();
}

void VZ_EditorFrame::OnCmbVelCurveSelect(wxCommandEvent& event)
{
    m_pVoice->SetPitchVelCurve(event.GetSelection());
    AutoSend();
}

void VZ_EditorFrame::OnRadioTremeloWaveformSelect(wxCommandEvent& event)
{
    m_pVoice->SetTremeloWaveform(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnRadioVibratoMultiSelect(wxCommandEvent& event)
{
    m_pVoice->EnableVibratoMulti(event.GetInt() == 1);
    AutoSend();
}

void VZ_EditorFrame::OnRadioVibratoWaveformSelect(wxCommandEvent& event)
{
    m_pVoice->SetVibratoWaveform(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxEmptyString, wxEmptyString, wxEmptyString,wxT("Library files (*.xml)|*.xml|VZ tone files (*vzt)|*.vzt|VZ operation files (*vzo)|*.vzo|All files (*.*)|*.*"), wxFD_OPEN);
    dlg.SetFilterIndex(m_pNotebook->GetSelection());
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    wxFileName fnFilename(dlg.GetPath());
    if(fnFilename.GetExt().Lower().IsSameAs(wxT("xml")))
    {
        if(m_pvzLib->IsDirty())
            ; //!@todo Handle dirty library
        m_pvzLib->Load(dlg.GetPath());
        m_pLstLib->SetData(m_pvzLib);
        return;
    }
    LoadFile(dlg.GetPath());
}

void VZ_EditorFrame::OnLibSort(wxListEvent& event)
{
    m_pLstLib->Sort(event.GetColumn());
}

void VZ_EditorFrame::OnLibActivate(wxListEvent& event)
{
    wxString sFilename = m_pLstLib->GetItemFilename(event.GetIndex());
    wxString sType = m_pLstLib->GetItemType(event.GetIndex());
    if(LoadFile(wxT("library/") + sFilename)) //!@todo configure path to library
        m_pNotebook->SetSelection(1);
}

void VZ_EditorFrame::OnBtnGetVoice(wxCommandEvent& event)
{
    GetVoice();
    m_pNotebook->SetSelection(1);
}

void VZ_EditorFrame::OnBtnGetOperation(wxCommandEvent& event)
{
    GetOperation();
    m_pNotebook->SetSelection(2);
}

void VZ_EditorFrame::OnSaveFile(wxCommandEvent& event)
{
    Save(m_pNotebook->GetSelection());
}

void VZ_EditorFrame::UpdateMidiPorts()
{
    m_pCmbInPort->Clear();
    m_pCmbOutPort->Clear();
    int nDevices = Pm_CountDevices();
    for(int i = 0; i < nDevices; ++i)
    {
        const PmDeviceInfo* pInfo = Pm_GetDeviceInfo(i);
        if(pInfo->input)
        {
            int nIndex = m_pCmbInPort->Append(wxString::FromUTF8(pInfo->name));
            m_pCmbInPort->SetClientData(nIndex, (void*)pInfo);
        }
        if(pInfo->output)
        {
            int nIndex = m_pCmbOutPort->Append(wxString::FromUTF8(pInfo->name));
            m_pCmbOutPort->SetClientData(nIndex, (void*)pInfo);
        }
    }
}

void VZ_EditorFrame::AutoSend()
{
    if(m_pChkAutoUpdate->IsChecked())
        Send();
}

void VZ_EditorFrame::OnLevelChanged(wxScrollEvent& event)
{
    m_pVoice->SetLevel(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnOctaveChanged(wxScrollEvent& event)
{
    m_pVoice->SetOctave(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnDcoVelSensChange(wxScrollEvent& event)
{
    m_pVoice->SetPitchVelSens(event.GetInt());
    AutoSend();
}


void VZ_EditorFrame::OnTremeloDepthChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloDepth(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnTremeloRateChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloRate(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnTremeloDelayChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloDelay(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnVibratoDepthChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoDepth(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnVibratoRateChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoRate(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnVibratoDelayChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoDelay(event.GetInt());
    AutoSend();
}


void VZ_EditorFrame::OnBtnSaveDump(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxT("Select filename and folder to save new library"), wxEmptyString, wxT("NewLibrary.xml"), wxT("Library files (*.xml)|*.xml|All files (*.*)|*.*"), wxFD_SAVE);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    m_vzSave.SaveToDisk(dlg.GetPath());
}
