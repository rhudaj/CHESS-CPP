#ifndef TEXT_OB
#define TEXT_OB

#include "observer.h"
#include "board.h"
#include <iostream>

class TextOb : public Observer  //defines a type of observer (text output)
{
    private: 

        Board* board;                   //does not own the subject. Only has a reference to it. 

        std::ostream& out = std::cout;  //defines output to go to console output

    public: 

        TextOb(Board* board);

        ~TextOb(); 

        void notify() override;         //called when the subject calls notifyAllObservers()
};

#endif
