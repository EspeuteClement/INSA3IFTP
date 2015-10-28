#ifndef BINARY_TREE_H
#define BINRAY_TREE_H

#include "Node.h"
#include "Sensor.h"

class BinaryTree{
public:
	Sensor *Search(long ID);
	// Returns the sensor that has it's id matching ID.

	void Add(Sensor *sensor);
	// Add a sensor in the tree, creating a node.

	void Display();
	// Draw the binary tree

	void GetDepth();

	void Insert(int ID);

	BinaryTree(Node *aRoot);
	// Initialize the BinaryTree with root as the first 
	// element in the binary tree.

	~BinaryTree();
private:
	Node *root; // The first element in the binary tree.
};



#endif //BINARY_TREE_H