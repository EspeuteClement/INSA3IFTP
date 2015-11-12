#include "BinaryTree.h"
#include "IoEngine.h"
#include <ctime>
// Uncomment following line if you want to execute the tests in TestEngine :
//#define DEBUG

// Uncomment if you want to export a binary tree as a lua table. Need debug enabled
//#define SERIALIZE

#ifdef DEBUG

#include "TestEngine.h"
#include "Utils.h"
#endif

/** Performs the tests from TestEngine if DEBUG is defined.
* Else, initiates IoEngine to listen for user input and execute it as long as no
* EXIT command is issued.
*/
int main()
{
#ifndef DEBUG
	BinaryTree tree;

  IoEngine engine(&tree);
  while(engine.ReadInput());
#endif

#ifdef DEBUG
#ifndef SERIALIZE
  // Tests the BinaryTree features
  TestEngine::IterationTest_1();
	TestEngine::BalanceTest_1();

  // Tests the sensors features
	TestEngine::SensorTest_1();

  // Test the overall performance of the binary tree operations
  MESURE_TIME((TestEngine::PerformanceSearch()), "PerformanceSearch");
  MESURE_TIME((TestEngine::PerformanceInsert()), "PerformanceInsert");
#else
  TestEngine::SerializeTest();
#endif

#endif

  return 0;
}
