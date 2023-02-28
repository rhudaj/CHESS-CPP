#include "gamesetup.h"
#include "board.h"
#include "position.h"
#include "square.h"
#include "windowobserver.h"
#include "empty.h"

GameSetup::GameSetup(): board{new Board()}
{
    board->initializeBoardEmpty(); 

    positionsToUpdate.allPositions(board->numRows, board->numCols); 

    setupWindow = addObservers(); 

    board->notifyObservers(); 
}

GameSetup::~GameSetup() 
{
  delete board; 
}

void GameSetup::setStartPlayer(PlayerNum startingPlayer)
{
    startingPlayer = startingPlayer; 
}

WindowOb* GameSetup::addObservers()
{
  return new WindowOb(board, positionsToUpdate); 
}

void GameSetup::addPiece(char pieceChar, Pos pos)
{
    board->setPiece(pos, char2Piece(pieceChar)); 
    positionsToUpdate.add(pos); 
    board->notifyObservers(); 
}

void GameSetup::removePiece(Pos pos)
{
  Piece* emptyPiece = new Empty(); 
  board->setPiece(pos, emptyPiece); 
  positionsToUpdate.add(pos); 
  board->notifyObservers(); 
}

void GameSetup::done()
{
  delete setupWindow; 
}
