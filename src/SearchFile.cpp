#include<iostream>
#include "../include/SearchFile.h"
#include <string>
#include <fstream>

using namespace std;


///Constructor
SearchFile::SearchFile(const string file, const string& searching, const string& replacing){
   fileName = file;
   searchFor = searching;
   replaceWith = replacing;
}

///Destructor
SearchFile::~SearchFile(){};

///searchFile function, which contains most of the calculations.
///Returns true if the file was opened, false if it was not
bool SearchFile::SearchReplace(){

   ifstream inFile;
   ofstream outFile("newFile.txt");
   inFile.open(fileName.c_str());
   string line;

   if(!inFile){
      return false;
   }

   size_t pos;

   // Gets a line from the file
   getline(inFile, line);
   while(!inFile.eof()){
      //Searches for the string
      for(int i = 0; i <= line.size(); i++){
	 pos=line.find(searchFor);
	 if(pos != string::npos){

	   Label:

	    bool replaceable = true;
	    //If its followed by any letters other than a space, dont replace
	    if(pos + searchFor.size() != line.size()){
	       for(int j = 0; j < 26; j++){
		  if(line.at(pos + searchFor.size()) == 'a' + j){
		     replaceable = false;
		     break;
		  }
	       }
	    }

	    //replaces the word
	    if(replaceable == true){
	       line.replace(pos, searchFor.size(), replaceWith);
	       pos = line.find(searchFor.size() + replaceWith.size());
	    }

	 }
      }
      //writes the line to a new file
      outFile << line;
      outFile << endl;
      getline(inFile, line);
   }

      ///removes the old file
      if(remove(fileName.c_str()) != 0)
	 cout << "Error!" << endl;

      //renames the new file to the old file
      int result;
      result = rename("newFile.txt", fileName.c_str());
      if(result != 0)
	 cout << "Error!" << endl;
      return true;

}

