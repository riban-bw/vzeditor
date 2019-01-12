#ifndef VZVOICE_H
#define VZVOICE_H

#define VZ_VOICE_PAYLOAD_SIZE 672 //Size of sysex voice payload in bytes
#define VZ_TYPE_VOICE 0x00
#define VZ_TYPE_TONE 0x00

#include "vzsysex.h"
#include "envelope.h"
#include "keyfollow.h"

enum VZ_WAVEFORM{
    SINE    = 0,
    SAW1    = 1,
    SAW2    = 2,
    SAW3    = 3,
    SAW4    = 4,
    SAW5    = 5,
    NOISE1  = 6,
    NOISE2  = 7
};

enum VZ_LINE {
    MIX     = 0,
    PHASE   = 1,
    RING    = 2
};

/** Provides interface to VZ SysEx voice data
*   @note   Data is stored as raw SysEx data
*/
class vzvoice : public vzsysex
{
    public:
        /** @brief  Construct vzvoice object
        *   @note   Initialises voice data to defaults
        */
        vzvoice();

        /** @brief  Construct vzvoice object from existing SysEx data
        *   @param  pData Pointer to a buffer containing raw SysEx voice data
        *   @note   Initialises any invalid values to defaults and sets modified field
        */
        vzvoice(wxByte* pData);

        /** @brief  Default destruct vzvoice object
        */
        virtual ~vzvoice();

        /** @brief  Validates raw SysEx sysex data
        *   @param  bFix True to initialise invalid data
        *   @retval bool True if data is valid
        */
        bool Validate(bool bFix = false);

        /** @brief  Is the external phase enabled for a module
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval bool True if external phase enabled
        */
        bool IsExtPhase(wxByte nModule);

        /** @brief  Enable / disable the external phase for a module
        *   @param  nModule Index of module (zero base) [3,5,7]
        *   @param  bEnable True to enable, false to disable [Default: true]
        *   @retval bool True on success
        */
        bool EnableExtPhase(wxByte nModule, bool bEnable = true);

        /** @brief  Get the waveform for a module
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte Waveform
        */
        wxByte GetWaveform(wxByte nModule);

        /** @brief  Set the waveform for a module
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nWaveform Waveform [VZ_WAVEFORM]
        *   @retval bool True on success
        */
        bool SetWaveform(wxByte nModule, VZ_WAVEFORM nWaveform);

        /** @brief  Get the configuration for an internal line
        *   @param  nLine Internal line [0..3]
        *   @retval wxByte Line configuration [VZ_LINE]
        */
        wxByte GetLine(wxByte nLine);

        /** @brief  Set the line configuration for an internal line
        *   @param  nLine Internal line index [0..3]
        *   @param  nMode Line configuration [VZ_LINE]
        *   @retval bool True on success
        */
        bool SetLine(wxByte nLine, VZ_LINE nMode);

        /** @brief  Gets course detune value
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte Course detune value
        */
        wxByte GetDetuneCourse(wxByte nModule);

        /** @brief  Sets course detune value
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nValue Course detune value [0..127]
        *   @retval bool True on success
        */
        bool SetDetuneCourse(wxByte nModule, wxByte nDetune);

        /** @brief  Gets fine detune value
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte Fine detune value
        */
        wxByte GetDetuneFine(wxByte nModule);

        /** @brief  Sets fine detune value
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nValue Fine detune value [0..63]
        *   @retval bool True on success
        */
        bool SetDetuneFine(wxByte nModule, wxByte nDetune);

        /** @brief  Gets detune polarity
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval bool Detune polarity [True for positive]
        */
        bool IsDetunePositive(wxByte nModule);

        /** @brief  Sets detune polarity
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  bPolarity Detune polarity [Default: true (positive)]
        *   @retval bool True on success
        */
        bool SetDetunePositive(wxByte nModule, bool bPolarity = true);

        /** @brief  Gets detune value
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval int Detune value
        */
        int GetDetune(wxByte nModule);

        /** @brief  Sets detune value
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nDetune Detune value [-8191..8191]
        *   @retval bool True on success
        */
        bool SetDetune(wxByte nModule, int nDetune);

        /** @brief  Is pitch fix enabled
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval bool True if pitch fixed enabled
        */
        bool IsPitchFix(wxByte nModule);

        /** @brief  Enable / disable pitch fix
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  bEnable True to enable pitch fix [Default: true]
        *   @retval bool True on success
        */
        bool EnablePitchFix(wxByte nModule, bool bEnable = true);

        /** @brief  Is pitch fix x16 range enabled
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval bool True if pitch fix x16 range enabled
        */
        bool IsPitchFixRange(wxByte nModule);

        /** @brief  Enable / disable pitch fix x16 range
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  bEnable True to enable pitch fix x16 range [Default: true]
        *   @retval bool True on success
        */
        bool EnablePitchFixRange(wxByte nModule, bool bEnable = true);

        /** @brief  Get pointer to a module's DCA Envelope
        *   @param  nModule Index of module (zero base) [0..7] [0..7]
        *   @retval Envelope* Pointer to envelope
        *   @note   Updates envelopes from SysEx data
        */
        Envelope* GetDCAEnvelope(wxByte nModule);

        /** @brief  Update DCA Envelope
        *   @param  nModule Index of module (zero base) [0..7] [0..7]
        *   @retval bool True on success
        *   @note   Call this function after any changes to the envelope to update the SysEx data
        *   @todo   Automatially update after any changes to parameters
        */
        bool UpdateDCAEnvelope(wxByte nModule);

        /** @brief  Get pointer to a DCO Envelope
        *   @retval Envelope* Pointer to envelope
        *   @note   Updates envelope from SysEx data
        */
        Envelope* GetDCOEnvelope();

        /** @brief  Update DCO Envelope
        *   @retval bool True on success
        *   @note   Call this function after any changes to the envelope to update the SysEx data
        *   @todo   Automatially update after any changes to parameters
        */
        bool UpdateDCOEnvelope();

        /** @brief  Get total level
        *   @retval wxByte Level
        */
        wxByte GetLevel();

        /** @brief  Set total level
        *   @param  nLevel Level [0..99]
        *   @retval bool True on success
        */
        bool SetLevel(wxByte nLevel);

        /** @brief  Get module sensitivity to continuous controllers
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte Sensitivity
        */
        wxByte GetCCSensitivity(wxByte nModule);

        /** @brief  Set module sensitivity to continuous controllers
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nSensitivity [0..7]
        *   @retval bool True on success
        */
        bool SetCCSensitivity(wxByte nModule, wxByte nSensitivity);

        /** @brief  Get DCA envelope depth
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte DCA envelope depth
        */
        wxByte GetDCAEnvDepth(wxByte nModule);

        /** @brief  Set DCA envelope depth
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nDepth [0..7F]
        *   @retval bool True on success
        */
        bool SetDCAEnvDepth(wxByte nModule, wxByte nDepth);

        /** @brief  Is module enabled
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval bool True if module enabled (On)
        */
        bool IsModuleEnabled(wxByte nModule);

        /** @brief  Enable / disable module
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  bEnable True to enable module [Default: true]
        *   @retval bool True on success
        */
        bool EnableModule(wxByte nModule, bool bEnable = true);

        /** @brief  Is the DCO range set to wide or narrow
        *   @retval bool True if DCO range set to wide
        */
        bool IsDCORangeWide();

        /** @brief  Set DCO range to wide or narrow
        *   @param  bWide True to set range to wide [Default: true]
        *   @retval bool True on success
        */
        bool SetDCORangeWide(bool bWide = true);

        /** @brief  Get pointer to a module's DCA Key Follow
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval KeyFllow* Pointer to key follow
        *   @note   Updates key follow from SysEx data
        */
        KeyFollow* GetDCAKeyFollow(wxByte nModule);

        /** @brief  Update DCA Key Follow
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval bool True on success
        *   @note   Call this function after any changes to the key follow to update the SysEx data
        *   @todo   Automatially update after any changes to parameters
        */
        bool UpdateDCAKeyFollow(wxByte nModule);

        /** @brief  Get pointer to a DCO Key Follow
        *   @retval Envelope* Pointer to key follow
        *   @note   Updates envelope from SysEx data
        */
        KeyFollow* GetDCOKeyFolllow();

        /** @brief  Update DCO Key Follow
        *   @retval bool True on success
        *   @note   Call this function after any changes to the key follow to update the SysEx data
        *   @todo   Automatially update after any changes to parameters
        */
        bool UpdateDCOKeyFollow();

        /** @brief  Get key for a step in the follow key crate urve
        *   @param  nStep Step for which to retrieve KF key [0..5]
        *   @retval wxByte Key at this step
        */
        wxByte GetKFkey(wxByte nStep);

        /** @brief  Set key for a step in the key follow rate curve
        *   @param  nStep Step for which to set KF key [0..5]
        *   @param  nKey Key value [0x0C..0x78]
        *   @retval bool True on success
        */
        bool SetKFkey(wxByte nStep, wxByte nKey);

        /** @brief  Get rate for a step in the follow rate curve
        *   @param  nStep Step for which to retrieve KF rate [0..5]
        *   @retval wxByte Key follow rate
        */
        wxByte GetKFrate(wxByte nStep);

        /** @brief  Set rate for a step in the key follow rate curve
        *   @param  nStep Step for which to retrieve KF rate [0..5]
        *   @param  nRate Rate value [0x00..0x7F]
        *   @retval bool True on success
        */
        bool SetKFrate(wxByte nStep, wxByte nRate);

        /** @brief  Get module key velocity curve
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte Velocity curve
        */
        wxByte GetModuleVelCurve(wxByte nModule);

        /** @brief  Set module key velocity curve
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nCurve Curve [0..7]
        *   @retval bool True on success
        */
        bool SetModuleVelCurve(wxByte nModule, wxByte nCurve);

        /** @brief  Get module key velocity sensitivity
        *   @param  nModule Index of module (zero base) [0..7]
        *   @retval wxByte Velocity sensitivity
        */
        wxByte GetModuleVelSens(wxByte nModule);

        /** @brief  Set module key velocity sensitivity
        *   @param  nModule Index of module (zero base) [0..7]
        *   @param  nCurve Sensitivity [0x00..0x1F]
        *   @retval bool True on success
        */
        bool SetModuleVelSens(wxByte nModule, wxByte nSens);

        /** @brief  Get pitch key velocity curve
        *   @retval wxByte Velocity curve
        */
        wxByte GetPitchVelCurve();

        /** @brief  Set pitch key velocity curve
        *   @param  nSens Curve [0x00..0x07]
        *   @retval bool True on success
        */
        bool SetPitchVelCurve(wxByte nSens);

        /** @brief  Get pitch key velocity sensitivity
        *   @retval wxByte Velocity sensitivity
        */
        wxByte GetPitchVelSens();

        /** @brief  Set pitch key velocity sensitivity
        *   @param  nSens Sensitivity [0x00..0x1F]
        *   @retval bool True on success
        */
        bool SetPitchVelSens(wxByte nSens);

        /** @brief  Get rate key velocity curve
        *   @retval wxByte Velocity curve
        */
        wxByte GetRateVelCurve();

        /** @brief  Set rate key velocity curve
        *   @param  nSens Velocity curve [0x00..0x07]
        *   @retval bool True on success
        */
        bool SetRateVelCurve(wxByte nSens);

        /** @brief  Get rate key velocity sensitivity
        *   @retval wxByte Velocity sensitivity
        */
        wxByte GetRateVelSens();

        /** @brief  Set rate key velocity sensitivity
        *   @param  nSens Sensitivity [0x00..0x1F]
        *   @retval bool True on success
        */
        bool SetRateVelSens(wxByte nSens);

        /** @brief  Get octave
        *   @retval int Octave
        */
        int GetOctave();

        /** @brief  Set octave
        *   @param  nOctave Octave [-2..+2]
        *   @retval bool True on success
        */
        bool SetOctave(int nOctave);

        /** @brief  Is vibrato set to multi-mode
        *   @retval bool True if vibrator is set to multi-mode
        */
        bool IsVibratoMulti();

        /** @brief  Enable / disable vibrato multi-mode
        *   @param  bEnable True to enable multi-mode [Default: true]
        *   @retval bool True on success
        */
        bool EnableVibratoMulti(bool bEnable);

        /** @brief  Get vibrato waveform
        *   @retval wxByte Vibrato waveform
        */
        wxByte GetVibratoWaveform();

        /** @brief  Set vibrato waveform
        *   @param  nWaveform Vibrator waveform [0..3]
        *   @retval bool True on succes
        */
        bool SetVibratoWaveform(wxByte nWaveform);

        /** @brief  Get vibrato depth
        *   @retval wxByte Vibrato depth
        */
        wxByte GetVibratoDepth();

        /** @brief  Set vibrato depth
        *   @param  nDepth Vibrato depth [0..99]
        *   @retval bool True on success
        */
        bool SetVibratoDepth(wxByte nDepth);

        /** @brief  Get vibrato rate
        *   @retval wxByte Vibrato rate
        */
        wxByte GetVibratoRate();

        /** @brief  Set vibrato rate
        *   @param  nDepth Vibrato rate [0..99]
        *   @retval bool True on success
        */
        bool SetVibratoRate(wxByte nRate);

        /** @brief  Get vibrato delat
        *   @retval wxByte Vibrato delay
        */
        wxByte GetVibratoDelay();

        /** @brief  Set vibrato delay
        *   @param  nDepth Vibrato delay [0..99]
        *   @retval bool True on success
        */
        bool SetVibratoDelay(wxByte nDelay);

        /** @brief  Is tremelo set to multi-mode
        *   @retval bool True if tremelor is set to multi-mode
        */
        bool IsTremeloMulti();

        /** @brief  Enable / disable tremelo multi-mode
        *   @param  bEnable True to enable multi-mode [Default: true]
        *   @retval bool True on success
        */
        bool EnableTremeloMulti(bool bEnable);

        /** @brief  Get tremelo waveform
        *   @retval wxByte tremelo waveform
        */
        wxByte GetTremeloWaveform();

        /** @brief  Set tremelo waveform
        *   @param  nWaveform tremelor waveform [0..3]
        *   @retval bool True on succes
        */
        bool SetTremeloWaveform(wxByte nWaveform);

        /** @brief  Get tremelo depth
        *   @retval wxByte tremelo depth
        */
        wxByte GetTremeloDepth();

        /** @brief  Set tremelo depth
        *   @param  nDepth tremelo depth [0..99]
        *   @retval bool True on success
        */
        bool SetTremeloDepth(wxByte nDepth);

        /** @brief  Get tremelo rate
        *   @retval wxByte tremelo rate
        */
        wxByte GetTremeloRate();

        /** @brief  Set tremelo rate
        *   @param  nDepth tremelo rate [0..99]
        *   @retval bool True on success
        */
        bool SetTremeloRate(wxByte nRate);

        /** @brief  Get tremelo delat
        *   @retval wxByte tremelo delay
        */
        wxByte GetTremeloDelay();

        /** @brief  Set tremelo delay
        *   @param  nDepth tremelo delay [0..99]
        *   @retval bool True on success
        */
        bool SetTremeloDelay(wxByte nDelay);

        /** @brief  Gets the voice name
        *   @retval wxString Name of the voice
        */
        wxString GetName();

        /** @brief  Sets the voice name
        *   @param wxString Name of the voice
        */
        void SetName(wxString sName);

    protected:

    private:
        Envelope m_envDCA[8]; //!< DCA envelope for each module
        Envelope m_envDCO; //!< DCO envelope
        wxByte m_nLevel; //!< Totoal Level [0..62,127]
        bool m_bModuleEnabled[8]; //!< True to enable module
        bool m_bDCORange; //!< DCO Range True = wide, false = narrow
        KeyFollow m_kfDCA[8]; //!< DCA keyboard follow curve
        KeyFollow* m_pkfDCO; //!< DCO keyboard follow curve
};

#endif // VZVOICE_H
