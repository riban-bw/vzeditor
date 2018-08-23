#ifndef VZLINE_H
#define VZLINE_H

//(*Headers(VZLine)
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class VZLine: public wxPanel
{
	public:

		VZLine(wxWindow* parent);
		virtual ~VZLine();

		//(*Declarations(VZLine)
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(VZLine)
		static const long ID_STATICTEXT1;
		//*)

	private:

		//(*Handlers(VZLine)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
