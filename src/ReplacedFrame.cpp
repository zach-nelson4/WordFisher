#include "../include/ReplacedFrame.h"

//(*InternalHeaders(ReplacedFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ReplacedFrame)
//*)

BEGIN_EVENT_TABLE(ReplacedFrame,wxFrame)
	//(*EventTable(ReplacedFrame)
	//*)
END_EVENT_TABLE()

ReplacedFrame::ReplacedFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ReplacedFrame)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	//*)
}

ReplacedFrame::~ReplacedFrame()
{
	//(*Destroy(ReplacedFrame)
	//*)
}

