#include "pawn.h"
#include "move.h"

Pawn::Pawn(PlayerNum player): Piece{(player == p1) ? 'P' : 'p', player}, player{player} {}

bool Pawn::canMove(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol(); 

    int factor = 1; 

    if(player == p1) factor = 1;
    if(player == p2) factor = -1; 

    if(endRow - startRow == 1 * factor && abs(endCol - startCol) == 0)
    {
        return true;    
    }
    else if (!firstMoveMade && endRow - startRow == 2 * factor && abs(endCol - startCol) == 0)
    {
        firstMoveMade = true; 
        return true;
    }
    else if (endRow - startRow == 1 * factor && abs(endCol - startCol) == 1)
    {
        return true; 
    }
    else 
    {
        return false; 
    }

    return true; 
}
