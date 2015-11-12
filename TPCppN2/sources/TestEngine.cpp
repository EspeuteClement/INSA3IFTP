#include "TestEngine.h"
#include "BinaryTree.h"
#include "Sensor.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

bool TestEngine::IterationTest_1(bool verbose)
{
	// The numbers of elements to put in the binary tree
	const int NUMBERS = 15000;
	Utils::printBold("ITERATION TEST 1", true);

	// Create the binary tree
	BinaryTree testTree = BinaryTree();

	// Create an array that will store if a node has been
	// traversed
	bool found[NUMBERS];
	for (int i = 0; i < NUMBERS; ++i)
	{
		found[i] = false;
	}

	// Populate the tree with id between 0 and NUMBERS
	for (int i = 0; i < NUMBERS; ++i)
	{
		testTree.Insert(i,0,0,0,0);
	}

	// Iterate trough the tree
	testTree.InitIterate();
	Node *iterator = NULL;
	while( (iterator = testTree.Iterate() ) != NULL)
	{
		int id = iterator->GetSensorID();
		if (verbose)
		{
			cout << id << '\n';
		}
		// If we haven't visited this node yet ...
		if (found[id] == false)
		{
			// Now we have :)
			found[id] = true;
		}
		else // We've gone trough the node twice !!!
		{
			Utils::printRed("ERROR, A NODE WAS FOUND TWICE",true);
			return false;
		}
	}

	for (int i = 0; i< NUMBERS; ++i)
	{
		if (!found[i])
		{
			Utils::printRed("ERROR, A NODE WAS NOT VISITED",true);
			return false;
		}
	}

	Utils::printGreen("TEST SUCESSFUL",true);
	return true;
}

bool TestEngine::SearchTest_1(bool verbose)
{
	// The numbers of elements to put in the binary tree
	const int NUMBERS = 15000;
	Utils::printBold("SEARCH TEST 1", true);

	// Create the binary tree
	BinaryTree testTree = BinaryTree();

	// Create an array that will store if a node has been
	// traversed
	bool found[NUMBERS];
	for (int i = 0; i < NUMBERS; ++i)
	{
		found[i] = false;
	}

	// Populate the tree with id between 0 and NUMBERS
	for (int i = 0; i < NUMBERS; ++i)
	{
		testTree.Insert(i,0,0,0,0);
	}

	// Iterate trough the tree
	for(int i = 0; i < NUMBERS; ++i)
	{
		Sensor *result = testTree.Search(i);
		int id = i;
		if (verbose)
		{
			cout << id << '\n';
		}
		// If we haven't visited this node yet ...
		if (result != NULL)
		{
			int id = result->GetID();
			if (found[id] == false)
				{
					// Now we have :)
					found[id] = true;
				}
		}
		
	}

	for (int i = 0; i< NUMBERS; ++i)
	{
		if (!found[i])
		{
			Utils::printRed("ERROR, A NODE WAS NOT FOUND",true);
			return false;
		}
	}

	Utils::printGreen("TEST SUCESSFUL",true);
	return true;
}


bool TestEngine::BalanceTest_1(bool verbose)
{
	srand(127);
	const int NUMBERS = 15000;
	Utils::printBold("BALANCE 1", true);

	// Create the binary tree
	BinaryTree testTree = BinaryTree();


	// Populate the tree with random id between 0 and NUMBERS
	for (int i = 0; i < NUMBERS; i++)
	{
		testTree.Insert(rand()%15000-7500,0,0,0,0);
	}
	//testTree.Serialize();
	// Iterate trough the tree
	testTree.InitIterate();
	Node *iterator = NULL;
	while( (iterator = testTree.Iterate() ) != NULL)
	{
		int id = iterator->GetSensorID();
		int balance = iterator->GetBalance();
		if (verbose)
		{
			cout << id << " " << balance <<'\n';
		}
		if (abs(balance) > 1)
		{
			Utils::printRed("WARNING : A NODE WITH A BALANCE OF 2 OR PLUS HAS BEEN FOUND",true);
		}
	}

	Utils::printGreen("TEST SUCESSFUL",true);
	return true;
}

bool TestEngine::SensorTest_1(bool verbose) {
	Utils::printBold("SENSOR TEST 1", true);

	Sensor *sensor1 = new Sensor(19783);

	sensor1->AddEvent(1, 12, 32, 'V');

	sensor1->AddEvent(1, 12, 32, 'J');
	sensor1->AddEvent(1, 12, 33, 'J');

	sensor1->AddEvent(1, 12, 32, 'R');
	sensor1->AddEvent(1, 13, 32, 'R');
	sensor1->AddEvent(1, 14, 32, 'R');

	sensor1->AddEvent(1, 12, 32, 'N');
	sensor1->AddEvent(2, 12, 32, 'N');
	sensor1->AddEvent(3, 12, 32, 'N');
	sensor1->AddEvent(4, 12, 32, 'N');

	// -----------------------StatsByMin-------------------------
	// Expected : [1, 1, 1, 1]
	Stats *minStats = sensor1->GetStatsByMin(1,12,32);

	if (!(minStats->counters[V] == 1 && minStats->counters[J] == 1 &&
		minStats->counters[R] == 1 && minStats->counters[N] == 1))
	{
		cout << "Error : unexpected result for GetStatsByMin\n";
		if (verbose)
		{
			cout << "------------By Min-------------\n";
			cout << "V " << minStats->counters[V] << "\n";
			cout << "J " << minStats->counters[J] << "\n";
			cout << "R " << minStats->counters[R] << "\n";
			cout << "N " << minStats->counters[N] << "\n";
		}
		return false;
	}

	// -----------------------StatsByHour-------------------------
	// Expected : [1, 2, 1, 1]
	Stats *hourStats = new Stats();
	sensor1->AddStatsByHour(1,12, hourStats);

	if (!(hourStats->counters[V] == 1 && hourStats->counters[J] == 2 &&
		hourStats->counters[R] == 1 && hourStats->counters[N] == 1))
	{
		cout << "Error : unexpected result for GetStatsByHour\n";
		if (verbose)
		{
			cout << "------------By Hour-------------\n";
			cout << "V " << hourStats->counters[V] << "\n";
			cout << "J " << hourStats->counters[J] << "\n";
			cout << "R " << hourStats->counters[R] << "\n";
			cout << "N " << hourStats->counters[N] << "\n";
		}
		return false;
	}

	delete hourStats;

	// -----------------------StatsByDay-------------------------
	// Expected : [1, 2, 3, 1]
	Stats *dayStats = new Stats();
	sensor1->AddStatsByDay(1, dayStats);

	if (!(dayStats->counters[V] == 1 && dayStats->counters[J] == 2 &&
		dayStats->counters[R] == 3 && dayStats->counters[N] == 1))
	{
		cout << "Error : unexpected result for GetStatsByDay\n";
		if (verbose)
		{
			cout << "------------By Day-------------\n";
			cout << "V " << dayStats->counters[V] << "\n";
			cout << "J " << dayStats->counters[J] << "\n";
			cout << "R " << dayStats->counters[R] << "\n";
			cout << "N " << dayStats->counters[N] << "\n";
		}
		return false;
	}

	delete dayStats;

	// -----------------------StatsBySensor-------------------------
	// Expected : [1, 2, 3, 4]
	Stats *sensorStats = new Stats();
	sensor1->AddStatsBySensor(sensorStats);

	if (!(sensorStats->counters[V] == 1 && sensorStats->counters[J] == 2 &&
		sensorStats->counters[R] == 3 && sensorStats->counters[N] == 4))
	{
		cout << "Error : unexpected result for GetStatsBySensor\n";
		if (verbose)
		{
			cout << "------------By Sensor-------------\n";
			cout << "V " << sensorStats->counters[V] << "\n";
			cout << "J " << sensorStats->counters[J] << "\n";
			cout << "R " << sensorStats->counters[R] << "\n";
			cout << "N " << sensorStats->counters[N] << "\n";
		}
		return false;
	}

	delete sensorStats;

	delete sensor1;

	Utils::printGreen("TEST SUCESSFUL",true);
	return true;
}

void TestEngine::PerformanceSearch()
{
	srand(127);
	BinaryTree testTree = BinaryTree();
	char c[] = "R";
	for (int i = 0; i < 1500; ++i)
	{
		testTree.Insert(i,1,1,1,'V');
	}

	for (int i = 0; i< 20000000;i++)
	{
		testTree.Search(rand()%1500);
	}
}

void TestEngine::PerformanceInsert()
{
	srand(127);
	BinaryTree testTree = BinaryTree();
	for (int i = 0; i < 1500; i++)
	{
		testTree.Insert(i,1,1,1,'V');
	}

	for (int i = 0; i< 20000000;i++)
	{
		testTree.Insert(rand()%1500,1,1,1,'V');
	}
}