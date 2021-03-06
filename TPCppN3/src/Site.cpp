/*************************************************************************
                           Site  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <Site> (fichier Site.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Site.h"

//----------------------------------------------------------- Constantes
const string CHEMIN_FICHIER_EXTERNE = "Externe";

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Site::AjouterVisite (const string cheminDestination)
{
    // Créer le fichier destination s'il n'existe pas déjà
    if (fichiers.find(cheminDestination) == fichiers.end())
    {
        AjouterFichier(cheminDestination);
    }

    // Ajouter une visite du fichier externe source dans celui (interne)
    // destination
    fichiers[cheminDestination]->AjouterVisite(fichiers[CHEMIN_FICHIER_EXTERNE]);

}

void Site::AjouterVisite (const string cheminSource, const string cheminDestination)
{
    // Créer le fichier destination s'il n'existe pas déjà
    if (fichiers.find(cheminDestination) == fichiers.end())
    {
        AjouterFichier(cheminDestination);
    }

    // Créer le fichier source s'il n'existe pas déjà
    if (fichiers.find(cheminSource) == fichiers.end())
    {
        AjouterFichier(cheminSource);
    }

    // Ajouter une visite du fichier d'où on vient dans celui où on va
    fichiers[cheminDestination]->AjouterVisite(fichiers[cheminSource]);
}

void Site::AfficherPremiers (const uint32_t nbPremiers)
{
    // Tri des fichiers en fonction de leur nombre de hits
    list<Fichier*> liste;

    for(SI iterator = fichiers.begin(); iterator != fichiers.end(); iterator++)
    {
        // On n'ajoute pas le fichier externe à la liste des documents consultés
        // ainsi que les Fichiers ayant 0 hits.
        if (iterator->second->GetChemin().compare(CHEMIN_FICHIER_EXTERNE) != 0
              && iterator->second->GetHits() != 0)
        {
            liste.push_back(iterator->second);
        }
    }

    liste.sort(&Fichier::PlusPetitNbHits);

    // Affichage des fichiers triés par nombre de hits décroissant.
    uint32_t i;
    uint32_t tailleListe = liste.size();
    // Quitter la méthode si rien à afficher.
    if (tailleListe == 0)
    {
        return;
    }
    // Affichage de tous les fichiers si leur nombre est inférieur à nbPremiers.
    else if (tailleListe < nbPremiers)
    {
        for (i = 0; i < tailleListe; i++)
        {
            cout << liste.back()->GetChemin() << " (" << liste.back()->GetHits() <<
            " hits)" << endl;
            liste.pop_back();
        }
    }
    // Affichage des nbPremiers premiers seulement si leur nombre est supérieur à nbPremiers.
    else
    {
        for (i = 0; i < nbPremiers; i++)
        {
          cout << liste.back()->GetChemin() << " (" << liste.back()->GetHits() <<
          " hits)" << endl;
          liste.pop_back();
        }
    }
}

void Site::FaireGraphe (ofstream &theStream)
{
    theStream << "digraph {" << endl;

    // Ajouter tous les fichiers comme bulles
    for (SI iterator = fichiers.begin(); iterator != fichiers.end(); iterator++)
    {
        theStream << "\t\"" << iterator->first << "\";" << endl;
    }

    // Ajouter tous les hits relatifs comme liens
    for (SI siteIterator = fichiers.begin(); siteIterator != fichiers.end(); siteIterator++)
    {
        siteIterator->second->FaireGraphe(theStream);
    }


    theStream << "}" << endl;
}

//----------------------------------------------------- Getters
string Site::GetAdresse () const
{
    return adresse;
}

//-------------------------------------------- Constructeurs - destructeur
Site::Site (const string uneAdresse)
{
#ifdef MAP
    cout << "Appel au constructeur de <Site>" << endl;
#endif

    adresse = uneAdresse;
    fichiers[CHEMIN_FICHIER_EXTERNE] = new Fichier(CHEMIN_FICHIER_EXTERNE);
}

Site::~Site ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Site>" << endl;
#endif
    for (SI iterator = fichiers.begin(); iterator != fichiers.end(); iterator++)
    {
        delete iterator->second;
    }
}

//----------------------------------------------------------------- PRIVE

//----------------------------------------------------- Méthodes privées
void Site::AjouterFichier(const string chemin)
{
    fichiers[chemin] = new Fichier(chemin);
}
