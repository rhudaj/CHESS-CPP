#ifndef PAWN
#define PAWN

#include "globals.h"
#include "piece.h"
#include "move.h"
class Board; 

class Pawn : public Piece
{
  private: 

    PlayerNum player; 

    bool firstMoveMade = false;
    
    public: 
  
      Pawn(PlayerNum player);

      bool canMove(Move move) override;
}; 

#endif
