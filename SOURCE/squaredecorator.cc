#include "squaredecorator.h"
    

SquareDecorator::SquareDecorator(Xwindow* window, int x0, int y0, int color): window{window}, x0{x0}, y0{y0}, color{color} {}

SquareDecorator::~SquareDecorator() {}

void SquareDecorator::box(int left, int right, int top, int bottom) 
{
    window->fillRectangle(x0+left, y0+top, right-left, bottom-top, color); 
}

int SquareDecorator::centeredBox(int bottom, int width, int height)
{
    int center = x0 + 20; 
    int leftX = center - width/2; 

    int startY = y0 + (bottom - height); 

    window->fillRectangle(leftX, startY, width, height, color); 
    
    return bottom - height;
}


//kind decorator

KingDecoration::KingDecoration(Xwindow* window, int x0, int y0, int color): SquareDecorator{window, x0, y0, color} {}
    
KingDecoration::~KingDecoration()
{
    window = nullptr; 
}

void KingDecoration::build()
{
    //base
    int y = centeredBox(piece_bottom, 12, 4); 
    y = centeredBox(y, 10, 2);  
    //neck
    y = centeredBox(y, 6, 10); 
    y = centeredBox(y, 10, 2);  
    //crown
    y = centeredBox(y, 4, 2);  
    y = centeredBox(y, 6, 2);  
    y = centeredBox(y, 8, 2);  
    y = centeredBox(y, 10, 3);  
    //plus sign
    y = centeredBox(y, 2, 2);  
    y = centeredBox(y, 6, 2);
    y = centeredBox(4, 2, 2); 
}

//queen decorator

QueenDecoration::QueenDecoration(Xwindow* window, int x0, int y0, int color): SquareDecorator{window, x0, y0, color} {}

QueenDecoration::~QueenDecoration()
{
    window = nullptr; 
}

void QueenDecoration::build()
{
    //base
    int y = centeredBox(piece_bottom, 14, 2); 
    y = centeredBox(y, 12, 3);       
    y = centeredBox(y, 8, 3); 
    //neck
    y = centeredBox(y, 6, 10);   
    y = centeredBox(y, 10, 2);
    //crown
    y = centeredBox(y, 4, 3);  
    y = centeredBox(y, 6, 2);   
    y = centeredBox(y, 8, 2);
    y = centeredBox(y, 10, 2); 
    //circle  
    y = centeredBox(y, 2, 1); 
    y = centeredBox(y, 4, 2);
    y = centeredBox(y, 2, 1); 
}

//knight decor

KnightDecoration::KnightDecoration(Xwindow* window, int x0, int y0, int color): SquareDecorator{window, x0, y0, color} {}

KnightDecoration::~KnightDecoration()
{
    window = nullptr; 
}

void KnightDecoration::build()
{

   //base 
    int y = centeredBox(piece_bottom, 18, 2); //y=33
    y = centeredBox(y, 16, 3); //y=30
    y = centeredBox(y, 10, 3); //y=27

    //head post
    y = centeredBox(y, 8, 15); //y=12
    y = centeredBox(y, 12, 4); //y=8

    //head
    int z = y - 8;

    box(10, 12, z+18, z+20); 

    box(10, 18, z+12, z+18); 

    box(22, 26, 10, 25); 
}

//rook decor

RookDecoration::RookDecoration(Xwindow* window, int x0, int y0, int color): SquareDecorator{window, x0, y0, color} {}

RookDecoration::~RookDecoration()
{
    window = nullptr; 
}

void RookDecoration::build()
{
    //base
    int y = centeredBox(piece_bottom, 16, 4); 
    y = centeredBox(y, 14, 2); 
    y = centeredBox(y, 10, 2); 
    //neck
    y = centeredBox(y, 8, 15); 
    //top
    y = centeredBox(y, 12, 6); 
}

//bishop decor

BishopDecoration::BishopDecoration(Xwindow* window, int x0, int y0, int color): SquareDecorator{window, x0, y0, color} {}

BishopDecoration::~BishopDecoration()
{
    window = nullptr; 
}

void BishopDecoration::build()
{
      //base
      int y = centeredBox(piece_bottom, 14, 2); 
      y = centeredBox(y, 12, 3);       
      y = centeredBox(y, 8, 3);      

      //neck
      y = centeredBox(y, 6, 4); 
      y = centeredBox(y, 4, 8);   
      y = centeredBox(y, 8, 2);  

      //spout
      y = centeredBox(y, 4, 2);
      y = centeredBox(y, 6, 3);  
      y = centeredBox(y, 4, 2);  
      y = centeredBox(y, 2, 1); 
      
      //circle 
      y = centeredBox(y, 2, 1); 
      y = centeredBox(y, 4, 2); 
      y = centeredBox(y, 2, 1); 
}

//pawn decor

PawnDecoration::PawnDecoration(Xwindow* window, int x0, int y0, int color): SquareDecorator{window, x0, y0, color} {}

PawnDecoration::~PawnDecoration()
{
    window = nullptr; 
}

void PawnDecoration::build()
{
    //base 
    int y = centeredBox(piece_bottom, 18, 2); //y=27
    y = centeredBox(y, 16, 3);        //y=24
    y = centeredBox(y, 10, 3);      //y=21
    //neck
    y = centeredBox(y, 8, 2); 
    y = centeredBox(y, 6, 4);  
    y = centeredBox(y, 4, 3);  
    //top
    y = centeredBox(y, 6, 2);  //8
    y = centeredBox(y, 10, 4); //10
    y = centeredBox(y, 6, 2);  //12
}

