#ifndef EVENT_H
#define EVENT_H

class Event {
  public :
    Event(int aMinute, char aState);

    ~Event();

    void SetNext(Event *aNext);

  private :
    int minute;
    char state;
    Event *next;
};
#endif //EVENT_H
