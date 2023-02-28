#include "game.h"
#include "textobserver.h"
#include "windowobserver.h"
#include <iostream>
#include "move.h"
#include "board.h"
#include "gamesetup.h"
#include "globals.h"
#include "position.h"
using namespace std; 

Game::Game(): board{new Board()}
{
  currPlayer = p1;
  otherPlayer = p2; 

  board->initializeBoardStandard();

  positionsToUpdate.allPositions(board->numRows, board->numCols); 
  
  addObservers(); 

  board->notifyObservers(); 
}

Game::~Game() 
{
  delete windowOb;  //detaches itself from board
  delete textOb;    //detaches itself from board
  delete board;
}

Game::Game(GameSetup* gameSetup): board{gameSetup->board}, currPlayer{gameSetup->startingPlayer} //copy the board made by the setup object
{
  otherPlayer = (currPlayer == p1) ? p2 : p1; 

  out << "new game from setup!" << std::endl; 

  positionsToUpdate.allPositions(board->numRows, board->numCols); 

  addObservers(); 

  board->notifyObservers(); 
}


void Game::gameLoop(std::istream& in)
{
  string command; 

  while(cin >> command)
  {
    if(command == "resign")
    {
      out << currPlayer << " has resigned" << std::endl; 
      return; 
    }
    else if(command == "move")
    {
      Move moveToMake; 
      in >> moveToMake;

      if(!moveToMake.isWithinBounds(board->numRows, board->numCols))
      {
        continue; 
      }
      move(moveToMake); 
      gameOutput(); 
    }
  } 
}

void Game::addObservers()
{
  textOb = new TextOb(board); 

  windowOb = new WindowOb(board, positionsToUpdate); 
}

void Game::gameOutput()
{
  board->notifyObservers(); 
}

void Game::nextPlayersMove()
{
  if(currPlayer == p1) 
  {
    currPlayer = p2; 
    otherPlayer = p1; 
  }
  else if(currPlayer == p2) 
  {
    currPlayer = p1; 
    otherPlayer = p2; 
  }
}

bool Game::validMove(Move move, PlayerNum player)   //check if the move your trying to make is valid before changing the board
{
  if(!board->isPlayersPiece(move.start(), player))   //Is it the chosen pieces turn to move? 
  {
    out << "invalid move. Not your piece to move." << std::endl; 
    return false;
  }
  else if(board->isPlayersPiece(move.end(), player)) //are you trying to take your own piece? 
  {
    out << "invalid move. Can't take your own piece" << std::endl; 
    return false;
  }

  Square square = board->getState(move.start()); 
  Piece* movingPiece = square.getPiece(); 
  char pieceChar = square.getPieceChar();

  if(!movingPiece->canMove(move))  //if the piece can physically make the move (based on it's type) and it's not jumping over pieces if it's not allowed to. 
  {
    out << pieceChar << " can't physically make that move" << std::endl; 

    return false;   
  }

  if( ( pieceChar != 'N' && pieceChar != 'n' && pieceChar != 'K' && pieceChar != 'k' ) && board->pieceBetweenPositions(move)) //if not a knight (only piece that can jump)
  { 
    out << "Invalid move. " << pieceChar << " can't jump over pieces" << std::endl; 
    return false;
  }

  if(pieceChar == 'K' || pieceChar == 'k' && kingInCheckAtPos(move.end(), player)) //if doing this move would put your king in check...
  {
    out << "Invalid move. Can't put your own king in check." << std::endl; 
    return false;
  }

  return true; 
}

Pos Game::getKingPosition(PlayerNum player)
{
  if(player == p1)      return p1kingpos; 
  else if(player == p2) return p2kingpos; 
}

void Game::move(Move move)
{
  if(!validMove(move, currPlayer)) return; 

  board->move(move);                                                  //actually move the pieces on the board. 

  if( kingInCheckAtPos(getKingPosition(otherPlayer), otherPlayer) )   //after the move, check the game condition: 
  {
    if(wonByCheckMate(currPlayer))                                    //if the move you just made put the other king in checkmate. Then curr player has won. 
    {
      win(currPlayer); 
      return; 
    }
  }
  else if(!kingInCheckAtPos(getKingPosition(otherPlayer), otherPlayer) && inStaleMate(otherPlayer))
  {
    tie(currPlayer);
    return; 
  }
  else if(!kingInCheckAtPos(getKingPosition(currPlayer), currPlayer) && inStaleMate(currPlayer)) //if the move you just made put you or the other player in stalemate. The game is a tie. 
  {
    tie(currPlayer); 
    return; 
  }
  else  //otherwise, move onto the next players move 
  {
    char pieceChar = board->getState(move.start()).getPieceChar(); 

    if(pieceChar == 'K' || pieceChar == 'k')     //otherwise, you can move your king here. Update the currplayer's king pos. 
    {
      updateKingPosition(move.end(), currPlayer); 
    }

    positionsToUpdate.add(move.start()); 
    positionsToUpdate.add(move.end()); 
    nextPlayersMove(); 
  }
}

void Game::win(PlayerNum winner)
{
  out << winner << " is a winner!" << std::endl; 
}

void Game::tie(PlayerNum stuckPlayer)
{
  out << "Stalemate! " << stuckPlayer << "can't move!" << std::endl; 
}

PlayerNum Game::getOtherPlayer(PlayerNum player) const
{
  if(player == p1) return p2;
  else if(player == p2) return p1; 
}

bool Game::pieceCanMakeMove(Move move)
{
  Square square = board->getState(move.start()); 
  Piece* movingPiece = square.getPiece(); 

  if(movingPiece->canMove(move))    //if the piece can't physically make that move based on it's type
  {
    char pieceChar = square.getPieceChar(); 

    if(pieceChar != 'N' && pieceChar != 'n' && pieceChar != 'K' && pieceChar != 'k' && board->pieceBetweenPositions(move)) //if not a knight (only piece that can jump)
    {
      return false;
    }
    else 
    {
      return true; 
    }
  }
  else 
  {
    return false; 
  }
}

void Game::updateKingPosition(Pos pos, PlayerNum player)
{
  if(player == p1)
  {
    p1kingpos = pos; 
  }
  else if(player == p2)
  {
    p2kingpos = pos; 
  }           
}

bool Game::playerInCheck(PlayerNum playerToCheck)
{
  Pos kingPos = (playerToCheck == p1) ? p1kingpos : p2kingpos; 

  for(int row = 0; row < board->numRows; ++row) //check if any piece on the board can move to the king
  {
    for(int col = 0; col < board->numCols; ++col)
    {
      Pos currPos{row,col}; 
      Square square = board->getState(currPos); 
      Piece* piece = board->getState(currPos).getPiece(); 
      Move move2King{currPos, kingPos}; 
      PlayerNum player = square.getPiecePlayer(); 

      if(player != playerToCheck && !board->isEmpty(currPos))
      {
        if( pieceCanMakeMove(move2King) )
        {
          return true; 
        }
      }
    }
  }
  return false; 
}

bool Game::kingInCheckAtPos(Pos pos, PlayerNum playerToCheck)
{
  for(int row = 0; row < board->numRows; ++row) //check if any piece on the board can move to the king
  {
    for(int col = 0; col < board->numCols; ++col)
    {
      Pos currPos{row,col}; 
      Move move2King{currPos, pos}; 
      Square square = board->getState(currPos); 
      PlayerNum player = square.getPiecePlayer(); 

      if(player != playerToCheck && !board->isEmpty(currPos) && pieceCanMakeMove(move2King)) 
      {
        return true; 
      }
    }
  }
  return false; 
}

bool Game::wonByCheckMate(PlayerNum winner) //called when a king is in check
{
  Pos kingInTroublePos; 
  PlayerNum loser; 

  if(winner == p1) 
  {
    kingInTroublePos = p2kingpos; 
    loser = p2; 
  }
  else if(winner == p2) 
  {
    loser = p1; 
    kingInTroublePos = p1kingpos; 
  }

  int kingRow = kingInTroublePos.getRow(); 
  int kingCol = kingInTroublePos.getCol(); 

  for(int x = -1; x <= 1; ++x)
  {
    for(int y = -1; y <= 1; y++)
    {
      Pos pos{kingInTroublePos.getRow()+ x, kingInTroublePos.getCol() + y}; 
      {
        Move escapeMove{kingInTroublePos,pos}; 

        if(validMove(escapeMove, loser) && !kingInCheckAtPos(pos, loser) && board->isEmpty(pos) && y+x != 0)
        {
          return false; 
        }
      }
    }
  }  
  return true; 
}

bool Game::inStaleMate(PlayerNum stuckPlayer) //called when the king is not in check
{
  Pos kingInTroublePos; 

  if(stuckPlayer == p1) 
  {
    kingInTroublePos = p1kingpos; 
  }
  else if(stuckPlayer == p2) 
  {
    kingInTroublePos = p2kingpos; 
  }

  int kingRow = kingInTroublePos.getRow(); 
  int kingCol = kingInTroublePos.getCol(); 

  for(int x = -1; x <= 1; ++x)
  {
    for(int y = -1; y <= 1; ++y)
    {
      Pos pos{kingInTroublePos.getRow() + x, kingInTroublePos.getCol() + y}; 

      if(pos.isWithinBounds(board->numRows, board->numCols))
      {
        Move escapeMove{kingInTroublePos,pos}; 

        if(!kingInCheckAtPos(pos, stuckPlayer)) //should we check that the board is empty at that position?
        {
          if(y+x == 0) //current pos
          {
            return false; 
          }
          else if(board->isEmpty(pos))
          {
            return false; 
          }
        }
      }
    }
  }  
  return true; 
}
