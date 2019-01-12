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
        *   @note   Initialises any invalid values to defaults and sets modified field
        */
        vzoperation(wxByte* pData);

        /** @brief  Default destruct vzoperation object
        */
        virtual ~vzoperation();

        /** @brief  Validates raw SysEx sysex data
        *   @param  bFix True to initialise invalid data
        *   @retval bool True if data is valid
        */
        bool Validate(bool bFix = false);

        /** @brief  Gets the operationa data name
        *   @retval wxString Name of the operationa data
        */
        wxString GetName();

        /** @brief  Sets the operationa data  name
        *   @param wxString Name of the operationa data
        */
        void SetName(wxString sName);

    protected:

    private:

};

#endif // VZOPERATION_H
