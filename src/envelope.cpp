/***************************************************************
 * Name:      envelope.cpp
 * Purpose:   Implements Envelope class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-20
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

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
    if(nLevel > 99)
        nLevel = 0x7F;
    m_vEnvelopeSteps[nStep]->level = nLevel;
    return true;
}

unsigned int Envelope::GetLevel(wxByte nStep)
{
    if(nStep >= GetSteps())
        return 0;
    wxByte nLevel = m_vEnvelopeSteps[nStep]->level;
    if(nLevel > 99)
        nLevel = 99;
    return nLevel;
}

bool Envelope::SetRate(wxByte nStep, unsigned int nRate)
{
    if(nStep >= GetSteps())
        return false;
    if(nRate > 99)
        nRate = 0x7F;
    m_vEnvelopeSteps[nStep]->rate = nRate;
    return true;
}

unsigned int Envelope::GetRate(wxByte nStep)
{
    if(nStep >= GetSteps())
        return 0;
    wxByte nRate = m_vEnvelopeSteps[nStep]->rate;
    if(nRate > 99)
        nRate = 99;
    return nRate;
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
        nSensitivity = 7;
    m_nAmpSens = nSensitivity;
    return true;
}

wxByte Envelope::GetDepth()
{
    return m_nDepth;
}

bool Envelope::SetDepth(wxByte nDepth)
{
    if(nDepth > 98)
        nDepth = 0x7F;
    m_nDepth = nDepth;
    return true;
}
