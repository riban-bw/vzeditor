/***************************************************************
 * Name:      vzmodule.cpp
 * Purpose:   Implements VZModule class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-31
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "vzmodule.h"
#include "../media/keyboard.xpm"

//(*InternalHeaders(VZModule)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VZModule)
const long VZModule::ID_CHKENABLE = wxNewId();
const long VZModule::ID_CHKEXTPHASE = wxNewId();
const long VZModule::ID_STATICTEXT4 = wxNewId();
const long VZModule::ID_CMBWAVEFORM = wxNewId();
const long VZModule::ID_STATICTEXT5 = wxNewId();
const long VZModule::ID_SLIDERDETUNEOCTAVE = wxNewId();
const long VZModule::ID_STATICTEXT6 = wxNewId();
const long VZModule::ID_SLIDERDETUNEFINE = wxNewId();
const long VZModule::ID_CHKFIXEDFREQ = wxNewId();
const long VZModule::ID_CHKX16 = wxNewId();
const long VZModule::ID_ENVELOPEAMP = wxNewId();
const long VZModule::ID_SLIDERENVDEPTH = wxNewId();
const long VZModule::ID_BMPKEYBOARD = wxNewId();
const long VZModule::ID_ENVELOPEKEY = wxNewId();
const long VZModule::ID_CMBKEYVELCURVE = wxNewId();
const long VZModule::ID_SLIDERVELSENSITIVITY = wxNewId();
const long VZModule::ID_SLIDERAMPSENS = wxNewId();
//*)

BEGIN_EVENT_TABLE(VZModule,wxPanel)
    //(*EventTable(VZModule)
    //*)
    EVT_COMMAND(ID_ENVELOPEAMP, ENVELOPEGRAPH_EVENT, VZModule::OnAmpEnvChange)
    EVT_COMMAND(ID_ENVELOPEKEY, ENVELOPEGRAPH_EVENT, VZModule::OnKeyEnvChange)
END_EVENT_TABLE()

VZModule::VZModule(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size) :
    m_pVoice(NULL)
{
    //(*Initialize(VZModule)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;
    wxStaticBoxSizer* StaticBoxSizer6;
    wxStaticBoxSizer* StaticBoxSizer7;

    Create(parent, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL, _T("wxID_ANY"));
    m_pSizerModule = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Module"));
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    m_pChkEnable = new wxCheckBox(this, ID_CHKENABLE, _("Enable"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKENABLE"));
    m_pChkEnable->SetValue(true);
    m_pChkEnable->SetToolTip(_("Enable module"));
    BoxSizer2->Add(m_pChkEnable, 1, wxALL|wxEXPAND, 5);
    m_pChkExtPhase = new wxCheckBox(this, ID_CHKEXTPHASE, _("Ext Phase"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKEXTPHASE"));
    m_pChkExtPhase->SetValue(false);
    m_pChkExtPhase->SetToolTip(_("Enable external phase"));
    BoxSizer2->Add(m_pChkExtPhase, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, this, _("DCO"));
    m_pLblWaveform = new wxStaticText(this, ID_STATICTEXT4, _("Waveform"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticBoxSizer2->Add(m_pLblWaveform, 0, wxALL|wxEXPAND, 5);
    m_pChoiceWaveform = new wxChoice(this, ID_CMBWAVEFORM, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBWAVEFORM"));
    m_pChoiceWaveform->SetSelection( m_pChoiceWaveform->Append(_("Sine")) );
    m_pChoiceWaveform->Append(_("Saw 1"));
    m_pChoiceWaveform->Append(_("Saw 2"));
    m_pChoiceWaveform->Append(_("Saw 3"));
    m_pChoiceWaveform->Append(_("Saw 4"));
    m_pChoiceWaveform->Append(_("Saw 5"));
    m_pChoiceWaveform->Append(_("Noise 1"));
    m_pChoiceWaveform->Append(_("Noise 2"));
    m_pChoiceWaveform->SetToolTip(_("Select DCO Waveform"));
    StaticBoxSizer2->Add(m_pChoiceWaveform, 0, wxALL|wxEXPAND, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT5, _("Detune Course"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticBoxSizer2->Add(StaticText3, 0, wxALL|wxEXPAND, 5);
    m_pSliderDetuneOctave = new wxSlider(this, ID_SLIDERDETUNEOCTAVE, 0, -128, 127, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDERDETUNEOCTAVE"));
    m_pSliderDetuneOctave->SetToolTip(_("Set DCO detune in semitone steps"));
    StaticBoxSizer2->Add(m_pSliderDetuneOctave, 0, wxALL|wxEXPAND, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT6, _("Detune Fine"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticBoxSizer2->Add(StaticText4, 0, wxALL|wxEXPAND, 5);
    m_pSliderDetuneFine = new wxSlider(this, ID_SLIDERDETUNEFINE, 32, 0, 63, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDERDETUNEFINE"));
    m_pSliderDetuneFine->SetToolTip(_("Set DCO detune in 1.6 cent steps"));
    StaticBoxSizer2->Add(m_pSliderDetuneFine, 0, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    m_pChkFixedFreq = new wxCheckBox(this, ID_CHKFIXEDFREQ, _("Fixed Freq"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKFIXEDFREQ"));
    m_pChkFixedFreq->SetValue(false);
    m_pChkFixedFreq->SetToolTip(_("Select DCO fixed frequency"));
    BoxSizer1->Add(m_pChkFixedFreq, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pChkX16 = new wxCheckBox(this, ID_CHKX16, _("x16"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHKX16"));
    m_pChkX16->SetValue(false);
    m_pChkX16->SetToolTip(_("Select DCO frequency detune multiplier"));
    BoxSizer1->Add(m_pChkX16, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer2->Add(BoxSizer1, 0, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DCA"));
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Amplitude Envelope"));
    m_pGraphDCA = new EnvelopeGraph(this,ID_ENVELOPEAMP);
    StaticBoxSizer4->Add(m_pGraphDCA, 1, wxALL|wxEXPAND, 5);
    m_pSliderEnvDepth = new wxSlider(this, ID_SLIDERENVDEPTH, 99, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERENVDEPTH"));
    m_pSliderEnvDepth->SetToolTip(_("Set DCA amplitude envelope depth"));
    StaticBoxSizer4->Add(m_pSliderEnvDepth, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    BoxSizer4->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, this, _("Key Follow"));
    m_pBmpKeyboard = new wxStaticBitmap(this, ID_BMPKEYBOARD, wxBitmap(keyboard_xpm), wxDefaultPosition, wxDefaultSize, 0, _T("ID_BMPKEYBOARD"));
    StaticBoxSizer5->Add(m_pBmpKeyboard, 0, wxALL|wxEXPAND, 5);
    m_pGraphKeyfollow = new EnvelopeGraph(this,ID_ENVELOPEKEY);
    StaticBoxSizer5->Add(m_pGraphKeyfollow, 1, wxALL|wxEXPAND, 5);
    BoxSizer4->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, this, _("Key Velocity"));
    m_pChoiceKeyVelCurve = new wxChoice(this, ID_CMBKEYVELCURVE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CMBKEYVELCURVE"));
    m_pChoiceKeyVelCurve->SetSelection( m_pChoiceKeyVelCurve->Append(_("Curve 1")) );
    m_pChoiceKeyVelCurve->Append(_("Curve 2"));
    m_pChoiceKeyVelCurve->Append(_("Curve 3"));
    m_pChoiceKeyVelCurve->Append(_("Curve 4"));
    m_pChoiceKeyVelCurve->Append(_("Curve 5"));
    m_pChoiceKeyVelCurve->Append(_("Curve 6"));
    m_pChoiceKeyVelCurve->Append(_("Curve 7"));
    m_pChoiceKeyVelCurve->Append(_("Curve 8"));
    m_pChoiceKeyVelCurve->SetToolTip(_("Select DCA key velocity curve"));
    StaticBoxSizer6->Add(m_pChoiceKeyVelCurve, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_pSliderVelSensitivity = new wxSlider(this, ID_SLIDERVELSENSITIVITY, 0, 0, 31, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERVELSENSITIVITY"));
    m_pSliderVelSensitivity->SetToolTip(_("Set DCA key velocity sensitivity"));
    StaticBoxSizer6->Add(m_pSliderVelSensitivity, 1, wxALL|wxEXPAND, 5);
    BoxSizer4->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer7 = new wxStaticBoxSizer(wxVERTICAL, this, _("Sensitivity"));
    m_pSliderAmpSens = new wxSlider(this, ID_SLIDERAMPSENS, 7, 0, 7, wxDefaultPosition, wxDefaultSize, wxSL_VERTICAL|wxSL_INVERSE, wxDefaultValidator, _T("ID_SLIDERAMPSENS"));
    m_pSliderAmpSens->SetToolTip(_("Set DCA sensititivy to external modulation"));
    StaticBoxSizer7->Add(m_pSliderAmpSens, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(StaticBoxSizer7, 0, wxALL|wxEXPAND, 5);
    StaticBoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    m_pSizerModule->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    SetSizer(m_pSizerModule);
    SetSizer(m_pSizerModule);
    Layout();

    Connect(ID_CHKENABLE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZModule::OnEnable);
    Connect(ID_CHKEXTPHASE,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZModule::OnExtPhase);
    Connect(ID_CMBWAVEFORM,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZModule::OnWaveform);
    Connect(ID_SLIDERDETUNEOCTAVE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZModule::OnDetuneCourse);
    Connect(ID_SLIDERDETUNEFINE,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZModule::OnDetuneFine);
    Connect(ID_CHKFIXEDFREQ,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZModule::OnFixedFreq);
    Connect(ID_CHKX16,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&VZModule::OnX16);
    Connect(ID_SLIDERENVDEPTH,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZModule::OnEnvDepth);
    Connect(ID_CMBKEYVELCURVE,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&VZModule::OnKeyVelCurve);
    Connect(ID_SLIDERVELSENSITIVITY,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZModule::OnKeyVelSens);
    Connect(ID_SLIDERAMPSENS,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&VZModule::OnSensitivity);
    //*)
    m_pGraphDCA->SetMaxNodes(8);
    m_pGraphDCA->SetMaxHeight(99);
    m_pGraphDCA->SetOrigin(99);
    m_pGraphKeyfollow->SetMaxNodes(6);
    m_pGraphKeyfollow->SetMaxHeight(99);
    m_pGraphKeyfollow->SetOrigin(99);
}

VZModule::~VZModule()
{
    //(*Destroy(VZModule)
    //*)
}

void VZModule::SetVoice(VZVoice* pVoice)
{
    m_pVoice = pVoice;
}

void VZModule::SetModule(wxByte nModule)
{
    m_nModule = nModule;
    UpdateGui();
}

void VZModule::UpdateGui()
{
    m_pGraphDCA->InhibitUpdates();    m_pGraphKeyfollow->InhibitUpdates();
    m_pSizerModule->GetStaticBox()->SetLabel(wxString::Format("M%d", m_nModule + 1));
    if(m_nModule < 3 || !(m_nModule %2))
    {
        m_pChkExtPhase->Disable();
        m_pChkExtPhase->Hide();
    }
    if(!m_pVoice)
        return;
    m_pChkExtPhase->SetValue(m_pVoice->IsExtPhase(m_nModule));
    m_pChoiceWaveform->SetSelection(m_pVoice->GetWaveform(m_nModule));
    m_pSliderDetuneOctave->SetValue(m_pVoice->GetDetuneCourse(m_nModule));
    m_pSliderDetuneFine->SetValue(m_pVoice->GetDetuneFine(m_nModule));
    m_pChkFixedFreq->SetValue(m_pVoice->IsPitchFixRange(m_nModule));
    m_pChkX16->SetValue(m_pVoice->IsPitchFixRange(m_nModule));
    m_pSliderVelSensitivity->SetValue(m_pVoice->GetModuleVelSens(m_nModule));
    m_pChoiceKeyVelCurve->SetSelection(m_pVoice->GetModuleVelCurve(m_nModule));
    m_pSliderAmpSens->SetValue(m_pVoice->GetCCSensitivity(m_nModule));
    m_pSliderEnvDepth->SetValue(m_pVoice->GetDCAEnvDepth(m_nModule));
    Envelope* pEnvelope = m_pVoice->GetDCAEnvelope(m_nModule);
    m_pGraphDCA->Clear(false);
    unsigned int nX = 0;
    for(unsigned int nNode = 1; nNode < pEnvelope->GetSteps(); ++nNode)
    {
        nX += pEnvelope->GetRate(nNode);
        unsigned int nY = m_pGraphDCA->GetMaxHeight() - pEnvelope->GetLevel(nNode);
        int nIndex = m_pGraphDCA->AddNode(wxPoint(nX, nY));
        if((int)pEnvelope->GetSustainStep() == nIndex)
            m_pGraphDCA->SetSustain(nIndex);
    }
    KeyFollow* pKeyFollow = m_pVoice->GetDCAKeyFollow(m_nModule);
    for(unsigned int nNode = 1; nNode < pKeyFollow->GetSteps(); ++nNode)
    {
        nX = pKeyFollow->GetKey(nNode);
        unsigned int nY = m_pGraphDCA->GetMaxHeight() - pKeyFollow->GetLevel(nNode);
        m_pGraphKeyfollow->AddNode(wxPoint(nX, nY));
    }
    m_pChkEnable->SetValue(m_pVoice->IsModuleEnabled(m_nModule));
    EnableControls(m_pVoice->IsModuleEnabled(m_nModule));
    m_pGraphDCA->InhibitUpdates(false);
    m_pGraphKeyfollow->InhibitUpdates(false);
}

void VZModule::OnEnable(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->EnableModule(m_nModule, event.IsChecked());
    EnableControls(event.IsChecked());
}

void VZModule::EnableControls(bool bEnable)
{
    // Enable / disable controls (not enable checkbox)
    const wxWindowList& windowList = this->GetChildren();
    for(wxWindowList::compatibility_iterator node = windowList.GetFirst(); node; node = node->GetNext())
    {
        wxWindow *pWindow = node->GetData();
        if(pWindow != m_pChkEnable)
            pWindow->Enable(bEnable);
    }
}

void VZModule::OnExtPhase(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->EnableExtPhase(m_nModule, event.IsChecked());
}

void VZModule::OnWaveform(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetWaveform(m_nModule, (VZ_WAVEFORM)event.GetInt());
}

void VZModule::OnDetuneCourse(wxScrollEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetDetuneCourse(m_nModule, event.GetInt());
}

void VZModule::OnDetuneFine(wxScrollEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetDetuneFine(m_nModule, event.GetInt());
}

void VZModule::OnFixedFreq(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->EnablePitchFix(m_nModule, event.IsChecked());
}

void VZModule::OnX16(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->EnablePitchFixRange(m_nModule, event.IsChecked());
}

void VZModule::OnEnvDepth(wxScrollEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetDCAEnvDepth(m_nModule, event.GetInt());
}

void VZModule::OnKeyVelCurve(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetModuleVelCurve(m_nModule, event.GetInt());
}

void VZModule::OnKeyVelSens(wxScrollEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetModuleVelSens(m_nModule, event.GetInt());
}

void VZModule::OnSensitivity(wxScrollEvent& event)
{
    if(!m_pVoice)
        return;
    m_pVoice->SetCCSensitivity(m_nModule, event.GetInt());
}

void VZModule::OnAmpEnvChange(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    unsigned int nNode;
    unsigned int nLastX = 0;
    Envelope* pEnvelope = m_pVoice->GetDCAEnvelope(m_nModule);
    for(nNode = 1; nNode < m_pGraphDCA->GetNodeCount(); ++nNode)
    {
        //!@todo We should allow adjustment of node zero
        //Start from 1 because node 0 is at 0,0
        pEnvelope->SetLevel(nNode, m_pGraphKeyfollow->GetMaxHeight() - m_pGraphDCA->GetNode(nNode).y);
        pEnvelope->SetRate(nNode, m_pGraphDCA->GetNode(nNode).x - nLastX);
        nLastX = m_pGraphDCA->GetNode(nNode).x;
    }
    pEnvelope->SetLastStep(nNode);
    pEnvelope->SetSustainStep(m_pGraphDCA->GetSustain());
    m_pVoice->UpdateDCAEnvelope(m_nModule);
}

void VZModule::OnKeyEnvChange(wxCommandEvent& event)
{
    if(!m_pVoice)
        return;
    KeyFollow* pKeyFollow = m_pVoice->GetDCAKeyFollow(m_nModule);
    for(unsigned int nNode = 1; nNode < m_pGraphDCA->GetNodeCount(); ++nNode)
    {
        //Start from 1 because node 0 is at 0,0
        pKeyFollow->SetLevel(nNode, m_pGraphKeyfollow->GetMaxHeight() - m_pGraphKeyfollow->GetNode(nNode).y);
        pKeyFollow->SetKey(nNode, m_pGraphKeyfollow->GetNode(nNode).x); //!@todo Scale key follow
    }
    m_pVoice->UpdateDCAKeyFollow(m_nModule);
}

