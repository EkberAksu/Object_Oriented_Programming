/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Text.h"

Text::Text(const string& n, const string& o, const string& s, const string& d, const string& t)
    : File(n,o,s,d){
    setType(t);
    if(t.empty()){
        cout<<"wrong initialization, program will exit!"<<endl;
        exit(1);
    }
}

void Text::setType(const string& t){
    if(!t.empty())
        type=t;
    else{
        cout<<"wrong input for the type of the text file";
    }
}

string Text::getType() const{
    return type;
}

string Text::path(const string& name) const{
    cout<<"cant return path on this file";
    return name;
}

void Text::ls(const string& commend) const{
    cout<<"this function dosnt work on this file!";
}

bool Text::cp(File& file){
    cout<<"this function dosnt work on this file!";
    return 0;
}

Text& Text::cd(File& file){
    cout<<"this function dose not work on this file!";
    return *this;
}