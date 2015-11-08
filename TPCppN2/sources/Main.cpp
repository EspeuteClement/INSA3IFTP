#include <iostream>
#include <stdlib.h>
#include "Node.h"
#include "Sensor.h"
#include "BinaryTree.h"
#include "TestEngine.h"
#include "IoEngine.h"

int main()
{
	srand(127);
	BinaryTree tree;

  IoEngine test(&tree);
  while(test.ReadInput());

  //TestEngine::BalanceTest_1();
  //TestEngine::Iteration_Test1();
  // TEST THE ITERATION PROCESS
  /*
  tree.InitIterate();
  Node *daNode = NULL;
  int counter = 0;
  while((daNode = tree.Iterate()) != NULL)
  {
    std::cout << daNode->GetSensorID() <<'\n';
    counter ++;
  }
  std::cout << counter << '\n';
  */
	//
  //std::cout << "V" << theRoot->Search(1)->GetSensor()->GetStatsByMin(1,1,1)->v << "\n";
	//theRoot->DoubleLeftRotation();
	//int2Node->Rebalance();
	//tree.Serialize();
  return 0;
}