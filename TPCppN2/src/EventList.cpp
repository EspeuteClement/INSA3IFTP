#include "EventList.h"

EventList::EventList)(){
  first = NULL;
}

EventList::~EventList(){
  delete first;
}

EventList::InsertEvent(uint8_t aMinute, State aState){
  Event *newEvent = new Event(aMinute, aState);
  if (first == NULL) {
    first = newEvent;
  }
  else {
    newEvent.next = first;
    first = newEvent;
}
