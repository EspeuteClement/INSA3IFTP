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
void Collection::Afficher ()
{
}

void Collection::Ajouter (int valeur)
{
}

void Collection::Retirer (int valeur, int occurencesNb)
{
}

int Collection::Ajuster (int uneTaille)
{   
    // Erreur si la nouvelle taille est trop petite
    if (uneTaille < nbElements) 
    {   return ERR_TAILLE;
    }
    // Recréer un tableau si sa taille est plus grande que celle actuelle
    else if (uneTaille <= alloue) 
    {   int nouveauTableau = new int[uneTaille]; // Nouveau tableau qui sera alloué
        
        // Copie de l'ancien tableau vers le nouveau
        for (int = 0;i<nbElements;i++)
        {   nouveauTableau[i] = tableau[i];
        }

        delete tableau;
        tableau = nouveauTableau;
    }
    alloue = uneTaille;
    return NO_ERR;
}

void Collection::Reunir (const Collection &Collection)
{
}

//-------------------------------------------- Constructeurs - destructeur
Collection::Collection (int uneTaille)
{
#ifdef MAP
    cout << "Appel au premier constructeur de <Collection>" << endl;
#endif

    taille = uneTaille;
    tableau = new int[uneTaille];
}

Collection::Collection (int uneTaille, int *unTableau)
{
#ifdef MAP
    cout << "Appel au second constructeur de <Collection>" << endl;
#endif

    taille = uneTaille;
    tableau = new int[uneTaille];

    int i;
    for (i = 0; i < taille; i++) {
      tableau[i] = unTableau[i];
    }
}


Collection::~Collection ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif

    delete tableau;
}
