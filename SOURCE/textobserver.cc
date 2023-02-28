#include "textobserver.h"
#include "observer.h"
#include "board.h"
#include <iostream>

TextOb::TextOb(Board* board): board{board}
{
    board->attach(this);        //attach yourself 
}

TextOb::~TextOb()
{
    board->detach(this);        //detach yourself 
} 

void TextOb::notify()          
{
  std::string boardColumnChars[8] = {"A", "B", "C", "D", "E", "F", "G", "H"}; 


  out << "  "; 
  for(int row{0}; row < 8; ++row) out << " " << boardColumnChars[row]; 

  out << std::endl; 

  out << "  "; 
  for(int row{7}; row >= 0; --row) out << " -"; 

  for(int row{7}; row >= 0; --row)
  {
    out << std::endl; 
    out << row+1 << "|"; 

    for(int col{0}; col < 8; ++col)
    {
        Square square = board->getState({row,col}); 
        out << " " << square; 
    }

    out << "|"; 
  }
  
  out << std::endl << "  "; 
  for(int row{7}; row >= 0; --row) out << " -"; 
  out << std::endl; 

  out << "  "; 
  for(int row{0}; row < 8; ++row) out << " " << boardColumnChars[row]; 
  out << std::endl << std::endl; 
}
