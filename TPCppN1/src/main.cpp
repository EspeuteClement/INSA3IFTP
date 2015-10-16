#include <iostream>

#include "Collection.h"


const int TAILLE_TEST = 20; // Taille qui sera allouée lors du test de taille et du redimentionnement
const char BOLD_SYMBOL[] = "\033[1m"; // Code terminal pour afficher les caractères en gras
const char END_SYMBOL[] = "\033[0m"; // Code terminal pour annuler la mise en forme

int main()
{	
	//Création de la classe
	std::cout <<BOLD_SYMBOL<< "Test du constructeur par défaut\n"<<END_SYMBOL;
	Collection collectionTest(TAILLE_TEST/2);
	// Test pour voir si le tableau fait la bonne taille
	collectionTest.Afficher();

	std::cout <<BOLD_SYMBOL<< "Test du constructeur avec un tableau\n"<<END_SYMBOL;
	int leTableau[] = {100,200,300,400,500,600,700,800,900,999};
	Collection collectionReunir(10,leTableau);
	collectionReunir.Afficher();

	// Ajout de 20 éléments dans le tableau
	for (int i = 0; i < TAILLE_TEST; ++i)
	{	collectionTest.Ajouter(i);
	}

	//Vérification de la cohérence des données (doit être cohérent à la taille alouée)
	collectionTest.Afficher();

	std::cout <<BOLD_SYMBOL<< "Test de réajustement trop petit\n"<<END_SYMBOL;
	if(collectionTest.Ajuster(TAILLE_TEST - 1))
	{	std::cout << "ça aurait du planter !!!\n";
	}
	else
	{	std::cout << "Le réajustement à bien échoué\n";
	}

	std::cout <<BOLD_SYMBOL<< "Test de réajustement normal\n"<<END_SYMBOL;
	if(collectionTest.Ajuster(50))
	{	std::cout << "Réajustement réussi\n";
	}
	else
	{	std::cout << "Le réajustement échoué, pas normal\n";
	}

	// ============ RETIRER ===========
	std::cout << BOLD_SYMBOL << "Test de supprésion de données : On supprime " << TAILLE_TEST/2 << " Elements\n"<<END_SYMBOL;
	for (int i = 0; i < TAILLE_TEST/2; ++i)
	{	collectionTest.Retirer(TAILLE_TEST-i-1,1);
	}
	collectionTest.Afficher();	

	// ============= RERIRER MULTIPLE ==
	Collection collectionRetirer(5);
	for (int i = 0; i < 10; ++i)
	{	collectionRetirer.Ajouter(8);
	}
	std::cout << BOLD_SYMBOL << "Test de suppression mutiple : Collection de base \n" <<END_SYMBOL;

	collectionRetirer.Afficher();

	std::cout << BOLD_SYMBOL << "Test de suppression mutiple : Suppression de 3 éléments \n" <<END_SYMBOL;
	collectionRetirer.Retirer(8,3);
	collectionRetirer.Afficher();

	std::cout << BOLD_SYMBOL << "Test de suppression mutiple : Suppression du reste des éléments \n" <<END_SYMBOL;
	collectionRetirer.Retirer(8,-1);
	collectionRetirer.Afficher();

	// ============ REUNIR =============
	std::cout << BOLD_SYMBOL << "Test de Réunir :\n" << END_SYMBOL; 

	std::cout << BOLD_SYMBOL << "Collection 1\n" << END_SYMBOL;
	collectionTest.Afficher();
	std::cout << BOLD_SYMBOL << "Collection 2\n" << END_SYMBOL;
	collectionReunir.Afficher();

	std::cout << BOLD_SYMBOL << "Reunion des Collection : (Collection 1 + 2)\n" << END_SYMBOL;
	collectionTest.Reunir(collectionReunir);
	collectionTest.Afficher();
}