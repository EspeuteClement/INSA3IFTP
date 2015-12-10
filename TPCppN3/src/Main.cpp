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

/*
#include <string>
#include <iostream>
#include "Fichier.h"
#include "Site.h"
using namespace std;

int main()
{
		cout << "-----------------------------------------------" << endl;
		cout << "----------Test de la classe <Fichier>----------" << endl;
		cout << "-----------------------------------------------" << endl << "\n";

		cout << "----------Création d'un fichier /blog/index.html----------" << endl;
		string nomFichier1 = "/blog/index.html";
		Fichier * fichier1 = new Fichier(nomFichier1);

		cout << "----------Création d'un fichier /yolo/index.html----------" << endl;
		string nomFichier2 = "/yolo/index.html";
		Fichier * fichier2 = new Fichier(nomFichier2);

		cout << "----------AjouterVisite depuis /yolo/index.html dans /blog/index.html----------" << endl;
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		cout << "Test GetChemin() sur fichier1 (attendu : /blog/index.html) : " << fichier1->GetChemin() << endl;
		cout << "Test GetHits() sur fichier1 (attendu : 5) : " << fichier1->GetHits() << endl;

		delete fichier1;
		delete fichier2;
		cout << "-----------------------------------------------" << endl << "\n";


		cout << "-----------------------------------------------" << endl;
		cout << "----------Test de la classe <Site>----------" << endl;
		cout << "-----------------------------------------------" << endl << "\n";

		cout << "----------Création d'un site intranet-if.insa-lyon.fr----------" << endl;
		string nomSite = "intranet-if.insa-lyon.fr";
		Site * site = new Site(nomSite);
		cout << site->GetAdresse() << endl << "\n";

		cout << "----------Ajout de visites venant de l'extérieur----------" << endl;
		string cheminDestination1 = "/blog/index.html";
		string cheminDestination2 = "/blog/view.php";
		site->AjouterVisite(cheminDestination1);
		site->AjouterVisite(cheminDestination1);
		site->AjouterVisite(cheminDestination2);

		cout << "----------Ajout de visites venant de l'intérieur----------" << endl;
		string cheminSource1 = "/moodle/index.html";
		string cheminSource2 = "/gradle/view.php";
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource2, cheminDestination2);
		site->AjouterVisite(cheminSource2, cheminDestination2);

		delete site;
		cout << "-----------------------------------------------" << endl;

		return 0;
}
*/
