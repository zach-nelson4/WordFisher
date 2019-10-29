#ifndef HISTORY_H
#define HISTORY_H
#include <deque>
#include<iostream>

using namespace std;


class History
{
    public:
        History();
        virtual ~History();
        string getWas(int when);
        string getBecome(int when);
        int length();
        void add(string was, string become);
        void clean();
        void addFile(string FileName);
        string getFile(int when);
    protected:
    private:
        deque<string> WhatWas;
        deque<string> WhatBecome;
        deque<string> file;

};

#endif // HISTORY_H
