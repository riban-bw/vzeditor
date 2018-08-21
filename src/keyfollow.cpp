#include "keyfollow.h"

KeyFollow::KeyFollow(wxByte nSteps, bool bDCO) :
    m_nMaxValue(0x7F)
{
    for(wxByte nStep = 0; nStep < nSteps; ++nSteps)
        m_vKFsteps.push_back(new KeyFollow_Step());
    if(bDCO)
        m_nMaxValue = 0x3F;
}

KeyFollow::~KeyFollow()
{
    for(wxByte nStep = 0; nStep < GetSteps(); ++nStep)
        delete m_vKFsteps[nStep];
}

wxByte KeyFollow::GetKey(wxByte nStep)
{
    if(nStep > GetSteps())
        return 0;
    return m_vKFsteps[nStep]->key;
}

bool KeyFollow::SetKey(wxByte nStep, wxByte nKey)
{
    if(nStep > GetSteps() || nKey > MAX_KEYS)
        return false;
    m_vKFsteps[nStep]->key = nKey;
    return true;
}

wxByte KeyFollow::GetLevel(wxByte nStep)
{
    if(nStep > GetSteps())
        return 0;
    return m_vKFsteps[nStep]->level;
}

bool KeyFollow::SetLevel(wxByte nStep, wxByte nLevel)
{
    if(nStep > GetSteps() || nLevel > m_nMaxValue)
        return false;
    m_vKFsteps[nStep]->level = nLevel;
    return true;
}
