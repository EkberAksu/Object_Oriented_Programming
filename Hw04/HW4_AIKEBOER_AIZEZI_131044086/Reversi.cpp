/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include "Reversi.h"

using namespace std;

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
		default: cout<<"-"; break;
	}
}
//---------------------------------------------------
int Reversi::reversiNum = 0;

Reversi::Reversi() 
  : gamecells(leastSize,vector<cell>(leastSize,gamecell)) 
{ 
        ++reversiNum;
	int num=leastSize;
	setSize(num);
	
   if(gamecells.size() != gamecells[0].size() ) exit(1);

  const int x = num / 2 - 1; 
  const int y = num / 2 - 1; 
  setCell(x  ,y  ,user); 
  setCell(x+1,y  ,computer); 
  setCell(x  ,y+1,computer); 
  setCell(x+1,y+1,user); 
}

Reversi::Reversi(const int num) 
  : gamecells(num,vector<cell>(num,gamecell)) 
{ 
    ++reversiNum;
    setSize(num);
	
   if(gamecells.size() != gamecells[0].size() ) exit(1);

  const int x = num / 2 - 1; 
  const int y = (num / 2 - 1); 
  setCell(x  ,y  ,user); 
  setCell(x+1,y  ,computer); 
  setCell(x  ,y+1,computer); 
  setCell(x+1,y+1,user);  
}

Reversi::Reversi(const int x,const int y) 
  : gamecells(y,vector<cell>(x,gamecell)) 
{ 
    ++reversiNum;
    setSize(x,y);

  const int m_x = x / 2 - 1; 
  const int m_y = y / 2 - 1; 
  setCell(m_x  ,m_y  ,user); 
  setCell(m_x+1,m_y  ,computer); 
  setCell(m_x  ,m_y+1,computer); 
  setCell(m_x+1,m_y+1,user); 
}

void Reversi::setSize(const int num){
	setSizeX(num);
	setSizeY(num);
}

void Reversi::setSize(const int x,const int y){
	setSizeX(x);
	setSizeY(y);
}

void Reversi::setSizeX(const int x){
	sizeX=x;
}

void Reversi::setSizeY(const int y){
	sizey=y;
}

void Reversi::setCell(const int x, const int y, const player turn){
	gamecells[y][x].setPlayer(turn);
}

const int Reversi::getSizeX() const{
	return sizeX;
}

const int Reversi::getSizeY() const{
	return sizey;
}

const player Reversi::getCell(const int x, const int y) const{
	return gamecells[y][x].getPlayer();
}


void Reversi::print() const{
	const int sizex=getSizeX();
	const int sizey=getSizeY();
	
	cout<<"  ";
	
	for(int i=0; i<sizex;++i){
		cout<<static_cast<char>('a'+i);
	}
	
	cout<<endl;
	
	const vector<vector<cell> >& Board = GetBoard(); 
	for(int i=0; i<sizey;++i){
		cout<<i%10<<" ";
		for(int m=0; m<sizex;++m){
			
			Board[i][m].print();
			
		}
		cout<<" "<<i%10<<endl;
	}
	
	cout<<"  ";
	for(int i=0; i<sizex;++i){
		cout<<static_cast<char>('a'+i);
	}
	
	cout<<endl;
}

//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveUp(const int x, const int y, const player turn) const 
{ 
  int b = y - 1; 
  if (b < 1) return false; 
  if (getCell(x,b) != getOtherPlayer(turn)) return false; 
  while (b > 0) 
  { 
    b--; 
    if (getCell(x,b) == turn) return true; 
    if (getCell(x,b) == empty) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveUpLeft(const int x, const int y, const player turn) const 
{ 
  int a = x - 1; 
  int b = y - 1; 
  if (a < 1 || b < 1) return false; 
  if (getCell(a,b) != getOtherPlayer(turn)) return false; 
  while (a > 0 && b > 0) 
  { 
    a--; 
    b--; 
    if (getCell(a,b) == turn) return true; 
    if (getCell(a,b) == empty) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveLeft(const int x, const int y, const player turn) const 
{ 
  int a = x - 1; 
  if (a < 1) return false; 
  if (getCell(a,y) != getOtherPlayer(turn)) return false; 
  while (a > 0) 
  { 
    a--; 
    if (getCell(a,y) == turn) return true; 
    if (getCell(a,y) == empty) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveDownLeft(const int x, const int y, const player turn) const 
{ 
  const int sizey = getSizeY(); 
  int a = x - 1; 
  int b = y + 1; 

  if (a < 1) return false; 
  if (b > sizey -1 ) return false; 
  if (getCell(a,b) != getOtherPlayer(turn)) return false; 
  while (a > 0 && b < sizey - 1) 
  { 
    a--; 
    b++; 
    if (getCell(a,b) == turn) return true; 
    if (getCell(a,b) == empty) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveDown(const int x, const int y, const player turn) const 
{ 
  const int sizey = getSizeY(); 
  int b = y + 1; 
  if (b > sizey -1 ) return false; 
  if (getCell(x,b) != getOtherPlayer(turn)) return false; 
  while (b < sizey - 1) 
  { 
    b++; 
    if (getCell(x,b) == turn) return true; 
    if (getCell(x,b) == empty ) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveDownRight(const int x, const int y, const player turn) const 
{ 
  const int sizex = getSizeX(); 
  const int sizey = getSizeY(); 
  
  int a = x + 1; 
  int b = y + 1; 
  if (a > sizex - 1) return false; 
  if (b > sizey -1 ) return false; 
  if (getCell(a,b) != getOtherPlayer(turn)) return false; 
  while (a < sizex - 1 && b < sizey - 1) 
  { 
    b++; 
    a++; 
    if (getCell(a,b) == turn) return true; 
    if (getCell(a,b) == empty ) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveRight(const int x, const int y, const player turn) const 
{ 
  const int sizex = getSizeX();  
  int a = x + 1; 
  if (a > sizex - 1) return false; 
  if (getCell(a,y) != getOtherPlayer(turn)) return false; 
  while (a < sizex - 1) 
  { 
    a++; 
    if (getCell(a,y) == turn) return true; 
    if (getCell(a,y) == empty) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const bool Reversi::IsRightMoveUpRight(const int x, const int y, const player turn) const 
{ 
  const int sizex = getSizeX();
  int a = x + 1; 
  int b = y - 1; 
  if (a > sizex - 1) return false; 
  if (b < 1) return false; 
  if (getCell(a,b) != getOtherPlayer(turn)) return false; 
  while (a < sizex - 1 && b > 0) 
  { 
    a++; 
    b--; 
    if (getCell(a,b) == turn) return true; 
    if (getCell(a,b) == empty) return false; 
  } 
  return false; 
} 
//--------------------------------------------------------------------------- 
const int Reversi::ValidMoves(const player turn) const 
{ 
  const int sizex = getSizeX();
  const int sizey = getSizeY(); 
  int validmoves=0; 
  for (int y=0; y!=sizey; ++y) 
  { 
    for (int x=0; x!=sizex; ++x) 
    { 
      if (IsValidMove(x,y,turn)==true) 
      { 
        ++validmoves; 
      } 
    } 
  } 
  return validmoves; 
} 

void Reversi::validMoves(vector<vector<cell> > board,vector<vector<int> > &moves,const player turn)
{
	const int sizex = getSizeX();
    const int sizey = getSizeY(); 
    int xdelta =0;                  
    int ydelta =0;                  
	int row = 0;          
    int col = 0;                 
    char opponent = (turn == user)? computer : user; 

	for (int y=0; y!=sizey; ++y)
    	for (int x=0; x!=sizex; ++x)  
    		moves[y][x]=0;
	
	for(int y= 0; y < sizey; ++y)
     for(int x = 0; x < sizex; ++x)
   	{ 
        if(board[y][x].getPlayer()!=empty)  continue;
   
   		for(ydelta = -1; ydelta <= 1; ++ydelta)
     	for(xdelta = -1; xdelta <= 1; ++xdelta)
     	{ 
      
       		if(x + xdelta < 0 || x + xdelta >= sizex ||
         	 y + ydelta < 0 || y + ydelta >= sizey || 
                               (xdelta==0 && ydelta== 0))
         		continue;

      
       if(board[y + ydelta][x + xdelta].getPlayer() == opponent)
       {
                                  
         row=x+ xdelta;        
         col=y+ ydelta;        

         for(;;)
         {
           row += xdelta;           
           col += ydelta;           

           
           if(row < 0 || row >= sizex || col < 0 || col >= sizey)
             break;
 
           
           if(board[col][row].getPlayer() == empty)
             break;

           
           if(board[col][row].getPlayer() ==turn)
           {
              
               moves[y][x]=1;    
             break;                    
           } 
         }
       }
     }
	}
}
//--------------------------------------------------------------------------- 
void Reversi::MoveUp(const int x, int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn); 
    --y; 
  } 
} 
//--------------------------------------------------------------------------- 
void Reversi::MoveUpLeft(int x, int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn);
    --y; 
    --x; 
  } 
} 
//--------------------------------------------------------------------------- 
void Reversi::MoveLeft(int x, const int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn);
    --x; 
  } 

} 
//--------------------------------------------------------------------------- 
void Reversi::MoveDownLeft(int x, int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn);
    ++y; 
    --x; 
  } 
} 
//--------------------------------------------------------------------------- 
void Reversi::MoveDown(const int x, int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn); 
    ++y; 
  } 
} 
//--------------------------------------------------------------------------- 
void Reversi::MoveDownRight(int x, int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn); 
    ++y; 
    ++x; 
  } 
} 
//--------------------------------------------------------------------------- 
void Reversi::MoveRight(int x, const int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn);
    ++x; 
  } 
} 
//--------------------------------------------------------------------------- 
void Reversi::MoveUpRight(int x, int y, const player turn) 
{ 
  while ( getCell(x,y) == getOtherPlayer(turn) ) 
  { 
    setCell(x,y,turn); 
    --y; 
    ++x; 
  } 
} 

//---------------------------------------------------------

const player Reversi::getOtherPlayer(const player turn) const
{ 
  switch (turn) 
  { 
    case user: return computer; 
    case computer: return user; 
  } 
   
  return empty; 
} 

const vector<vector<cell> >& Reversi::GetBoard() const 
{ 
  return gamecells; 
} 

void Reversi::doMove(const int x, const int y, const player turn) 
{ 

  if (IsRightMoveUp(       x,y,turn) == true) MoveUp(       x  ,y-1,turn); 
  if (IsRightMoveUpLeft(   x,y,turn) == true) MoveUpLeft(   x-1,y-1,turn); 
  if (IsRightMoveLeft(     x,y,turn) == true) MoveLeft(     x-1,y  ,turn); 
  if (IsRightMoveDownLeft( x,y,turn) == true) MoveDownLeft( x-1,y+1,turn); 
  if (IsRightMoveDown(     x,y,turn) == true) MoveDown(     x  ,y+1,turn); 
  if (IsRightMoveDownRight(x,y,turn) == true) MoveDownRight(x+1,y+1,turn); 
  if (IsRightMoveRight(    x,y,turn) == true) MoveRight(    x+1,y  ,turn); 
  if (IsRightMoveUpRight(  x,y,turn) == true) MoveUpRight(  x+1,y-1,turn); 
  setCell(x,y,turn); 
} 

void Reversi::doMove(vector<vector<cell> > &board,const int x,const int y,const player turn)
{
	const int sizex = getSizeX();
   const int sizey = getSizeY(); 
   int xdelta =0;                   
   int ydelta =0;  
   
   int row=0;
   int col=0;                 
   
   char opponent = getOtherPlayer(turn);  

   board[y][x].setPlayer(turn);   
           
   
   		for(ydelta = -1; ydelta <= 1; ++ydelta)
     	for(xdelta = -1; xdelta <= 1; ++xdelta)
     	{ 
       
       		if(x + xdelta < 0 || x + xdelta >= sizex ||
          	y + ydelta < 0 || y + ydelta >= sizey || 
                               (xdelta==0 && ydelta== 0))
         		continue;

       
       if(board[y + ydelta][x + xdelta].getPlayer() == opponent)
       {
                                       
         row=x+ xdelta;        
         col=y+ ydelta;        

         for(;;)
         {
           row += xdelta;           
           col += ydelta;            

           
           if(row < 0 || row >= sizex || col < 0 || col >= sizey)
             break;
 
           
           if(board[col][row].getPlayer() == empty)
             break;

           
           if(board[col][row].getPlayer() ==turn)
           {
             while(board[col -= ydelta][row -= xdelta].getPlayer() ==opponent) 
               board[y][x].setPlayer(turn);    
             break;                     
           } 
         }
       }
     }
}

const bool Reversi::IsValidMove(const int x, const int y, const player turn) const 
{ 
  if (IsRightMoveUp(       x,y,turn)==true) return true; 
  if (IsRightMoveUpLeft(   x,y,turn)==true) return true; 
  if (IsRightMoveLeft(     x,y,turn)==true) return true; 
  if (IsRightMoveDownLeft( x,y,turn)==true) return true; 
  if (IsRightMoveDown(     x,y,turn)==true) return true; 
  if (IsRightMoveDownRight(x,y,turn)==true) return true; 
  if (IsRightMoveRight(    x,y,turn)==true) return true; 
  if (IsRightMoveUpRight(  x,y,turn)==true) return true; 
  return false; 
} 

const int Reversi::Count(const player turn) const 
{ 
  const int sizex = getSizeX(); 
  const int sizey = getSizeY();

  int sum=0; 

	
 		for (int y=0; y!=sizey; ++y) 
 		{ 
    		for (int x=0; x!=sizex; ++x) 
    		{ 
     			 if (gamecells[y][x].getPlayer() == turn) ++sum; 
   			} 
  		} 

  return sum; 
} 

const int Reversi::getscore(vector<vector<cell> > board, const player turn) const{
	
	const int sizex = getSizeX(); 
   	const int sizey = getSizeY();
	int score = 0;   
   	player opponent = getOtherPlayer(turn);   

   for(int y= 0; y < sizey; ++y)
     for(int x = 0; x < sizex; ++x)
   { 
     score -= board[y][x].getPlayer() == opponent; 
     score += board[y][x].getPlayer() == turn;   
   }
   return score;
}

void Reversi::computer_move( vector<vector<int> > &moves,const player turn)
{
	const int sizex = getSizeX(); 
   	const int sizey = getSizeY();
                          
   int best_row = 0;                    
   int best_col = 0;                     
                             
   int new_score = 0;                    
   int score = 100;                      
   vector<vector<cell> > tempBoard (sizey,vector<cell> (sizex, gamecell));          
   vector<vector<int> > newMoves (sizey,vector<int> (sizex, 0));           
   player opponent = getOtherPlayer(turn);  

   
   for(int y= 0; y < sizey; ++y){
     for(int x = 0; x < sizex; ++x)
   	{ 
       if(moves[y][x] == 0)
         continue;
       
       for(int i = 0; i < sizey; i++)
         for(int j = 0; j < sizex; j++)
           tempBoard[i][j] = gamecells[i][j];
   
       
       doMove(tempBoard, x, y, turn); 

       
       validMoves(tempBoard, newMoves, opponent);

       
       new_score = best_move(tempBoard, newMoves, opponent);
       

       if(new_score<score)    
       {                  
         score = new_score; 

         best_row = x; 
         best_col = y;  
       }
     }
 }
   
   doMove( best_row, best_col, turn); 
}

const int Reversi::best_move(vector<vector<cell> > board, vector<vector<int> > moves,const player turn)
{
   const int sizex = getSizeX(); 
   const int sizey = getSizeY();

   player opponent = getOtherPlayer(turn);  

   vector<vector<cell> > newBoard (sizey,vector<cell> (sizex, gamecell));  
   
   int score = 0;                       
   int new_score = 0;            

   
   for(int y= 0 ; y<sizey ; ++y)
     for(int x= 0 ; x<sizex ; ++x)
     {
       if(!moves[y][x])             
         continue;               
 
       for(int i = 0 ; i<sizey ; ++i)
         for(int j = 0 ; j<sizex ; ++j)
           newBoard[i][j]=board[i][j];

       doMove(newBoard, x, y, turn);  

  
       new_score = getscore(newBoard, turn);  

       if(score<new_score)        
               score = new_score;  
     }
   return score;  
}

const bool Reversi::play(const int x, const int y){
    
    if (IsValidMove(x,y, user) == false) 
    { 
      cout 
        << "Oops! this is not a valid move!,try again>" << endl; 
      return false; 
    } 
    
    doMove(x, y, user);
    
    return true;
}

void Reversi::play(){
    
    vector<vector<int> > newMoves (getSizeY(),vector<int> (getSizeY(), 0));
    validMoves(GetBoard(),newMoves,computer);
    computer_move(newMoves,computer);
}

void Reversi::playGame(){
    
    
    int row=0,column=0;
        
    while(1){
	cout << "Please enter two integers separately by pressing Enter,"
                " as the size of the Reversi Board>" << endl; 
    	cin>>row>>column;
    	if(row<4||row>26||column<4||column>26){
    		cout<<"invalid board size, its hight and width should be between 4~26 >"<<endl;
    		continue;
		}
	break;
    }
		
    player cur_player=user;
	
    Reversi reversi1(row,column);
    
    char X;
    int y=0;
    int x=0;
	
    while (1) 
    { 
    cout << "\nThe board's current state: " << endl ;
    
    reversi1.print();
    while(cur_player==user){
        
        if (reversi1.ValidMoves(cur_player)==0) 
        { 
            cout << "Oops!, there is no any valid move,"; 
            cur_player = (cur_player == user ? computer : user); 
            cout << "\nThe next turn goes to " << (cur_player == user ? "you," : "Computer,") << "!" << endl; 
            break; 
        } 
	   
	cout<< endl 
        << "It is your turn.\n" 
        << "Please enter a coordinate in this style: a8 , 'p' to pass or 'q' to quit" 
        << endl; 

        cin>>X;


        if (X == 'q') 
        { 
            exit (0); 
        } 
        if (X == 'p') 
        { 
            cur_player = (cur_player == user? computer : user); 
            continue; 
        } 

	x=static_cast<int>(X-'a');
	cin>>y;

        if(reversi1.play(x,y))  break;
    
   }
    
    if(cur_player==computer){
        
	reversi1.play();
	}
       
    if (reversi1.gameEnd()) 
    { 
      
      const int num1 = reversi1.Count(user); 
      const int num2 = reversi1.Count(computer); 
      cout << "The game has ended." << endl 
        << "You conquered " << num1 << " squares." << endl 
        << "Computer conquered " << num2 << " squares." << endl 
        << "The winner is player " << (num1 > num2 ? "You," : "Computer,") << std::endl 
        << "Congratulations!" << endl 
        << endl 
        << "Press any key to quit. " << endl; 

      cin.get(); 
      exit (0);  
    } 

    cur_player = (cur_player == user ? computer : user);
  }  	
   
}

const bool Reversi::gameEnd() const{
    
    return (Count(empty) == 0);
}



 



