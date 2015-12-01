/*************************************************************************
                           MoteurES  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <MoteurES> (fichier MoteurES.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "MoteurES.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void MoteurES::Afficher10Premiers ()
{
}

void FaireGraphe (string nomDuFichier) const
{
}

//-------------------------------------------- Constructeurs - destructeur
MoteurES::MoteurES (const unsigned int uneTaille)
{
#ifdef MAP
    cout << "Appel au premier constructeur de <MoteurES>" << endl;
#endif
}

MoteurES::~MoteurES ()
{
#ifdef MAP
    cout << "Appel au destructeur de <MoteurES>" << endl;
#endif
}
