/*************************************************************************
                           Fichier  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <Fichier> (fichier Fichier.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Fichier.h"

//----------------------------------------------------------------- PUBLIC

//------------------------------------------------------ Méthodes publiques
void Fichier::AjouterVisite (Fichier * fichierSource)
{
    hits[fichierSource]++;
    totalHits++;
}

void Fichier::FaireGraphe (ofstream &theStream)
{
    // Pour le fichier courant, créer tous les liens des autres fichiers vers lui.
    for (FI fichierIterator = hits.begin(); fichierIterator != hits.end(); fichierIterator++)
    {
        theStream << "\t" << fichierIterator->first->GetChemin() << " -> " <<
        chemin << " [label=\"" << fichierIterator->second << "\"];" << endl;
    }
}

//----------------------------------------------------- Getters
uint32_t Fichier::GetHits () const
{
    return totalHits;
}

string Fichier::GetChemin () const
{
    return chemin;
}

//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier (const string unChemin)
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
