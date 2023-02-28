#ifndef GAME
#define GAME

#include "board.h"
#include "boardTracker.h"
#include "globals.h"
#include "position.h"
#include "piece.h"
#include <iostream>
class WindowOb;
class TextOb;

class Game
{
  private:  

    std::ostream& out = std::cout; 

    Board* board; 

    PlayerNum currPlayer; 
    PlayerNum otherPlayer; 

    PositionsToUpdate positionsToUpdate; 

    WindowOb* windowOb; 
    TextOb* textOb; 

    void updateKingPosition(Pos pos, PlayerNum player); 

  private:

    Pos p1kingpos{0,4};  
    Pos p2kingpos{7,4}; 

  public: 

    void gameLoop(std::istream& in); 

    void gameOutput(); 

    Game();   

    ~Game(); 

    Game(GameSetup* gameSetup); 

  private: 

    void addObservers(); 

    void resign(); 

    void win(PlayerNum winner); 

    void tie(PlayerNum stuckPlayer); 

    bool validMove(Move move, PlayerNum player); 

    void move(Move move); 

    void nextPlayersMove(); 

    bool playerInCheck(PlayerNum player); 

    bool kingInCheckAtPos(Pos pos, PlayerNum playerToCheck); 

    bool kingInCheck(PlayerNum playerToCheck); 

    bool pieceCanMakeMove(Move move); 

    PlayerNum getOtherPlayer(PlayerNum player) const; 

    Pos getKingPosition(PlayerNum player); 

    bool wonByCheckMate(PlayerNum winner); 

    bool inStaleMate(PlayerNum movingPlayer); 
};

#endif
