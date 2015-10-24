#include "vzvoicemodule.h"
#include "../media/keyboard.xpm"

//(*InternalHeaders(vzVoiceModule)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(vzVoiceModule)
const long vzVoiceModule::ID_STATICTEXT1 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT12 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT14 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT15 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT13 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT31 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT16 = wxNewId();
const long vzVoiceModule::ID_CHOICE3 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT2 = wxNewId();
const long vzVoiceModule::ID_CHECKBOX1 = wxNewId();
const long vzVoiceModule::ID_SLIDER8 = wxNewId();
const long vzVoiceModule::ID_SLIDER25 = wxNewId();
const long vzVoiceModule::ID_ENVAMP = wxNewId();
const long vzVoiceModule::ID_SLIDER11 = wxNewId();
const long vzVoiceModule::ID_SLIDER10 = wxNewId();
const long vzVoiceModule::ID_CHOICE4 = wxNewId();
const long vzVoiceModule::ID_SLIDER9 = wxNewId();
const long vzVoiceModule::ID_STATICBITMAP1 = wxNewId();
const long vzVoiceModule::ID_ENVKF = wxNewId();
//*)

wxDEFINE_EVENT(wxEVT_VZ_MODULE, wxCommandEvent);

BEGIN_EVENT_TABLE(vzVoiceModule,wxPanel)
	//(*EventTable(vzVoiceModule)
	//*)
END_EVENT_TABLE()

vzVoiceModule::vzVoiceModule(wxWindow* parent, unsigned int nId, long lStyle) :
    m_nIndex(nId),
    m_pVoiceData(NULL)
{
	//(*Initialize(vzVoiceModule)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer10;
	wxBoxSizer* BoxSizer1;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer6 = new wxFlexGridSizer(2, 0, 0, 0);
	FlexGridSizer6->AddGrowableCol(2);
	FlexGridSizer6->AddGrowableCol(6);
	FlexGridSizer6->AddGrowableRow(1);
	m_pLblWaveform = new wxStaticText(this, ID_STATICTEXT1, _("Waveform"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer6->Add(m_pLblWaveform, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblDetune = new wxStaticText(this, ID_STATICTEXT12, _("Detune"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	FlexGridSizer6->Add(m_pLblDetune, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblAmpEnv = new wxStaticText(this, ID_STATICTEXT14, _("Amplitude Envelope"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	FlexGridSizer6->Add(m_pLblAmpEnv, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblDepth = new wxStaticText(this, ID_STATICTEXT15, _("Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	FlexGridSizer6->Add(m_pLblDepth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblAmpSens = new wxStaticText(this, ID_STATICTEXT13, _("Amp Sensitivity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	FlexGridSizer6->Add(m_pLblAmpSens, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblVelocity = new wxStaticText(this, ID_STATICTEXT31, _("Velocity"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
	FlexGridSizer6->Add(m_pLblVelocity, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblKeyFollow = new wxStaticText(this, ID_STATICTEXT16, _("Key Follow"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	FlexGridSizer6->Add(m_pLblKeyFollow, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10 = new wxFlexGridSizer(0, 1, 0, 0);
	m_pCmbWaveform = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	m_pCmbWaveform->SetSelection( m_pCmbWaveform->Append(_("Sine")) );
	m_pCmbWaveform->Append(_("Saw 1"));
	m_pCmbWaveform->Append(_("Saw 2"));
	m_pCmbWaveform->Append(_("Saw 3"));
	m_pCmbWaveform->Append(_("Saw 4"));
	m_pCmbWaveform->Append(_("Saw 5"));
	m_pCmbWaveform->Append(_("Noise 1"));
	m_pCmbWaveform->Append(_("Noise 2"));
	FlexGridSizer10->Add(m_pCmbWaveform, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pLblTitle = new wxStaticText(this, ID_STATICTEXT2, _("Mx"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont m_pLblTitleFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	m_pLblTitle->SetFont(m_pLblTitleFont);
	FlexGridSizer10->Add(m_pLblTitle, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pChkEnable = new wxCheckBox(this, ID_CHECKBOX1, _("Enable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	m_pChkEnable->SetValue(true);
	FlexGridSizer10->Add(m_pChkEnable, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_pSliderDetune = new wxSlider(this, ID_SLIDER8, 0, -128, 127, wxDefaultPosition, wxSize(58,49), 0, wxDefaultValidator, _T("ID_SLIDER8"));
	BoxSizer1->Add(m_pSliderDetune, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderDetuneFine = new wxSlider(this, ID_SLIDER25, 32, 0, 63, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER25"));
	BoxSizer1->Add(m_pSliderDetuneFine, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(BoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pEnvEditorAmp = new EnvelopeEditor(this,ID_ENVAMP,wxDefaultPosition,wxSize(296,82),ENV_STYLE_DCA_ENV,_T("ID_ENVAMP"));
	FlexGridSizer6->Add(m_pEnvEditorAmp, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderEnvDepth = new wxSlider(this, ID_SLIDER11, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER11"));
	FlexGridSizer6->Add(m_pSliderEnvDepth, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderAmpSens = new wxSlider(this, ID_SLIDER10, 7, 0, 7, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER10"));
	FlexGridSizer6->Add(m_pSliderAmpSens, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer9->AddGrowableRow(1);
	m_pCmbCurve = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
	m_pCmbCurve->SetSelection( m_pCmbCurve->Append(_("Curve 1")) );
	m_pCmbCurve->Append(_("Curve 2"));
	m_pCmbCurve->Append(_("Curve 3"));
	m_pCmbCurve->Append(_("Curve 4"));
	m_pCmbCurve->Append(_("Curve 5"));
	m_pCmbCurve->Append(_("Curve 6"));
	m_pCmbCurve->Append(_("Curve 7"));
	m_pCmbCurve->Append(_("Curve 8"));
	FlexGridSizer9->Add(m_pCmbCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderVelSensitivity = new wxSlider(this, ID_SLIDER9, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER9"));
	FlexGridSizer9->Add(m_pSliderVelSensitivity, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer9, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	m_pBmpKeyboard = new wxStaticBitmap(this, ID_STATICBITMAP1, keyboard_xpm, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	FlexGridSizer1->Add(m_pBmpKeyboard, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pEnvEditorKeyFollow = new EnvelopeEditor(this,ID_ENVKF,wxDefaultPosition,wxSize(296,-1),ENV_STYLE_DCA_KF,_T("ID_ENVKF"));
	FlexGridSizer1->Add(m_pEnvEditorKeyFollow, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer6);
	FlexGridSizer6->Fit(this);
	FlexGridSizer6->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&vzVoiceModule::OnChkEnableClick);
	Connect(ID_SLIDER8,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderDetuneCmdScrollChanged);
	Connect(ID_SLIDER25,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderDetuneFineCmdScrollChanged);
	Connect(ID_SLIDER11,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderEnvDepthCmdScrollChanged);
	Connect(ID_SLIDER10,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderAmpSensCmdScrollChanged);
	Connect(ID_SLIDER9,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderVelSensitivityCmdScrollChanged);
	//*)
	Connect(ID_ENVAMP, wxEVT_ENVED, (wxObjectEventFunction)&vzVoiceModule::OnAmpEnv);
	Connect(ID_ENVKF, wxEVT_ENVED, (wxObjectEventFunction)&vzVoiceModule::OnKFEnv);
//	if(VZVOICE_STYLE_NOTITLE == lStyle)
//    {
//        m_pLblAmpEnv->Hide();
//        m_pLblAmpSens->Hide();
//        m_pLblDepth->Hide();
//        m_pLblDetune->Hide();
//        m_pLblKeyFollow->Hide();
//        m_pLblVelocity->Hide();
//        m_pLblWaveform->Hide();
//        m_pBmpKeyboard->Hide();
//    }
    m_pLblTitle->SetLabel(wxString::Format("M%d", nId + 1));
}

vzVoiceModule::~vzVoiceModule()
{
	//(*Destroy(vzVoiceModule)
	//*)
}

void vzVoiceModule::UpdateVoice()
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 1 + m_nIndex / 2;
    bool bLower = 0 == ((m_nIndex + 1) / nReg - 1);
    wxByte cValue = m_pVoiceData[nReg];
    if(bLower)
    {
        m_pCmbWaveform->SetSelection(cValue & 0x03);
        //!@todo signal routing
    }
    else
    {
        m_pCmbWaveform->SetSelection((cValue & 0x38) >> 3);
        //!@todo signal routing
    }
    m_pSliderDetuneFine->SetValue(m_pVoiceData[5 + 2 * m_nIndex]);
    m_pSliderDetune->SetValue((m_pVoiceData[6 + 2 * m_nIndex] & 0xFC) >> 2); //!@todo Course detune not working correctly
    //!@todo Pitch fix and detune range (x1, 1/16)

    m_pEnvEditorAmp->Clear();
    unsigned int nEnvSteps = (m_pVoiceData[165 + m_nIndex] & 0x70) >> 4;
    for(unsigned int nStep = 0; nStep <= nEnvSteps; ++nStep)
    {
        int nRate = m_pVoiceData[21 + m_nIndex + 18 * nStep] & 0x7F;
        bool bKeyVelocity = (0x80 == (m_pVoiceData[21 + m_nIndex + 18 * nStep] & 0x80));
        int nLevel = m_pVoiceData[30 + m_nIndex + 18 * nStep] & 0x7F;
        bool bSustain = (0x80 == (m_pVoiceData[30 + m_nIndex + 18 * nStep] & 0x80));
        m_pEnvEditorAmp->AddNodeRate(nRate, nLevel, bKeyVelocity, bSustain);
    }

    m_pSliderAmpSens->SetValue(m_pVoiceData[165 + m_nIndex] & 0x07);

    int nEnvDepth = m_pVoiceData[175 + m_nIndex] & 0x7F;
    m_pSliderEnvDepth->SetValue(0x7F - nEnvDepth);
    bool bEnable = (0x80 != (m_pVoiceData[175 + m_nIndex] & 0x80));
    m_pChkEnable->SetValue(bEnable); //!@todo call enable module
    m_pEnvEditorKeyFollow->Clear();
    for(unsigned int nStep = 0; nStep < 6; ++nStep)
    {
        int nKfKey = m_pVoiceData[184 + 12 * m_nIndex + 2 * nStep] & 0x7F;
        int nKfLevel = m_pVoiceData[185 + 12 * m_nIndex + 2 * nStep] & 0x7F;
        m_pEnvEditorKeyFollow->AddNode(nKfKey, nKfLevel, false, false);
    }
    int nVelSens = m_pVoiceData[304 + m_nIndex] & 0x1F;
    int nVelCurve = (m_pVoiceData[304 + m_nIndex] & 0xE0) >> 5; //!@todo Show velocity curves as graphics
    m_pSliderVelSensitivity->SetValue(nVelSens);
    m_pCmbCurve->SetSelection(nVelCurve);
}

void vzVoiceModule::OnChkEnableClick(wxCommandEvent& event)
{
    m_pCmbCurve->Enable(event.IsChecked());
    m_pCmbWaveform->Enable(event.IsChecked());
    m_pEnvEditorKeyFollow->Enable(event.IsChecked());
    m_pEnvEditorAmp->Enable(event.IsChecked());
    m_pSliderAmpSens->Enable(event.IsChecked());
    m_pSliderDetune->Enable(event.IsChecked());
    m_pSliderDetuneFine->Enable(event.IsChecked());
    m_pSliderEnvDepth->Enable(event.IsChecked());
    m_pSliderVelSensitivity->Enable(event.IsChecked());
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 175 + m_nIndex;
    wxByte cValue = m_pVoiceData[nReg] & 0x7F;
    cValue = cValue | ((event.IsChecked()?0:1) << 7);
    m_pVoiceData[nReg] = cValue;
    SendUpdate();
}

void vzVoiceModule::SendUpdate()
{
    wxCommandEvent event(wxEVT_VZ_MODULE, GetId());
    event.SetEventObject(this);
    ProcessWindowEvent(event);
}

void vzVoiceModule::OnCmbWaveformSelect(wxCommandEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 1 + m_nIndex / 2;
    unsigned int nShift = (m_nIndex + 1) / nReg - 1;
    wxByte cValue = m_pVoiceData[nReg];
    wxByte cMask = nShift?0xC7:0xF8;
    cValue = (cValue & cMask) | event.GetInt() << (nShift * 3);
    m_pVoiceData[nReg] = cValue;
    SendUpdate();
}

void vzVoiceModule::OnSliderDetuneCmdScrollChanged(wxScrollEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 6 + 2 * m_nIndex;
    m_pVoiceData[nReg] = event.GetInt();
    SendUpdate();
}

void vzVoiceModule::OnSliderDetuneFineCmdScrollChanged(wxScrollEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 5 + 2 * m_nIndex;
    m_pVoiceData[nReg] = event.GetInt();
    SendUpdate();
}

void vzVoiceModule::OnSliderEnvDepthCmdScrollChanged(wxScrollEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 175 + m_nIndex;
    m_pVoiceData[nReg] = (m_pVoiceData[nReg] | 0x80) & event.GetInt();
    SendUpdate();
}

void vzVoiceModule::OnSliderAmpSensCmdScrollChanged(wxScrollEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 165 + m_nIndex;
    m_pVoiceData[nReg] = (m_pVoiceData[nReg] | 0xF0) & event.GetInt();
    SendUpdate();
}

void vzVoiceModule::OnCmbCurveSelect(wxCommandEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 304 + m_nIndex;
    m_pVoiceData[nReg] = (m_pVoiceData[nReg] | 0x1F) & (event.GetInt() << 5);
    SendUpdate();
}

void vzVoiceModule::OnSliderVelSensitivityCmdScrollChanged(wxScrollEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 304 + m_nIndex;
    m_pVoiceData[nReg] = (m_pVoiceData[nReg] | 0xE0) & event.GetInt();
    SendUpdate();
}

void vzVoiceModule::OnAmpEnv(wxCommandEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    m_pVoiceData[165 + m_nIndex] = (m_pVoiceData[165 + m_nIndex] & 0x0F) | ((m_pEnvEditorAmp->GetNodeCount() - 1) << 4);
    m_pVoiceData[21 + event.GetInt() * 18 + m_nIndex] = m_pEnvEditorAmp->GetRate(event.GetInt()) | ((m_pEnvEditorAmp->IsVelocity(event.GetInt())?1:0) << 7);
//    wxLogDebug("vzVoiceModule::OnAmpEnv M%d, Node %d, Rate %d, Value %d", m_nIndex, event.GetInt(), m_pEnvEditorAmp->GetRate(event.GetInt()), m_pEnvEditorAmp->GetValue(event.GetInt()));
    m_pVoiceData[30 + event.GetInt() * 18 + m_nIndex] = m_pEnvEditorAmp->GetValue(event.GetInt()) | ((m_pEnvEditorAmp->IsSustain(event.GetInt())?1:0) << 7);
}

void vzVoiceModule::OnKFEnv(wxCommandEvent& event)
{
    if(!m_pVoiceData || m_nIndex > 7)
        return;
    unsigned int nReg = 184 + event.GetInt() + 6 * m_nIndex;
    m_pVoiceData[nReg] = m_pEnvEditorKeyFollow->GetPosition(event.GetInt());
    m_pVoiceData[nReg + 1] = m_pEnvEditorKeyFollow->GetValue(event.GetInt());
}
