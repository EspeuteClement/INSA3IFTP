#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
using namespace std;

const int NUMBER_OF_DAYS = 7;
const int NUMBER_OF_HOURS = 24;
const int NUMBER_OF_MINUTES = 60;
const int NUMBER_OF_STATES = 4;
const int V = 0;
const int J = 1;
const int R = 2;
const int N = 3;

/** Stores event integer counters for each of the possible traffic states
* ('V', 'J', 'R', 'N').
*/
struct Stats
{
  int counters[NUMBER_OF_STATES];

  /** Default constructor sets all array elements to zero.
  */
  Stats ()
  {
    for (int i = 0; i < NUMBER_OF_STATES; i++)
    {
      counters[i] = 0;
    }
  };

  /** Overloads the += operator in order to be able to add two Stats structs
  * by adding each array element separately.
  * @param stats is the right-side expression of the struct to be added.
  * @return the reference to the current Stats instance.
  */
  Stats& operator+=(const Stats& stats)
  {
    for (int i = 0; i < NUMBER_OF_STATES; i++)
    {
      counters[i] += stats.counters[i];
    }
    return *this;
  };

  /** Adds the statistics together
  * @return a double type sum of the array elements ('V', 'J', 'R', 'N')
  */
  double Sum ()
  {
    double total = 0;
    for (int i = 0; i < NUMBER_OF_STATES; i++)
    {
      total += counters[i];
    }
    return total;
  }
};

/** Stores statistics for each of the possible traffic states
* ('V', 'J', 'R', 'N').
*/
struct StatsRel {
  double counterStats[NUMBER_OF_STATES];

  /** Default constructor converts all the array elements of the passed in Stats
  * struct into statistics relative to the sum of all the counters.
  */
  StatsRel (Stats *stats) {
    double total = stats->Sum();
    for (int i = 0; i < NUMBER_OF_STATES; i++)
    {
      counterStats[i] = 0;
      if (total != 0)
      {
        counterStats[i] = stats->counters[i] / total;
      }
    }
  };

  /** Displays the array elements of the StatsRel struct one per line, rounded
  * into percentages.
  */
  void PrintStatsRel ()
  {
    cout << "V " << (int)(counterStats[V]*100) << "%\n";
    cout << "J " << (int)(counterStats[J]*100) << "%\n";
    cout << "R " << (int)(counterStats[R]*100) << "%\n";
    cout << "N " << (int)(counterStats[N]*100) << "%\n";
  }
};

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
    *  array element ('V', 'J', 'R', 'N').
    */
    void PrintSensorStatsRel ();

    /** Computes and returns the probable duration of the journey through the
    * road segment associated with the sensor. Each probable state is associated
    * with a duration : (v->1, j->2, r->4, n->10). If no data is available, all
    * the stats are equal to zero, therefore affecting 1 minute ('V' case).
    * @param d7 is the day of the week, ranging from 1 to 7 included.
    * @param h is the hour, ranging from 0 to 23.
    * @param m is the minute, ranging from 0 to 59.
    * @return the duration.
    */
    int GetDuration(int d7, int h, int m);

  private :
    /** Tri-dimensional index of Stats event counters. Dimensions are in order :
    * Day Of The Week (d7), Hour, Minute.
    */
    Stats ***index;
    /** Primary key that identifies the Sensor.*/
    long ID;
};
#endif //SENSOR_H
