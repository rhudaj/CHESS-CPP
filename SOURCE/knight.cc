#include "knight.h"
#include "move.h"

Knight::Knight(PlayerNum player): Piece{(player == p1) ? 'N' : 'n', player} {}

bool Knight::canMove(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol(); 

    if( ( abs(endRow - startRow) == 2 && abs(endCol - startCol) == 1 ) || ( abs(endRow - startRow) == 1 && abs(endCol - startCol) == 2 ) )
    {
      return true;
    }
    else 
    {
      return false; 
    }
}
