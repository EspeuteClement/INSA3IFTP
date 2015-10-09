#include <iostream>

#include "Collection.h"

int main()
{	
	//Création de la classe 
	Collection collectionTest(10);
	collectionTest.Afficher();
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);

	collectionTest.Afficher();
	std::cout << "Patate";
	collectionTest.Ajuster(50);
	collectionTest.Ajuster(20);
}