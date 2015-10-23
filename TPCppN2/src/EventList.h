#ifndef EVENTLIST_H
#define EVENTLIST_H

class EventList {
  public :
    EventList();

    ~EventList();

    InsertEvent(uint8_t aMinute, State aState);

  private :
    Event *first;
};
#endif //EVENTLIST_H
