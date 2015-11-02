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

  cout << "V " << sensor1->GetStatsByMin(1,12,32)->v << "\n";
  cout << "J " << sensor1->GetStatsByMin(1,12,32)->j << "\n";
  cout << "R " << sensor1->GetStatsByMin(1,12,32)->r << "\n";
  cout << "N " << sensor1->GetStatsByMin(1,12,32)->n << "\n";

  cout << "------------By Hour-------------\n";
  // Expected : [1, 2, 1, 1]

  cout << "V " << sensor1->GetStatsByHour(1,12)->v << "\n";
  cout << "J " << sensor1->GetStatsByHour(1,12)->j << "\n";
  cout << "R " << sensor1->GetStatsByHour(1,12)->r << "\n";
  cout << "N " << sensor1->GetStatsByHour(1,12)->n << "\n";

  cout << "------------By Day-------------\n";
  // Expected : [1, 2, 3, 1]

  cout << "V " << sensor1->GetStatsByDay(1)->v << "\n";
  cout << "J " << sensor1->GetStatsByDay(1)->j << "\n";
  cout << "R " << sensor1->GetStatsByDay(1)->r << "\n";
  cout << "N " << sensor1->GetStatsByDay(1)->n << "\n";

  cout << "------------By Sensor-------------\n";
  // Expected : [10%, 20%, 30%, 40%]

  cout << "V " << (int)(sensor1->GetStatsBySensor()->v*100) << "%\n";
  cout << "J " << (int)(sensor1->GetStatsBySensor()->j*100) << "%\n";
  cout << "R " << (int)(sensor1->GetStatsBySensor()->r*100) << "%\n";
  cout << "N " << (int)(sensor1->GetStatsBySensor()->n*100) << "%\n";

  return 0;
}

