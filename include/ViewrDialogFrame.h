#ifndef VIEWRDIALOGFRAME_H
#define VIEWRDIALOGFRAME_H

//(*Headers(ViewrDialogFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ViewrDialogFrame: public wxFrame
{
	public:

		ViewrDialogFrame(wxWindow* parent);
		virtual ~ViewrDialogFrame();

		//(*Declarations(ViewrDialogFrame)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxMenuBar* MenuBar1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

        std::string ReturnFileName(){ return FileName;}
		std::string ReturnSearchName(){ return SearchName;}
		std::string ReturnReplaceName(){ return ReplaceName;}

	protected:

		//(*Identifiers(ViewerDialog)
		//*)

		std::string FileName;
		std::string SearchName;
		std::string ReplaceName;

	private:

		//(*Handlers(ViewrDialogFrame)
        void OnButton2Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnInit(wxInitDialogEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
