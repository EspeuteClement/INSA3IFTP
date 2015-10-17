#include <iostream>
#include "main.h"
#include "Collection.h"

using namespace std;
const int TAILLE_TEST = 20; // Taille qui sera allouée lors du test de taille et du redimensionnement



// POUR AFFIHCER DU GRAS DANS LA CONSOLE (POUR LES TESTS)


int main()
{
	testConstructeur2_1();
	testConstructeur2_2();
	testConstructeur2_3();
	// testAjouter();

	// testAjuster1();
	// testAjuster2();
	// testAjuster3();

	// testRetirer1();
	// testRetirer2();
	// testRetirer3();
	// testRetirer4();
	// testRetirer5();

	// testReunir1();
	// testReunir2();
	// testReunir3();
}

void testConstructeur1()
{
	//Création de la classe
	printTitre("TEST CONSTRUCTEUR : CONSTRUCTEUR 1");
	printGras("Construceur de base");
	Collection collectionTest(TAILLE_TEST/2);
	// Test pour voir si la Collection fait la bonne taille
	collectionTest.Afficher();

	

}

void testConstructeur2_1(){
	printTitre("TEST CONSTRUCTEUR : CONSTRUCTEUR 2");
	printGras("Test du constructeur avec tableau");
	int leTableau[] = {100,200,300,400,500,600,700,800,900,999};
	Collection collectionReunir(10,leTableau);
	collectionReunir.Afficher();
}

void testConstructeur2_2(){
	printGras("Test du constructeur avec tableau vide");
	int leTableau[] = {};
	Collection collectionReunir(0,leTableau);
	collectionReunir.Afficher();
}

void testConstructeur2_3(){
	printGras("Test du constructeur avec tableau, et nbElements inférieur à la taille du tableau");
	int leTableau[] = {100,200,300,400,500,600,700,800,900,999};
	Collection collectionReunir(5,leTableau);
	collectionReunir.Afficher();
}

void testAjouter()
{
	// Initialisation du talbeau
	printTitre("TEST 2 : AJOUTER");
	printGras("Collection de base :");
	Collection collectionTest(0);
	collectionTest.Afficher();
	// Ajout de 20 éléments dans le tableau
	for (int i = 0; i < TAILLE_TEST; ++i)
	{	collectionTest.Ajouter(i);
	}

	//Vérification de la cohérence des données (doit être cohérent à la taille alouée)
	printGras("Collection après l'ajout de 20 éléments:");
	collectionTest.Afficher();
}

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
	{	cout << "(ERREUR !) Le réajustement a réusi alors qu'il aurait du échouer\n";
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
	// Redimentionnement de la collection dans le cas où nouvelleTaille < alouée
	printGras("Test de réajustement dans avec la nouvelle taille plus petite que l'ancienne ");
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



void testRetirer1()
{
	printTitre("TEST 4 : RETIRER");
	// Initialisation de la collection
	printGras("Collection initiale :");
	int tabBase[] = {
			1,42,1,42,8,4,42,42,42,1,8,9,42,42,8,7,3,42,8
		};

	Collection collectionTest(19,tabBase);
	collectionTest.Afficher();

	printGras("On retire 1 élément 42");
	collectionTest.Retirer(42,1);
	collectionTest.Afficher();
}

void testRetirer2()
{
	// Retirer plus d'un seul élément
	printGras("On retire 4 éléments 42");
	printGras("Collection initiale :");
	int tabBase[] = {
			1,42,1,42,8,4,42,42,42,1,8,9,42,42,8,7,3,42,8
		};

	Collection collectionTest(19,tabBase);
	collectionTest.Afficher();

	// Le test à proprement parler

	
	collectionTest.Retirer(42,4);
	collectionTest.Afficher();
}

void testRetirer3()
{ 	// Retirer tout les éléments d'une valeur donnée
	printGras("On retire tous les éléments 42");
	printGras("Collection initiale :");
		int tabBase[] = {
			1,42,1,42,8,4,42,42,42,1,8,9,42,42,8,7,3,42,8
		};

	Collection collectionTest(19,tabBase);
	collectionTest.Afficher();

	// Le test à proprement parler

	printGras("Collection après Retirer(42,-1)");
	collectionTest.Retirer(42,-1);
	collectionTest.Afficher();
}

void testRetirer4()
{
	// Supréssion d'une valeur non comprise dans la Collection
	printGras("On retire une valeur non présente dans la Collection (100)");
	printGras("Collection initiale :");
		int tabBase[] = {
			1,42,1,42,8,4,42,42,42,1,8,9,42,42,8,7,3,42,8
		};

	Collection collectionTest(19,tabBase);
	collectionTest.Afficher();

	printGras("Collection après Retirer(100,-1)");
	
	collectionTest.Retirer(100,-1);
	collectionTest.Afficher();
}

void testRetirer5()
{
	// Supréssion de toutes les valeurs :
	int tabBase[] = {
			1,9,1,9,8,4,9,9,9,1,8,9,9,9,8,7,3,9,8
		};

	Collection collectionTest(19,tabBase);
	collectionTest.Afficher();

	printGras("On retire tout les éléments de la Collection");
	for (int i = 0; i < 10; ++i)
	{
		collectionTest.Retirer(i,-1);
	}
	collectionTest.Afficher();
}


void testReunir1()
{
	printTitre("TEST : REUNIR");
	printGras("Initialisation des Collections à réunir vides :");

	// Initialisation des collections
	Collection col1(10);
	Collection col2(20);

	// 
	printGras("Collection 1");
	col1.Afficher();
	printGras("Collection 2");
	col2.Afficher();
	printGras("Réunion des 2");
	col1.Reunir(col2);
	col1.Afficher();

}

void testReunir2()
{
	// Initialisation des collections
	printGras("Test avec Collections à moitié rempies");
	Collection col1(30);
	for (int i = 0; i < 15; ++i)
	{	col1.Ajouter(i);
	}
	Collection col2(10);
	for (int i = 0; i < 5; ++i)
	{	col2.Ajouter((i+1)*10);
	}

	printGras("Collection 1");
	col1.Afficher();
	printGras("Collection 2");
	col2.Afficher();
	printGras("Réunion des 2");
	col1.Reunir(col2);
	col1.Afficher();
}

void testReunir3()
{
	printGras("Test avec Collections néssésitant un redimensionnement");
	// Initialisation des collections
	Collection col1(15);
	for (int i = 0; i < 15; ++i)
	{	col1.Ajouter(i);
	}
	Collection col2(10);
	for (int i = 0; i < 10; ++i)
	{	col2.Ajouter((i+1)*10);
	}

	printGras("Collection 1");
	col1.Afficher();
	printGras("Collection 2");
	col2.Afficher();
	printGras("Réunion des 2");
	col1.Reunir(col2);
	col1.Afficher();
}