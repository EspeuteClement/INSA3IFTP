#include <iostream>
#include "BinaryTree.h"

#include "Node.h"

void Add(Sensor *sensor){
	/*Node *newNode = new Node(sensor);
	Node *currentNode = root;
	while(currentNode.left != null)
	{
		currentNode
	}*/
}

void BinaryTree::Display()
{
	root->ComputeHeight();
	std::cout<<"return ";
	root->Serialize(0);
	std::cout<<"\n";
	/*for (int i = 0; i < height*2; ++i)
	{	std::cout << ' ';
	}
	std::cout <<root->GetSensorID();
	std::cout << '\n';
	for (int i = 0; i < height*2-1; ++i)
	{	std::cout << ' ';
	}
	std::cout <<"/ \\";
	std::cout << '\n';
	if(root->GetLeft() != NULL)
	{	std::cout <<root->GetLeft()->GetSensorID();
	}
	else
	{	std::cout <<" ";
	}
	std::cout << "   ";
	if(root->GetRight() != NULL)
	{	std::cout <<root->GetRight()->GetSensorID();
	}
	else
	{	std::cout <<" ";
	}*/
}

void BinaryTree::Insert(int ID)
{
	Node *sensorNode = root->Insert(ID);
}

BinaryTree::BinaryTree(Node* aRoot):root(aRoot)
{

}

BinaryTree::~BinaryTree()
{
	delete root;
}