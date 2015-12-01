/*************************************************************************
                           Site  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <Site> (fichier Site.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Site.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Site::AjouterVisite (string source) const
{
}

//-------------------------------------------- Constructeurs - destructeur
Site::Site (const unsigned int uneTaille)
{
#ifdef MAP
    cout << "Appel au premier constructeur de <Site>" << endl;
#endif
}

Site::~Site ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Site>" << endl;
#endif
}
