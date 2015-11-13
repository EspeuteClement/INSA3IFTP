#include "Utils.h"
#include <string>
#ifdef EXTENDED_CONSOLE
	const string Utils::BOLD = "\e[1m";
	const string Utils::END_BOLD = "\e[21m";
	const string Utils::GREEN = "\e[32m";
	const string Utils::RED = "\e[31m";
	const string Utils::END_COLOR = "\e[39m";
#else //EXTENDED_CONSOLE
	const string Utils::BOLD = "=== ";
	const string Utils::END_BOLD = " ===";
	const string Utils::GREEN = "";
	const string Utils::RED = "";
	const string Utils::END_COLOR = "";
#endif //EXTENDED_CONSOLE


//------------------------------------------------------------------------------
// Public functions and methods
//------------------------------------------------------------------------------
void Utils::printBold(string message, bool r)
{
	cout << Utils::BOLD;
	cout << message;
	cout << Utils::END_BOLD;
	if (r)
	{
		std::cout << '\n';
	}
}

void Utils::printGreen(string message,bool r)
{
	cout << Utils::GREEN;
	cout << message;
	cout << Utils::END_COLOR;
	if (r)
	{
		std::cout << '\n';
	}
}

void Utils::printRed(string message, bool r)
{
	cout << Utils::RED;
	cout << message;
	cout << Utils::END_COLOR;
	if (r)
	{
		std::cout << '\n';
	}
}
