#include "../include/History.h"
// a vector of strings to show the previous record of what is changed to what
//There will be two vector of string, "WhatWas" and "WhatBecome"
//main plugin should able to look in to see the previous changes made
History::History()
{
    //ctor
}

History::~History()
{
    //dtor
}

string History::getWas(int when)
{
    return WhatWas[when];
}

string History::getBecome(int when)
{
    return WhatBecome[when];
}

void History::add(string was, string become)
{
    if(WhatWas.size()>=3){
        WhatWas.pop_front();
        WhatBecome.pop_front();
    }
    WhatWas.push_back(was);
    WhatBecome.push_back(become);
}

// remove everything from histroy
void History::clean()
{
    WhatWas.clear();
    WhatBecome.clear();
}

int History::length()
{
    return WhatWas.size();
}

void History::addFile(string FileName)
{
    if(file.size()>= 3){
        file.pop_front();
    }
    file.push_back(FileName);
}

string History::getFile(int when)
{
    return file[when];
}







