#include "piece.h" 
#include "globals.h"

Piece::Piece(char symbol, PlayerNum player): symbol{symbol}, player{player} {}

Piece::~Piece() {}

char Piece::getChar() const
{
  return symbol; 
}

PlayerNum Piece::getPlayer() const 
{
  return player;
}
