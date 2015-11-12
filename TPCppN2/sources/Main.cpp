#include "BinaryTree.h"
#include "IoEngine.h"

// Uncomment following line if you want to execute the tests in TestEngine :
#define DEBUG

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
	//MESURE_TIME((TestEngine::Iteration_Test1()),"Iteration_Test1");
	// TestEngine::BalanceTest_1();
	// TestEngine::SensorTest_1();
  //TestEngine::PerformanceSearch();
  MESURE_TIME((TestEngine::PerformanceSearch()), "PerformanceSearch");
  MESURE_TIME((TestEngine::PerformanceInsert()), "PerformanceInsert");
#endif

  return 0;
}
