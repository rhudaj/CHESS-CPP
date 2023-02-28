#ifndef WINDOW_OB
#define WINDOW_OB

#include "observer.h"
#include "board.h"
#include "window.h"
#include <vector>
#include "position.h"

#include "boardTracker.h"
#include "squaredecorator.h"
#include <vector>

class WindowOb : public Observer 
{
  private:

    Board* board;

    PositionsToUpdate& positionsToUpdate; 

    Xwindow* window;

    const int squareWidth = 40, squareHeight = 40;

    const int boardTopMargin = 20, boardLeftMargin = 40;

    std::vector <SquareDecorator*> decorators;

  public: 

    void squareOutput(Pos pos); 

    void rowStringOutput(); 

    void colStringOutput(); 

    WindowOb(Board* board, PositionsToUpdate& positionsToUpdate);

    ~WindowOb(); 

    void notify() override;                 //called upon notifyAllObservers()
};

#endif
