

#include <cstdlib>
#include "Executable.h"
#include "Text.h"
#include "Directory.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Text text("text","ekber","25","21/12/2015","Unicode");
    cout<<text.getName()<<"    "<<text.getOwner()<<"   "<<text.getSize()<<"    "
            <<text.getDate()<<"    "<<text.getType();
    
    text.setType("Ascii");
    cout<<endl<<text.getType()<<endl;
    
    Directory direc("folder","ekber","100","20/12/2015","home/user");
    
    direc.cp(text);
    cout<<direc.path("text")<<endl;
    
    cout<<endl;
    direc.ls("l");
    
    cout<<endl;
    direc.ls("a");

    return 0;
}

