#ifndef KING
#define KING

#include "globals.h"
#include "piece.h"
#include "move.h"
class Board; 

class King : public Piece
{
  private: //when king is called in move change this field to true

    bool firstMoveMade = false;

  public: 

    King(PlayerNum player);

    //bool canCastle();

    bool canMove(Move move) override;
}; 

#endif
