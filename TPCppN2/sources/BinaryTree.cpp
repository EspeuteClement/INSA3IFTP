#include <iostream>
#include "BinaryTree.h"
#include "Sensor.h"
#include "Node.h"

void BinaryTree::Serialize()
{
	// print return (so the lua table will be returned as a function)
	std::cout<<"return ";
	root->Serialize();
	std::cout<<"\n";
}

Sensor *BinaryTree::Search(long ID)
{
	if (root != NULL)
	{
		// Simpli executre search on the tree's root
		Node *nodeMatch = root->Search(ID);

		//If we found a Node, then return the node sensor
		if (nodeMatch != NULL)
		{
			return nodeMatch->GetSensor();
		}
	}
	
	return NULL;
}

void BinaryTree::Insert(int ID, 
				unsigned char d,
				unsigned char h,
				unsigned char m,
				unsigned char value)
{
	Node *sensorNode = NULL;
	// If there is no root, create a root !
	if (root == NULL)
	{
		root = new Node(new Sensor(ID));
		sensorNode = root;
	}
	else
	{
		// Else simply call insert on the tree's root.
		sensorNode = root->Insert(ID);
	}
	// Then add the Evelnt.
	sensorNode->GetSensor()->AddEvent(d,h,m,value);
}

void BinaryTree::InitIterate()
{
	if (root!= NULL)
	{
		if (stack == NULL || stackDepth != root->GetHeight()+2)
		{
			if (stack != NULL)
			{
				delete[] stack;
			}
			stackDepth = root->GetHeight()+2;
			stack = new Node*[stackDepth];
		}
		stackPos = 0;
		stack[stackPos] = root;
	}
}

Node *BinaryTree::Iterate()
{
	if (stack != NULL && stack[0] != NULL && root != NULL)
	{
		// Ready the current node for the return
		Node *returnValue = stack[stackPos];;
		
		//If there is a value at the left of the current node,
		// push it into the stack
		if (returnValue->GetLeft() != NULL)
		{
			++stackPos;
			stack[stackPos] = returnValue->GetLeft();
		}
		//Else, if there is a value right to this node,
		// push in into the stack
		else if (returnValue->GetRight() != NULL)
		{
			++stackPos;
			stack[stackPos] = returnValue->GetRight();
		}
		//Else, pop all the values until we found a node
		//the right that we havn't visited, then push
		// that node in
		else
		{
			//stackPos;
			while(stack[stackPos]->GetRight() == NULL || stack[stackPos+1] == stack[stackPos]->GetRight())
			{
				//pop
				--stackPos;
				if (stackPos < 0)
				{
					stack[0] = NULL;
					return returnValue;
				}

			}
			// Then we have found our node, push it
			++stackPos;
			stack[stackPos] = stack[stackPos-1]->GetRight();
		}

		return returnValue;
	}
	return NULL;
}


BinaryTree::BinaryTree(Node* aRoot):root(aRoot)
{
	stack = NULL;
	stackDepth = 0;
	stackPos = 0;
}

BinaryTree::~BinaryTree()
{
	if (stack != NULL)
	{
		delete[] stack;
	} 
	if (root != NULL)
	{
		delete root;	
	}
}
