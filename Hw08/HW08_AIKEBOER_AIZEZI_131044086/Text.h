/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Text.h
 * Author: Akbar Aziz
 *
 * Created on December 24, 2015, 9:45 PM
 */

#ifndef TEXT_H
#define TEXT_H

#include "File.h"

class Text : public File{
    public:
        Text(const string& n,const string& o,const string& s,const string& d,const string& t);
        string path(const string& name) const;
        void ls(const string& commend) const;
        Text& cd(File& file);
        bool cp( File& file);
        void setType(const string& t);
        string getType() const;
    private:
        string type;
};


#endif /* TEXT_H */

