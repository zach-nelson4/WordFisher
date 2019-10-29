#include "../include/HistoryWindow.h"
#include "../include/History.h"

//(*InternalHeaders(HistoryWindow)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(HistoryWindow)
//*)

BEGIN_EVENT_TABLE(HistoryWindow,wxDialog)
	//(*EventTable(HistoryWindow)
	//*)
END_EVENT_TABLE()

HistoryWindow::HistoryWindow(wxWindow* parent, History* h)
{
	//(*Initialize(HistoryWindow)
	wxXmlResource::Get()->LoadObject(this,parent,_T("HistoryWindow"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	StaticText4 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT4"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	TextCtrl4 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL4"));
	TextCtrl5 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL5"));
	TextCtrl6 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL6"));
	TextCtrl7 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL7"));
	TextCtrl8 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL8"));
	TextCtrl9 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL9"));
	TextCtrl10 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL10"));
	TextCtrl11 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL11"));
	TextCtrl12 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL12"));
	TextCtrl13 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL13"));
	TextCtrl14 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL14"));
	TextCtrl15 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL15"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));
	Button5 = (wxButton*)FindWindow(XRCID("ID_BUTTON5"));
	Button6 = (wxButton*)FindWindow(XRCID("ID_BUTTON6"));
	H = h;

	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&HistoryWindow::OnButton1Click);
	//*)

	//Filling the history boxes

    std::string stlString;

    //First row
	if(H->length() > 0){
	    //Filename
        stlString = H->getFile(0);
        wxString I(stlString.c_str(), wxConvUTF8);
        TextCtrl1->ChangeValue(I);

        //Search
        stlString = H->getWas(0);
        wxString J(stlString.c_str(), wxConvUTF8);
        TextCtrl2->ChangeValue(J);

        //Replace
        stlString = H->getBecome(0);
        wxString K(stlString.c_str(), wxConvUTF8);
        TextCtrl3->ChangeValue(K);
	}
	//Second row
		if(H->length() > 1){
	    //Filename
        stlString = H->getFile(1);
        wxString L(stlString.c_str(), wxConvUTF8);
        TextCtrl4->ChangeValue(L);

        //Search
        stlString = H->getWas(1);
        wxString M(stlString.c_str(), wxConvUTF8);
        TextCtrl5->ChangeValue(M);

        //Replace
        stlString = H->getBecome(1);
        wxString N(stlString.c_str(), wxConvUTF8);
        TextCtrl6->ChangeValue(N);
	}

}

HistoryWindow::~HistoryWindow()
{
	//(*Destroy(HistoryWindow)
	//*)
}


void HistoryWindow::OnButton1Click(wxCommandEvent& event)
{
    Close();
}
