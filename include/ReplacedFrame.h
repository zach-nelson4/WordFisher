#ifndef REPLACEDFRAME_H
#define REPLACEDFRAME_H

//(*Headers(ReplacedFrame)
#include <wx/frame.h>
//*)

class ReplacedFrame: public wxFrame
{
	public:

		ReplacedFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ReplacedFrame();

		//(*Declarations(ReplacedFrame)
		//*)

	protected:

		//(*Identifiers(ReplacedFrame)
		//*)

	private:

		//(*Handlers(ReplacedFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
