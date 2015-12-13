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
#include <list>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Fichier.h"

//------------------------------------------------------------------------
// Rôle de la classe <Site>
// Stocke un identifiant unique (adresse) désignant un site web, ainsi qu'un
// dictionnaire reliant l'identifiant (chemin) de tous les Fichiers internes au
// site à un pointeur vers ce Fichier (redondances impossibles). Ce dictionnaire
// contient aussi un identifiant CHEMIN_FICHIER_EXTERNE constant, désignant un
// pointeur vers un Fichier représentant l'ensemble des Fichiers externes au
// site. Si l'utilisateur choisit d'afficher toutes les adresses sources de
// externes, elles seront alors stockées comme des fichiers internes, dans le
// dictionnaire.
//------------------------------------------------------------------------
class Site
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void AjouterVisite (const string cheminDestination);
    // Mode d'emploi :
    // Fais appel à la méthode AjouterVisite (en lui passant
    // CHEMIN_FICHIER_EXTERNE en paramètre) du Fichier identifié par
    // cheminDestination. Si le Fichier identifié par cheminDestination n'existe
    // pas déjà dans le dictionnaire du Site, une instance de Fichier
    // correspondante est créée et ajoutée au dictionnaire du Site.
    // Contrat :
    // cheminDestination doit désigner un Fichier interne au Site.

    void AjouterVisite (const string cheminSource, const string cheminDestination);
    // Mode d'emploi :
    // Fais appel à la méthode AjouterVisite (en lui passant cheminSource en
    // paramètre) du Fichier identifié par cheminDestination. Si le Fichier
    // identifié par cheminSource ou cheminDestination n'existe pas déjà
    // dans le dictionnaire du Site, une instance de Fichier correspondante est
    // créée et ajoutée au dictionnaire du Site.
    // Contrat :
    // cheminSource et cheminDestination doivent désigner tous deux des Fichiers
    // internes au Site.

    void AfficherPremiers (const uint32_t nbPremiers);
    // Mode d'emploi :
    // Créé une liste des fichiers du Site courant, triés par ordre croissant de
    // leurs nombre de hits total, et affiche les chemins et le nombre de hits
    // total des nbPremiers plus visités, dans l'ordre décroissant de leur nombre de
    // hits total. S'il y a moins de nbPremiers fichiers, ils sont tous affichés de la
    // même manière. Si un Fichier a 0 hits, il n'est pas pris en compte. S'il
    // n'y en a aucun, la méthode ne fait rien.

    void FaireGraphe (ofstream &theStream);
    // Mode d'emploi :
    // Ajoute les lignes de code GraphViz au ofstream passé par référence,
    // produisant un fichier GraphViz valide (compilable).
    // Contrat :
    // Le ofstream passé par référence doit être valide.

//----------------------------------------------------- Getters
    string GetAdresse () const;
    // Mode d'emploi :
    // Renvoie l'adresse du Site courant.

//-------------------------------------------- Constructeurs - destructeur
    Site (const string uneAdresse);
    // Mode d'emploi :
    // Créé une instance de Site, lui affecte l'adresse passée en paramètre,
    // et créé une instance de Fichier représentant les Fichiers externes au
    // Site.

    virtual ~Site ();
    // Mode d'emploi :
    // Détruit l'instance de Site après avoir détruit toutes les instances de
    // fichiers présentes dans le dictionnaire.

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    string adresse;
    typedef map<string, Fichier*> FichierMap;
    typedef map<string, Fichier*> :: iterator SI;
    FichierMap fichiers;

    void AjouterFichier(const string chemin);
};

#endif // SITE_H
