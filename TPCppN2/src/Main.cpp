#include <iostream>
#include <stdlib.h>
#include "Node.h"
#include "Sensor.h"
#include "BinaryTree.h"

#include "IoEngine.h"
int main()
{
	srand(127);
	Node *theRoot = new Node(new Sensor(1));
	BinaryTree tree(theRoot);

  IoEngine test(&tree);
  while(test.ReadInput());
	//tree.Serialize();
	//for (int i = 20000000; i > 0; --i)
	//{
	//	tree.Insert(rand()%1500,1,1,1,'V');
	//}
	//
  //std::cout << "V" << theRoot->Search(1)->GetSensor()->GetStatsByMin(1,1,1)->v << "\n";
	//theRoot->DoubleLeftRotation();
	//int2Node->Rebalance();
	//tree.Serialize();
  return 0;
}
/*
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
	Stats *minStats = sensor1->GetStatsByMin(1,12,32);

  cout << "V " << minStats->counters[V] << "\n";
  cout << "J " << minStats->counters[J] << "\n";
  cout << "R " << minStats->counters[R] << "\n";
  cout << "N " << minStats->counters[N] << "\n";

  cout << "------------By Hour-------------\n";
  // Expected : [1, 2, 1, 1]
	Stats *hourStats = new Stats();
	sensor1->AddStatsByHour(1,12, hourStats);

  cout << "V " << hourStats->counters[V] << "\n";
  cout << "J " << hourStats->counters[J] << "\n";
  cout << "R " << hourStats->counters[R] << "\n";
  cout << "N " << hourStats->counters[N] << "\n";

	delete hourStats;

  cout << "------------By Day-------------\n";
  // Expected : [1, 2, 3, 1]
	Stats *dayStats = new Stats();
	sensor1->AddStatsByDay(1, dayStats);

	cout << "V " << dayStats->counters[V] << "\n";
	cout << "J " << dayStats->counters[J] << "\n";
	cout << "R " << dayStats->counters[R] << "\n";
	cout << "N " << dayStats->counters[N] << "\n";

	delete dayStats;

  cout << "------------By Sensor-------------\n";
  // Expected : [10%, 20%, 30%, 40%]

  sensor1->PrintSensorStatsRel();

	delete sensor1;

  return 0;
}
*/
