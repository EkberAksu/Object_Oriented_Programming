/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reversi.h
 * Author: Akbar Aziz
 *
 * Created on November 29, 2015, 8:01 PM
 */

#ifndef REVERSI_H
#define REVERSI_H

#include <vector>

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

    

class Reversi{
	public:
		Reversi();
		Reversi(const int num);
		Reversi(const int x,const int y);
		
		const vector<vector<cell> >& GetBoard() const; 
  		void doMove(const int x, const int y, const player turn); 
  		void doMove(vector<vector<cell> > &board,const int x,const int y,const player turn);
  		const bool IsValidMove(const int x, const int y, const player turn) const; 
  		const int ValidMoves(const player turn) const;  
  		void validMoves(vector<vector<cell> > board,vector<vector<int> > &moves,const player turn);
  		const int Count(const player turn) const;
		const player getOtherPlayer(const player turn) const;
		const int getscore(const vector<vector<cell> > board,const player turn) const;
		const int best_move(vector<vector<cell> > board, vector<vector<int> > moves,const player turn);
		void computer_move(vector<vector<int> > &moves,const player turn);
                const bool play(const int x, const int y);            //User plays
                void play();          // computer plays
                static void playGame();      //plays the whole game.
                const bool gameEnd() const; 
		void print() const;
		
		void setSize(const int num);
		void setSize(const int x,const int y);
		void setSizeX(const int x);
		void setSizeY(const int y);
		void setCell(const int x, const int y, const player turn);
		void setBoard();
		const int getSizeX() const;
		const int getSizeY() const;
		const player getCell(const int x, const int y) const;
	private:
                
		vector<vector<cell> > gamecells;
		int sizeX;
		int sizey;
		const static int leastSize=4;
                
                static int reversiNum;
		
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

const cell gamecell;

#endif /* REVERSI_H */

