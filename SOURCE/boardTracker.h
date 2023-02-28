#ifndef BOARD_TRACKER
#define BOARD_TRACKER

#include <vector>
#include "position.h"

class PositionsToUpdate
{
  private: 

    std::vector <Pos> positions; 

  public: 

    void allPositions(int numRows, int numCols); 

    PositionsToUpdate(); 

    void add(Pos pos);

    Pos get(); 

    bool none(); 
}; 

#endif
