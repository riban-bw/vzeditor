#ifndef KEYFOLLOW_H
#define KEYFOLLOW_H

#include <vector>

using namespace std;

#define MAX_KEYS 0x78

struct KeyFollow_Step
{
    unsigned int key = 60; //!< MIDI note value for the key in this step
    unsigned int level = 0; //!< Level of this step
};

class KeyFollow
{
    public:
        /** Construct KeyFollow object
        *   @param  nSteps Quantity of steps
        *   @param  bDCO True for DCO envelope
        */
        KeyFollow(unsigned int nSteps, bool bDCO);

        /** Destruct KeyFollow object
        */
        virtual ~KeyFollow();

        /** Get the quantity of steps in the envelope
        *   @retval unsigned int Quantity of steps
        */
        unsigned int GetSteps() { return m_vKFsteps.size(); }

        /** Get the key at specified step
        *   @param  nStep Step index
        *   @retval unsigned int Key for this step
        */
        unsigned int GetKey(unsigned int nStep);

        /** Set step key
        *   @param  nStep Step to update
        *   @param  nKey Key value for this step
        *   @retval bool True on success
        */
        bool SetKey(unsigned int nStep, unsigned int nKey);

        /** Get the level at specified step
        *   @param  nStep Step index
        *   @retval unsigned int Level for this step
        */
        unsigned int GetLevel(unsigned int nStep);

        /** Set level key
        *   @param  nStep Step to update
        *   @param  nLevel Level value for this step
        *   @retval bool True on success
        */
        bool SetLevel(unsigned int nStep, unsigned int nLevel);

    protected:

    private:
        vector<KeyFollow_Step*> m_vKFsteps; //!< Vector of key follow steps
        unsigned int m_nMaxValue; //!< Maximum value for each step
};

#endif // KEYFOLLOW_H
