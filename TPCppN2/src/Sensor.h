#ifndef SENSOR_H
#define SENSOR_H

using namespace std;

const int NUMBER_OF_DAYS = 7;
const int NUMBER_OF_HOURS = 24;
const int NUMBER_OF_MINUTES = 60;

struct Stats
{
  int v, j, r, n;
  Stats ():v(0), j(0), r(0), n(0) {};
  Stats& operator+=(const Stats& stats)
  {
    v += stats.v;
    j += stats.j;
    r += stats.r;
    n += stats.n;
    return *this;
  };
};

struct StatsRel {
  double v, j, r, n;
  StatsRel ():v(0), j(0), r(0), n(0) {};
  StatsRel& operator=(const Stats& stats)
  {
    v = stats.v;
    j = stats.j;
    r = stats.r;
    n = stats.n;
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

    Stats* GetStatsByMin (int d7, int h, int m);

    void GetStatsByHour (int d7, int h, Stats *stats);

    void GetStatsByDay (int d7, Stats *stats);

    void GetStatsBySensor (Stats *stats);

    void GetStatsRelBySensor (StatsRel *stats);

  private :
    Stats ***index;
    long ID;
};
#endif //SENSOR_H
