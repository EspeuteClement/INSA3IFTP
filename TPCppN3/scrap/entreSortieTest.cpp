#include <iostream>
#include "Config.h"
using namespace std;
int main(int nombreArguments, char* arguments[])
{
	// switch(nombreArguments){
	// 	case 1:
	// 	cout << "Hello world !\n";
	// 	break;
	// 	case 2:
	// 	string S (arguments[1]);
	// 	cout << "Hello " << S << " !\n";
	// 	break;
	// }
	bool vulgarOption = false;
	string nom = "";

	//Lire la liste des args
	for (int argumentParse = 1; argumentParse < nombreArguments; argumentParse ++)
	{
		if (arguments[argumentParse][0] == '-')
		{
			// Gérér le cas des options
			switch (arguments[argumentParse][1]){
				case 'v':
				vulgarOption = true;
				break;
				case 'n':
				// Récuperer le prochain nom
				argumentParse++;
				if (argumentParse < nombreArguments) {
					nom = arguments[argumentParse];
				}
				break;
			}
		}
	}

	// Imprimer le hello world
	if (vulgarOption)
	{
		cout << "Fucking ";
	}
	cout << "Hello ";
	if (nom.length() > 0)
	{
		cout << nom;
	}
	else
	{
		cout << "World";
	}
	cout << " !\n";

}