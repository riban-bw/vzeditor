#ifndef VZSAVE_H
#define VZSAVE_H

#define VZ_SAVE_PAYLOAD_SIZE 0 //Size of sysex save / load payload in bytes

#include "vzsysex.h"
#include "vzvoice.h"
#include "vzoperation.h"
#include <vector>

using namespace std;

/*  Data flow
    Sending device  | Receiving device  | Notes
    IDLE            | IDLE              | Idle state - no save / load operation in progress
    Sends OPEN      | Receives OPEN     | Request to send data
    Receives OK     | Sends OK          | Acknowledge request - send end will continue after short timeout regardless
    TX Sends data   | RX Receives data  | Data sent from sender to receiver
    Send CLOSE      | Receive CLOSE     | End of transaction - return to IDLE

    VZ-1 sends OPEN
    VZ Editor waits (could send OK but let's implement simplex
    VZ-1 sends DATA
    VZ Editor stores data in 64 objects (could save to 64 files each called NAME.vzt / NAME.vzo)
    VZ-1 sends CLOSE
    VX Editor offers user option to save objects
*/

enum VZSAVE_RX_STATUS {
    RX_STATUS_IDLE,
    RX_STATUS_VOICE, //Receiving voice data
    RX_STATUS_OP, //Receiving operation data
    RX_STATUS_VOICE_OP, //Receiving voice and operation data
    RX_STATUS_CLOSE //Awaiting close message
};

enum VZSAVE_DATATYPE {
    VZSAVE_DATATYPE_NONE,    // No valid data available
    VZSAVE_DATATYPE_VOICE,   // Voice data available
    VZSAVE_DATATYPE_OP,      // Operation data available
    VZSAVE_DATATYPE_VOICE_OP // Voice and operation data available
};

/** Provides interface to VZ SysEx save operation
*/
class vzsave : public vzsysex
{
    public:
        vzsave();
        virtual ~vzsave();

        /** @brief  Send OPEN message to VZ device
        *   @note   Fails if transmission already in progress
        */
        void SendOpen();

        /** @brief  Send CLOSE message to VZ device
        *   @note   Part of transmission conversation so application should not call this directly
        */
        void SendClose();

        /** @brief  Send OK message to VZ device
        */
        void SendOk();

        /** @brief  Send ERROR message to VZ device
        */
        void SendError();

        /** @brief  Send data to VZ device
        */
        void SendData();

        /** @brief  Handle received OPEN message from VZ device
        *   @param  nDataType The data type requested to be sent [0=64 tones, 1=64 operations, 2=64 tones + 64 operations]
        */
        void OnOpen(unsigned int nDataType);

        /** @brief  Handle received CLOSE message from VZ device
        */
        void OnClose();

        /** @brief  Handle received OK message from VZ device
        */
        void OnOk();

        /** @brief  Handle received ERROR message from VZ device
        */
        void OnError();

        /** @brief  Handle received DATA message from VZ device
        *   @param  pData Pointer to array of wxByte data
        *   @param  lLength Quantity of bytes in data
        */
        void OnData(wxByte* pData, long lLength);

        /** @brief  Get type of data available
        *   @retval VZSAVE_DATATYPE Type of data available
        */
        VZSAVE_DATATYPE GetAvailable();

        /** @brief  Get voice data
        *   @param  nIndex Index of voice data to retrieve
        *   @retval pData Pointer to vzvoice object or NULL if data not available
        */
        vzvoice* GetVoice(unsigned int nIndex);

        /** @brief  Get operation data
        *   @param  nIndex Index of operation data to retrieve
        *   @retval pData Pointer to vzoperation object or NULL if data not available
        */
        vzoperation* GetOperation(unsigned int nIndex);

        /** @brief  Save data to files and create a library
        *   @param  sPath Full path and filename to save new library
        *   @retval bool True on success
        *   @note   Each voice and operation data is saved as individual files within same folder
        */
        bool SaveToDisk(wxString sPath);

    protected:

    private:
        void ClearVectors();
        VZSAVE_RX_STATUS m_nRxStatus; //Current status of receiver
        VZSAVE_DATATYPE m_nStatus;
        vector<vzvoice*> m_vVoice; //Vector of pointers to voice data
        vector<vzoperation*> m_vOperation; //Vector of pointers to operation data
};

#endif // VZSAVE_H
