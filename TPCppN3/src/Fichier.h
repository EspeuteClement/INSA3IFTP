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

//----------------------------------------------------------- Types utilisateur
typedef map<Fichier *, uint32_t> HitMap;
typedef map<Fichier *, uint32_t> :: iterator FI;

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

    void FaireGraphe (ofstream &theStream, string cheminCourant);
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Surcharge d'opérateurs
    inline bool operator < (const Fichier& fichier2)
    {
        return (this->GetHits() < fichier2.GetHits());
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

    uint32_t GetHits (Fichier * fichierSource);
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
    typedef map<Fichier *, uint32_t> HitMap;
    HitMap hits;
    uint32_t totalHits;
};

#endif // FICHIER_H
