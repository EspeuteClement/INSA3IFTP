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
		cout << "-----------------------------------------------" << endl;
		cout << "----------Test de la classe <Fichier>----------" << endl;
		cout << "-----------------------------------------------" << endl << "\n";

		cout << "----------Création d'un fichier /blog/index.html----------" << endl;
		string nomFichier1 = "/blog/index.html";
		Fichier * fichier1 = new Fichier(nomFichier1);
		cout << fichier1->GetChemin() << endl << "\n";

		cout << "----------Création d'un fichier /yolo/index.html----------" << endl;
		string nomFichier2 = "/yolo/index.html";
		Fichier * fichier2 = new Fichier(nomFichier2);
		cout << fichier2->GetChemin() << endl << "\n";

		cout << "----------AjouterVisite depuis /yolo/index.html dans /blog/index.html----------" << endl;
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		fichier1->AjouterVisite(fichier2);
		cout << "Nombre de hits de blog depuis yolo (on veut 5) : " << fichier1->GetHits(fichier2) << endl << "\n";

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
		cout << "Chemin de /blog/index.html : " << site->GetFichier(cheminDestination1)->GetChemin() << endl;
		cout << "Chemin de /blog/view.php : " << site->GetFichier(cheminDestination2)->GetChemin() << endl << "\n";

		cout << "Nombre de hits de /blog/index.html depuis externe (on veut 2) : " <<
			site->GetFichier(cheminDestination1)->GetHits(site->GetExterne()) << endl << "\n";
		cout << "Nombre de hits de /blog/view.php depuis externe (on veut 1) : " <<
			site->GetFichier(cheminDestination2)->GetHits(site->GetExterne()) << endl << "\n";

		cout << "----------Ajout de visites venant de l'intérieur----------" << endl;
		string cheminSource1 = "/moodle/index.html";
		string cheminSource2 = "/gradle/view.php";
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource1, cheminDestination1);
		site->AjouterVisite(cheminSource2, cheminDestination2);
		site->AjouterVisite(cheminSource2, cheminDestination2);
		cout << "Chemin de /moodle/index.html : " << site->GetFichier(cheminSource1)->GetChemin() << endl;
		cout << "Chemin de /gradle/view.php : " << site->GetFichier(cheminSource2)->GetChemin() << endl << "\n";

		cout << "Nombre de hits de /blog/index.html depuis /moodle/index.html (on veut 3) : " <<
			site->GetFichier(cheminDestination1)->GetHits(site->GetFichier(cheminSource1)) << endl;
		cout << "Nombre de hits de /blog/view.php depuis /gradle/view.php (on veut 2) : " <<
			site->GetFichier(cheminDestination2)->GetHits(site->GetFichier(cheminSource2)) << endl;

		delete site;
		cout << "-----------------------------------------------" << endl;

		return 0;
}
*/
