#include "gtest/gtest.h"
#include "History.h"
#include <iostream>

TEST (HistroyTest, addHistroy)
{	
    // check if what add is shwon right
	History h;
	h.add("test", "testing");
	EXPECT_EQ("test",h.getWas(0));
	EXPECT_EQ("testing",h.getBecome(0));
	
}

TEST (HistroyTest, countHistory)
{
    // check if it counts the amount of histroy right
	History h;
	h.add("test0", "testing0");
	h.add("test1", "testing1");
	h.add("test2", "testing2");
	EXPECT_EQ(3,h.length());
}

TEST (HistroyTest, removeHistroy)
{
    // check if history gets removed 
	History h;
	h.add("test0", "testing0");
	h.add("test1", "testing1");
	h.add("test2", "testing2");
	h.clean();
	EXPECT_EQ(0,h.length());
}