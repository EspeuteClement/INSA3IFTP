#ifndef EVENTLIST_H
#define EVENTLIST_H

class EventList {
  public :
    EventList();

    InsertEvent(uint8_t aMinute, State aState){
      Event *current = 0;
      while ()
      last = new Event(aMinute, aState);
    };

  private :
    Event *first;
    Event *last;
}
#endif //EVENTLIST_H
