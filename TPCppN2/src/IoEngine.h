#ifndef	IO_ENGINE_H
#define IO_ENGINE_H
#include "BinaryTree.h"
class IoEngine{
public:
	
	/** Read the input from the STDIO and modify the tree if needed
	*	@returns true if the user hasn't quited, false if the command 'EXIT'
	*	has been issued.
	*/
	bool ReadInput();

	/** Performs the ADD operation.
	*/
	void HandleADD();

	/** Performs the STATS_C operation : print the global status of the
	*	sensor in percentage.
	*/
	void HandleSTATS_C();

	void HandleJAM_DH();

	IoEngine(BinaryTree *tree);
private:
	BinaryTree *theTree;
};
#endif