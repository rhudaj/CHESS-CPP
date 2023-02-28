#include "windowobserver.h"
#include "window.h"
#include "board.h"
#include "subject.h"
#include "globals.h"
#include "squaredecorator.h"
#include <string>

WindowOb::WindowOb(Board* board, PositionsToUpdate& positionsToUpdate): board{board}, positionsToUpdate{positionsToUpdate}
{
  window = new Xwindow;                         //open a new window (instantiate)  
  board->attach(this);                          //attach this observer to the subject
}

WindowOb::~WindowOb() 
{
  board->detach(this);                          //detach this obserber from the subject
  window->~Xwindow();

  while(!decorators.empty())
  {
    delete decorators.back(); 
    decorators.pop_back(); 
  }
}

void WindowOb::squareOutput(Pos pos)
{
  Square square = board->getState(pos);
    Color squareColor = square.getColor();  
    Piece* piece = square.getPiece(); 
      char piece_char = square.getPieceChar(); 
      PlayerNum player = square.getPiecePlayer(); 

  int pieceColor = (player == p2) ? window->Black : window->White; 
  
  int x0 = ( (pos.getCol())  * squareWidth ) + boardLeftMargin; 
  int y0 = ( (7 - pos.getRow()) * squareHeight ) + boardTopMargin; 

  window->fillRectangle(x0, y0, squareWidth, squareHeight, squareColor); 

  SquareDecorator* decorator = nullptr; 

  if(piece_char == 'Q' || piece_char == 'q')
  {
    decorator = new KingDecoration{window, x0, y0, pieceColor}; 
  }
  else if(piece_char == 'K' || piece_char == 'k')
  {
    decorator = new QueenDecoration{window, x0, y0, pieceColor};
  }
  else if(piece_char == 'R' || piece_char == 'r')
  {
    decorator = new RookDecoration{window, x0, y0, pieceColor}; 
  }
  else if(piece_char == 'B' || piece_char == 'b')
  {
    decorator = new BishopDecoration{window, x0, y0, pieceColor}; 
  }
  else if(piece_char == 'N' || piece_char == 'n')
  {
    decorator = new KnightDecoration{window, x0, y0, pieceColor}; 
  }
  else if(piece_char == 'P' || piece_char == 'p')
  {
    decorator = new PawnDecoration{window, x0, y0, pieceColor}; 
  }
  if(decorator) decorator->build();  

  decorators.emplace_back(decorator); 
}

void WindowOb::rowStringOutput()
{
  std::string boardColumnChars[8] = {"A", "B", "C", "D", "E", "F", "G", "H"}; 
  int x0; 
  for(int col{0}; col < board->numCols; ++col)
  {
    x0 = col * squareHeight;
    window->drawString(x0 + boardLeftMargin + squareWidth / 2, squareHeight*9, boardColumnChars[col]); 
  }
}

void WindowOb::colStringOutput()
{
  int y0; 
  for(int row{1}; row <= board->numRows; ++row)
  {
    y0 = (row - 1) * squareHeight;
    std::string rowNum = std::to_string((row - 9)*-1); 
    window->drawString(boardLeftMargin/2, y0 + squareHeight/2 + boardTopMargin, rowNum); 
  }
}

void WindowOb::notify()                                          
{
  colStringOutput(); 

  while(!positionsToUpdate.none())
  {
    Pos pos = positionsToUpdate.get(); 
    squareOutput(pos);
  }

  rowStringOutput(); 
}
