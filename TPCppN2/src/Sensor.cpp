#include "Sensor.h"

Sensor::Sensor(int aID):ID(aID}, uptime(0){}

Sensor::~Sensor () {
  for (uint8_t i = 0; i < NUMBER_OF_DAYS; i++) {
    for (uint8_t j = 0; i < NUMBER_OF_HOURS; j++) {
      delete index[i][j];
    }
  }
}
