# CHESS-CPP

## Summary
CS 246 - Object-Oriented Software Development Chess Game

Our team created this game for CS246 — Assignment-5 "Group Project" (Fall 2022)

## Highlighted features:

* AI computer opponent with 4 levels of difficulty: easy, medium, hard, master
* Graphical interface using X11-libraries 
* Setup Mode: create a custom board setup and launch the game from that state 
* Play Modes: 
  * Player vs Player
  * Player vs Computer
  * Computer vs Computer
* Stalemate
* Checkmate
* Castling 

# Design

[uml.pdf](https://github.com/Romanhudaj11/CHESS-CPP/blob/main/DOCUMENTATION/uml.pdf)

# Instructions

## How Pieces are represented in instructions: 

  Letters (Capital letters represent white pieces, lowercase represent black pieces) are used to represent pieces as follows: 

  Symbols | Piece
  --------| --------
  k/K     | king
  q/Q     | queen
  r/R     | rook 
  b/B     | bishop
  n/N     | knight
  p/P     | pawn
  
## How Positions are represented in instructions: 

  the board is a grid. Positions follow what is shown in the image below: 
  
  ![alt text](https://www.houseofstaunton.com/media/wysiwyg/ChessBasics/HOS/blank-board.jpg)
  
  

# Command Guide (How to Play)

`Game [white-player] [black-player]`

   Starts a new game. 
    
  [white-player] & [black-player] parameters can be either: 
  
  1. human
  2. computer[1-4] (1 being easy-mode, 4 being master mode)  
    
   Examples: 
   
    Game human computer[1]
    Game human human
    Game computer[2] human
    Game computer[1] computer[4]

`resign`
  
  concedes the game to your opponent
    
## Moving Pieces 
 
  `move [square 1] [square 2]`
  
  example: 

    move e4 e5 

  to move, it must be your turn 
  You can only move to valid squares

  castling is specified by two-square move for the king
  
  Example:

      black: move e1 g1
      white: move e1 c1
      
  Pawn promotion: specify the piece type to which the pawn is promoted: 
  
  Example:

      move f7 f8 Q 

## Setup Mode

`setup`

  enters setup mode that for setting up initial board configurations before you start
  
`+ [piece] [position]`

  piece position places the piece on the position.
  replaces if a piece already exists
  
  Example: 
  
    + K e1
    + q f2

`- [position]`

  position removes the piece from the position
  takes no action if there is nothing
  
  Example: 
  
    - e1
    - f2

`= [white/black]`

  colour makes it colour’s turn to go next
  
  Example: 
  
    = white

`done`

  leaves setup mode


