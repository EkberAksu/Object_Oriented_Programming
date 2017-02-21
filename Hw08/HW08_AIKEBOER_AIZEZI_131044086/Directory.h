/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Directory.h
 * Author: Akbar Aziz
 *
 * Created on December 24, 2015, 10:21 PM
 */

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <vector>
#include <typeinfo>
#include "File.h"


class Directory : public File{
    public:
        Directory(const string& n,const string& o,const string& s,const string& d,const string& p);
      
        string path(const string& name) const override;
        void ls(const string& commend) const override;
        Directory& cd(File& file) override;
        bool cp(File& file) override;
        void setPath(const string& p);
    private:
        string Path;
        vector<File*> directory;
    
};

#endif /* DIRECTORY_H */

