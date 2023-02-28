#ifndef BISHOP
#define BISHOP

#include "globals.h"
#include "piece.h"
#include "move.h"

class Bishop : public Piece
{
  public: 

    ~Bishop(); 
  
    Bishop(PlayerNum player);

    bool canMove(Move move) override;
};

#endif 
