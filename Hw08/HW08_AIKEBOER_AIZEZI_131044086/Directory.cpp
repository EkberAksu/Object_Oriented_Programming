/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Directory.h"
#include <cstdlib>

Directory::Directory(const string& n, const string& o, const string& s, const string& d, const string& p)
    : File(n,o,s,d){
    if(p.empty()){
        cout<<"wrong initialization,program will exit!"<<endl;
        exit(1);
    }
    setPath(p);
}

void Directory::setPath(const string& p){
    if(p.empty()){
        cout<<"wrong input for path!";
        return;
    }
    else
        Path=p;
}
Directory& Directory::cd(File& file ){
    if(typeid(Directory)==typeid(file)){
        return dynamic_cast<Directory&> (file);
    }
    else{
        cout<<"can not change to this one!";
        return *this;
    }
}

bool Directory::cp(File& file){
    if(typeid(Directory)==typeid(file)){
        directory.push_back(dynamic_cast<File*>(&file));
    }
    else{
        directory.push_back(dynamic_cast<File*>(&file));
        /*directory[0]= (File*) malloc (sizeof(File));
        directory[0]=&file;*/
    }
    return 1;
}

void Directory::ls(const string& commend) const{
    if(commend=="l"){
        for(int i=0;directory[i+1]!=nullptr;++i){
            cout<<directory[0]->getName()<<"    "<<directory[0]->getOwner()<<"   "<<directory[0]->getSize()<<"    "
            <<directory[0]->getDate();
        }
        cout<<endl;
    }
    if(commend=="a"){
        for(int i=0;directory[i+1]!=nullptr;++i){
            cout<<directory[0]->getName();
        }
        cout<<endl;
    }
}

string Directory::path(const string& name) const{
    return Path+"/"+name;
}

