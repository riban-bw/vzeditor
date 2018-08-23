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
const long VZ_EditorFrame::ID_CHOICE1 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT1 = wxNewId();
const long VZ_EditorFrame::ID_CHOICE2 = wxNewId();
const long VZ_EditorFrame::ID_CHECKBOX1 = wxNewId();
const long VZ_EditorFrame::ID_BUTTON1 = wxNewId();
const long VZ_EditorFrame::ID_BTNGETVOICE = wxNewId();
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
const long VZ_EditorFrame::ID_STATICTEXT6 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT5 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT4 = wxNewId();
const long VZ_EditorFrame::ID_RADIOTREMELOWAVEFORM = wxNewId();
const long VZ_EditorFrame::ID_SLIDERTREMELODEPTH = wxNewId();
const long VZ_EditorFrame::ID_SLIDERTREMELORATE = wxNewId();
const long VZ_EditorFrame::ID_SLIDERTREMELODELAY = wxNewId();
const long VZ_EditorFrame::ID_RADIOBOX3 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT7 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT8 = wxNewId();
const long VZ_EditorFrame::ID_STATICTEXT9 = wxNewId();
const long VZ_EditorFrame::ID_RADIOBOX4 = wxNewId();
const long VZ_EditorFrame::ID_SLIDER5 = wxNewId();
const long VZ_EditorFrame::ID_SLIDER4 = wxNewId();
const long VZ_EditorFrame::ID_SLIDER6 = wxNewId();
const long VZ_EditorFrame::ID_PNLVOICE = wxNewId();
const long VZ_EditorFrame::ID_LSTLIB = wxNewId();
const long VZ_EditorFrame::ID_PANEL1 = wxNewId();
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
    //(*Initialize(VZ_EditorFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer9;
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
    m_pCmbInPort = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(181,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer1->Add(m_pCmbInPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("MIDI Output Port"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbOutPort = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxSize(181,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    FlexGridSizer1->Add(m_pCmbOutPort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkAutoUpdate = new wxCheckBox(this, ID_CHECKBOX1, _("Auto Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    m_pChkAutoUpdate->SetValue(false);
    FlexGridSizer1->Add(m_pChkAutoUpdate, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSend = new wxButton(this, ID_BUTTON1, _("Send Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(m_pBtnSend, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetVoice = new wxButton(this, ID_BTNGETVOICE, _("Get Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETVOICE"));
    m_pBtnGetVoice->Disable();
    FlexGridSizer1->Add(m_pBtnGetVoice, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSizerMain->Add(FlexGridSizer1, 1, wxALL|wxEXPAND, 5);
    m_pNotebook = new wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK"));
    m_pPnlVoice = new wxPanel(m_pNotebook, ID_PNLVOICE, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLVOICE"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    m_pScrollWinVoiceEditor = new wxScrolledWindow(m_pPnlVoice, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    m_pLine1 = new VZLine(m_pScrollWinVoiceEditor);
    BoxSizer1->Add(m_pLine1, 1, wxALL|wxEXPAND, 5);
    m_pLine2 = new VZLine(m_pScrollWinVoiceEditor);
    BoxSizer1->Add(m_pLine2, 1, wxALL|wxEXPAND, 5);
    m_pLine3 = new VZLine(m_pScrollWinVoiceEditor);
    BoxSizer1->Add(m_pLine3, 1, wxALL|wxEXPAND, 5);
    m_pLine4 = new VZLine(m_pScrollWinVoiceEditor);
    BoxSizer1->Add(m_pLine4, 1, wxALL|wxEXPAND, 5);
    m_pScrollWinVoiceEditor->SetSizer(BoxSizer1);
    BoxSizer1->Fit(m_pScrollWinVoiceEditor);
    BoxSizer1->SetSizeHints(m_pScrollWinVoiceEditor);
    FlexGridSizer2->Add(m_pScrollWinVoiceEditor, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 0, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    StaticText3 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT3, _("Voice Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtVoiceName = new wxTextCtrl(m_pPnlVoice, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(125,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer4->Add(m_pTxtVoiceName, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer8->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer7->AddGrowableCol(1);
    StaticText30 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT30, _("Level"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer7->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderLevel = new wxSlider(m_pPnlVoice, ID_SLIDERLEVEL, 127, 0, 127, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDERLEVEL"));
    FlexGridSizer7->Add(m_pSliderLevel, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer8->Add(FlexGridSizer7, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, m_pPnlVoice, _("DCO"));
    FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText10 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT10, _("Octave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer6->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderOctave = new wxSlider(m_pPnlVoice, ID_SLIDEROCTAVE, 0, -2, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDEROCTAVE"));
    FlexGridSizer6->Add(m_pSliderOctave, 1, wxALL|wxEXPAND, 5);
    StaticText11 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT11, _("Velocity\nSensitivity"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT11"));
    FlexGridSizer6->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVelSens = new wxSlider(m_pPnlVoice, ID_SLIDERVELSENS, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDERVELSENS"));
    FlexGridSizer6->Add(m_pSliderVelSens, 1, wxALL|wxEXPAND, 5);
    m_pLblVelCurve = new wxStaticText(m_pPnlVoice, ID_STATICTEXT12, _("Curve"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer6->Add(m_pLblVelCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbVelCurve = new wxChoice(m_pPnlVoice, ID_CMBVELCURVE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBVELCURVE"));
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
    FlexGridSizer8->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, m_pPnlVoice, _("Tremelo"));
    FlexGridSizer3 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer3->AddGrowableRow(1);
    wxString __wxRadioBoxChoices_1[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioTremeloMulti = new wxRadioBox(m_pPnlVoice, ID_RADIOTREMELOMULTI, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOTREMELOMULTI"));
    FlexGridSizer3->Add(m_pRadioTremeloMulti, 1, wxALL|wxEXPAND, 5);
    StaticText6 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT6, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT5, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT4, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_2[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioTremeloWaveform = new wxRadioBox(m_pPnlVoice, ID_RADIOTREMELOWAVEFORM, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_2, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOTREMELOWAVEFORM"));
    FlexGridSizer3->Add(m_pRadioTremeloWaveform, 1, wxALL|wxEXPAND, 5);
    m_pSliderTremeloDepth = new wxSlider(m_pPnlVoice, ID_SLIDERTREMELODEPTH, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELODEPTH"));
    FlexGridSizer3->Add(m_pSliderTremeloDepth, 1, wxALL|wxEXPAND, 5);
    m_pSliderTremeloRate = new wxSlider(m_pPnlVoice, ID_SLIDERTREMELORATE, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELORATE"));
    m_pSliderTremeloRate->SetMinSize(wxSize(0,0));
    FlexGridSizer3->Add(m_pSliderTremeloRate, 1, wxALL|wxEXPAND, 5);
    m_pSliderTremeloDelay = new wxSlider(m_pPnlVoice, ID_SLIDERTREMELODELAY, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELODELAY"));
    FlexGridSizer3->Add(m_pSliderTremeloDelay, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(FlexGridSizer3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    FlexGridSizer8->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, m_pPnlVoice, _("Vibrato"));
    FlexGridSizer5 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer5->AddGrowableRow(1);
    wxString __wxRadioBoxChoices_3[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioVibratoMulti = new wxRadioBox(m_pPnlVoice, ID_RADIOBOX3, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX3"));
    FlexGridSizer5->Add(m_pRadioVibratoMulti, 1, wxALL|wxEXPAND, 5);
    StaticText7 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT7, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer5->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT8, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer5->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(m_pPnlVoice, ID_STATICTEXT9, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer5->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_4[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioVibratoWaveform = new wxRadioBox(m_pPnlVoice, ID_RADIOBOX4, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_4, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX4"));
    FlexGridSizer5->Add(m_pRadioVibratoWaveform, 1, wxALL|wxEXPAND, 5);
    m_pSliderVibratoDepth = new wxSlider(m_pPnlVoice, ID_SLIDER5, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER5"));
    FlexGridSizer5->Add(m_pSliderVibratoDepth, 1, wxALL|wxEXPAND, 5);
    m_pSliderVibratoRate = new wxSlider(m_pPnlVoice, ID_SLIDER4, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER4"));
    FlexGridSizer5->Add(m_pSliderVibratoRate, 1, wxALL|wxEXPAND, 5);
    m_pSliderVibratoDelay = new wxSlider(m_pPnlVoice, ID_SLIDER6, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER6"));
    FlexGridSizer5->Add(m_pSliderVibratoDelay, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2->Add(FlexGridSizer5, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer8->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer2->Add(FlexGridSizer8, 1, wxALL|wxEXPAND, 5);
    m_pPnlVoice->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(m_pPnlVoice);
    FlexGridSizer2->SetSizeHints(m_pPnlVoice);
    Panel1 = new wxPanel(m_pNotebook, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer9 = new wxFlexGridSizer(2, 0, 0, 0);
    FlexGridSizer9->AddGrowableCol(0);
    FlexGridSizer9->AddGrowableRow(1);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    FlexGridSizer9->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    m_pLstLib = new SortableList(Panel1,ID_LSTLIB);
    FlexGridSizer9->Add(m_pLstLib, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(FlexGridSizer9);
    FlexGridSizer9->Fit(Panel1);
    FlexGridSizer9->SetSizeHints(Panel1);
    m_pNotebook->AddPage(m_pPnlVoice, _("Voice Editor"), false);
    m_pNotebook->AddPage(Panel1, _("Voice Library"), false);
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

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnInPortSelect);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnOutPortSelect);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZ_EditorFrame::OnChkAutoUpdateClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZ_EditorFrame::OnBtnSendClick);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZ_EditorFrame::OnTxtVoiceNameText);
    Connect(ID_SLIDERVELSENS,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OSliderVelSensCmdScroll);
    Connect(ID_CMBVELCURVE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnCmbVelCurveSelect);
    Connect(ID_RADIOTREMELOMULTI,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioVibratoMultiSelect);
    Connect(ID_RADIOBOX3,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioVibratoMultiSelect);
    Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnRadioVibratoWaveformSelect);
    Connect(ID_SLIDER5,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnSliderVibratoDepthCmdScroll);
    Connect(ID_SLIDER4,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnSliderVibratoRateCmdScroll);
    Connect(ID_SLIDER6,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZ_EditorFrame::OnSliderVibratoDelayCmdScroll);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnOpenFile);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnSaveFile);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZ_EditorFrame::OnAbout);
    //*)
    Connect(ID_LSTLIB,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&VZ_EditorFrame::OnLibSort);
    //Get MIDI interfaces
    //!@todo React to MIDI ports appearing and disappearing, e.g. USB plugged in - maybe using wxMidiDevice::HasHostError()
    m_pMidi = wxMidiSystem::GetInstance();
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
    m_pMidiOut = (wxMidiOutDevice*)NULL;
    m_pMidiIn = (wxMidiInDevice*)NULL;
}

VZ_EditorFrame::~VZ_EditorFrame()
{
    //(*Destroy(VZ_EditorFrame)
    //*)
}

void VZ_EditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void VZ_EditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Casio VZ-1 / VZ-10M / VZ-8\nLibrary and editor"));
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
        if(nType == 0 && lLength == VZ_VOICE_SIZE)
        {
            //Tone data
            m_vzVoiceMidi.SetSysEx(pSysExMsg);
            m_pBtnGetVoice->Enable();
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
    wxByte acSysex[VZ_VOICE_SIZE];
    m_vzVoice.Validate(true);
    m_vzVoice.GetSysEx(acSysex);
    if(file.Write(m_vzVoice.GetSysEx(), VZ_VOICE_SIZE) != VZ_VOICE_SIZE)
        wxMessageBox(wxT("Error - corrupt file"), wxT("Error"), wxICON_ERROR);
    file.Close();
}

void VZ_EditorFrame::LoadVoice()
{
    wxFileDialog dlg(this, wxT("Select file to load voice from"),wxEmptyString, wxEmptyString, wxT("SysEx files (*.syx)|*.syx|All files (*.*)|*.*"), wxFD_OPEN);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    wxFile file(dlg.GetPath(), wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox(wxT("Failed to open file"), wxT("Error"), wxICON_ERROR);
        return;
    }
    wxByte acSysex[VZ_VOICE_SIZE];
    if(file.Length() != VZ_VOICE_SIZE || file.Read(acSysex, VZ_VOICE_SIZE) != VZ_VOICE_SIZE)
        wxMessageBox(wxT("Corrupt file"), wxT("Error"), wxICON_ERROR);
    file.Close();
    if(m_vzVoice.SetSysEx(acSysex))
        wxMessageBox(wxT("Invalid VZ voice file"), wxT("Error"), wxICON_ERROR);
    UpdateGui();
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
    //!@todo Implement UpdateGui
}


void VZ_EditorFrame::OnChkAutoUpdateClick(wxCommandEvent& event)
{
    //!@todo Implement auto update
}

void VZ_EditorFrame::OnBtnSendClick(wxCommandEvent& event)
{
    SendVoice();
}

void VZ_EditorFrame::OnTxtVoiceNameText(wxCommandEvent& event)
{
    m_vzVoice.SetName(m_pTxtVoiceName->GetValue());
}

void VZ_EditorFrame::OnRadioTremeloMultiSelect(wxCommandEvent& event)
{
    //!@todo Implement OnRadioTremeloMultiSelect
}

void VZ_EditorFrame::OnSliderLevelCmdScroll(wxScrollEvent& event)
{
    //!@todo Implement OnSliderLevelCmdScroll
}

void VZ_EditorFrame::OSliderOctaveCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OSliderVelSensCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnCmbVelCurveSelect(wxCommandEvent& event)
{
}

void VZ_EditorFrame::OnRadioTremeloWaveformSelect(wxCommandEvent& event)
{
}

void VZ_EditorFrame::OnSliderTremeloDepthCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnSliderTremeloRateCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnSliderTremeloDelayCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnRadioVibratoMultiSelect(wxCommandEvent& event)
{
}

void VZ_EditorFrame::OnRadioVibratoWaveformSelect(wxCommandEvent& event)
{
}

void VZ_EditorFrame::OnSliderVibratoDepthCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnSliderVibratoRateCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnSliderVibratoDelayCmdScroll(wxScrollEvent& event)
{
}

void VZ_EditorFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxT("Select file to load voice from"),wxEmptyString, wxEmptyString, wxT("SysEx files (*.syx)|*.syx|All files (*.*)|*.*"), wxFD_OPEN);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    wxFile file(dlg.GetPath(), wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox(wxT("Failed to open file"), wxT("Error"), wxICON_ERROR);
        return;
    }
    wxByte acSysex[VZ_VOICE_SIZE];
    if(file.Length() != VZ_VOICE_SIZE || file.Read(acSysex, VZ_VOICE_SIZE) != VZ_VOICE_SIZE)
        wxMessageBox(wxT("Corrupt file"), wxT("Error"), wxICON_ERROR);
    file.Close();
    if(m_vzVoice.SetSysEx(acSysex))
        wxMessageBox(wxT("Invalid VZ voice file"), wxT("Error"), wxICON_ERROR);
//    else
//        m_pLstLog->Append(wxString::Format(wxT("Loaded voice %s"), m_vzVoice.GetName().c_str()));
    m_pTxtVoiceName->SetValue(m_vzVoice.GetName());
    UpdateGui();

}

void VZ_EditorFrame::OnLibSort(wxListEvent& event)
{
    m_pLstLib->Sort(event.GetColumn());
}


void VZ_EditorFrame::OnBtnGetVoice(wxCommandEvent& event)
{
    GetVoice();
}

void VZ_EditorFrame::OnSaveFile(wxCommandEvent& event)
{
    SaveVoice();
}

void VZ_EditorFrame::OnLoadFile(wxCommandEvent& event)
{
    LoadVoice();
}
