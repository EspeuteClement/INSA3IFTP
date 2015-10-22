// NOTE : Normalement
void testAjuster1()
{
	printTitre("TEST 3 : AJUSTER");
	// TESTER SI LE REDIMENTIONNAGE AVEC UNE TAILLE TROP FAIBLE NE MARCHE PAS

	printGras("Création d'une collection de taille 10 et population avec 5 éléments");
	Collection collectionTest(10);
	for (int i = 0; i < 5; ++i)
	{	collectionTest.Ajouter(i);
	}
	collectionTest.Afficher();
	printGras("Test de réajustement dans le cas où nbElement > nouvelleTaille");
	printGras("(de 10 à 4 de taille alouée avec 5 éléments)");
	if(collectionTest.Ajuster(4))
	{	cout << "(ERREUR !) Le réajustement a réussi alors qu'il aurait du échouer\n";
	}
	else
	{	cout << "Le réajustement a bien échoué\n";
	}
	collectionTest.Afficher();
}

void testAjuster2()
{
	printGras("Test de réajustement dans avec la nouvelle taille plus grande que l'ancienne ");
	printGras("(De 10 à 20 de taille allouée)");

	printGras("Création d'une collection de taille 10 et population avec 5 éléments");
	Collection collectionTest(10);
	for (int i = 0; i < 5; ++i)
	{	collectionTest.Ajouter(i);
	}
	collectionTest.Afficher();

	if(collectionTest.Ajuster(20))
	{	cout << "Réajustement réussi\n";
	}
	else
	{	cout << "(ERREUR !) Le réajustement a échoué\n";
	}
	collectionTest.Afficher();
}

void testAjuster3()
{
	// Redimensionnement de la collection dans le cas où nouvelleTaille < alloue
	printGras("Test de réajustement avec la nouvelle taille plus petite que l'ancienne ");
	printGras("(De 20 à 10 de taille allouée)");
	printGras("Création d'une Collection de taille 20 et population avec 5 éléments");
	Collection collectionTest(20);
	for (int i = 0; i < 5; ++i)
	{	collectionTest.Ajouter(i);
	}
	collectionTest.Afficher();
	if(collectionTest.Ajuster(10))
	{	cout << "Réajustement réussi\n";
	}
	else
	{	cout << "(ERREUR !) Le réajustement a échoué\n";
	}
	collectionTest.Afficher();
}
