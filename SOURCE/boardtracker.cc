#include "boardTracker.h"
#include "position.h"

void  PositionsToUpdate::add(Pos pos)
{
  positions.emplace_back(pos); 
}

Pos PositionsToUpdate::get()
{
  Pos tmp = positions.back(); 
  positions.pop_back();
  return tmp; 
}

bool PositionsToUpdate::none()
{
  return positions.empty(); 
}

void PositionsToUpdate::allPositions(int numRows, int numCols)
{
  for(int row{7}; row >= 0; --row)
  {
    for(int col{7}; col >= 0; --col)
    {
      add({row,col}); 
    }
  }
}

PositionsToUpdate::PositionsToUpdate()
{
  
}
