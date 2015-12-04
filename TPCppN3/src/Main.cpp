#include <iostream>
#include "Config.h"
#include "MoteurES.h"
using namespace std;
int main(int nombreArguments, char* arguments[])
{
	MoteurES testMoteur;

	cout<<testMoteur.OuvrirFichierLog("")<<endl;
}