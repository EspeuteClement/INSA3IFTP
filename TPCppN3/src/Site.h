/*************************************************************************
                           Site  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Interface de la classe <Site> (fichier Site.h) ------
#if ! defined ( SITE_H )
#define SITE_H
#define DEBUG
//#define MAP

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <map>
#include <vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Fichier.h"

//----------------------------------------------------------- Enumérations

//------------------------------------------------------------------------
// Rôle de la classe <Site>
//
//------------------------------------------------------------------------
class Site
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterVisite (string cheminDestination);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterVisite (string cheminSource, string cheminDestination);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Fichier * Trouver (string cheminFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<Fichier*> * GetListe ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Site (string uneAdresse);
    // Mode d'emploi :
    //

    virtual ~Site ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

//private:
//------------------------------------------------------- Attributs privés
    string adresse;
    typedef map<string, Fichier*> FichierMap;
    FichierMap fichiers;
    Fichier * fichierExterne;

    void AjouterFichier(string chemin);
};

#endif // SITE_H
