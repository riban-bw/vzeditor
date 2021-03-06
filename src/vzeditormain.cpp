/***************************************************************
 * Name:      vzeditormain.cpp
 * Purpose:   Implements main application frame VZEditorFrame
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-22
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "vzeditormain.h"
#include "../version.h"
#include "../media/icon.xpm"
#include <wx/msgdlg.h>
#include <wx/file.h>
#include <wx/filename.h>
#include <wx/config.h>
#include <wx/display.h>
#include <wx/utils.h>
#include <wx/dir.h>
#include <wx/mousemanager.h>
#include <list>
#include <complex>

//(*InternalHeaders(VZEditorFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZEditorFrame)
const long VZEditorFrame::ID_STATICTEXTMIDIINPUT = wxNewId();
const long VZEditorFrame::ID_CMBINPORT = wxNewId();
const long VZEditorFrame::ID_STATICTEXTMIDIOUTPUT = wxNewId();
const long VZEditorFrame::ID_CMBOUTPORT = wxNewId();
const long VZEditorFrame::ID_CHECKBOXKEYBOARD = wxNewId();
const long VZEditorFrame::ID_CHKAUTOUPDATE = wxNewId();
const long VZEditorFrame::ID_BTNSEND = wxNewId();
const long VZEditorFrame::ID_BTNGETVOICE = wxNewId();
const long VZEditorFrame::ID_BTNGETOPERATION = wxNewId();
const long VZEditorFrame::ID_BTNSAVEDUMP = wxNewId();
const long VZEditorFrame::ID_PANEL1 = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLADD = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLDELETE = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLSAVE = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLSAVEAS = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLOPRN = wxNewId();
const long VZEditorFrame::ID_LISTBOXLIBRARY = wxNewId();
const long VZEditorFrame::ID_GRIDCONFIG = wxNewId();
const long VZEditorFrame::ID_PNLLIBRARY = wxNewId();
const long VZEditorFrame::ID_LINE1 = wxNewId();
const long VZEditorFrame::ID_LINE2 = wxNewId();
const long VZEditorFrame::ID_LINE3 = wxNewId();
const long VZEditorFrame::ID_LINE4 = wxNewId();
const long VZEditorFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT3 = wxNewId();
const long VZEditorFrame::ID_TEXTCTRL1 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT30 = wxNewId();
const long VZEditorFrame::ID_SLIDERLEVEL = wxNewId();
const long VZEditorFrame::ID_ENVELOPEDCO = wxNewId();
const long VZEditorFrame::ID_SLIDERDCOENVDEPTH = wxNewId();
const long VZEditorFrame::ID_STATICTEXT10 = wxNewId();
const long VZEditorFrame::ID_SLIDEROCTAVE = wxNewId();
const long VZEditorFrame::ID_STATICTEXT11 = wxNewId();
const long VZEditorFrame::ID_SLIDERVELSENS = wxNewId();
const long VZEditorFrame::ID_STATICTEXT12 = wxNewId();
const long VZEditorFrame::ID_CMBVELCURVE = wxNewId();
const long VZEditorFrame::ID_RADIOTREMELOMULTI = wxNewId();
const long VZEditorFrame::ID_RADIOTREMELOWAVEFORM = wxNewId();
const long VZEditorFrame::ID_STATICTEXT6 = wxNewId();
const long VZEditorFrame::ID_SLIDERTREMELODEPTH = wxNewId();
const long VZEditorFrame::ID_STATICTEXT5 = wxNewId();
const long VZEditorFrame::ID_SLIDERTREMELORATE = wxNewId();
const long VZEditorFrame::ID_STATICTEXT4 = wxNewId();
const long VZEditorFrame::ID_SLIDERTREMELODELAY = wxNewId();
const long VZEditorFrame::ID_RADIOBOX3 = wxNewId();
const long VZEditorFrame::ID_RADIOBOX4 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT7 = wxNewId();
const long VZEditorFrame::ID_SLIDER5 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT8 = wxNewId();
const long VZEditorFrame::ID_SLIDER4 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT9 = wxNewId();
const long VZEditorFrame::ID_SLIDER6 = wxNewId();
const long VZEditorFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long VZEditorFrame::ID_SPLITTERWINDOW1 = wxNewId();
const long VZEditorFrame::ID_PNLVOICE = wxNewId();
const long VZEditorFrame::ID_SCROLLEDWINDOW3 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT13 = wxNewId();
const long VZEditorFrame::ID_TXTOPERATIONNAME = wxNewId();
const long VZEditorFrame::ID_SCROLLEDWINDOW4 = wxNewId();
const long VZEditorFrame::ID_SPLITTERWINDOW2 = wxNewId();
const long VZEditorFrame::ID_PNLOPERATION = wxNewId();
const long VZEditorFrame::ID_PANELMULTICHANNEL = wxNewId();
const long VZEditorFrame::ID_SLIDERVOLUME = wxNewId();
const long VZEditorFrame::ID_SLIDERMASTERTUNE = wxNewId();
const long VZEditorFrame::ID_SLIDERTRANSPOSE = wxNewId();
const long VZEditorFrame::ID_SLIDERCZBENDRANGE = wxNewId();
const long VZEditorFrame::ID_CHOICEMODE = wxNewId();
const long VZEditorFrame::ID_RADIOBOXCARDBANK = wxNewId();
const long VZEditorFrame::ID_PANELMISC = wxNewId();
const long VZEditorFrame::ID_NOTEBOOK = wxNewId();
const long VZEditorFrame::ID_STATICTEXT14 = wxNewId();
const long VZEditorFrame::ID_SPIN_KEYCHAN = wxNewId();
const long VZEditorFrame::ID_STATICTEXT15 = wxNewId();
const long VZEditorFrame::ID_SPINCTRL1 = wxNewId();
const long VZEditorFrame::ID_PANEL2 = wxNewId();
const long VZEditorFrame::ID_KBD = wxNewId();
const long VZEditorFrame::idMenuOpen = wxNewId();
const long VZEditorFrame::idMenuSave = wxNewId();
const long VZEditorFrame::ID_MENU_SAVEAS = wxNewId();
const long VZEditorFrame::idMenuQuit = wxNewId();
const long VZEditorFrame::ID_MENU_HEADER = wxNewId();
const long VZEditorFrame::ID_MENU_LIBRARY = wxNewId();
const long VZEditorFrame::ID_MENU_VOICE = wxNewId();
const long VZEditorFrame::ID_MENU_OPERATION = wxNewId();
const long VZEditorFrame::ID_MENU_MULTICHANNEL = wxNewId();
const long VZEditorFrame::ID_MENU_MISC = wxNewId();
const long VZEditorFrame::ID_MENU_KEYBOARD = wxNewId();
const long VZEditorFrame::idMenuAbout = wxNewId();
const long VZEditorFrame::ID_STATUSBAR1 = wxNewId();
const long VZEditorFrame::ID_TIMER1S = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZEditorFrame,wxFrame)
    //(*EventTable(VZEditorFrame)
    //*)
    EVT_COMMAND(ID_KBD, KEYBOARD_NOTE_ON_EVENT, VZEditorFrame::OnKeyboardNoteOn)
    EVT_COMMAND(ID_KBD, KEYBOARD_NOTE_OFF_EVENT, VZEditorFrame::OnKeyboardNoteOff)
    EVT_COMMAND(wxID_ANY, SYSEX_EVENT, VZEditorFrame::OnModuleEvent)
    EVT_GRID_CELL_BEGIN_DRAG(VZEditorFrame::OnGridStartDrag)
END_EVENT_TABLE()

VZEditorFrame::VZEditorFrame(wxWindow* parent,wxWindowID id)
{
    wxTextValidator m_validateVoiceName;
    wxArrayString asValidate;
    m_validateVoiceName.SetStyle(wxFILTER_INCLUDE_CHAR_LIST);
    for(char c = 'A'; c <= 'Z'; ++c)
        asValidate.Add(wxString::Format("%c", c));
    for(char c = '0'; c <= '9'; ++c)
        asValidate.Add(wxString::Format("%c", c));
    asValidate.Add(" ");
    asValidate.Add("-");
    asValidate.Add("/");
    asValidate.Add(".");
    m_validateVoiceName.SetIncludes(wxArrayString(asValidate));

    //(*Initialize(VZEditorFrame)
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer13;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer15;
    wxBoxSizer* BoxSizer16;
    wxBoxSizer* BoxSizer17;
    wxBoxSizer* BoxSizer18;
    wxBoxSizer* BoxSizer19;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer20;
    wxBoxSizer* BoxSizer21;
    wxBoxSizer* BoxSizer22;
    wxBoxSizer* BoxSizer23;
    wxBoxSizer* BoxSizer24;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer9;
    wxFlexGridSizer* FlexGridSizer6;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer7;
    wxStaticBoxSizer* StaticBoxSizer8;
    wxStaticBoxSizer* StaticBoxSizer9;

    Create(parent, wxID_ANY, _("riban Casio VZ-x Voice Editor and Library"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, _T("wxID_ANY"));
    SetClientSize(wxSize(-1,-1));
    SetToolTip(_("Set keyboard transpose"));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(icon_xpm));
    	SetIcon(FrameIcon);
    }
    m_pSizerMain = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
    m_pLblMidiInputPort = new wxStaticText(Panel1, ID_STATICTEXTMIDIINPUT, _("MIDI Input"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTMIDIINPUT"));
    BoxSizer22->Add(m_pLblMidiInputPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChoiceInPort = new wxChoice(Panel1, ID_CMBINPORT, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBINPORT"));
    m_pChoiceInPort->SetToolTip(_("Select MIDI input port"));
    BoxSizer22->Add(m_pChoiceInPort, 0, wxALL, 5);
    m_pLblMidiOutputPort = new wxStaticText(Panel1, ID_STATICTEXTMIDIOUTPUT, _("MIDI Output"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTMIDIOUTPUT"));
    BoxSizer22->Add(m_pLblMidiOutputPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChoiceOutPort = new wxChoice(Panel1, ID_CMBOUTPORT, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBOUTPORT"));
    m_pChoiceOutPort->SetToolTip(_("Select MIDI output port"));
    BoxSizer22->Add(m_pChoiceOutPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkKeyboard = new wxCheckBox(Panel1, ID_CHECKBOXKEYBOARD, _("Keyboard"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOXKEYBOARD"));
    m_pChkKeyboard->SetValue(false);
    BoxSizer22->Add(m_pChkKeyboard, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer22->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkAutoUpdate = new wxCheckBox(Panel1, ID_CHKAUTOUPDATE, _("Auto Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKAUTOUPDATE"));
    m_pChkAutoUpdate->SetValue(false);
    m_pChkAutoUpdate->SetToolTip(_("Enable automatic, immediate send of changes"));
    BoxSizer22->Add(m_pChkAutoUpdate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSend = new wxButton(Panel1, ID_BTNSEND, _("Send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSEND"));
    m_pBtnSend->SetToolTip(_("Send data to MIDI output"));
    BoxSizer22->Add(m_pBtnSend, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetVoice = new wxButton(Panel1, ID_BTNGETVOICE, _("Get Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETVOICE"));
    m_pBtnGetVoice->Disable();
    m_pBtnGetVoice->SetToolTip(_("Load voice data recieved from MIDI input"));
    BoxSizer22->Add(m_pBtnGetVoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetOperation = new wxButton(Panel1, ID_BTNGETOPERATION, _("Get Operation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETOPERATION"));
    m_pBtnGetOperation->Disable();
    m_pBtnGetOperation->SetToolTip(_("Load operational data recieved from MIDI input"));
    BoxSizer22->Add(m_pBtnGetOperation, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSaveDump = new wxButton(Panel1, ID_BTNSAVEDUMP, _("New Library"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSAVEDUMP"));
    BoxSizer22->Add(m_pBtnSaveDump, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer22);
    BoxSizer22->Fit(Panel1);
    BoxSizer22->SetSizeHints(Panel1);
    m_pSizerMain->Add(Panel1, 0, wxALL|wxEXPAND, 5);
    m_pNotebook = new wxNotebook(this, ID_NOTEBOOK, wxDefaultPosition, wxDefaultSize, wxNB_NOPAGETHEME, _T("ID_NOTEBOOK"));
    m_pNotebook->SetToolTip(_("Select voice library tab"));
    m_pPnlLibrary = new wxPanel(m_pNotebook, ID_PNLLIBRARY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLLIBRARY"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    m_pBtnLibToolAdd = new wxBitmapButton(m_pPnlLibrary, ID_BITMAPBUTTONLIBTOOLADD, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NEW")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTONLIBTOOLADD"));
    m_pBtnLibToolAdd->SetToolTip(_("Add entry to library"));
    BoxSizer3->Add(m_pBtnLibToolAdd, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnLibToolDelete = new wxBitmapButton(m_pPnlLibrary, ID_BITMAPBUTTONLIBTOOLDELETE, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTONLIBTOOLDELETE"));
    m_pBtnLibToolDelete->SetToolTip(_("Delete selected entries from library"));
    BoxSizer3->Add(m_pBtnLibToolDelete, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnLibToolSave = new wxBitmapButton(m_pPnlLibrary, ID_BITMAPBUTTONLIBTOOLSAVE, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTONLIBTOOLSAVE"));
    m_pBtnLibToolSave->Disable();
    m_pBtnLibToolSave->SetToolTip(_("Save library"));
    BoxSizer3->Add(m_pBtnLibToolSave, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnLibToolSaveAs = new wxBitmapButton(m_pPnlLibrary, ID_BITMAPBUTTONLIBTOOLSAVEAS, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE_AS")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTONLIBTOOLSAVEAS"));
    m_pBtnLibToolSaveAs->SetToolTip(_("Save library with different name"));
    BoxSizer3->Add(m_pBtnLibToolSaveAs, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnLibToolOpen = new wxBitmapButton(m_pPnlLibrary, ID_BITMAPBUTTONLIBTOOLOPRN, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_OPEN")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTONLIBTOOLOPRN"));
    m_pBtnLibToolOpen->SetToolTip(_("Open"));
    m_pBtnLibToolOpen->SetHelpText(_("Open another library"));
    BoxSizer3->Add(m_pBtnLibToolOpen, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
    BoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer24 = new wxBoxSizer(wxVERTICAL);
    m_pLstLibrary = new wxListBox(m_pPnlLibrary, ID_LISTBOXLIBRARY, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOXLIBRARY"));
    BoxSizer24->Add(m_pLstLibrary, 1, wxALL|wxEXPAND, 5);
    BoxSizer23->Add(BoxSizer24, 0, wxALL|wxEXPAND, 5);
    BoxSizer20 = new wxBoxSizer(wxVERTICAL);
    m_pGridConfig = new wxGrid(m_pPnlLibrary, ID_GRIDCONFIG, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRIDCONFIG"));
    m_pGridConfig->CreateGrid(16,8);
    m_pGridConfig->EnableEditing(false);
    m_pGridConfig->EnableGridLines(true);
    m_pGridConfig->SetDefaultColSize(120, true);
    m_pGridConfig->SetRowLabelValue(0, _("Tone 1"));
    m_pGridConfig->SetRowLabelValue(1, _("Tone 2"));
    m_pGridConfig->SetRowLabelValue(2, _("Tone 3"));
    m_pGridConfig->SetRowLabelValue(3, _("Tone 4"));
    m_pGridConfig->SetRowLabelValue(4, _("Tone 5"));
    m_pGridConfig->SetRowLabelValue(5, _("Tone 6"));
    m_pGridConfig->SetRowLabelValue(6, _("Tone 7"));
    m_pGridConfig->SetRowLabelValue(7, _("Tone 8"));
    m_pGridConfig->SetRowLabelValue(8, _("Operation 1"));
    m_pGridConfig->SetRowLabelValue(9, _("Operation 2"));
    m_pGridConfig->SetRowLabelValue(10, _("Operation 3"));
    m_pGridConfig->SetRowLabelValue(11, _("Operation 4"));
    m_pGridConfig->SetRowLabelValue(12, _("Operation 5"));
    m_pGridConfig->SetRowLabelValue(13, _("Operation 6"));
    m_pGridConfig->SetRowLabelValue(14, _("Operation 7"));
    m_pGridConfig->SetRowLabelValue(15, _("Operation 8"));
    m_pGridConfig->SetDefaultCellFont( m_pGridConfig->GetFont() );
    m_pGridConfig->SetDefaultCellTextColour( m_pGridConfig->GetForegroundColour() );
    BoxSizer20->Add(m_pGridConfig, 0, wxALL, 5);
    BoxSizer23->Add(BoxSizer20, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer23, 1, wxALL|wxEXPAND, 5);
    m_pPnlLibrary->SetSizer(BoxSizer2);
    BoxSizer2->Fit(m_pPnlLibrary);
    BoxSizer2->SetSizeHints(m_pPnlLibrary);
    m_pPnlVoice = new wxPanel(m_pNotebook, ID_PNLVOICE, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLVOICE"));
    m_pPnlVoice->SetToolTip(_("Select voice editor tab"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    m_pSplitterMain = new wxSplitterWindow(m_pPnlVoice, ID_SPLITTERWINDOW1, wxDefaultPosition, wxDefaultSize, wxSP_3D, _T("ID_SPLITTERWINDOW1"));
    m_pSplitterMain->SetMinimumPaneSize(10);
    m_pSplitterMain->SetSashGravity(1);
    m_pScrollWinVoiceEditor = new wxScrolledWindow(m_pSplitterMain, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    m_pSizerLines = new wxBoxSizer(wxVERTICAL);
    m_pLine1 = new VZLine(m_pScrollWinVoiceEditor, 0);
    m_pSizerLines->Add(m_pLine1, 1, wxALL|wxEXPAND, 5);
    m_pLine2 = new VZLine(m_pScrollWinVoiceEditor, 1);
    m_pSizerLines->Add(m_pLine2, 1, wxALL|wxEXPAND, 5);
    m_pLine3 = new VZLine(m_pScrollWinVoiceEditor, 2);
    m_pSizerLines->Add(m_pLine3, 1, wxALL|wxEXPAND, 5);
    m_pLine4 = new VZLine(m_pScrollWinVoiceEditor, 3);
    m_pSizerLines->Add(m_pLine4, 1, wxALL|wxEXPAND, 5);
    m_pScrollWinVoiceEditor->SetSizer(m_pSizerLines);
    m_pSizerLines->Fit(m_pScrollWinVoiceEditor);
    m_pSizerLines->SetSizeHints(m_pScrollWinVoiceEditor);
    m_pScrollwindowGlobalParameters = new wxScrolledWindow(m_pSplitterMain, ID_SCROLLEDWINDOW2, wxDefaultPosition, wxDefaultSize, wxVSCROLL, _T("ID_SCROLLEDWINDOW2"));
    m_pFlexgridGlobalParameters = new wxBoxSizer(wxVERTICAL);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT3, _("Tone Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer9->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtVoiceName = new wxTextCtrl(m_pScrollwindowGlobalParameters, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, m_validateVoiceName, _T("ID_TEXTCTRL1"));
    m_pTxtVoiceName->SetMaxLength(12);
    m_pTxtVoiceName->SetToolTip(_("Edit voice name"));
    BoxSizer9->Add(m_pTxtVoiceName, 1, wxALL, 5);
    m_pFlexgridGlobalParameters->Add(BoxSizer9, 0, wxALL|wxEXPAND, 5);
    BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
    StaticText30 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT30, _("Level"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    BoxSizer10->Add(StaticText30, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderLevel = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERLEVEL, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERLEVEL"));
    m_pSliderLevel->SetToolTip(_("Set voice output level"));
    BoxSizer10->Add(m_pSliderLevel, 1, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(BoxSizer10, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, m_pScrollwindowGlobalParameters, _("DCO"));
    StaticBoxSizer9 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("Amplitude Envelope"));
    m_pGraphDCO = new EnvelopeGraph(m_pScrollwindowGlobalParameters,ID_ENVELOPEDCO);
    StaticBoxSizer9->Add(m_pGraphDCO, 1, wxALL|wxEXPAND, 5);
    m_pSliderDCOEnvDepth = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERDCOENVDEPTH, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERDCOENVDEPTH"));
    m_pSliderDCOEnvDepth->SetToolTip(_("Set DCA amplitude envelope depth"));
    StaticBoxSizer9->Add(m_pSliderDCOEnvDepth, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    StaticBoxSizer3->Add(StaticBoxSizer9, 0, wxALL|wxEXPAND, 5);
    FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer6->AddGrowableCol(1);
    StaticText10 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT10, _("Octave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer6->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderOctave = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDEROCTAVE, 0, -2, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDEROCTAVE"));
    m_pSliderOctave->SetToolTip(_("Set DCO octave"));
    FlexGridSizer6->Add(m_pSliderOctave, 1, wxALL|wxEXPAND, 5);
    StaticText11 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT11, _("Velocity\nSensitivity"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT11"));
    FlexGridSizer6->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVelSens = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERVELSENS, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDERVELSENS"));
    m_pSliderVelSens->SetToolTip(_("Set DCO velocity sensitivity"));
    FlexGridSizer6->Add(m_pSliderVelSens, 1, wxALL|wxEXPAND, 5);
    m_pLblVelCurve = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT12, _("Curve"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer6->Add(m_pLblVelCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChoiceVelCurve = new wxChoice(m_pScrollwindowGlobalParameters, ID_CMBVELCURVE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBVELCURVE"));
    m_pChoiceVelCurve->SetSelection( m_pChoiceVelCurve->Append(_("Curve 1")) );
    m_pChoiceVelCurve->Append(_("Curve 2"));
    m_pChoiceVelCurve->Append(_("Curve 3"));
    m_pChoiceVelCurve->Append(_("Curve 4"));
    m_pChoiceVelCurve->Append(_("Curve 5"));
    m_pChoiceVelCurve->Append(_("Curve 6"));
    m_pChoiceVelCurve->Append(_("Curve 7"));
    m_pChoiceVelCurve->Append(_("Curve 8"));
    m_pChoiceVelCurve->SetToolTip(_("Select DCO curve"));
    FlexGridSizer6->Add(m_pChoiceVelCurve, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3->Add(FlexGridSizer6, 0, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(StaticBoxSizer3, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("Tremelo"));
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    wxString __wxRadioBoxChoices_1[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioTremeloMulti = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOTREMELOMULTI, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOTREMELOMULTI"));
    m_pRadioTremeloMulti->SetToolTip(_("Select tremelo multi"));
    BoxSizer11->Add(m_pRadioTremeloMulti, 0, wxALL|wxEXPAND, 5);
    wxString __wxRadioBoxChoices_2[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioTremeloWaveform = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOTREMELOWAVEFORM, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_2, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOTREMELOWAVEFORM"));
    m_pRadioTremeloWaveform->SetToolTip(_("Select tremelo waveform"));
    BoxSizer11->Add(m_pRadioTremeloWaveform, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer1->Add(BoxSizer11, 0, wxALL|wxEXPAND, 5);
    BoxSizer12 = new wxBoxSizer(wxVERTICAL);
    StaticText6 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT6, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer12->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderTremeloDepth = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERTREMELODEPTH, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELODEPTH"));
    m_pSliderTremeloDepth->SetToolTip(_("Set tremelo depth"));
    BoxSizer12->Add(m_pSliderTremeloDepth, 1, wxALL, 5);
    StaticBoxSizer1->Add(BoxSizer12, 0, wxALL|wxEXPAND, 5);
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    StaticText5 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT5, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer13->Add(StaticText5, 0, wxALL|wxEXPAND, 5);
    m_pSliderTremeloRate = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERTREMELORATE, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELORATE"));
    m_pSliderTremeloRate->SetToolTip(_("Set tremelo rate"));
    BoxSizer13->Add(m_pSliderTremeloRate, 1, wxALL, 5);
    StaticBoxSizer1->Add(BoxSizer13, 0, wxALL|wxEXPAND, 5);
    BoxSizer14 = new wxBoxSizer(wxVERTICAL);
    StaticText4 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT4, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer14->Add(StaticText4, 0, wxALL, 5);
    m_pSliderTremeloDelay = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERTREMELODELAY, 0, 0, 99, wxDefaultPosition, wxSize(20,100), wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTREMELODELAY"));
    m_pSliderTremeloDelay->SetToolTip(_("Set tremelo delay"));
    BoxSizer14->Add(m_pSliderTremeloDelay, 1, wxALL, 5);
    StaticBoxSizer1->Add(BoxSizer14, 0, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("Vibrato"));
    BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer16 = new wxBoxSizer(wxVERTICAL);
    wxString __wxRadioBoxChoices_3[2] =
    {
    	_("Off"),
    	_("On")
    };
    m_pRadioVibratoMulti = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOBOX3, _("Multi"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX3"));
    m_pRadioVibratoMulti->SetToolTip(_("Select vibrato multi"));
    BoxSizer16->Add(m_pRadioVibratoMulti, 1, wxALL|wxEXPAND, 5);
    wxString __wxRadioBoxChoices_4[4] =
    {
    	_("Triangle"),
    	_("Saw Up"),
    	_("Saw Down"),
    	_("Square")
    };
    m_pRadioVibratoWaveform = new wxRadioBox(m_pScrollwindowGlobalParameters, ID_RADIOBOX4, _("Waveform"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_4, 1, wxRA_HORIZONTAL, wxDefaultValidator, _T("ID_RADIOBOX4"));
    m_pRadioVibratoWaveform->SetToolTip(_("Select vibrato waveform"));
    BoxSizer16->Add(m_pRadioVibratoWaveform, 1, wxALL|wxEXPAND, 5);
    BoxSizer15->Add(BoxSizer16, 0, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    StaticText7 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT7, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    BoxSizer4->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoDepth = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDER5, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER5"));
    m_pSliderVibratoDepth->SetToolTip(_("Set vibrato depth"));
    BoxSizer4->Add(m_pSliderVibratoDepth, 1, wxALL, 5);
    BoxSizer15->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
    BoxSizer17 = new wxBoxSizer(wxVERTICAL);
    StaticText8 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT8, _("Rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    BoxSizer17->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoRate = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDER4, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER4"));
    m_pSliderVibratoRate->SetToolTip(_("Set vibrato rate"));
    BoxSizer17->Add(m_pSliderVibratoRate, 1, wxALL, 5);
    BoxSizer15->Add(BoxSizer17, 0, wxALL|wxEXPAND, 5);
    BoxSizer18 = new wxBoxSizer(wxVERTICAL);
    StaticText9 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT9, _("Delay"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    BoxSizer18->Add(StaticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVibratoDelay = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDER6, 0, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER6"));
    m_pSliderVibratoDelay->SetToolTip(_("Set vibrato delay"));
    BoxSizer18->Add(m_pSliderVibratoDelay, 1, wxALL, 5);
    BoxSizer15->Add(BoxSizer18, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer2->Add(BoxSizer15, 1, wxALL|wxEXPAND, 5);
    m_pFlexgridGlobalParameters->Add(StaticBoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pScrollwindowGlobalParameters->SetSizer(m_pFlexgridGlobalParameters);
    m_pFlexgridGlobalParameters->Fit(m_pScrollwindowGlobalParameters);
    m_pFlexgridGlobalParameters->SetSizeHints(m_pScrollwindowGlobalParameters);
    m_pSplitterMain->SplitVertically(m_pScrollWinVoiceEditor, m_pScrollwindowGlobalParameters);
    BoxSizer1->Add(m_pSplitterMain, 1, wxALL|wxEXPAND, 5);
    m_pPnlVoice->SetSizer(BoxSizer1);
    BoxSizer1->Fit(m_pPnlVoice);
    BoxSizer1->SetSizeHints(m_pPnlVoice);
    m_pPnlOperation = new wxPanel(m_pNotebook, ID_PNLOPERATION, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PNLOPERATION"));
    m_pPnlOperation->SetToolTip(_("Select operation editor tab"));
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
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    StaticText12 = new wxStaticText(ScrolledWindow2, ID_STATICTEXT13, _("Operation Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer19->Add(StaticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtOperationName = new wxTextCtrl(ScrolledWindow2, ID_TXTOPERATIONNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, m_validateVoiceName, _T("ID_TXTOPERATIONNAME"));
    m_pTxtOperationName->SetMaxLength(12);
    m_pTxtOperationName->SetToolTip(_("Edit operation name"));
    BoxSizer19->Add(m_pTxtOperationName, 1, wxALL, 5);
    BoxSizer7->Add(BoxSizer19, 0, wxALL|wxEXPAND, 5);
    ScrolledWindow2->SetSizer(BoxSizer7);
    BoxSizer7->Fit(ScrolledWindow2);
    BoxSizer7->SetSizeHints(ScrolledWindow2);
    SplitterWindow2->SplitVertically(ScrolledWindow1, ScrolledWindow2);
    BoxSizer5->Add(SplitterWindow2, 1, wxALL|wxEXPAND, 5);
    m_pPnlOperation->SetSizer(BoxSizer5);
    BoxSizer5->Fit(m_pPnlOperation);
    BoxSizer5->SetSizeHints(m_pPnlOperation);
    m_pPnlMultichannel = new wxPanel(m_pNotebook, ID_PANELMULTICHANNEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELMULTICHANNEL"));
    m_pPnlMisc = new wxPanel(m_pNotebook, ID_PANELMISC, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELMISC"));
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer8 = new wxStaticBoxSizer(wxVERTICAL, m_pPnlMisc, _("Master Volume"));
    m_pSliderVolume = new wxSlider(m_pPnlMisc, ID_SLIDERVOLUME, 100, 0, 127, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_LABELS|wxSL_RIGHT|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERVOLUME"));
    m_pSliderVolume->SetToolTip(_("Set master tune"));
    StaticBoxSizer8->Add(m_pSliderVolume, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer8, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, m_pPnlMisc, _("Master Tune"));
    m_pSliderMasterTune = new wxSlider(m_pPnlMisc, ID_SLIDERMASTERTUNE, 0, -64, 64, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_LABELS|wxSL_RIGHT|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERMASTERTUNE"));
    m_pSliderMasterTune->SetToolTip(_("Set master tune"));
    StaticBoxSizer4->Add(m_pSliderMasterTune, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, m_pPnlMisc, _("Transpose"));
    m_pSliderTranspose = new wxSlider(m_pPnlMisc, ID_SLIDERTRANSPOSE, 0, -5, 6, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_LABELS|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERTRANSPOSE"));
    StaticBoxSizer5->Add(m_pSliderTranspose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, m_pPnlMisc, _("CZ Bend Range"));
    m_pSliderCZBendRange = new wxSlider(m_pPnlMisc, ID_SLIDERCZBENDRANGE, 0, 0, 48, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_LABELS|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERCZBENDRANGE"));
    m_pSliderCZBendRange->SetToolTip(_("Set CZ bend range"));
    StaticBoxSizer7->Add(m_pSliderCZBendRange, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer7, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, m_pPnlMisc, _("Mode"));
    m_pChoiceMode = new wxChoice(m_pPnlMisc, ID_CHOICEMODE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICEMODE"));
    m_pChoiceMode->Append(_("Normal Mode"));
    m_pChoiceMode->Append(_("Combination Mode"));
    m_pChoiceMode->Append(_("Operation Mode"));
    m_pChoiceMode->Append(_("Multichannel Mode"));
    m_pChoiceMode->Append(_("Multichannel Mode Poly=0"));
    m_pChoiceMode->Append(_("Multichannel Mode Poly=1"));
    m_pChoiceMode->SetToolTip(_("Select VZ mode"));
    StaticBoxSizer6->Add(m_pChoiceMode, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_5[4] =
    {
    	_("1"),
    	_("2"),
    	_("3"),
    	_("4")
    };
    m_pRadioCardbank = new wxRadioBox(m_pPnlMisc, ID_RADIOBOXCARDBANK, _("Card Bank"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_5, 1, 0, wxDefaultValidator, _T("ID_RADIOBOXCARDBANK"));
    m_pRadioCardbank->SetToolTip(_("Select card bank"));
    StaticBoxSizer6->Add(m_pRadioCardbank, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(StaticBoxSizer6, 1, wxALL, 5);
    m_pPnlMisc->SetSizer(BoxSizer8);
    BoxSizer8->Fit(m_pPnlMisc);
    BoxSizer8->SetSizeHints(m_pPnlMisc);
    m_pNotebook->AddPage(m_pPnlLibrary, _("Library"), false);
    m_pNotebook->AddPage(m_pPnlVoice, _("Tone Editor"), false);
    m_pNotebook->AddPage(m_pPnlOperation, _("Operation Editor"), false);
    m_pNotebook->AddPage(m_pPnlMultichannel, _("Multi-channel Editor"), false);
    m_pNotebook->AddPage(m_pPnlMisc, _("Misc"), false);
    m_pSizerMain->Add(m_pNotebook, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND, 5);
    m_pSizerKeyboard = new wxBoxSizer(wxHORIZONTAL);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer21 = new wxBoxSizer(wxVERTICAL);
    StaticText13 = new wxStaticText(Panel2, ID_STATICTEXT14, _("MIDI Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    BoxSizer21->Add(StaticText13, 0, wxALL|wxEXPAND, 5);
    m_pSpnKeyChannel = new wxSpinCtrl(Panel2, ID_SPIN_KEYCHAN, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 16, 1, _T("ID_SPIN_KEYCHAN"));
    m_pSpnKeyChannel->SetValue(_T("1"));
    BoxSizer21->Add(m_pSpnKeyChannel, 0, wxALL, 5);
    StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT15, _("Program"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    BoxSizer21->Add(StaticText14, 0, wxALL|wxEXPAND, 5);
    m_pSpnProgram = new wxSpinCtrl(Panel2, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 128, 1, _T("ID_SPINCTRL1"));
    m_pSpnProgram->SetValue(_T("1"));
    BoxSizer21->Add(m_pSpnProgram, 0, wxALL, 5);
    Panel2->SetSizer(BoxSizer21);
    BoxSizer21->Fit(Panel2);
    BoxSizer21->SetSizeHints(Panel2);
    m_pSizerKeyboard->Add(Panel2, 0, wxALL|wxEXPAND, 5);
    m_pKeyboard = new Keyboard(this,ID_KBD);
    m_pSizerKeyboard->Add(m_pKeyboard, 1, wxALL|wxEXPAND, 5);
    m_pSizerMain->Add(m_pSizerKeyboard, 0, wxALL|wxEXPAND, 5);
    SetSizer(m_pSizerMain);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuOpen, _("&Open\tCtrl+O"), _("Open file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu1, idMenuSave, _("&Save\tCtrl+S"), _("Save voice data to file"), wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem10 = new wxMenuItem(Menu1, ID_MENU_SAVEAS, _("Save &As"), _("Save with new filename"), wxITEM_NORMAL);
    Menu1->Append(MenuItem10);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu3, ID_MENU_HEADER, _("&Header\tALT+0"), _("Move focus to header"), wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    Menu4 = new wxMenuItem(Menu3, ID_MENU_LIBRARY, _("&Library\tALT+1"), _("Show library editor"), wxITEM_NORMAL);
    Menu3->Append(Menu4);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENU_VOICE, _("&Voice\tALT+2"), _("Show voice editor"), wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENU_OPERATION, _("&Operation\tALT+3"), _("Show operation editor"), wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem11 = new wxMenuItem(Menu3, ID_MENU_MULTICHANNEL, _("Multi-&channel\tALT+4"), _("Show multi-channel editor"), wxITEM_NORMAL);
    Menu3->Append(MenuItem11);
    MenuItem9 = new wxMenuItem(Menu3, ID_MENU_MISC, _("&Misc\tALT+5"), _("Show miscelaneous control panel"), wxITEM_NORMAL);
    Menu3->Append(MenuItem9);
    MenuItem8 = new wxMenuItem(Menu3, ID_MENU_KEYBOARD, _("&Keyboard\tALT+K"), _("Show on-screen MIDI keyboard"), wxITEM_NORMAL);
    Menu3->Append(MenuItem8);
    MenuBar1->Append(Menu3, _("&View"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    m_pStatusbar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    m_pStatusbar->SetFieldsCount(1,__wxStatusBarWidths_1);
    m_pStatusbar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(m_pStatusbar);
    m_timer1s.SetOwner(this, ID_TIMER1S);
    m_timer1s.Start(300, true);
    SetSizer(m_pSizerMain);
    Layout();
    Center();

    Connect(ID_CMBINPORT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnInPortSelect);
    Connect(ID_CMBOUTPORT,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnOutPortSelect);
    Connect(ID_CHECKBOXKEYBOARD,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnChkKeyboard);
    Connect(ID_CHKAUTOUPDATE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZEditorFrame::Onm_pChkKeyboardClick);
    Connect(ID_BTNSEND,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnBtnSendClick);
    Connect(ID_BTNGETVOICE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnBtnGetVoice);
    Connect(ID_BTNGETOPERATION,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnBtnGetOperation);
    Connect(ID_BTNSAVEDUMP,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnBtnSaveDump);
    Connect(ID_BITMAPBUTTONLIBTOOLADD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnLibToolAdd);
    Connect(ID_BITMAPBUTTONLIBTOOLDELETE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnLibToolDelete);
    Connect(ID_BITMAPBUTTONLIBTOOLSAVE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnSaveFile);
    Connect(ID_BITMAPBUTTONLIBTOOLSAVEAS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnSaveFile);
    Connect(ID_BITMAPBUTTONLIBTOOLOPRN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnOpenFile);
    Connect(ID_LISTBOXLIBRARY,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnLstLibrary);
    Connect(ID_LISTBOXLIBRARY,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&VZEditorFrame::OnLibDClick);
    Connect(ID_GRIDCONFIG,wxEVT_GRID_CELL_LEFT_DCLICK,(wxObjectEventFunction)&VZEditorFrame::OnGridConfigDClick);
    m_pGridConfig->Connect(wxEVT_KEY_DOWN,(wxObjectEventFunction)&VZEditorFrame::OnGridConfigKeyDown,0,this);
    m_pGridConfig->Connect(wxEVT_KEY_UP,(wxObjectEventFunction)&VZEditorFrame::OnGridConfigKeyUp,0,this);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnTxtVoiceNameText);
    Connect(ID_SLIDERLEVEL,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnLevelChanged);
    Connect(ID_SLIDEROCTAVE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnOctaveChanged);
    Connect(ID_SLIDERVELSENS,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnDcoVelSensChange);
    Connect(ID_CMBVELCURVE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnCmbVelCurveSelect);
    Connect(ID_RADIOTREMELOMULTI,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnRadioTremeloMultiSelect);
    Connect(ID_RADIOTREMELOWAVEFORM,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnRadioTremeloWaveformSelect);
    Connect(ID_SLIDERTREMELODEPTH,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnTremeloDepthChanged);
    Connect(ID_SLIDERTREMELORATE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnTremeloRateChanged);
    Connect(ID_SLIDERTREMELODELAY,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnTremeloDelayChanged);
    Connect(ID_RADIOBOX3,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnRadioVibratoMultiSelect);
    Connect(ID_RADIOBOX4,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnRadioVibratoWaveformSelect);
    Connect(ID_SLIDER5,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnVibratoDepthChanged);
    Connect(ID_SLIDER4,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnVibratoRateChanged);
    Connect(ID_SLIDER6,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnVibratoDelayChanged);
    Connect(ID_TXTOPERATIONNAME,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnTxtVoiceNameText);
    Connect(ID_SLIDERVOLUME,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnMasterVolume);
    Connect(ID_SLIDERMASTERTUNE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnMasterTune);
    Connect(ID_SLIDERTRANSPOSE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnTranspose);
    Connect(ID_SLIDERCZBENDRANGE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZEditorFrame::OnCzBendRange);
    Connect(ID_CHOICEMODE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMode);
    Connect(ID_RADIOBOXCARDBANK,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnCardBank);
    Connect(ID_SPIN_KEYCHAN,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnKeyChan);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnKeyProgram);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnOpenFile);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnSaveFile);
    Connect(ID_MENU_SAVEAS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnSaveAs);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnQuit);
    Connect(ID_MENU_HEADER,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(ID_MENU_LIBRARY,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(ID_MENU_VOICE,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(ID_MENU_OPERATION,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(ID_MENU_MULTICHANNEL,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(ID_MENU_MISC,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(ID_MENU_KEYBOARD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnMenuShow);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnAbout);
    Connect(ID_TIMER1S,wxEVT_TIMER,(wxObjectEventFunction)&VZEditorFrame::OnTimer1s);
    //*)
    m_pScrollWinVoiceEditor->SetScrollRate(10,10);
    m_pScrollwindowGlobalParameters->SetScrollRate(0, 10);

//    m_pGridConfig->SetSelectionMode(wxGrid::wxGridSelectionModes::wxGridSelectRowsOrColumns);
//    m_pGridConfig->EnableDragCell();
    for(unsigned int nRow = 0; nRow < 8; ++ nRow)
    {
        m_pGridConfig->DisableRowResize(nRow);
        m_pGridConfig->DisableRowResize(nRow + 8);
        for(unsigned int nCol = 0; nCol < 8; ++nCol)
        {
            m_pGridConfig->SetCellBackgroundColour(nRow, nCol, wxColour(200, 210, 220));
            m_pGridConfig->SetCellBackgroundColour(nRow + 8, nCol, wxColour(220, 210, 200));
            m_pGridConfig->DisableColResize(nCol);
        }
    }
    Connect(wxID_ANY, wxEVT_MIDI_INPUT,(wxObjectEventFunction)&VZEditorFrame::OnMidiReceive);
    Connect(wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&VZEditorFrame::OnClose);

    wxConfig configPersist(wxTheApp->GetAppName(), "riban",wxEmptyString, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
    int nX, nY, nWidth, nHeight;
    bool bX;
    configPersist.Read("persist/keyboard", &bX, false);
    m_pSizerKeyboard->Show(bX);
    m_pChkKeyboard->SetValue(bX);
    //Position window
    configPersist.Read("persist/left", &nX, 0);
    configPersist.Read("persist/top", &nY, 0);
    configPersist.Read("persist/width", &nWidth, 800);
    configPersist.Read("persist/height", &nHeight, 600);
    configPersist.Read("persist/maximised", &bX, false);
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

    configPersist.Read("persist/midi_in", &nX, 0);
    if(m_pChoiceInPort->GetCount())
    {
        if((int)m_pChoiceInPort->GetCount() - 1 < nX)
            nX = m_pChoiceInPort->GetCount() - 1;
        if(nX < 0)
            nX = 0;
        wxCommandEvent event;
        m_pChoiceInPort->Select(nX);
        event.SetClientData(m_pChoiceInPort->GetClientData(nX));
        OnInPortSelect(event);
    }
    configPersist.Read("persist/midi_out", &nX, 0);
    if(m_pChoiceOutPort->GetCount())
    {
        if((int)m_pChoiceOutPort->GetCount() - 1 < nX)
            nX = m_pChoiceOutPort->GetCount() - 1;
        if(nX < 0)
            nX = 0;
        wxCommandEvent event;
        m_pChoiceOutPort->Select(nX);
        event.SetClientData(m_pChoiceOutPort->GetClientData(nX));
        OnOutPortSelect(event);
    }
    configPersist.Read("persist/keyboard_midi_channel", &nX, 0);
    m_pSpnKeyChannel->SetValue(nX + 1);
    m_pKeyboard->SetSendChannel(nX);
    bool bAuto;
    configPersist.Read("persist/auto_update", &bAuto, false);
    m_pChkAutoUpdate->SetValue(bAuto);
    wxString sFilename;
    configPersist.Read("persist/library", &sFilename);
    m_pvzLib = new VZLibrary();
    LoadFile(sFilename);
    m_pVoice = new VZVoice();
    m_pVoice->SetEventHandler(this);
    m_pVoiceMidi = new VZVoice();
    m_pOperation = new VZOperation();
    m_pOperation->SetEventHandler(this);
    m_pOperationMidi = new VZOperation();

    m_pLine1->SetVoice(m_pVoice);
    m_pLine2->SetVoice(m_pVoice);
    m_pLine3->SetVoice(m_pVoice);
    m_pLine4->SetVoice(m_pVoice);
    m_bInhibitUpdate = false;

    // Configure drag and drop of library elements
    m_pLstLibrary->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(VZEditorFrame::onLstLibLeftDown), NULL, this);
    m_pGridConfig->SetDropTarget(new VZDropTarget(m_pGridConfig));

    LoadLibrary();
}

VZEditorFrame::~VZEditorFrame()
{
}

void VZEditorFrame::OnClose(wxCloseEvent& event)
{
    wxConfig configPersist(wxTheApp->GetAppName(), "riban",wxEmptyString, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
    configPersist.Write("persist/midi_out", m_pChoiceOutPort->GetSelection());
    configPersist.Write("persist/auto_update", m_pChkAutoUpdate->IsChecked());
    configPersist.Write("persist/midi_in", m_pChoiceInPort->GetSelection());
    configPersist.Write("persist/maximised", IsMaximized());
    configPersist.Write("persist/keyboard", m_pChkKeyboard->IsChecked());
    configPersist.Write("persist/keyboard_midi_channel", m_pSpnKeyChannel->GetValue() - 1);
    configPersist.Write("persist/library", m_pvzLib->GetFilename());

    if(!IsMaximized() && !IsIconized())
    {
        configPersist.Write("persist/width", GetSize().GetWidth());
        configPersist.Write("persist/height", GetSize().GetHeight());
        configPersist.Write("persist/left", GetPosition().x);
        configPersist.Write("persist/top", GetPosition().y);
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

void VZEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void VZEditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString sMessage = wxString::Format("VZEditor %ld.%ld.%ld\n\n", AutoVersion::MAJOR, AutoVersion::MINOR, AutoVersion::BUILD);
    sMessage += "Copyright riban <brian@riban.co.uk> 2014-2020\nLicense: GPL3 <https://www.gnu.org/licenses/gpl-3.0.html>\n";
    sMessage += "wxMidi(c) 2005-2015 Cecilio Salmeron - wxWidgets license, version 3.1\n";
    sMessage += "portmidi (c) 1999-2000 Ross Bencina and Phil Burk, 2001-2006 Roger B. Dannenberg";
    wxMessageBox(sMessage, "Casio VZ-1 / VZ-10M / VZ-8 library and editor");
}

int VZEditorFrame::GetPortId(PmDeviceInfo* pInfo)
{
    for(int nPort = 0; nPort < Pm_CountDevices(); ++nPort)
        if(pInfo == Pm_GetDeviceInfo(nPort))
            return nPort;
    return -1;
}

void VZEditorFrame::OnInPortSelect(wxCommandEvent& event)
{
    CloseInput();
    int nPort = GetPortId((PmDeviceInfo*)event.GetClientData());
    if(nPort < 0)
        return;
    m_pMidiIn = new wxMidiInDevice(nPort);
    m_pMidiIn->Open();
    m_pMidiIn->StartListening(this);
}

void VZEditorFrame::OnOutPortSelect(wxCommandEvent& event)
{
    CloseOutput();
    int nPort = GetPortId((PmDeviceInfo*)event.GetClientData());
    if(nPort < 0)
        return;
    m_pMidiOut = new wxMidiOutDevice(nPort);
    m_pMidiOut->Open(0);
    m_pBtnSend->Enable();
}

void VZEditorFrame::CloseInput()
{
    if(!m_pMidiIn)
        return;
    m_pMidiIn->StopListening();
    m_pMidiIn->Close();
    delete m_pMidiIn;
    m_pMidiIn = (wxMidiInDevice*)NULL;
}

void VZEditorFrame::CloseOutput()
{
    if(!m_pMidiOut)
        return;
    m_pMidiOut->Close();
    delete m_pMidiOut;
    m_pMidiOut = (wxMidiOutDevice*)NULL;
}

void VZEditorFrame::OnMidiReceive(wxCommandEvent &event)
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
//        m_pLstLog->Append(wxString::Format("VZ-1/VZ-10 SysEx message. Length %ld. Channel %d. Type %d", lLength, nChannel + 1, nType));
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

void VZEditorFrame::OnVzSave()
{
    //!@todo What to do when save message received?
    if(m_vzSave.GetAvailable() == VZSAVE_DATATYPE_NONE)
        return;
    for(unsigned int i = 0; i < 64; ++i)
    {
        VZVoice* pVoice = m_vzSave.GetVoice(i);
        if(pVoice)
        {
            wxString sName = pVoice->GetName();
        }
        VZOperation* pOperation = m_vzSave.GetOperation(i);
        if(pOperation)
        {
            wxString sName = pOperation->GetName();
        }
    }
}

void VZEditorFrame::Save(unsigned int nType, wxString sFilename)
{
    if(sFilename.IsEmpty())
    {
        wxFileDialog dlg(this, wxEmptyString, wxEmptyString, wxEmptyString, wxEmptyString, wxFD_SAVE);
        switch(nType)
        {
        case VZ_TYPE_LIBRARY:
            //Library
            dlg.SetWildcard("Library files (*.xml)|*.xml|All files (*.*)|*.*");
            break;
        case VZ_TYPE_TONE:
            //Voice
            dlg.SetFilename(wxString::Format("%s.vzt", m_pVoice->GetName().c_str()));
            dlg.SetWildcard("VZ tone files (*.vzt)|*.vzt|All files (*.*)|*.*");
            break;
        case VZ_TYPE_OPERATION:
            //Operation data
            dlg.SetFilename(wxString::Format("%s.vzo", m_pOperation->GetName().c_str()));
            dlg.SetWildcard("VZ operation files (*.vzo)|*.vzo|All files (*.*)|*.*");
            break;
        default:
            return;
        }
        if(dlg.ShowModal() == wxID_CANCEL)
            return;
        if(wxFileExists(dlg.GetPath()) && wxMessageBox("Do you want to overwrite existing file?", "Warning", wxYES_NO|wxICON_WARNING) != wxYES)
            return;
        sFilename = dlg.GetPath();
    }
    VZSysex* pSysex = NULL;
    switch(nType)
    {
    case VZ_TYPE_LIBRARY:
        //Library
        m_pvzLib->Save(sFilename);
        return;
        break;
    case VZ_TYPE_TONE:
        //Voice
        pSysex = (VZVoice*)m_pVoice;
        break;
    case VZ_TYPE_OPERATION:
        //Operation data
        pSysex = (VZOperation*)m_pOperation;
        break;
    default:
        return;
    }
    if(pSysex)
    {
        pSysex->Update();
        wxFile file(sFilename, wxFile::write);
        if(!file.IsOpened())
        {
            wxMessageBox("Failed to save file", "Error", wxICON_ERROR);
            return;
        }
        if(file.Write(pSysex->GetSysEx(), pSysex->GetSize()) != pSysex->GetSize())
            wxMessageBox("Error - corrupt file", "Error", wxICON_ERROR);
        file.Close();
        pSysex->Archive();
    }
}

bool VZEditorFrame::LoadFile(wxString sFilename)
{
    if(!wxFileExists(sFilename))
    {
        wxMessageBox("File '" + sFilename + "' does not exist", "Error", wxICON_ERROR);
        return false;
    }
    wxFileName fnFilename(sFilename);
    if(fnFilename.GetExt().Lower().IsSameAs("xml"))
    {
        if(m_pvzLib->IsDirty())
        {
            //!@todo Handle dirty library should probably be before here
            if(wxMessageBox("Library has changed. Save before loading new library?", "Warning", wxYES_NO|wxICON_WARNING) == wxYES)
                m_pvzLib->Save();
        }
        m_pvzLib->Load(sFilename);
        m_pGridConfig->ClearGrid();
        for(unsigned int nRow = 0; nRow < 8; ++ nRow)
            for(unsigned int nColumn = 0; nColumn < 8; ++ nColumn)
            {
                m_pGridConfig->SetCellValue(nRow, nColumn, m_pvzLib->GetToneName(nRow + nColumn * 8));
                m_pGridConfig->SetCellValue(nRow + 8, nColumn, m_pvzLib->GetOperationName(nRow + nColumn * 8));
            }
        return true;
    }
    wxFile file(sFilename, wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox("Failed to open file", "Error", wxICON_ERROR);
        return false;
    }
    wxByte acSysex[file.Length()];
    if(file.Length() < VZ_HEADER_SIZE || file.Length() != file.Read(acSysex, file.Length()))
    {
        wxMessageBox("Failed to read file", "Error", wxICON_ERROR);
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
            m_pVoice->SetFilename(sFilename);
        }
        else
            m_pVoice->SetFilename(wxEmptyString);
        break;
    case VZ_TYPE_OPERATION:
        if(!m_pOperation->SetSysEx(acSysex))
        {
            UpdateOperationGui();
            m_pNotebook->SetSelection(2);
            bFail = false;
            m_pOperation->SetFilename(sFilename);
        }
        else
            m_pOperation->SetFilename(wxEmptyString);
        break;
    default:
        bFail = true;
    }
    if(bFail)
    {
        wxMessageBox("This does not appear to be a valid VZ file", "Error", wxICON_ERROR);
        return false;
    }
    return true;
}

void VZEditorFrame::Send()
{
    if(CheckHostError())
        return;
    VZSysex* pSysex = NULL;
    switch(m_pNotebook->GetSelection())
    {
    case 0: //Library
        return;
        break;
    case 1: //Voice
        pSysex = (VZVoice*)m_pVoice;
        break;
    case 2: //Operation data
        pSysex = (VZOperation*)m_pOperation;
        break;
    default:
        return;
    }
    pSysex->Validate(true);
    wxMidiSysExMessage sysExMsg(pSysex->GetSysEx());
    m_pLblMidiOutputPort->SetBackgroundColour(*wxGREEN);
    m_pLblMidiOutputPort->Refresh();
    m_pMidiOut->Write(&sysExMsg);
    m_timer1s.Start(300, true);
}

void VZEditorFrame::GetVoice()
{
    m_pVoice->SetSysEx(m_pVoiceMidi->GetSysEx());
    UpdateVoiceGui();
}

void VZEditorFrame::GetOperation()
{
    m_pOperation->SetSysEx(m_pOperationMidi->GetSysEx());
    UpdateOperationGui();
}

void VZEditorFrame::UpdateVoiceGui()
{
    m_pTxtVoiceName->SetValue(m_pVoice->GetName());
    m_pSliderLevel->SetValue(m_pVoice->GetLevel());
    m_pSliderOctave->SetValue(m_pVoice->GetOctave());
    m_pSliderVelSens->SetValue(m_pVoice->GetPitchVelSens());
    m_pChoiceVelCurve->SetSelection(m_pVoice->GetPitchVelCurve());
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
    m_pLine1->UpdateGui();
    m_pLine2->UpdateGui();
    m_pLine3->UpdateGui();
    m_pLine4->UpdateGui();
}

void VZEditorFrame::UpdateOperationGui()
{
    m_pTxtOperationName->SetValue(m_pOperation->GetName());
}

void VZEditorFrame::OnBtnSendClick(wxCommandEvent& event)
{
    Send();
}

void VZEditorFrame::OnTxtVoiceNameText(wxCommandEvent& event)
{
    m_pVoice->SetName(m_pTxtVoiceName->GetValue());
}

void VZEditorFrame::OnRadioTremeloMultiSelect(wxCommandEvent& event)
{
    m_pVoice->EnableTremeloMulti(event.GetInt() == 1);
}

void VZEditorFrame::OnCmbVelCurveSelect(wxCommandEvent& event)
{
    m_pVoice->SetPitchVelCurve(event.GetSelection());
}

void VZEditorFrame::OnRadioTremeloWaveformSelect(wxCommandEvent& event)
{
    m_pVoice->SetTremeloWaveform(event.GetInt());
}

void VZEditorFrame::OnRadioVibratoMultiSelect(wxCommandEvent& event)
{
    m_pVoice->EnableVibratoMulti(event.GetInt() == 1);
}

void VZEditorFrame::OnRadioVibratoWaveformSelect(wxCommandEvent& event)
{
    m_pVoice->SetVibratoWaveform(event.GetInt());
}

void VZEditorFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxEmptyString, wxEmptyString, wxEmptyString,"Library files (*.xml)|*.xml|VZ tone files (*vzt)|*.vzt|VZ operation files (*vzo)|*.vzo|All files (*.*)|*.*", wxFD_OPEN);
    dlg.SetFilterIndex(m_pNotebook->GetSelection());
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    wxFileName fnFilename(dlg.GetPath());
    LoadFile(dlg.GetPath());
}

void VZEditorFrame::OnBtnGetVoice(wxCommandEvent& event)
{
    GetVoice();
    m_pNotebook->SetSelection(1);
}

void VZEditorFrame::OnBtnGetOperation(wxCommandEvent& event)
{
    GetOperation();
    m_pNotebook->SetSelection(2);
}

void VZEditorFrame::OnSaveFile(wxCommandEvent& event)
{
    switch(m_pNotebook->GetSelection())
    {
    case 0:
        Save(VZ_TYPE_LIBRARY, m_pvzLib->GetFilename());
        break;
    case 1:
        Save(VZ_TYPE_TONE, m_pVoice->GetFilename());
        break;
    case 2:
        Save(VZ_TYPE_OPERATION, m_pOperation->GetFilename());
        break;
    }
}

void VZEditorFrame::UpdateMidiPorts()
{
    m_pChoiceInPort->Clear();
    m_pChoiceOutPort->Clear();
    int nDevices = Pm_CountDevices();
    for(int i = 0; i < nDevices; ++i)
    {
        const PmDeviceInfo* pInfo = Pm_GetDeviceInfo(i);
        if(pInfo->input)
        {
            int nIndex = m_pChoiceInPort->Append(wxString::FromUTF8(pInfo->name));
            m_pChoiceInPort->SetClientData(nIndex, (void*)pInfo);
        }
        if(pInfo->output)
        {
            int nIndex = m_pChoiceOutPort->Append(wxString::FromUTF8(pInfo->name));
            m_pChoiceOutPort->SetClientData(nIndex, (void*)pInfo);
        }
    }
}

void VZEditorFrame::AutoSend()
{
    if(m_pChkAutoUpdate->IsChecked())
        Send();
}

void VZEditorFrame::OnLevelChanged(wxScrollEvent& event)
{
    m_pVoice->SetLevel(event.GetInt());
}

void VZEditorFrame::OnOctaveChanged(wxScrollEvent& event)
{
    m_pVoice->SetOctave(event.GetInt());
}

void VZEditorFrame::OnDcoVelSensChange(wxScrollEvent& event)
{
    m_pVoice->SetPitchVelSens(event.GetInt());
}


void VZEditorFrame::OnTremeloDepthChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloDepth(event.GetInt());
}

void VZEditorFrame::OnTremeloRateChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloRate(event.GetInt());
}

void VZEditorFrame::OnTremeloDelayChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloDelay(event.GetInt());
}

void VZEditorFrame::OnVibratoDepthChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoDepth(event.GetInt());
}

void VZEditorFrame::OnVibratoRateChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoRate(event.GetInt());
}

void VZEditorFrame::OnVibratoDelayChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoDelay(event.GetInt());
}


void VZEditorFrame::OnBtnSaveDump(wxCommandEvent& event)
{
    wxFileDialog dlg(this, "Select filename and folder to save new library", wxEmptyString, "NewLibrary.xml", "Library files (*.xml)|*.xml|All files (*.*)|*.*", wxFD_SAVE);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    m_vzSave.SaveToDisk(dlg.GetPath());
}

void VZEditorFrame::OnChkKeyboard(wxCommandEvent& event)
{
    m_pSizerKeyboard->Show(event.IsChecked());
    m_pSizerMain->Layout();
}

void VZEditorFrame::OnKeyboardNoteOn(wxCommandEvent& event)
{
    if(CheckHostError())
        return;
    KeyboardEventData* pData = (KeyboardEventData*)event.GetClientData();
    if(pData)
    {
        m_pMidiOut->NoteOn(pData->channel, pData->note, pData->velocity);
        m_pStatusbar->SetStatusText(wxString::Format("Note on: channel %d, note %d, velocity %d", pData->channel, pData->note, pData->velocity));
    }
}

void VZEditorFrame::OnKeyboardNoteOff(wxCommandEvent& event)
{
    if(CheckHostError())
        return;
    m_pStatusbar->SetStatusText(wxString::Format("Note off: %d", event.GetInt()));
    KeyboardEventData* pData = (KeyboardEventData*)event.GetClientData();
    if(pData)
        m_pMidiOut->NoteOff(pData->channel, pData->note, pData->velocity);
}

void VZEditorFrame::OnKeyChan(wxSpinEvent& event)
{
    m_pKeyboard->SetSendChannel(event.GetValue() - 1);
    m_pSpnProgram->SetValue(m_anProgram[event.GetValue() - 1]);
}

void VZEditorFrame::OnKeyProgram(wxSpinEvent& event)
{
    if(CheckHostError())
        m_pMidiOut->ProgramChange(m_pKeyboard->GetSendChannel(), event.GetValue() - 1);
    m_anProgram[m_pSpnKeyChannel->GetValue() - 1] = event.GetValue();
}

void VZEditorFrame::Onm_pChkKeyboardClick(wxCommandEvent& event)
{
}

void VZEditorFrame::Onm_pCmbOutPortSelect(wxCommandEvent& event)
{
}

void VZEditorFrame::OnTimer1s(wxTimerEvent& event)
{
    m_pLblMidiInputPort->SetBackgroundColour(wxNullColour);
    m_pLblMidiInputPort->Refresh();
    m_pLblMidiOutputPort->SetBackgroundColour(wxNullColour);
    m_pLblMidiOutputPort->Refresh();
}

void VZEditorFrame::OnLibToolAdd(wxCommandEvent& event)
{
    wxFileDialog dlg(this, "Select voice or operation file to add to library",
                     wxEmptyString, wxEmptyString, wxEmptyString, wxFD_OPEN);
    dlg.SetWildcard("VZ files (*.vzt;*vzo)|*.vzt;*vzo|All files (*.*)|*.*");
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    wxFile file(dlg.GetPath(), wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox("Failed to open file", "Error", wxICON_ERROR);
        return;
    }
    wxByte acSysex[file.Length()];
    if(file.Length() < VZ_HEADER_SIZE || file.Length() != file.Read(acSysex, file.Length()))
    {
        wxMessageBox("Failed to read file", "Error", wxICON_ERROR);
        file.Close();
        return;
    }
    file.Close();
    wxString sFilename = wxEmptyString;
    wxString sName;
    wxString sType;
    switch(acSysex[VZ_HEADER_TYPE])
    {
    case VZ_TYPE_TONE:
    {
        VZVoice voiceTemp;
        if(!voiceTemp.SetSysEx(acSysex))
        {
            sName = voiceTemp.GetName();
            sType = "vzvoice";
        }
        break;
    }
    case VZ_TYPE_OPERATION:
    {
        VZOperation opTemp;
        if(!opTemp.SetSysEx(acSysex))
        {
            sName = opTemp.GetName();
            sType = "vzoperation";
        }
        break;
    }
    }
    if(sName.IsEmpty())
        return;
    m_pBtnLibToolSave->Enable(m_pvzLib->IsDirty());
}

void VZEditorFrame::OnLibToolDelete(wxCommandEvent& event)
{
    m_pBtnLibToolSave->Enable(m_pvzLib->IsDirty());
}

void VZEditorFrame::OnMenuShow(wxCommandEvent& event)
{
    if(event.GetId() == ID_MENU_HEADER)
        m_pChoiceInPort->SetFocus();
    else if(event.GetId() == ID_MENU_LIBRARY)
    {
        m_pNotebook->SetSelection(0);
        m_pGridConfig->SetFocus();
    }
    else if(event.GetId() == ID_MENU_VOICE)
        m_pNotebook->SetSelection(1);
    else if(event.GetId() == ID_MENU_OPERATION)
        m_pNotebook->SetSelection(2);
    else if(event.GetId() == ID_MENU_KEYBOARD)
    {
        m_pChkKeyboard->SetValue(!m_pChkKeyboard->IsChecked());
        m_pSizerKeyboard->Show(m_pChkKeyboard->GetValue());
        m_pSizerMain->Layout();
        m_pSpnKeyChannel->SetFocus();
    }
    else if(event.GetId() == ID_MENU_MULTICHANNEL)
        m_pNotebook->SetSelection(3);
    else if(event.GetId() == ID_MENU_MISC)
        m_pNotebook->SetSelection(4);
}

void VZEditorFrame::OnMasterVolume(wxScrollEvent& event)
{
    if(CheckHostError())
        return;
    wxMidiShortMessage msg(0xB0 | (m_pSpnKeyChannel->GetValue() - 1), 0x07, event.GetInt());
    m_pMidiOut->Write(&msg);
}

void VZEditorFrame::OnMasterTune(wxScrollEvent& event)
{
    if(CheckHostError())
        return;
    wxByte cChan = 0x70 | (m_pSpnKeyChannel->GetValue() - 1);
    wxByte cData = abs(m_pSliderMasterTune->GetValue());
    wxByte cDu =  cData >> 4;
    if(m_pSliderMasterTune->GetValue() < 0)
        cDu |= 0x08;
    wxByte cDl = cData & 0x0F;
    wxByte acMsg[] = {0xF0, 0x44, 0x03, 0x00, cChan, 0x40, 0x00, cDu, cDl, 0xF7};
    wxMidiSysExMessage msg(acMsg);
    m_pMidiOut->Write(&msg);
}

void VZEditorFrame::OnTranspose(wxScrollEvent& event)
{
    if(CheckHostError())
        return;
    wxByte cChan = 0x70 | (m_pSpnKeyChannel->GetValue() - 1);
    wxByte cData = abs(m_pSliderTranspose->GetValue());
    wxByte cDu =  cData >> 4;
    if(m_pSliderTranspose->GetValue() < 0)
        cDu |= 0x08;
    wxByte cDl = cData & 0x0F;
    wxByte acMsg[] = {0xF0, 0x44, 0x03, 0x00, cChan, 0x40, 0x01, cDu, cDl, 0xF7};
    wxMidiSysExMessage msg(acMsg);
    m_pMidiOut->Write(&msg);
}

void VZEditorFrame::OnCzBendRange(wxScrollEvent& event)
{
    if(CheckHostError())
        return;
    wxByte cChan = 0x70 | (m_pSpnKeyChannel->GetValue() - 1);
    wxByte cData = m_pSliderCZBendRange->GetValue();
    wxByte acMsg[] = {0xF0, 0x44, 0x00, 0x00, cChan, 0x40, cData, 0xF7};
    wxMidiSysExMessage msg(acMsg);
    m_pMidiOut->Write(&msg);
}

void VZEditorFrame::OnMode(wxCommandEvent& event)
{
    if(CheckHostError())
        return;
    wxByte cChan = 0x70 | (m_pSpnKeyChannel->GetValue() - 1);
    wxByte cData = m_pChoiceMode->GetSelection();
    wxByte acMsg[] = {0xF0, 0x44, 0x03, 0x00, cChan, 0x50, cData, 0xF7};
    wxMidiSysExMessage msg(acMsg);
    m_pMidiOut->Write(&msg);
}

void VZEditorFrame::OnCardBank(wxCommandEvent& event)
{
    if(CheckHostError())
        return;
    wxByte cChan = 0x70 | (m_pSpnKeyChannel->GetValue() - 1);
    wxByte cData = m_pRadioCardbank->GetSelection();
    wxByte acMsg[] = {0xF0, 0x44, 0x03, 0x00, cChan, 0x51, cData, 0xF7};
    wxMidiSysExMessage msg(acMsg);
    m_pMidiOut->Write(&msg);
}

void VZEditorFrame::OnModuleEvent(wxCommandEvent& event)
{
    AutoSend();
}

bool VZEditorFrame::CheckHostError()
{
    // The idea was to capture errors like removal of MIDI port but does not seem to work so should probably remove
    if(!m_pMidiOut)
        return true;
    if(m_pMidiOut->HasHostError() == 0)
        return false;
    //!@todo Be less brutal with output port host errors
    CloseOutput();
    UpdateMidiPorts();
    //!@todo Check selection of MIDI ports after refreshing
    return true;
}

void VZEditorFrame::OnSaveAs(wxCommandEvent& event)
{
    unsigned int nType = 0;
    switch(m_pNotebook->GetSelection())
    {
    case 0:
        nType = VZ_TYPE_LIBRARY;
        break;
    case 1:
        nType = VZ_TYPE_TONE;
        break;
    case 2:
        nType = VZ_TYPE_OPERATION;
        break;
    }
    Save(nType);
}

void VZEditorFrame::OnGridConfigDClick(wxGridEvent& event)
{
    int nRow = event.GetRow();
    int nCol = event.GetCol();
    if(nRow < 8)
    {
        int nIndex = nRow + nCol * 8;
        if(m_pvzLib->GetToneName(nIndex).IsEmpty())
            return;
        LoadFile(m_pvzLib->GetToneFilename(nIndex));
    }
    else
    {
        int nIndex = nRow -8 + nCol * 8;
        if(m_pvzLib->GetOperationName(nIndex).IsEmpty())
            return;
        LoadFile(m_pvzLib->GetOperationFilename(nIndex));
    }
}

bool VZEditorFrame::SetConfigVoice(unsigned int nIndex, wxString sFilename)
{
    if(nIndex > 63)
        return false;
    wxFile file(sFilename, wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox("Failed to open file", "Error", wxICON_ERROR);
        return false;
    }
    wxByte acSysex[file.Length()];
    if(file.Length() < VZ_HEADER_SIZE || file.Length() != file.Read(acSysex, file.Length()))
    {
        wxMessageBox("Failed to read file", "Error", wxICON_ERROR);
        file.Close();
        return false;
    }
    file.Close();
    if(acSysex[VZ_HEADER_TYPE] != VZ_TYPE_TONE)
    {
        wxMessageBox("Not a VZ Tone data file");
        return false;
    }
    VZVoice voiceTemp;
    if(voiceTemp.SetSysEx(acSysex))
    {
        wxMessageBox("Failed to load file - corrupt tone data", "Error", wxICON_ERROR);
        return false;
    }
    m_pvzLib->SetToneName(nIndex, voiceTemp.GetName());
    m_pvzLib->SetToneFilename(nIndex, sFilename);
    m_pGridConfig->SetCellValue(nIndex % 8, nIndex / 8, voiceTemp.GetName());
    m_pBtnLibToolSave->Enable(m_pvzLib->IsDirty());
    return true;
}

bool VZEditorFrame::SetConfigOperation(unsigned int nIndex, wxString sFilename)
{
    if(nIndex > 63)
        return false;
    wxFile file(sFilename, wxFile::read);
    if(!file.IsOpened())
    {
        wxMessageBox("Failed to open file", "Error", wxICON_ERROR);
        return false;
    }
    wxByte acSysex[file.Length()];
    if(file.Length() < VZ_HEADER_SIZE || file.Length() != file.Read(acSysex, file.Length()))
    {
        wxMessageBox("Failed to read file", "Error", wxICON_ERROR);
        file.Close();
        return false;
    }
    file.Close();
    if(acSysex[VZ_HEADER_TYPE] != VZ_TYPE_OPERATION)
    {
        wxMessageBox("Not a VZ Operation data file");
        return false;
    }
    VZOperation opTemp;
    if(opTemp.SetSysEx(acSysex))
    {
        wxMessageBox("Failed to load file - corrupt operation data", "Error", wxICON_ERROR);
        return false;
    }
    m_pvzLib->SetOperationName(nIndex, opTemp.GetName());
    m_pvzLib->SetOperationFilename(nIndex, sFilename);
    m_pGridConfig->SetCellValue(nIndex % 8 + 8, nIndex / 8, opTemp.GetName());
    m_pBtnLibToolSave->Enable(m_pvzLib->IsDirty());
    return true;
}

void VZEditorFrame::OnGridStartDrag(wxGridEvent& event)
{
    m_nDragSource = event.GetRow() + event.GetCol() * 8;
}

void VZEditorFrame::LoadLibrary()
{
    wxDir dir;
    wxArrayString asFiles;
    dir.GetAllFiles("library", &asFiles, "*.vzt");
    dir.GetAllFiles("library", &asFiles, "*.vzo");
    for(size_t nIndex = 0; nIndex < asFiles.GetCount(); ++nIndex)
        m_pLstLibrary->Append(asFiles[nIndex]);
}

void VZEditorFrame::OnLibDClick(wxCommandEvent& event)
{
    LoadFile(event.GetString());
}

void VZEditorFrame::OnLstLibrary(wxCommandEvent& event)
{
}

void VZEditorFrame::onLstLibLeftDown(wxMouseEvent& event)
{
    int nIndex = m_pLstLibrary->HitTest(event.GetPosition());
    if(nIndex == wxNOT_FOUND)
        return;
    wxFileDataObject myData;
    myData.AddFile(m_pLstLibrary->GetString(nIndex));
    wxDropSource dragSource(this);
    dragSource.SetData(myData);
    dragSource.DoDragDrop(true);
}

void VZEditorFrame::OnGridConfigKeyUp(wxKeyEvent& event)
{
    if(event.GetKeyCode() == WXK_RETURN)
    {
        int nRow = m_pGridConfig->GetGridCursorRow();
        int nCol = m_pGridConfig->GetGridCursorCol();
        if(nRow == wxNOT_FOUND || nCol == wxNOT_FOUND)
            return;
        if(nRow < 8)
        {
            int nIndex = nRow + nCol * 8;
            if(m_pvzLib->GetToneName(nIndex).IsEmpty())
                return;
            LoadFile(m_pvzLib->GetToneFilename(nIndex));
        }
        else
        {
            int nIndex = nRow -8 + nCol * 8;
            if(m_pvzLib->GetOperationName(nIndex).IsEmpty())
                return;
            LoadFile(m_pvzLib->GetOperationFilename(nIndex));
        }
    }
}

void VZEditorFrame::OnGridConfigKeyDown(wxKeyEvent& event)
{
    if(event.GetKeyCode() == WXK_RETURN)
        return;
    event.Skip();
}
