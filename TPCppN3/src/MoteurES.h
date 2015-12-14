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
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
//------------------------------------------------------ Include personnel
#include "Site.h"

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
    AIDE_ARG,       // L’utilisateur à demandé l'affichage de l'aide.
    PAS_FICHIER     // Le fichier demandé n'est pas trouvé 
};

//-------------------------------------------------------- Types de classe

// Représente l'ensemble des données utiles (pour notre application)
// d'une ligne de log apache.
struct DonneesLog{
    public :
        //Note : L'ordre correspond à l'ordre des données dans le log apache

        string FichierDestination; // Le chemin du fichier vers lequel la
                                   // requête pointe
        unsigned int CodeHttp;     // Le code Http de la requête

        string Protocole;           // Le protocole utilisé par la requête

        string SiteSource;          // Le site d'origine de la requête
        string FichierSource;       // Le chemin de le fichier d'origine de la
                                    // requête

        EtatDonneesLog Etat;    /* L'état des données lues*/

        DonneesLog( string FichierDestination,
                    unsigned int codeHttp,
                    string protocole,
                    string SiteSource,
                    string FichierSource,
                    EtatDonneesLog etat
                  ):
                    FichierDestination(FichierDestination),
                    CodeHttp(codeHttp),
                    Protocole(protocole),
                    SiteSource(SiteSource),
                    FichierSource(FichierSource),
                    Etat(etat)
        {

        };
        // Mode d'emploi
        // Constructeur qui initialise l'ensemble des
        // données de la structure dans l'ordre dans
        // lesquelles elles sont situés dans le
        // log apache.

        inline bool FinDuFichier() const {return Etat == END_FILE;};
        // Mode d'emploi :
        // Renvoie vrai si l'on à atteint la fin du fichier lu par la
        // méthode LireLigneLog
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
    CodeRetourMoteurES OuvrirFichierLog(string const chemin);
    // Mode d'emploi :
    // Tente d'ouvrir le fichier situé au chemin
    // donné en paramètre.
    // La méthode renvoie un CodeRetourMoteurES qui vaut :
    //      FICHIER_OK si l'ouverture du fichier s'est bien
    //      déroulée,
    //      FICHIER_ERR si le fichier n'a pas pu être ouvert
    //      (Par exemple si le fichier n'existe pas ou qu'il
    //      est en lecture seule)

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

    void ModifierMatchs(int const heure = -1);
    // Mode d'emploi :
    // Modifie la manière dont le MoteurES cherche les sites
    // dans le log
    // Paramètres :
    // heure : L'heure à choisir. Mettre -1 pour ignorer.

    CodeRetourArgument GestionArguments(int const nombreArguments, char* const arguments[]);
    // Mode d'emploi :
    // Gère la gestion des arguments passés au programme par l’utilisateur.
    // Les arguments sont les même arguments que ceux de la fonction main.

    void AfficherAide() const;
    // Mode d'emploi :
    // Affiche l'aide du programme dans la sortie standard

    void ParserLog();
    // Mode d'emploi :
    // Lis l'intégralité du log ouvert précédemment à l'aide de
    // OuvrirFichierLog(). Ne fait rien si aucun fichier n'a été ouvert.

    bool FaireGraphe() const;
    // Mode d'emploi :
    // Crée le graphe dans un fichier ayant pour nom la string
    // nomFichierSortie. Renvoie false si le fichier ne peut
    // pas être crée ou écrit, sinon renvoie true.

//-------------------------------------------- Constructeurs - destructeur
    MoteurES ();
    // Mode d'emploi :
    // Crée un Moteur d'Entrées Sorties.

    virtual ~MoteurES ();
    // Mode d'emploi :
    // Détruit le moteur et le site relié.

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés

    unordered_set<string> blackListExtension; // La liste des extensions de fichiers ignorée.

    regex apacheLogRegex;
    ifstream fichierLog; // Le fichier de log que l'on lit.
    bool verbose; // Si l'on doit afficher chaque information lue dans le ficher log.
    Site *leSite;
    string leSiteNom;

    string nomFichierSortie;
    bool afficherSiteExternes;

    bool afficherFichiersPlusConsultes;

};


#endif // MOTEURES_H
