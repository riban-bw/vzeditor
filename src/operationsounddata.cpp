#include "operationsounddata.h"
#include "vzsysex.h"

OperationSoundData::OperationSoundData() :
    m_nVoice(0),
    m_bVoiceCard(false),
    m_bSolo(false),
    m_bSusPedal(false),
    m_bVelInv(false),
    m_bVibInv(false),
    m_bTremInv(false),
    m_bPortamentoMode(false),
    m_nPortamentoTime(0),
    m_nPitchBendRange(0),
    m_bPitchBendRelease;(false),
    m_nAftertouchSensitivity(0),
    m_bAftertouchVibDepth(false),
    m_bAftertouchVibRate(false),
    m_bAftertouchPitchUp(false),
    m_bAftertouchPitchDown(false),
    m_bAftertouchPrtmTime(false),
    m_bAftertouchTremDepth(false),
    m_bAftertouchTremRate(false),
    m_bAftertouchAmpBias(false),
    m_nDefWheel1Sensitivity(0),
    m_bDefWheel1VibDepth(false),
    m_bDefWheel1VibRate(false),
    m_bDefWheel1PitchUp(false),
    m_bDefWheel1PitchDown(false),
    m_bDefWheel1PrtmTime(false),
    m_bDefWheel1TremDepth(false),
    m_bDefWheel1TremRate(false),
    m_bDefWheel1AmpBias(false),
    m_nDefWheel2Sensitivity(0),
    m_bDefWheel2VibDepth(false),
    m_bDefWheel2VibRate(false),
    m_bDefWheel2PitchUp(false),
    m_bDefWheel2PitchDown(false),
    m_bDefWheel2PrtmTime(false),
    m_bDefWheel2TremDepth(false),
    m_bDefWheel2TremRate(false),
    m_bDefWheel2AmpBias(false),
    m_nFootSensitivity(0),
    m_bFootVibDepth(false),
    m_bFootVibRate(false),
    m_bFootPitchUp(false),
    m_bFootPitchDown(false),
    m_bFootPrtmTime(false),
    m_bFootTremDepth(false),
    m_bFootTremRate(false),
    m_bFootAmpBias(false),
    m_nLevel(0),
    m_bPitch(false),
    m_nVelPitchMin(0),
    m_nVelPitchMax(0),
    m_nDelayTrig(0)
{
}

OperationSoundData::~OperationSoundData()
{
}

bool OperationSoundData::IsCard()
{
    return GetValue()
}

bool OperationSoundData::SelectCard(bool bCard);

unsigned OperationSoundData::int GetVoice();

bool OperationSoundData::SetVoice(unsigned int nVoice);

bool OperationSoundData::IsSolo();

bool OperationSoundData::EnableSolo(bool bSolo);

bool OperationSoundData::IsSustainPedal();

bool OperationSoundData::EnableSustainPedal(bool bEnable);

bool OperationSoundData::IsVelocityInvert();

bool OperationSoundData::EnableVelocityInvert(bool bEnable);

bool OperationSoundData::IsVibratoInvert();

bool OperationSoundData::EnableVibratoInvert(bool bEnable);

bool OperationSoundData::IsTremeloInvert();

bool OperationSoundData::EnableTremeloInvert(bool bEnable);

unsigned OperationSoundData::int GetPortamentoTime();

bool OperationSoundData::SetPortamentoTime(unsigned int pTime);

bool OperationSoundData::IsPortomentoRateConstant();

bool OperationSoundData::SelectPortomentoRateConstant(bool bMode);

unsigned OperationSoundData::int GetPitchBendRange();

bool OperationSoundData::SetPitchBendRange(unsigned int nRange);

bool OperationSoundData::IsPitchBendRelease();

bool OperationSoundData::EnablePitchBendRelease(bool bEnable);

int OperationSoundData::GetAftertouchSensitivity();

bool OperationSoundData::SetAftertouchSensitivity(int nSensitivity);

bool OperationSoundData::IsAftertouchVibratoDepth();

bool OperationSoundData::EnableAftertouchVibratoDepth(bool bEnable);

bool OperationSoundData::IsAftertouchVibratoRate();

bool OperationSoundData::EnableAftertouchVibratoRate(bool bEnable);

bool OperationSoundData::IsAftertouchPitchDown();

bool OperationSoundData::EnableAftertouchPitchDown(bool bEnable);

bool OperationSoundData::IsAftertouchPitchUp();

bool OperationSoundData::EnableAftertouchPitchUp(bool bEnable);

bool OperationSoundData::IsAftertouchPortamentoTime();

bool OperationSoundData::EnableAftertouchPortamentoTime(bool bEnable);

bool OperationSoundData::IsAftertouchTremeloDepth();

bool OperationSoundData::EnableAftertouchTremeloDepth(bool bEnable);

bool OperationSoundData::IsAftertouchTremeloRate();

bool OperationSoundData::EnableAftertouchTremeloRate(bool bEnable);

bool OperationSoundData::IsAftertouchAmplitudeBias();

bool OperationSoundData::EnableAftertouchAmplitudeBias(bool bEnable);

int OperationSoundData::GetDefWheel1Sensitivity();

bool OperationSoundData::SetDefWheel1Sensitivity(int nSensitivity);

bool OperationSoundData::IsDefWheel1VibratoDepth();

bool OperationSoundData::EnableDefWheel1VibratoDepth(bool bEnable);

bool OperationSoundData::IsDefWheel1VibratoRate();

bool OperationSoundData::EnableDefWheel1VibratoRate(bool bEnable);

bool OperationSoundData::IsDefWheel1PitchDown();

bool OperationSoundData::EnableDefWheel1PitchDown(bool bEnable);

bool OperationSoundData::IsDefWheel1PitchUp();

bool OperationSoundData::EnableDefWheel1PitchUp(bool bEnable);

bool OperationSoundData::IsDefWheel1PortamentoTime();

bool OperationSoundData::EnableDefWheel1PortamentoTime(bool bEnable);

bool OperationSoundData::IsDefWheel1TremeloDepth();

bool OperationSoundData::EnableDefWheel1TremeloDepth(bool bEnable);

bool OperationSoundData::IsDefWheel1TremeloRate();

bool OperationSoundData::EnableDefWheel1TremeloRate(bool bEnable);

bool OperationSoundData::IsDefWheel1AmplitudeBias();

bool OperationSoundData::EnableDefWheel1AmplitudeBias(bool bEnable);

int OperationSoundData::GetDefWheel2Sensitivity();

bool OperationSoundData::SetDefWheel2Sensitivity(int nSensitivity);

bool OperationSoundData::IsDefWheel2VibratoDepth();

bool OperationSoundData::EnableDefWheel2VibratoDepth(bool bEnable);

bool OperationSoundData::IsDefWheel2VibratoRate();

bool OperationSoundData::EnableDefWheel2VibratoRate(bool bEnable);

bool OperationSoundData::IsDefWheel2PitchDown();

bool OperationSoundData::EnableDefWheel2PitchDown(bool bEnable);

bool OperationSoundData::IsDefWheel2PitchUp();

bool OperationSoundData::EnableDefWheel2PitchUp(bool bEnable);

bool OperationSoundData::IsDefWheel2PortamentoTime();

bool OperationSoundData::EnableDefWheel2PortamentoTime(bool bEnable);

bool OperationSoundData::IsDefWheel2TremeloDepth();

bool OperationSoundData::EnableDefWheel2TremeloDepth(bool bEnable);

bool OperationSoundData::IsDefWheel2TremeloRate();

bool OperationSoundData::EnableDefWheel2TremeloRate(bool bEnable);

bool OperationSoundData::IsDefWheel2AmplitudeBias();

bool OperationSoundData::EnableDefWheel2AmplitudeBias(bool bEnable);

int OperationSoundData::GetDefFootSensitivity();

bool OperationSoundData::SetDefFootSensitivity(int nSensitivity);

bool OperationSoundData::IsDefFootVibratoDepth();

bool OperationSoundData::EnableDefFootVibratoDepth(bool bEnable);

bool OperationSoundData::IsDefFootVibratoRate();

bool OperationSoundData::EnableDefFootVibratoRate(bool bEnable);

bool OperationSoundData::IsDefFootPitchDown();

bool OperationSoundData::EnableDefFootPitchDown(bool bEnable);

bool OperationSoundData::IsDefFootPitchUp();

bool OperationSoundData::EnableDefFootPitchUp(bool bEnable);

bool OperationSoundData::IsDefFootPortamentoTime();

bool OperationSoundData::EnableDefFootPortamentoTime(bool bEnable);

bool OperationSoundData::IsDefFootTremeloDepth();

bool OperationSoundData::EnableDefFootTremeloDepth(bool bEnable);

bool OperationSoundData::IsDefFootTremeloRate();

bool OperationSoundData::EnableDefFootTremeloRate(bool bEnable);

bool OperationSoundData::IsDefFootAmplitudeBias();

bool OperationSoundData::EnableDefFootAmplitudeBias(bool bEnable);

unsigned int OperationSoundData::GetLevel();

bool OperationSoundData::SetLevel(unsigned int nLevel);

int OperationSoundData::GetPitch();

bool OperationSoundData::SetPitch(int nPitch);

unsigned int OperationSoundData::GetVelSplitMin();

bool OperationSoundData::SetVelSplitMin(unsigned int nMin);

unsigned int OperationSoundData::GetVelSplitMax();

bool OperationSoundData::SetVelSplitMax(unsigned int nMax);

unsigned int OperationSoundData::GetDelayTrigger();

bool OperationSoundData::GetDelayTrigger(unsigned int nDelay);
