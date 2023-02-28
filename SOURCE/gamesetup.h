#ifndef GAME_SETUP
#define GAME_SETUP

#include "globals.h"
#include "piece.h"
#include "char2piece.h"
#include "board.h"
#include "boardTracker.h"
#include "windowobserver.h"

class GameSetup
{
    friend class Game; 

    private: 

        Board* board; 

        PlayerNum startingPlayer; 

        PositionsToUpdate positionsToUpdate; 

        WindowOb* setupWindow; 

    public: 

        GameSetup();

        ~GameSetup(); 

        WindowOb* addObservers(); 

        void setStartPlayer(PlayerNum startingPlayer);

        void addPiece(char pieceChar, Pos pos);
     
        void removePiece(Pos pos);

        void done(); 
};

#endif
