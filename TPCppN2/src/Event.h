#ifndef EVENT_H
#define EVENT_H

enum State {V, J, R, N};

class Event {
  public :
    Event(uint8_t aMinute, State aState);

    ~Event();

  private :
    uint8_t minute;
    State state;
    Event *next;
};
#endif //EVENT_H
