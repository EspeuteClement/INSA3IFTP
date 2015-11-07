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
	// <h> <m> <d7> <trafic>

	// Used to gather the useless values

	int id;
	int h;
	int m;
	int d7;
	unsigned char trafic[10];

	scanf("%i %*i %*i %*i %i %i %i %s",&id , &h , &m , &d7,trafic);
	theTree->Insert(id,d7,h,m,trafic[0]);
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

	// TODO : Handle "every sensor"
	/*
	Stats *d7StatsTab = new Stats[NUMBER_OF_HOURS];
	for (every sensor)
	{
		for (i = 0; i < NUMBER_OF_HOURS; i++)
		{
			theSensor->AddStatsByHour(d7, i, d7StatsTab[i]); // may need a * or &
		}
	}
	for (i = 0; i < NUMBER_OF_HOURS; i++)
	{
		cout << d7 << " " << i << " " << (int)((d7Stats->r + d7Stats->n) * 100 / d7Stats->Sum()) << "%\n";
	}
	delete[] d7StatsTab;
	*/
}

void IoEngine::HandleSTATS_D7()
{
	int d7;

	cin >> d7;

	// TODO : Handle "every sensor"
	/*
	Stats *d7Stats = new Stats());
	for (every sensor)
	{
		theSensor->AddStatsByDay(d7, d7Stats)
	}
	StatsRel *d7StatsRel = new StatsRel(d7Stats);
	d7StatsRel->PrintStatsRel();
	delete d7Stats;
	delete d7StatsRel;
	*/
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
	for (int i = 0; i < segCount; i++) {
		sensorTab[i] += theTree->Search(segTab[i]);
	}

	delete[] segTab;
	*/
}
