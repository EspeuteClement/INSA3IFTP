#ifndef	IO_ENGINE_H
#define IO_ENGINE_H
#include "BinaryTree.h"

/** Manages the inputs on the standard input stream and displays the according
* data. It is assumed that the user will issue valid commands, otherwise, they
* will not be excecuted. That is :
* 'yyyy' is the year, an integer.
* 'mm' is the month, an integer.
* 'dd' is the day of the month, an integer.
* 'h' is the hour, integer ranging from 0 to 23 included.
* 'm' is the minute, integer ranging from 0 to 59 included.
* 'd7' is the day of the week, integer ranging from 1 to 7 included.
* 'traffic' is the state of the traffic, one of the characters 'V', 'J', 'R', 'N'.
* 'idSensor' is the primary key of a sensor, an integer;
* 'H_start' is the beginning of the timeframe of a journey, integer ranging from
* 0 to 24.
* 'H_end' is the end of the timeframe of a journey, integer ranging from
* 0 to 24.
* 'seg_count' is the number of road segments of the journey, an integer.
* 'seg_m' is the id of the sensor associated to the m'th segment.
* The maximal value of m must be equal to seg_count.
*/
class IoEngine
{
	public:
		/** Default constructor. Affects the BinaryTree pointer to the attribute.
		* @param tree is a pointer to the BinaryTree we will be using for Sensors
		*/
		IoEngine(BinaryTree *tree);

		/** Reads the input from the standard input stream and calls for the methods
		* associated to the user commands.
		*	@returns true if the user didn't exit, false if the command 'EXIT'
		*	has been issued.
		*/
		bool ReadInput();

		/** Calls the necessary function thats adds the new event to the appropriate
		* sensor and creates the sensor (and the associated node in the binary tree)
		* if they don't exist yet.
		* The expected command is :
		* ADD 'id' 'yyyy' 'mm' 'dd' 'h' 'm' 'd7' 'traffic'
		*
		* 'yyyy', 'mm' and 'dd' are not used.
		*/
		void HandleADD();

		/** Performs the STATS_C operation : displays the statistics for each of the
		* traffic states attributes (v, j, r, n) of a sensor as percentages, one by
		* line. It is assumed the sensor exists or the method will simply exit.
		* The expected command is :
		* STATS_C 'idSensor'
		*/
		void HandleSTATS_C();

		/** Performs the JAM_DH operation : computes and displays the percentage of
		* traffic jam (corresponding to a "r" or "n" traffic state) for each hour
		* (0 to 23) of a given day of the week, averaging from every sensor.
		* The expected command is :
		* JAM_DH 'd7'
		*/
		void HandleJAM_DH();

		/** Performs the STATS_D7 operation : computes and displays the statistics
		* of every traffic state (v, j, r, n) of a given day of the week, averaging
		* from every sensor.
		* The expected command is :
		* STATS_D7 'd7'
		*/
		void HandleSTATS_D7();

		/** Performs the OPT operation : computes and displays the optimal time
		* (which reduces the duration of the journey through the given segments) of
		* departure and the associated minimal duration. It is assumed that every
		* required sensor exists or the method will simply exit.
		* The expected command is :
		* OPT 'd7' 'H_start' 'H_end' 'seg_count' 'seg_1' ... 'seg_n'
		*/
		void HandleOPT();

	private:
		BinaryTree *theTree; /** Pointer to the binary tree that stores the sensors*/

		/* Simple check functions for input values according to the requirements.
		* @param the value to test.
		* @return true if the passed in value doesn't meet the requirements, false
		* if it does.
		*/
		bool checkHour(int hour);
		bool checkHourTimeFrame(int hour);
		bool checkMinute(int minute);
		bool checkD7(int day);
		bool checkTraffic(char traffic);
};
#endif
