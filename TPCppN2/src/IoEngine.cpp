#include "IoEngine.h"
#include <string>
#include <iostream>
#include "Sensor.h"
#include <cstdio>
#include <cstring>

using namespace std;

IoEngine::IoEngine(BinaryTree *tree):theTree(tree)
{

}

bool IoEngine::ReadInput()
{
	char command[10];
	scanf("%s",command);
	
	if (strcmp(command,"ADD") == 0)
	{
		HandleADD();
	}
	/*else if (command.compare("STATS_C") == 0)
	{
		//cout << "COUCOU";
		HandleSTATS_C();
	}*/
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
		//theSensor->GetStatsRelBySensor();
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

	// TODO : Handle poulet au fromage
}