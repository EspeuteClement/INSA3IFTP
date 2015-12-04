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
void Fichier::AjouterVisite (Fichier * fichierSource)
{
    hits[fichierSource]++;
    totalHits++;
}

//----------------------------------------------------- Getters
string Fichier::GetChemin () const
{
    return chemin;
}

int Fichier::GetHits () const
{
    return totalHits;
}

int Fichier::GetHits (const Fichier * const fichierSource) const
{
    if (hits.find(fichierSource) != hits.end())
    {
        return hits[fichierSource];
    }
}

//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier (string unChemin)
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif

    chemin = unChemin;
    totalHits = 0;
}

Fichier::~Fichier ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
}
