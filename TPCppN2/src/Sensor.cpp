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
      for (int k = 0; k < NUMBER_OF_MINUTES; k++)
      {
        index[i][j][k].v = 0;
        index[i][j][k].j = 0;
        index[i][j][k].r = 0;
        index[i][j][k].n = 0;
      }
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

StatsRel* Sensor::GetStatsByMin (int d7, int h, int m)
{
  double total = index[d7 - 1][h][m].Sum();
  StatsRel *stats = new StatsRel(index[d7 - 1][h][m].v/total, index[d7 - 1][h][m].j/total,
    index[d7 - 1][h][m].r/total, index[d7 - 1][h][m].n/total);
  return stats;
}

StatsRel* Sensor::GetStatsByHour (int d7, int h)
{
  double total = 0;
  StatsRel *stats = new StatsRel();
  for (int i = 0; i < NUMBER_OF_MINUTES; i++)
  {
    if (index[d7 - 1][h][i].Sum() != 0)
    {
      *stats += index[d7 - 1][h][i];
      total += index[d7 - 1][h][i].Sum();
    }
  }
  if (total != 0)
  {
    *stats /= total;
  }
  return stats;
}

StatsRel* Sensor::GetStatsByDay (int d7)
{
  double total = 0;
  StatsRel *stats = new StatsRel();
  for (int i = 0; i < NUMBER_OF_HOURS; i++)
  {
    for (int j = 0; j < NUMBER_OF_MINUTES; j++)
    {
      if (index[d7 - 1][i][j].Sum() != 0)
      {
        *stats += index[d7 - 1][i][j];
        total += index[d7 - 1][i][j].Sum();
      }
    }
  }
  if (total != 0)
  {
    *stats /= total;
  }
  return stats;
}

StatsRel* Sensor::GetStatsBySensor ()
{
  double total = 0;
  StatsRel *stats = new StatsRel();
  for (int i = 0; i < NUMBER_OF_DAYS; i++) {
    for (int j = 0; j < NUMBER_OF_HOURS; j++)
    {
      for (int k = 0; k < NUMBER_OF_MINUTES; k++)
      {
        if (index[i][j][k].Sum() != 0)
        {
          *stats += index[i][j][k];
          total += index[i][j][k].Sum();
        }
      }
    }
  }
  if (total != 0)
  {
    *stats /= total;
  }
  return stats;
}
