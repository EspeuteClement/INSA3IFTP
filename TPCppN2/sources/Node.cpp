#include <iostream>
#include "Node.h"
#include "Sensor.h"
#include "Utils.h"
<<<<<<< HEAD
//#define MAP

=======
using namespace std;
>>>>>>> 70ec4105610ffc0a668fc45ed750cf2f5e1fad11
// AVL ALGORITHM : http://www.cise.ufl.edu/~nemo/cop3530/AVL-Tree-Rotations.pdf

//------------------------------------------------------------------------------
// Private functions and methods
//------------------------------------------------------------------------------
void Node::setLeft(Node *theLeft)
{
	left = theLeft;
	if (left != NULL)
	{	left->parent = this;
	}
	// We recompute the height because the added node
	// could have a bigger height than the right sub
	// tree.
	ComputeHeight();
}

void Node::setRight(Node *theRight)
{
	right = theRight;
	if (right != NULL)
	{	right->parent = this;
	}
	ComputeHeight();
}


void Node::SwapSensor(Node *target)
{
	// Note : This method is used when we have to swap
	// 2 nodes in the tree, especially in the left &
	// right rotations. It has the advantage to not mess
	// with the parents & child relations, and it preserves
	// the root in the BinaryTree.
	Sensor *tmp = this->sensor; // Buffer target sensor

	//Perform the swap
	this->sensor = target->sensor;
	target->sensor = tmp;
}

void Node::LeftRotation()
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
		right->setRight(right->left);
		right->setLeft(this->left);
		this->setLeft(right);
		this->setRight(oldRight);
	}
}

void Node::RightRotation()
{
	if(left != NULL)
	{
		// This method is a mirror of LeftRotation.
		SwapSensor(left);
		Node *oldLeft = left->left;
		left->setLeft(left->right);
		left->setRight(this->right);
		this->setRight(left);
		this->setLeft(oldLeft);
	}
}

void Node::DoubleLeftRotation()
{
	if(right!=NULL)
	{
		right->RightRotation();
		LeftRotation();
	}
}

void Node::DoubleRightRotation()
{
	if(left!=NULL)
	{
		left->LeftRotation();
		RightRotation();
	}
}

void Node::Rebalance()
{
	//ComputeHeight();
	long bal = GetBalance();
	//cout << "Rebalancing. Bal : " << bal << "\n";
	if (bal>1) // If the tree is left heavy
	{
		if (left->GetBalance()<=-1) // If the left subtree is right heavy
		{
			DoubleRightRotation();
		}
		else
		{
			RightRotation();
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
			LeftRotation();
		}
	}
	if (parent != NULL)
	{	parent->Rebalance();
	}
}

long Node::ComputeHeight()
{ 
	int l = 0; // The height of the left subtree
	int r = 0; // The height of the right subtree
	if(left != NULL)
	{	l = left->height;
	}
	if(right != NULL)
	{	r = right->height;
	}

	int oldH = height;
	// The height is the max of the subtrees height, plus one
	height = Utils::max(l,r) + 1;

	//Then we call this method for this node parent to propagate
	//The height change (it the height has changed)
	if( oldH != height && parent !=NULL)
	{	parent->ComputeHeight();
	}
	return height;
}

//------------------------------------------------------------------------------
// Public functions and methods
//------------------------------------------------------------------------------
void Node::Serialize()
{

	// The goal is to print something like this :
	// {id,height,left={id,left={...}},right={...}}
	cout << '{';
	cout << "id=" <<GetSensorID();
	cout << ",height=" << height <<',';
	cout << "left=";

	// Serialize the left part of the array
	if (left != NULL)
	{	left->Serialize();
	}
	else // Set the table to nil if the left node is NULL
	{	cout << "nil";
	}
	cout << ',';

	cout << "right=";
	// Serialize the right part of the array
	if (right != NULL)
	{	right->Serialize();
	}
	else // Set the table to nil if the right node is NULL
	{	cout << "nil";
	}

	cout << '}';
}

Node *Node::Search(long searchID)
{

	Node *current = this; // Pointer to the current node

	long id = current->GetSensorID();
	//While we havn't found the right node or there is no more node left ...
	while(current != NULL && !(id == searchID))
	{
		// Go left if searchID is inferior to current node id
		if (searchID < current->GetSensorID())
		{
			current = current->left;
		}
		// Else go right
		else if (searchID > current->GetSensorID())
		{
			current = current->right;
		}
		// If current is not null, get it's id
		if (current != NULL)
		{
			id = current->GetSensorID();
		}
	}
	return current;
}

Node *Node::Insert(int searchID)
{
	if(searchID < GetSensorID())
	{
		if (left != NULL) //If there is a node, search in this subtree
		{	return left->Insert(searchID);
		}
		else //Else return the pointer to the left part
		{
			Node *n = new Node(new Sensor(searchID),this);
			setLeft(n);
			Rebalance();

			return n;
		}
	}
	else if(searchID > GetSensorID())
	{
		if (right != NULL)
		{	return right->Insert(searchID);
		}
		else
		{
			Node *n = new Node(new Sensor(searchID),this);
			setRight(n);
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

<<<<<<< HEAD
void Node::Rebalance()
{
	long bal = GetBalance();
	if (bal>1) // If the tree is left heavy
	{
		if (left->GetBalance()<=-1) // If the left subtree is right heavy
		{
			DoubleRightRotation();
		}
		else
		{
			RightRotation();
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
			LeftRotation();
		}
	}
	if (parent != NULL)
	{	parent->Rebalance();
	}
}


=======
//------------------------------------------------------------------------------
// Constructors or/and Destructors
//------------------------------------------------------------------------------
>>>>>>> 70ec4105610ffc0a668fc45ed750cf2f5e1fad11
Node::Node(Sensor *sensor, Node *parent, Node *left, Node *right):
	sensor(sensor),parent(parent),left(left),right(right)
{
	height = 1;
}

Node::~Node(){
	if (left != NULL)
	{	delete left;
	}
	if (right != NULL)
	{	delete right;
	}
	delete sensor;
}
