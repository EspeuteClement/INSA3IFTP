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

  return 0;
}
