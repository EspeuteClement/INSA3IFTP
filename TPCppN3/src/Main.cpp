#include <iostream>
#include "Config.h"
#include "MoteurES.h"
using namespace std;

int main(int nombreArguments, char* arguments[])
{
	MoteurES testMoteur;
	vector<string> bl = vector<string>();
	bl.push_back("html");
	bl.push_back("php");
	testMoteur.ModifierMatchs(bl,11);
	cout<<testMoteur.OuvrirFichierLog("log/anonyme.log")<<endl;
	DonneesLog resultat("",0,"","","",END_FILE);
	do
	{
		resultat = testMoteur.LireLigneLog();
		if(resultat.Etat == OK)
		{
			cout << resultat.FichierDestination<< endl;
		}
	} while(resultat.Etat != END_FILE);

	testMoteur.FermerFichierLog();
}