#include "queen.h"
#include "move.h"

Queen::Queen(PlayerNum player): Piece{(player == p1) ? 'Q' : 'q', player} {}

bool Queen::canMove(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol(); 

    if(abs(endRow - startRow) > 0 && abs(endCol - startCol) > 0)
    {
        if(abs(endRow-startRow) == abs(endCol-startCol))
        {
            return true; 
        }
        else
        {
            return false; 
        }
    }
    else 
    {
        return true; 
    }
}
