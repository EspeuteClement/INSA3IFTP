#include <iostream>

#include "Collection.h"

int main()
{	
	Collection maCol(10);
	maCol.Ajouter(5);
	maCol.Ajouter(10);
	maCol.Afficher();
	maCol.Ajuster(50);
	maCol.Ajuster(20);
}