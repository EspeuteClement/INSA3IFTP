#include <iostream>
#include "Config.h"
#include "MoteurES.h"
using namespace std;

int main(int nombreArguments, char* arguments[])
{
	MoteurES testMoteur;
	CodeRetourArgument ret = testMoteur.GestionArguments(nombreArguments, arguments);

	if (ret == OK_ARG)
	{
		testMoteur.ParserLog();
		testMoteur.FaireGraphe();
		testMoteur.FermerFichierLog();
	}
	else if(ret == ERR_ARG)
	{
		cout << "Arguments incorrects. Utilisez -h pour l'aide du programme." << endl;
	}
	else if(ret == AIDE_ARG)
	{
		testMoteur.AfficherAide();
	}
}
