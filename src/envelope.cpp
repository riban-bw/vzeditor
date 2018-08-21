#include "envelope.h"


Envelope::Envelope(wxByte nSteps) :
    m_nSustainStep(0)
{
    for(wxByte nStep = 0; nStep < nSteps; ++nStep)
        m_vEnvelopeSteps.push_back(new EnvelopeStep);
}

Envelope::~Envelope()
{
    for(wxByte nStep = 0; nStep < GetSteps(); ++nStep)
        delete m_vEnvelopeSteps[nStep];
}

bool Envelope::SetLevel(wxByte nStep, unsigned int nLevel)
{
    if(nStep >= GetSteps())
        return false;
    //!@todo Validate value
    m_vEnvelopeSteps[nStep]->level = nLevel;
    return true;
}

unsigned int Envelope::GetLevel(wxByte nStep)
{
    if(nStep >= GetSteps())
        return 0;
    return m_vEnvelopeSteps[nStep]->level;
}

bool Envelope::SetRate(wxByte nStep, unsigned int nRate)
{
    if(nStep >= GetSteps())
        return false;
    //!@todo Validate value
    m_vEnvelopeSteps[nStep]->rate = nRate;
    return true;
}

unsigned int Envelope::GetRate(wxByte nStep)
{
    if(nStep >= GetSteps())
        return 0;
    return m_vEnvelopeSteps[nStep]->rate;
}

bool Envelope::SetSustainStep(wxByte nStep)
{
    if(nStep >= GetSteps())
        return false;
    m_nSustainStep = nStep;
    return true;
}

unsigned int Envelope::GetSustainStep()
{
    return m_nSustainStep;
}

bool Envelope::IsVelocityRateEnabled(wxByte nStep)
{
    if(nStep >= GetSteps())
        return false;
    return m_vEnvelopeSteps[nStep]->velocityRate;
}

bool Envelope::EnableVelocityRate(wxByte nStep, bool bEnable)
{
    if(nStep > GetSteps())
        return false;
    m_vEnvelopeSteps[nStep]->velocityRate = bEnable;
    return true;
}

wxByte Envelope::GetLastStep()
{
    return m_nEndStep;
}

bool Envelope::IsLastStep(wxByte nStep)
{
    return (nStep == m_nEndStep);
}

bool Envelope::SetLastStep(wxByte nStep)
{
    if(nStep > GetSteps())
        return false;
    m_nEndStep = nStep;
    return true;
}

wxByte Envelope::GetAmpSens()
{
    return m_nAmpSens;
}

bool Envelope::SetAmpSens(wxByte nSensitivity)
{
    if(nSensitivity > 7)
        return false;
    m_nAmpSens = nSensitivity;
    return true;
}

wxByte Envelope::GetDepth()
{
    return m_nDepth;
}

bool Envelope::SetDepth(wxByte nDepth)
{
    if(nDepth > 99)
        return false;
    if(nDepth == 99)
        m_nDepth = 0x7F;
    else
        m_nDepth = nDepth;
    return true;
}
