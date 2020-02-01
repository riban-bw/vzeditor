/***************************************************************
 * Name:      vzoperation.h
 * Purpose:   Implements VZOperation class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2019-01-10
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "vzoperation.h"

VZOperation::VZOperation() :
    VZSysex(VZ_OPERATION_PAYLOAD_SIZE)
{
    Validate(true);
}

VZOperation::VZOperation(wxByte* pData, bool bPayload) :
    VZSysex(VZ_OPERATION_PAYLOAD_SIZE, pData, bPayload)
{
    Validate(true);
    m_bModified = false;
}

VZOperation::~VZOperation()
{
}

bool VZOperation::Validate(bool bFix)
{
    VZSysex::Validate(bFix);
    m_bModified |= ValidateByte(m_pSysEx + 5, 0x01, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 6, 0x40, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 7 + m_nPayloadSize, Checksum(m_pSysEx + 7, m_nPayloadSize), bFix);
    return m_bModified;
}

unsigned int VZOperation::GetMode()
{
    return GetValue(0, 0x0F);
}

bool VZOperation::SetMode(unsigned int nMode)
{
    if(nMode > 8)
        return false;
    SetValue(0, 0x0F, nMode);
    return true;
}

wxString VZOperation::GetName()
{
    wxString sName;
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
    {
        sName += wxString::FromAscii(GetByteFromSysex(1 + nIndex));
    }
    return sName.Trim();
}

void VZOperation::SetName(wxString sName)
{
    sName.Truncate(12);
    sName.Pad(12 - sName.Length());
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
        PutByteToSysex(1 + nIndex, sName[nIndex]);
}

bool VZOperation::IsXfade()
{
    return 0x02 == (GetByteFromSysex(15) & 0x02);
}

bool VZOperation::EnableXfade(bool bEnable)
{
    PutByteToSysex(15, bEnable?0x02:0x00);
    return true;
}

unsigned int VZOperation::GetSplitPoint(unsigned int nPoint)
{
    if(nPoint > 3)
        return 0;
    return (GetByteFromSysex(16 + nPoint) & 0x7F);
}

bool VZOperation::SetSplitPoint(unsigned int nPoint, unsigned int nKey)
{
    if(nPoint > 3 || nKey > 0x7F)
        return false;
    PutByteToSysex(16 + nPoint, nKey);
    return true;
}

unsigned int VZOperation::GetXfadeMin(unsigned int nPoint)
{
    if(nPoint > 3)
        return 0;
    return GetByteFromSysex(20 + nPoint * 2);
}

bool VZOperation::SetXfadeMin(unsigned int nPoint, unsigned int nValue)
{
    if(nPoint > 3 || nValue > 0x78)
        return false;
    PutByteToSysex(20 + nPoint * 2, nValue);
    return true;
}

unsigned int VZOperation::GetXfadeMax(unsigned int nPoint)
{
    if(nPoint > 3)
        return 0;
    return GetByteFromSysex(21 + nPoint * 2);
}

bool VZOperation::SetXfadeMax(unsigned int nPoint, unsigned int nValue)
{
    if(nPoint > 3 || nValue > 0x78)
        return false;
    PutByteToSysex(21 + nPoint * 2, nValue);
    return true;
}

bool VZOperation::IsCard(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(28 + nCombi * 100, 0x40) != 0);
}

bool VZOperation::SelectCard(unsigned int nCombi, bool bCard)
{
    if(nCombi > 3)
        return false;
    SetValue(28 + nCombi * 100, 0x40, bCard?1:0);
    return true;
}


unsigned int VZOperation::GetVoice(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(28 + nCombi * 100, 0x3F);
}

bool VZOperation::SetVoice(unsigned int nCombi, unsigned int nVoice)
{
    if(nCombi > 3 || nVoice > 63)
        return false;
    SetValue(28 + nCombi * 100, 0x3F, nVoice);
    return true;
}

bool VZOperation::IsSolo(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x08) != 0);
}

bool VZOperation::EnableSolo(unsigned int nCombi, bool bSolo)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x08, bSolo?1:0);
    return true;
}

bool VZOperation::IsSustainPedal(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x10) != 0);
}

bool VZOperation::EnableSustainPedal(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool VZOperation::IsVelocityInvert(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x20) != 0);
}

bool VZOperation::EnableVelocityInvert(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool VZOperation::IsVibratoInvert(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x40) != 0);
}

bool VZOperation::EnableVibratoInvert(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool VZOperation::IsTremeloInvert(unsigned int nCombi) //!@todo Is this tremelo invert or inverse?
{
    if(nCombi > 3)
        return false;
    return (GetValue(29 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::EnableTremeloInvert(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(29 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

unsigned int VZOperation::GetPortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(30 + nCombi * 100, 0x3F);
}

bool VZOperation::SetPortamentoTime(unsigned int nCombi, unsigned int nTime)
{
    if(nCombi > 3 || nTime > 63)
        return false;
    SetValue(30 + nCombi * 100, 0x3F, nTime);
    return true;
}

bool VZOperation::IsPortomentoRateConstant(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(30 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::SelectPortomentoRateConstant(unsigned int nCombi, bool bMode)
{
    if(nCombi > 3)
        return false;
    SetValue(30 + nCombi * 100, 0x80, bMode?1:0);
    return true;
}

unsigned int VZOperation::GetPitchBendRange(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(31 + nCombi * 100, 0x3F);
}

bool VZOperation::SetPitchBendRange(unsigned int nCombi, unsigned int nRange)
{
    if(nCombi > 3 || nRange > 63)
        return false;
    SetValue(31 + nCombi * 100, 0x3F, nRange);
    return true;
}

bool VZOperation::IsPitchBendRelease(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(31 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::EnablePitchBendRelease(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(31 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int VZOperation::GetAftertouchSensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(32 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(32 + nCombi * 100, 0x3F);
    else
        return -1 * (GetValue(32 + nCombi * 100, 0x3F));
}

bool VZOperation::SetAftertouchSensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(32 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(32 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool VZOperation::IsAftertouchVibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x01) != 0);
}

bool VZOperation::EnableAftertouchVibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchVibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x02) != 0);
}

bool VZOperation::EnableAftertouchVibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchPitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x04) != 0);
}

bool VZOperation::EnableAftertouchPitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchPitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x08) != 0);
}

bool VZOperation::EnableAftertouchPitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchPortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x10) != 0);
}

bool VZOperation::EnableAftertouchPortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchTremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x20) != 0);
}

bool VZOperation::EnableAftertouchTremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchTremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x40) != 0);
}

bool VZOperation::EnableAftertouchTremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool VZOperation::IsAftertouchAmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(33 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::EnableAftertouchAmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(33 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int VZOperation::GetDefWheel1Sensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(34 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(34 + nCombi * 100, 0x3F);
    else
        return -1 * (GetValue(34 + nCombi * 100, 0x3F));
}

bool VZOperation::SetDefWheel1Sensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3)
        return false;
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(34 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(34 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool VZOperation::IsDefWheel1VibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x01) != 0);
}

bool VZOperation::EnableDefWheel1VibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1VibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x02) != 0);
}

bool VZOperation::EnableDefWheel1VibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1PitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x04) != 0);
}

bool VZOperation::EnableDefWheel1PitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1PitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x08) != 0);
}

bool VZOperation::EnableDefWheel1PitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1PortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x10) != 0);
}

bool VZOperation::EnableDefWheel1PortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1TremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x20) != 0);
}

bool VZOperation::EnableDefWheel1TremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1TremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x40) != 0);
}

bool VZOperation::EnableDefWheel1TremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel1AmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(35 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::EnableDefWheel1AmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(35 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int VZOperation::GetDefWheel2Sensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(36 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(36 + nCombi * 100, 0x3F);
    else
        return -1 * (GetValue(36 + nCombi * 100, 0x3F));
}

bool VZOperation::SetDefWheel2Sensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3)
        return false;
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(36 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(36 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool VZOperation::IsDefWheel2VibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x01) != 0);
}

bool VZOperation::EnableDefWheel2VibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2VibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x02) != 0);
}

bool VZOperation::EnableDefWheel2VibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2PitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x04) != 0);
}

bool VZOperation::EnableDefWheel2PitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2PitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x08) != 0);
}

bool VZOperation::EnableDefWheel2PitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2PortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x10) != 0);
}

bool VZOperation::EnableDefWheel2PortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2TremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x20) != 0);
}

bool VZOperation::EnableDefWheel2TremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2TremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x40) != 0);
}

bool VZOperation::EnableDefWheel2TremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefWheel2AmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(37 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::EnableDefWheel2AmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(37 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

int VZOperation::GetDefFootSensitivity(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    bool bSign = (GetValue(38 + nCombi * 100, 0x80) != 0);
    if(bSign)
        return GetValue(38 + nCombi * 100, 0x3F);
    else
        return -1 * (GetValue(38 + nCombi * 100, 0x3F));
}

bool VZOperation::SetDefFootSensitivity(unsigned int nCombi, int nSensitivity)
{
    if(nCombi > 3)
        return false;
    if(nCombi > 3 || abs(nSensitivity) > 63)
        return false;
    SetValue(38 + nCombi * 100, 0x3F, abs(nSensitivity));
    SetValue(38 + nCombi * 100, 0x80, (nSensitivity < 1)?0:1);
    return true;
}

bool VZOperation::IsDefFootVibratoDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x01) != 0);
}

bool VZOperation::EnableDefFootVibratoDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x01, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootVibratoRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x02) != 0);
}

bool VZOperation::EnableDefFootVibratoRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x02, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootPitchDown(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x04) != 0);
}

bool VZOperation::EnableDefFootPitchDown(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x04, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootPitchUp(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x08) != 0);
}

bool VZOperation::EnableDefFootPitchUp(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x08, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootPortamentoTime(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x10) != 0);
}

bool VZOperation::EnableDefFootPortamentoTime(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x10, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootTremeloDepth(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x20) != 0);
}

bool VZOperation::EnableDefFootTremeloDepth(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x20, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootTremeloRate(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x40) != 0);
}

bool VZOperation::EnableDefFootTremeloRate(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x40, bEnable?1:0);
    return true;
}

bool VZOperation::IsDefFootAmplitudeBias(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return (GetValue(39 + nCombi * 100, 0x80) != 0);
}

bool VZOperation::EnableDefFootAmplitudeBias(unsigned int nCombi, bool bEnable)
{
    if(nCombi > 3)
        return false;
    SetValue(39 + nCombi * 100, 0x80, bEnable?1:0);
    return true;
}

unsigned int VZOperation::GetLevel(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return (GetValue(40 + nCombi * 100, 0x3F));
}

bool VZOperation::SetLevel(unsigned int nCombi, unsigned int nLevel)
{
    if(nCombi > 3 || nLevel > 63)
        return false;
    SetValue(40 + nCombi * 100, 0x3F, nLevel);
    return true;
}

int VZOperation::GetPitch(unsigned int nCombi)
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

bool VZOperation::SetPitch(unsigned int nCombi, int nPitch)
{
    if(nCombi > 3 || abs(nPitch) > 6300)
        return false;
    SetValue(41 + nCombi * 100, 0xFC, abs(nPitch) / 100);
    SetValue(42 + nCombi * 100, 0x3F, abs(nPitch) % 100);
    SetValue(42 + nCombi * 100, 0x80, (nPitch < 1)?0:1);
    return true;

}

unsigned int VZOperation::GetVelSplitMin(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(43 + nCombi * 100, 0x3F);
}

bool VZOperation::SetVelSplitMin(unsigned int nCombi, unsigned int nMin)
{
    if(nCombi > 3 || nMin > 63)
        return false;
    SetValue(43 + nCombi * 100, 0x3F, nMin);
    return true;
}

unsigned int VZOperation::GetVelSplitMax(unsigned int nCombi)
{
    if(nCombi > 3)
        return 0;
    return GetValue(44 + nCombi * 100, 0x3F);
}

bool VZOperation::SetVelSplitMax(unsigned int nCombi, unsigned int nMax)
{
    if(nCombi > 3 || nMax > 63)
        return false;
    SetValue(44 + nCombi * 100, 0x3F, nMax);
    return true;
}

unsigned int VZOperation::GetDelayTrigger(unsigned int nCombi)
{
    if(nCombi > 3)
        return false;
    return GetValue(45 + nCombi * 100, 0x3F);
}

bool VZOperation::SetDelayTrigger(unsigned int nCombi, unsigned int nDelay)
{
    if(nCombi > 3 || nDelay > 63)
        return false;
    SetValue(45 + nCombi * 100, 0x3F, nDelay);
    return true;
}
