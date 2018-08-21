#ifndef ENVELOPE_H
#define ENVELOPE_H
#include <vector>
#include "wx/wx.h"

using namespace std;

struct EnvelopeStep
{
    wxByte level;
    wxByte rate;
    wxByte ampSens;
    bool velocityRate;
};

class Envelope
{
    public:
        /** @brief  Construct envelope object
        *   @param nSteps Quantity of steps in envelope [Default: 8]
        */
        Envelope(wxByte nSteps = 8);

        /** @brief  Destruct envelope object*/
        virtual ~Envelope();

        /** @brief  Get the quantity of steps in the envelope
        *   @retval unsigned int Quantity of steps
        */
        unsigned int GetSteps() { return m_vEnvelopeSteps.size(); }

        /** @brief  Set step level
        *   @param nStep Step index
        *   @param nLevel Step level
        *   @retval bool True on success
        */
        bool SetLevel(wxByte nStep, unsigned int nLevel);

        /** @brief  Get step level
        *   @param nStep Step index
        *   @retval unsigned int Value of step level
        */
        unsigned int GetLevel(wxByte nStep);

        /** @brief  Set step rate
        *   @param nStep Step index
        *   @param nRate Step rate
        *   @retval bool True on success
        */
        bool SetRate(wxByte nStep, unsigned int nRate);

        /** @brief  Get step rate
        *   @param nStep Step index
        *   @retval unsigned int Value of step rate
        */
        unsigned int GetRate(wxByte nStep);

        /** @brief  Set sustain step
        *   @param nStep Step index
        *   @retval bool True on success
        */
        bool SetSustainStep(wxByte nStep);

        /** @brief  Get sustain step
        *   @retval unsigned int Index of sustain step
        */
        unsigned int GetSustainStep();

        /** @brief  Is velocity rate enabled for a step
        *   @param  nStep Step index
        *   @retval bool True if velocity rate enabled
        */
        bool IsVelocityRateEnabled(wxByte nStep);

        /** @brief  Enable / disable velocity rate for a step
        *   @param  nStep   Step index
        *   @param  bEnable True to enable velocity reate for this step [Default: true]
        *   @retval bool True on success
        */
        bool EnableVelocityRate(wxByte nStep, bool bEnable = true);

        /** @brief  Gets the index of the last step of the envelope
        *   @retval wxByte Index of last step
        */
        wxByte GetLastStep();

        /** @brief  Is step last in envelope
        *   @param  nStep Step index
        *   @retval bool Index of last step
        */
        bool IsLastStep(wxByte nStep);

        /** @brief  Sets the index of the last step of the envelope
        *   @param  nStep Index of last step
        *   @retval bool rue on success
        */
        bool SetLastStep(wxByte nStep);

        /** @brief Gets amplitude sensitivity
        *   @retval wxByte Amplitude sensitivity
        */
        wxByte GetAmpSens();

        /** @brief  Sets amplitude sensitivity
        *   @param  nSensitivity
        *   @retval bool True on success
        */
        bool SetAmpSens(wxByte nSensitivity);

        /** @brief  Get envelope depth
        *   @retval wxByte Envelope depth
        */
        wxByte GetDepth();

        /** @brief  Set envelope depth
        *   @param  nDepth Envelope depth [0..99]
        *   @retval bool True on succes
        *   @todo   DCO has range [63..0]
        *   @todo   Range is inverted (0..99 == 127..0)
        */
        bool SetDepth(wxByte nDepth);

    protected:

    private:
        vector<EnvelopeStep*> m_vEnvelopeSteps; //!< Vector of pointers to steps in envelope
        wxByte m_nSustainStep; //!< Index of sustain step
        wxByte m_nEndStep; //!< Index of end step
        wxByte m_nAmpSens; //!< Amplitude sensitivity
        wxByte m_nDepth; //!< Envelope depth
};

#endif // ENVELOPE_H
