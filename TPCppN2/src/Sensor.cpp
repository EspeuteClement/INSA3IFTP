#include "Sensor.h"

Sensor::Sensor(long aID):ID(aID)
{
  index = new Stats ** [ NUMBER_OF_DAYS ];
  for (int i = 0; i < NUMBER_OF_DAYS; i++)
  {
    index[i] = new Stats * [NUMBER_OF_HOURS];
    for (int j = 0; j < NUMBER_OF_HOURS; j++)
    {
      index[i][j] = new Stats[NUMBER_OF_MINUTES];
    }
  }
}

Sensor::~Sensor ()
{
  for (int i = 0; i < NUMBER_OF_DAYS; i++)
  {
    for (int j = 0; j < NUMBER_OF_HOURS; j++)
    {
      delete[] index[i][j];
    }
    delete[] index[i];
  }
  delete[] index;
}

void Sensor::AddEvent(int d7, int h, int m, char state)
{
  switch (state)
  {
    case 'V':
      index[d7 - 1][h][m].v++;
      break;
    case 'J':
      index[d7 - 1][h][m].j++;
      break;
    case 'R':
      index[d7 - 1][h][m].r++;
      break;
    case 'N':
      index[d7 - 1][h][m].n++;
      break;
  }
}

Stats* Sensor::GetStatsByMin (int d7, int h, int m)
{
  return &index[d7-1][h][m];
}

void Sensor::AddStatsByHour (int d7, int h, Stats *stats)
{
  for (int i = 0; i < NUMBER_OF_MINUTES; i++)
  {
    *stats += *GetStatsByMin(d7, h, i);
  }
}

void Sensor::AddStatsByDay (int d7, Stats *stats)
{
  for (int i = 0; i < NUMBER_OF_HOURS; i++)
  {
    AddStatsByHour(d7, i, stats);
  }
}

void Sensor::AddStatsBySensor (Stats *stats)
{
  for (int i = 1; i <= NUMBER_OF_DAYS; i++) {
    AddStatsByDay(i, stats);
  }
}

void Sensor::PrintSensorStatsRel ()
{
  // Stores sensor data in a temporary Stats struct instance.
  Stats *buffer = new Stats();
  AddStatsBySensor(buffer);
  // Converts into statistics by using a temporary StatsRel struct instance.
  StatsRel *sensorStatsRel = new StatsRel(buffer);
  sensorStatsRel->PrintStatsRel();
  // Never forget to dispose of these temporary objects !
  delete buffer;
  delete sensorStatsRel;
}
