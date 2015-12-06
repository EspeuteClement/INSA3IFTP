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

void Fichier::FaireGraphe (ofstream &theStream, string cheminCourant)
{
  for (FI fichierIterator = hits.begin(); fichierIterator != hits.end(); fichierIterator++)
  {
      theStream << "\t" << chemin << " -> " << cheminCourant << " [label=\"" << fichierIterator->second << "\"];" << endl;
  }
}

//----------------------------------------------------- Getters
uint32_t Fichier::GetHits () const
{
    return totalHits;
}

uint32_t Fichier::GetHits (Fichier * fichierSource)
{
    if (hits.find(fichierSource) != hits.end())
    {
        return hits[fichierSource];
    }
    else
    {
        return 0;
    }
}

//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier (const string unChemin)
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif

    totalHits = 0;
}

Fichier::~Fichier ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
}
