#include "rook.h"
#include "move.h"

Rook::Rook(PlayerNum player): Piece{(player == p1) ? 'R' : 'r', player} {}

bool Rook::canMove(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol(); 

    if(abs(endRow - startRow) > 0 && abs(endCol - startCol) > 0)
    {
        return false; 
    }
    else 
    {
        return true; 
    }
}
