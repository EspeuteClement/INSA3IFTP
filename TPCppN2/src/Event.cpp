#include "Event.h"

Event::Event (unsigned char aMinute, State aState):minute(aMinute), state(aState) {
  next = 0;
}
