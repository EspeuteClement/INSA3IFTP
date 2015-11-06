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
	*	@return A pointer to the left node of this node. Returns NULL
	*	if there is no left node
	*/
	inline Node *GetLeft() const {return left;};

	/** Returns the node at the right of the current node
	*	@return A pointer to the right node of this node. Returns NULL
	*	if there is no right node
	*/
	inline Node *GetRight() const {return right;};

	// TODO : Put those in private or delete them
	

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

	/**	Performs a LeftRotation using this node as the root
	*/
	void LeftRotation();

	/**	Performs a RightRotation using this node as the root
	*/
	void RightRotation();

	/** Performs a right rotation on the right subtree of this node,
		then performs a left roation on this node.
	*/
	void DoubleLeftRotation();
	
	/** Performs a left rotation on the right subtree of this node,
		then performs a right roation on this node.
	*/
	void DoubleRightRotation();
	

	/** Rebalance this subtree, then this node parent subtree up to this
	*	tree root.
	*/
	void Rebalance();

	/** Compute this node Height (the number of node in the longest
	*	subtree of this node)
	*	@return this node Height
	*/
	long ComputeHeight();

	/** Retruns the substraction of the left tree's height with the 
	*	right tree's one. A null value indicates that
	*	this subtree is perfecly balanced. A positive one indicates that
	*	the tree is left heavy, and a negative one that the tree is right heavy
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
	*	{id=sensor.ID,height=height,left={left.Serialize()},=right{right.Serialize()}}
	*/
	void Serialize(int depth);

	Sensor *GetSensor() {return sensor;};

	/**	Create a Node.
	*	@param sensor The sensor contained in this node
	*/
	Node(Sensor *sensor, Node *parent = NULL, Node *left = NULL, Node *right = NULL);

	~Node();


private:
	/** Set the left node of this node to be theLeft
	*	@param theLeft A pointer to the node that should be inserted
	*/
	void setLeft(Node *theLeft); 

	/** Set the right node of this node to be theRight
	*	@param theRight A pointer to the node that should be inserted
	*/
	void setRight(Node *theRight);

	Sensor *sensor;	/**The sensor contained in the node */

	Node *parent;	/**	The parent node to this one. NULL if there is
					no parent node*/

	Node *left;		/**The node on the left */
	Node *right;	/**The node on the right*/
	long height;	/** The height, i.e. the number of nodes in the
					longest branch under this node */

	
};


#endif	//NODE_H