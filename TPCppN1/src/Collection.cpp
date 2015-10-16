/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 2015/10/09
    copyright            : (C) 2015 par cespeute & brenault
*************************************************************************/

//---------- Realisation de la classe <Collection> (fichier Collection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
void Collection::Afficher () const
{
#ifdef DEBUG
    printNbElements();
    printAlloue();
#endif
    int i;
    for (i = 0; i < nbElements; i++)
    {   cout << tableau[i] << "\n";
    }
}

void Collection::Ajouter (int valeur)
{   // Couvre le cas ou la collection est deja pleine.
    if (alloue == nbElements)
    {   Ajuster(alloue+1);
    }
    tableau[nbElements] = valeur;
    nbElements++;
}

void Collection::Retirer (int valeur, int occurencesNb)
{   // Si occurencesNb < 0 on supprime toutes les occurences de la valeur dans
    // la collection courante. Pour cela on reporte a chaque fois la derniere
    // valeur a la place de l'element a supprimer et on reduit la taille du
    // tableau en consequence.
    if (occurencesNb < 0) {
        for (int i = 0; i < nbElements; i++) {
            if (tableau[i] == valeur) {
                if (i != nbElements - 1) {
                    tableau[i] = tableau[nbElements - 1];
                }
                nbElements--;
                Ajuster(nbElements);
            }
        }
    }

    else {
      int occurences = 0;
      for (int i = 0; i < nbElements; i++) {
          if (tableau[i] == valeur) {
              occurences++;
              if (occurences <= occurencesNb) {
                  if (i != nbElements - 1) {
                      tableau[i] = tableau[nbElements - 1];
                  }
                  nbElements--;
                  Ajuster(nbElements);
              }
          }
      }
    }
}

int Collection::Ajuster (unsigned long int uneTaille)
{
    // Erreur si la nouvelle taille est trop petite
    if (uneTaille < nbElements)
    {   return ERR_TAILLE;
    }
    // Recreer un tableau si sa taille est differente que celle actuelle
    else if (uneTaille != alloue)
    {   int *nouveauTableau = new int[uneTaille]; // Nouveau tableau qui sera alloué
        // Copie de l'ancien tableau vers le nouveau
        for (int i = 0;i<nbElements;i++)
        {   nouveauTableau[i] = tableau[i];
        }

        delete tableau;
        tableau = nouveauTableau;
    }
    alloue = uneTaille;
    return PAS_ERR;
}

void Collection::Reunir (const Collection &uneCollection)
{
    // Cas ou la collection courante n'est pas assez grande pour accueillir tous
    // les elements de la seconde.
    if (alloue < nbElements + uneCollection.nbElements)
    {   Ajuster(nbElements + uneCollection.nbElements);
    }

    // Copie les valeurs de la seconde collection dans la courante
    int i;
    for (i = nbElements; i < alloue; i++) 
    {   tableau[i] = uneCollection.tableau[i - nbElements];
    }

    nbElements = alloue;
}

//-------------------------------------------- Constructeurs - destructeur
Collection::Collection (unsigned int uneTaille)
{
#ifdef MAP
    cout << "Appel au premier constructeur de <Collection>" << endl;
#endif

    alloue = uneTaille;
    nbElements = 0;
    tableau = new int[uneTaille];
}

Collection::Collection (unsigned int uneTaille, int *unTableau)
{
#ifdef MAP
    cout << "Appel au second constructeur de <Collection>" << endl;
#endif

    alloue = uneTaille;
    tableau = new int[uneTaille];

    // Copie les elements du tableau passe en parametre un a un
    int i;
    for (i = 0; i < alloue; i++)
    {   tableau[i] = unTableau[i];
    }
    nbElements = alloue;
}


Collection::~Collection ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif

    delete tableau;
}

void Collection::printNbElements() const
{   cout << "NbElements : " << nbElements << '\n';
}

void Collection::printAlloue () const
{   cout << "Alloue : " << alloue << '\n';
}
