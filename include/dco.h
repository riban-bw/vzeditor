#ifndef DCO_H
#define DCO_H

class DCO
{
    public:
        /** Default constructor */
        DCO();
        /** Default destructor */
        virtual ~DCO();

        /** Set DCO waveform
        *   @param  nWaveform Waveform type
        *   @retval bool True on success
        *   @todo   Use enumeration for waveform [0:SINE 1:SAW1 2:SAW2 3:SAW3 4:SAW4 5:SAW5 6:NOISE1 7:NOISE2]
        */
        bool SetWaveform(unsigned int nWaveform);

        /** Get DCO waveform
        *   @retval unsigned int Waveform type
        */
        unsigned int GetWaveform();

        /** Set DCO Detune
        *   @param  nDetune Detune offset in 1/64 note durations
        */
        void SetDetune(int nDetune);

        /** Get DCO Detune
        *   @retval int Detune offset in 1/64 note durations
        */
        int GetDetune();

        /** Set DCO Detune Course
        *   @param  nDetune Detune offset in note durations
        *   @note   Does not alter fine detune element
        */
        void SetDetuneCourse(int nDetune);

        /** Get DCO Detune Course
        *   @retval int Course detune offset element in note durations
        */
        int GetDetuneCourse();

        /** Set DCO Detune Fine
        *   @param  nDetune Detune offset in 1/64 note durations
        *   @note   Does not alter course detune element
        */
        void SetDetuneFine(int nDetune);

        /** Get DCO Detune Fine
        *   @retval int Fine detune offset element in 1/64 note durations
        */
        int GetDetuneFine();

        /** Get DCO Detune polarity
        *   @retval bool True if detune is positive
        */
        bool GetDetunePolarity();

        /** Set DCO to fixed frequency
        *   @param  bFixed True to set to fixed frequency
        */
        void SetFixedFreq(bool bFixed);

        /** Is DCO set to fixed frequency?
        *   @retval bool True if DCO set to fixed frequency
        */
        bool IsFixedFreq();

        /** Set DCO fixed frequency x16
        *   @param  bRange True to set to fixed frequency range to x16
        */
        void SetRange(bool bRange);

        /** Is DCO fixed frequency range set to x16?
        *   @retval bool True if DCO fixed frequency range set to x16
        */
        bool IsRange();

    protected:

    private:
        unsigned int m_nWaveform; //!< DCO waveform
        int m_nDetune; //!< Detune offset
        bool m_bFixedFreq; //!< True if DCO frequency fixed
        bool m_bRange; //!< True if fixed frequency is scaled x16
};

#endif // DCO_H
