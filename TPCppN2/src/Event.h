#ifndef EVENT_H
#define EVENT_H

enum State {V, J, R, N};

class Event {
  public :
    Event(unsigned char aMinute, State aState);

  private :
    unsigned char minute;
    State state;
    Event *next;
};
#endif //EVENT_H
