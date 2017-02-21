/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "File.h"
#include <cstdlib>

File::File(const string& n, const string& o, const string& s, const string& d){
    if(!(n.empty() || o.empty() || s.empty() || d.empty() )){
        setName(n);
        setOwner(o);
        setSize(s);
        setDate(d);
    }
    else{
        cout<<"wrong initialization of file!, program will exit."<<endl;
        exit(1);
    }
}


void File::setName(const string& n){
    if(!n.empty()){
        name=n;
    }
    else{
        cout<<"wrong input for name!";
    }
}

void File::setOwner(const string& o){
    if(!o.empty()){
        owner=o;
    }
    else{
        cout<<"wrong input for owner!";
    }
}

void File::setSize(const string& s){
    if(!s.empty()){
        size=s;
    }
    else{
        cout<<"wrong input for size!";
    }
}

void File::setDate(const string& d){
    if(!d.empty()){
        last_M_date=d;
    }
    else{
        cout<<"wrong input for last modification date!";
    }
}

string File::getName() const{
    return name;
}

string File::getOwner() const{
    return owner;
}

string File::getSize() const{
    return size;
}

string File::getDate() const{
    return last_M_date;
}