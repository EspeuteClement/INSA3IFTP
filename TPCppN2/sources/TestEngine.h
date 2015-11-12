#ifndef TEST_ENGINE_H
#define TEST_ENGINE_H

#include <string>

// Set to true if you want all the Tests to be more explicit
#define DEFAULT_VERBOSE false

/** A class that tests the BinaryTree and the sensor classes
*/
class TestEngine
{
public:
	/** Tests the Iteration method in the BinaryTree Class
	*	@param verbose Will display more information about the tests at execution.
	*	@return true if the test is successful, false else
	*/
	static bool IterationTest_1(bool verbose = DEFAULT_VERBOSE);

	/** Print the number of unbalanced nodes
	*	@param verbose Will display more information about the tests at execution.
	*	@return true if the test is successful, false else
	*/
	static bool BalanceTest_1(bool verbose = DEFAULT_VERBOSE);

	/** Tests the Search function
	*	@param verbose Will display more information about the tests at execution.
	*	@return true if the test is successful, false else
	*/
	static bool SearchTest_1(bool verbose = DEFAULT_VERBOSE);

	/** Creates a Sensor object, adds events to it, and displays statistics
	*	@param verbose Will display more information about the tests at execution.
	*	@return true if the test is successful, false else
	*/
	static bool SensorTest_1(bool verbose = DEFAULT_VERBOSE);

	/** Creates 1500 sensors and performs
	*	20000000 search operations on them
	*	Allows to make some speed tests
	*/
	static void PerformanceSearch();

	/** Creates 1500 sensors and performs
	*	20000000 insert operations on them
	*	Allows to make some speed tests
	*/
	static void PerformanceInsert();

	/** Creates a tree and Serializes it
	*/
	static void SerializeTest();

};

#undef DEFAULT_VERBOSE

#endif
