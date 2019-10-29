#ifndef VIEWERDIALOG_H
#define VIEWERDIALOG_H

#include "../include/History.h"

//(*Headers(ViewerDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ViewerDialog: public wxDialog
{
	public:

		ViewerDialog(wxWindow* parent);
		ViewerDialog(wxWindow* parent, History* H);
		virtual ~ViewerDialog();

		//(*Declarations(ViewerDialog)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;

		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl6;
        wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl9;
		wxTextCtrl* TextCtrl10;
		wxTextCtrl* TextCtrl11;
		wxTextCtrl* TextCtrl12;
		//*)

		std::string ReturnFileName(){ return FileName;}
		std::string ReturnSearchName(){ return SearchName;}
		std::string ReturnReplaceName(){ return ReplaceName;}
		wxString ReturnFileNameWX(){ return FileNameWX;}

	protected:

		//(*Identifiers(ViewerDialog)
		//*)

		std::string FileName;
		std::string SearchName;
		std::string ReplaceName;
        wxString FileNameWX;
        History* h;

	private:

		//(*Handlers(ViewerDialog)
		void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
		void OnButton7Click(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
