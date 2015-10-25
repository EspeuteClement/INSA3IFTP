#ifndef LISTEELEMENT_H
#define LISTEELEMENT_H

class ListElement {
  public :
    ListElement(int aMinute, char aState);

    ~ListElement();

    void SetNext(ListElement *aNext);

  private :
    int minute;
    char state;
    ListElement *next;
};
#endif //LISTEELEMENT_H
