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
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel

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

    void FaireGraphe (ofstream &theStream);
    // Mode d'emploi :
    //
    // Contrat :
    //

    static bool CompareHitsFichiers (const Fichier* fichier1, const Fichier* fichier2)
    {
        return (fichier1->GetHits() < fichier2->GetHits());
    }
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Getters
    uint32_t GetHits () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    string GetChemin () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Fichier (const string unChemin);
    // Mode d'emploi :
    //

    virtual ~Fichier ();
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    string chemin;
    uint32_t totalHits;
    typedef map<Fichier *, uint32_t> HitMap;
    typedef map<Fichier *, uint32_t> :: iterator FI;
    HitMap hits;
};

#endif // FICHIER_H
