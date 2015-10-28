#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
  public :
    Sensor(long aID);

    inline long GetID(){return ID;};

  private :
    //Event *index[7][24];
    long ID;
    long uptime;
};
#endif //SENSOR_H
