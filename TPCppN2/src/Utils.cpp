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