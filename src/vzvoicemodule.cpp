#include "vzvoicemodule.h"
#include "../media/keyboard.xpm"

//(*InternalHeaders(vzVoiceModule)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(vzVoiceModule)
const long vzVoiceModule::ID_STATICTEXT2 = wxNewId();
const long vzVoiceModule::ID_CHKENABLE = wxNewId();
const long vzVoiceModule::ID_CHKEXTPHASE = wxNewId();
const long vzVoiceModule::ID_STATICTEXT1 = wxNewId();
const long vzVoiceModule::ID_CHOICE3 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT3 = wxNewId();
const long vzVoiceModule::ID_SLIDER8 = wxNewId();
const long vzVoiceModule::ID_STATICTEXT5 = wxNewId();
const long vzVoiceModule::ID_SLIDER1 = wxNewId();
const long vzVoiceModule::ID_CHECKBOX2 = wxNewId();
const long vzVoiceModule::ID_CHECKBOX3 = wxNewId();
const long vzVoiceModule::ID_ENVAMP = wxNewId();
const long vzVoiceModule::ID_STATICTEXT15 = wxNewId();
const long vzVoiceModule::ID_SLIDER11 = wxNewId();
const long vzVoiceModule::ID_CHECKBOX4 = wxNewId();
const long vzVoiceModule::ID_STATICBITMAP1 = wxNewId();
const long vzVoiceModule::ID_ENVKF = wxNewId();
const long vzVoiceModule::ID_CHOICE4 = wxNewId();
const long vzVoiceModule::ID_SLIDER9 = wxNewId();
const long vzVoiceModule::ID_SLIDER10 = wxNewId();
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
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer9;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer6;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer6 = new wxFlexGridSizer(1, 0, 0, 0);
	FlexGridSizer6->AddGrowableCol(2);
	FlexGridSizer6->AddGrowableCol(4);
	FlexGridSizer6->AddGrowableRow(0);
	BoxSizer2 = new wxBoxSizer(wxVERTICAL);
	m_pLblTitle = new wxStaticText(this, ID_STATICTEXT2, _("Mx"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont m_pLblTitleFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	m_pLblTitle->SetFont(m_pLblTitleFont);
	BoxSizer2->Add(m_pLblTitle, 1, wxALL, 5);
	m_pChkEnable = new wxCheckBox(this, ID_CHKENABLE, _("Enable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKENABLE"));
	m_pChkEnable->SetValue(true);
	m_pChkEnable->SetToolTip(_("Enable module"));
	BoxSizer2->Add(m_pChkEnable, 1, wxALL|wxEXPAND, 5);
	m_pChkExtPhase = new wxCheckBox(this, ID_CHKEXTPHASE, _("Ext Phase"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKEXTPHASE"));
	m_pChkExtPhase->SetValue(false);
	m_pChkExtPhase->Disable();
	m_pChkExtPhase->SetToolTip(_("External phase"));
	BoxSizer2->Add(m_pChkExtPhase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DCO"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
	m_pLblWaveform = new wxStaticText(this, ID_STATICTEXT1, _("Waveform"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer4->Add(m_pLblWaveform, 1, wxALL|wxEXPAND, 5);
	m_pCmbWaveform = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
	m_pCmbWaveform->SetSelection( m_pCmbWaveform->Append(_("Sine")) );
	m_pCmbWaveform->Append(_("Saw 1"));
	m_pCmbWaveform->Append(_("Saw 2"));
	m_pCmbWaveform->Append(_("Saw 3"));
	m_pCmbWaveform->Append(_("Saw 4"));
	m_pCmbWaveform->Append(_("Saw 5"));
	m_pCmbWaveform->Append(_("Noise 1"));
	m_pCmbWaveform->Append(_("Noise 2"));
	m_pCmbWaveform->SetToolTip(_("DCO Waveform"));
	FlexGridSizer4->Add(m_pCmbWaveform, 1, wxALL|wxEXPAND, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT3, _("Detune Course"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer4->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
	m_pSliderDetuneOctave = new wxSlider(this, ID_SLIDER8, 0, -128, 127, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER8"));
	m_pSliderDetuneOctave->SetToolTip(_("Detune DCO in semitone steps"));
	FlexGridSizer4->Add(m_pSliderDetuneOctave, 1, wxALL|wxEXPAND, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT5, _("Detune Fine"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer4->Add(StaticText3, 1, wxALL|wxEXPAND, 5);
	m_pSliderDetuneFine = new wxSlider(this, ID_SLIDER1, 32, 0, 63, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER1"));
	m_pSliderDetuneFine->SetToolTip(_("Detune DCO in 1.6 cent steps"));
	FlexGridSizer4->Add(m_pSliderDetuneFine, 1, wxALL|wxEXPAND, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	m_pChkFixedFreq = new wxCheckBox(this, ID_CHECKBOX2, _("Fixed Freq"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	m_pChkFixedFreq->SetValue(false);
	m_pChkFixedFreq->SetToolTip(_("DCO Fixed frequency"));
	BoxSizer1->Add(m_pChkFixedFreq, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pChkX16 = new wxCheckBox(this, ID_CHECKBOX3, _("x16"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	m_pChkX16->SetValue(false);
	m_pChkX16->SetToolTip(_("DCO frequency detune multiplier"));
	BoxSizer1->Add(m_pChkX16, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer4->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer1->Add(FlexGridSizer4, 0, wxALIGN_LEFT, 0);
	FlexGridSizer6->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DCA"));
	FlexGridSizer2 = new wxFlexGridSizer(1, 0, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableRow(1);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Amplitude Envelope"));
	FlexGridSizer7 = new wxFlexGridSizer(1, 0, 0, 0);
	FlexGridSizer7->AddGrowableCol(0);
	FlexGridSizer7->AddGrowableRow(1);
	m_pEnvEditorAmp = new EnvelopeEditor(this,ID_ENVAMP,wxDefaultPosition,wxSize(296,82),ENV_STYLE_DCA_ENV,_T("ID_ENVAMP"));
	FlexGridSizer7->Add(m_pEnvEditorAmp, 2, wxALL|wxEXPAND, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer3->AddGrowableRow(0);
	m_pLblDepth = new wxStaticText(this, ID_STATICTEXT15, _("Env Depth"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	FlexGridSizer3->Add(m_pLblDepth, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderEnvDepth = new wxSlider(this, ID_SLIDER11, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER11"));
	m_pSliderEnvDepth->SetToolTip(_("DCA Amplitued envelope depth"));
	FlexGridSizer3->Add(m_pSliderEnvDepth, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX4, _("Range"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
	CheckBox1->SetValue(false);
	FlexGridSizer3->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer3->Add(FlexGridSizer7, 0, wxALIGN_LEFT, 0);
	FlexGridSizer2->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Key Follow"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(1);
	m_pBmpKeyboard = new wxStaticBitmap(this, ID_STATICBITMAP1, keyboard_xpm, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	FlexGridSizer1->Add(m_pBmpKeyboard, 1, wxALL|wxEXPAND, 5);
	m_pEnvEditorKeyFollow = new EnvelopeEditor(this,ID_ENVKF,wxDefaultPosition,wxSize(296,-1),ENV_STYLE_DCA_KF,_T("ID_ENVKF"));
	FlexGridSizer1->Add(m_pEnvEditorKeyFollow, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer4->Add(FlexGridSizer1, 0, wxEXPAND, 0);
	FlexGridSizer2->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Key Velocity"));
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
	m_pCmbCurve->SetToolTip(_("DCA key velocity curve"));
	FlexGridSizer9->Add(m_pCmbCurve, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_pSliderVelSensitivity = new wxSlider(this, ID_SLIDER9, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER9"));
	m_pSliderVelSensitivity->SetToolTip(_("DCA key velocity sensitivity"));
	FlexGridSizer9->Add(m_pSliderVelSensitivity, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5->Add(FlexGridSizer9, 0, wxEXPAND, 0);
	FlexGridSizer2->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Sensitivity"));
	FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer5->AddGrowableRow(0);
	m_pSliderAmpSens = new wxSlider(this, ID_SLIDER10, 7, 0, 7, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDER10"));
	m_pSliderAmpSens->SetToolTip(_("DCA Sensititivy to external modulation"));
	FlexGridSizer5->Add(m_pSliderAmpSens, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
	StaticBoxSizer6->Add(FlexGridSizer5, 0, wxEXPAND, 0);
	FlexGridSizer2->Add(StaticBoxSizer6, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer2->Add(FlexGridSizer2, 0, wxEXPAND, 0);
	FlexGridSizer6->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(FlexGridSizer6);
	FlexGridSizer6->Fit(this);
	FlexGridSizer6->SetSizeHints(this);

	Connect(ID_SLIDER8,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderDetuneCmdScrollChanged);
	Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderDetuneFineCmdScrollChanged);
	Connect(ID_SLIDER11,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderEnvDepthCmdScrollChanged);
	Connect(ID_SLIDER9,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderVelSensitivityCmdScrollChanged);
	Connect(ID_SLIDER10,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&vzVoiceModule::OnSliderAmpSensCmdScrollChanged);
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
