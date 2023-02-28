#include <iostream>
#include "string"
#include "window.h"
#include "move.h"
#include "game.h"
#include "gamesetup.h"

using namespace std; 

void setupLoop(GameSetup* gameSetup)
{
  cout << "in setup mode " << endl; 

  string setupCmd; 

  while(cin >> setupCmd)
  {
    if(setupCmd == "+")
    {
      char pieceChar; 
      Pos pos; 

      cout << "adding a piece: " << endl; 

      cin >> pieceChar >> pos; 

      cout << "adding " << pieceChar << " to " << pos << endl; 

      gameSetup->addPiece(pieceChar, pos); 
    }
    else if(setupCmd == "-")
    {
      Pos pos; 

      cin >> pos; 
      
      gameSetup->removePiece(pos); 
    }
    else if(setupCmd == "=")
    {
      PlayerNum startPlayer; 

      string startPlayerStr;

      cin >> startPlayerStr; 

      if(startPlayerStr == "white")  startPlayer = p1; 
      else if(startPlayerStr == "black") startPlayer = p2; 

      gameSetup->setStartPlayer(startPlayer); 
    }
    else if(setupCmd == "done")
    {
      gameSetup->done(); 
      return; 
    }
  }
}

int main()
{
  string command1; 

  while(cin >> command1)
  {
    if(command1 == "game")
    {
      string white_player, black_player;  

      cin >> white_player >> black_player; 

      Game* game = new Game(); //standard game 
      
      game->gameLoop(cin); 

      delete game; 
    }
    else if(command1 == "setup")
    {
      GameSetup* gameSetup = new GameSetup(); 

      setupLoop(gameSetup); 

      Game* game = new Game(gameSetup); //standard game 

      game->gameLoop(cin); 

      delete game; 
      delete gameSetup; 
    }
  }
}
