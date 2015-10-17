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
void testConstructeur2();

void testAjouter();


void testRetirer1(); // Retirer 1 élement de la collection
void testRetirer2(); // Retirer n éléments de la collection
void testRetirer3(); // Retirer touts les éléments d'une valeur donné 
void testRetirer4(); // Retirer un élément non présent dans la collection
void testRetirer5(); // Retirer tout les éléments de la collection

void testAjuster1();
void testAjuster2();
void testAjuster3();

void testReunir();



#endif //MAIN_H