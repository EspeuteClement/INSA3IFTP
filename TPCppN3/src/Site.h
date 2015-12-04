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
#include "Fichier.h";

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
    void AjouterFichier (Fichier * unFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterVisite (string source, string destination);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Fichier * Trouver (string nomFichier);
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
    Site ();
    // Mode d'emploi :
    //

    virtual ~Site ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    string nom;
    map<Site *, int> listeFichiers;
    Fichier * externes;
};

#endif // SITE_H
