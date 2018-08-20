#ifndef VZ1VOICE_H
#define VZ1VOICE_H

#define VZ_VOICE_SIZE 681 //Size of sysex voice data in bytes
#define VZ_VOICE_PAYLOAD_SIZE 672 //Size of sysex voice payload in bytes
#define VZ_VOICE_PAYLOAD_START 7 //Offset of start of payload in bytes

#include "wx/wx.h"
#include "envelope.h"

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


/** Provides interface to VZ-1 SysEx voice data
*   @note   Data is stored as raw SysEx data
*/
class vzvoice
{
    public:
        /** @brief  Construct vz1voice object
        *   @note   Initialises voice data to defaults
        */
        vzvoice();

        /** @brief  Construct vz1voice object from existing SysEx data
        *   @param  Data Pointer to a buffer containing raw SysEx voice data
        *   @note   Initiailses any invalid values to defaults and sets modified field
        */
        vzvoice(const unsigned char* pData);

        /** @brief  Default destruct vz1voice object
        */
        virtual ~vzvoice();

        //!@todo implement copy operator

        /** @brief  Check if data has been changed since last validate / save (***which)
        *   @retval bool True if data has been modified
        */
        bool IsModified();

        /** @brief  Get the raw SysEx data
        *   @param  pData Pointer to buffer to store raw SyseEx data
        */
        void GetSysEx(unsigned char* pData);

        /** @brief  Get the raw SysEx data
        *   @retval (unsigned char*) Pointer to buffer with raw SyseEx data
        */
        unsigned char* GetSysEx();

        /** @brief  Set the raw SysEx data
        *   @param  pData Pointer to a buffer containing raw SysEx voice data
        *   @retval bool True if any data is invalid and initialised
        *   @note   Data is validated before populating the voice data
        */
        bool SetSysEx(const unsigned char* pData);

        /** @brief  Validate a single byte
        *   @param  pByte Pointer to the byte to validate
        *   @param  nByte Value to validate against
        *   @param  bFix True to correct invalid data
        *   @retval bool True if data invalid
        */
        bool ValidateByte(unsigned char* pByte, unsigned char nByte, bool bFix);

        /** @brief  Validates raw SysEx voice data
        *   @param  bFix True to initalise invalid data
        *   @retval bool True if data is valid
        */
        bool Validate(bool bFix = false);

        /** @brief  Validate data against checksum
        *   @param  pData Pointer to the data to validate
        *   @param  nSize Quantity of bytes to validate
        *   @param  nChecksum Checksum to validate [Default: 0 - calculate checksum]
        *   @retval unsigned char Calculated value of checksum (zero if valid checksum)
        *   @note   Pass zero checksum to calculate a checksum. Pass a checksum to check data (zero return for valid data)
        */
        unsigned char Checksum(unsigned char* pData, unsigned int nSize, unsigned char nChecksum = 0);

        /** @brief  Gets the voice name
        *   @retval wxString Name of the voice
        */
        wxString GetName();

        /** @brief  Sets the voice name
        *   @param wxString Name of the voice
        */
        void SetName(wxString sName);

        /** @brief  Is the external phase enabled for a module
        *   @param  nModule Module index
        *   @retval bool True if external phase enabled
        */
        bool IsExtPhase(wxByte nModule);

        /** @brief  Enable / disable the external phase for a module
        *   @param  nModule Index of module (zero base) [3,5,7]
        *   @param  bEnable True to enable, false to disable [Default: true]
        */
        void EnableExtPhase(wxByte nModule, bool bEnable = true);

        /** @brief  Get the waveform for a module
        *   @param  nModule Index of module (zero base) [0-7]
        *   @retval wxByte Waveform
        */
        wxByte GetWaveform(wxByte nModule);

        /** @brief  Set the waveform for a module
        *   @param  nModule Index of module (zero base) [0-7]
        *   @param  nWaveform Waveform [VZ_WAVEFORM]
        */
        void SetWaveform(wxByte nModule, VZ_WAVEFORM nWaveform);

        /** @brief  Get the configuration for an internal line
        *   @param  nLine Internal line
        *   @retval wxByte Line configuration [VZ_LINE]
        */
        wxByte GetLine(wxByte nLine);

        /** @brief  Set the line configuration for an internal line
        *   @param  nLine Internal line index
        *   @param  nMode Line configuration [VZ_LINE]
        *   @retval bool True on success
        */
        bool SetLine(wxByte nLine, VZ_LINE nMode);

        /** @brief  Gets course detune value
        *   @param  nModule Module index
        *   @retval wxByte Course detune value
        */
        wxByte GetDetuneCourse(wxByte nModule);

        /** @brief  Sets course detune value
        *   @param  nModule Module index
        *   @param  nValue Course detune value [0..127]
        *   @retval bool True on success
        */
        bool SetDetuneCourse(wxByte nModule, wxByte nDetune);

        /** @brief  Gets fine detune value
        *   @param  nModule Module index
        *   @retval wxByte Fine detune value
        */
        wxByte GetDetuneFine(wxByte nModule);

        /** @brief  Sets fine detune value
        *   @param  nModule Module index
        *   @param  nValue Fine detune value [0..63]
        *   @retval bool True on success
        */
        bool SetDetuneFine(wxByte nModule, wxByte nDetune);

        /** @brief  Gets detune polarity
        *   @param  nModule Module index
        *   @retval bool Detune polarity [True for positive]
        */
        bool IsDetunePositive(wxByte nModule);

        /** @brief  Sets detune polarity
        *   @param  nModule Module index
        *   @param  bPolarity Detune polarity [Default: true (positive)]
        *   @retval bool True on success
        */
        bool SetDetunePositive(wxByte nModule, bool bPolarity = true);

        /** @brief  Gets detune value
        *   @param  nModule Module index
        *   @retval int Detune value
        */
        int GetDetune(wxByte nModule);

        /** @brief  Sets detune value
        *   @param  nModule Module index
        *   @param  nDetune Detune value [-8191..8191]
        *   @retval bool True on success
        */
        bool SetDetune(wxByte nModule, int nDetune);

        /** @brief  Is pitch fix enabled
        *   @param  nModule Module index
        *   @retval bool True if pitch fixed enabled
        */
        bool IsPitchFix(wxByte nModule);

        /** @brief  Enable / disable pitch fix
        *   @param  nModule Module index
        *   @param  bEnable True to enable pitch fix [Default: true]
        *   @retval bool True on success
        */
        bool EnablePitchFix(wxByte nModule, bool bEnable = true);

        /** @brief  Is pitch fix x16 range enabled
        *   @param  nModule Module index
        *   @retval bool True if pitch fix x16 range enabled
        */
        bool IsPitchFixRange(wxByte nModule);

        /** @brief  Enable / disable pitch fix x16 range
        *   @param  nModule Module index
        *   @param  bEnable True to enable pitch fix x16 range [Default: true]
        *   @retval bool True on success
        */
        bool EnablePitchFixRange(wxByte nModule, bool bEnable = true);

        /** @brief  Get pointer to a module's DCA Envelope
        *   @param  nModule Module index [0..7]
        *   @retval Envelope* Pointer to envelope
        *   @note   Updates envelopes from SysEx data
        */
        Envelope* GetDCAEnvelope(wxByte nModule);

        /** @brief  Update DCA Envelope
        *   @param  nModule Module index [0..7]
        *   @retval bool   True on success
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
        *   @retval bool   True on success
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

        /** @brief  Is module enabled
        *   @param  nModule Module index
        *   @retval bool True if module enabled (On)
        */
        bool IsModuleEnabled(wxByte nModule);

        /** @brief  Enable / disable module
        *   @param  nModule Module index
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


    protected:

    private:
        wxByte m_acSysEx[VZ_VOICE_SIZE]; //Raw sysex voice data
        bool m_bModified; //True if any fields have changed since last validate / save ***We don't really mean save
        Envelope m_envDCA[8]; //!< DCA envelope for each module
        Envelope m_envDCO; //!< DCO envelope
        wxByte m_nLevel; //!< Totoal Level [0..62,127]
        bool m_bModuleEnabled[8]; //!< True to enable module
        bool m_bDCORange; //!< DCO Range True = wide, false = narrow

        wxByte DecodeByte(wxByte* pCursor); //!< Decodes 2 nibbles in separate bytes to single byte
        void EncodeByte(wxByte* pCursor, wxByte nValue); //!< Encodes byte to 2 nibbles in separate bytes
        wxByte GetByteFromSysex(unsigned int nOffset); //!< Decode a byte of data from the position in SysEx payload pointed to by cursor
        bool PutByteToSysex(unsigned int nOffset, wxByte nValue); //!< Encode a byte of data into position in SysEx payload pointed to by cursor

};

#endif // VZ1VOICE_H
