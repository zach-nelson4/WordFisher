#include "../include/SuccesfullyReplaced.h"

//(*InternalHeaders(SuccesfullyReplaced)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(SuccesfullyReplaced)
//*)

BEGIN_EVENT_TABLE(SuccesfullyReplaced,wxDialog)
	//(*EventTable(SuccesfullyReplaced)
	//*)
END_EVENT_TABLE()

SuccesfullyReplaced::SuccesfullyReplaced(wxWindow* parent)
{
	//(*Initialize(SuccesfullyReplaced)
	wxXmlResource::Get()->LoadObject(this,parent,_T("SuccesfullyReplaced"),_T("wxDialog"));
	StaticText1 = (wxStaticText*)FindWindow(XRCID("ID_STATICTEXT1"));
	Button1 = (wxButton*)FindWindow(XRCID("ID_BUTTON1"));

	Connect(XRCID("ID_BUTTON1"),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SuccesfullyReplaced::OnButton1Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&SuccesfullyReplaced::OnInit);
	//*)
}

SuccesfullyReplaced::~SuccesfullyReplaced()
{
	//(*Destroy(SuccesfullyReplaced)
	//*)
}


void SuccesfullyReplaced::OnButton1Click(wxCommandEvent& event)
{
    Close();
}

void SuccesfullyReplaced::OnInit(wxInitDialogEvent& event)
{
}
