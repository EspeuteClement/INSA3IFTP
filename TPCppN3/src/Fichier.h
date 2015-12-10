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
// Pour chaque Fichier d'un site web, cette classe stocke un identifiant unique
// (chemin), le nombre de fois qu'il a été visité (totalHits), ainsi qu'un
// dictionnaire reliant le nombre de fois que quelqu'un est arrivé au Fichier
// courant à partir d'un autre Fichier, dont le pointeur sert de clef audit
// dictionnaire (les redondances ne sont pas possibles).
//------------------------------------------------------------------------
class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterVisite (Fichier * fichierSource);
    // Mode d'emploi :
    // Incrémente d'un le nombre de hits total du Fichier courant et le nombre
    // de hits associé au pointeur du Fichier source donné. Ne fais rien si le
    // pointeur est NULL.

    void FaireGraphe (ofstream &theStream);
    // Mode d'emploi :
    // Ajoute les lignes de code GraphViz au ofstream passé par référence
    // correspondant aux liens à tracer entre les Fichiers sources de visites
    // vers le Fichier courant.
    // Contrat :
    // Le ofstream passé par référence doit être valide. Cette méthode ne doit
    // être appelée qu'à l'intérieur d'une autre fonction/méthode comprenant les
    // autres lignes de code nécessaires à la validité du code GraphViz.

    static bool PlusPetitNbHits (const Fichier* fichier1, const Fichier* fichier2)
    {
        return (fichier1->GetHits() < fichier2->GetHits());
    }
    // Mode d'emploi :
    // Renvoie true si le nombre de hits total du fichier1 est inférieur à celui
    // du fichier2, false sinon.
    // Contrat :
    // fichier1 et fichier2 ne doivent pas être des pointeurs NULL.

//----------------------------------------------------- Getters
    uint32_t GetHits () const;
    // Mode d'emploi :
    // Renvoie le nombre de hits total du Fichier courant.

    string GetChemin () const;
    // Mode d'emploi :
    // Renvoie le chemin du Fichier courant.

//-------------------------------------------- Constructeurs - destructeur
    Fichier (const string unChemin);
    // Mode d'emploi :
    // Créé une instance de Fichier, lui affecte le chemin passé en paramètre,
    // et initialise le nombre de hits total à 0.

    virtual ~Fichier ();
    // Mode d'emploi :
    // Détruit l'instance de Fichier.

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
