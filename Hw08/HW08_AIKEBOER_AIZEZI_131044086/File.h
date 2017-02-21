/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FILE.h
 * Author: Akbar Aziz
 *
 * Created on December 23, 2015, 5:41 PM
 */

#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>

using namespace std;

class File{
public:
    File(const string& n,const string& o,const string& s,const string& d);
    virtual string path(const string& name) const=0;
    virtual void ls(const string& commend) const =0;
    virtual File& cd(File& file) =0;
    virtual bool cp(File& file) =0;
    
    void setName(const string& n);
    void setOwner(const string& o);
    void setSize(const string& s);
    void setDate(const string& d);
    string getName() const;
    string getOwner() const;
    string getSize() const;
    string getDate() const;
    
private:
    string name;
    string owner;
    string size;
    string last_M_date;
};


#endif /* FILE_H */

