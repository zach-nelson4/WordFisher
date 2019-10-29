#include "../include/ViewerDialog.h"
#include  <wx/filedlg.h>
#include <wx/wfstream.h>
#include "../include/History.h"

//(*InternalHeaders(ViewerDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(ViewerDialog)
//*)

BEGIN_EVENT_TABLE(ViewerDialog,wxDialog)
	//(*EventTable(ViewerDialog)
	//*)
END_EVENT_TABLE()

ViewerDialog::ViewerDialog(wxWindow* parent)
{
	//(*Initialize(ViewerDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("ViewerDialog"),_T("wxDialog"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));

	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	StaticText4 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT4"));

	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton1Click);
	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton2Click);
	Connect(XRCID("ID_BUTTON3"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton3Click);
    Connect(XRCID("ID_BUTTON5"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton5Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ViewerDialog::OnInit);
	//*)
}


ViewerDialog::ViewerDialog(wxWindow* parent, History* H)
{
	//(*Initialize(ViewerDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("ViewerDialog"),_T("wxDialog"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));
    Button5 = (wxButton*)FindWindow(XRCID("ID_BUTTON5"));
    Button6 = (wxButton*)FindWindow(XRCID("ID_BUTTON6"));
    Button7 = (wxButton*)FindWindow(XRCID("ID_BUTTON7"));
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
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	StaticText4 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT4"));

	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton1Click);
	Connect(XRCID("ID_BUTTON2"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton2Click);
	Connect(XRCID("ID_BUTTON3"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton3Click);
	Connect(XRCID("ID_BUTTON4"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton4Click);
	Connect(XRCID("ID_BUTTON5"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton5Click);
    Connect(XRCID("ID_BUTTON6"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton6Click);
	Connect(XRCID("ID_BUTTON7"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ViewerDialog::OnButton7Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&ViewerDialog::OnInit);
	h = H;
	//*)

}

ViewerDialog::~ViewerDialog()
{
	//(*Destroy(ViewerDialog)
	//*)
}


void ViewerDialog::OnButton2Click(wxCommandEvent& event)
{
    Close();
}

void ViewerDialog::OnButton3Click(wxCommandEvent& event)
{
    std::string stlString = "Open CPP file";
    wxString w(stlString.c_str(), wxConvUTF8);

    std::string emptyString = "";
    wxString emp(emptyString.c_str(), wxConvUTF8);

    std::string openFiles = "CPP Files (*.cpp)|*.cpp|(*.cc)|*.cc";
    wxString filetypes(openFiles.c_str(), wxConvUTF8);

    wxFileDialog openFileDialog(this, (w), emp, emp, filetypes, wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxFileInputStream input_stream(openFileDialog.GetPath());
    if(!input_stream.IsOk())
    {
        //wxLogError("Cannot open file '%s'.", openFileDialog.GetPath());
        return;
    }
    TextCtrl1->ChangeValue(openFileDialog.GetPath());
}


void ViewerDialog::OnButton1Click(wxCommandEvent& event)
{
    //Converts the first textbox into a usable string
    wxString s = TextCtrl1->GetValue();
    FileNameWX = s;

    for (wxString::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        char toConvert;
        wchar_t wch = *it;
        toConvert = (char)wch;
        FileName = FileName + toConvert;


    }

    //Converts the second textbox into a usable string
    s = TextCtrl2->GetValue();
    for (wxString::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        char toConvert;
        wchar_t wch = *it;
        toConvert = (char)wch;
        SearchName = SearchName + toConvert;

    }

    //Converts the third textbox into a usable string
    s = TextCtrl3->GetValue();
        for (wxString::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        char toConvert;
        wchar_t wch = *it;
        toConvert = (char)wch;
        ReplaceName = ReplaceName + toConvert;

    }

    Close();

}

void ViewerDialog::OnButton4Click(wxCommandEvent& event)
{

    std::string stlString;

    //First row
	if(h->length() > 0){
	    //Filename
        stlString = h->getFile(0);
        wxString I(stlString.c_str(), wxConvUTF8);
        TextCtrl4->ChangeValue(I);

        //Search
        stlString = h->getWas(0);
        wxString J(stlString.c_str(), wxConvUTF8);
        TextCtrl5->ChangeValue(J);

        //Replace
        stlString = h->getBecome(0);
        wxString K(stlString.c_str(), wxConvUTF8);
        TextCtrl6->ChangeValue(K);
	}

	//Second row
    if(h->length() > 1){
	    //Filename
        stlString = h->getFile(1);
        wxString L(stlString.c_str(), wxConvUTF8);
        TextCtrl7->ChangeValue(L);

        //Search
        stlString = h->getWas(1);
        wxString M(stlString.c_str(), wxConvUTF8);
        TextCtrl8->ChangeValue(M);

        //Replace
        stlString = h->getBecome(1);
        wxString N(stlString.c_str(), wxConvUTF8);
        TextCtrl9->ChangeValue(N);
	}

	//Third Row
    if(h->length() > 2){
	    //Filename
        stlString = h->getFile(2);
        wxString O(stlString.c_str(), wxConvUTF8);
        TextCtrl10->ChangeValue(O);

        //Search
        stlString = h->getWas(2);
        wxString P(stlString.c_str(), wxConvUTF8);
        TextCtrl11->ChangeValue(P);

        //Replace
        stlString = h->getBecome(2);
        wxString Q(stlString.c_str(), wxConvUTF8);
        TextCtrl12->ChangeValue(Q);
	}

}

void ViewerDialog::OnButton5Click(wxCommandEvent& event)
{
    if(h->length()>0){
        FileName = h->getFile(0);
        SearchName = h->getBecome(0);
        ReplaceName = h->getWas(0);
    }

    Close();
}

void ViewerDialog::OnButton6Click(wxCommandEvent& event)
{
    if(h->length()>1){
        FileName = h->getFile(1);
        SearchName = h->getBecome(1);
        ReplaceName = h->getWas(1);
    }

    Close();
}

void ViewerDialog::OnButton7Click(wxCommandEvent& event)
{
    if(h->length()>2){
        FileName = h->getFile(2);
        SearchName = h->getBecome(2);
        ReplaceName = h->getWas(2);
    }

    Close();
}



void ViewerDialog::OnInit(wxInitDialogEvent& event)
{

}
