#include <iostream>

#include "Collection.h"

using namespace std;
const int TAILLE_TEST = 20; // Taille qui sera allouée lors du test de taille et du redimensionnement


#define BOLD_USAGE
// POUR AFFIHCER DU GRAS DANS LA CONSOLE (POUR LES TESTS)
#ifdef BOLD_USAGE
	const char BOLD_SYMBOL[] = "\033[1m"; // Code terminal pour afficher les caractères en gras
	const char END_SYMBOL[] = "\033[0m"; // Code terminal pour annuler la mise en forme
#else
	const char BOLD_SYMBOL[] = ""; // Code terminal pour afficher les caractères en gras
	const char END_SYMBOL[] = ""; // Code terminal pour annuler la mise en forme
#endif //BOLD_USAGE

int main()
{
	//Création de la classe
	cout <<BOLD_SYMBOL<< "======= TEST 1 : CONSTRUCTEURS ======\n\n"<<END_SYMBOL;
	cout <<BOLD_SYMBOL<< "Test du constructeur par défaut\n"<<END_SYMBOL;
	Collection collectionTest(TAILLE_TEST/2);
	// Test pour voir si le tableau fait la bonne taille
	collectionTest.Afficher();

	cout <<BOLD_SYMBOL<< "Test du constructeur avec un tableau\n"<<END_SYMBOL;
	int leTableau[] = {100,200,300,400,500,600,700,800,900,999};
	Collection collectionReunir(10,leTableau);
	collectionReunir.Afficher();

	cout <<BOLD_SYMBOL<< "======= TEST 2 : AJOUTER ======\n\n"<<END_SYMBOL;
	// Ajout de 20 éléments dans le tableau
	for (int i = 0; i < TAILLE_TEST; ++i)
	{	collectionTest.Ajouter(i);
	}

	//Vérification de la cohérence des données (doit être cohérent à la taille alouée)
	collectionTest.Afficher();

	cout <<BOLD_SYMBOL<< "======= TEST 3 : RETIRER ======\n\n"<<END_SYMBOL;
	// ============ RETIRER ===========
	cout << BOLD_SYMBOL << "Test de suppression de données : On supprime " << TAILLE_TEST/2 << " Elements\n"<<END_SYMBOL;
	for (int i = 0; i < TAILLE_TEST/2; ++i)
	{	collectionTest.Retirer(TAILLE_TEST-i-1,1);
	}
	collectionTest.Afficher();

	// ============= RETIRER MULTIPLE ==
	Collection collectionRetirer(5);
	for (int i = 0; i < 10; ++i)
	{	collectionRetirer.Ajouter(8);
	}
	cout << BOLD_SYMBOL << "Test de suppression mutiple : Collection d'origine \n" <<END_SYMBOL;

	collectionRetirer.Afficher();

	cout << BOLD_SYMBOL << "Test de suppression mutiple : Suppression de 3 éléments \n" <<END_SYMBOL;
	collectionRetirer.Retirer(8,3);
	collectionRetirer.Afficher();

	cout << BOLD_SYMBOL << "Test de suppression mutiple : Suppression du reste des éléments \n" <<END_SYMBOL;
	collectionRetirer.Retirer(8,-1);
	collectionRetirer.Afficher();

	cout <<BOLD_SYMBOL<< "======= TEST 4 : AJUSTER ======\n\n"<<END_SYMBOL;

	cout <<BOLD_SYMBOL<< "Test de réajustement trop petit\n"<<END_SYMBOL;
	if(collectionTest.Ajuster(TAILLE_TEST - 1))
	{	cout << "Ça aurait du planter !!!\n";
	}
	else
	{	cout << "Le réajustement a bien échoué\n";
	}

	cout <<BOLD_SYMBOL<< "Test de réajustement normal\n"<<END_SYMBOL;
	if(collectionTest.Ajuster(50))
	{	cout << "Réajustement réussi\n";
	}
	else
	{	cout << "Le réajustement a échoué, pas normal\n";
	}

	cout <<BOLD_SYMBOL<< "======= TEST 5 : REUNIR ======\n\n"<<END_SYMBOL;

	// ============ REUNIR =============
	cout << BOLD_SYMBOL << "Test de Réunir :\n" << END_SYMBOL;

	cout << BOLD_SYMBOL << "Collection 1\n" << END_SYMBOL;
	collectionTest.Afficher();
	cout << BOLD_SYMBOL << "Collection 2\n" << END_SYMBOL;
	collectionReunir.Afficher();

	cout << BOLD_SYMBOL << "Réunion des Collections : (Collection 1 + 2)\n" << END_SYMBOL;
	collectionTest.Reunir(collectionReunir);
	collectionTest.Afficher();
}
