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

	/** Returns the Node at the left of the current Node
	*	@return A pointer to the left Node of this Node. Returns NULL
	*	if there is no left Node
	*/
	inline Node *GetLeft() const {return left;};

	/** Returns the Node at the right of the current Node
	*	@return A pointer to the right Node of this Node. Returns NULL
	*	if there is no right Node
	*/
	inline Node *GetRight() const {return right;};

	/** Simply returns the ID of this Node's sensor.
	*	@return The sensors's ID
	*/
	inline long GetSensorID() const {return sensor->GetID();};

	/** Return this Node's height.
	*/
	inline long GetHeight() const {return height;};

	/** Returns the subtraction of the left tree's height with the
	*	right tree's one. A 0 value indicates that
	*	this subtree is perfectly balanced. A positive one indicates that
	*	the tree is left heavy (more elements in the left subtree than in the right)
	* , and a negative one that the tree is right heavy.
	*/
	long GetBalance();

	/** Returns the pointer to the Node that contains a sensor with its ID matching
	*	searchID
	*	@param [in] searchID The ID used for the search.
	*	@return If the Node is found, return the pointer to the Node.
	*	Else, returns a NULL pointer.
	*/
	Node *Search(long searchID);

	/** Insert the given sensor in the subtree and returns a pointer to
	*	the new Node.
	*	@param searchID [in] the ID to match in the insertion.
	*	@return A pointer to the new Node that has been inserted. 
	*	If there was already a Node containing a sensor with ID equals 
	*	to searchID, returns a pointer to that Node instead.
	*/
	Node *Insert(int searchID);


	/** Print in the standard output a representation of this Node
	*	subtree that can be read as a lua table.\n
	*	The table will have this form :\n
	*	<CODE>{id=sensor.ID,height=height,left={left.Serialize()},
	*	right={right.Serialize()}} </CODE>
	*/
	void Serialize();

	/** Returns a pointer to this Node's sensor.
	*/
	Sensor *GetSensor() const {return sensor;};

	/**	Create a Node.
	*	@param sensor The sensor contained in this Node
	*/
	Node(Sensor *sensor, Node *parent = NULL, Node *left = NULL, Node *right = NULL);

	~Node();


private:
	/** Set the left Node of this Node to be theLeft
	*	@param theLeft A pointer to the Node that should be inserted
	*/
	void setLeft(Node *theLeft);

	/** Set the right Node of this Node to be theRight
	*	@param theRight A pointer to the Node that should be inserted
	*/
	void setRight(Node *theRight);

	/** Exchanges this Node sensor with the one in target
	* @param [in] target The Node where the swap will happen.
	*/
	void SwapSensor(Node *target);
	// Exchanges this object sensor with the one in target

	/**	Performs a LeftRotation using this Node as the root
	*/
	void LeftRotation();

	/**	Performs a RightRotation using this Node as the root
	*/
	void RightRotation();

	/** Performs a right rotation on the right subtree of this Node,
		then performs a left rotation on this Node.
	*/
	void DoubleLeftRotation();

	/** Performs a left rotation on the right subtree of this Node,
		then performs a right rotation on this Node.
	*/
	void DoubleRightRotation();

	/** Re balance this subtree, then this Node parent subtree up to
	*	this tree root.
	*/
	void Rebalance();

	/** Compute this Node Height (the number of Node in the longest
	*	subtree of this Node) and then returns it
	*	@return this Node Height
	*/
	long ComputeHeight();

	Sensor *sensor;	/**The sensor contained in the Node */

	Node *parent;	/**	The parent Node to this one. NULL if there is
					no parent Node*/

	Node *left;		/**The Node on the left */
	Node *right;	/**The Node on the right*/
	long height;	/** The height, i.e. the number of Nodes in the
					longest branch under this Node */


};


#endif	//NODE_H
