#ifndef EVENTLIST_H
#define EVENTLIST_H

#include "Event.h"

class EventList {
  public :
    EventList();

    ~EventList();

    void InsertEvent(int aMinute, char aState);

  private :
    Event *first;
};
#endif //EVENTLIST_H
