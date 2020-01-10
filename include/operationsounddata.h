#ifndef OPERATIONSOUNDDATA_H
#define OPERATIONSOUNDDATA_H


class OperationSoundData
{
    public:
        OperationSoundData();
        virtual ~OperationSoundData();

        /** @brief  Is voice in internal memory on on external card
        *   @retval bool True if voice on card
        */
        bool IsCard();

        /** @brief  Select internal or external card voice
        *   @param  bCard True to select voice on card
        *   @retval bool True on success
        */
        bool SelectCard(bool bCard);

        /** @brief  Get voice
        *   @retval unsigned int Voice number
        */
        unsigned int GetVoice();

        /** @brief  Set voice
        *   @param  nVoice Voice number
        *   @retval bool True on success
        */
        bool SetVoice(unsigned int nVoice);

        /** @brief  Is solo mode enabled
        *   @retval bool True if solo mode enabled
        */
        bool IsSolo();

        /** @brief  Select solo mode
        *   @param  bSolo True to enable solo mode
        *   @retval bool True on success
        */
        bool EnableSolo(bool bSolo);

        /** @brief  Is sustain pedal enabled
        *   @retval bool True if sustain pedal enabled
        */
        bool IsSustainPedal();

        /** @brief  Select sustain pedal enabled
        *   @param  bEnable True to enable sustain pedal
        *   @retval bool True on success
        */
        bool EnableSustainPedal(bool bEnable);

        /** @brief  Is velocity invert enabled
        *   @retval bool True if velocity invert enabled
        */
        bool IsVelocityInvert();

        /** @brief  Enable velocity invert
        *   @param  bEnable True to enable velocity invert
        *   @retval bool True on success
        */
        bool EnableVelocityInvert(bool bEnable);

        /** @brief  Is vibrato invert enabled
        *   @retval bool True if vibrato invert enabled
        */
        bool IsVibratoInvert();

        /** @brief  Enable vibrato invert
        *   @param bEnable True to enable vibrato invert
        *   @retval bool True on success
        */
        bool EnableVibratoInvert(bool bEnable);

        /** @brief  Is tremelo invert enabled
        *   @retval bool True if tremelo invert enabled
        */
        bool IsTremeloInvert();

        /** @brief  Enable tremelo invert
        *   @param bEnable True to enable tremelo invert
        *   @retval bool True on success
        */
        bool EnableTremeloInvert(bool bEnable);

        /** @brief  Get portamento time
        *   @retval unsigned int Portamento time
        */
        unsigned int GetPortamentoTime();

        /** @brief  Set portamento time
        *   @param  pTime Portamento time
        *   @retval bool True on success
        */
        bool SetPortamentoTime(unsigned int pTime);

        /** @brief  Is portamento mode time or rate constant
        *   @retval bool True if portamento is rate constant. False if time constant
        */
        bool IsPortomentoRateConstant();

        /** @brief  Select portamento mode time or rate constant
        *   @param  bMode True to select rate constant. False to select time constant
        *   @retval bool True on success
        */
        bool SelectPortomentoRateConstant(bool bMode);

        /** @brief  Get pitch bend range
        *   @retval unsigned int Pitch bend range
        */
        unsigned int GetPitchBendRange();

        /** @brief  Set pitch bend range
        *   @param  nRange Pitch bend range
        *   @retval bool True on success
        */
        bool SetPitchBendRange(unsigned int nRange);

        /** @brief  Is pitch bend release enabled
        *   @retval bool True if pitch bend release is enabled
        */
        bool IsPitchBendRelease();

        /** @brief  Enable pitch bend release
        *   @param  bEnable True to enable pitch bend release
        *   @retval bool True on success
        */
        bool EnablePitchBendRelease(bool bEnable);

        /** @brief  Get aftertouch sensitivity
        *   @retval int Aftertouch sensitivity
        */
        int GetAftertouchSensitivity();

        /** @brief  Set aftertouch sensitivity
        *   @param  nSensitivity Aftertouch sensitivity
        *   @retval bool True on success
        */
        bool SetAftertouchSensitivity(int nSensitivity);

        /** @brief  Does aftertouch affect vibrato depth
        *   @retval bool True if aftertouch affects vibrato depth
        */
        bool IsAftertouchVibratoDepth();

        /** @brief  Enable aftertouch affect on vibrato depth
        *   @param  bEnable True to enable aftertouch affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableAftertouchVibratoDepth(bool bEnable);

        /** @brief  Does aftertouch affect vibrato rate
        *   @retval bool True if aftertouch affects vibrato rate
        */
        bool IsAftertouchVibratoRate();

        /** @brief  Enable aftertouch affect on vibrato rate
        *   @param  bEnable True to enable aftertouch affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableAftertouchVibratoRate(bool bEnable);

        /** @brief  Does aftertouch bend pitch down
        *   @retval bool True if aftertouch bends pitch down
        */
        bool IsAftertouchPitchDown();

        /** @brief  Enable aftertouch bend pitch down
        *   @param  bEnable True to enable aftertouch bends pitch down
        *   @retval bool True on success
        */
        bool EnableAftertouchPitchDown(bool bEnable);

        /** @brief  Does aftertouch bend pitch up
        *   @retval bool True if aftertouch bends pitch up
        */
        bool IsAftertouchPitchUp();

        /** @brief  Enable aftertouch bend pitch up
        *   @param  bEnable True to enable aftertouch bends pitch up
        *   @retval bool True on success
        */
        bool EnableAftertouchPitchUp(bool bEnable);

        /** @brief  Does aftertouch affect portamento time
        *   @retval bool True if aftertouch affects portamento time
        */
        bool IsAftertouchPortamentoTime();

        /** @brief  Enable aftertouch affect on portamento time
        *   @param  bEnable True to enable aftertouch affect on portamento time
        *   @retval bool True on success
        */
        bool EnableAftertouchPortamentoTime(bool bEnable);

        /** @brief  Does aftertouch affect tremelo depth
        *   @retval bool True if aftertouch affects tremelo depth
        */
        bool IsAftertouchTremeloDepth();

        /** @brief  Enable aftertouch affect on tremelo depth
        *   @param  bEnable True to enable aftertouch affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableAftertouchTremeloDepth(bool bEnable);

        /** @brief  Does aftertouch affect tremelo rate
        *   @retval bool True if aftertouch affects tremelo rate
        */
        bool IsAftertouchTremeloRate();

        /** @brief  Enable aftertouch affect on tremelo rate
        *   @param  bEnable True to enable aftertouch affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableAftertouchTremeloRate(bool bEnable);

        /** @brief  Does aftertouch affect amplitude bias
        *   @retval bool True if aftertouch affects amplitude bias
        */
        bool IsAftertouchAmplitudeBias();

        /** @brief  Enable aftertouch affect on amplitude bias
        *   @param  bBenable True to enable aftertouch affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableAftertouchAmplitudeBias(bool bEnable);

        /** @brief  Get definable wheel 1 sensitivity
        *   @retval int DefWheel1 sensitivity
        */
        int GetDefWheel1Sensitivity();

        /** @brief  Set definable wheel 1 sensitivity
        *   @param  nSensitivity DefWheel1 sensitivity
        *   @retval bool True on success
        */
        bool SetDefWheel1Sensitivity(int nSensitivity);

        /** @brief  Does definable wheel 1 affect vibrato depth
        *   @retval bool True if definable wheel 1 affects vibrato depth
        */
        bool IsDefWheel1VibratoDepth();

        /** @brief  Enable definable wheel 1 affect on vibrato depth
        *   @param  bEnable True to enable definable wheel 1 affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableDefWheel1VibratoDepth(bool bEnable);

        /** @brief  Does definable wheel 1 affect vibrato rate
        *   @retval bool True if definable wheel 1 affects vibrato rate
        */
        bool IsDefWheel1VibratoRate();

        /** @brief  Enable definable wheel 1 affect on vibrato rate
        *   @param  bEnable True to enable definable wheel 1 affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableDefWheel1VibratoRate(bool bEnable);

        /** @brief  Does definable wheel 1 bend pitch down
        *   @retval bool True if definable wheel 1 bends pitch down
        */
        bool IsDefWheel1PitchDown();

        /** @brief  Enable definable wheel 1 bend pitch down
        *   @param  bEnable True to enable definable wheel 1 bends pitch down
        *   @retval bool True on success
        */
        bool EnableDefWheel1PitchDown(bool bEnable);

        /** @brief  Does definable wheel 1 bend pitch up
        *   @retval bool True if definable wheel 1 bends pitch up
        */
        bool IsDefWheel1PitchUp();

        /** @brief  Enable definable wheel 1 bend pitch up
        *   @param  bEnable True to enable definable wheel 1 bends pitch up
        *   @retval bool True on success
        */
        bool EnableDefWheel1PitchUp(bool bEnable);

        /** @brief  Does definable wheel 1 affect portamento time
        *   @retval bool True if definable wheel 1 affects portamento time
        */
        bool IsDefWheel1PortamentoTime();

        /** @brief  Enable definable wheel 1 affect on portamento time
        *   @param  bEnable True to enable definable wheel 1 affect on portamento time
        *   @retval bool True on success
        */
        bool EnableDefWheel1PortamentoTime(bool bEnable);

        /** @brief  Does definable wheel 1 affect tremelo depth
        *   @retval bool True if definable wheel 1 affects tremelo depth
        */
        bool IsDefWheel1TremeloDepth();

        /** @brief  Enable definable wheel 1 affect on tremelo depth
        *   @param  bEnable True to enable definable wheel 1 affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableDefWheel1TremeloDepth(bool bEnable);

        /** @brief  Does definable wheel 1 affect tremelo rate
        *   @retval bool True if definable wheel 1 affects tremelo rate
        */
        bool IsDefWheel1TremeloRate();

        /** @brief  Enable definable wheel 1 affect on tremelo rate
        *   @param  bEnable True to enable definable wheel 1 affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableDefWheel1TremeloRate(bool bEnable);

        /** @brief  Does definable wheel 1 affect amplitude bias
        *   @retval bool True if definable wheel 1 affects amplitude bias
        */
        bool IsDefWheel1AmplitudeBias();

        /** @brief  Enable definable wheel 1 affect on amplitude bias
        *   @param  bBenable True to enable definable wheel 1 affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableDefWheel1AmplitudeBias(bool bEnable);

        /** @brief  Get definable wheel 2 sensitivity
        *   @retval int DefWheel2 sensitivity
        */
        int GetDefWheel2Sensitivity();

        /** @brief  Set definable wheel 2 sensitivity
        *   @param  nSensitivity DefWheel2 sensitivity
        *   @retval bool True on success
        */
        bool SetDefWheel2Sensitivity(int nSensitivity);

        /** @brief  Does definable wheel 2 affect vibrato depth
        *   @retval bool True if definable wheel 2 affects vibrato depth
        */
        bool IsDefWheel2VibratoDepth();

        /** @brief  Enable definable wheel 2 affect on vibrato depth
        *   @param  bEnable True to enable definable wheel 2 affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableDefWheel2VibratoDepth(bool bEnable);

        /** @brief  Does definable wheel 2 affect vibrato rate
        *   @retval bool True if definable wheel 2 affects vibrato rate
        */
        bool IsDefWheel2VibratoRate();

        /** @brief  Enable definable wheel 2 affect on vibrato rate
        *   @param  bEnable True to enable definable wheel 2 affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableDefWheel2VibratoRate(bool bEnable);

        /** @brief  Does definable wheel 2 bend pitch down
        *   @retval bool True if definable wheel 2 bends pitch down
        */
        bool IsDefWheel2PitchDown();

        /** @brief  Enable definable wheel 2 bend pitch down
        *   @param  bEnable True to enable definable wheel 2 bends pitch down
        *   @retval bool True on success
        */
        bool EnableDefWheel2PitchDown(bool bEnable);

        /** @brief  Does definable wheel 2 bend pitch up
        *   @retval bool True if definable wheel 2 bends pitch up
        */
        bool IsDefWheel2PitchUp();

        /** @brief  Enable definable wheel 2 bend pitch up
        *   @param  bEnable True to enable definable wheel 2 bends pitch up
        *   @retval bool True on success
        */
        bool EnableDefWheel2PitchUp(bool bEnable);

        /** @brief  Does definable wheel 2 affect portamento time
        *   @retval bool True if definable wheel 2 affects portamento time
        */
        bool IsDefWheel2PortamentoTime();

        /** @brief  Enable definable wheel 2 affect on portamento time
        *   @param  bEnable True to enable definable wheel 2 affect on portamento time
        *   @retval bool True on success
        */
        bool EnableDefWheel2PortamentoTime(bool bEnable);

        /** @brief  Does definable wheel 2 affect tremelo depth
        *   @retval bool True if definable wheel 2 affects tremelo depth
        */
        bool IsDefWheel2TremeloDepth();

        /** @brief  Enable definable wheel 2 affect on tremelo depth
        *   @param  bEnable True to enable definable wheel 2 affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableDefWheel2TremeloDepth(bool bEnable);

        /** @brief  Does definable wheel 2 affect tremelo rate
        *   @retval bool True if definable wheel 2 affects tremelo rate
        */
        bool IsDefWheel2TremeloRate();

        /** @brief  Enable definable wheel 2 affect on tremelo rate
        *   @param  bEnable True to enable definable wheel 2 affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableDefWheel2TremeloRate(bool bEnable);

        /** @brief  Does definable wheel 2 affect amplitude bias
        *   @retval bool True if definable wheel 2 affects amplitude bias
        */
        bool IsDefWheel2AmplitudeBias();

        /** @brief  Enable definable wheel 2 affect on amplitude bias
        *   @param  bBenable True to enable definable wheel 2 affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableDefWheel2AmplitudeBias(bool bEnable);

        /** @brief  Get definable foot controller sensitivity
        *   @retval int DefFoot sensitivity
        */
        int GetDefFootSensitivity();

        /** @brief  Set definable foot controller sensitivity
        *   @param  nSensitivity DefFoot sensitivity
        *   @retval bool True on success
        */
        bool SetDefFootSensitivity(int nSensitivity);

        /** @brief  Does definable foot controller affect vibrato depth
        *   @retval bool True if definable foot controller affects vibrato depth
        */
        bool IsDefFootVibratoDepth();

        /** @brief  Enable definable foot controller affect on vibrato depth
        *   @param  bEnable True to enable definable foot controller affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableDefFootVibratoDepth(bool bEnable);

        /** @brief  Does definable foot controller affect vibrato rate
        *   @retval bool True if definable foot controller affects vibrato rate
        */
        bool IsDefFootVibratoRate();

        /** @brief  Enable definable foot controller affect on vibrato rate
        *   @param  bEnable True to enable definable foot controller affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableDefFootVibratoRate(bool bEnable);

        /** @brief  Does definable foot controller bend pitch down
        *   @retval bool True if definable foot controller bends pitch down
        */
        bool IsDefFootPitchDown();

        /** @brief  Enable definable foot controller bend pitch down
        *   @param  bEnable True to enable definable foot controller bends pitch down
        *   @retval bool True on success
        */
        bool EnableDefFootPitchDown(bool bEnable);

        /** @brief  Does definable foot controller bend pitch up
        *   @retval bool True if definable foot controller bends pitch up
        */
        bool IsDefFootPitchUp();

        /** @brief  Enable definable foot controller bend pitch up
        *   @param  bEnable True to enable definable foot controller bends pitch up
        *   @retval bool True on success
        */
        bool EnableDefFootPitchUp(bool bEnable);

        /** @brief  Does definable foot controller affect portamento time
        *   @retval bool True if definable foot controller affects portamento time
        */
        bool IsDefFootPortamentoTime();

        /** @brief  Enable definable foot controller affect on portamento time
        *   @param  bEnable True to enable definable foot controller affect on portamento time
        *   @retval bool True on success
        */
        bool EnableDefFootPortamentoTime(bool bEnable);

        /** @brief  Does definable foot controller affect tremelo depth
        *   @retval bool True if definable foot controller affects tremelo depth
        */
        bool IsDefFootTremeloDepth();

        /** @brief  Enable definable foot controller affect on tremelo depth
        *   @param  bEnable True to enable definable foot controller affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableDefFootTremeloDepth(bool bEnable);

        /** @brief  Does definable foot controller affect tremelo rate
        *   @retval bool True if definable foot controller affects tremelo rate
        */
        bool IsDefFootTremeloRate();

        /** @brief  Enable definable foot controller affect on tremelo rate
        *   @param  bEnable True to enable definable foot controller affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableDefFootTremeloRate(bool bEnable);

        /** @brief  Does definable foot controller affect amplitude bias
        *   @retval bool True if definable foot controller affects amplitude bias
        */
        bool IsDefFootAmplitudeBias();

        /** @brief  Enable definable foot controller affect on amplitude bias
        *   @param  bBenable True to enable definable foot controller affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableDefFootAmplitudeBias(bool bEnable);

        /** @brief  Get volume level
        *   @retval unsigned int Volume level
        */
        unsigned int GetLevel();

        /** @brief  Set volume level
        *   @param  nLevel Volume level
        *   @retval bool True on success
        */
        bool SetLevel(unsigned int nLevel);

        /** @brief  Get pitch offset
        *   @retval int Pitch [+/-63 notes in cents]
        */
        int GetPitch();

        /** @brief  Set pitch offset
        *   @param  nPitch Pitch [+/-63 notes in cents]
        *   @retval bool True on success
        */
        bool SetPitch(int nPitch);

        /** @brief  Get velocity split range minimum
        *   @retval unsigned int Minimum velocity split value
        */
        unsigned int GetVelSplitMin();

        /** @brief  Set velocity split range minimum
        *   @param  nMin Minimum velocity split value
        *   @retval bool True on success
        */
        bool SetVelSplitMin(unsigned int nMin);

        /** @brief  Get velocity split range maximum
        *   @retval unsigned int Maximum velocity split value
        */
        unsigned int GetVelSplitMax();

        /** @brief  Set velocity split range maximum
        *   @param  nMax Maximum velocity split value
        *   @retval bool True on success
        */
        bool SetVelSplitMax(unsigned int nMax);

        /** @brief  Get delay trigger
        *   @retval unsigned int Delay trigger value
        */
        unsigned int GetDelayTrigger();

        /** @brief  Set delay trigger
        *   @param  nDelay Delay trigger value
        *   @retval bool True on success
        */
        bool GetDelayTrigger(unsigned int nDelay);

    protected:

    private:
        unsigned int m_nVoice;
        bool m_bVoiceCard; // True if voice is on card. False if voice is in internal memory
        bool m_bSolo;
        bool m_bSusPedal;
        bool m_bVelInv;
        bool m_bVibInv;
        bool m_bTremInv;
        bool m_bPortamentoMode;
        unsigned int m_nPortamentoTime;
        unsigned int m_nPitchBendRange;
        bool m_bPitchBendRelease;
        int m_nAftertouchSensitivity;
        bool m_bAftertouchVibDepth;
        bool m_bAftertouchVibRate;
        bool m_bAftertouchPitchUp;
        bool m_bAftertouchPitchDown;
        bool m_bAftertouchPrtmTime;
        bool m_bAftertouchTremDepth;
        bool m_bAftertouchTremRate;
        bool m_bAftertouchAmpBias;
        int  m_nDefWheel1Sensitivity;
        bool m_bDefWheel1VibDepth;
        bool m_bDefWheel1VibRate;
        bool m_bDefWheel1PitchUp;
        bool m_bDefWheel1PitchDown;
        bool m_bDefWheel1PrtmTime;
        bool m_bDefWheel1TremDepth;
        bool m_bDefWheel1TremRate;
        bool m_bDefWheel1AmpBias;
        int  m_nDefWheel2Sensitivity;
        bool m_bDefWheel2VibDepth;
        bool m_bDefWheel2VibRate;
        bool m_bDefWheel2PitchUp;
        bool m_bDefWheel2PitchDown;
        bool m_bDefWheel2PrtmTime;
        bool m_bDefWheel2TremDepth;
        bool m_bDefWheel2TremRate;
        bool m_bDefWheel2AmpBias;
        int  m_nFootSensitivity;
        bool m_bFootVibDepth;
        bool m_bFootVibRate;
        bool m_bFootPitchUp;
        bool m_bFootPitchDown;
        bool m_bFootPrtmTime;
        bool m_bFootTremDepth;
        bool m_bFootTremRate;
        bool m_bFootAmpBias;
        unsigned int m_nLevel;
        int m_bPitch;
        unsigned int m_nVelPitchMin;
        unsigned int m_nVelPitchMax;
        unsigned int m_nDelayTrig;

};

#endif // OPERATIONSOUNDDATA_H
