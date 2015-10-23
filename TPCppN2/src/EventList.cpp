#include "EventList.h"

EventList::EventList(){
  first = 0;
}

EventList::~EventList(){
  delete first;
}

void EventList::InsertEvent(int aMinute, char aState){
  Event *newEvent = new Event(aMinute, aState);
  if (first == 0) {
    first = newEvent;
  }
  else {
    newEvent->SetNext(first);
    first = newEvent;
  }
}
