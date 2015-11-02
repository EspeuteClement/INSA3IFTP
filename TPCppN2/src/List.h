#ifndef LIST_H
#define LIST_H

#include "ListElement.h"

class List {
  public :
    List();

    ~List();

    void InsertElement(int aMinute, char aState);

    ListElement* Find ();

  private :
    ListElement *first;
};
#endif //LIST_H
