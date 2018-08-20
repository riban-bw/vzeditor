#ifndef DCA_H
#define DCA_H
#include <vector>
#include "envelope.h"
#include "keyfollow.h"

class DCA
{
    public:
        /** Default constructor */
        DCA();
        /** Default destructor */
        virtual ~DCA();

        /** @brief  Get a pointer to the envelope
        *   @retval Envelope* Pointer to the envelope
        */
        Envelope* GetEnvelope();

        /** @brief  Get envelope depth
        *   @retval unsigned int Envelope depth
        */
        unsigned int GetEnvelopeDepth();

        /** @brief  Set envelope depth
        *   @param  nDepth unsigned int Envelope depth
        *   @retval bool True on success
        */
        bool SetEnvelopeDepth(unsigned int nDepth);

        /** @brief  Get a pointer to the key follow
        *   @retval KeyFollow* Pointer to the key follow
        */
        KeyFollow* GetKeyFollow();

        /** @brief  Get key sensitivity
        *   @retval unsigned int Key sensitivity
        */
        unsigned int GetKeySensitivity();

        /** @brief  Set key sensitivity
        *   @param  nSensitivity unsigned int Key sensitivity
        *   @retval bool True on success
        */
        bool SetKeySensitivity(unsigned int nSensitivity);

        /** @brief  Get key curve
        *   @retval unsigned int Key curve
        */
        unsigned int GetKeyCurve();

        /** @brief  Set key curve
        *   @param  nCurve unsigned int Key curve
        *   @retval bool True on success
        */
        bool SetKeyCurve(unsigned int nCurve);

        /** @brief  Get controller sensitivity
        *   @retval unsigned int Controller sensitivity
        */
        unsigned int GetControllerSensitivity();

        /** @brief  Set controller sensitivity
        *   @param  nCurve unsigned int Controller sensitivity
        *   @retval bool True on success
        */
        bool SetControllerSensitivity(unsigned int nSensitivity);

    protected:

    private:
        Envelope* m_pEnvelope; //!< 8 step amplitude envelope
        unsigned int m_nEnvDepth; //!< Depth of envelope
        KeyFollow* m_pKeyfollow; //!< 6 step keyboard follow curve
        unsigned int m_nKeySensitivity; //!< Sensitivity of key velocity
        unsigned int m_nKeyCurve; //!< Key velocity curve
        unsigned int m_nControllerSensitivity; //!< Sensitivity to continuous controlers
};

#endif // DCA_H
