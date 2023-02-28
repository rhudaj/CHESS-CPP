#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "observer.h"

class Square; 
class Pos; 

class Subject 
{
  private:
  
    std::vector<Observer*> observers;

  public:

    void attach(Observer *o);

    void detach(Observer *o);

    void notifyObservers();

    virtual Square getState(Pos pos) const = 0; 

    virtual ~Subject() = default; 
};

#endif
