#include "TestEngine.h"
#include "BinaryTree.h"
#include "Utils.h"

#include <iostream>




bool TestEngine::Iteration_Test1(bool verbose)
{
	const int NUMBERS = 1500;
	Utils::printBold("ITERATION TEST 1", true);

	// Create the binary tree
	BinaryTree testTree = BinaryTree();

	// Create an array that will store if a node has been
	// traversed
	bool found[NUMBERS];
	for (int i = 0; i < NUMBERS; ++i)
	{
		found[i] = false;
	}

	// Populate the tree with id between 0 and NUMBERS
	for (int i = 0; i < NUMBERS; ++i)
	{
		testTree.Insert(i,0,0,0,0);
	}

	// Iterate trough the tree
	testTree.InitIterate();
	Node *iterator = NULL;
	while( (iterator = testTree.Iterate() ) != NULL)
	{
		int id = iterator->GetSensorID();
		if (verbose)
		{
			std::cout << id << '\n';
		}
		// If we haven't visited this node yet ...
		if (found[id] == false)
		{
			// Now we have :)
			found[id] = true;
		}
		else // We've gone trough the node twice !!!
		{
			Utils::printRed("ERROR, A NODE WAS FOUND TWICE",true);
			return false;
		}
	}

	for (int i = 0; i< NUMBERS; ++i)
	{
		if (!found[i])
		{
			Utils::printRed("ERROR, A NODE WAS NOT VISITED",true);
			return false;
		}
	}

	Utils::printGreen("TEST SUCESSFUL",true);
	return true;
}

bool TestEngine::BalanceTest_1(bool verbose)
{
	return false;
}
