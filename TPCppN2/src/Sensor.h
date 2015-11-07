#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
using namespace std;

/** Stores event integer counters for each of the possible traffic states
* (v, j, r, n).
*/
struct Stats
{
  int v, j, r, n;

  /** Default constructor sets all attributes to zero.
  */
  Stats ():v(0), j(0), r(0), n(0) {};

  /** Overloads the += operator in order to be able to add two Stats structs
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

  /** Adds the statistics together
  * @return a double type sum of the attributes (v, j, r, n)
  */
  double Sum ()
  {
    return v + j + r + n;
  }
};

/** Stores statistics for each of the possible traffic states
* (v, j, r, n).
*/
struct StatsRel {
  double v, j, r, n;

  /** Default constructor sets all attributes to zero.
  */
  StatsRel ():v(0), j(0), r(0), n(0) {};

  /** Second constructor converts all the attributes of the passed in Stats
  * struct into statistics relative to the sum of all the counters.
  */
  StatsRel (Stats *stats) {
    double total = stats->Sum();
    v = stats->v / total;
    j = stats->j / total;
    r = stats->r / total;
    n = stats->n / total;
  };

  /** Displays the attributes of the StatsRel struct one per line, rounded into
  * percentages.
  */
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

/** Stores the ID of a given sensor and a pointer to a tri-dimensional
* index of Stats event counters thus allowing easy computation of statistics on
* a per minute, hour, day and sensor basis.
*/
class Sensor
{
  public :

    /** Default constructor sets ID to the one given and dynamically allocates
    * the memory required for the tri-dimensional index.
    */
    Sensor(long aID);

    /** Default destructor deletes the tri-dimensional index.
    */
    ~Sensor();

    /** Increments the suitable event state counter for a given day of week,
    * hour and minute by one.
    * @param d7 is the day of the week, ranging from 1 to 7 included.
    * @param h is the hour, ranging from 0 to 23.
    * @param m is the minute, ranging from 0 to 59.
    * @param state is the character representing the state of traffic at the
    * given time to be incremented.
    */
    void AddEvent (int d7, int h, int m, char state);

    /** Getter for the sensor ID.
    * @return the long int value of the ID.
    */
    inline long GetID()
    {
      return ID;
    };

    /** Getter for the Stats of a given time.
    * @param d7 is the day of the week, ranging from 1 to 7 included.
    * @param h is the hour, ranging from 0 to 23.
    * @param m is the minute, ranging from 0 to 59.
    * @return the pointer to the Stats struct of the index for the given time.
    */
    Stats* GetStatsByMin (int d7, int h, int m);

    /** Adds all the Stats structs comprised in the given day and hour to the
    * Stats struct which pointer is passed in.
    * @param d7 is the day of the week, ranging from 1 to 7 included.
    * @param h is the hour, ranging from 0 to 23.
    * @param[in, out] stats contains the sum of the counters of all the minute
    * included within a hour.
    */
    void AddStatsByHour (int d7, int h, Stats *stats);

    /** Adds all the Stats structs comprised in the given day to the Stats
    * struct which pointer is passed in.
    * @param d7 is the day of the week, ranging from 1 to 7 included.
    * @param[in, out] stats contains the sum of the counters of all the hours
    * included within a day.
    */
    void AddStatsByDay (int d7, Stats *stats);

    /** Adds all the Stats structs of the current Sensor to the Stats struct
    * which pointer is passed in.
    * @param[in, out] stats contains the sum of the counters of all the Stats
    * structs included in the Sensor index.
    */
    void AddStatsBySensor (Stats *stats);

    /** Computes and displays the statistics of the current Sensor for every
    *  attribute (v, j, r, n).
    */
    void PrintSensorStatsRel ();

  private :
    /** Tri-dimensional index of Stats event counters. Dimensions are in order :
    * Day Of The Week (d7), Hour, Minute.
    */
    Stats ***index;
    /** Primary key that identifies the Sensor.*/
    long ID;
};
#endif //SENSOR_H
