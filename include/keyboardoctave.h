#ifndef KEYBOARDOCTAVE_H
#define KEYBOARDOCTAVE_H

//(*Headers(KeyboardOctave)
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class KeyboardOctave: public wxPanel
{
	public:

		KeyboardOctave(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~KeyboardOctave();

		//(*Declarations(KeyboardOctave)
		wxPanel* m_pPnlKeyA;
		wxPanel* m_pPnlKeyB;
		wxPanel* m_pPnlKeyC;
		wxPanel* m_pPnlKeyD;
		wxPanel* m_pPnlKeyE;
		wxPanel* m_pPnlKeyF;
		wxPanel* m_pPnlKeyG;
		//*)

	protected:

		//(*Identifiers(KeyboardOctave)
		static const long ID_PNLKEYC;
		static const long ID_PNLKEYD;
		static const long ID_PNLKEYE;
		static const long ID_PNLKEYF;
		static const long ID_PNLKEYG;
		static const long ID_PNLKEYA;
		static const long ID_PNLKEYB;
		//*)

	private:

		//(*Handlers(KeyboardOctave)
		void OnKeyDown(wxMouseEvent& event);
		void OnKeyUp(wxMouseEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
