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
}