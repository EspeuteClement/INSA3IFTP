#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H

#include <string>



// set to true if you want all the Tests to be verbose
#define DEFAULT_VERBOSE false
/** A class that tests all the stuff in the binary tree
*/
class TestEngine
{
public:
	/** Tests the Iteration method in the BinaryTree Class
	*	@param verbose Will print what the test is doing and a title in
	*	the standard output
	*	@return true if the test is successful, false else
	*/
	static bool Iteration_Test1(bool verbose = DEFAULT_VERBOSE);

	/** Print the number of unbalanced nodes
	*/
	static bool BalanceTest_1(bool verbose = DEFAULT_VERBOSE);
};

#undef DEFAULT_VERBOSE

#endif