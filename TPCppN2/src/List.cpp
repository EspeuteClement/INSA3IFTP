#include "List.h"

List::List(){
  first = 0;
}

List::~List(){
  delete first;
}

void List::InsertElement(int aMinute, char aState){
  ListElement *newElement = new ListElement(aMinute, aState);
  if (first == 0) {
    first = newElement;
  }
  else {
    newElement->SetNext(first);
    first = newElement;
  }
}
