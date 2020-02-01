#pragma once

#include "wx/wx.h"

wxDECLARE_EVENT(KEYBOARD_NOTE_ON_EVENT, wxCommandEvent);
wxDECLARE_EVENT(KEYBOARD_NOTE_OFF_EVENT, wxCommandEvent);

class KeyboardEventData : public wxClientData
{
    public:
        unsigned int channel;
        unsigned int note;
        unsigned int velocity;
};

class Keyboard : public wxControl
{
    public:
        DECLARE_DYNAMIC_CLASS(Keyboard);

        // Default constructor
        Keyboard();
        // Constructor
        Keyboard(wxWindow* parent, wxWindowID id = -1);
        // Destructor
        virtual ~Keyboard();

        //Overrides
        wxSize DoGetBestSize() const;
        void OnPaint(wxPaintEvent& event);
        void SetMinSize(const wxSize& size);

        /** @brief  Set quantity of notes to show
        *   @param  nNotes Quantity of notes
        */
        void SetNotes(unsigned int nNotes);

        /** @brief  Get quantity of notes shown
        *   @retval unsigned int Quantity of notes
        */
        unsigned int GetNotes();

        /** @brief  Set first notes of keyboard
        *   @param  nNote Index of first note
        */
        void SetFirstNote(unsigned int nNote);

        /** @brief  Get first note of keyboard
        *   @retval unsigned int First note
        */
        unsigned int GetFirstNote();

        /** @brief  Set MIDI send channel
        *   @param  nChannel MIDI channel to transmit [0..15]
        */
        void SetSendChannel(unsigned int nChannel);

        /** @brief  Get MIDI send channel
        *   @retval unsigned int MIDI send channel
        */
        unsigned int GetSendChannel();

    protected:

    private:
        void OnMouseLeftDown(wxMouseEvent &event); //Handle left mouse button press
        void OnMouseLeftUp(wxMouseEvent &event); //Handle left mouse button release
        void OnMotion(wxMouseEvent &event); //Handle mouse movement
        void OnExitWindow(wxMouseEvent &event); //Handle mouse exiting window
        unsigned int GetNote(wxPoint pt); // Get the MIDI note for the screen position identified by pt, 255 for no key
        unsigned int GetVelocity(wxPoint pt); // Get the MIDI note velocity for the screen position identified by pt, default 0
        void SendNoteOn(unsigned int nChannel, unsigned int nNote, unsigned int nVelocity); // Send a Note On event
        void SendNoteOff(unsigned int nChannel, unsigned int nNote, unsigned int nVelocity = 0); // Send a Note Off event
        void OnSize(wxSizeEvent &event); //Handle window resizing
        void SetOffset(); // Update the offset

        unsigned int m_nNotes = 88; //Quantity of notes on keyboard
        unsigned int m_nFirstNote = 21; //Index of first note on keyboard
        unsigned int m_nTxChannel = 0; // MIDI transmit channel
        unsigned int m_nKeyLength = 100;
        unsigned int m_nKeyWidth = 20;
        unsigned int m_nMinKeyWidth = 10;
        unsigned int m_nMinKeyLength = 30;
        unsigned int m_nOffset = 0;
        unsigned int m_nCurrentNote = 255; // Current MIDI note being played (monphonic). 255 for none
        KeyboardEventData m_clientData;

        DECLARE_EVENT_TABLE();

};

