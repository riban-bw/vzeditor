#include "vzoperation.h"

vzoperation::vzoperation() :
    vzsysex(VZ_OPERATION_PAYLOAD_SIZE)
{
}

vzoperation::vzoperation(wxByte* pData) :
    vzsysex(VZ_OPERATION_PAYLOAD_SIZE, pData)
{
}

vzoperation::~vzoperation()
{
}

bool vzoperation::Validate(bool bFix)
{
    vzsysex::Validate(bFix);
    m_bModified |= ValidateByte(m_pSysEx + 5, 0x01, bFix);
    m_bModified |= ValidateByte(m_pSysEx + 6, 0x40, bFix);
    return m_bModified;
}

wxString vzoperation::GetName()
{
    wxString sName;
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
    {
        sName += wxString::FromAscii(GetByteFromSysex(1 + nIndex));
    }
    return sName.Trim();
}

void vzoperation::SetName(wxString sName)
{
    sName.Truncate(12);
    sName.Pad(12 - sName.Length());
    for(unsigned int nIndex = 0; nIndex < 12; ++nIndex)
        PutByteToSysex(1 + nIndex, sName[nIndex]);
}
