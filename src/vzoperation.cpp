#include "vzoperation.h"

vzoperation::vzoperation() :
    vzsysex(VZ_OPERATION_PAYLOAD_SIZE)
{
    Validate(true);
}

vzoperation::vzoperation(wxByte* pData, bool bPayload) :
    vzsysex(VZ_OPERATION_PAYLOAD_SIZE, pData, bPayload)
{
    Validate(true);
    m_bModified = false;
}

vzoperation::~vzoperation()
{
}

bool vzoperation::Validate(bool bFix)
{
    vzsysex::Validate(bFix);
    m_bModified |= ValidateByte(m_pSysEx + 5, 0x01, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 6, 0x40, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 7 + m_nPayloadSize, Checksum(m_pSysEx + 7, m_nPayloadSize), bFix);
    return m_bModified;
}

unsigned int vzoperation::GetMode()
{
    return GetValue(0, 0x0F);
}

bool vzoperation::SetMode(unsigned int nMode)
{
    if(nMode > 8)
        return false;
    SetValue(0, 0x0F, nMode);
    return true;
}

wxString vzoperation::GetName()
{
    wxString sName;
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
    {
        sName += wxString::FromAscii(GetByteFromSysex(1 + nIndex));
    }
    return sName.Trim();
}

void vzoperation::SetName(wxString sName)
{
    sName.Truncate(12);
    sName.Pad(12 - sName.Length());
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
        PutByteToSysex(1 + nIndex, sName[nIndex]);
}

bool vzoperation::IsXfade()
{
    return 0x02 == (GetByteFromSysex(15) & 0x02);
}

bool vzoperation::EnableXfade(bool bEnable)
{
    PutByteToSysex(15, bEnable?0x02:0x00);
    return true;
}

unsigned int vzoperation::GetSplitPoint(unsigned int nPoint)
{
    if(nPoint > 3)
        return 0;
    return (GetByteFromSysex(16 + nPoint) & 0x7F);
}

bool vzoperation::SetSplitPoint(unsigned int nPoint, unsigned int nKey)
{
    if(nPoint > 3 || nKey > 0x7F)
        return false;
    PutByteToSysex(16 + nPoint, nKey);
    return true;
}

unsigned int vzoperation::GetXfadeMin(unsigned int nPoint)
{
    if(nPoint > 3)
        return 0;
    return GetByteFromSysex(20 + nPoint * 2);
}

bool vzoperation::SetXfadeMin(unsigned int nPoint, unsigned int nValue)
{
    if(nPoint > 3 || nValue > 0x78)
        return false;
    PutByteToSysex(20 + nPoint * 2, nValue);
    return true;
}

unsigned int vzoperation::GetXfadeMax(unsigned int nPoint)
{
    if(nPoint > 3)
        return 0;
    return GetByteFromSysex(21 + nPoint * 2);
}

bool vzoperation::SetXfadeMax(unsigned int nPoint, unsigned int nValue)
{
    if(nPoint > 3 || nValue > 0x78)
        return false;
    PutByteToSysex(21 + nPoint * 2, nValue);
    return true;
}

bool vzoperation::IsCard(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(28 + nCombi * 100, 0x40) != 0);
}

bool vzoperation::SelectCard(unsigned int nCombi, bool bCard)
{
    if(nCombi > 3)
        return false;
    SetValue(28 + nCombi * 100, 0x40, bCard?1:0);
    return true;
}


unsigned int vzoperation::GetVoice(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(28 + nCombi * 100, 0x3F);
}

bool vzoperation::SetVoice(unsigned int nCombi, unsigned int nVoice)
{
    if(nCombi > 3 || nVoice > 63)
        return false;
    SetValue(28 + nCombi * 100, 0x3F, nVoice);
    return true;
}

bool vzoperation::IsSolo(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x08) != 0);
}

bool vzoperation::EnableSolo(unsigned int nCombi, bool bSolo)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x08, bSolo?1:0);
    return true;
}

bool vzoperation::IsSustainPedal(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x10) != 0);
}

bool vzoperation::EnableSustainPedal(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool vzoperation::IsVelocityInvert(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x20) != 0);
}

bool vzoperation::EnableVelocityInvert(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool vzoperation::IsVibratoInvert(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x40) != 0);
}

bool vzoperation::EnableVibratoInvert(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool vzoperation::IsTremeloInvert(unsigned int nCombi) //!@todo Is this tremelo invert or inverse?
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::EnableTremeloInvert(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

unsigned int vzoperation::GetPortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(30 + nCombi * 100, 0x3F);
}

bool vzoperation::SetPortamentoTime(unsigned int nCombi, unsigned int nTime)
{
    if(nCombi > 3 || nTime > 63)
        return false;
    SetValue(30 + nCombi * 100, 0x3F, nTime);
    return true;
}

bool vzoperation::IsPortomentoRateConstant(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(30 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::SelectPortomentoRateConstant(unsigned int nCombi, bool bMode)
{
    if(nCombi > 3)
        return false;
    SetValue(30 + nCombi * 100, 0x80, bMode?1:0);
    return true;
}

unsigned int vzoperation::GetPitchBendRange(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(31 + nCombi * 100, 0x3F);
}

bool vzoperation::SetPitchBendRange(unsigned int nCombi, unsigned int nRange)
{
    if(nCombi > 3 || nRange > 63)
        return false;
    SetValue(31 + nCombi * 100, 0x3F, nRange);
    return true;
}

bool vzoperation::IsPitchBendRelease(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(31 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::EnablePitchBendRelease(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(31 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int vzoperation::GetAftertouchSensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(32 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(32 + nCombi * 100, 0x3F);
    else
            return -1 * (GetValue(32 + nCombi * 100, 0x3F));
}

bool vzoperation::SetAftertouchSensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(32 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(32 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool vzoperation::IsAftertouchVibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x01) != 0);
}

bool vzoperation::EnableAftertouchVibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchVibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x02) != 0);
}

bool vzoperation::EnableAftertouchVibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchPitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x04) != 0);
}

bool vzoperation::EnableAftertouchPitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchPitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x08) != 0);
}

bool vzoperation::EnableAftertouchPitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchPortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x10) != 0);
}

bool vzoperation::EnableAftertouchPortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchTremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x20) != 0);
}

bool vzoperation::EnableAftertouchTremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchTremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x40) != 0);
}

bool vzoperation::EnableAftertouchTremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool vzoperation::IsAftertouchAmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::EnableAftertouchAmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int vzoperation::GetDefWheel1Sensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(34 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(34 + nCombi * 100, 0x3F);
    else
            return -1 * (GetValue(34 + nCombi * 100, 0x3F));
}

bool vzoperation::SetDefWheel1Sensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3)
        return false;
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(34 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(34 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool vzoperation::IsDefWheel1VibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x01) != 0);
}

bool vzoperation::EnableDefWheel1VibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1VibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x02) != 0);
}

bool vzoperation::EnableDefWheel1VibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1PitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x04) != 0);
}

bool vzoperation::EnableDefWheel1PitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1PitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x08) != 0);
}

bool vzoperation::EnableDefWheel1PitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1PortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x10) != 0);
}

bool vzoperation::EnableDefWheel1PortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1TremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x20) != 0);
}

bool vzoperation::EnableDefWheel1TremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1TremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x40) != 0);
}

bool vzoperation::EnableDefWheel1TremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel1AmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::EnableDefWheel1AmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int vzoperation::GetDefWheel2Sensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(36 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(36 + nCombi * 100, 0x3F);
    else
            return -1 * (GetValue(36 + nCombi * 100, 0x3F));
}

bool vzoperation::SetDefWheel2Sensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3)
        return false;
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(36 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(36 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool vzoperation::IsDefWheel2VibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x01) != 0);
}

bool vzoperation::EnableDefWheel2VibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2VibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x02) != 0);
}

bool vzoperation::EnableDefWheel2VibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2PitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x04) != 0);
}

bool vzoperation::EnableDefWheel2PitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2PitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x08) != 0);
}

bool vzoperation::EnableDefWheel2PitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2PortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x10) != 0);
}

bool vzoperation::EnableDefWheel2PortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2TremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x20) != 0);
}

bool vzoperation::EnableDefWheel2TremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2TremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x40) != 0);
}

bool vzoperation::EnableDefWheel2TremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefWheel2AmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::EnableDefWheel2AmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int vzoperation::GetDefFootSensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(38 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(38 + nCombi * 100, 0x3F);
    else
            return -1 * (GetValue(38 + nCombi * 100, 0x3F));
}

bool vzoperation::SetDefFootSensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3)
        return false;
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(38 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(38 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool vzoperation::IsDefFootVibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x01) != 0);
}

bool vzoperation::EnableDefFootVibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootVibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x02) != 0);
}

bool vzoperation::EnableDefFootVibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootPitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x04) != 0);
}

bool vzoperation::EnableDefFootPitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootPitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x08) != 0);
}

bool vzoperation::EnableDefFootPitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootPortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x10) != 0);
}

bool vzoperation::EnableDefFootPortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootTremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x20) != 0);
}

bool vzoperation::EnableDefFootTremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootTremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x40) != 0);
}

bool vzoperation::EnableDefFootTremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool vzoperation::IsDefFootAmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x80) != 0);
}

bool vzoperation::EnableDefFootAmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

unsigned int vzoperation::GetLevel(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return (GetValue(40 + nCombi * 100, 0x3F));
}

bool vzoperation::SetLevel(unsigned int nCombi, unsigned int nLevel)
{
    if(nCombi > 3 || nLevel > 63)
        return false;
    SetValue(40 + nCombi * 100, 0x3F, nLevel);
    return true;
}

int vzoperation::GetPitch(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(42 + nCombi * 100, 0x80) != 0);
    //!@todo Do cents contribute to pitch in positive or signed direction?
    if(bSign)
        return GetValue(41 + nCombi * 100, 0xFC) + 100 * GetValue(42 + nCombi * 100, 0x3F);
    else
            return -1 * (GetValue(41 + nCombi * 100, 0xFC) + 100 * GetValue(42 + nCombi * 100, 0x3F));
}

bool vzoperation::SetPitch(unsigned int nCombi, int nPitch)
{
    if(nCombi > 3 || abs(nPitch) > 6300)
        return false;
    SetValue(41 + nCombi * 100, 0xFC, abs(nPitch) / 100);
    SetValue(42 + nCombi * 100, 0x3F, abs(nPitch) % 100);
    SetValue(42 + nCombi * 100, 0x80, (nPitch < 1)?0:1);
    return true;

}

unsigned int vzoperation::GetVelSplitMin(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(43 + nCombi * 100, 0x3F);
}

bool vzoperation::SetVelSplitMin(unsigned int nCombi, unsigned int nMin)
{
    if(nCombi > 3 || nMin > 63)
        return false;
    SetValue(43 + nCombi * 100, 0x3F, nMin);
    return true;
}

unsigned int vzoperation::GetVelSplitMax(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(44 + nCombi * 100, 0x3F);
}

bool vzoperation::SetVelSplitMax(unsigned int nCombi, unsigned int nMax)
{
    if(nCombi > 3 || nMax > 63)
        return false;
    SetValue(44 + nCombi * 100, 0x3F, nMax);
    return true;
}

unsigned int vzoperation::GetDelayTrigger(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return GetValue(45 + nCombi * 100, 0x3F);
}

bool vzoperation::SetDelayTrigger(unsigned int nCombi, unsigned int nDelay)
{
    if(nCombi > 3 || nDelay > 63)
        return false;
    SetValue(45 + nCombi * 100, 0x3F, nDelay);
    return true;
}
