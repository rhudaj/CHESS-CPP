#include "position.h"

Pos::Pos(int row, int col): row{row}, col{col} {}

Pos::Pos() 
{
  row = 0; 
  col = 0;
} 

bool Pos::operator==(Pos& other) const
{
  return (row == other.row) && (col == other.col); 
}

bool Pos::operator==(Pos&& other) const
{
  return (row == other.row) && (col == other.col); 
}

bool Pos::operator!=(Pos& other) const
{
  return !(*this == other); 
}

int Pos::getRow() const
{
  return row; 
}

int Pos::getCol() const
{
  return col; 
}

bool Pos::isWithinBounds(int numRows, int numCols)
{
  return (col < numCols) && (col >= 0) && (row < numRows) && (row >= 0); 
}

int char2Col(char c)
{
  if(c == 'H' || c == 'h') return 7; 
  if(c == 'G' || c == 'g') return 6; 
  if(c == 'F' || c == 'f') return 5; 
  if(c == 'E' || c == 'e') return 4; 
  if(c == 'D' || c == 'd') return 3; 
  if(c == 'C' || c == 'c') return 2; 
  if(c == 'B' || c == 'b') return 1; 
  if(c == 'A' || c == 'a') return 0; 
}

std::istream& operator>>(std::istream& in, Pos& pos)
{
  char col; 
  int row; 

  in >> col >> row; 

  pos.row = row-1; 
  pos.col = char2Col(col);
  
  return in; 
}

std::ostream& operator<<(std::ostream& out, Pos& pos)
{
  out << "(" << pos.row << "," << pos.col << ")"; 

  return out; 
}
