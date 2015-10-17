#ifndef MAIN_H
#define MAIN_H

#define BOLD_USAGE // Active ou  désactive le gras dans la console
using namespace std;

#ifdef BOLD_USAGE
	const char BOLD_SYMBOL[] = "\033[1m"; // Code terminal pour afficher les caractères en gras
	const char END_SYMBOL[] = "\033[0m"; // Code terminal pour annuler la mise en forme
#else
	const char BOLD_SYMBOL[] = ""; // Code terminal pour afficher les caractères en gras
	const char END_SYMBOL[] = ""; // Code terminal pour annuler la mise en forme
#endif //BOLD_USAGE

//AFFICHE UN TEXTE EN GRAS :
inline void printGras(const char* texte)
{	cout <<BOLD_SYMBOL<< texte <<END_SYMBOL<<"\n";
}

//AFFICHE LE TITRE :
inline void printTitre(const char* texte)
{	cout <<BOLD_SYMBOL<< "\n====================================\n====== "<< texte <<" ======\n====================================\n\n"<<END_SYMBOL;
}

void testConstructeur1();
void testConstructeur2_1();
void testConstructeur2_2();
void testConstructeur2_3();


void testAjouter();


void testRetirer1(); // Retirer 1 élement de la collection
void testRetirer2(); // Retirer n éléments de la collection d'une valeur donné
void testRetirer3(); // Retirer touts les éléments d'une valeur donné 
void testRetirer4(); // Retirer un élément non présent dans la collection
void testRetirer5(); // Retirer tout les éléments de la collection

void testAjuster1(); // Ajustement quand il y a plus d'éléments dans le tableau que la nouvelle taille (provoque une erreur)
void testAjuster2(); // Ajustement quand la nouvelle taille est plus grande que l'ancienne
void testAjuster3(); // Ajustement quand la nouvelle taille est plus petite que l'ancienne

void testReunir1();	// Réunion de 2 Collections vides
void testReunir2(); // Réunion de 2 Collections peuplées sans redimentionement nessésaire
void testReunir3(); // Réunion de 3 Collections peuplées avec redimentionement nessésaire



#endif //MAIN_H