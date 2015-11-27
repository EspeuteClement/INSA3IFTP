#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Useful macro that allows to mesure the time that a function takes to execute
// itself.
// USAGE :
// func = the function to test surrounded by ().
// name = a String that contains the name of the function.
#define MESURE_TIME(func,name) {clock_t begin = clock(); \
  func; \
  clock_t end = clock(); \
  cout << "Time taken by " <<name " : "<<double(end-begin)/ CLOCKS_PER_SEC <<" sec\n";}


// Define if you want the displayed info to be fancier.
#define EXTENDED_CONSOLE

/** Small utility library, contains miscellaneous static functions.
*/
class Utils{
public:
	static const string BOLD;
	static const string END_BOLD;
	static const string GREEN;
	static const string RED;
	static const string END_COLOR;

	/** Returns the highest number between a and b
	*	@return a if a > b, or b if b > a
	*/
	static inline long max(long a, long b){return a > b ? a : b;}

	/** Prints out a bold message.
	*	@param message the text to print.
	*	@param r if the function should add a line break at the
	*	end of the print.
	*/
	static void printBold(string message, bool r = false);

	/** Prints out a green message.
	*	@param message the text to print.
	*	@param r if the function should add a line break at the
	*	end of the print.
	*/
	static void printGreen(string message, bool r = false);

	/* Prints out a red message
	*	@param message the text to print.
	*	@param r if the function should add a line break at the
	*	end of the print.
	*/
	static void printRed(string message, bool r = false);

};

#endif //UTILS_H
