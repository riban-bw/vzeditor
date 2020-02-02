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
#include <list>

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
const long VZEditorFrame::ID_BUTTONADDTOLIB = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLADD = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLDELETE = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTON1 = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLSAVEAS = wxNewId();
const long VZEditorFrame::ID_BITMAPBUTTONLIBTOOLOPRN = wxNewId();
const long VZEditorFrame::ID_LSTLIB = wxNewId();
const long VZEditorFrame::ID_STATICTEXT1 = wxNewId();
const long VZEditorFrame::ID_STATICTEXTLIBENTRYNAME = wxNewId();
const long VZEditorFrame::ID_STATICTEXT2 = wxNewId();
const long VZEditorFrame::ID_TEXTCTRL2 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT16 = wxNewId();
const long VZEditorFrame::ID_COMBOBOX1 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT17 = wxNewId();
const long VZEditorFrame::ID_STATICTEXT18 = wxNewId();
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
const long VZEditorFrame::ID_NOTEBOOK = wxNewId();
const long VZEditorFrame::ID_STATICTEXT14 = wxNewId();
const long VZEditorFrame::ID_SPIN_KEYCHAN = wxNewId();
const long VZEditorFrame::ID_STATICTEXT15 = wxNewId();
const long VZEditorFrame::ID_SPINCTRL1 = wxNewId();
const long VZEditorFrame::ID_KBD = wxNewId();
const long VZEditorFrame::idMenuOpen = wxNewId();
const long VZEditorFrame::idMenuSave = wxNewId();
const long VZEditorFrame::idMenuQuit = wxNewId();
const long VZEditorFrame::idMenuAbout = wxNewId();
const long VZEditorFrame::ID_STATUSBAR1 = wxNewId();
const long VZEditorFrame::ID_TIMER1S = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZEditorFrame,wxFrame)
    //(*EventTable(VZEditorFrame)
    //*)
    EVT_COMMAND(ID_KBD, KEYBOARD_NOTE_ON_EVENT, VZEditorFrame::OnKeyboardNoteOn)
    EVT_COMMAND(ID_KBD, KEYBOARD_NOTE_OFF_EVENT, VZEditorFrame::OnKeyboardNoteOff)
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
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer9;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer6;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;

    Create(parent, wxID_ANY, _("riban Casio VZ-x Voice Editor and Library"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(-1,-1));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(icon_xpm));
    	SetIcon(FrameIcon);
    }
    m_pSizerMain = new wxBoxSizer(wxVERTICAL);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    m_pLblMidiInputPort = new wxStaticText(this, ID_STATICTEXTMIDIINPUT, _("MIDI Input"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTMIDIINPUT"));
    BoxSizer8->Add(m_pLblMidiInputPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbInPort = new wxChoice(this, ID_CMBINPORT, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBINPORT"));
    m_pCmbInPort->SetToolTip(_("Select MIDI input port"));
    BoxSizer8->Add(m_pCmbInPort, 0, wxALL, 5);
    m_pLblMidiOutputPort = new wxStaticText(this, ID_STATICTEXTMIDIOUTPUT, _("MIDI Output"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTMIDIOUTPUT"));
    BoxSizer8->Add(m_pLblMidiOutputPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbOutPort = new wxChoice(this, ID_CMBOUTPORT, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBOUTPORT"));
    m_pCmbOutPort->SetToolTip(_("Select MIDI output port"));
    BoxSizer8->Add(m_pCmbOutPort, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkKeyboard = new wxCheckBox(this, ID_CHECKBOXKEYBOARD, _("Keyboard"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOXKEYBOARD"));
    m_pChkKeyboard->SetValue(false);
    BoxSizer8->Add(m_pChkKeyboard, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkAutoUpdate = new wxCheckBox(this, ID_CHKAUTOUPDATE, _("Auto Update"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKAUTOUPDATE"));
    m_pChkAutoUpdate->SetValue(false);
    m_pChkAutoUpdate->SetToolTip(_("Enable automatic, immediate send of changes"));
    BoxSizer8->Add(m_pChkAutoUpdate, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSend = new wxButton(this, ID_BTNSEND, _("Send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSEND"));
    m_pBtnSend->SetToolTip(_("Send data to MIDI output"));
    BoxSizer8->Add(m_pBtnSend, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetVoice = new wxButton(this, ID_BTNGETVOICE, _("Get Voice"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETVOICE"));
    m_pBtnGetVoice->Disable();
    m_pBtnGetVoice->SetToolTip(_("Load voice data recieved from MIDI input"));
    BoxSizer8->Add(m_pBtnGetVoice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnGetOperation = new wxButton(this, ID_BTNGETOPERATION, _("Get Operation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNGETOPERATION"));
    m_pBtnGetOperation->Disable();
    m_pBtnGetOperation->SetToolTip(_("Load operational data recieved from MIDI input"));
    BoxSizer8->Add(m_pBtnGetOperation, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pBtnSaveDump = new wxButton(this, ID_BTNSAVEDUMP, _("New Library"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNSAVEDUMP"));
    BoxSizer8->Add(m_pBtnSaveDump, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_bBtnAddToLib = new wxButton(this, ID_BUTTONADDTOLIB, _("Add to library"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONADDTOLIB"));
    BoxSizer8->Add(m_bBtnAddToLib, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSizerMain->Add(BoxSizer8, 0, wxALL|wxEXPAND, 5);
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
    m_pBtnLibToolSave = new wxBitmapButton(m_pPnlLibrary, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FILE_SAVE")),wxART_TOOLBAR), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
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
    BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
    m_pLstLib = new SortableList(m_pPnlLibrary,ID_LSTLIB);
    BoxSizer20->Add(m_pLstLib, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(m_pPnlLibrary, ID_STATICTEXT1, _("Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pLblLibEntryName = new wxStaticText(m_pPnlLibrary, ID_STATICTEXTLIBENTRYNAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXTLIBENTRYNAME"));
    FlexGridSizer1->Add(m_pLblLibEntryName, 1, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(m_pPnlLibrary, ID_STATICTEXT2, _("Description"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pTxtLibEntryDescription = new wxTextCtrl(m_pPnlLibrary, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(m_pTxtLibEntryDescription, 1, wxALL|wxEXPAND, 5);
    StaticText15 = new wxStaticText(m_pPnlLibrary, ID_STATICTEXT16, _("Group"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer1->Add(StaticText15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pCmbLibEntryGroup = new wxComboBox(m_pPnlLibrary, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    FlexGridSizer1->Add(m_pCmbLibEntryGroup, 1, wxALL|wxEXPAND, 5);
    StaticText16 = new wxStaticText(m_pPnlLibrary, ID_STATICTEXT17, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer1->Add(StaticText16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pLblLibEntryType = new wxStaticText(m_pPnlLibrary, ID_STATICTEXT18, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer1->Add(m_pLblLibEntryType, 1, wxALL|wxEXPAND, 5);
    BoxSizer20->Add(FlexGridSizer1, 0, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer20, 1, wxALL|wxEXPAND, 5);
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
    StaticText3 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT3, _("Voice Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
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
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, m_pScrollwindowGlobalParameters, _("DCO"));
    FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer6->AddGrowableCol(1);
    StaticText10 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT10, _("Octave"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer6->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderOctave = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDEROCTAVE, 0, -2, 2, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDEROCTAVE"));
    m_pSliderOctave->SetToolTip(_("Set DCO octave"));
    FlexGridSizer6->Add(m_pSliderOctave, 1, wxALL|wxEXPAND, 5);
    StaticText11 = new wxStaticText(m_pScrollwindowGlobalParameters, ID_STATICTEXT11, _("Velocity\nSensitivity"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT11"));
    FlexGridSizer6->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVelSens = new wxSlider(m_pScrollwindowGlobalParameters, ID_SLIDERVELSENS, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL, wxDefaultValidator, _T("ID_SLIDERVELSENS"));
    m_pSliderVelSens->SetToolTip(_("Set DCO velocity sensitivity"));
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
    m_pCmbVelCurve->SetToolTip(_("Select DCO curve"));
    FlexGridSizer6->Add(m_pCmbVelCurve, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    m_pNotebook->AddPage(m_pPnlLibrary, _("Voice Library"), false);
    m_pNotebook->AddPage(m_pPnlVoice, _("Voice Editor"), false);
    m_pNotebook->AddPage(m_pPnlOperation, _("Operation Editor"), false);
    m_pSizerMain->Add(m_pNotebook, 1, wxALL|wxEXPAND, 5);
    m_pSizerKeyboard = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer21 = new wxBoxSizer(wxVERTICAL);
    StaticText13 = new wxStaticText(this, ID_STATICTEXT14, _("MIDI Channel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    BoxSizer21->Add(StaticText13, 0, wxALL|wxEXPAND, 5);
    m_pSpnKeyChannel = new wxSpinCtrl(this, ID_SPIN_KEYCHAN, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 16, 1, _T("ID_SPIN_KEYCHAN"));
    m_pSpnKeyChannel->SetValue(_T("1"));
    BoxSizer21->Add(m_pSpnKeyChannel, 0, wxALL, 5);
    StaticText14 = new wxStaticText(this, ID_STATICTEXT15, _("Program"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    BoxSizer21->Add(StaticText14, 0, wxALL|wxEXPAND, 5);
    m_pSpnProgram = new wxSpinCtrl(this, ID_SPINCTRL1, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 128, 1, _T("ID_SPINCTRL1"));
    m_pSpnProgram->SetValue(_T("1"));
    BoxSizer21->Add(m_pSpnProgram, 0, wxALL, 5);
    m_pSizerKeyboard->Add(BoxSizer21, 0, wxALL|wxEXPAND, 5);
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
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
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
    Connect(ID_BUTTONADDTOLIB,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnAddToLib);
    Connect(ID_BITMAPBUTTONLIBTOOLADD,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnLibToolAdd);
    Connect(ID_BITMAPBUTTONLIBTOOLDELETE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnLibToolDelete);
    Connect(ID_BITMAPBUTTONLIBTOOLSAVEAS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnSaveFile);
    Connect(ID_BITMAPBUTTONLIBTOOLOPRN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VZEditorFrame::OnOpenFile);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnTxtLibEntryDescription);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnCmbLibEntryGroup);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnCmbLibEntryGroup);
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
    Connect(ID_SPIN_KEYCHAN,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnKeyChan);
    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&VZEditorFrame::OnKeyProgram);
    Connect(idMenuOpen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnOpenFile);
    Connect(idMenuSave,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnSaveFile);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnAbout);
    Connect(ID_TIMER1S,wxEVT_TIMER,(wxObjectEventFunction)&VZEditorFrame::OnTimer1s);
    //*)
    m_pScrollWinVoiceEditor->SetScrollRate(10,10);
    m_pScrollwindowGlobalParameters->SetScrollRate(0, 10);
    Connect(ID_LSTLIB,wxEVT_COMMAND_LIST_COL_CLICK,(wxObjectEventFunction)&VZEditorFrame::OnLibSort);
    Connect(ID_LSTLIB,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&VZEditorFrame::OnLibEntrySelected);
    Connect(ID_LSTLIB,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&VZEditorFrame::OnLibActivate);
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
    if(m_pCmbInPort->GetCount())
    {
        if((int)m_pCmbInPort->GetCount() - 1 < nX)
            nX = m_pCmbInPort->GetCount() - 1;
        wxCommandEvent event;
        m_pCmbInPort->Select(nX);
        event.SetClientData(m_pCmbInPort->GetClientData(0));
        OnInPortSelect(event);
    }
    configPersist.Read("persist/midi_out", &nX, 0);
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
    configPersist.Read("persist/auto_update", &bAuto, false);
    m_pChkAutoUpdate->SetValue(bAuto);
    m_pvzLib = new VZLibrary();
    m_pLstLib->SetData(m_pvzLib);
    PopulateLibraryGroups();

    m_pVoice = new VZVoice();
    m_pVoiceMidi = new VZVoice();
    m_pOperation = new VZOperation();
    m_pOperationMidi = new VZOperation();

    m_pLine1->SetVoice(m_pVoice);
    m_pLine2->SetVoice(m_pVoice);
    m_pLine3->SetVoice(m_pVoice);
    m_pLine4->SetVoice(m_pVoice);
}

VZEditorFrame::~VZEditorFrame()
{
}

void VZEditorFrame::OnClose(wxCloseEvent& event)
{
    wxConfig configPersist(wxTheApp->GetAppName(), "riban",wxEmptyString, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
    configPersist.Write("persist/midi_out", m_pCmbOutPort->GetSelection());
    configPersist.Write("persist/auto_update", m_pChkAutoUpdate->IsChecked());
    configPersist.Write("persist/midi_in", m_pCmbInPort->GetSelection());
    configPersist.Write("persist/maximised", IsMaximized());
    configPersist.Write("persist/keyboard", m_pChkKeyboard->IsChecked());
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
    wxString sMessage = wxString::Format("VZEditor %d.%d.%d\n\n", AutoVersion::MAJOR, AutoVersion::MINOR, AutoVersion::BUILD);
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

void VZEditorFrame::Save(unsigned int nType)
{
    wxString sType;
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
    wxFile file(dlg.GetPath(), wxFile::write);
    if(!file.IsOpened())
    {
        wxMessageBox("Failed to save file", "Error", wxICON_ERROR);
        return;
    }
    VZSysex* pSysex = NULL;
    switch(nType)
    {
    case VZ_TYPE_LIBRARY:
        //Library
        //!@todo Write library
        file.Close();
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
        pSysex->Validate(true);
        if(file.Write(pSysex->GetSysEx(), pSysex->GetSize()) != pSysex->GetSize())
            wxMessageBox("Error - corrupt file", "Error", wxICON_ERROR);
    }
    file.Close();
}

bool VZEditorFrame::LoadFile(wxString sFilename)
{
    if(!wxFileExists(sFilename))
    {
        wxMessageBox("File does not exist", "Error", wxICON_ERROR);
        return false;
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
        wxMessageBox("This does not appear to be a valid VZ file", "Error", wxICON_ERROR);
        return false;
    }
    return true;
}

void VZEditorFrame::Send()
{
    if(!m_pMidiOut)
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
    AutoSend();
}

void VZEditorFrame::OnRadioTremeloMultiSelect(wxCommandEvent& event)
{
    m_pVoice->EnableTremeloMulti(event.GetInt() == 1);
    AutoSend();
}

void VZEditorFrame::OnCmbVelCurveSelect(wxCommandEvent& event)
{
    m_pVoice->SetPitchVelCurve(event.GetSelection());
    AutoSend();
}

void VZEditorFrame::OnRadioTremeloWaveformSelect(wxCommandEvent& event)
{
    m_pVoice->SetTremeloWaveform(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnRadioVibratoMultiSelect(wxCommandEvent& event)
{
    m_pVoice->EnableVibratoMulti(event.GetInt() == 1);
    AutoSend();
}

void VZEditorFrame::OnRadioVibratoWaveformSelect(wxCommandEvent& event)
{
    m_pVoice->SetVibratoWaveform(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnOpenFile(wxCommandEvent& event)
{
    wxFileDialog dlg(this, wxEmptyString, wxEmptyString, wxEmptyString,"Library files (*.xml)|*.xml|VZ tone files (*vzt)|*.vzt|VZ operation files (*vzo)|*.vzo|All files (*.*)|*.*", wxFD_OPEN);
    dlg.SetFilterIndex(m_pNotebook->GetSelection());
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    wxFileName fnFilename(dlg.GetPath());
    if(fnFilename.GetExt().Lower().IsSameAs("xml"))
    {
        if(m_pvzLib->IsDirty())
            ; //!@todo Handle dirty library
        m_pvzLib->Load(dlg.GetPath());
        m_pLstLib->SetData(m_pvzLib);
        PopulateLibraryGroups();
        return;
    }
    LoadFile(dlg.GetPath());
}

void VZEditorFrame::OnLibSort(wxListEvent& event)
{
    m_pLstLib->Sort(event.GetColumn());
}

void VZEditorFrame::OnLibActivate(wxListEvent& event)
{
    wxString sFilename = m_pLstLib->GetItemFilename(event.GetIndex());
    wxString sType = m_pLstLib->GetItemType(event.GetIndex());
    if(LoadFile("library/" + sFilename)) //!@todo configure path to library
        m_pNotebook->SetSelection(1);
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
        Save(VZ_TYPE_LIBRARY);
        break;
    case 1:
        Save(VZ_TYPE_TONE);
        break;
    case 2:
        Save(VZ_TYPE_OPERATION);
        break;
    }
}

void VZEditorFrame::UpdateMidiPorts()
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

void VZEditorFrame::AutoSend()
{
    if(m_pChkAutoUpdate->IsChecked())
        Send();
}

void VZEditorFrame::OnLevelChanged(wxScrollEvent& event)
{
    m_pVoice->SetLevel(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnOctaveChanged(wxScrollEvent& event)
{
    m_pVoice->SetOctave(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnDcoVelSensChange(wxScrollEvent& event)
{
    m_pVoice->SetPitchVelSens(event.GetInt());
    AutoSend();
}


void VZEditorFrame::OnTremeloDepthChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloDepth(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnTremeloRateChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloRate(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnTremeloDelayChanged(wxScrollEvent& event)
{
    m_pVoice->SetTremeloDelay(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnVibratoDepthChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoDepth(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnVibratoRateChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoRate(event.GetInt());
    AutoSend();
}

void VZEditorFrame::OnVibratoDelayChanged(wxScrollEvent& event)
{
    m_pVoice->SetVibratoDelay(event.GetInt());
    AutoSend();
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
    KeyboardEventData* pData = (KeyboardEventData*)event.GetClientData();
    if(m_pMidiOut && pData)
    {
        m_pMidiOut->NoteOn(pData->channel, pData->note, pData->velocity);
        m_pStatusbar->SetStatusText(wxString::Format("Note on: channel %d, note %d, velocity %d", pData->channel, pData->note, pData->velocity));
    }
}

void VZEditorFrame::OnKeyboardNoteOff(wxCommandEvent& event)
{
    m_pStatusbar->SetStatusText(wxString::Format("Note off: %d", event.GetInt()));
    KeyboardEventData* pData = (KeyboardEventData*)event.GetClientData();
    if(m_pMidiOut && pData)
        m_pMidiOut->NoteOff(pData->channel, pData->note, pData->velocity);
}

void VZEditorFrame::OnKeyChan(wxSpinEvent& event)
{
    m_pKeyboard->SetSendChannel(event.GetValue() - 1);
}

void VZEditorFrame::OnKeyProgram(wxSpinEvent& event)
{
    if(m_pMidiOut)
        m_pMidiOut->ProgramChange(m_pKeyboard->GetSendChannel(), event.GetValue() - 1);
}

void VZEditorFrame::Onm_pChkKeyboardClick(wxCommandEvent& event)
{
}

void VZEditorFrame::Onm_pCmbOutPortSelect(wxCommandEvent& event)
{
}

void VZEditorFrame::OnAddToLib(wxCommandEvent& event)
{
    switch(m_pNotebook->GetSelection())
    {
    case 0:
        //Library
    {
        wxString sType;
        wxFileDialog dlg(this, "Select file to add to library", wxEmptyString, wxEmptyString, wxEmptyString, wxFD_OPEN);
        dlg.SetWildcard("VZ tone files (*.vzt)|*.vzt|All files (*.*)|*.*");
        if(dlg.ShowModal() == wxID_CANCEL)
            return;
        //!@todo Add file to library
        /*  Open file
            Load into temporary sysex object
            Close file
            Validate sysex
            Extract name
            Add name and filename to library
            Offer description editor
            Add description to library
            Delete temporary sysex
        */
    }
    break;
    case 1:
        //Voice
        Save(VZ_TYPE_TONE);
        break;
    case 2:
        Save(VZ_TYPE_OPERATION);
        break;
        //Operation data
    }
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
    dlg.SetWildcard("VZ tone files (*.vzt)|*.vzt|VZ operation files (*.vzo)|*.vzo|All files (*.*)|*.*");
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
    m_pvzLib->AddEntry(sName, dlg.GetPath(), sName, "Default", sType); //!@todo Should we add items to the list rather than the underlying data obect?
    m_pLstLib->SetData(m_pvzLib);
}

void VZEditorFrame::OnLibEntrySelected(wxListEvent& event)
{
    m_bAllowUpdate = false;
    m_pLblLibEntryName->SetLabel(m_pLstLib->GetItemName(event.GetIndex()));
    m_pTxtLibEntryDescription->SetValue(m_pLstLib->GetItemDescription(event.GetIndex()));
    m_pCmbLibEntryGroup->SetValue(m_pLstLib->GetItemGroup(event.GetIndex()));
    m_pLblLibEntryType->SetLabel(m_pLstLib->GetItemType(event.GetIndex()));
    m_bAllowUpdate = true;
}

void VZEditorFrame::PopulateLibraryGroups()
{
    list<wxString> listGroups;
    for(int nIndex = 0; nIndex < m_pLstLib->GetItemCount(); ++nIndex)
        listGroups.push_back(m_pLstLib->GetItemGroup(nIndex));
    listGroups.unique();
    for(auto it = listGroups.begin(); it != listGroups.end(); ++it)
        m_pCmbLibEntryGroup->Append(*it);
}

void VZEditorFrame::OnTxtLibEntryDescription(wxCommandEvent& event)
{
    if(m_bAllowUpdate)
        m_pLstLib->SetItemDescription(event.GetString());
}

void VZEditorFrame::OnCmbLibEntryGroup(wxCommandEvent& event)
{
    if(m_bAllowUpdate)
        m_pLstLib->SetItemGroup(event.GetString());
    m_pBtnLibToolSave->Enable(m_pvzLib->IsDirty());
}


void VZEditorFrame::OnLibToolDelete(wxCommandEvent& event)
{
    m_pLstLib->RemoveItems();
    m_pBtnLibToolSave->Enable(m_pvzLib->IsDirty());
}
