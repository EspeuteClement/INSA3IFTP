#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include "IoEngine.h"
#include "Sensor.h"

using namespace std;

IoEngine::IoEngine(BinaryTree *tree):theTree(tree){}

bool IoEngine::ReadInput()
{
	char command[10];
	scanf("%s",command);
	
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
		HandleSTATS_C();
	}
	else if (strcmp(command,"EXIT") == 0)
	{
		return false;
	}
	return true;
}

void IoEngine::HandleADD()
{
	// The values are :
	// ADD <id> <yyyy(useless)> <mm(useless)> <dd(useless)>
	// <h> <m> <d7> <traffic>

	// Used to gather the useless values

	int id;
	int h;
	int m;
	int d7;
	unsigned char traffic[10];

	// Scanf is used here instead of cin because
	// it's waaaay faster when you have to deal with
	// 20 000 000 entries.
	scanf("%i %*i %*i %*i %i %i %i %s",&id , &h , &m , &d7,traffic);
	theTree->Insert(id,d7,h,m,traffic[0]);
}

void IoEngine::HandleSTATS_C()
{
	int id;

	cin >> id;

	Sensor *theSensor = theTree->Search(id);
	if (theSensor != NULL)
	{
		cout << id << " found !" << "\n";
		theSensor->PrintSensorStatsRel();
	}
	else
	{
		cout << id << " not found !" << "\n";
	}
}

void IoEngine::HandleJAM_DH()
{
	int d7;

	cin >> d7;

	Stats **d7StatsTab = new Stats*[NUMBER_OF_HOURS];
	for (int i = 0; i < NUMBER_OF_HOURS; ++i)
	{
		d7StatsTab[i] = new Stats();
	}
	// Ready the iteration
	theTree->InitIterate();
	Node *iterator = NULL;
	while ( (iterator = theTree->Iterate() ) != NULL )
	{
		for (int i = 0; i < NUMBER_OF_HOURS; i++)
		{
			iterator->GetSensor()->AddStatsByHour(d7, i, d7StatsTab[i]); // may need a * or &
		}
	}
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

	/*Stats *d7Stats = new Stats();
	// Ready the iteration
	theTree->InitIterate();
	Node *iterator = NULL;
	while ( (iterator = theTree->Iterate() ) != NULL )
	{
		iterator->GetSensor()->AddStatsByDay(d7, d7Stats);
	}
	StatsRel *d7StatsRel = new StatsRel(d7Stats);
	d7StatsRel->PrintStatsRel();
	delete d7Stats;
	delete d7StatsRel;*/
	
}

void IoEngine::HandleOPT()
{
	// TODO : Fill the variables with the data
	/*
	int d7, hStart, hEnd, segCount;
	int segTab[segCount];

	//... Read and affect data to atributes

	//Caches the sensors to avoid redundant parsing of the binary tree
	Stats *sensorTab = new Stats[segCount];
	for (int i = 0; i < segCount; i++)
	{
		sensorTab[i] += theTree->Search(segTab[i]);
	}

	//Starting from every minute within [hStart, hEnd], we compute the duration of
	//the journey and only keep the shortest that also complies with hEnd.
	int minDuration = (hEnd-hStart)*60;
	int minMinOfStart = 0;
	int minHourOfStart = hStart;

	int minOfStart = 0;
	int hourOfStart = hStart;

	int duration = 0;
	int totalDuration = 0;
	int currentMin = 0;
	int currentHour = hourOfStart;

	while (int hourOfStart < hEnd)
	{
		// Simulates the journey for the given startTime
		for (int segNum = 0; segNum < segCount; segNum++)
		{
			duration = sensorTab[segNum]->GetDuration(d7, h, m);
			totalDuration += duration;

			// Incrementation of the current time by duration minutes
			if (currentMin + duration < NUMBER_OF_MINUTES)
			{
				currentMin += duration;
			}
			else
			{
				currentMin += (duration - NUMBER_OF_MINUTES + 1);
				currentHour++;
			}
		}

		//Only keep the minimum duration of all and the start time associated
		if (totalDuration < minDuration && currentHour < hEnd) {
			minDuration = totalDuration;
			minMinOfStart = minOfStart;
			minHourOfStart = hourOfStart;
		}

		// Reinitialize the journey
		totalDuration = 0;
		currentMin = 0;
		currentHour = 0;

		// Incrementation of the time of start by one minute
		if (minOfStart < NUMBER_OF_MINUTES - 1)
		{
			minOfStart++;
		}
		else
		{
			minOfStart = 0;
			hourOfStart++;
		}
	}

	delete[] segTab;

	// Display the optimal time of departure and the journey's duration
	cout << d7 << " " << minHourOfStart << " " << minMinOfStart << " " << minDuration;
	*/
}
