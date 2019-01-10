#include "vzoperation.h"

vzoperation::vzoperation() :
    vzsysex(VZ_OPERATION_PAYLOAD_SIZE)
{
}

vzoperation::vzoperation(wxByte* pData) :
    vzsysex(pData, VZ_OPERATION_PAYLOAD_SIZE)
{
}

vzoperation::~vzoperation()
{
}

