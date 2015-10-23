#include "Sensor.h"

Sensor::Sensor(long aID):ID(aID), uptime(0){
  index = new EventList[NUMBER_OF_DAYS][NUMBER_OF_HOURS];
}

Sensor::~Sensor () {
  for (int i = 0; i < NUMBER_OF_DAYS; i++) {
    for (int j = 0; i < NUMBER_OF_HOURS; j++) {
      delete index[i][j];
    }
  }
}

void Sensor::AddEvent(int d7, int h, int aMinute, char aState) {
  index[d7 - 1][h]->InsertEvent(aMinute, aState);
  uptime++;
}
