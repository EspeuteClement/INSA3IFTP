#include "ListElement.h"
#include <iostream>
using namespace std;

ListElement::ListElement (int aMinute, char aState):minute(aMinute), state(aState), next(0) {
}

ListElement::~ListElement () {
  if (next != 0) {
    delete next;
  }
}

void ListElement::SetNext (ListElement *aNext) {
  next = aNext;
}
