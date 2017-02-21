/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "cell.h"


cell::cell(){
	setPlayer(empty);
}

cell::cell(const player turn){
	setPlayer(turn);
}

cell::cell(const int rowN,const char columnL,const player turn){
	setRow(rowN);
	setColumn(columnL);
	setPlayer(turn);
}

void cell::setRow(const int rowN){
	row=rowN;
}

void cell::setColumn(const char columnL){
	column=columnL;
}

void cell::setPlayer(player turn){
	cur_player=turn;
}

const int cell::getRow() const{
	return row;
}

const char cell::getColumn() const{
	return column;
}

const player cell::getPlayer() const{
	return cur_player;
}

void cell::print() const{
	switch(cur_player){
		case user: cout<<"X"; break;
		case computer: cout<<"O"; break;
		case empty: cout<<"."; break;
		default: cout<<"."; break;
	}
}