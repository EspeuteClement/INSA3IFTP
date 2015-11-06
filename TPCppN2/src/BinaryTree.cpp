#include <iostream>
#include "BinaryTree.h"
#include "Sensor.h"
#include "Node.h"

void BinaryTree::Serialize()
{
	//root->ComputeHeight();
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

Sensor *BinaryTree::Search(long ID)
{
	Node *nodeMatch = root->Search(ID);
	if (nodeMatch != NULL)
	{
		return nodeMatch->GetSensor();
	}
	return NULL;
}

void BinaryTree::Insert(int ID, 
				unsigned char d,
				unsigned char h,
				unsigned char m,
				unsigned char value)
{
	Node *sensorNode = root->Insert(ID);
	sensorNode->GetSensor()->AddEvent(d,h,m,value);
}

BinaryTree::BinaryTree(Node* aRoot):root(aRoot)
{

}

BinaryTree::~BinaryTree()
{
	delete root;
}
