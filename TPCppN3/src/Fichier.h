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

//----------------------------------------------------------- Enumérations

//------------------------------------------------------------------------
// Rôle de la classe <Fichier>
//
//------------------------------------------------------------------------
class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterVisite (Fichier * fichierSource);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Fichier (string unChemin);
    // Mode d'emploi :
    //

    virtual ~Fichier ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

//private:
//------------------------------------------------------- Attributs privés
    string chemin;
    typedef map<Fichier *, int> HitMap;
    HitMap hits;
};

#endif // FICHIER_H
