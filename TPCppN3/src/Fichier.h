/*************************************************************************
                           Fichier  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Interface de la classe <Fichier> (fichier Fichier.h) ------
#if ! defined ( FICHIER_H )
#define FICHIER_H
#define DEBUG
//#define MAP

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <map>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Site.h"

//----------------------------------------------------------- Enumérations
enum CodesRetour
{
};

//------------------------------------------------------------------------
// Rôle de la classe <Fichier>
//
//------------------------------------------------------------------------
class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterVisite (string source) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Fichier ();
    // Mode d'emploi :
    //

    virtual ~Fichier ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    string nom;
    Site siteSource;
    map<*Fichier, int> hits;
};

#endif // FICHIER_H
