#include <iostream>

#include "Collection.h"

int main()
{	
	//Création de la classe 
	Collection collectionTest(10);
	collectionTest.PrintNbElements();

	collectionTest.Ajouter(5);
	collectionTest.Ajouter(10);
	collectionTest.PrintNbElements();
	
	collectionTest.Afficher();
	collectionTest.Ajuster(50);
	collectionTest.Ajuster(20);
}