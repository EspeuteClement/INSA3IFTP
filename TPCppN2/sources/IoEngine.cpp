#include <iostream>

#include <cstdio>
#include <cstring>

#include "IoEngine.h"
#include "Sensor.h"

using namespace std;

//------------------------------------------------------------------------------
// Private functions and methods
//------------------------------------------------------------------------------
bool IoEngine::checkHour(int hour)
{
	if (hour < 0 || hour > NUMBER_OF_HOURS - 1) {
		cout << "The hour must be an integer ranging from 0 to 23 included.\n";
		return true;
	}
	return false;
}

bool IoEngine::checkHourTimeFrame(int hour)
{
	if (hour < 0 || hour > NUMBER_OF_HOURS) {
		cout << "The hour of start an end must be integers ranging from 0 to 24 included.\n";
		return true;
	}
	return false;
}

bool IoEngine::checkMinute(int minute)
{
	if (minute < 0 || minute > NUMBER_OF_MINUTES - 1) {
		cout << "The minute must be an integer ranging from 0 to 59 included.\n";
		return true;
	}
	return false;
}

bool IoEngine::checkD7(int day)
{
	if (day < 1 || day > NUMBER_OF_DAYS) {
		cout << "The day of week must be an integer ranging from 1 to 7 included.\n";
		return true;
	}
	return false;
}

bool IoEngine::checkTraffic(char traffic)
{
	if (!(traffic == 'V' || traffic == 'J' || traffic == 'R' || traffic == 'N')) {
		cout << "Traffic state must be either 'V', 'J', 'R' or 'N'.\n";
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
// Public functions and methods
//------------------------------------------------------------------------------
bool IoEngine::ReadInput()
{
	char command[10];

	// Read the command
	scanf("%s",command);

	// Try to match the command with what we know
	// and then execute the correct method.
	if (strcmp(command,"ADD") == 0)
	{
		HandleADD();
	}
	else if (strcmp(command, "STATS_C") == 0)
	{
		HandleSTATS_C();
	}
	else if (strcmp(command, "JAM_DH") == 0)
	{
		HandleJAM_DH();
	}
	else if (strcmp(command, "STATS_D7") == 0)
	{
		HandleSTATS_D7();
	}
	else if (strcmp(command, "OPT") == 0)
	{
		HandleOPT();
	}
	else if (strcmp(command,"EXIT") == 0)
	{
		return false;
	}
	return true;
}

void IoEngine::HandleADD()
{
	int id;
	int h;
	int m;
	int d7;
	unsigned char traffic[2];

	// * allows us to ignore the useless data.
	scanf("%i %*i %*i %*i %i %i %i %s",&id , &h , &m , &d7,traffic);

	if (checkHour(h)) return;
	if (checkMinute(m)) return;
	if (checkD7(d7)) return;
	if (checkTraffic(traffic[0])) return;

	theTree->Insert(id,d7,h,m,traffic[0]);
}

void IoEngine::HandleSTATS_C()
{
	int id;

	cin >> id;

	// Checks if the desired sensor even exists before displaying its data.
	Sensor *theSensor = theTree->Search(id);
	if (theSensor != NULL)
	{
		theSensor->PrintSensorStatsRel();
	}
}

void IoEngine::HandleJAM_DH()
{
	int d7;

	cin >> d7;
	if (checkD7(d7)) return;

	// Caches the hourly statistics data of all sensor in order to avoid to
	// iterate 24 times through the tree.
	Stats **d7StatsTab = new Stats*[NUMBER_OF_HOURS];
	for (int i = 0; i < NUMBER_OF_HOURS; ++i)
	{
		d7StatsTab[i] = new Stats();
	}

	// Ready the iteration.
	theTree->InitIterate();
	Node *iterator = NULL;

	// Iterates through the entire tree to collect the hourly statistics.
	while ( (iterator = theTree->Iterate() ) != NULL )
	{
		for (int i = 0; i < NUMBER_OF_HOURS; i++)
		{
			iterator->GetSensor()->AddStatsByHour(d7, i, d7StatsTab[i]);
		}
	}

	// Computes and displays the hourly jam relative statistics.
	for (int i = 0; i < NUMBER_OF_HOURS; i++)
	{
		long print = 0;
		long sum = d7StatsTab[i]->Sum();
		if (sum != 0)
		{
			print = (int)((d7StatsTab[i]->counters[R] +
				d7StatsTab[i]->counters[N]) * 100 / sum);
		}

		cout << d7 << " " << i << " " << print << "%\n";
		delete d7StatsTab[i];
	}
	delete[] d7StatsTab;
}

void IoEngine::HandleSTATS_D7()
{
	int d7;

	cin >> d7;
	if (checkD7(d7)) return;

	Stats *d7Stats = new Stats();

	// Ready the iteration
	theTree->InitIterate();
	Node *iterator = NULL;

	// Iterates through the entire tree to collect the daily statistics.
	while ( (iterator = theTree->Iterate() ) != NULL )
	{
		iterator->GetSensor()->AddStatsByDay(d7, d7Stats);
	}

	// Makes relative statistics out of the collected ones and displays them.
	StatsRel *d7StatsRel = new StatsRel(d7Stats);
	d7StatsRel->PrintStatsRel();
	delete d7Stats;
	delete d7StatsRel;
}

void IoEngine::HandleOPT()
{
	int d7, hStart, hEnd, segCount;

	// Fill the variables with the data.
	cin >> d7;
	cin >> hStart;
	cin >> hEnd;
	cin >> segCount;

	if (checkD7(d7)) return;
	if (checkHourTimeFrame(hStart)) return;
	if (checkHourTimeFrame(hEnd)) return;

	int *segTab = new int[segCount];

	for (int i = 0; i < segCount; i++)
	{
		cin >> segTab[i];
	}

	//Caches the sensors to avoid redundant parsing of the binary tree.
	Sensor **sensorTab = new Sensor*[segCount];

	for (int i = 0; i < segCount; i++)
	{
		sensorTab[i] = theTree->Search(segTab[i]);

		// If one of the passed in sensors doesn't exist, the function exits.
		if (sensorTab[i] == NULL)
		{
			return;
		}
	}

	//Starting from every minute within [hStart, hEnd], we compute the duration of
	//the journey and only keep the shortest.

	//
	int minDuration = (hEnd-hStart)*60;

	int minMinOfStart = 0;
	int minHourOfStart = hStart;

	// Start values for each simulation
	int minOfStart = 0;
	int hourOfStart = hStart;
	int dayOfStart = d7;

	// Values that evolve during a given simulation
	int duration = 0;
	int totalDuration = 0;
	int currentMin = minOfStart;
	int currentHour = hourOfStart;
	int currentDay = dayOfStart;

	while (hourOfStart < hEnd)
	{
		// Simulates the journey for the given startTime.
		for (int segNum = 0; segNum < segCount; segNum++)
		{
			duration = sensorTab[segNum]->GetDuration(d7, currentHour, currentMin);

			totalDuration += duration;

			// Incrementation of the current time by duration minutes.
			if (currentMin + duration < NUMBER_OF_MINUTES)
			{
				currentMin += duration;
			}
			else
			{
				if (currentHour + 1 < NUMBER_OF_HOURS)
				{
					currentMin += (duration - NUMBER_OF_MINUTES);
					currentHour++;
				}
				else
				{
					currentHour = 0;
					if (currentDay + 1 < NUMBER_OF_DAYS)
					{
						currentDay++;
					}
					else
					{
						currentDay = 0;
					}
				}
			}
		}

		//Only keep the minimum duration of all and the start time associated.
		if (totalDuration < minDuration) {
			minDuration = totalDuration;
			minMinOfStart = minOfStart;
			minHourOfStart = hourOfStart;
		}

		// Incrementation of the time of start by one minute.
		if (minOfStart < NUMBER_OF_MINUTES - 1)
		{
			minOfStart++;
		}
		else
		{
			minOfStart = 0;
			hourOfStart++;
		}

		// Reinitialize the journey for the next simulation.
		totalDuration = 0;
		currentMin = minOfStart;
		currentHour = hourOfStart;
	}

	delete[] segTab;
	delete[] sensorTab;

	// Display the optimal time of departure and the journey's duration.
	cout << d7 << " " << minHourOfStart << " " << minMinOfStart << " " <<
	minDuration << "\n";
}

//------------------------------------------------------------------------------
// Constructors or/and Destructors
//------------------------------------------------------------------------------
IoEngine::IoEngine(BinaryTree *tree):theTree(tree){}
