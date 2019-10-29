/*****************************************************************************
\Author Zachary Nelson
\Date February 25th 2018

This is the searchFile class, which is designed to open a file with the given name, and search through the file for the
given string. When it finds the string, it replaces it with the second string given.

*******************************************************************************/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#ifndef SEARCHFILE_H
#define SEARCHFILE_H

class SearchFile{
public:
   SearchFile(const string,const string&,const string&);
   ~SearchFile();
   bool SearchReplace();
   
   
private:
   string fileName;
   string searchFor;
   string replaceWith;
   
};

#endif
