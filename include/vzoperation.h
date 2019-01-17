#ifndef VZOPERATION_H
#define VZOPERATION_H

#define VZ_OPERATION_PAYLOAD_SIZE 200 //Size of sysex operation payload in bytes
#define VZ_TYPE_OPERATION 0x01

#include "vzsysex.h"

/** Provides interface to VZ SysEx operation data
*   @note   Data is stored as raw SysEx data
*/
class vzoperation : public vzsysex
{
    public:
        /** @brief  Construct vzoperation object
        *   @note   Initialises operation data to defaults
        */
        vzoperation();

        /** @brief  Construct vzoperation object from existing SysEx data
        *   @param  Data Pointer to a buffer containing raw SysEx operation data
        *   @param  bPayload True if pData contains payload only (create default header and footer) [Default: false]
        *   @note   Initialises any invalid values to defaults and sets modified field
        */
        vzoperation(wxByte* pData, bool bPayload = false);

        /** @brief  Default destruct vzoperation object
        */
        virtual ~vzoperation();

        /** @brief  Validates raw SysEx sysex data
        *   @param  bFix True to initialise invalid data
        *   @retval bool True if data is valid
        */
        bool Validate(bool bFix = false);

        /** @brief  Get the mode/assign value
        *   @retval unsigned int Mode
        */
        unsigned int GetMode();

        /** @brief  Set the mode/assign
        *   @param  nMode Mode [0..8]
        *   @retval bool True on success
        */
        bool SetMode(unsigned int nMode);

        /** @brief  Gets the operation data name
        *   @retval wxString Name of the operation data
        */
        wxString GetName();

        /** @brief  Sets the operation data  name
        *   @param wxString Name of the operation data
        */
        void SetName(wxString sName);

        /** @brief  Is positional cross-fade effect enabled
        *   @retval bool True if effect enabled
        */
        bool IsXfade();

        /** @brief  Enable positional cross-fade effect
        *   @param  bEnable True to enable
        *   @retval bool True on success
        */
        bool EnableXfade(bool bEnable);

        /** @brief  Get split point
        *   @param  nPoint [0 for 1 point split, 1 for low, 2 for mid, 3 for upper]
        *   @retval unsigned int Key value of split point
        */
        unsigned int GetSplitPoint(unsigned int nPoint);

        /** @brief  Set split point
        *   @param  nPoint [0 for 1 point split, 1 for low, 2 for mid, 3 for upper]
        *   @param  nKey Key value for the set point [0..120]
        *   @retval bool True on success
        */
        bool SetSplitPoint(unsigned int nPoint, unsigned int nKey);

        /** @brief  Get positional cross-fade minimum mix value
        *   @param  nPoint Crosspoint
        *   @retval unsigned int Minimum mix value of this crosspoint
        */
        unsigned int GetXfadeMin(unsigned int nPoint);

        /** @brief  Set positional cross-fade minimum mix value
        *   @param  nPoint Crosspoint
        *   @param  nValue Minimum value
        *   @retval bool True on success
        */
        bool SetXfadeMin(unsigned int nPoint, unsigned int nValue);

        /** @brief  Get positional cross-fade maximum mix value
        *   @param  nPoint Crosspoint
        *   @retval unsigned int Maximum mix value of this crosspoint
        */
        unsigned int GetXfadeMax(unsigned int nPoint);

        /** @brief  Set positional cross-fade maximum mix value
        *   @param  nPoint Crosspoint
        *   @param  nValue Maximum value
        *   @retval bool True on success
        */
        bool SetXfadeMax(unsigned int nPoint, unsigned int nValue);

        /** @brief  Is voice in internal memory on on external card
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if voice on card
        */
        bool IsCard(unsigned int nCombi);

        /** @brief  Select internal or external card voice
        *   @param  nCombi voice index [0-3]
        *   @param  bCard True to select voice on card
        *   @retval bool True on success
        */
        bool SelectCard(unsigned int nCombi, bool bCard);


        /** @brief  Get voice
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Voice number
        */
        unsigned int GetVoice(unsigned int nCombi);

        /** @brief  Set voice
        *   @param  nCombi voice index [0-3]
        *   @param  nVoice Voice number
        *   @retval bool True on success
        */
        bool SetVoice(unsigned int nCombi, unsigned int nVoice);

        /** @brief  Is solo mode enabled
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if solo mode enabled
        */
        bool IsSolo(unsigned int nCombi);

        /** @brief  Select solo mode
        *   @param  nCombi voice index [0-3]
        *   @param  bSolo True to enable solo mode
        *   @retval bool True on success
        */
        bool EnableSolo(unsigned int nCombi, bool bSolo);

        /** @brief  Is sustain pedal enabled
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if sustain pedal enabled
        */
        bool IsSustainPedal(unsigned int nCombi);

        /** @brief  Select sustain pedal enabled
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable sustain pedal
        *   @retval bool True on success
        */
        bool EnableSustainPedal(unsigned int nCombi, bool bEnable);

        /** @brief  Is velocity invert enabled
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if velocity invert enabled
        */
        bool IsVelocityInvert(unsigned int nCombi);

        /** @brief  Enable velocity invert
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable velocity invert
        *   @retval bool True on success
        */
        bool EnableVelocityInvert(unsigned int nCombi, bool bEnable);

        /** @brief  Is vibrato invert enabled
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if vibrato invert enabled
        */
        bool IsVibratoInvert(unsigned int nCombi);

        /** @brief  Enable vibrato invert
        *   @param  nCombi voice index [0-3]
        *   @param bEnable True to enable vibrato invert
        *   @retval bool True on success
        */
        bool EnableVibratoInvert(unsigned int nCombi, bool bEnable);

        /** @brief  Is tremelo invert enabled
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if tremelo invert enabled
        */
        bool IsTremeloInvert(unsigned int nCombi);

        /** @brief  Enable tremelo invert
        *   @param  nCombi voice index [0-3]
        *   @param bEnable True to enable tremelo invert
        *   @retval bool True on success
        */
        bool EnableTremeloInvert(unsigned int nCombi, bool bEnable);

        /** @brief  Get portamento time
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Portamento time
        */
        unsigned int GetPortamentoTime(unsigned int nCombi);

        /** @brief  Set portamento time
        *   @param  nCombi voice index [0-3]
        *   @param  nTime Portamento time
        *   @retval bool True on success
        */
        bool SetPortamentoTime(unsigned int nCombi, unsigned int nTime);

        /** @brief  Is portamento mode time or rate constant
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if portamento is rate constant. False if time constant
        */
        bool IsPortomentoRateConstant(unsigned int nCombi);

        /** @brief  Select portamento mode time or rate constant
        *   @param  nCombi voice index [0-3]
        *   @param  bMode True to select rate constant. False to select time constant
        *   @retval bool True on success
        */
        bool SelectPortomentoRateConstant(unsigned int nCombi, bool bMode);

        /** @brief  Get pitch bend range
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Pitch bend range
        */
        unsigned int GetPitchBendRange(unsigned int nCombi);

        /** @brief  Set pitch bend range
        *   @param  nCombi voice index [0-3]
        *   @param  nRange Pitch bend range
        *   @retval bool True on success
        */
        bool SetPitchBendRange(unsigned int nCombi, unsigned int nRange);

        /** @brief  Is pitch bend release enabled
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if pitch bend release is enabled
        */
        bool IsPitchBendRelease(unsigned int nCombi);

        /** @brief  Enable pitch bend release
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable pitch bend release
        *   @retval bool True on success
        */
        bool EnablePitchBendRelease(unsigned int nCombi, bool bEnable);

        /** @brief  Get aftertouch sensitivity
        *   @param  nCombi voice index [0-3]
        *   @retval int Aftertouch sensitivity
        */
        int GetAftertouchSensitivity(unsigned int nCombi);

        /** @brief  Set aftertouch sensitivity
        *   @param  nCombi voice index [0-3]
        *   @param  nSensitivity Aftertouch sensitivity
        *   @retval bool True on success
        */
        bool SetAftertouchSensitivity(unsigned int nCombi, int nSensitivity);

        /** @brief  Does aftertouch affect vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch affects vibrato depth
        */
        bool IsAftertouchVibratoDepth(unsigned int nCombi);

        /** @brief  Enable aftertouch affect on vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableAftertouchVibratoDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch affect vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch affects vibrato rate
        */
        bool IsAftertouchVibratoRate(unsigned int nCombi);

        /** @brief  Enable aftertouch affect on vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableAftertouchVibratoRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch bends pitch down
        */
        bool IsAftertouchPitchDown(unsigned int nCombi);

        /** @brief  Enable aftertouch bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch bends pitch down
        *   @retval bool True on success
        */
        bool EnableAftertouchPitchDown(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch bends pitch up
        */
        bool IsAftertouchPitchUp(unsigned int nCombi);

        /** @brief  Enable aftertouch bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch bends pitch up
        *   @retval bool True on success
        */
        bool EnableAftertouchPitchUp(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch affect portamento time
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch affects portamento time
        */
        bool IsAftertouchPortamentoTime(unsigned int nCombi);

        /** @brief  Enable aftertouch affect on portamento time
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch affect on portamento time
        *   @retval bool True on success
        */
        bool EnableAftertouchPortamentoTime(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch affect tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch affects tremelo depth
        */
        bool IsAftertouchTremeloDepth(unsigned int nCombi);

        /** @brief  Enable aftertouch affect on tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableAftertouchTremeloDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch affect tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch affects tremelo rate
        */
        bool IsAftertouchTremeloRate(unsigned int nCombi);

        /** @brief  Enable aftertouch affect on tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable aftertouch affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableAftertouchTremeloRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does aftertouch affect amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if aftertouch affects amplitude bias
        */
        bool IsAftertouchAmplitudeBias(unsigned int nCombi);

        /** @brief  Enable aftertouch affect on amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @param  bBenable True to enable aftertouch affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableAftertouchAmplitudeBias(unsigned int nCombi, bool bEnable);

        /** @brief  Get definable wheel 1 sensitivity
        *   @param  nCombi voice index [0-3]
        *   @retval int DefWheel1 sensitivity
        */
        int GetDefWheel1Sensitivity(unsigned int nCombi);

        /** @brief  Set definable wheel 1 sensitivity
        *   @param  nCombi voice index [0-3]
        *   @param  nSensitivity DefWheel1 sensitivity
        *   @retval bool True on success
        */
        bool SetDefWheel1Sensitivity(unsigned int nCombi, int nSensitivity);

        /** @brief  Does definable wheel 1 affect vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 affects vibrato depth
        */
        bool IsDefWheel1VibratoDepth(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 affect on vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableDefWheel1VibratoDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 affect vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 affects vibrato rate
        */
        bool IsDefWheel1VibratoRate(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 affect on vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableDefWheel1VibratoRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 bends pitch down
        */
        bool IsDefWheel1PitchDown(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 bends pitch down
        *   @retval bool True on success
        */
        bool EnableDefWheel1PitchDown(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 bends pitch up
        */
        bool IsDefWheel1PitchUp(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 bends pitch up
        *   @retval bool True on success
        */
        bool EnableDefWheel1PitchUp(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 affect portamento time
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 affects portamento time
        */
        bool IsDefWheel1PortamentoTime(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 affect on portamento time
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 affect on portamento time
        *   @retval bool True on success
        */
        bool EnableDefWheel1PortamentoTime(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 affect tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 affects tremelo depth
        */
        bool IsDefWheel1TremeloDepth(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 affect on tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableDefWheel1TremeloDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 affect tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 affects tremelo rate
        */
        bool IsDefWheel1TremeloRate(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 affect on tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 1 affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableDefWheel1TremeloRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 1 affect amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 1 affects amplitude bias
        */
        bool IsDefWheel1AmplitudeBias(unsigned int nCombi);

        /** @brief  Enable definable wheel 1 affect on amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @param  bBenable True to enable definable wheel 1 affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableDefWheel1AmplitudeBias(unsigned int nCombi, bool bEnable);

        /** @brief  Get definable wheel 2 sensitivity
        *   @param  nCombi voice index [0-3]
        *   @retval int DefWheel2 sensitivity
        */
        int GetDefWheel2Sensitivity(unsigned int nCombi);

        /** @brief  Set definable wheel 2 sensitivity
        *   @param  nCombi voice index [0-3]
        *   @param  nSensitivity DefWheel2 sensitivity
        *   @retval bool True on success
        */
        bool SetDefWheel2Sensitivity(unsigned int nCombi, int nSensitivity);

        /** @brief  Does definable wheel 2 affect vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 affects vibrato depth
        */
        bool IsDefWheel2VibratoDepth(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 affect on vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableDefWheel2VibratoDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 affect vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 affects vibrato rate
        */
        bool IsDefWheel2VibratoRate(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 affect on vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableDefWheel2VibratoRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 bends pitch down
        */
        bool IsDefWheel2PitchDown(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 bends pitch down
        *   @retval bool True on success
        */
        bool EnableDefWheel2PitchDown(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 bends pitch up
        */
        bool IsDefWheel2PitchUp(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 bends pitch up
        *   @retval bool True on success
        */
        bool EnableDefWheel2PitchUp(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 affect portamento time
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 affects portamento time
        */
        bool IsDefWheel2PortamentoTime(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 affect on portamento time
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 affect on portamento time
        *   @retval bool True on success
        */
        bool EnableDefWheel2PortamentoTime(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 affect tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 affects tremelo depth
        */
        bool IsDefWheel2TremeloDepth(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 affect on tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableDefWheel2TremeloDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 affect tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 affects tremelo rate
        */
        bool IsDefWheel2TremeloRate(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 affect on tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable wheel 2 affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableDefWheel2TremeloRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable wheel 2 affect amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable wheel 2 affects amplitude bias
        */
        bool IsDefWheel2AmplitudeBias(unsigned int nCombi);

        /** @brief  Enable definable wheel 2 affect on amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @param  bBenable True to enable definable wheel 2 affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableDefWheel2AmplitudeBias(unsigned int nCombi, bool bEnable);

        /** @brief  Get definable foot controller sensitivity
        *   @param  nCombi voice index [0-3]
        *   @retval int DefFoot sensitivity
        */
        int GetDefFootSensitivity(unsigned int nCombi);

        /** @brief  Set definable foot controller sensitivity
        *   @param  nCombi voice index [0-3]
        *   @param  nSensitivity DefFoot sensitivity
        *   @retval bool True on success
        */
        bool SetDefFootSensitivity(unsigned int nCombi, int nSensitivity);

        /** @brief  Does definable foot controller affect vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller affects vibrato depth
        */
        bool IsDefFootVibratoDepth(unsigned int nCombi);

        /** @brief  Enable definable foot controller affect on vibrato depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller affect on vibrato depth
        *   @retval bool True on success
        */
        bool EnableDefFootVibratoDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller affect vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller affects vibrato rate
        */
        bool IsDefFootVibratoRate(unsigned int nCombi);

        /** @brief  Enable definable foot controller affect on vibrato rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller affect on vibrato rate
        *   @retval bool True on success
        */
        bool EnableDefFootVibratoRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller bends pitch down
        */
        bool IsDefFootPitchDown(unsigned int nCombi);

        /** @brief  Enable definable foot controller bend pitch down
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller bends pitch down
        *   @retval bool True on success
        */
        bool EnableDefFootPitchDown(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller bends pitch up
        */
        bool IsDefFootPitchUp(unsigned int nCombi);

        /** @brief  Enable definable foot controller bend pitch up
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller bends pitch up
        *   @retval bool True on success
        */
        bool EnableDefFootPitchUp(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller affect portamento time
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller affects portamento time
        */
        bool IsDefFootPortamentoTime(unsigned int nCombi);

        /** @brief  Enable definable foot controller affect on portamento time
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller affect on portamento time
        *   @retval bool True on success
        */
        bool EnableDefFootPortamentoTime(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller affect tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller affects tremelo depth
        */
        bool IsDefFootTremeloDepth(unsigned int nCombi);

        /** @brief  Enable definable foot controller affect on tremelo depth
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller affect on tremelo depth
        *   @retval bool True on success
        */
        bool EnableDefFootTremeloDepth(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller affect tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller affects tremelo rate
        */
        bool IsDefFootTremeloRate(unsigned int nCombi);

        /** @brief  Enable definable foot controller affect on tremelo rate
        *   @param  nCombi voice index [0-3]
        *   @param  bEnable True to enable definable foot controller affect on tremelo rate
        *   @retval bool True on success
        */
        bool EnableDefFootTremeloRate(unsigned int nCombi, bool bEnable);

        /** @brief  Does definable foot controller affect amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @retval bool True if definable foot controller affects amplitude bias
        */
        bool IsDefFootAmplitudeBias(unsigned int nCombi);

        /** @brief  Enable definable foot controller affect on amplitude bias
        *   @param  nCombi voice index [0-3]
        *   @param  bBenable True to enable definable foot controller affect on amplitude bias
        *   @retval bool True on success
        */
        bool EnableDefFootAmplitudeBias(unsigned int nCombi, bool bEnable);

        /** @brief  Get volume level
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Volume level
        */
        unsigned int GetLevel(unsigned int nCombi);

        /** @brief  Set volume level
        *   @param  nCombi voice index [0-3]
        *   @param  nLevel Volume level
        *   @retval bool True on success
        */
        bool SetLevel(unsigned int nCombi, unsigned int nLevel);

        /** @brief  Get pitch offset
        *   @param  nCombi voice index [0-3]
        *   @retval int Pitch [+/-63 notes in cents]
        *   @todo   May be more appropriate to split pitch to notes and cents
        */
        int GetPitch(unsigned int nCombi);

        /** @brief  Set pitch offset
        *   @param  nCombi voice index [0-3]
        *   @param  nPitch Pitch [+/-63 notes in cents]
        *   @retval bool True on success
        */
        bool SetPitch(unsigned int nCombi, int nPitch);

        /** @brief  Get velocity split range minimum
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Minimum velocity split value
        */
        unsigned int GetVelSplitMin(unsigned int nCombi);

        /** @brief  Set velocity split range minimum
        *   @param  nCombi voice index [0-3]
        *   @param  nMin Minimum velocity split value
        *   @retval bool True on success
        */
        bool SetVelSplitMin(unsigned int nCombi, unsigned int nMin);

        /** @brief  Get velocity split range maximum
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Maximum velocity split value
        */
        unsigned int GetVelSplitMax(unsigned int nCombi);

        /** @brief  Set velocity split range maximum
        *   @param  nCombi voice index [0-3]
        *   @param  nMax Maximum velocity split value
        *   @retval bool True on success
        */
        bool SetVelSplitMax(unsigned int nCombi, unsigned int nMax);

        /** @brief  Get delay trigger
        *   @param  nCombi voice index [0-3]
        *   @retval unsigned int Delay trigger value
        */
        unsigned int GetDelayTrigger(unsigned int nCombi);

        /** @brief  Set delay trigger
        *   @param  nCombi voice index [0-3]
        *   @param  nDelay Delay trigger value
        *   @retval bool True on success
        */
        bool SetDelayTrigger(unsigned int nCombi, unsigned int nDelay);

    protected:

    private:

};

#endif // VZOPERATION_H
