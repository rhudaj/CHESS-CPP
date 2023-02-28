# CHESS-CPP

# Summary
CS 246 - Object-Oriented Software Development Chess Game

Our team created this game for CS246 — Assignment-5 "Group Project" (Fall 2022)

The game has the following functions: 

4 levels of difficulty for the computer AI: easy, medium, hard, master
Graphical interface using X11-libraries 
Setup Mode: create a custom board setup and launch the game from that state 
Play Modes: 
  Player vs Player
  Player vs Computer
  Computer vs Computer
Command Line for controls/Instruction

# To Start a new Game

Game [white-player] [black-player] starts a new game

W

white-player & black-player parameters can be either: human or computer[1-4]
resign concedes the game to your opponent

capital letters represent white pieces, otherwise black pieces

Letter	K	Q	R	B	N	P
Piece	King	Queen	Rook	Bishop	Knight	Pawn
To move: move src dst (ex. move e2 e4)

castling is specified by two-square move for the king

black: move e1 g1
white: move e1 c1
Pawn promotion additionally specify the piece type to which the pawn is promoted: move e7 e8 Q.

setup enters setup mode that can set up initial board configurations(can only be done when game is not running)

+ piece position places the piece on the position (ex. + K e1), replaces if a piece already exists
- position removes the piece from the position(ex. - e1), takes no action if there is nothing
= colour makes it colour’s turn to go next(ex. = white)
done leaves setup mode
history for viewing your past moves

For more detailed instructions: Instructions

Design & Planning
We used Observer pattern as a design recipe for the game.

For how our team tackled the project: Plan


UML In pdf: UML
