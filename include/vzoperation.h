#ifndef VZOPERATION_H
#define VZOPERATION_H

#define VZ_OPERATION_PAYLOAD_SIZE 200 //Size of sysex operation payload in bytes

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
        *   @note   Initiailses any invalid values to defaults and sets modified field
        */
        vzoperation(wxByte* pData);

        /** @brief  Default destruct vzoperation object
        */
        virtual ~vzoperation();

    protected:

    private:

};

#endif // VZOPERATION_H
