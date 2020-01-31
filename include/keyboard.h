#pragma once

#include "wx/wx.h"

wxDECLARE_EVENT(KEYBOARD_NOTE_ON_EVENT, wxCommandEvent);
wxDECLARE_EVENT(KEYBOARD_NOTE_OFF_EVENT, wxCommandEvent);

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

    protected:

    private:
        void OnMouseLeftDown(wxMouseEvent &event); //Handle left mouse button press
        void OnMouseLeftUp(wxMouseEvent &event); //Handle left mouse button release
        void OnMotion(wxMouseEvent &event); //Handle mouse movement
        void OnEnterWindow(wxMouseEvent &event); //Handle mouse entering window
        void OnExitWindow(wxMouseEvent &event); //Handle mouse exiting window
        int GetNote(wxPoint pt); // Get the MIDI note for the screen position identified by pt, -1 for no key
        void SendNoteOn(int nNote); // Send a Note On event
        void SendNoteOff(int nNote); // Send a Note Off event

        unsigned int m_nNotes = 88; //Quantity of notes on keyboard
        unsigned int m_nFirstNote = 21; //Index of first note on keyboard
        unsigned int m_nKeyLength = 100;
        unsigned int m_nKeyWidth = 10;
        int m_nCurrentNote = -1; // Current MIDI note being played (monphonic). -1 for none

        DECLARE_EVENT_TABLE();

};

