/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Executable.h
 * Author: Akbar Aziz
 *
 * Created on December 24, 2015, 4:39 PM
 */

#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "File.h"

class Executable : public File{
public:
    Executable(const string& n, const string& o, const string& s,const string& d,const string& c);
    string path(const string& name) const;
    void ls(const string& commend) const;
    Executable& cd(File& file);
    bool cp( File& file);
    void setCompiler(const string& c);
    string getCompiler() const;
private:
    string compiler;
};

#endif /* EXECUTABLE_H */

