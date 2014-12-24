/***************************************************************
 * Name:      sysexMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2014-12-15
 * Copyright: Brian Walton (riban.co.uk)
 * License:
 **************************************************************/

#include "vz1editormain.h"
#include <wx/msgdlg.h>
#include <wx/log.h>
#include <wx/file.h>
#include <wx/stdpaths.h>

//(*InternalHeaders(sysexFrame)
#include <wx/string.h>
#include <wx/intl.h>
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

//(*IdInit(sysexFrame)
const long sysexFrame::ID_STATICTEXT2 = wxNewId();
const long sysexFrame::ID_CHOICE1 = wxNewId();
const long sysexFrame::ID_STATICTEXT1 = wxNewId();
const long sysexFrame::ID_CHOICE2 = wxNewId();
const long sysexFrame::ID_CHECKBOX1 = wxNewId();
const long sysexFrame::ID_BUTTON1 = wxNewId();
const long sysexFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long sysexFrame::ID_STATICTEXT3 = wxNewId();
const long sysexFrame::ID_TEXTCTRL1 = wxNewId();
const long sysexFrame::ID_STATICTEXT30 = wxNewId();
const long sysexFrame::ID_SLIDER26 = wxNewId();
const long sysexFrame::ID_STATICTEXT10 = wxNewId();
const long sysexFrame::ID_SLIDER7 = wxNewId();
const long sysexFrame::ID_STATICTEXT11 = wxNewId();
const long sysexFrame::ID_SLIDER8 = wxNewId();
const long sysexFrame::ID_STATICTEXT12 = wxNewId();
const long sysexFrame::ID_CHOICE4 = wxNewId();
const long sysexFrame::ID_RADIOBOX2 = wxNewId();
const long sysexFrame::ID_STATICTEXT6 = wxNewId();
const long sysexFrame::ID_STATICTEXT5 = wxNewId();
const long sysexFrame::ID_STATICTEXT4 = wxNewId();
const long sysexFrame::ID_RADIOBOX1 = wxNewId();
const long sysexFrame::ID_SLIDER3 = wxNewId();
const long sysexFrame::ID_SLIDER2 = wxNewId();
const long sysexFrame::ID_SLIDER1 = wxNewId();
const long sysexFrame::ID_RADIOBOX3 = wxNewId();
const long sysexFrame::ID_STATICTEXT7 = wxNewId();
const long sysexFrame::ID_STATICTEXT8 = wxNewId();
const long sysexFrame::ID_STATICTEXT9 = wxNewId();
const long sysexFrame::ID_RADIOBOX4 = wxNewId();
const long sysexFrame::ID_SLIDER5 = wxNewId();
const long sysexFrame::ID_SLIDER4 = wxNewId();
const long sysexFrame::ID_SLIDER6 = wxNewId();
const long sysexFrame::ID_PANEL1 = wxNewId();
const long sysexFrame::idMenuOpen = wxNewId();
const long sysexFrame::idMenuSave = wxNewId();
const long sysexFrame::idMenuQuit = wxNewId();
const long sysexFrame::idMenuAbout = wxNewId();
const long sysexFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(sysexFrame,wxFrame)
    //(*EventTable(sysexFrame)
    //*)
    EVT_COMMAND(wxID_ANY, wxEVT_MIDI_INPUT, sysexFrame::OnMidiReceive)
    EVT_COMMAND(wxID_ANY, wxEVT_VZ_MODULE, sysexFrame::OnModuleEvent)
END_EVENT_TABLE()

sysexFrame::sysexFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(sysexFrame)
    wxStaticBoxSizer* StaticBoxSizer2;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer4;
    wxMenuItem* menuAbout;
    wxFlexGridSizer* FlexGridSizer3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenuItem* menuQuit;
    wxMenu* Menu2;
    wxFlexGridSizer* FlexGridSizer5;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    m_pSizerMain = new wxFlexGridSizer(0, 1, 0, 0);
    m_pSizerMain->AddGrowableCol(0);
    m_pSizerMain->AddGrowableRow(1);
    FlexGridSizer1 = new wxFlexGridSizer(0, 0, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("MIDI Input Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbInPort = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(181,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer1->Add(m_pCmbInPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("MIDI Output Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbOutPort = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(181,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer1->Add(m_pCmbOutPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkAutoUpdate = new wxCheckBox(this, ID_CHECKBOX1, _("Auto Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_pChkAutoUpdate->SetValue(false);
    FlexGridSizer1->Add(m_pChkAutoUpdate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSend = new wxButton(this, ID_BUTTON1, _("Send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(m_pBtnSend, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSizerMain->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    m_pScrollWinVoiceEditor = new wxScrolledWindow(Panel1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    m_pModule1 = new vzVoiceModule(m_pScrollWinVoiceEditor,0, VZVOICE_STYLE_TITLE);
    BoxSizer1->Add(m_pModule1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule3 = new vzVoiceModule(m_pScrollWinVoiceEditor,1);
    BoxSizer1->Add(m_pModule3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule2 = new vzVoiceModule(m_pScrollWinVoiceEditor,2);
    BoxSizer1->Add(m_pModule2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule4 = new vzVoiceModule(m_pScrollWinVoiceEditor,3);
    BoxSizer1->Add(m_pModule4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule5 = new vzVoiceModule(m_pScrollWinVoiceEditor,4);
    BoxSizer1->Add(m_pModule5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule6 = new vzVoiceModule(m_pScrollWinVoiceEditor,5);
    BoxSizer1->Add(m_pModule6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule7 = new vzVoiceModule(m_pScrollWinVoiceEditor,6);
    BoxSizer1->Add(m_pModule7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pModule8 = new vzVoiceModule(m_pScrollWinVoiceEditor,7);
    BoxSizer1->Add(m_pModule8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pScrollWinVoiceEditor->SetSizer(BoxSizer1);
    BoxSizer1->Fit(m_pScrollWinVoiceEditor);
    BoxSizer1->SetSizeHints(m_pScrollWinVoiceEditor);
    FlexGridSizer2->Add(m_pScrollWinVoiceEditor, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 0, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Voice Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtVoiceName = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(125,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer4->Add(m_pTxtVoiceName, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer7->AddGrowableCol(1);
    StaticText30 = new wxStaticText(Panel1, ID_STATICTEXT30, _("Level"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer7->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderLevel = new wxSlider(Panel1, ID_SLIDER26, 99, 0, 99, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER26"));
    FlexGridSizer7->Add(m_pSliderLevel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Octave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer7->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderOctave = new wxSlider(Panel1, ID_SLIDER7, 0, -2, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDER7"));
    FlexGridSizer7->Add(m_pSliderOctave, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Velocity\nSensitivity"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT11"));
    FlexGridSizer7->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVelSens = new wxSlider(Panel1, ID_SLIDER8, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDER8"));
    FlexGridSizer7->Add(m_pSliderVelSens, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pLblVelCurve = new wxStaticText(Panel1, ID_STATICTEXT12, _("Curve"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer7->Add(m_pLblVelCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbVelCurve = new wxChoice(Panel1, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    m_pCmbVelCurve->SetSelection( m_pCmbVelCurve->Append(_("Curve 1")) );
    m_pCmbVelCurve->Append(_("Curve 2"));
    m_pCmbVelCurve->Append(_("Curve 3"));
    m_pCmbVelCurve->Append(_("Curve 4"));
    m_pCmbVelCurve->Append(_("Curve 5"));
    m_pCmbVelCurve->Append(_("Curve 6"));
    m_pCmbVelCurve->Append(_("Curve 7"));
    m_pCmbVelCurve->Append(_("Curve 8"));
    FlexGridSizer7->Add(m_pCmbVelCurve, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(FlexGridSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Tremelo"));
    FlexGridSizer3 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer3->AddGrowableRow(1);
    wxString __wxRadioBoxChoices_1[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioTremeloMulti = new wxRadioBox(Panel1, ID_RADIOBOX2, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX2"));
    FlexGridSizer3->Add(m_pRadioTremeloMulti, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_2[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioTremeloWaveform = new wxRadioBox(Panel1, ID_RADIOBOX1, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_2, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX1"));
    FlexGridSizer3->Add(m_pRadioTremeloWaveform, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloDepth = new wxSlider(Panel1, ID_SLIDER3, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER3"));
    m_pSliderTremeloDepth->SetMinSize(wxSize(0,0));
    FlexGridSizer3->Add(m_pSliderTremeloDepth, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloRate = new wxSlider(Panel1, ID_SLIDER2, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_TOP|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER2"));
    m_pSliderTremeloRate->SetMinSize(wxSize(0,0));
    FlexGridSizer3->Add(m_pSliderTremeloRate, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloDelay = new wxSlider(Panel1, ID_SLIDER1, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_TOP|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER1"));
    FlexGridSizer3->Add(m_pSliderTremeloDelay, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Vibrato"));
    FlexGridSizer5 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer5->AddGrowableRow(1);
    wxString __wxRadioBoxChoices_3[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioVibratoMulti = new wxRadioBox(Panel1, ID_RADIOBOX3, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX3"));
    FlexGridSizer5->Add(m_pRadioVibratoMulti, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer5->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer5->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer5->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_4[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioVibratoWaveform = new wxRadioBox(Panel1, ID_RADIOBOX4, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_4, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX4"));
    FlexGridSizer5->Add(m_pRadioVibratoWaveform, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoDepth = new wxSlider(Panel1, ID_SLIDER5, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER5"));
    FlexGridSizer5->Add(m_pSliderVibratoDepth, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoRate = new wxSlider(Panel1, ID_SLIDER4, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER4"));
    FlexGridSizer5->Add(m_pSliderVibratoRate, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoDelay = new wxSlider(Panel1, ID_SLIDER6, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER6"));
    FlexGridSizer5->Add(m_pSliderVibratoDelay, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(FlexGridSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(Panel1);
    FlexGridSizer2->SetSizeHints(Panel1);
    m_pSizerMain->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(m_pSizerMain);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menuOpen = new wxMenuItem(Menu1, idMenuOpen, _("Open Patch\tctrl+o"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(menuOpen);
    menuSave = new wxMenuItem(Menu1, idMenuSave, _("Save Patch\tctrl+s"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(menuSave);
    menuQuit = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(menuQuit);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    menuAbout = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(menuAbout);
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

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&sysexFrame::OnInPortSelect);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&sysexFrame::OnOutPortSelect);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&sysexFrame::OnChkAutoUpdateClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&sysexFrame::OnBtnSendClick);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&sysexFrame::OnTxtVoiceNameText);
    Connect(ID_SLIDER26,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderLevelCmdScrollChanged);
    Connect(ID_SLIDER7,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderOctaveCmdScrollChanged);
    Connect(ID_SLIDER8,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderVelSensCmdScrollChanged);
    Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&sysexFrame::OnCmbVelCurveSelect);
    Connect(ID_RADIOBOX2,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&sysexFrame::OnRadioTremeloMultiSelect);
    Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&sysexFrame::OnRadioTremeloWaveformSelect);
    Connect(ID_SLIDER3,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderTremeloDepthCmdScrollChanged);
    Connect(ID_SLIDER2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderTremeloRateCmdScrollChanged);
    Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderTremeloDelayCmdScrollChanged);
    Connect(ID_RADIOBOX3,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&sysexFrame::OnRadioVibratoMultiSelect);
    Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&sysexFrame::OnRadioVibratoWaveformSelect);
    Connect(ID_SLIDER5,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderVibratoDepthCmdScrollChanged);
    Connect(ID_SLIDER4,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderVibratoRateCmdScrollChanged);
    Connect(ID_SLIDER6,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&sysexFrame::OnSliderVibratoDelayCmdScrollChanged);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sysexFrame::OnmenuOpenSelected);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sysexFrame::OnmenuSaveSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sysexFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&sysexFrame::OnAbout);
    //*)

    m_pScrollWinVoiceEditor->SetScrollRate(1, 1);

    m_pMidiIn = (wxMidiInDevice*)NULL;
    m_pMidiOut = (wxMidiOutDevice*)NULL;
    m_bAutoUpdate = false;
    m_pMidi = wxMidiSystem::GetInstance();

    int nDevices = Pm_CountDevices();
	int i;
	for(i = 0; i < nDevices; ++i)
	{
		const PmDeviceInfo* pInfo = Pm_GetDeviceInfo(i);
		if(pInfo->input)
        {
            int nIndex = m_pCmbInPort->Append(pInfo->name);
            m_pCmbInPort->SetClientData(nIndex, (void*)(long)i);
        }
		if(pInfo->output)
        {
            int nIndex = m_pCmbOutPort->Append(pInfo->name);
            m_pCmbOutPort->SetClientData(nIndex, (void*)(long)i);
        }
	}
	m_pModule1->SetVoiceData(m_aVoice);
	m_pModule2->SetVoiceData(m_aVoice);
	m_pModule3->SetVoiceData(m_aVoice);
	m_pModule4->SetVoiceData(m_aVoice);
	m_pModule5->SetVoiceData(m_aVoice);
	m_pModule6->SetVoiceData(m_aVoice);
	m_pModule7->SetVoiceData(m_aVoice);
	m_pModule8->SetVoiceData(m_aVoice);

    wxString sFilename = wxStandardPaths::Get().GetUserLocalDataDir();
    if(!wxDirExists(sFilename))
    {
        if(!wxMkdir(sFilename))
            wxMessageBox(wxString::Format("User data directory (%s) is missing and cannot be created. This may result in reduced functionality and errors", "Error", sFilename.c_str()));
    }
    sFilename += "/vz.tmp";
    if(wxFileExists(sFilename))
        OpenPatch(sFilename);
}

sysexFrame::~sysexFrame()
{
    wxString sFilename = wxStandardPaths::Get().GetUserLocalDataDir();
    sFilename += "/vz.tmp";
    SavePatch(sFilename);
    CloseInput();
    CloseOutput();
    if(m_pMidi)
        delete m_pMidi;
}

void sysexFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void sysexFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("riban VZ1/VZ10 Patch Editor"));
}

void sysexFrame::OnInPortSelect(wxCommandEvent& event)
{
    CloseInput();
    int nPort = (int)(long)event.GetClientData();
    m_pMidiIn = new wxMidiInDevice(nPort);
    m_pMidiIn->Open();
    m_pMidiIn->StartListening(this);
}

void sysexFrame::OnOutPortSelect(wxCommandEvent& event)
{
    CloseOutput();
    int nPort = (int)(long)event.GetClientData();
    m_pMidiOut = new wxMidiOutDevice(nPort);
    m_pMidiOut->Open(0); //!@todo Chose appropriate latency
}

void sysexFrame::OnBtnSendClick(wxCommandEvent& event)
{
    SendVoice();
}

void sysexFrame::OnMidiReceive(wxCommandEvent& event)
{
    event.Skip(true); //Do not propogate this event
    wxString sMsg;
    wxMidiError nErr;
    //Process all recieved messages
    while(m_pMidiIn->Poll())
    {
        wxMidiMessage* pMidiMsg = m_pMidiIn->Read(&nErr);
        switch(nErr)
        {
            case wxMIDI_ERROR_NoDataAvailable:
                break;
            case wxMIDI_NO_ERROR:
            {
                switch(pMidiMsg->GetType())
                {
                    case wxMIDI_SHORT_MSG:
                    {
                        wxMidiShortMessage* pMsg = (wxMidiShortMessage*)pMidiMsg;
                        wxLogDebug("Received short message: %02X %02X %02X",
                                                        pMsg->GetStatus(),
                                                        pMsg->GetData1(),
                                                        pMsg->GetData2());
                        delete pMsg; // do not forget!!
                        break;
                    }
                    case wxMIDI_SYSEX_MSG:
                    {
                        wxMidiSysExMessage* pMsg = (wxMidiSysExMessage*)pMidiMsg;
                        wxByte* pData = pMsg->GetMessage();
                        if(pMsg->Length() > 7)
                        {
                            //Header long enough
                            if(0xF0 == pData[0] && 0x44 == pData[1] && 0x03 == pData[2] && 0x00 == pData[3] && 0x70 == (pData[4] & 0xF0))
                            {
                                wxLogDebug("Sysex message from Casio - length = %d", pMsg->Length());
                                switch(pData[5])
                                {
                                    case 0x00: //Tone data
                                    {
                                        wxLogDebug("Tone data recieved for C/R %d", pData[6] - 0x40);
                                        if(pMsg->Length() < 681)
                                        {
                                            wxLogDebug("Short message!!!");
                                            break;
                                        }
                                        //Each byte is transmitted as two bytes with most significant nibble of each set to 0. MSB sent first.
                                        wxByte nChecksum = 0;
                                        for(int i = 0; i < 336; ++i)
                                        {
                                            m_aVoice[i] = (pData[7 + i * 2] << 4) + pData[8 + i * 2];
                                            nChecksum += m_aVoice[i];
                                        }
                                        nChecksum += pData[679];
                                        if(0x00 != (0x7F & nChecksum))
                                            wxLogDebug("Checksum error"); //!@todo Handle checksum error
                                        else
                                        {
                                            UpdateVoice();
                                        }
                                        break;
                                    }
                                    case 0x01: //Operational data
                                    {
                                        wxLogDebug("Operational data recieved for sound area %02X", pData[6]);
                                        if(pMsg->Length() < 209)
                                        {
                                            wxLogDebug("Short message!!!");
                                            break;
                                        }
                                        wxByte nChecksum = 0;
                                        for(int i = 0; i < 100; ++i)
                                        {
                                            m_aOp[i] = (pData[7 + i * 2] << 4) + pData[8 + i * 2];
                                            nChecksum += m_aOp[i];
                                        }
                                        nChecksum += pData[207];
                                        if(0x00 != (0x7F & nChecksum))
                                            wxLogDebug("Checksum error"); //!@todo Handle checksum error
                                        break;
                                    }
                                    case 0x02: //Multi Channel Mode data
                                    {
                                        wxLogDebug("Multi channel mode data recieved");
                                        break;
                                    }
                                    case 0x40: //Various configs
                                    {
                                        switch(pData[6])
                                        {
                                            case 0x00: //Master Tune
                                            {
                                                wxLogDebug("Master Tune %d", (pData[7] << 4) + pData[8]);
                                                break;
                                            }
                                            case 0x01: //Key transpose
                                            {
                                                wxLogDebug("Key transpose", (pData[7] << 4) + pData[8]);
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 0x50: //Mode change
                                    {
                                        switch(pData[6])
                                        {
                                            case 0x00:
                                                wxLogDebug("Normal Mode");
                                                break;
                                            case 0x01:
                                                wxLogDebug("Combination Mode");
                                                break;
                                            case 0x02:
                                                wxLogDebug("OPerationa Memory Mode");
                                                break;
                                            case 0x03:
                                                wxLogDebug("Multichannel Mode");
                                                break;
                                            case 0x04:
                                                wxLogDebug("Multichannel Mode Poly = 0");
                                                break;
                                            case 0x05:
                                                wxLogDebug("Multichannel Mode Poly = 1");
                                                break;
                                        }
                                        break;
                                    }
                                    case 0x51: //Card bank change
                                    {
                                        wxLogDebug("Card bank changed to %d", pData[6]);
                                        break;
                                    }
                                    case 0x70: //Save/Load Open
                                    {
                                        wxLogDebug("Save / Load Open");
                                        break;
                                    }
                                    case 0x71: //Save/Load Close
                                    {
                                        wxLogDebug("Save / Load Close");
                                        break;
                                    }
                                    case 0x72: //Save/Load OK
                                    {
                                        wxLogDebug("Save / Load OK");
                                        break;
                                    }
                                    case 0x73: //Save/Load Error
                                    {
                                        wxLogDebug("Save / Load Error");
                                        break;
                                    }
                                    case 0x74: //Save/Load Data
                                    {
                                        wxLogDebug("Save / Load Data");
                                        break;
                                    }
                                }
                            }
                        }
                        delete pMsg; // do not forget!!
                        break;
                    }
                    case wxMIDI_UNDEFINED_MSG:
                        break;
                }
                break;
            }
            default:
                wxLogDebug("Error recieving MIDI message (%d) - %s", nErr, m_pMidi->GetErrorText(nErr).c_str());
        }
    }
}

void sysexFrame::CloseInput()
{
	if(!m_pMidiIn)
        return;
    m_pMidiIn->StopListening();
    m_pMidiIn->Close();
    delete m_pMidiIn;
    m_pMidiIn = (wxMidiInDevice*)NULL;
}

void sysexFrame::CloseOutput()
{
    if(!m_pMidiOut)
        return;
    m_pMidiOut->Close();
    delete m_pMidiOut;
    m_pMidiOut = (wxMidiOutDevice*)NULL;
}

void sysexFrame::SendVoice()
{
    if(!m_pMidiOut)
        return;
    wxString sName = m_pTxtVoiceName->GetValue();
    m_pTxtVoiceName->SetValue(sName.MakeUpper());
    m_pTxtVoiceName->Refresh();
    if(!m_pMidiOut)
        return;



    //Now send the voice data
    wxByte pSysexMsg[681] = {
		0xF0,				//start of sysex message
		0x44, 0x03, 0x00, 0x70, //casio
		0x00,               //voice data
		0x40               //Normal, C/R 0
	};
	wxByte nChecksum = 0;
	for(int i = 0; i < 336; ++i)
	{
	    pSysexMsg[7 + i * 2] = m_aVoice[i] >> 4;
	    pSysexMsg[8 + i * 2] = m_aVoice[i] & 0x0F;
	    nChecksum += m_aVoice[i];
	}
    nChecksum = (0 - nChecksum) & 0x7F;
    pSysexMsg[679] = nChecksum;
    pSysexMsg[680] = 0xF7; //end of sysex message

    wxMidiSysExMessage msg(pSysexMsg);
    m_pMidiOut->Write(&msg);
}

void sysexFrame::UpdateVoice()
{
    wxString sName = wxString::Format("%c%c%c%c%c%c%c%c%c%c%c%c%c%c", m_aVoice[322], m_aVoice[323], m_aVoice[324], m_aVoice[325], m_aVoice[326], m_aVoice[327], m_aVoice[328], m_aVoice[329], m_aVoice[330], m_aVoice[331], m_aVoice[332], m_aVoice[333], m_aVoice[334], m_aVoice[335]);
    m_pTxtVoiceName->SetValue(sName);
    m_pSliderTremeloDepth->SetValue(m_aVoice[319]);
    m_pSliderTremeloRate->SetValue(m_aVoice[320]);
    m_pSliderTremeloDelay->SetValue(m_aVoice[321]);
    m_pRadioTremeloMulti->SetSelection((m_aVoice[318] & 0x08) >> 3);
    m_pRadioTremeloWaveform->SetSelection(m_aVoice[318] & 0x03);
    m_pSliderVibratoDepth->SetValue(m_aVoice[315]);
    m_pSliderVibratoRate->SetValue(m_aVoice[316]);
    m_pSliderVibratoDelay->SetValue(m_aVoice[317]);
    m_pRadioVibratoMulti->SetSelection((m_aVoice[314] & 0x08) >> 3);
    m_pRadioVibratoWaveform->SetSelection(m_aVoice[314] & 0x03);
    m_pSliderOctave->SetValue(int((m_aVoice[314] & 0x60) >> 5) * int(0x80 == (m_aVoice[314] & 0x80))?1:-1); //!@todo Octave slider not reaching ends
    m_pSliderLevel->SetValue(99 - m_aVoice[174]);
    m_pSliderVelSens->SetValue(m_aVoice[313] & 0x1F);
    m_pCmbVelCurve->SetSelection((m_aVoice[313] & 0xE0) >> 5);
    m_pModule1->UpdateVoice();
    m_pModule2->UpdateVoice();
    m_pModule3->UpdateVoice();
    m_pModule4->UpdateVoice();
    m_pModule5->UpdateVoice();
    m_pModule6->UpdateVoice();
    m_pModule7->UpdateVoice();
    m_pModule8->UpdateVoice();
}

void sysexFrame::OnTxtVoiceNameText(wxCommandEvent& event)
{
    for(unsigned int i = 0; i < 14; ++i)
    {
        wxByte c = ' ';
        if(m_pTxtVoiceName->GetValue().Length() > i)
            c = m_pTxtVoiceName->GetValue().MakeUpper()[i];
        m_aVoice[322 + i] = c;
    }
}

void sysexFrame::OnSliderTremeloDelayCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[321] = event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnSliderTremeloDepthCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[319] = event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnSliderTremeloRateCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[320] = event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnRadioTremeloMultiSelect(wxCommandEvent& event)
{
    m_aVoice[318] = (m_aVoice[318] & 0x03) | (m_pRadioTremeloMulti->GetSelection() << 3);
    AutoUpdateVoice();
}

void sysexFrame::OnRadioTremeloWaveformSelect(wxCommandEvent& event)
{
    m_aVoice[318] = (m_aVoice[318] & 0x08) | m_pRadioTremeloWaveform->GetSelection();
    AutoUpdateVoice();
}


void sysexFrame::OnChkAutoUpdateClick(wxCommandEvent& event)
{
    m_bAutoUpdate = event.IsChecked();
}

void sysexFrame::OnModuleEvent(wxCommandEvent &event)
{
    AutoUpdateVoice();
}

void sysexFrame::AutoUpdateVoice()
{
    if(m_bAutoUpdate)
        SendVoice();
}

void sysexFrame::SetVzMode(unsigned int nMode)
{
    if(!m_pMidiOut)
        return;
    //Set mode to normal
    wxByte pSysexMsgMode[8] = {
		0xF0,				//start of sysex message
		0x44, 0x03, 0x00, 0x70, //casio
		0x50,               //Set mode
		0x00,               //Normal mode
		0xF7                //End of sysex message
	};
    wxMidiSysExMessage msgMode(pSysexMsgMode);
    m_pMidiOut->Write(&msgMode);
}

void sysexFrame::OnmenuSaveSelected(wxCommandEvent& event)
{
    SavePatch();
}

void sysexFrame::OnmenuOpenSelected(wxCommandEvent& event)
{
    OpenPatch();
}

void sysexFrame::SavePatch(wxString sFilename)
{
    if(sFilename.IsEmpty())
    {
        wxFileDialog dialog(this, "Save patch", "", "", "VZ patch files (*.vz1)|*.vz1|All files (*.*)|*.*", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
        int nResult = dialog.ShowModal();
        if(wxID_CANCEL == nResult)
            return;
        sFilename = dialog.GetFilename();
    }
    wxFile file(sFilename, wxFile::write);
    if(file.IsOpened())
        file.Write(m_aVoice, sizeof(m_aVoice));
    file.Close();
}

void sysexFrame::OpenPatch(wxString sFilename)
{
    if(sFilename.IsEmpty())
    {
        wxFileDialog dialog(this, "Open patch", "", "", "VZ patch files (*.vz1)|*.vz1|All files (*.*)|*.*", wxFD_OPEN);
        int nResult = dialog.ShowModal();
        if(wxID_CANCEL == nResult)
            return;
        sFilename = dialog.GetFilename();
    }
    wxFile file(sFilename, wxFile::read);
    if(file.IsOpened())
    {
        int nSize = file.Read(m_aVoice, sizeof(m_aVoice));
        file.Close();
        if(nSize == sizeof(m_aVoice))
            UpdateVoice(); //!@todo Handle failure to load - maybe load to temp buffer to avoid corrupting already loaded patch
    }
}

void sysexFrame::OnSliderLevelCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[174] = 0x7F - event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnSliderOctaveCmdScrollChanged(wxScrollEvent& event)
{
    wxByte nValue = abs(event.GetInt());
    if(event.GetInt() >= 0)
        nValue += 0x04;
    m_aVoice[314] = (m_aVoice[314] & 0x1F) | (nValue << 5);
    AutoUpdateVoice();
}

void sysexFrame::OnSliderVelSensCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[313] = (m_aVoice[313] & 0xE0) | event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnCmbVelCurveSelect(wxCommandEvent& event)
{
    m_aVoice[313] = (m_aVoice[313] & 0x1F) | (event.GetInt() << 5);
    AutoUpdateVoice();
}

void sysexFrame::OnRadioVibratoMultiSelect(wxCommandEvent& event)
{
    m_aVoice[314] = (m_aVoice[314] & 0xF7) | (event.GetInt() << 3);
    AutoUpdateVoice();
}

void sysexFrame::OnRadioVibratoWaveformSelect(wxCommandEvent& event)
{
    m_aVoice[314] = (m_aVoice[314] & 0xFC) | (event.GetInt());
    AutoUpdateVoice();
}

void sysexFrame::OnSliderVibratoDepthCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[315] = event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnSliderVibratoRateCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[316] = event.GetInt();
    AutoUpdateVoice();
}

void sysexFrame::OnSliderVibratoDelayCmdScrollChanged(wxScrollEvent& event)
{
    m_aVoice[317] = event.GetInt();
    AutoUpdateVoice();
}
