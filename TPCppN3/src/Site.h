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

//----------------------------------------------------------- Constantes
const string CHEMIN_FICHIER_EXTERNE = "Externe";

//----------------------------------------------------------- Types utilisateur
typedef map<string, Fichier*> FichierMap;
typedef map<string, Fichier*> :: iterator SI;

//------------------------------------------------------------------------
// Rôle de la classe <Site>
//
//------------------------------------------------------------------------
class Site
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterVisite (const string cheminDestination);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterVisite (const string cheminSource, const string cheminDestination);
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<Fichier*> * GetListe ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void FaireGraphe (ofstream &theStream);
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Getters
    string GetAdresse () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    uint32_t GetHits (const string cheminDestination);
    // Mode d'emploi :
    //
    // Contrat :
    //

    uint32_t GetHits (const string cheminSource, const string cheminDestination);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Site (const string uneAdresse);
    // Mode d'emploi :
    //

    virtual ~Site ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    string adresse;
    FichierMap fichiers;
    Fichier * fichierExterne;

    void AjouterFichier(const string chemin);
};

#endif // SITE_H
