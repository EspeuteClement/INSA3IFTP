#include "Event.h"
#include <iostream>
using namespace std;

Event::Event (int aMinute, char aState):minute(aMinute), state(aState), next(0) {
  cout << "minute = " << minute << " ; state = " << state << "\n";
}

Event::~Event () {
  if (next != 0) {
    delete next;
  }
}

void Event::SetNext (Event *aNext) {
  next = aNext;
}
