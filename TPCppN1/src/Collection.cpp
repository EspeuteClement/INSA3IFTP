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

void Collection::Ajuster (int uneTaille)
{
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
