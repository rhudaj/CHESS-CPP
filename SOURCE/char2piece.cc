#include "char2piece.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

Piece* char2Piece(char pieceChar)
{
    Piece* piece = nullptr; 

    if(pieceChar == 'K' || pieceChar == 'k')
    {
        PlayerNum player; 
        if(pieceChar == 'K')    player = p1;
        else                    player = p2; 

        piece = new King(player); 
    }
    else if(pieceChar == 'Q' || pieceChar == 'q')
    {
        PlayerNum player; 
        if(pieceChar == 'Q')    player = p1;
        else                    player = p2; 

        piece = new Queen(player); 
    }
    else if(pieceChar == 'B' || pieceChar == 'b')
    {
        PlayerNum player; 
        if(pieceChar == 'B')    player = p1;
        else                    player = p2; 

        piece = new Bishop(player); 
    }
    else if(pieceChar == 'N' || pieceChar == 'n')
    {
        PlayerNum player; 
        if(pieceChar == 'N')    player = p1;
        else                    player = p2; 

        piece = new Knight(player); 
    }
    else if(pieceChar == 'R' || pieceChar == 'r')
    {
        PlayerNum player; 
        if(pieceChar == 'R')    player = p1;
        else                    player = p2; 

        piece = new Rook(player); 
    }
    else if(pieceChar == 'P' || pieceChar == 'p')
    {
        PlayerNum player; 
        if(pieceChar == 'P')    player = p1;
        else                    player = p2; 

        piece = new Pawn(player); 
    }
    
    return piece; 
}
