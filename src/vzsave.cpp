#include "vzsave.h"

vzsave::vzsave() :
    vzsysex(VZ_SAVE_PAYLOAD_SIZE),
    m_nRxStatus(VZSAVE_RX_STATUS::RX_STATUS_IDLE)
{
}

vzsave::~vzsave()
{
    ClearVectors();
}

void vzsave::ClearVectors()
{
    // Clear any existing data and start again
    for(vector<vzvoice*>::iterator it = m_vVoice.begin(); it != m_vVoice.end(); ++it)
        delete *it;
    m_vVoice.empty();
    for(vector<vzoperation*>::iterator it = m_vOperation.begin(); it != m_vOperation.end(); ++it)
        delete *it;
    m_vOperation.empty();
}

void vzsave::OnOpen(unsigned int nDataType)
{
    ClearVectors();
    switch(nDataType)
    {
        case 0:
            m_nRxStatus = VZSAVE_RX_STATUS::RX_STATUS_VOICE;
            //!@todo Populate voice data
            break;
        case 1:
            m_nRxStatus = VZSAVE_RX_STATUS::RX_STATUS_OP;
            //!@todo Populate operation data
            break;
        case 2:
            m_nRxStatus = VZSAVE_RX_STATUS::RX_STATUS_VOICE_OP;
            //!@todo Populate voice data
            //!@todo Populate operation data
            break;
        default:
            m_nRxStatus = VZSAVE_RX_STATUS::RX_STATUS_IDLE;
    }
}

void vzsave::OnClose()
{
    m_nRxStatus = VZSAVE_RX_STATUS::RX_STATUS_IDLE;
}

void vzsave::OnOk()
{
    //!@todo Implement OnOk
}

void vzsave::OnError()
{
    //!@todo Implement OnError
}

void vzsave::OnData(wxByte* pData, long lLength)
{
    if(lLength < 6)
        return;
    pData += 6;
    lLength -= 6;
    // Iterate through data, one voice at a time populating new voice objects
    if(m_nRxStatus == VZSAVE_RX_STATUS::RX_STATUS_VOICE || m_nRxStatus == VZSAVE_RX_STATUS::RX_STATUS_VOICE_OP)
    {
        if(lLength < (VZ_VOICE_PAYLOAD_SIZE + 1) * 64)
            return;
        for(unsigned int i = 0; i < 64; ++i)
        {
            m_vVoice.push_back(new vzvoice(pData, true));
            pData += VZ_VOICE_PAYLOAD_SIZE + 1;
        }
        lLength -= VZ_VOICE_PAYLOAD_SIZE * 64;
    }
    if(m_nRxStatus == VZSAVE_RX_STATUS::RX_STATUS_OP || m_nRxStatus == VZSAVE_RX_STATUS::RX_STATUS_VOICE_OP)
    {
        if(lLength < (VZ_OPERATION_PAYLOAD_SIZE + 1) * 64)
            return;
        for(unsigned int i = 0; i < 64; ++i)
        {
            m_vOperation.push_back(new vzoperation(pData, true));
            pData += VZ_OPERATION_PAYLOAD_SIZE + 1;
        }
    }
    m_nRxStatus = VZSAVE_RX_STATUS::RX_STATUS_CLOSE;
}

VZSAVE_DATATYPE vzsave::GetAvailable()
{
    if (m_vOperation.size() > 0)
    {
        if(m_vVoice.size() > 0)
            return VZSAVE_DATATYPE::VOICE_OP;
        else
            return VZSAVE_DATATYPE::OP;
    }
    if(m_vVoice.size() > 0)
        return VZSAVE_DATATYPE::VOICE;
    return VZSAVE_DATATYPE::NONE;
}

vzvoice* vzsave::GetVoice(unsigned int nIndex)
{
    if(m_vVoice.size() > nIndex)
        return m_vVoice[nIndex];
    return nullptr;
}

vzoperation* vzsave::GetOperation(unsigned int nIndex)
{
    if(m_vOperation.size() > nIndex)
        return m_vOperation[nIndex];
    return nullptr;
}
