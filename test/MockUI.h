#ifndef MOCKUI_H_INCLUDED
#define MOCKUI_H_INCLUDED

#include "../include/Viewer.h"

class MockUI : public Viewer
{
	MockUI() {}
    virtual ~MockUI() {}
	
	MOCK_METHOD0(DisplayTitle, void());
	MOCK_METHOD1(DisplayFileName, void());
	MOCK_METHOD2(DisplaySearch, void());
	MOCK_METHOD3(DisplayReplace, void());
	MOCK_METHOD4(DisplaySuccess, void());
	MOCK_METHOD5(DisplayFail, void());
	MOCK_METHOD6(GetInput, const string());
};
#endif //