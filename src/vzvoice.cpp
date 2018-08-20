#include "vzvoice.h"
#include <cstring>

vzvoice::vzvoice()
{
    Validate(true);
    m_bModified = false;
}

vzvoice::vzvoice(wxByte* pData)
{
    SetSysEx(pData);
}

vzvoice::~vzvoice()
{
}

bool vzvoice::IsModified()
{
    return m_bModified;
}

void vzvoice::GetSysEx(wxByte* pData)
{
    memcpy(pData, m_acSysEx, VZ_VOICE_SIZE);
}

wxByte* vzvoice::GetSysEx()
{
    return m_acSysEx;
}

bool vzvoice::SetSysEx(wxByte* pData)
{
    memcpy(m_acSysEx, pData, VZ_VOICE_SIZE);
    m_bModified = Validate(true);
    return m_bModified;
}

bool vzvoice::ValidateByte(wxByte* pByte, wxByte nByte, bool bFix)
{
    bool bInvalid = (nByte != *pByte);
    if(bFix)
        *pByte = nByte;
    return bInvalid;
}

bool vzvoice::Validate(bool bFix)
{
    m_bModified = false;
    m_bModified |= ValidateByte(m_acSysEx, 0xF0, bFix);
    m_bModified |= ValidateByte(m_acSysEx + 1, 0x44, bFix);
    m_bModified |= ValidateByte(m_acSysEx + 2, 0x03, bFix);
    m_bModified |= ValidateByte(m_acSysEx + 3, 0x00, bFix);
    m_bModified |= ValidateByte(m_acSysEx + 4, 0x70, bFix); //!@todo Allow different MIDI channel [0xF0 - 0xFF]
    m_bModified |= ValidateByte(m_acSysEx + 5, 0x00, bFix);
    m_bModified |= ValidateByte(m_acSysEx + 6, 0x40, bFix); //!@todo Allow different tone locations [0x40 - 0x44]
    m_bModified |= ValidateByte(m_acSysEx + VZ_VOICE_PAYLOAD_SIZE + 7, Checksum(m_acSysEx + 7, VZ_VOICE_PAYLOAD_SIZE), bFix);
    m_bModified |= ValidateByte(m_acSysEx + VZ_VOICE_PAYLOAD_SIZE + 8, 0xF7, bFix); //!@todo Allow different tone locations [0x40 - 0x44]
    return m_bModified;
}

wxByte vzvoice::Checksum(wxByte* pData, unsigned int nSize, wxByte nChecksum)
{
    wxByte nSum = nChecksum;
    for(unsigned int nIndex = 0; nIndex < nSize; nIndex+=2)
        nSum += DecodeByte(pData + nIndex);
    return (0 - nSum) & 0x7F;
}


wxByte vzvoice::DecodeByte(wxByte* pCursor)
{
    return (*(pCursor) << 4) | (*(pCursor + 1));
}

void vzvoice::EncodeByte(wxByte* pCursor, wxByte nValue)
{
    *pCursor = (nValue & 0xF0) >> 4;
    *(pCursor + 1) = nValue & 0x0F;
}

wxByte vzvoice::GetByteFromSysex(unsigned int nOffset)
{
    if(nOffset >= VZ_VOICE_PAYLOAD_SIZE / 2)
            return 0;

    return DecodeByte(m_acSysEx + VZ_VOICE_PAYLOAD_START + nOffset * 2);
}

bool vzvoice::PutByteToSysex(unsigned int nOffset, wxByte nValue)
{
    if(nOffset >= VZ_VOICE_PAYLOAD_SIZE / 2)
        return false;
    EncodeByte(m_acSysEx + VZ_VOICE_PAYLOAD_START + nOffset * 2, nValue);
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

bool vzvoice::IsExtPhase(wxByte nModule)
{
    switch(nModule)
    {
        case 3:
            return (m_acSysEx[8] & 0x01);
        case 5:
            return (m_acSysEx[8] & 0x02);
        case 7:
            return (m_acSysEx[8] & 0x04);
        default:
            return false;
    }
}

void vzvoice::EnableExtPhase(wxByte nModule, bool bEnable)
{
    if(bEnable)
        switch(nModule)
        {
            case 3:
                m_acSysEx[8] |= 0x01;
                break;
            case 5:
                m_acSysEx[8] |= 0x02;
                break;
            case 7:
                m_acSysEx[8] |= 0x04;
                break;
        }
    else
        switch(nModule)
        {
            case 3:
                m_acSysEx[8] &= ~0x01;
                break;
            case 5:
                m_acSysEx[8] &= ~0x02;
                break;
            case 7:
                m_acSysEx[8] &= ~0x04;
                break;
        }
}

wxByte vzvoice::GetWaveform(wxByte nModule)
{
    wxByte nValue  = DecodeByte(m_acSysEx + VZ_VOICE_PAYLOAD_START + 1 + nModule / 2);
    wxByte nShift = 3 * (nModule % 2);
    return ((nValue >> nShift) & 0x07);
}

void vzvoice::SetWaveform(wxByte nModule, VZ_WAVEFORM nWaveform)
{
    wxByte nValue = GetByteFromSysex(1 + nModule / 2);
    wxByte nShift = 3 * (nModule % 2);
    nValue &= ~(0x07 << nShift);
    nValue |= (nWaveform << nShift);
    PutByteToSysex(1 + nModule / 2, nValue);
}

wxByte vzvoice::GetLine(wxByte nLine)
{
    if(nLine > 2)
       return 0;
    wxByte nValue = GetByteFromSysex(1 + nLine);
    return nValue >> 6;
}

bool vzvoice::SetLine(wxByte nLine, VZ_LINE nMode)
{
    if(nLine > 3 || nMode > 2)
       return false;
    wxByte nValue = GetByteFromSysex(1 + nLine);
    nValue &= 0x3F;
    nValue |= (nMode << 6);
    PutByteToSysex(1+ nLine, nValue);
    return true;
}

wxByte vzvoice::GetDetuneCourse(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    wxByte nValue = GetByteFromSysex(6 + nModule * 2);
    return nValue & 0x7F;
}

bool vzvoice::SetDetuneCourse(wxByte nModule, wxByte nDetune)
{
    if(nModule > 7 || nDetune > 0x7F)
        return false;
    wxByte nValue = GetByteFromSysex(6 + nModule * 2);
    nValue &= 0x80;
    nValue |= nDetune;
    PutByteToSysex(6 + nModule * 2, nValue);
    return true;
}

wxByte vzvoice::GetDetuneFine(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    wxByte nValue = GetByteFromSysex(5 + nModule * 2);
    return (nValue >> 2) & 0x3F;
}

bool vzvoice::SetDetuneFine(wxByte nModule, wxByte nDetune)
{
    if(nModule > 7 || nDetune > 0x3F)
        return false;
    wxByte nValue = GetByteFromSysex(5 + nModule * 2);
    nValue &= 0x03;
    nValue |= (nDetune << 2);
    PutByteToSysex(5 + nModule * 2, nValue);
    return true;
}

bool vzvoice::IsDetunePositive(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    wxByte nValue = GetByteFromSysex(6 + nModule * 2);
    return nValue & 0x80;
}

bool vzvoice::SetDetunePositive(wxByte nModule, bool bPolarity)
{
    if(nModule > 7)
        return false;
    wxByte nValue = GetByteFromSysex(6 + nModule * 2);
    nValue &= 0x7F;
    nValue |= (bPolarity << 7); //!@todo is bool == 0x01?
    PutByteToSysex(6 + nModule * 2, nValue);
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
        return 0;
    wxByte nValue = GetByteFromSysex(5 + nModule * 2);
    return nValue & 0x02;
}

bool vzvoice::EnablePitchFix(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    wxByte nValue = GetByteFromSysex(5 + nModule * 2);
    nValue &= 0xFD;
    nValue |= (bEnable << 1); //!@todo is bool == 0x01?
    PutByteToSysex(5 + nModule * 2, nValue);
    return true;
}

bool vzvoice::IsPitchFixRange(wxByte nModule)
{
    if(nModule > 7)
        return 0;
    wxByte nValue = GetByteFromSysex(5 + nModule * 2);
    return nValue & 0x01;
}

bool vzvoice::EnablePitchFixRange(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    wxByte nValue = GetByteFromSysex(5 + nModule * 2);
    nValue &= 0xFE;
    nValue |= bEnable; //!@todo is bool == 0x01?
    PutByteToSysex(5 + nModule * 2, nValue);
    return true;
}

Envelope* vzvoice::GetDCAEnvelope(wxByte nModule)
{
    if(nModule > 7)
        nModule = 0; //Default to first module if invalid module requested (could give null but may be safer this way)
    wxByte nValue;
    Envelope* pEnv = &m_envDCA[nModule];
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        nValue = GetByteFromSysex(21 + nModule + nStep * 18);
        pEnv->SetStepRate(nStep, nValue & 0x7F);
        pEnv->EnableVelocityRate(nStep, nValue & 0x80);
        nValue = GetByteFromSysex(30 + nModule + nStep * 18);
        pEnv->SetStepLevel(nStep, nValue & 0x7F);
        if(nValue & 0x80)
            pEnv->SetSustainStep(nStep);
        nValue = GetByteFromSysex(165 + nModule);
        pEnv->SetLastStep((nValue & 0x70) >> 4);
        pEnv->SetAmpSens(nValue & 0x07);
        nValue =GetByteFromSysex(175 + nModule);
        pEnv->SetDepth(nValue & 0x7F);
    }
    return pEnv;
}

bool vzvoice::UpdateDCAEnvelope(wxByte nModule)
{
    if(nModule > 7)
        return false;
    Envelope* pEnv = &m_envDCA[nModule];
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        PutByteToSysex(21 + nModule + nStep * 18, pEnv->GetStepRate(nStep) & (pEnv->IsVelocityRateEnabled(nStep)<< 7));
        PutByteToSysex(30 + nModule + nStep * 18, pEnv->GetStepLevel(nStep) & ((pEnv->GetSustainStep() == nStep) << 7));
        PutByteToSysex(165 + nModule, (pEnv->GetLastStep() << 4) | pEnv->GetAmpSens());
        PutByteToSysex(175 + nModule, (pEnv->GetDepth() & 0x7F) | (IsModuleEnabled(nModule) << 7));
    }
    return true;
}

Envelope* vzvoice::GetDCOEnvelope()
{
    wxByte nValue;
    Envelope* pEnv = m_envDCA;
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        nValue = GetByteFromSysex(29 + nStep * 18);
        pEnv->SetStepRate(nStep, nValue & 0x7F);
        pEnv->EnableVelocityRate(nStep, nValue & 0x80);
        nValue = GetByteFromSysex(38 + nStep * 18);
        pEnv->SetStepLevel(nStep, nValue & 0x7F);
        if(nValue & 0x80)
            pEnv->SetSustainStep(nStep);
        nValue = GetByteFromSysex(173);
        pEnv->SetLastStep((nValue & 0x70) >> 4);
        pEnv->SetAmpSens(nValue & 0x07);
        nValue =GetByteFromSysex(183);
        pEnv->SetDepth(nValue & 0x3F);
    }
    return pEnv;
}

bool vzvoice::UpdateDCOEnvelope()
{
    Envelope* pEnv = &m_envDCO;
    for(wxByte nStep = 0; nStep < pEnv->GetSteps(); ++ nStep)
    {
        PutByteToSysex(29 + nStep * 18, pEnv->GetStepRate(nStep) & (pEnv->IsVelocityRateEnabled(nStep)<< 7));
        PutByteToSysex(38 + nStep * 18, pEnv->GetStepLevel(nStep) & ((pEnv->GetSustainStep() == nStep) << 7));
        PutByteToSysex(173, pEnv->GetLastStep() << 4 & pEnv->GetAmpSens());
        PutByteToSysex(183, (pEnv->GetDepth() & 0x3F) | (IsDCORangeWide() << 7));
    }
    return true;
}

wxByte vzvoice::GetLevel()
{
    return m_nLevel;
}

bool vzvoice::SetLevel(wxByte nLevel)
{
    if(nLevel > 99)
        return false;
    if(nLevel == 99)
        m_nLevel = 0x7F;
    else
        m_nLevel = nLevel;
    return true;
}

bool vzvoice::IsModuleEnabled(wxByte nModule)
{
    if(nModule > 7)
        return false;
    return m_bModuleEnabled[nModule];
}

bool vzvoice::EnableModule(wxByte nModule, bool bEnable)
{
    if(nModule > 7)
        return false;
    m_bModuleEnabled[nModule] = bEnable;
    return true;
}

bool vzvoice::IsDCORangeWide()
{
    return m_bDCORange;
}

bool vzvoice::SetDCORangeWide(bool bWide)
{
    m_bDCORange = bWide;
    return true;
}
