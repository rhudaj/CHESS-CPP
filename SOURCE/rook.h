#ifndef ROOK
#define ROOK

#include "globals.h"
#include "piece.h"
#include "move.h"
class Board; 

class Rook : public Piece
{
  private:

    bool firstMoveMade = false;

  public: 
  
    Rook(PlayerNum player);

    bool canMove(Move move) override;

    //bool canCastle();  
}; 

#endif
