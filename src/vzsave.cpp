/***************************************************************
 * Name:      vzsavve.h
 * Purpose:   Implements VZSave class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2019-01-17
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#include "vzsave.h"
#include "vzlibrary.h"

VZSave::VZSave() :
    VZSysex(VZ_SAVE_PAYLOAD_SIZE),
    m_nRxStatus(RX_STATUS_IDLE)
{
}

VZSave::~VZSave()
{
    ClearVectors();
}

void VZSave::ClearVectors()
{
    // Clear any existing data and start again
    for(vector<VZVoice*>::iterator it = m_vVoice.begin(); it != m_vVoice.end(); ++it)
        delete *it;
    m_vVoice.empty();
    for(vector<VZOperation*>::iterator it = m_vOperation.begin(); it != m_vOperation.end(); ++it)
        delete *it;
    m_vOperation.empty();
}

void VZSave::OnOpen(unsigned int nDataType)
{
    ClearVectors();
    switch(nDataType)
    {
    case 0:
        m_nRxStatus = RX_STATUS_VOICE;
        //!@todo Populate voice data
        break;
    case 1:
        m_nRxStatus = RX_STATUS_OP;
        //!@todo Populate operation data
        break;
    case 2:
        m_nRxStatus = RX_STATUS_VOICE_OP;
        //!@todo Populate voice data
        //!@todo Populate operation data
        break;
    default:
        m_nRxStatus = RX_STATUS_IDLE;
    }
}

void VZSave::OnClose()
{
    if(m_nRxStatus == RX_STATUS_VOICE || m_nRxStatus == RX_STATUS_VOICE_OP)
    {
        //!@todo Save new voices to (temporary?) .vzt files
    }
    if(m_nRxStatus == RX_STATUS_OP || m_nRxStatus == RX_STATUS_VOICE_OP)
    {
        //!@todo Save new voices to (temporary?) .vzo files
    }
    m_nRxStatus = RX_STATUS_IDLE;
}

void VZSave::OnOk()
{
    //!@todo Implement OnOk
}

void VZSave::OnError()
{
    //!@todo Implement OnError
}

void VZSave::OnData(wxByte* pData, long lLength)
{
    if(lLength < 6)
        return;
    pData += 6;
    lLength -= 6;
    // Iterate through data, one voice at a time populating new voice objects
    if(m_nRxStatus == RX_STATUS_VOICE || m_nRxStatus == RX_STATUS_VOICE_OP)
    {
        if(lLength < (VZ_VOICE_PAYLOAD_SIZE + 1) * 64)
            return;
        for(unsigned int i = 0; i < 64; ++i)
        {
            m_vVoice.push_back(new VZVoice(pData, true));
            pData += VZ_VOICE_PAYLOAD_SIZE + 1;
        }
        lLength -= VZ_VOICE_PAYLOAD_SIZE * 64;
    }
    if(m_nRxStatus == RX_STATUS_OP || m_nRxStatus == RX_STATUS_VOICE_OP)
    {
        if(lLength < (VZ_OPERATION_PAYLOAD_SIZE + 1) * 64)
            return;
        for(unsigned int i = 0; i < 64; ++i)
        {
            m_vOperation.push_back(new VZOperation(pData, true));
            pData += VZ_OPERATION_PAYLOAD_SIZE + 1;
        }
    }
    m_nRxStatus = RX_STATUS_CLOSE;
}

VZSAVE_DATATYPE VZSave::GetAvailable()
{
    if (m_vOperation.size() > 0)
    {
        if(m_vVoice.size() > 0)
            return VZSAVE_DATATYPE_VOICE_OP;
        else
            return VZSAVE_DATATYPE_OP;
    }
    if(m_vVoice.size() > 0)
        return VZSAVE_DATATYPE_VOICE;
    return VZSAVE_DATATYPE_NONE;
}

VZVoice* VZSave::GetVoice(unsigned int nIndex)
{
    if(m_vVoice.size() > nIndex)
        return m_vVoice[nIndex];
    return NULL;
}

VZOperation* VZSave::GetOperation(unsigned int nIndex)
{
    if(m_vOperation.size() > nIndex)
        return m_vOperation[nIndex];
    return NULL;
}


bool VZSave::SaveToDisk(wxString sPath)
{
//    if(m_vVoice.size() == 0 && m_vOperation.size() == 0)
//        return; // Nothing to save
    VZLibrary vzLib(sPath);
    if(!vzLib.IsValid())
        return false;

    return true;
}
