#include "vzvoice.h"
#include <cstring>

vzvoice::vzvoice() :
    vzsysex(VZ_VOICE_PAYLOAD_SIZE)
{
    Validate(true);
    m_pkfDCO = new KeyFollow(6, true);
}

vzvoice::vzvoice(wxByte* pData, bool bPayload) :
    vzsysex(VZ_VOICE_PAYLOAD_SIZE, pData, bPayload)
{
    Validate(true);
    m_bModified = false;
}

vzvoice::~vzvoice()
{
}

bool vzvoice::Validate(bool bFix)
{
    vzsysex::Validate(bFix);
    m_bModified |= ValidateByte(m_pSysEx + 5, 0x00, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 6, 0x40, bFix); //!@todo Allow different tone locations [0x40 - 0x44]
    m_bModified |= ValidateByte(m_pSysEx + 7 + m_nPayloadSize, Checksum(m_pSysEx + 7, m_nPayloadSize), bFix);
    return m_bModified;
}

bool vzvoice::IsExtPhase(wxByte nModule)
{
    switch(nModule)
    {
        case 3:
            return GetValue(0, 0x01);
        case 5:
            return GetValue(0, 0x02);
        case 7:
            return GetValue(0, 0x04);
        default:
            return false;
    }
}

bool vzvoice::EnableExtPhase(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    switch(nModule)
    {
        case 3:
            SetValue(0, 0x01, bEnable);
            break;
        case 5:
            SetValue(0, 0x02, bEnable);
            break;
        case 7:
            SetValue(0, 0x04, bEnable);
            break;
        default:
            return false;
    }
    return true;
}

wxByte vzvoice::GetWaveform(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return GetValue(1 + nModule / 2, 0x07 << (nModule%2 * 3));
}

bool vzvoice::SetWaveform(wxByte nModule, VZ_WAVEFORM nWaveform)
{
    if(nModule > 7 || nWaveform > 7)
        return false;
    SetValue(1 + nModule / 2, 0x07 << (nModule%2 * 3), nWaveform);
    return true;
}

wxByte vzvoice::GetLine(wxByte nLine)
{
    if(nLine > 3)
       return 0;
    return GetValue(1 + nLine, 0xC0);
}

bool vzvoice::SetLine(wxByte nLine, VZ_LINE nMode)
{
    if(nLine > 3 || nMode > 2)
       return false;
    SetValue(1 + nLine, 0xC0, nMode);
    return true;
}

wxByte vzvoice::GetDetuneCourse(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return GetValue(6 + nModule * 2, 0x7F);
}

bool vzvoice::SetDetuneCourse(wxByte nModule, wxByte nDetune)
{
    if(nModule > 7 || nDetune > 0x7F)
        return false;
    SetValue(6 + nModule * 2, 0x7F, nDetune);
    return true;
}

wxByte vzvoice::GetDetuneFine(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return GetValue(5 + nModule * 2, 0xFC);
}

bool vzvoice::SetDetuneFine(wxByte nModule, wxByte nDetune)
{
    if(nModule > 7 || nDetune > 0x3F)
        return false;
    SetValue(5 + nModule * 2, 0xFC, nDetune);
    return true;
}

bool vzvoice::IsDetunePositive(wxByte nModule)
{
    if(nModule > 7)
        return false;
    return GetValue(6 + nModule * 2, 0x80);
}

bool vzvoice::SetDetunePositive(wxByte nModule, bool bPolarity)
{
    if(nModule > 7)
        return false;
    SetValue(6 + nModule * 2, 0x80, bPolarity);
    return true;
}

int vzvoice::GetDetune(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    int nValue = GetDetuneCourse(nModule) * 64 + GetDetuneFine(nModule);
    if(!IsDetunePositive(nModule))
       nValue = -nValue;
    return nValue;
}

bool vzvoice::SetDetune(wxByte nModule, int nDetune)
{
    if(nModule > 7 || nDetune > 16383 || nDetune < 16383)
        return false;
    bool bPositive = true;
    wxByte nCourse = 0;
    wxByte nFine = 0;
    if(nDetune < 0)
    {
        bPositive = false;
        nDetune = -nDetune;
    }
    nCourse = (nDetune & 0x3F80) >> 7;
    nFine = (nDetune & 0x7F);
    bool bRetVal = SetDetunePositive(nModule, bPositive);
    bRetVal &= SetDetuneCourse(nModule, nCourse);
    bRetVal &= SetDetuneFine(nModule, nFine);
    return bRetVal;
}

bool vzvoice::IsPitchFix(wxByte nModule)
{
    if(nModule > 7)
        return false;
    return GetValue(5 + nModule * 2, 0x02);
}

bool vzvoice::EnablePitchFix(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    SetValue(5 + nModule * 2, 0x02, bEnable);
    return true;
}

bool vzvoice::IsPitchFixRange(wxByte nModule)
{
    if(nModule > 7)
        return false;
    return GetValue(5 + nModule * 2, 0x01);
}

bool vzvoice::EnablePitchFixRange(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    SetValue(5 + nModule * 2, 0x01, bEnable);
    return true;
}

Envelope* vzvoice::GetDCAEnvelope(wxByte nModule)
{
    if(nModule > 7)
        nModule = 0; //Default to first module if invalid module requested (could give null but may be safer this way)
    Envelope* pEnv = &m_envDCA[nModule];
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        pEnv->SetRate(nStep, GetValue(21 + nModule + nStep * 18, 0x7F));
        pEnv->EnableVelocityRate(nStep, GetValue(21 + nModule + nStep * 18, 0x80));
        pEnv->SetLevel(nStep, GetValue(30 + nModule + nStep * 18, 0x7F));
        if(GetValue(30 + nModule + nStep * 18, 0x80))
            pEnv->SetSustainStep(nStep); //!@todo Check whether first or last sustain step is used by synth (in case bad config)
    }
    pEnv->SetLastStep(GetValue(165 + nModule, 0x70));
    pEnv->SetAmpSens(GetValue(165 + nModule, 0x07));
    pEnv->SetDepth(GetValue(175, 0x7F));
    return pEnv;
}

bool vzvoice::UpdateDCAEnvelope(wxByte nModule)
{
    if(nModule > 7)
        return false;
    Envelope* pEnv = &m_envDCA[nModule];
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        SetValue(21 + nModule + nStep * 18, 0x7F, pEnv->GetRate(nStep));
        SetValue(21 + nModule + nStep * 18, 0x80, pEnv->IsVelocityRateEnabled(nStep));
        SetValue(30 + nModule + nStep * 18, 0x7F, pEnv->GetLevel(nStep));
        SetValue(30 + nModule + nStep * 18, 0x80, (pEnv->GetSustainStep() == nStep));
    }
    SetValue(165 + nModule, 0x70, pEnv->GetLastStep());
    SetValue(165 + nModule, 0x07, pEnv->GetAmpSens());
    SetValue(175 + nModule, 0x7F, pEnv->GetDepth());
    return true;
}

Envelope* vzvoice::GetDCOEnvelope()
{
    Envelope* pEnv = m_envDCA;
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        pEnv->SetRate(nStep, GetValue(29 + nStep * 18, 0x7F));
        pEnv->EnableVelocityRate(nStep, GetValue(29 + nStep * 18, 0x80));
        pEnv->SetLevel(nStep, GetValue(38 + nStep * 18, 0x7F));
        if(GetValue(38 +nStep * 18, 0x80))
            pEnv->SetSustainStep(nStep); //!@todo Check whether first or last sustain step is used by synth (in case bad config)
    }
    pEnv->SetLastStep(GetValue(173, 0x70));
    pEnv->SetAmpSens(GetValue(173, 0x07));
    pEnv->SetDepth(GetValue(183, 0x7F));
    return pEnv;
}

bool vzvoice::UpdateDCOEnvelope()
{
    Envelope* pEnv = &m_envDCO;
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        SetValue(29 + nStep * 18, 0x7F, pEnv->GetRate(nStep));
        SetValue(29 + nStep * 18, 0x80, pEnv->IsVelocityRateEnabled(nStep));
        SetValue(38 + nStep * 18, 0x7F, pEnv->GetLevel(nStep));
        SetValue(38 + nStep * 18, 0x80, (pEnv->GetSustainStep() == nStep));
    }
    SetValue(173, 0x70, pEnv->GetLastStep());
    SetValue(173, 0x07, pEnv->GetAmpSens());
    SetValue(182, 0x3F, pEnv->GetDepth());
    return true;
}

wxByte vzvoice::GetLevel()
{
    int nLevel = GetValue(174, 0x7F);
    if(nLevel > 99)
        return 99;
    return nLevel;
}

bool vzvoice::SetLevel(wxByte nLevel)
{
    if(nLevel > 99)
        return false;
    if(nLevel == 99)
        nLevel = 0x7F;
    SetValue(174, 0x7F, nLevel);
    return true;
}

wxByte vzvoice::GetCCSensitivity(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return GetValue(165 + nModule, 0x07);
}

bool vzvoice::SetCCSensitivity(wxByte nModule, wxByte nSensitivity)
{
    if(nModule > 7 || nSensitivity > 0x07)
        return false;
    SetValue(165 + nModule, 0x07, nSensitivity);
    return true;
}

wxByte vzvoice::GetDCAEnvDepth(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return GetValue(175 + nModule, 0x7F);
}

bool vzvoice::SetDCAEnvDepth(wxByte nModule, wxByte nDepth)
{
    if(nModule > 7 || nDepth > 99)
        return false;
    if(nDepth == 99)
        nDepth = 0x7F;
    SetValue(175 + nModule, 0x7F, nDepth);
    return true;
}

bool vzvoice::IsModuleEnabled(wxByte nModule)
{
    if(nModule > 7)
        return false;
    return !GetValue(175 + nModule, 0x80);
}

bool vzvoice::EnableModule(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    SetValue(175 + nModule, 0x80, !bEnable);
    return true;
}

bool vzvoice::IsDCORangeWide()
{
    return GetValue(183, 0x80);
}

bool vzvoice::SetDCORangeWide(bool bWide)
{
    SetValue(183, 0x80, bWide);
    return true;
}

KeyFollow* vzvoice::GetDCAKeyFollow(wxByte nModule)
{
    if(nModule > 7)
        nModule = 0; //Default to first module if invalid module requested (could give null but may be safer this way)
    KeyFollow* pKF = &m_kfDCA[nModule];
    for(wxByte nStep = 0; nStep < pKF->GetSteps(); ++ nStep)
    {
        pKF->SetKey(nStep, GetValue(184 + nStep + nModule * 12, 0x7F));
        pKF->SetLevel(nStep, GetValue(185 + nStep + nModule * 12, 0x7F));
    }
    return pKF;
}

bool vzvoice::UpdateDCAKeyFollow(wxByte nModule)
{
    if(nModule > 7)
        return false;
    KeyFollow* pKF= &m_kfDCA[nModule];
    for(wxByte nStep = 0; nStep < pKF->GetSteps(); ++ nStep)
    {
        SetValue(184 + nStep + nModule * 12, 0x7F, pKF->GetKey(nStep));
        SetValue(185 + nStep + nModule * 12, 0x7F, pKF->GetLevel(nStep));
    }
    return true;
}

KeyFollow* vzvoice::GetDCOKeyFolllow()
{
    for(wxByte nStep = 0; nStep < m_pkfDCO->GetSteps(); ++ nStep)
    {
        m_pkfDCO->SetKey(nStep, GetValue(280, 0x7F)); //!@todo Limit KF range to 0x00..0x78 (Note 7)
        m_pkfDCO->SetLevel(nStep, GetValue(281, 0x3F)); //!@todo Limit KF level to 63..0 and invert?(Note 6)
    }
    return m_pkfDCO;
}

bool vzvoice::UpdateDCOKeyFollow()
{
    for(wxByte nStep = 0; nStep < m_pkfDCO->GetSteps(); ++ nStep)
    {
        SetValue(280 + nStep, 0x7F, m_pkfDCO->GetKey(nStep));
        SetValue(281 + nStep, 0x7F, m_pkfDCO->GetLevel(nStep));
    }
    return true;
}

wxByte vzvoice::GetKFkey(wxByte nStep)
{
    if(nStep > 5)
        return 0;
    return GetValue(292 + nStep * 2, 0x7F);
}

bool vzvoice::SetKFkey(wxByte nStep, wxByte nKey)
{
    if(nStep > 5 || nKey > 0x78)
        return false;
    SetValue(292 +nStep * 2, 0x7F, nKey);
    return true;
}

wxByte vzvoice::GetKFrate(wxByte nStep)
{
    if(nStep > 5)
        return 0;
    return (GetValue(293 + nStep * 2, 0x7F));
}

bool vzvoice::SetKFrate(wxByte nStep, wxByte nRate)
{
    if(nStep > 5 || nRate > 0x78)
        return false;
    SetValue(293 + nStep * 2, 0x7F, nRate);
    return true;
}

wxByte vzvoice::GetModuleVelCurve(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return  GetValue(304 + nModule, 0xE0);
}

bool vzvoice::SetModuleVelCurve(wxByte nModule, wxByte nCurve)
{
    if(nModule > 7 || nCurve > 0x07)
        return false;
    SetValue(304 + nModule, 0xE0, nCurve);
    return true;
}

wxByte vzvoice::GetModuleVelSens(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    return  GetValue(304 + nModule, 0x1F);
}

bool vzvoice::SetModuleVelSens(wxByte nModule, wxByte nSens)
{
    if(nModule > 7 || nSens > 0x1F)
        return false;
    SetValue(304 + nModule, 0x1F, nSens);
    return true;
}

wxByte vzvoice::GetPitchVelCurve()
{
    return GetValue(312, 0xE0);
}

bool vzvoice::SetPitchVelCurve(wxByte nCurve)
{
    SetValue(312, 0xE0, nCurve);
    return true;
}
wxByte vzvoice::GetPitchVelSens()
{
    return GetValue(312, 0x1F);
}

bool vzvoice::SetPitchVelSens(wxByte nSens)
{
    SetValue(312, 0x1F, nSens);
    return true;
}

wxByte vzvoice::GetRateVelCurve()
{
    return GetValue(313, 0xE0);
}

bool vzvoice::SetRateVelCurve(wxByte nCurve)
{
    SetValue(313, 0xE0, nCurve);
    return true;
}
wxByte vzvoice::GetRateVelSens()
{
    return GetValue(313, 0x1F);
}

bool vzvoice::SetRateVelSens(wxByte nSens)
{
    SetValue(313, 0x1F, nSens);
    return true;
}

int vzvoice::GetOctave()
{
    int nOctave = GetValue(314, 0x60);
    if(GetValue(314, 0x80))
        nOctave = -nOctave;
    return nOctave;
}

bool vzvoice::SetOctave(int nOctave)
{
    if(nOctave < -2 || nOctave > 2)
        return false;
    if(nOctave < 0)
    {
        SetValue(314, 0x80, 1);
        nOctave = -nOctave;
    }
    else
        SetValue(314, 0x80, 0);

    SetValue(314, 0x60, nOctave);
    return true;
}

bool vzvoice::IsVibratoMulti()
{
    return GetValue(314, 0x08);
}

bool vzvoice::EnableVibratoMulti(bool bEnable)
{
    SetValue(314, 0x08, bEnable);
    return true;
}

wxByte vzvoice::GetVibratoWaveform()
{
    return GetValue(314, 0x03);
}

bool vzvoice::SetVibratoWaveform(wxByte nWaveform)
{
    if(nWaveform > 3)
        return false;
    SetValue(314, 0x03, nWaveform);
    return true;
}

wxByte vzvoice::GetVibratoDepth()
{
    return GetValue(315, 0x7F);
}

bool vzvoice::SetVibratoDepth(wxByte nDepth)
{
    if(nDepth > 99)
        return false;
    SetValue(315, 0x7F, nDepth);
    return true;
}

wxByte vzvoice::GetVibratoRate()
{
    return GetValue(316, 0x7F);
}

bool vzvoice::SetVibratoRate(wxByte nRate)
{
    if(nRate > 99)
        return false;
    SetValue(316, 0x7F, nRate);
    return true;
}

wxByte vzvoice::GetVibratoDelay()
{
    return GetValue(317, 0x7F);
}

bool vzvoice::SetVibratoDelay(wxByte nDelay)
{
    if(nDelay > 99)
        return false;
    SetValue(317, 0x7F, nDelay);
    return true;
}

bool vzvoice::IsTremeloMulti()
{
    return GetValue(318, 0x08);
}

bool vzvoice::EnableTremeloMulti(bool bEnable)
{
    SetValue(318, 0x08, bEnable);
    return true;
}

wxByte vzvoice::GetTremeloWaveform()
{
    return GetValue(318, 0x03);
}

bool vzvoice::SetTremeloWaveform(wxByte nWaveform)
{
    if(nWaveform > 3)
        return false;
    SetValue(318, 0x03, nWaveform);
    return true;
}
wxByte vzvoice::GetTremeloDepth()
{
    return GetValue(319, 0x7F);
}

bool vzvoice::SetTremeloDepth(wxByte nDepth)
{
    if(nDepth > 99)
        return false;
    SetValue(319, 0x7F, nDepth);
    return true;
}

wxByte vzvoice::GetTremeloRate()
{
    return GetValue(320, 0x7F);
}

bool vzvoice::SetTremeloRate(wxByte nRate)
{
    if(nRate > 99)
        return false;
    SetValue(320, 0x7F, nRate);
    return true;
}

wxByte vzvoice::GetTremeloDelay()
{
    return GetValue(321, 0x7F);
}

bool vzvoice::SetTremeloDelay(wxByte nDelay)
{
    if(nDelay > 99)
        return false;
    SetValue(321, 0x7F, nDelay);
    return true;
}

wxString vzvoice::GetName()
{
    wxString sName;
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
    {
        sName += wxString::FromAscii(GetByteFromSysex(322 + nIndex));
    }
    return sName.Trim();
}

void vzvoice::SetName(wxString sName)
{
    sName.Truncate(12);
    sName.Pad(12 - sName.Length());
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
        PutByteToSysex(322 + nIndex, sName[nIndex]);
}
