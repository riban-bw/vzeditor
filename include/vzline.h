#ifndef VZLINE_H
#define VZLINE_H

//(*Headers(VZLine)
#include "vzmodule.h"
#include <wx/panel.h>
#include <wx/sizer.h>
//*)
#include "vzvoice.h"

class VZLine: public wxPanel
{
	public:

        /** @brief  Construct a VZ Internal Line GUI object
        *   @param  parent Pointer to the parent window
        *   @param  line Index of this line [0..3]
        */
		VZLine(wxWindow* parent, wxByte line);

		/** @brief  Destruct a VZ Internal Line GUI object
        */
		virtual ~VZLine();

		/** @brief  Set the vzvoice data
        *   @param  pVoice Pointer to the voice data
        */
        void SetVoice(vzvoice* pVoice);

		/** @brief  Update the GUI from voice data
        */
        void UpdateGui();

		//(*Declarations(VZLine)
		VZModule* m_pVzModule1;
		VZModule* m_pVzModule2;
		//*)

	protected:

		//(*Identifiers(VZLine)
		static const long ID_VZMODULE1;
		static const long ID_VZMODULE2;
		//*)

	private:

	    wxByte m_nLine;
	    vzvoice* m_pvzVoice;

		//(*Handlers(VZLine)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
