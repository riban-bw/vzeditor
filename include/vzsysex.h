#ifndef VZSYSEX_H
#define VZSYSEX_H

#include "wx/wx.h"

#define VZ_HEADER_SIZE 7

/** Provides interface to VZ SysEx data
*   @note   Data is stored as raw SysEx data
*/
class vzsysex
{
    public:
        /** @brief  Construct vzsysex object
        *   @param  nPayloadSize Quantity of bytes in payload
        *   @note   Initialises operation data to defaults
        */
        vzsysex(unsigned int nPayload);

        /** @brief  Construct vzsysex object from existing SysEx data
        *   @param  Data Pointer to a buffer containing raw SysEx operation data
        *   @param  nPayloadSize Quantity of bytes in payload
        *   @note   Initiailses any invalid values to defaults and sets modified field
        */
        vzsysex(wxByte* pData, unsigned int nPayload);

        /** @brief  Default destruct vzsysex object
        */
        virtual ~vzsysex();

        //!@todo implement copy operator

        /** @brief  Check if data has been changed since last validate / save (***which)
        *   @retval bool True if data has been modified
        */
        bool IsModified();

        /** @brief  Get the raw SysEx data
        *   @param  pData Pointer to buffer to store raw SyseEx data
        */
        void GetSysEx(wxByte* pData);

        /** @brief  Get the raw SysEx data
        *   @retval wxByte* Pointer to buffer with raw SyseEx data
        */
        wxByte* GetSysEx();

        /** @brief  Set the raw SysEx data
        *   @param  pData Pointer to a buffer containing raw SysEx operation data
        *   @retval bool True if any data is invalid and initialised
        *   @note   Data is validated before populating the sysex data
        */
        bool SetSysEx(wxByte* pData);

        /** @brief  Validate a single byte
        *   @param  pByte Pointer to the byte to validate
        *   @param  nByte Value to validate against
        *   @param  bFix True to correct invalid data
        *   @retval bool True if data invalid
        */
        bool ValidateByte(wxByte* pByte, wxByte nByte, bool bFix);

        /** @brief  Validates raw SysEx sysex data
        *   @param  bFix True to initalise invalid data
        *   @retval bool True if data is valid
        */
        bool Validate(bool bFix = false);

        /** @brief  Validate data against checksum
        *   @param  pData Pointer to the data to validate
        *   @param  nSize Quantity of bytes to validate
        *   @param  nChecksum Checksum to validate [Default: 0 - calculate checksum]
        *   @retval wxByte Calculated value of checksum (zero if valid checksum)
        *   @note   Pass zero checksum to calculate a checksum. Pass a checksum to check data (zero return for valid data)
        */
        wxByte Checksum(wxByte* pData, unsigned int nSize, wxByte nChecksum = 0);

        /** @brief  Get the quantity of bytes in a SysEx message
        *   @retval unsigned int Quantity of bytes
        */
        unsigned int GetSize();

    protected:
        wxByte* m_pSysEx; //Raw sysex operation data
        unsigned int m_nPayloadSize; //Quantity of bytes in payload
        wxByte GetValue(unsigned int nOffset, wxByte nMask); //!< Helper function to get value from SysEx
        void SetValue(unsigned int nOffset, wxByte nMask, wxByte nValue); //!< Helper function to set value in SysEx
        wxByte DecodeByte(wxByte* pCursor); //!< Decodes 2 nibbles in separate bytes to single byte
        void EncodeByte(wxByte* pCursor, wxByte nValue); //!< Encodes byte to 2 nibbles in separate bytes
        wxByte GetByteFromSysex(unsigned int nOffset); //!< Decode a byte of data from the position in SysEx payload pointed to by cursor
        bool PutByteToSysex(unsigned int nOffset, wxByte nValue); //!< Encode a byte of data into position in SysEx payload pointed to by cursor

    private:

        bool m_bModified; //True if any fields have changed since last validate / save ***We don't really mean save
};

#endif // VZSYSEX_H
