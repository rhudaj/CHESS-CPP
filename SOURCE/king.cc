#include "king.h"
#include "move.h"

King::King(PlayerNum player): Piece{(player == p1) ? 'K' : 'k', player} {}

bool King::canMove(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol();

    if(abs(endCol-startCol) > 1 || abs(endRow-startRow) > 1)
    {
        return false; 
    }
    else 
    {
        return true; 
    }
}
