#include <iostream>

#include "Collection.h"


const int TAILLE_TEST = 20; // Taille qui sera allouée lors du test de taille et du redimentionnement
const char BOLD_SYMBOL[] = "\033[1m"; // Code terminal pour afficher les caractères en gras
const char END_SYMBOL[] = "\033[0m"; // Code terminal pour annuler la mise en forme

int main()
{	
	//Création de la classe 
	Collection collectionTest(TAILLE_TEST/2);
	// Test pour voir si le tableau fait la bonne taille
	collectionTest.Afficher();

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



}