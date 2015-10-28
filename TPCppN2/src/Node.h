#ifndef NODE_H
#define NODE_H
//#include "BinaryTree.h"
#include "Sensor.h"
//#define NULL 0


class Node
{
public:
	// ------------------------------------------------------ GETERS :
	
	/** Returns the node at the left of the current node
	*/
	inline Node *GetLeft() const {return left;};

	/** Returns the node at the right of the current node
	*/
	inline Node *GetRight() const {return right;};

	// TODO : Put those in private or delete them
	void SetLeft(Node *theLeft); 

	void SetRight(Node *theRight);

	/** Exchanges this node sensor with the one in target

	* @param [in,out] target The node where the swap will happend.
	*/
	void SwapSensor(Node *target);
	// Exchanges this object sensor with the one in target

	inline long GetSensorID() const {return sensor->GetID();};
	// Gets the current node sensor ID

	inline long GetHeight() const {return height;};
	// Get the current computed height of this node
	// NOTE : ComputeHeight is more reliable, but involve maths

	void LeftRotate();
	// Performs a left rotation using this node as root

	void RightRotate();
	// Performs a right rotation using this node as root

	void DoubleLeftRotation();
	// Performs a right rotation on the right subtree of this node,
	// then performs a left roation on this node.

	void DoubleRightRotation();
	// Performs a left rotation on the right subtree of this node,
	// then performs a right roation on this node.

	/** Rebalances the tree
	*/
	void Rebalance();


	void SetHeight(long h) {height = h;};
	// Gets the height of the node

	long ComputeHeight();
	// Compute the Height of this node and his childs.
	// Returns the height of the node

	/** Retruns the substraction of the left tree's height with the 
	*	right tree's one. A null value indicates that
	*	this subtree is perfecly balanced. A positive one indicates that
	*	the tree is left heavy, and a negative one that the tree is right heavy
	*	
	*/
	long GetBalance();

	/** Returns the pointer to the node that contains a sensor with its ID matching 
	*	aID
	*	@param [in] aID The ID used for the search
	*	@returns If the node is found, return the pointer to the node; 
	*	else, returns a NULL pointer. 
	*/
	Node *Search(long aID);

	/** Insert the given sensor in the tree
	*	@retrun NULL if the node has been inserted. If there is already
	*	a node containing a sensor with ID equals to aID, retruns the
	*	node instead.
	*/
	Node *Insert(int aID);


	/** Print in the standard output a representation of this node
	*	subtree that can be read as a lua table.\n
	*	The table will have this form :\n
	*	{sensor.ID,left{left.Serialize()},right{right.Serialize}}
	*/
	void Serialize(int depth);
	// Prints the node so it can be parsed as a lua table
	// PS : Yes I'm crasy.

	Node(Sensor *sensor, Node *parent = NULL, Node *left = NULL, Node *right = NULL);
	// Node Constructor
	// sensor initialize the Node sensor, and left and right the
	// childs nodes of this node

	~Node();


private:
	Node *parent;
	Node *left;		//The node on the left
	Node *right;	//The node on the right
	long height;
	Sensor *sensor;	//The sensor contained in the node
};


#endif	//NODE_H