#include "move.h"
#include <iostream>

Pos Move::end() const
{
    return endPos; 
}

Pos Move::start() const
{
    return startPos; 
}

Move::Move() {}

Move::Move(Pos startPos, Pos endPos): startPos{startPos}, endPos{endPos} {}

bool Move::isWithinBounds(int numRows, int numCols)
{
    return startPos.isWithinBounds(numRows, numCols) && endPos.isWithinBounds(numRows, numCols); 
}

std::istream& operator>>(std::istream& in, Move& move)
{
    in >> move.startPos; 
    in >> move.endPos; 
    return in; 
}

std::ostream& operator<<(std::ostream& out, Move& move)
{
    out << move.startPos << "->" << move.endPos; 
    return out; 
}
