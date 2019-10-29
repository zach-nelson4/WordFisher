#include "gtest/gtest.h"

#include "MockUI.h"

#include <sdk.h>
#include <configurationpanel.h>
#include "../include/Wordfisher.h"
#include "../include/Targets.h"
#include "../include/SearchFile.h"
#include <fstream>
#include "../include/SuccesfullyReplaced.h"
#include "../include/History.h"
#include <logmanager.h>
// check if it runs corret, and check if it replace correct
TEST (WprdFishTest, ReplaceA)// replace "red" to "blue"
{
	string search = "red";
	string replace = "blue";
	string target = "TestTarget.txt";
	
	SearchFile s(target, search, replace);
	
    EXPECT_TRUE(s.SearchReplace());
}


TEST (WprdFishTest, ReplaceB)// replace "one1one" to "two2two"
{
	string target = "one1one";
	string replace = "two2two";
    string target = "TestTarget.txt";
	
	SearchFile s(target, search, replace);
	
    EXPECT_TRUE(s.SearchReplace());
}


TEST (WprdFishTest, ReplaceC)// replace "1234" to "5678"
{
	string target = "1234";
	string replace = "5678";
    string target = "TestTarget.txt";
	
	SearchFile s(target, search, replace);
	
    EXPECT_TRUE(s.SearchReplace());
}

