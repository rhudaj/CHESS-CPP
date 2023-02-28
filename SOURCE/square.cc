#include "square.h"
#include <iostream>

Square::Square(Piece* piece, Color color): piece{piece}, color{color} {}; 

Square::Square(): piece{nullptr}, color{white} {}

Piece* Square::getPiece() const
{
  return piece; 
}

Color Square::getColor() const
{
  return color; 
}

char Square::getPieceChar()
{
  return piece->getChar(); 
}

PlayerNum Square::getPiecePlayer()
{
  return piece->getPlayer(); 
}

void Square::setPiece(Piece* newPiece)
{
  piece = newPiece; 
}

void Square::deletePiece()
{
  delete piece; 
}

std::ostream& operator<<(std::ostream& out, Square& square)
{
  char pieceChar = square.getPieceChar(); 

  out << pieceChar; 
  
  return out;
}
