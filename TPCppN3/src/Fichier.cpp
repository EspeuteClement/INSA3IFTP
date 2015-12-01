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

//----------------------------------------------------- Méthodes publiques
void Fichier::AjouterVisite (string source) const
{
}

//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier (const unsigned int uneTaille)
{
#ifdef MAP
    cout << "Appel au premier constructeur de <Fichier>" << endl;
#endif
}

Fichier::~Fichier ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
}
