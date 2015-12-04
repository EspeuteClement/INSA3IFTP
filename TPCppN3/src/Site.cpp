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
void Site::AjouterVisite (const string cheminDestination)
{
    // Créer le fichier destination s'il n'existe pas déjà
    if (fichiers.find(cheminDestination) == fichiers.end())
    {
        AjouterFichier(cheminDestination);
    }

    // Ajouter une visite du fichier externe source dans celui (interne)
    // destination
    fichiers[cheminDestination]->AjouterVisite(fichierExterne);

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



vector<Fichier*> * GetListe ()
{
    return NULL;
}

//----------------------------------------------------- Getters
string Site::GetAdresse () const
{
    return adresse;
}

Fichier * Site::GetFichier (const string cheminFichier) const
{
    return fichiers[cheminFichier];
}

//----------------------------------------------------- Méthodes privées
void Site::AjouterFichier(string chemin)
{
    fichiers[chemin] = new Fichier(chemin);
}

//-------------------------------------------- Constructeurs - destructeur
Site::Site (string uneAdresse)
{
#ifdef MAP
    cout << "Appel au constructeur de <Site>" << endl;
#endif

    adresse = uneAdresse;

    fichierExterne = new Fichier("Externe");
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
