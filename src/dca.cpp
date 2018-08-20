#include "dca.h"

DCA::DCA() :
    m_nEnvDepth(0),
    m_nKeySensitivity(7),
    m_nKeyCurve(0),
    m_nControllerSensitivity(7)
{
    m_pEnvelope = new Envelope(8);
    m_pKeyfollow = new KeyFollow(6, false);
}

DCA::~DCA()
{
    delete m_pEnvelope;
    delete m_pKeyfollow;
}

Envelope* DCA::GetEnvelope()
{
    return m_pEnvelope;
}

unsigned int DCA::GetEnvelopeDepth()
{
    return m_nEnvDepth;
}

bool DCA::SetEnvelopeDepth(unsigned int nDepth)
{
    if(nDepth > 0x7F)
        return false;
    m_nEnvDepth = nDepth;
    return true;
}

KeyFollow* DCA::GetKeyFollow()
{
    return m_pKeyfollow;
}

unsigned int DCA::GetKeySensitivity()
{
    return m_nKeySensitivity;
}

bool DCA::SetKeySensitivity(unsigned int nSensitivity)
{
    if(nSensitivity > 0x1F)
        return false;
    m_nKeySensitivity = nSensitivity;
    return true;
}

unsigned int DCA::GetKeyCurve()
{
    return m_nKeyCurve;
}

bool DCA::SetKeyCurve(unsigned int nCurve)
{
    if(nCurve > 7)
        return false;
    m_nKeyCurve = nCurve;
    return true;
}

unsigned int DCA::GetControllerSensitivity()
{
    return m_nControllerSensitivity;
}

bool DCA::SetControllerSensitivity(unsigned int nSensitivity)
{
    if(nSensitivity > 7)
        return false;
    m_nControllerSensitivity= nSensitivity;
    return true;
}
