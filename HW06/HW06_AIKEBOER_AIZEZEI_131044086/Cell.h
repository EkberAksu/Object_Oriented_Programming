/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cell.h
 * Author: Akbar Aziz
 *
 * Created on December 11, 2015, 8:47 AM
 */

#ifndef CELL_H
#define CELL_H
using namespace std;

enum player { empty, user, computer }; 

class cell{
	public:
		cell();
		cell(const player turn);
		cell(const int rowN,const char columnL ,const player turn);
		void print() const;
		const int getRow() const;
		const char getColumn() const;
		const player getPlayer() const;
		void setRow(const int rowN);
		void setColumn(const char columnL);
		void setPlayer(const player turn);
		
	private:
		int row;
		char column;
		player cur_player;
	
};


#endif /* CELL_H */

