#ifndef MOVE
#define MOVE

//includes: 
#include <iostream>
#include "position.h"

class Move
{
    Pos startPos;

    Pos endPos; 

    public:

    Pos end() const;

    Pos start() const;

    Move();

    Move(Pos startPos, Pos endPos);

    bool isWithinBounds(int numRows, int numCols); 

    friend std::istream& operator>>(std::istream& in, Move& move); 

    friend std::ostream& operator<<(std::ostream& out, Move& move); 
}; 

#endif
