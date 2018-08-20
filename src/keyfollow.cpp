#include "keyfollow.h"

KeyFollow::KeyFollow(unsigned int nSteps, bool bDCO) :
    m_nMaxValue(0x7F)
{
    for(unsigned int nStep = 0; nStep < nSteps; ++nSteps)
        m_vKFsteps.push_back(new KeyFollow_Step());
    if(bDCO)
        m_nMaxValue = 0x3F;
}

KeyFollow::~KeyFollow()
{
    for(unsigned int nStep = 0; nStep < GetSteps(); ++nStep)
        delete m_vKFsteps[nStep];
}

unsigned int KeyFollow::GetKey(unsigned int nStep)
{
    if(nStep > GetSteps())
        return 0;
    return m_vKFsteps[nStep]->key;
}

bool KeyFollow::SetKey(unsigned int nStep, unsigned int nKey)
{
    if(nStep > GetSteps() || nKey > MAX_KEYS)
        return false;
    m_vKFsteps[nStep]->key = nKey;
    return true;
}

unsigned int KeyFollow::GetLevel(unsigned int nStep)
{
    if(nStep > GetSteps())
        return 0;
    return m_vKFsteps[nStep]->level;
}

bool KeyFollow::SetLevel(unsigned int nStep, unsigned int nLevel)
{
    if(nStep > GetSteps() || nLevel > m_nMaxValue)
        return false;
    m_vKFsteps[nStep]->level = nLevel;
    return true;
}
