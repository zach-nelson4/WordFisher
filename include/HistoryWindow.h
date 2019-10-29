#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include "../include/History.h"

//(*Headers(HistoryWindow)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class HistoryWindow: public wxDialog
{
	public:

		HistoryWindow(wxWindow* parent, History* h);
		virtual ~HistoryWindow();

		//(*Declarations(HistoryWindow)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl10;
		wxTextCtrl* TextCtrl11;
		wxTextCtrl* TextCtrl12;
		wxTextCtrl* TextCtrl13;
		wxTextCtrl* TextCtrl14;
		wxTextCtrl* TextCtrl15;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl6;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl9;
		//*)

	protected:

		//(*Identifiers(HistoryWindow)
		//*)
		History* H;

	private:

		//(*Handlers(HistoryWindow)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
