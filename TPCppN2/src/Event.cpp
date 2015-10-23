#include "Event.h"

Event::Event (int aMinute, char aState):minute(aMinute), state(aState), next(0) {}

Event::~Event () {
  if (next != 0) {
    delete next;
  }
}

void Event::SetNext (Event *aNext) {
  next = aNext;
}
