/*
#include <iostream>
#include "Config.h"
#include "MoteurES.h"
using namespace std;
int main(int nombreArguments, char* arguments[])
{
	MoteurES testMoteur;

	cout<<testMoteur.OuvrirFichierLog("")<<endl;
}
*/

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

		return 0;
}
