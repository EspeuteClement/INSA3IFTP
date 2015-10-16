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

inline void printTitre(const char* texte)
{	cout <<BOLD_SYMBOL<< "\n====================================\n====== "<< texte <<" ======\n====================================\n\n"<<END_SYMBOL;
}

void testConstructeur();
void testAjouter();
void testRetirer();
void testAjuster();
void testReunir();

#endif //MAIN_H