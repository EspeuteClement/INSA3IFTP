#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
  public :
    Sensor(int aID);

    inline int GetID(){return ID;};


  private :
    Event *index;
    int ID;
    int uptime;
}
#endif //SENSOR_H
