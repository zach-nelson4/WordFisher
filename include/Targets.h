/****************************************************************
\Author Zachary Nelson
\Date February 28th 2018

This is the "Targets" class.
This class is designed to contain all of the data relating to the words that the user wants to replace, and
the word that the user wants to replace said word with.

******************************************************************/

#include<iostream>
using namespace std;

#ifndef TARGETS_H
#define TARGETS_H

class Targets{
public:
   Targets();
   ~Targets();
   void setSearch(const string&);
   void setReplace(const string&);
   const string getSearch();
   const string getReplace();
   
private:
   string searchFor;
   string replaceWith;

};

#endif

