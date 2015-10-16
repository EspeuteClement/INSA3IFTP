#include <iostream>
#include "main.h"
#include "Collection.h"

using namespace std;
const int TAILLE_TEST = 20; // Taille qui sera allouée lors du test de taille et du redimensionnement



// POUR AFFIHCER DU GRAS DANS LA CONSOLE (POUR LES TESTS)


int main()
{
	testConstructeur();

	testAjouter();

	testAjuster();

	testRetirer();

	

	// cout <<BOLD_SYMBOL<< "\n======= TEST 5 : REUNIR ======\n\n"<<END_SYMBOL;

	// // ============ REUNIR =============
	// cout << BOLD_SYMBOL << "Test de Réunir :\n" << END_SYMBOL;
	// collectionTest.Ajuster(50);
	// cout << BOLD_SYMBOL << "Collection 1\n" << END_SYMBOL;
	// collectionTest.Afficher();
	// cout << BOLD_SYMBOL << "Collection 2\n" << END_SYMBOL;
	// collectionReunir.Afficher();

	// cout << BOLD_SYMBOL << "Réunion des Collections : (Collection 1 + 2)\n" << END_SYMBOL;
	// collectionTest.Reunir(collectionReunir);
	// collectionTest.Afficher();
}

void testConstructeur()
{
	//Création de la classe
	printTitre("TEST 1 : CONSTRUCTEUR");
	printGras("Construceur de base");
	Collection collectionTest(TAILLE_TEST/2);
	// Test pour voir si le tableau fait la bonne taille
	collectionTest.Afficher();

	printGras("Test du constructeur avec tableau");
	int leTableau[] = {100,200,300,400,500,600,700,800,900,999};
	Collection collectionReunir(10,leTableau);
	collectionReunir.Afficher();

}

void testAjouter()
{
	// Initialisation du talbeau
	printTitre("TEST 2 : AJOUTER");
	printGras("Tableau de base :");
	Collection collectionTest(0);
	collectionTest.Afficher();
	// Ajout de 20 éléments dans le tableau
	for (int i = 0; i < TAILLE_TEST; ++i)
	{	collectionTest.Ajouter(i);
	}

	//Vérification de la cohérence des données (doit être cohérent à la taille alouée)
	printGras("Tableau après l'ajout de 20 éléments:");
	collectionTest.Afficher();
}

void testAjuster()
{
	printTitre("TEST 3 : AJUSTER");

	printGras("Création d'un tableau de taille 10 et population avec 5 éléments");
	Collection collectionTest(10);
	for (int i = 0; i < 5; ++i)
	{	collectionTest.Ajouter(i);
	}
	collectionTest.Afficher();
	printGras("Test de réajustement dans le cas où nbElement > nouvelleTaille");
	printGras("(de 10 à 4 de taille alouée avec 5 éléments)");
	if(collectionTest.Ajuster(4))
	{	cout << "(ERREUR !) Le réajustement a réusi alors qu'il aurait du échouer\n";
	}
	else
	{	cout << "Le réajustement a bien échoué\n";
	}
	collectionTest.Afficher();
	

	printGras("Test de réajustement dans avec la nouvelle taille plus grande que l'ancienne ");
	printGras("(De 10 à 20 de taille allouée)");
	if(collectionTest.Ajuster(20))
	{	cout << "Réajustement réussi\n";
	}
	else
	{	cout << "(ERREUR !) Le réajustement a échoué\n";
	}
	collectionTest.Afficher();

	
	printGras("Test de réajustement dans avec la nouvelle taille plus petite que l'ancienne ");
	if(collectionTest.Ajuster(15))
	{	cout << "Réajustement réussi\n";
	}
	else
	{	cout << "(ERREUR !) Le réajustement a échoué\n";
	}
	collectionTest.Afficher();
}

void testRetirer()
{
	printTitre("TEST 4 : RETIRER");
	// Initialisation du tableau
	printGras("Tableau initial :");
	int tabBase[] = {
		1,
		42,
		1,
		42,
		8,
		4,
		42,
		42,
		42,
		1,
		8,
		9,
		42,
		42,
		8,
		7,
		3,
		42,
		8
	};

	Collection collectionTest(19,tabBase);
	collectionTest.Afficher();

	printGras("On retire 1 élément 42");
	collectionTest.Retirer(42,1);
	collectionTest.Afficher();

	printGras("On retire 4 éléments 42");
	collectionTest.Retirer(42,4);
	collectionTest.Afficher();

	printGras("On retire le reste des éléments 42");
	collectionTest.Retirer(42,-1);
	collectionTest.Afficher();

	printGras("On retire le reste des éléments du tableau");
	for (int i = 0; i < 10; ++i)
	{
		collectionTest.Retirer(i,-1);
	}
	collectionTest.Afficher();
}