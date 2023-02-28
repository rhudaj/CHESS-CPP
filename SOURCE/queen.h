#ifndef QUEEN
#define QUEEN

#include "globals.h"
#include "piece.h"
#include "move.h"
class Board; 

class Queen : public Piece
{
  public: 
  
    Queen(PlayerNum player);

    bool canMove(Move move) override;
}; 

#endif
