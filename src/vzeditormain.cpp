/***************************************************************
 * Name:      VZ_EditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#include "vzeditormain.h"
#include <wx/msgdlg.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/config.h>
#include <wx/display.h>

//(*InternalHeaders(VZ_EditorFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


//(*IdInit(VZ_EditorFrame)
const long VZ_EditorFrame::ID_STATICTEXT2 = wxNewId();
const long VZ_EditorFrame::ID_CMBINPORT = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT1 = wxNewId();
const long VZ_EditorFrame::ID_CMBOUTPORT = wxNewId();
const long VZ_EditorFrame::ID_CHKAUTOUPDATE = wxNewId();
const long VZ_EditorFrame::ID_BTNSEND = wxNewId();
const long VZ_EditorFrame::ID_BTNGETVOICE = wxNewId();
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
const long VZ_EditorFrame::ID_NOTEBOOK = wxNewId();
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
    wxFlexGridSizer* FlexGridSizer10;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer12;
    wxFlexGridSizer* FlexGridSizer13;
    wxFlexGridSizer* FlexGridSizer14;
    wxFlexGridSizer* FlexGridSizer15;
    wxFlexGridSizer* FlexGridSizer1;
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
    m_pBtnSend = new wxButton(this, ID_BTNSEND, _("Send Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSEND"));
    FlexGridSizer1->Add(m_pBtnSend, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetVoice = new wxButton(this, ID_BTNGETVOICE, _("Get Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETVOICE"));
    m_pBtnGetVoice->Disable();
    FlexGridSizer1->Add(m_pBtnGetVoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    FlexGridSizer3->AddGrowableRow(1);
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
    FlexGridSizer5->AddGrowableRow(1);
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
    m_pNotebook->AddPage(m_pPnlLibrary, _("Voice Library"), false);
    m_pNotebook->AddPage(m_pPnlVoice, _("Voice Editor"), false);
    m_pSizerMain->Add(m_pNotebook, 1, wxALL|wxEXPAND, 5);
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
    m_pvzLib = new VZLibrary();
    m_pLstLib->SetData(m_pvzLib);

    m_pLine1->SetVoice(&m_vzVoice);
    m_pLine2->SetVoice(&m_vzVoice);
    m_pLine3->SetVoice(&m_vzVoice);
    m_pLine4->SetVoice(&m_vzVoice);
}

VZ_EditorFrame::~VZ_EditorFrame()
{
    delete m_pvzLib;
}

void VZ_EditorFrame::OnClose(wxCloseEvent& event)
{
    wxConfig configPersist(wxTheApp->GetAppName(), wxT("riban"),wxEmptyString, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
    configPersist.Write(wxT("persist/midi_out"), m_pCmbOutPort->GetSelection());
    configPersist.Write(wxT("persist/midi_in"), m_pCmbInPort->GetSelection());
    configPersist.Write(wxT("persist/maximised"), IsMaximized());
	if(!IsMaximized() && !IsIconized())
	{
        configPersist.Write(wxT("persist/width"), GetSize().GetWidth());
        configPersist.Write(wxT("persist/height"), GetSize().GetHeight());
        configPersist.Write(wxT("persist/left"), GetPosition().x);
        configPersist.Write(wxT("persist/top"), GetPosition().y);
	}
    event.Skip();
}

void VZ_EditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void VZ_EditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Casio VZ-1 / VZ-10M / VZ-8 Library and editor"));
}

void VZ_EditorFrame::OnInPortSelect(wxCommandEvent& event)
{
//    CloseInput();
    int nPort = (int)(long)event.GetClientData();
    m_pMidiIn = new wxMidiInDevice(nPort);
    m_pMidiIn->Open();
    m_pMidiIn->StartListening(this);
}

void VZ_EditorFrame::OnOutPortSelect(wxCommandEvent& event)
{
    CloseOutput();
    int nPort = (int)(long)event.GetClientData();
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
                if(lLength != (long)m_vzVoiceMidi.GetSize())
                    break;
                m_vzVoiceMidi.SetSysEx(pSysExMsg);
                m_pBtnGetVoice->Enable();
                break;
            }
            case MESSAGE_TYPE_OPERATION:
            {
                //!@todo Implement operational
                break;
            }
        }
        //delete message when no longer needed
        delete pMsg;
    }
}

void VZ_EditorFrame::SaveVoice()
{
    wxFileDialog dlg(this, wxT("Select file to save voice to"),wxEmptyString, wxString::Format(wxT("%s.syx"), m_vzVoice.GetName().Trim().c_str()), wxT("SysEx files (*.syx)|*.syx|All files (*.*)|*.*"), wxFD_SAVE);
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
    wxByte acSysex[m_vzVoice.GetSize()];
    m_vzVoice.Validate(true);
    m_vzVoice.GetSysEx(acSysex);
    if(file.Write(m_vzVoice.GetSysEx(), m_vzVoice.GetSize()) != m_vzVoice.GetSize())
        wxMessageBox(wxT("Error - corrupt file"), wxT("Error"), wxICON_ERROR);
    file.Close();
}

bool VZ_EditorFrame::LoadVoice(wxString sFilename)
{
    wxFile file(sFilename, wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox(wxT("Failed to open file"), wxT("Error"), wxICON_ERROR);
        return false;
    }
    wxByte acSysex[m_vzVoice.GetSize()];
    if(file.Length() != (wxFileOffset)m_vzVoice.GetSize() || file.Read(acSysex, m_vzVoice.GetSize()) != (ssize_t)m_vzVoice.GetSize())
    {
        wxMessageBox(wxT("Corrupt file"), wxT("Error"), wxICON_ERROR);
        file.Close();
        return false;
    }
    file.Close();
    if(m_vzVoice.SetSysEx(acSysex))
    {
        wxMessageBox(wxT("Invalid VZ voice file"), wxT("Error"), wxICON_ERROR);
        return false;
    }
    m_pNotebook->SetSelection(1);
    UpdateGui();
    return true;
}

void VZ_EditorFrame::SendVoice()
{
    if(!m_pMidiOut)
        return;
    m_vzVoice.Validate(true);
    wxMidiSysExMessage sysExMsg(m_vzVoice.GetSysEx());
    m_pMidiOut->Write(&sysExMsg);
}

void VZ_EditorFrame::GetVoice()
{
    m_vzVoice.SetSysEx(m_vzVoiceMidi.GetSysEx());
    UpdateGui();
}

void VZ_EditorFrame::UpdateGui()
{
    m_pTxtVoiceName->SetValue(m_vzVoice.GetName());
    m_pSliderLevel->SetValue(m_vzVoice.GetLevel());
    m_pSliderOctave->SetValue(m_vzVoice.GetOctave());
    m_pSliderVelSens->SetValue(m_vzVoice.GetPitchVelSens());
    m_pCmbVelCurve->SetSelection(m_vzVoice.GetPitchVelCurve());
    m_pRadioTremeloMulti->SetSelection(m_vzVoice.IsTremeloMulti()?1:0);
    m_pRadioTremeloWaveform->SetSelection(m_vzVoice.GetTremeloWaveform());
    m_pSliderTremeloDepth->SetValue(m_vzVoice.GetTremeloDepth());
    m_pSliderTremeloRate->SetValue(m_vzVoice.GetTremeloRate());
    m_pSliderTremeloDelay->SetValue(m_vzVoice.GetTremeloDelay());
    m_pRadioVibratoMulti->SetSelection(m_vzVoice.IsVibratoMulti()?1:0);
    m_pRadioVibratoWaveform->SetSelection(m_vzVoice.GetVibratoWaveform());
    m_pSliderVibratoDepth->SetValue(m_vzVoice.GetVibratoDepth());
    m_pSliderVibratoRate->SetValue(m_vzVoice.GetVibratoRate());
    m_pSliderVibratoDelay->SetValue(m_vzVoice.GetVibratoDelay());
    m_pLine1->UpdateGui();
    m_pLine2->UpdateGui();
    m_pLine3->UpdateGui();
    m_pLine4->UpdateGui();
}

void VZ_EditorFrame::OnBtnSendClick(wxCommandEvent& event)
{
    SendVoice();
}

void VZ_EditorFrame::OnTxtVoiceNameText(wxCommandEvent& event)
{
    m_vzVoice.SetName(m_pTxtVoiceName->GetValue());
    AutoSend();
}

void VZ_EditorFrame::OnRadioTremeloMultiSelect(wxCommandEvent& event)
{
    m_vzVoice.EnableTremeloMulti(event.GetInt() == 1);
    AutoSend();
}

void VZ_EditorFrame::OnCmbVelCurveSelect(wxCommandEvent& event)
{
    m_vzVoice.SetPitchVelCurve(event.GetSelection());
    AutoSend();
}

void VZ_EditorFrame::OnRadioTremeloWaveformSelect(wxCommandEvent& event)
{
    m_vzVoice.SetTremeloWaveform(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnRadioVibratoMultiSelect(wxCommandEvent& event)
{
    m_vzVoice.EnableVibratoMulti(event.GetInt() == 1);
    AutoSend();
}

void VZ_EditorFrame::OnRadioVibratoWaveformSelect(wxCommandEvent& event)
{
    m_vzVoice.SetVibratoWaveform(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxT("Select file to open"),wxEmptyString, wxEmptyString, wxT("SysEx files (*.syx)|*.syx|Library (*.xml)|*.xml|All files (*.*)|*.*"), wxFD_OPEN);
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
    LoadVoice(dlg.GetPath());
}

void VZ_EditorFrame::OnLibSort(wxListEvent& event)
{
    m_pLstLib->Sort(event.GetColumn());
}

void VZ_EditorFrame::OnLibActivate(wxListEvent& event)
{
    wxString sFilename = m_pLstLib->GetItemFilename(event.GetIndex());
    if(LoadVoice(wxT("library/") + sFilename)) //!@todo configure path to library
        m_pNotebook->SetSelection(1);
}

void VZ_EditorFrame::OnBtnGetVoice(wxCommandEvent& event)
{
    GetVoice();
    m_pNotebook->SetSelection(1);
}

void VZ_EditorFrame::OnSaveFile(wxCommandEvent& event)
{
    SaveVoice();
}

void VZ_EditorFrame::OnLoadFile(wxCommandEvent& event)
{
    LoadVoice();
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
            m_pCmbInPort->SetClientData(nIndex, (void*)(long)i);
        }
        if(pInfo->output)
        {
            int nIndex = m_pCmbOutPort->Append(wxString::FromUTF8(pInfo->name));
            m_pCmbOutPort->SetClientData(nIndex, (void*)(long)i);
        }
    }
}

void VZ_EditorFrame::AutoSend()
{
    if(m_pChkAutoUpdate)
        SendVoice();
}

void VZ_EditorFrame::OnLevelChanged(wxScrollEvent& event)
{
    m_vzVoice.SetLevel(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnOctaveChanged(wxScrollEvent& event)
{
    m_vzVoice.SetOctave(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnDcoVelSensChange(wxScrollEvent& event)
{
    m_vzVoice.SetPitchVelSens(event.GetInt());
    AutoSend();
}


void VZ_EditorFrame::OnTremeloDepthChanged(wxScrollEvent& event)
{
    m_vzVoice.SetTremeloDepth(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnTremeloRateChanged(wxScrollEvent& event)
{
    m_vzVoice.SetTremeloRate(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnTremeloDelayChanged(wxScrollEvent& event)
{
    m_vzVoice.SetTremeloDelay(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnVibratoDepthChanged(wxScrollEvent& event)
{
    m_vzVoice.SetVibratoDepth(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnVibratoRateChanged(wxScrollEvent& event)
{
    m_vzVoice.SetVibratoRate(event.GetInt());
    AutoSend();
}

void VZ_EditorFrame::OnVibratoDelayChanged(wxScrollEvent& event)
{
    m_vzVoice.SetVibratoDelay(event.GetInt());
    AutoSend();
}
