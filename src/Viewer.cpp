/**************************
PLEASE NOTE: THIS FILE WILL BE REMOVED SOON DUE TO NO LONGER NEEDING A VIEWER
CLASS FOR THIS PLUGIN, AS CODEBLOCKS DOES NOT SUPPORT COUT AND CIN FUNCTIONS

************************/



/******************************************************************************************
\Author Zachary Nelson
\Date February 27th 2018

This contains all of the implementation for the Viewer class for the Wordfisher plugin.
It contains anything relating to the cin and cout statements.

*****************************************************************************************/

#include <iostream>
#include "../include/Viewer.h"

using namespace std;

void Viewer::DisplayTitle(){
   cout << "=================================================================" << endl;
   cout << endl;
   cout << "                             Wordfisher                          " << endl;
   cout << "                            Version 1.0                          " << endl;
   cout << "                Created by Zach Nelson and Saito Shohei          " << endl;
   cout << endl;
   cout << "=================================================================" << endl;

}

void Viewer::DisplayFileName(){
   cout << "Please enter the name of the file, with extension, you wish to search through: " << endl;
}

void Viewer::DisplaySearch(){
   cout << "Please enter the phrase you wish to search for: " << endl;
}

void Viewer::DisplayReplace(){
   cout << "Please enter the phrase you will replace it with: " << endl;
}

void Viewer::DisplaySuccess(){
   cout << "Succesfully completed the replacement." << endl;
}

void Viewer::DisplayFail(){
   cout << "Error completing the replacement. Please double check the file name." << endl;
}

/*
void Viewer::DisplayHistory(History past)
{
    int s = past.length();
    cout << "Replace history"<< endl;
    for(int i = 0; i < s; i++)
    {
        cout << i+1 << ": changed '" << past.getWas(i) << "' to '" << past.getBecome(i) << "' " << endl;

    }
}

void HistroyRemoved()
{
    cout << "removed all history" << endl;
}
*/

const string Viewer::GetInput(){
   string s;
   cin >> s;
   return s;
}
