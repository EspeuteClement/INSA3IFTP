#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Node.h"
#include "Sensor.h"

class BinaryTree{
public:
	/** Get the sensor where ID equals the sensor sensor ID
	*	@return A pointer to the sensor
	*/
	Sensor *Search(long ID);

	/** Prints a serialized form of the binary tree in the standard output.
	*	The serialization takes the form of a lua table, so it can be
	*	parsed by an external vizualizer. Check Node::Serialize for mode info
	*/
	void Serialize();

	// TODO : ADD THE OTHER INFO 
	/**	Insert data in the tree.
	*	@param ID The id of the sensor where the data should be stored. If
	*	the sensor doesn't exists, it will be created.
	*/
	void Insert(int ID, 
				unsigned char d,
				unsigned char h,
				unsigned char m,
				unsigned char value);

	/** Get the root of this tree
	*	@param a pointer to this tree's root.
	*/
	inline Node *GetRoot() {return root;};

	/** Should always called before using Iterate in a loop.
	*/
	void InitIterate();

	/** Each time Iterate is called, it will retrun a node that
	*	hasn't been returned by the function. Call InitIterate()
	*	 to reset the Iteration
	*/
	Node *Iterate();

	/**	BinaryTree constructor.
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
				 // stack[stackPos] contains the curently visited node

	int stackDepth; // The max number of elements in the stack
	int stackPos; // The position of the top element in the stack
};



#endif //BINARY_TREE_H