/**********************************************************
\Author Zachary Nelson
\Date February 25th 2018

This is the "Viewer" Class for the "Wordfisher" Plugin. It contains all of the functions which relate to the
inputs and outputs of a user.

***********************************************************/
#include<iostream>
#include "History.h"
using namespace std;

#ifndef VIEWER_H
#define VIEWER_H

class Viewer{
public:
   Viewer(){};
   ~Viewer(){};
   void DisplayTitle();
   void DisplayFileName();
   void DisplaySearch();
   void DisplayReplace();
   void DisplaySuccess();
   void DisplayFail();
   //void DisplayHistory(History past);
   //void HistoryRemoved();
   const string GetInput();
};

#endif
