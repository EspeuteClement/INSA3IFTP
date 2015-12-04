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

/*
#include <string>
#include <iostream>
#include "Fichier.h"
#include "Site.h"
using namespace std;

int main()
{
		// Nécessite de faire passer les attributs de <Fichier> en public
		cout << "-----------------------------------------------" << endl;
		cout << "----------Test de la classe <Fichier>----------" << endl;
		cout << "-----------------------------------------------" << endl;

		cout << "----------Création d'un fichier /blog/index.html----------" << endl;
		string nomFichier1 = "/blog/index.html";
		Fichier * fichier1 = new Fichier(nomFichier1);
		cout << fichier1->chemin << endl;

		cout << "----------Création d'un fichier /yolo/index.html----------" << endl;
		string nomFichier2 = "/yolo/index.html";
		Fichier * fichier2 = new Fichier(nomFichier2);
		cout << fichier2->chemin << endl;

		cout << "----------AjouterVisite depuis /yolo/index.html dans /blog/index.html----------" << endl;
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		cout << "Nombre de hits de blog depuis yolo (on veut 5) : " << fichier1->hits[fichier2] << endl;

		delete fichier1;
		delete fichier2;
		cout << "-----------------------------------------------" << endl;

		// Nécessite de faire passer les attributs de <Site> en public
		cout << "-----------------------------------------------" << endl;
		cout << "----------Test de la classe <Site>----------" << endl;
		cout << "-----------------------------------------------" << endl;

		cout << "----------Création d'un site intranet-if.insa-lyon.fr----------" << endl;
		string nomSite = "intranet-if.insa-lyon.fr";
		Site * site = new Site(nomSite);
		cout << site->adresse << endl;

		cout << "----------Ajout de visites venant de l'extérieur----------" << endl;
		string cheminDestination1 = "/blog/index.html";
		string cheminDestination2 = "/blog/view.php";
		site->AjouterVisite(cheminDestination1);
		site->AjouterVisite(cheminDestination1);
		site->AjouterVisite(cheminDestination2);
		cout << "Chemin de /blog/index.html : " << site->Trouver(cheminDestination1)->chemin << endl;
		cout << "Chemin de /blog/view.php : " << site->Trouver(cheminDestination2)->chemin << endl;

		cout << "Nombre de hits de /blog/index.html depuis externe (on veut 2) : " <<
			site->Trouver(cheminDestination1)->hits[site->fichierExterne] << endl;
		cout << "Nombre de hits de /blog/view.php depuis externe (on veut 1) : " <<
			site->Trouver(cheminDestination2)->hits[site->fichierExterne] << endl;

		cout << "----------Ajout de visites venant de l'intérieur----------" << endl;
		string cheminSource1 = "/moodle/index.html";
		string cheminSource2 = "/gradle/view.php";
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource2, cheminDestination2);
		site->AjouterVisite(cheminSource2, cheminDestination2);
		cout << "Chemin de /moodle/index.html : " << site->Trouver(cheminSource1)->chemin << endl;
		cout << "Chemin de /gradle/view.php : " << site->Trouver(cheminSource2)->chemin << endl;

		cout << "Nombre de hits de /blog/index.html depuis /moodle/index.html (on veut 3) : " <<
			site->Trouver(cheminDestination1)->hits[site->fichiers[cheminSource1]] << endl;
		cout << "Nombre de hits de /blog/view.php depuis /gradle/view.php (on veut 2) : " <<
			site->Trouver(cheminDestination2)->hits[site->fichiers[cheminSource2]] << endl;

		delete site;
		cout << "-----------------------------------------------" << endl;

		return 0;
}
*/

