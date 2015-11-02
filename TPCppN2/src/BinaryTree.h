#ifndef BINARY_TREE_H
#define BINRAY_TREE_H

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
	void Insert(int ID);

	/**	BinaryTree constructor.
	*/
	BinaryTree(Node *aRoot);
	// Initialize the BinaryTree with root as the first 
	// element in the binary tree.

	~BinaryTree();
private:
	Node *root; // The first element in the binary tree.
};



#endif //BINARY_TREE_H