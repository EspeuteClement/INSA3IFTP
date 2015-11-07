#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
// define if you want pretty
#define EXTENDED_CONSOLE
using namespace std;

/** Small utility library, contains some maths static functions
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

	/** Prints a bold message.
	*	@param message the text to print
	*	@param r if the function should add a line break at the
	*	end of the print.
	*/
	static inline void printBold(string message, bool r = false)
	{
		cout << BOLD;
		cout << message;
		cout << END_BOLD;
		if (r)
		{
			std::cout << '\n';
		}

	};

	static inline void printGreen(string message, bool r = false)
	{
		cout << GREEN;
		cout << message;
		cout << END_COLOR;
		if (r)
		{
			std::cout << '\n';
		}

	};

	static inline void printRed(string message, bool r = false)
	{
		cout << RED;
		cout << message;
		cout << END_COLOR;
		if (r)
		{
			std::cout << '\n';
		}

	};
};




#endif //UTILS_H
