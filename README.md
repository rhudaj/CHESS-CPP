# CHESS-CPP

# Summary
CS 246 - Object-Oriented Software Development Chess Game

Team Members : Edward Jiwook Kim, Nipun Lamba, and Prabhapaar Singh Batra

Our team developed this chess game for CS246 — Assignment 5, Group Project (Winter 2019)

The chess game provides all functionalities from the assignment specification:

4 levels of difficulty for the computer AI
Graphical interface using X11
Setup Mode
Move History
Play Modes of
Player vs Player
Player vs Computer
Computer vs Computer
Command Interpreter Instructions
game white-player black-player starts a new game.

white-player & white-player parameters can be either human or computer[1-4]
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
