/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Reversi.h"
#include <new>
#include <iostream>

int Reversi::reversiNum = 0;
int Reversi::count=0;

Reversi::Reversi() 
{ 
   ++reversiNum;
   int num=leastSize;
   setSize(num);
    
   gamecells = new (nothrow) cell[num*num];
   if(gamecells == NULL) exit(1);
   
   for(int i= 0; i < sizeY; ++i)
     for(int j = 0; j < sizeX; ++j){ 
         gamecells[i*sizeX+j].setPlayer(empty);
     }

  const int x = num / 2 - 1; 
  const int y = num / 2 - 1; 
  setCell(x  ,y  ,user); 
  setCell(x+1,y  ,computer); 
  setCell(x  ,y+1,computer); 
  setCell(x+1,y+1,user); 
  
}

Reversi::Reversi(const int num) 
{ 
    ++reversiNum;
    setSize(num);
	
   gamecells = new (nothrow) cell[num*num];
   if(gamecells == NULL) exit(1);
   
   for(int i= 0; i < sizeY; ++i)
     for(int j = 0; j < sizeX; ++j){ 
         gamecells[i*sizeX+j].setPlayer(empty);
     }

  const int x = num / 2 - 1; 
  const int y = num / 2 - 1; 
  setCell(x  ,y  ,user); 
  setCell(x+1,y  ,computer); 
  setCell(x  ,y+1,computer); 
  setCell(x+1,y+1,user); 
}

Reversi::Reversi(const int x,const int y)
{ 
    ++reversiNum;
    setSize(x,y);
    
    gamecells = new (nothrow) cell[x*y];
    if(gamecells == NULL) exit(1);
   
   for(int i= 0; i < sizeY; ++i)
     for(int j = 0; j < sizeX; ++j){ 
         gamecells[i*sizeX+j].setPlayer(empty);
     }
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
	sizeY=y;
}

void Reversi::setCell(const int x, const int y, const player turn){
    
    int coordinate = y*sizeX+x;
    gamecells[coordinate].setPlayer(turn);
    gamecells[coordinate].setColumn(y);
    gamecells[coordinate].setRow(x);
}

const int Reversi::getSizeX() const{
	return sizeX;
}

const int Reversi::getSizeY() const{
	return sizeY;
}

player Reversi::getCell(const int x, const int y) const{
    int coordinate = y*sizeX+x;
    return gamecells[coordinate].getPlayer();
}


void Reversi::print() const{
	const int sizex=getSizeX();
	const int sizey=getSizeY();
        
        cout << "\nThe board's current state: " << endl ;
	
	cout<<"  ";
	
	for(int i=0; i<sizex;++i){
		cout<<static_cast<char>('a'+i)<<" ";
	}
	
	cout<<endl;
	
	for(int i=0; i<sizey;++i){
            cout<<i%10<<" ";
            for(int m=0; m<sizex;++m){
			
		gamecells[i*sizex+m].print();
		cout<<" ";
            }
            cout<<" "<<i%10<<endl;
	}
	
	cout<<"  ";
	for(int i=0; i<sizex;++i){
		cout<<static_cast<char>('a'+i)<<" ";
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
  int Nvalidmoves=0; 
  for (int y=0; y!=sizey; ++y) 
  { 
    for (int x=0; x!=sizex; ++x) 
    { 
      if (IsValidMove(x,y,turn)==true) 
      { 
        ++Nvalidmoves; 
      } 
    } 
  } 
  return Nvalidmoves; 
} 

void Reversi::validMoves(cell* board,int* moves,const player turn)
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
    	moves[y*sizex+x]=0;
	
    for(int y= 0; y < sizey; ++y)
     for(int x = 0; x < sizex; ++x)
     { 
        if(board[y*sizex+x].getPlayer()!=empty)  continue;
   
   	for(ydelta = -1; ydelta <= 1; ++ydelta)
     	for(xdelta = -1; xdelta <= 1; ++xdelta)
     	{ 
      
            if(x + xdelta < 0 || x + xdelta >= sizex ||
                y + ydelta < 0 || y + ydelta >= sizey || 
                            (xdelta==0 && ydelta== 0))
         		continue;

      
       if(board[(y + ydelta)*sizex+(x + xdelta)].getPlayer() == opponent)
       {
                                  
         row=x+ xdelta;        
         col=y+ ydelta;        

         for(;;)
         {
           row += xdelta;           
           col += ydelta;           

           
           if(row < 0 || row >= sizex || col < 0 || col >= sizey)
             break;
 
           
           if(board[col*sizex+row].getPlayer() == empty)
             break;

           
           if(board[col*sizex+row].getPlayer() ==turn)
           {
              
               moves[y*sizex+x]=1;    
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
    default: return empty;
  } 
} 

cell* Reversi::GetBoard() const 
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

void Reversi::doMove(cell *board,const int x,const int y,const player turn)
{
    const int sizex = getSizeX();
   const int sizey = getSizeY(); 
   int xdelta =0;                   
   int ydelta =0;  
   
   int row=0;
   int col=0;                 
   
   char opponent = getOtherPlayer(turn);  

   board[y*sizex+x].setPlayer(turn);   
           
   
   	for(ydelta = -1; ydelta <= 1; ++ydelta){
     	for(xdelta = -1; xdelta <= 1; ++xdelta)
     	{ 
       
       		if(x + xdelta < 0 || x + xdelta >= sizex ||
          	y + ydelta < 0 || y + ydelta >= sizey || 
                               (xdelta==0 && ydelta== 0))
         		continue;

       
       if(board[(y + ydelta)*sizex+(x + xdelta)].getPlayer() == opponent)
       {
                                       
         row=x+ xdelta;        
         col=y+ ydelta;        

         for(;;)
         {
           row += xdelta;           
           col += ydelta;            

           
           if(row < 0 || row >= sizex || col < 0 || col >= sizey)
             break;
 
           
           if(board[col*sizex+row].getPlayer() == empty)
             break;

           
           if(board[col*sizex+row].getPlayer() ==turn)
           {
             while(board[(col -= ydelta)*sizex+(row -= xdelta)].getPlayer() ==opponent){ 
               board[col*sizex+row].setPlayer(turn);    }
             break;                     
           } 
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
     			 if (gamecells[y*sizex+x].getPlayer() == turn) ++sum; 
   			} 
  		} 

  return sum; 
} 

const int Reversi::getscore(cell* board, const player turn) const{
	
   const int sizex = getSizeX(); 
   const int sizey = getSizeY();
   int score = 0;   
   
   player opponent = getOtherPlayer(turn);   

   for(int y= 0; y < sizey; ++y)
     for(int x = 0; x < sizex; ++x)
   { 
     score -= board[y*sizex+x].getPlayer() == opponent; 
     score += board[y*sizex+x].getPlayer() == turn;   
   }
   return score;
}

void Reversi::computer_move( int* moves,const player turn)
{
   const int sizex = getSizeX(); 
   const int sizey = getSizeY();
                          
   int best_row = 0;                    
   int best_col = 0;                     
                             
   int new_score = 0;                    
   int score = 100;                      
   cell* tempBoard =new cell [sizex*sizey];          
   int* newMoves= new int [sizex*sizey]() ;  
   
   player opponent = getOtherPlayer(turn);  

   
   for(int y= 0; y < sizey; ++y){
     for(int x = 0; x < sizex; ++x)
   	{ 
       if(moves[y*sizex+x] == 0)
         continue;
       
       for(int i = 0; i < sizey; i++)
         for(int j = 0; j < sizex; j++)
           tempBoard[i*sizex+j] = gamecells[i*sizex+j];
   
       
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
   cout<<"This is computer's move:";
   doMove( gamecells,best_row, best_col, turn); 
   
   delete[] tempBoard;
   delete[] newMoves;
}

const int Reversi::best_move(cell* board, int* moves,const player turn)
{
   const int sizex = getSizeX(); 
   const int sizey = getSizeY();

   player opponent = getOtherPlayer(turn);  

   cell* newBoard =new cell[sizey*sizex];  
   
   int score = 0;                       
   int new_score = 0;            

   
   for(int y= 0 ; y<sizey ; ++y)
     for(int x= 0 ; x<sizex ; ++x)
     {
       if(!moves[y*sizex+x])             
         continue;               
 
       for(int i = 0 ; i<sizey ; ++i)
         for(int j = 0 ; j<sizex ; ++j)
           newBoard[i*sizex+j]=board[i*sizex+j];

       doMove(newBoard, x, y, turn);  

  
       new_score = getscore(newBoard, turn);  

       if(score<new_score)        
               score = new_score;  
     }
   
   delete[] newBoard;
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
    
    int* newMoves= new int [sizeX*sizeY]() ;  
     
    validMoves(gamecells,newMoves,computer);
    computer_move(newMoves,computer);
    
    delete[] newMoves;
}

void Reversi::playGame(){
    
    player cur_player=user;
    
    char X;
    int y=0;
    int x=0;
    
    print();
    
    while (count<6) 
    { 
       ++count;
    while(cur_player==user){
        
        if (ValidMoves(cur_player)==0) 
        { 
            cout << "Oops!, there is no any valid move,"; 
            cur_player = getOtherPlayer(cur_player);
            cout << "\nThe next turn goes to " << (cur_player == user ? "you," : "Computer,") << "!" << endl; 
            continue; 
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
            cur_player = getOtherPlayer(cur_player);
            continue; 
        } 

	x=static_cast<int>(X-'a');
	cin>>y;

        if(play(x,y))  break;
    
   }
    
    if(cur_player==computer){
        
	play();
	}
       
    if (gameEnd()) 
    { 
      
      const int num1 = Count(user); 
      const int num2 = Count(computer); 
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
    
    print();
    cur_player = getOtherPlayer(cur_player);
  }  	
   
}

const bool Reversi::gameEnd() const{
    
    return (Count(empty) == 0);
}

Reversi Reversi::operator++(){
    
    player cur_player=computer;
    if (ValidMoves(cur_player)==0) 
        { 
            cout << "Oops!, there is no any valid move,"; 
            cur_player = getOtherPlayer(cur_player); 
            cout << "\nThe next turn goes to " << (cur_player == user ? "you," : "Computer,") << "!" << endl; 
            return (*this); 
        } 
    if (gameEnd()) 
    { 
      
      const int num1 = Count(user); 
      const int num2 = Count(computer); 
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
    
    this->play();
    
    return (*this);
}

Reversi Reversi::operator++(int a){
    
    Reversi temp(getSizeX(),getSizeY());
    
    for(int i=0;i<sizeY*sizeX;++i)
        temp.GetBoard()[i]=(*this).GetBoard()[i];
    
    player cur_player=computer;
    if (ValidMoves(cur_player)==0) 
        { 
            cout << "Oops!, there is no any valid move,"; 
            cur_player = getOtherPlayer(cur_player); 
            cout << "\nThe next turn goes to " << (cur_player == user ? "you," : "Computer,") << "!" << endl; 
            return (*this); 
        } 
    if (gameEnd()) 
    { 
      
      const int num1 = Count(user); 
      const int num2 = Count(computer); 
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
    
    play();
    
    return temp;
}

 ostream& operator<<(ostream& os, const Reversi sample){
     
     sample.print();
     
     return os;
 }
 
 



