#ifndef SENSOR_H
#define SENSOR_H

#include "EventList.h"

const int NUMBER_OF_DAYS = 7;
const int NUMBER_OF_HOURS = 24;

class Sensor {
  public :

    Sensor(long aID);

    ~Sensor();

    void AddEvent (int d7, int h, int aMinute, char aState);

    inline long GetID(){return ID;};

  private :
    EventList **index;
    long ID;
    long uptime;
};
#endif //SENSOR_H
