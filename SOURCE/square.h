#ifndef SQUARE
#define SQUARE

#include "piece.h"
#include <iostream> 
#include "globals.h"

class Square
{
  private: 

    Piece* piece; 

    Color color; 

  public: 

    Square(Piece* piece, Color color); 

    Square();

    Piece* getPiece() const; 

      char getPieceChar(); 

      PlayerNum getPiecePlayer();

    Color getColor() const; 

    void setPiece(Piece* newPiece); 

    void deletePiece(); 

    friend std::ostream& operator<<(std::ostream& out, Square& square); 
};

#endif
