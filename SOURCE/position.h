#ifndef POSITION
#define POSITION

//includes: 
#include <iostream>

class Pos
{
  friend class Board; 

  private: 

    int row, col; 

  public: 

    int getRow() const;

    int getCol() const;

    Pos(int row, int col); 

    Pos(); 

    bool operator==(Pos& other) const; 

    bool operator==(Pos&& other) const; 

    bool operator!=(Pos& other) const;

    bool isWithinBounds(int numRows, int numCols); 

    friend std::istream& operator>>(std::istream& in, Pos& pos); 

    friend std::ostream& operator<<(std::ostream& out, Pos& pos); 
};

#endif
