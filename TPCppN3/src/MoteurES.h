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

#include <iostream>
#include <fstream>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
//------------------------------------------------------ Include personnel
#include "Site.h"

//----------------------------------------------------------- Constantes
const uint32_t NB_PREMIERS = 10;

//----------------------------------------------------------- Enumérations

/** L'ensemble des codes retours utilisées par les
*   méthodes de la classe MoteurES
*/
enum CodeRetourMoteurES
{
    FICHIER_OK = 0, // L'ouverture du fichier à bien eu lieu
    FICHIER_ERR = 1 // L'ouverture du fichier à échouée.
};

// L'ensemble des états que peut prendre la struct DonneesLog.
// Voir LireLigneLog() pour plus de détails
enum EtatDonneesLog
{
    OK,         // Si la lecture s'est déroulée sans accrocs
    NON_MATCH,   // Si la lecture n'a pas donné de résultat (Parce que ignoré)
    END_FILE    // Si on est arrivé à la fin du fichier
};

// Liste les codes de retour de la fonction
// GestionArguments
enum CodeRetourArgument
{
    OK_ARG,         // Tout c'est bien passé
    ERR_ARG,        // Les arguments sont mal formés
    AIDE_ARG        // L’utilisateur à demandé l'affichage de l'aide.
};

//-------------------------------------------------------- Types de classe

// Représente l'ensemble des données utiles (pour notre application)
// d'une ligne de log apache.
struct DonneesLog{
    public :
        //Note : L'ordre correspond à l'ordre des données dans le log apache

        string FichierDestination; /* Le Fichier vers où l'on va */
        unsigned int CodeHttp;  /* Le code http correspondant à la */

        //TODO : Voir si on mets pas ça en enum ...
        string Protocole;       /* Le protocole qui à été utilisé pour la requête*/

        string SiteSource;      /* */
        string FichierSource;      /* Le Fichier d'où l'on vient */

        EtatDonneesLog Etat;    /* L'état des données lues*/
        // Constructeur qui initialise l'ensemble des
        // données de la structure dans l'ordre dans
        // lesquelles elles sont situés dans le
        // log apache.
        DonneesLog( string FichierDestination,
                    unsigned int codeHttp,
                    string protocole,
                    string SiteSource,
                    string FichierSource,
                    EtatDonneesLog etat):
                    FichierDestination(FichierDestination),
                    CodeHttp(codeHttp),
                    Protocole(protocole),
                    SiteSource(SiteSource),
                    FichierSource(FichierSource),
                    Etat(etat)
        {

        };

        inline bool FinDuFichier() const {return Etat == END_FILE;};
        // Mode d'emploi :
        // Permet de savoir si on a atteint la fin du fichier après une
        // lecture d'une ligne du log
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
    CodeRetourMoteurES OuvrirFichierLog(string chemin);
    // Mode d'emploi :
    // Tente d'ouvrir le fichier situé au chemin
    // donné en paramètre.
    // La méthode renvoie un CodeRetourMoteurES qui vaut :
    //      FICHIER_OK si l'ouverture du fichier s'est bien
    //      déroulée,
    //      FICHIER_ERR si le fichier n'a pas pu être ouvert

    CodeRetourMoteurES FermerFichierLog();
    // Mode d'emploi :
    // Tente de fermer le fichier actuellement ouvert par
    // ce MoteurES.
    // La méthode renvoie un CodeRetourMoteurES qui vaut :
    //      FICHIER_OK si la fermeture du fichier s'est bien
    //      déroulée,
    //      FICHIER_ERR si le fichier n'a pas pu être fermé

    DonneesLog LireLigneLog();
    // Mode d'emploi :
    // Renvoie dans un DonnesLog la prochaine ligne du fichier
    // actuellement ouvert par le MoteurES.
    // Les informations sur la lectures sont stockés dans l’attribut
    // Etat de la struct DonneesLog.
    // Si la lecture est terminée, ou qu'aucun fichier n'est ouvert,
    // DonnesLog.FinDuFichier() renverra true.


    inline bool FichierEstOuvert() const {return fichierLog.is_open();} ;
    // Mode d'emploi :
    // Renvoie vrai si un fichier est actuellement ouvert par
    // ce MoteurES.

    void ModifierMatchs(int heure = -1);
    // Mode d'emploi :
    // Modifie la manière dont le MoteurES cherche les sites
    // dans le log
    // Paramètres :
    // extensions : La liste des extensions à exclure
    // heure : L'heure à choisir. Mettre -1 pour ignorer.

    CodeRetourArgument GestionArguments(int nombreArguments, char* arguments[]);
    // Mode d'emploi :
    // Gère la gestion des arguments passés au programme par l’utilisateur.
    // Les arguments sont ceux fournis par le main.

    void AfficherAide();
    // Mode d'emploi :
    // Affiche l'aide du programme dans la sortie standard

    void ParserLog();

    void FaireGraphe();
//-------------------------------------------- Constructeurs - destructeur
    MoteurES ();
    // Mode d'emploi :
    // Crée un Moteur d'Entrées Sorties.

    virtual ~MoteurES ();
    // Mode d'emploi :
    // Détruit le moteur

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    //Site leSite;
    vector<string> blackListExtension; /*La liste des extensions de fichiers ignorée*/
    regex apacheLogRegex;
    ifstream fichierLog; /**Le fichier de log que l'on lit*/
    bool verbose = false; /* Si l'on doit afficher chaque information lue dans le ficher log */
    Site leSite = Site("intranet-if.insa-lyon.fr");
    string leSiteNom = "intranet-if.insa-lyon.fr";
    string nomFichierSortie = "";

    bool afficherSiteExternes = false;

};


#endif // MOTEURES_H
