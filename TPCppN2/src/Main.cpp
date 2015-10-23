#include <iostream>
#include "Sensor.h"

using namespace std;

int main() {
  Sensor *sensor1 = new Sensor(19783);
  sensor1->AddEvent(1, 12, 32, 'V');

  return 0;
}
