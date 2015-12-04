/*************************************************************************
                           Fichier  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <Fichier> (fichier Fichier.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Fichier.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------------ Méthodes publiques
void Fichier::AjouterVisite (Fichier * source)
{
    hits[source]++;
}

//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier (string unNom)
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif

    nom = unNom;
}

Fichier::~Fichier ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
}
