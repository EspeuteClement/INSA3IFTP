/*************************************************************************
                           MoteurES  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Interface de la classe <MoteurES> (fichier MoteurES.h) ------
#if ! defined ( MOTEURES_H )
#define MOTEURES_H
#define DEBUG
//#define MAP

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Site.h"

//----------------------------------------------------------- Enumérations
enum CodesRetour
{
};

//------------------------------------------------------------------------
// Rôle de la classe <MoteurES>
//
//------------------------------------------------------------------------
class MoteurES
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher10Premiers ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void FaireGraphe (string nomDuFichier) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    MoteurES ();
    // Mode d'emploi :
    //

    virtual ~MoteurES ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    Site leSite;
};

#endif // MOTEURES_H
