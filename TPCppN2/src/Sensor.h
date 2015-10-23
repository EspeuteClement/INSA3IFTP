#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
  public :
    const uint8_t NUMBER_OF_DAYS = 7;
    const uint8_t NUMBER_OF_HOURS = 24;

    Sensor(uint32_t aID);

    ~Sensor();

    inline uint32_t GetID(){return ID;};

  private :
    Event *index[NUMBER_OF_DAYS][NUMBER_OF_HOURS];
    uint32_t ID;
    uint32_t uptime;
};
#endif //SENSOR_H
