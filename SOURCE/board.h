#ifndef BOARD
#define BOARD

  //includes
#include "square.h"
#include <iostream>
#include "position.h"
#include "subject.h"
#include "move.h"
#include <vector>
#include "boardTracker.h"
class GameSetup; 

class Board : public Subject
{
  friend class GameSetup; //a game setup should be the only thing that can modify a board

  public: 

    static const int numRows{8}, numCols{8};
  
  private: //data

    Square squares[numRows][numRows]; 

  private: //methods

    Piece* PieceAt(Pos pos) const; 

    char charAt(Pos pos) const; 

  public: //methods 

    Board(); 

    ~Board(); 

    Square getState(Pos pos) const override;

    void initializeBoardEmpty(); 
    
    void initializeBoardStandard(); 

    void move(const Move& move); 

    bool isEmpty(Pos pos); 

    void setPiece(Pos pos, Piece* piece);

    void deletePiece(Pos pos);

    bool isPlayersPiece(Pos pos, PlayerNum player) const; 

    bool pieceBetweenPositions(Move move); 
}; 

#endif

