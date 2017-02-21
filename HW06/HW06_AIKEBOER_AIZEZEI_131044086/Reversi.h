/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reversi.h
 * Author: Akbar Aziz
 *
 * Created on December 11, 2015, 8:47 AM
 */

#ifndef REVERSI_H
#define REVERSI_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include "Cell.h"

const cell gamecell;

class Reversi{
	public:
		Reversi();
		Reversi(const int num);
		Reversi(const int x,const int y);
		
		cell* GetBoard() const; 
  		void doMove(const int x, const int y, const player turn); 
  		void doMove(cell* board,const int x,const int y,const player turn);
  		const bool IsValidMove(const int x, const int y, const player turn) const; 
  		const int ValidMoves(const player turn) const;  
  		void validMoves(cell* board,int* moves,const player turn);
  		const int Count(const player turn) const;
		const player getOtherPlayer(const player turn) const;
		const int getscore( cell* board,const player turn) const;
		const int best_move(cell* board, int* moves,const player turn);
		void computer_move(int* moves,const player turn);
                const bool play(const int x, const int y);            //User plays
                void play();          // computer plays
                void playGame();      //plays the whole game.
                const bool gameEnd() const; 
		void print() const;
               
                Reversi operator++();
                Reversi operator++(int a);
                
                friend ostream& operator<<(ostream& os, const Reversi sample);
                
		void setSize(const int num);
		void setSize(const int x,const int y);
		void setSizeX(const int x);
		void setSizeY(const int y);
		void setCell(const int x, const int y, const player turn);
		const int getSizeX() const;
		const int getSizeY() const;
		player getCell(const int x, const int y) const;
	private:
                
		cell* gamecells;
		int sizeX;
		int sizeY;
		const static int leastSize=4;
                
                static int reversiNum;
                static int count;
		
		const bool IsRightMoveUp(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveUpLeft(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveLeft(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveDownLeft(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveDown(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveDownRight(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveRight(const int x, const int y, const player turn) const; 
  		const bool IsRightMoveUpRight(const int x, const int y, const player turn) const; 

  		void MoveUp(const int x, int y, const player turn); 
  		void MoveUpLeft(int x, int y, const player turn); 
  		void MoveLeft(int x, const int y, const player turn); 
  		void MoveDownLeft(int x, int y, const player turn); 
  		void MoveDown(const int x, int y, const player turn); 
  		void MoveDownRight(int x, int y, const player turn); 
  		void MoveRight(int x, const int y, const player turn); 
  		void MoveUpRight(int x, int y, const player turn); 
};

#endif /* REVERSI_H */

