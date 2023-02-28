#include "square.h"
#include "board.h"
#include "position.h"
#include "globals.h"
#include <iostream>
#include "move.h"
#include "boardTracker.h"

#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "empty.h"

Board::Board() {} 

Board::~Board()
{
  for(int row{0}; row < numRows; ++row)
  {
    for(int col{0}; col < numCols; ++col)
    {
      deletePiece({row,col}); 
    }
  }
}

Square Board::getState(Pos pos) const
{
  return squares[pos.row][pos.col]; 
}

Piece* Board::PieceAt(Pos pos) const
{
  return squares[pos.row][pos.col].getPiece(); 
}

char Board::charAt(Pos pos) const
{
  return PieceAt(pos)->getChar(); 
}

Piece* pieceFromPos(Pos& pos, PlayerNum playerNum)
{
  Piece* piece = nullptr; 

  int row = pos.getRow(); 
  int col = pos.getCol(); 

  if(row == 0 || row == 7)
  {
    if(col == 0 || col == 7)                piece = new Rook(playerNum); 
    else if(col == 1 || col == 6)           piece = new Knight(playerNum); 
    else if(col == 2 || col == 5)           piece = new Bishop(playerNum); 
    else if(col == 3)                       piece = new Queen(playerNum); 
    else if(col == 4)                       piece = new King(playerNum); 
  }
  else if(row == 1 || row == 6)
  {
    piece = new Pawn(playerNum);
  }
  else
  {
    piece = new Empty(); 
  }

  return piece; 
}

Color colorFromPos(Pos& pos)
{
  Color squareColor;

  int row = pos.getRow(); 
  int col = pos.getCol(); 

  if(row % 2) (col % 2) ? squareColor = white : squareColor = black; 
  else            (col % 2) ? squareColor = black : squareColor = white; 

  return squareColor; 
}

void Board::initializeBoardEmpty()
{
  for(int row{0}; row < numRows; ++row)
  {

    for(int col{0}; col < numCols; ++col)
    {
      Pos pos{row, col}; 
      Piece* emptyPiece = new Empty(); 
      Square newSquare = Square(emptyPiece, colorFromPos(pos));  
      squares[row][col] = newSquare; 
    }
  }
}

void Board::initializeBoardStandard()
{
  for(int row{0}; row < numRows; ++row)
  {
    PlayerNum playerNum = none; 
      if (row < 2) playerNum = p1;
      if (row > 5) playerNum = p2; 
  
    for(int col{0}; col < numCols; ++col)
    {
      Pos pos{row, col}; 
      
      Square newSquare = Square(pieceFromPos(pos, playerNum), colorFromPos(pos));  //piece == nullptr if no piece there

      squares[row][col] = newSquare; 
    }
  }
}

void Board::move(const Move& move)
{ 
  Pos startPos = move.start(); 
  Pos endPos = move.end(); 

  Piece* movingPiece = squares[startPos.row][startPos.col].getPiece();  //get the moving piece pointer 

  //deletePiece(endPos); 
  setPiece(endPos, movingPiece); 

  Piece* emptyPiece = new Empty(); 
  setPiece(startPos, emptyPiece);
}

bool Board::isEmpty(Pos pos)
{
  return squares[pos.getRow()][pos.getCol()].getPieceChar() == ' ';  //should check for nullptr
}

void Board::setPiece(Pos pos, Piece* piece)
{
  squares[pos.getRow()][pos.getCol()].setPiece(piece); 
}

void Board::deletePiece(Pos pos)
{
  delete getState(pos).getPiece(); 
}

bool Board::isPlayersPiece(Pos pos, PlayerNum player) const
{
  return ( getState(pos).getPiecePlayer() == player );
}

bool Board::pieceBetweenPositions(Move move)
{
    int startRow = move.start().getRow(); 
    int startCol = move.start().getCol(); 

    int endRow = move.end().getRow();
    int endCol = move.end().getCol(); 

    if(abs(endRow-startRow) == abs(endCol-startCol)) //moving diagonal
    {
      if(abs(endRow-startRow) == 1) //only moving one space diagonal
      {
        return false; 
      }
      if(endCol > startCol)   //going right
      {
        if(endRow > startRow) //going up
        {
          int y = startRow + 1; 
          for(int x = startCol + 1; x < endCol; x++)
          {
            if(!isEmpty({y,x})) 
            {
              return true; 
            }
            ++y; 
          }
        }
        else                  //going down 
        {
          int y = startRow - 1; 
          for(int x = startCol + 1; x < endCol; x++)
          {
            if(!isEmpty({y,x})) 
            {
              return true; 
            }
            --y; 
          }
        }
      }
      else                    //going left
      {
        if(endRow > startRow) //going up
        {
          int y = startRow + 1; 
          for(int x = startCol - 1; x > endCol; x--)
          {
            if(!isEmpty({y,x})) 
            {
              return true; 
            }
            ++y; 
          }
        }
        else                  //going down 
        {
          int y = startRow - 1; 
          for(int x = startCol - 1; x > endCol; x--)
          {
            if(!isEmpty({y,x})) 
            {
              return true; 
            }
            --y; 
          }
        }
      }

    }
    else if(startRow == endRow)   //moving horizontal
    {

      int constRow = startRow; 

      if(abs(startRow-endRow) == 1) return false;  //only moving one space 
    
      if(endCol > startCol) //if going right
      {
        for(int x = startCol + 1; x < endCol; x++) 
        {
          if(!isEmpty({constRow, x})) return true;     //piece in the way
        }
      }
      else      //going left
      {
        for(int x = startCol - 1; x > endCol; x--) 
        {
          if(!isEmpty({constRow, x})) return true;     //piece in the way
        }
      }
    }
    else if (startCol == endCol) //moving vertical
    {
      if(abs(startCol-endCol) == 1) return false;  //only moving one space

      int constCol = startCol; 

      if(endRow > startRow) //if going up
      {
        for(int y = startRow + 1; y < endRow; y++) 
        {
          if(!isEmpty({y, constCol})) return true;     //piece in the way
        }
      }
      else      //going down
      {
        for(int y = startRow - 1; y > endRow; y--) 
        {
          if(!isEmpty({y, constCol})) return true;     //piece in the way
        }
      }
    }
  return false; 
}
