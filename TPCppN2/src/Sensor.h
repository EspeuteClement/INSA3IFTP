#ifndef SENSOR_H
#define SENSOR_H

#include "EventList.h"
#include <iostream>
using namespace std;

const int NUMBER_OF_DAYS = 7;
const int NUMBER_OF_HOURS = 24;
const int NUMBER_OF_MINUTES = 60;

struct Stats
{
  int v, j, r, n;
  double Sum ()
  {
    return v + j + r + n;
  }
};

struct StatsRel {
  double v, j, r, n;
  StatsRel ():v(0), j(0), r(0), n(0) {};
  StatsRel (double aV, double aJ, double aR, double aN):v(aV), j(aJ), r(aR), n(aN) {};
  StatsRel& operator+=(const Stats& stats)
  {
    v += stats.v;
    j += stats.j;
    r += stats.r;
    n += stats.n;
    return *this;
  };

  StatsRel& operator/=(const double diviser)
  {
    v /= diviser;
    j /= diviser;
    r /= diviser;
    n /= diviser;
    return *this;
  };

  double Sum ()
  {
    return v + j + r + n;
  }
};

class Sensor
{
  public :
    Sensor(long aID);

    ~Sensor();

    void AddEvent (int d7, int h, int m, char state);

    inline long GetID()
    {
      return ID;
    };

    StatsRel* GetStatsByMin (int d7, int h, int m);

    StatsRel* GetStatsByHour (int d7, int h);

    StatsRel* GetStatsByDay (int d7);

    StatsRel* GetStatsBySensor ();

  private :
    Stats ***index;
    long ID;
};
#endif //SENSOR_H
