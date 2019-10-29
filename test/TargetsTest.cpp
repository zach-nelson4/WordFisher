#include "gtest/gtest.h"
#include "Targets.h"
#include <iostream>

TEST (TargetsTest, TestSearch)
{	
    // check if what set in targets shows
	Targets t;
	t.setSearch("Test");
	EXPECT_EQ("Test", t.getSearch);
	
	
}

TEST (TargetsTest, TestReplace)
{	
    // check if what set in targets shows
	Targets t;
	t.setReplace("Testing");
	EXPECT_EQ("Testing", t.getReplace);
	
	
}

