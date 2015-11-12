	#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"
#include "Sensor.h"


/** Data structure used for holding all the Sensor Objects in your application.
*/
class BinaryTree{
public:

	/** Get the sensor where ID equals the sensor ID
	*	@return A pointer to the sensor
	*/
	Sensor *Search(long ID);

	/** Prints a serialized form of the binary tree in the standard output.
	*	The serialization takes the form of a lua table, so it can be
	*	parsed by an external visualizer. Check Node::Serialize() for mode info
	*/
	void Serialize();

	/**	Insert data in the tree.
	*	@param ID The id of the sensor where the data should be stored. If
	*	the sensor doesn't exists, it will be created.
	*	@param d The day in the week where the data must be put.
	*	1 = Monday ... 7 = Sunday.
	*	@param h The hour where to put the data.
	*	@param m The minute where to put the data.
	*	@param value a char corresponding to the traffic to put in the
	*	sensor. 
	*/
	void Insert(int ID, 
				unsigned char d,
				unsigned char h,
				unsigned char m,
				char value);

	/** Get the root of this tree.
	*/
	inline Node *GetRoot() {return root;};

	/** Should always be called before using Iterate in a loop.
	*/
	void InitIterate();

	/** Each time Iterate is called, it will return a node that
	*	hasn't been returned by the function. Call InitIterate()
	*	to reset the Iteration
	*	@return A pointer to the next node in the tree to iterate, or
	*	NULL if the end of the tree has been reached. 
	*/
	Node *Iterate();

	/**	BinaryTree constructor.
	*	@param aRoot A pointer to the node to put as the tree's root.
	*/
	BinaryTree(Node *aRoot = NULL);
	// Initialize the BinaryTree with root as the first 
	// element in the binary tree.

	~BinaryTree();
private:
	Node *root; // The first element in the binary tree.
	
	Node **stack; 
				 // A stack used for the Iterate method.
				 // stack[0] contains the root
				 // stack[stackPos] contains the currently visited node

	int stackDepth; // The max number of elements in the stack
	int stackPos; // The position of the top element in the stack
};



#endif //BINARY_TREE_H