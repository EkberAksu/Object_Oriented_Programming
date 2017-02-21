/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Akbar Aziz
 *
 * Created on December 11, 2015, 8:46 AM
 */

#include <cstdlib>
#include "Reversi.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout<< "***********" << endl 
    	<< "* REVERSI *" << endl 
    	<< "***********" << endl 
    	<< endl;
    
    Reversi reversi1(16,16);
    
    //First player plays the game against computer,each taking three moves.
    reversi1.playGame();
    
    cout<<(++reversi1)<<endl;
    cout<<reversi1;
    
    cout<<reversi1++<<endl;
    cout<<reversi1;
    
    
   
    
	
    return 0;
}



