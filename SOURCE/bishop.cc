#include "bishop.h"
#include "move.h"

Bishop::Bishop(PlayerNum player): Piece{(player == p1) ? 'B' : 'b', player} {}

Bishop::~Bishop() {}

bool Bishop::canMove(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol(); 

    if(abs(endRow-startRow) == abs(endCol-startCol)) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}
