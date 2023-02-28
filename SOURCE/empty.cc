#include "empty.h"
#include "move.h"
#include "globals.h"

Empty::Empty(): Piece{' ', none} {}

bool Empty::canMove(Move move)
{
    return false;
}
