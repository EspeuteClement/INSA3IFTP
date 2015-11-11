#ifndef NODE_H
#define NODE_H
//#include "BinaryTree.h"
#include <iostream>
#include "Sensor.h"
//#define NULL 0

/** Represents a BinaryTree Leaf, and contain a Sensor.
*/
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

	

	/** Simply returns the ID of this node's sensor.
	*	@return The sensors's ID
	*/
	inline long GetSensorID() const {return sensor->GetID();};

	/** Return this node height.
	*/
	inline long GetHeight() const {return height;};
	// Get the current computed height of this node
	// NOTE : ComputeHeight is more reliable, but involve maths

	


	

	

	/** Returns the subtraction of the left tree's height with the
	*	right tree's one. A 0 value indicates that
	*	this subtree is perfectly balanced. A positive one indicates that
	*	the tree is left heavy, and a negative one that the tree is right heavy
	*/
	long GetBalance();

	/** Returns the pointer to the node that contains a sensor with its ID matching
	*	aID
	*	@param [in] aID The ID used for the search.
	*	@return If the node is found, return the pointer to the node.
	*	Else, returns a NULL pointer.
	*/
	Node *Search(long aID);

	/** Insert the given sensor in the subtree and returns a pointer to
	*	the new node.
	*	@return NULL if the node has been inserted. If there is already
	*	a node containing a sensor with ID equals to aID, returns the
	*	node instead.
	*/
	Node *Insert(int aID);


	/** Print in the standard output a representation of this node
	*	subtree that can be read as a lua table.\n
	*	The table will have this form :\n
	*	<CODE>{id=sensor.ID,height=height,left={left.Serialize()},
	*	right={right.Serialize()}} </CODE>
	*/
	void Serialize();

	/** Returns this node's sensor.
	*/
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

	/** Exchanges this node sensor with the one in target
	* @param [in] target The node where the swap will happen.
	*/
	void SwapSensor(Node *target);
	// Exchanges this object sensor with the one in target

	/**	Performs a LeftRotation using this node as the root
	*/
	void LeftRotation();

	/**	Performs a RightRotation using this node as the root
	*/
	void RightRotation();

	/** Performs a right rotation on the right subtree of this node,
		then performs a left rotation on this node.
	*/
	void DoubleLeftRotation();

	/** Performs a left rotation on the right subtree of this node,
		then performs a right rotation on this node.
	*/
	void DoubleRightRotation();

	/** Re balance this subtree, then this node parent subtree up to
	*	this tree root.
	*/
	void Rebalance();

	/** Compute this Node Height (the number of Node in the longest
	*	subtree of this node) and then returns it
	*	@return this Node Height
	*/
	long ComputeHeight();

	Sensor *sensor;	/**The sensor contained in the node */

	Node *parent;	/**	The parent node to this one. NULL if there is
					no parent node*/

	Node *left;		/**The node on the left */
	Node *right;	/**The node on the right*/
	long height;	/** The height, i.e. the number of nodes in the
					longest branch under this node */


};


#endif	//NODE_H
