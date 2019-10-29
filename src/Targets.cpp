#include<iostream>
#include "../include/Targets.h"

using namespace std;

///This is the constructor
Targets::Targets(){};

///This is the destructor
Targets::~Targets(){};

///This function is designed to set the paramter for the string you wish to search the file for
void Targets::setSearch(const string& s){
   searchFor = s;
}

///This function is designed to set the paramater for the string you wish to replace the searchFor with
void Targets::setReplace(const string& s){
   replaceWith = s;
}

///This function returns the string which you are searching for
const string Targets::getSearch(){
   return searchFor;
}

///This function returns the string which you aim to use as a replacement
const string Targets::getReplace(){
   return replaceWith;
}
