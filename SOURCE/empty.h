#ifndef EMPTY
#define EMPTY

#include "globals.h"
#include "piece.h"
#include "move.h"

class Empty : public Piece
{
  public: 
  
    Empty();

    bool canMove(Move move) override;
};

#endif 
