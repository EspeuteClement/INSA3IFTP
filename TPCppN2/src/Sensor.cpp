#include "Sensor.h"

Sensor::Sensor(long aID):ID(aID)
{
  index = new Stats ** [ NUMBER_OF_DAYS ];
  for (int i = 0; i < NUMBER_OF_DAYS; i++)
  {
    index[i] = new Stats * [NUMBER_OF_HOURS];
  }
  for (int i = 0; i < NUMBER_OF_DAYS; i++)
  {
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
      delete index[i][j];
    }
  }
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

Stats* Sensor::GetStatsByHour (int d7, int h)
{
  Stats *stats = new Stats();
  for (int i = 0; i < NUMBER_OF_MINUTES; i++)
  {
    *stats += *GetStatsByMin(d7, h, i);
  }
  return stats;
}

Stats* Sensor::GetStatsByDay (int d7)
{
  Stats *stats = new Stats();
  for (int i = 0; i < NUMBER_OF_HOURS; i++)
  {
    *stats += *GetStatsByHour(d7, i);
  }
  return stats;
}

StatsRel* Sensor::GetStatsBySensor ()
{
  StatsRel *stats = new StatsRel();
  for (int i = 1; i <= NUMBER_OF_DAYS; i++) {
    *stats += *GetStatsByDay(i);
  }
  double total = stats->Sum();
  if (total != 0)
  {
    *stats /= total;
  }
  return stats;
}
