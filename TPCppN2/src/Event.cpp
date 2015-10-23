#include "Event.h"

Event::Event (uint8_t aMinute, State aState):minute(aMinute), state(aState), next(NULL) {}

Event::~Event () {
  if (next != NULL) {
    delete next;
  }
}
