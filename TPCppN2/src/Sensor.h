#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
using namespace std;

/** Stats stores event integer counters for each of the possible traffic states
* (v, j, r, n).
*/
struct Stats
{
  int v, j, r, n;
  Stats ():v(0), j(0), r(0), n(0) {};

  /** Overload the += operator in order to be able to add two Stats structs
  * by adding each attribute separately.
  * @param stats is the right-side expression of the struct to be added.
  * @return the reference to the current Stats instance.
  */
  Stats& operator+=(const Stats& stats)
  {
    v += stats.v;
    j += stats.j;
    r += stats.r;
    n += stats.n;
    return *this;
  };

  double Sum ()
  {
    return v + j + r + n;
  }
};

/** StatsRel stores statistics for each of the possible traffic states
* (v, j, r, n).
*/
struct StatsRel {
  double v, j, r, n;
  StatsRel ():v(0), j(0), r(0), n(0) {};
  StatsRel (Stats *stats) {
    double total = stats->Sum();
    v = stats->v / total;
    j = stats->j / total;
    r = stats->r / total;
    n = stats->n / total;
  };

  void PrintStatsRel ()
  {
    cout << "V " << (int)(v*100) << "%\n";
    cout << "J " << (int)(j*100) << "%\n";
    cout << "R " << (int)(r*100) << "%\n";
    cout << "N " << (int)(n*100) << "%\n";
  }
};

const int NUMBER_OF_DAYS = 7;
const int NUMBER_OF_HOURS = 24;
const int NUMBER_OF_MINUTES = 60;

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

    /**
    * @param[in, out] stats contains the sum of the counters of all the minute
    * included within a hour.
    */
    void AddStatsByHour (int d7, int h, Stats *stats);

    void AddStatsByDay (int d7, Stats *stats);

    void AddStatsBySensor (Stats *stats);

    void PrintSensorStatsRel ();

  private :
    Stats ***index;
    long ID;
};
#endif //SENSOR_H
