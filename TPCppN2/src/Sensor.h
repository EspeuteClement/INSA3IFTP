#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
  public :
    Sensor(uint32_t aID);

    inline uint32_t GetID(){return ID;};

  private :
    Event *index[7][24];
    uint32_t ID;
    uint32_t uptime;
}
#endif //SENSOR_H
