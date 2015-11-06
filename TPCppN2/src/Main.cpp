/*
#include <iostream>
#include <stdlib.h>
#include "Node.h"
#include "Sensor.h"
#include "BinaryTree.h"
int main()
{
	srand(127);
	Node *theRoot = new Node(new Sensor(1));
	BinaryTree tree(theRoot);
	//tree.Serialize();
	for (int i = 15000; i > 0; --i)
	{
		tree.Insert(rand()%10000);
	}
	//theRoot->DoubleLeftRotation();
	//int2Node->Rebalance();
	tree.Serialize();

	return 0;
}*/

#include <iostream>
#include "Sensor.h"

using namespace std;

int main() {
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

  cout << "------------By Min-------------\n";
  // Expected : [1, 1, 1, 1]
  Stats *statsMin = sensor1->GetStatsByMin(1,12,32);

  cout << "V " << statsMin->v << "\n";
  cout << "J " << statsMin->j << "\n";
  cout << "R " << statsMin->r << "\n";
  cout << "N " << statsMin->n << "\n";

  cout << "------------By Hour-------------\n";
  // Expected : [1, 2, 1, 1]
  Stats *statsHour = new Stats();
  sensor1->GetStatsByHour(1,12, statsHour);

  cout << "V " << statsHour->v << "\n";
  cout << "J " << statsHour->j << "\n";
  cout << "R " << statsHour->r << "\n";
  cout << "N " << statsHour->n << "\n";

  delete statsHour;

  cout << "------------By Day-------------\n";
  // Expected : [1, 2, 3, 1]
  Stats *statsDay = new Stats();
  sensor1->GetStatsByDay(1, statsDay);

  cout << "V " << statsDay->v << "\n";
  cout << "J " << statsDay->j << "\n";
  cout << "R " << statsDay->r << "\n";
  cout << "N " << statsDay->n << "\n";

  delete statsDay;

  cout << "------------By Sensor-------------\n";
  // Expected : [10%, 20%, 30%, 40%]
  StatsRel *statsRelSensor = new StatsRel();
  sensor1->GetStatsRelBySensor(statsRelSensor);

  cout << "V " << (int)(statsRelSensor->v*100) << "%\n";
  cout << "J " << (int)(statsRelSensor->j*100) << "%\n";
  cout << "R " << (int)(statsRelSensor->r*100) << "%\n";
  cout << "N " << (int)(statsRelSensor->n*100) << "%\n";

  delete statsRelSensor;

  delete sensor1;

  return 0;
}
