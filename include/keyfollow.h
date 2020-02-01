/***************************************************************
 * Name:      keyfollow.h
 * Purpose:   Defines KeyFollow class
 * Author:    Brian Walton (brian@riban.co.uk)
 * Created:   2018-08-20
 * Copyright: Brian Walton (riban.co.uk)
 * License:   GPL3
 **************************************************************/

#pragma once

#include "wx/wx.h"
#include <vector>

using namespace std;

#define MAX_KEYS 0x78

struct KeyFollow_Step
{
    wxByte key = 60; //!< MIDI note value for the key in this step
    wxByte level = 0; //!< Level of this step
};

class KeyFollow
{
public:
    /** @brief  Construct KeyFollow object
    *   @param  nSteps Quantity of steps [Default: 6]
    *   @param  bDCO True for DCO envelope [Default: false]
    */
    KeyFollow(wxByte nSteps = 6, bool bDCO = false);

    /** @brief  Destruct KeyFollow object
    */
    virtual ~KeyFollow();

    /** @brief  Get the quantity of steps in the envelope
    *   @retval wxByte Quantity of steps
    */
    wxByte GetSteps()
    {
        return m_vKFsteps.size();
    }

    /** @brief  Get the key at specified step
    *   @param  nStep Step index
    *   @retval wxByte Key for this step
    */
    wxByte GetKey(wxByte nStep);

    /** @brief  Set step key
    *   @param  nStep Step to update
    *   @param  nKey Key value for this step
    *   @retval bool True on success
    */
    bool SetKey(wxByte nStep, wxByte nKey);

    /** @brief  Get the level at specified step
    *   @param  nStep Step index
    *   @retval wxByte Level for this step
    */
    wxByte GetLevel(wxByte nStep);

    /** @brief  Set level key
    *   @param  nStep Step to update
    *   @param  nLevel Level value for this step
    *   @retval bool True on success
    */
    bool SetLevel(wxByte nStep, wxByte nLevel);

protected:

private:
    vector<KeyFollow_Step*> m_vKFsteps; //!< Vector of key follow steps
    wxByte m_nMaxValue; //!< Maximum value for each step
};
