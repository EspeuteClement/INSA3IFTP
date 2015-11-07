#ifndef	IO_ENGINE_H
#define IO_ENGINE_H
#include "BinaryTree.h"

/** Manages the inputs on the standard input stream and displays the according
* data.
*/
class IoEngine
{
	public:
		/** Default constructor. Affects the BinaryTree pointer to the attribute.
		* @param tree is a pointer to the BinaryTree we will be using for Sensors
		*/
		IoEngine(BinaryTree *tree);

		/** Reads the input from the STDIO and modify the tree if needed
		*	@returns true if the user didn't exit, false if the command 'EXIT'
		*	has been issued.
		*/
		bool ReadInput();

		// TODO Write proper documentation for this function.
		void HandleADD();

		/** Performs the STATS_C operation : displays the statistics for each of the
		* traffic states attributes (v, j, r, n) of a sensor as percentages, one by
		* line;
		*/
		void HandleSTATS_C();

		/** Performs the JAM_DH operation : computes and displays the percentage of
		* traffic jam (corresponding to a "r" or "n" traffic state) for each hour
		* (0 to 23) of a given day of the week, averaging from every sensor.
		*/
		void HandleJAM_DH();

		/** Performs the STATS_D7 operation : computes and displays the statistics
		* of every traffic state (v, j, r, n) of a given day of the week, averaging
		* from every sensor.
		*/
		void HandleSTATS_D7();

		void HandleOPT();

	private:
		BinaryTree *theTree;
};
#endif
