#include "../include/ViewrDialogFrame.h"
#include <wx/filedlg.h>
#include <wx/wfstream.h>

//(*InternalHeaders(ViewrDialogFrame)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(ViewrDialogFrame)
//*)

BEGIN_EVENT_TABLE(ViewrDialogFrame,wxFrame)
	//(*EventTable(ViewrDialogFrame)
	//*)
END_EVENT_TABLE()

ViewrDialogFrame::ViewrDialogFrame(wxWindow* parent)
{
	//(*Initialize(ViewrDialogFrame)
	wxXmlResource::Get()->LoadObject(this,parent,_T("ViewrDialogFrame"),_T("wxFrame"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));
	TextCtrl1 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL1"));
	Button2 = (wxButton*)FindWindow(XRCID("ID_BUTTON2"));
	TextCtrl2 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL2"));
	TextCtrl3 = (wxTextCtrl*)FindWindow(XRCID("ID_TEXTCTRL3"));
	Button3 = (wxButton*)FindWindow(XRCID("ID_BUTTON3"));
	Button4 = (wxButton*)FindWindow(XRCID("ID_BUTTON4"));
	StaticText2 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT2"));
	StaticText3 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT3"));
	StaticText4 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT4"));
	//*)
}

ViewrDialogFrame::~ViewrDialogFrame()
{
	//(*Destroy(ViewrDialogFrame)
	//*)
}

void ViewrDialogFrame::OnButton2Click(wxCommandEvent& event)
{
    Close();
}

void ViewrDialogFrame::OnButton3Click(wxCommandEvent& event)
{
    wxString w;
    wxFileDialog openFileDialog(this, (w), w, w, w, wxFD_OPEN|wxFD_FILE_MUST_EXIST);



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

void ViewrDialogFrame::OnButton1Click(wxCommandEvent& event)
{
    //Converts the first textbox into a usable string
    wxString s = TextCtrl1->GetValue();

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
 //   FileName = (TextCtrl1->GetValue()).wc_str();
}

