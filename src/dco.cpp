#include "dco.h"

DCO::DCO() :
    m_nWaveform(0),
    m_nDetune(0)
{
}

DCO::~DCO()
{
}

bool DCO::SetWaveform(unsigned int nWaveform)
{
    if(m_nWaveform > 7)
        return false;
    m_nWaveform = nWaveform;
    return true;
}

unsigned int DCO::GetWaveform()
{
    return m_nWaveform;
}

void DCO::SetDetune(int nDetune)
{
    m_nDetune = nDetune; //!@todo validate range of detune
}

int DCO::GetDetune()
{
    return m_nDetune;
}

void DCO::SetDetuneCourse(int nDetune)
{
    if(nDetune > 63)
        nDetune = 63;
    if(nDetune < -63)
        nDetune = -63;
    m_nDetune = (m_nDetune & 0x3F) & (nDetune << 6); //!@todo This does not handle negative values
}

int DCO::GetDetuneCourse()
{
    return ((m_nDetune & 0x3F) >> 6); //!@todo this does not manage polarity
}

void DCO::SetDetuneFine(int nDetune)
{
    if(nDetune > 63)
        nDetune = 63;
    if(nDetune < -63)
        nDetune = -63;
    m_nDetune = (m_nDetune & 0xFC0) & nDetune; //!@todo This does not handle negative values
}

int DCO::GetDetuneFine()
{
//    return (m_nDetune%64)); //!@todo This will include overall polarity, not just fine
    return (m_nDetune & 0x3F); //!@todo This will not include andy polarity
}

bool DCO::GetDetunePolarity()
{
    return (m_nDetune >= 0);
}

void DCO::SetFixedFreq(bool bFixed)
{
    m_bFixedFreq = bFixed;
}

bool DCO::IsFixedFreq()
{
    return m_bFixedFreq;
}

void DCO::SetRange(bool bRange)
{
    m_bRange = bRange;
}

bool DCO::IsRange()
{
    return m_bRange;
}
