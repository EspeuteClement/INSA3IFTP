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



vector<Fichier*> GetListe ()
{
    vector<Fichier*> liste;

    for( MapType::iterator it = mFichierMap.begin(); it != FichierMap.end(); ++it ) {
        liste.push_back( it->second );
    }

    return liste;
}

//----------------------------------------------------- Getters
string Site::GetAdresse () const
{
    return adresse;
}

uint32_t Site::GetHits (const string cheminDestination)
{
    // Si le chemin du fichier donné est bien repertorié
    if (fichiers.find(cheminDestination) != fichiers.end())
    {
        return fichiers[cheminDestination]->GetHits();
    }
    // Si le chemin du fichier donné n'est pas répertorié
    else
    {
        return 0;
    }
}

uint32_t Site::GetHits (const string cheminSource, const string cheminDestination)
{
    // Si le chemin du fichier donné est bien repertorié
    if (fichiers.find(cheminDestination) != fichiers.end())
    {
        return fichiers[cheminDestination]->GetHits(fichiers[cheminSource]);
    }
    // Si le chemin du fichier donné n'est pas répertorié
    else
    {
        return 0;
    }
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
    typedef map<string, Fichier*> :: iterator FI;
    for (FI iterator = fichiers.begin(); iterator != fichiers.end(); iterator++)
    {
        delete iterator->second;
    }
    delete fichierExterne;
}

//----------------------------------------------------------------- PRIVE

//----------------------------------------------------- Méthodes privées
void Site::AjouterFichier(const string chemin)
{
    fichiers[chemin] = new Fichier(chemin);
}
