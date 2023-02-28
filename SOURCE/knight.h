#ifndef KNIGHT
#define KNIGHT

#include "globals.h"
#include "piece.h"
#include "move.h"
class Board; 

class Knight : public Piece
{
  public: 
  
    Knight(PlayerNum player);

    bool canMove(Move move) override;
}; 

#endif
