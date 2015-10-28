#include <iostream>
#include "Node.h"
#include "Sensor.h"
#include "Utils.h"

// AVL ALGORITHM : http://www.cise.ufl.edu/~nemo/cop3530/AVL-Tree-Rotations.pdf

void Node::SetLeft(Node *theLeft)
{
	left = theLeft;
	if (left != NULL)
	{	left->parent = this;
	}
	//height = -1;
	//ComputeHeight();
}

void Node::SetRight(Node *theRight)
{
	right = theRight;
	if (right != NULL)
	{	right->parent = this;
	}
	//height = -1;
	//ComputeHeight();
}


void Node::SwapSensor(Node *target)
{
	Sensor *tmp = this->sensor; // Buffer target sensor

	//Perform the swap
	this->sensor = target->sensor;
	target->sensor = tmp;
}

void Node::LeftRotate()
{
	if(right != NULL)
	{
		// We swap this sensor ID with this node right one
		// so pointers don't get messed up.
		// If we don't, parent node of this node will
		// still point to the same node after
		// the rotation, messing the tree up.
		SwapSensor(right);
		Node *oldRight = right->right;
		right->SetRight(right->left);
		right->SetLeft(this->left);
		this->SetLeft(right);
		this->SetRight(oldRight);
	}
}

void Node::RightRotate()
{
	if(left != NULL)
	{
		// This method is a mirror of LeftRotate.
		SwapSensor(left);
		Node *oldLeft = left->left;
		left->SetLeft(left->right);
		left->SetRight(this->right);
		this->SetRight(left);
		this->SetLeft(oldLeft);
	}
}

void Node::DoubleLeftRotation()
{
	if(right!=NULL)
	{
		right->RightRotate();
		LeftRotate();
	}
}

void Node::DoubleRightRotation()
{
	if(left!=NULL)
	{
		left->LeftRotate();
		RightRotate();
	}
}

long Node::ComputeHeight()
{
	//if (height != -1) return height;
	int l = 0; // The height of the left subtree
	int r = 0; // The height of the right subtree
	if(left != NULL)
	{	l = left->ComputeHeight();		
	}
	if(right != NULL)
	{	r = right->ComputeHeight();
	}
	height = Utils::max(l,r) + 1;
	return height;
}

void Node::Serialize(int depth)
{
	// Recursivity power :D

	// The goal is to print something like this :
	// {id,left={id,left={...}},right={...}}
	std::cout << '{';
	std::cout << "id=" <<GetSensorID();
	std::cout << ",height=" << height <<',';
	std::cout << "left=";
	
	// Serialize the left part of the array
	if (left != NULL)
	{	left->Serialize(depth+1);
	}
	else // Set the table to nil if the left node is NULL
	{	std::cout << "nil";
	}
	std::cout << ',';

	std::cout << "right=";
	// Serialize the right part of the array
	if (right != NULL)
	{	right->Serialize(depth+1);
	}
	else // Set the table to nil if the right node is NULL
	{	std::cout << "nil";
	}

	std::cout << '}';
}

Node *Node::Search(long aID)
{
	if(aID < GetSensorID())
	{
		if (left != NULL) //If there is a node, search in this subtree
		{	return left->Search(aID);
		}
		else //Else return the pointer to the left part
		{	return NULL;
		}
	}
	else if(aID > GetSensorID())
	{
		if (right != NULL)
		{	return right->Search(aID);
		}
		else
		{	return NULL;
		}
	}
	else
	{
		return this;
	}
}

Node *Node::Insert(int aID)
{
	if(aID < GetSensorID())
	{
		if (left != NULL) //If there is a node, search in this subtree
		{	return left->Insert(aID);
		}
		else //Else return the pointer to the left part
		{	
			Node *n = new Node(new Sensor(aID),this);
			SetLeft(n);
			Rebalance();
			
			return n;
		}
	}
	else if(aID > GetSensorID())
	{
		if (right != NULL)
		{	return right->Insert(aID);
		}
		else
		{	
			Node *n = new Node(new Sensor(aID),this);
			SetRight(n);
			Rebalance();
			return n;
		}
	}
	else
	{
		return this;
	}
}

long Node::GetBalance()
{
	long lHeight = 0;
	if (left != NULL)
	{	lHeight = left->height;
	}
	long rHeight = 0;
	if (right != NULL)
	{	rHeight = right->height;
	}

	return lHeight - rHeight;
}

void Node::Rebalance()
{
	ComputeHeight();
	long bal = GetBalance();
	//std::cout << "Rebalancing. Bal : " << bal << "\n";
	if (bal>1) // If the tree is left heavy
	{
		if (left->GetBalance()<=-1) // If the left subtree is right heavy
		{
			DoubleRightRotation();
		}
		else
		{
			RightRotate();
		}
	}
	else if (bal < -1) // if the tree is right heavy
	{
		if (right->GetBalance()>=1) // If the right subtree is left heavy
		{
			DoubleLeftRotation();
		}
		else
		{
			LeftRotate();
		}
	}
	if (parent != NULL)
	{	parent->Rebalance();
	}
}


Node::Node(Sensor *sensor, Node *parent, Node *left, Node *right):
	sensor(sensor),parent(parent),left(left),right(right)
{
#ifdef MAP
	std::cout << "Constructing a <None>";
#endif
	//height = 0;
}

Node::~Node(){
#ifdef MAP
	std::cout << "Destructing a <None>";
#endif
	if (left != NULL)
	{	delete left;
	}
	if (right != NULL)
	{	delete right;
	}
	delete sensor;
}

