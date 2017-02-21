/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Executable.h"

Executable::Executable(const string& n, const string& o, const string& s, const string& d, const string& c)
        : File(n,o,s,d){
    setCompiler(c);
    if(c.empty()){
        cout<<"wrong initialization, program will exit!"<<endl;
        exit(1);
    }
}

void Executable::setCompiler(const string& c){
    if(!c.empty())
        compiler=c;
    else{
        cout<<"this is a wrong input for compiler!";
    }
}

string Executable::getCompiler() const{
    return compiler;
}

string Executable::path(const string& name) const{
    cout<<"cant return path on this file";
    return name;
}

void Executable::ls(const string& commend) const{
    cout<<"this function dosnt work on this file!";
}

bool Executable::cp( File& file){
    cout<<"this function dosnt work on this file!";
    return 0;
}

Executable& Executable::cd(File& file){
    cout<<"this function dosnt work on this file!";
    return *this;
}