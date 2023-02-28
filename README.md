# CHESS-CPP

# Summary
CS 246 - Object-Oriented Software Development Chess Game

Our team created this game for CS246 — Assignment-5 "Group Project" (Fall 2022)

## Highlighted features:

4 levels of difficulty for the computer AI: easy, medium, hard, master
Graphical interface using X11-libraries 
Setup Mode: create a custom board setup and launch the game from that state 
Play Modes: 
  Player vs Player
  Player vs Computer
  Computer vs Computer
Stalemate
Checkmate
Castling 

# Command Guide (How to Play)


  **Game [white-player] [black-player]**

    Starts a new game. 
    
    white-player & black-player parameters can be either: 
    1. human
    2. computer[1-4] (1 being easy-mode, 4 being master mode)  

  **resign**
  
    concedes the game to your opponent
    
## Moving Pieces 
 
  **move [square 1] [square 2]**
  
    example: move e4 e5 

    Capital letters represent white pieces, otherwise black pieces

    k/K - king
    q/Q - queen
    r/R - rook 
    b/B - bishop
    n/N- knight
    p/P - pawn

    to move, it must be your turn 
    You can only move to valid squares

    castling is specified by two-square move for the king

      black: move e1 g1
      white: move e1 c1
      
    Pawn promotion: specify the piece type to which the pawn is promoted: 
    
        ie: move f7 f8 Q 

## Setup Mode
  **setup**
    enters setup mode that for setting up initial board configurations before you start
  **+**
      piece position places the piece on the position (ex. + K e1), replaces if a piece already exists
  **-**
      position removes the piece from the position(ex. - e1), takes no action if there is nothing
  **=**
      colour makes it colour’s turn to go next(ex. = white)
  **done**
      leaves setup mode


