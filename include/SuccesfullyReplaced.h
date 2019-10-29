#ifndef SUCCESFULLYREPLACED_H
#define SUCCESFULLYREPLACED_H

//(*Headers(SuccesfullyReplaced)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
//*)

class SuccesfullyReplaced: public wxDialog
{
	public:

		SuccesfullyReplaced(wxWindow* parent);
		virtual ~SuccesfullyReplaced();

		//(*Declarations(SuccesfullyReplaced)
		wxButton* Button1;
		wxStaticText* StaticText1;
		//*)

	protected:

		//(*Identifiers(SuccesfullyReplaced)
		//*)

	private:

		//(*Handlers(SuccesfullyReplaced)
		void OnButton1Click(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
