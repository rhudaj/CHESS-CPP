#ifndef SQUARE_DECORATOR
#define SQUARE_DECORATOR

#include "window.h"

class SquareDecorator
{
  protected: 

    Xwindow* window;              //does not own

    int x0, y0;                   //top left coordinates of a square

    int color;                    //the decorator has a color

    const int piece_bottom = 37;  //the bottom of the decorator 

  public: 

    SquareDecorator(Xwindow* window, int x0, int y0, int color); 

  protected:

    void box(int left, int right, int top, int bottom); 

    int centeredBox(int bottom, int width, int height); 

  public: 

    virtual void build() = 0; 

    virtual ~SquareDecorator(); 
}; 

class KingDecoration : public SquareDecorator
{
  public: 

    KingDecoration(Xwindow* window, int x0, int y0, int color);

    ~KingDecoration(); 

    void build() override;
}; 

class QueenDecoration : public SquareDecorator
{
  public: 
    QueenDecoration(Xwindow* window, int x0, int y0, int color); 

    ~QueenDecoration(); 

    void build() override;
}; 

class KnightDecoration : public SquareDecorator
{
  public: 

    KnightDecoration(Xwindow* window, int x0, int y0, int color); 

    ~KnightDecoration(); 

    void build() override; 
}; 

class RookDecoration : public SquareDecorator
{
  public: 

    RookDecoration(Xwindow* window, int x0, int y0, int color); 

    ~RookDecoration(); 

  void build() override; 
}; 

class BishopDecoration :  public SquareDecorator
{
  public: 

    BishopDecoration(Xwindow* window, int x0, int y0, int color); 

    ~BishopDecoration(); 

    void build() override; 
}; 

class PawnDecoration : public SquareDecorator
{
  public: 

    PawnDecoration(Xwindow* window, int x0, int y0, int color); 

    ~PawnDecoration(); 

    void build() override; 
}; 

#endif
