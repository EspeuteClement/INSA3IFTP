#include "TestEngine.h"
#include "BinaryTree.h"
#include "Utils.h"
#include <stdlib.h>
#include <iostream>


bool TestEngine::Iteration_Test1(bool verbose)
{
	// The numbers of elements to put in the binary tree
	const int NUMBERS = 15000;
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
	srand(127);
	const int NUMBERS = 15000;
	Utils::printBold("BALANCE 1", true);
	
	// Create the binary tree
	BinaryTree testTree = BinaryTree();
	

	// Populate the tree with random id between 0 and NUMBERS
	for (int i = 0; i < NUMBERS; i++)
	{
		testTree.Insert(rand()%15000-7500,0,0,0,0);
	}
	//testTree.Serialize();
	// Iterate trough the tree
	testTree.InitIterate();
	Node *iterator = NULL;
	while( (iterator = testTree.Iterate() ) != NULL)
	{
		int id = iterator->GetSensorID();
		int balance = iterator->GetBalance();
		if (verbose)
		{
			std::cout << id << " " << balance <<'\n';
		}
		if (abs(balance) > 1)
		{
			Utils::printRed("WARNING : A NODE WITH A BALANCE OF 2 OR PLUS HAS BEEN FOUND",true);
		}
	}
	return true;
}


