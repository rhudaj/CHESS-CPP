#include "subject.h"

void Subject::attach(Observer* o)    
{
  observers.emplace_back(o);      //add pointer to observer to vector
}

void Subject::detach(Observer *o) 
{
  for (auto it = observers.begin(); it != observers.end(); ++it) 
  {
    if (*it == o) 
    {
      observers.erase(it);      //remove pointer to observer from vector
      break;
    }
  }
}

void Subject::notifyObservers() 
{
  for (auto ob : observers) ob->notify();   //for each observer attached to the suject, call their notify() function 
}
