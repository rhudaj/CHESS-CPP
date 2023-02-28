#ifndef PIECE
#define PIECE

#include "globals.h"
#include "position.h"
#include "move.h"
#include <vector>

class Piece
{
  protected: 

    char symbol; 

    PlayerNum player; 
  
  public: 

    Piece(char symbol, PlayerNum player); 

    Piece(); 

    virtual ~Piece(); 

    char getChar() const; 

    PlayerNum getPlayer() const; 

  public: 

    virtual bool canMove(Move move) = 0;
};

#endif
