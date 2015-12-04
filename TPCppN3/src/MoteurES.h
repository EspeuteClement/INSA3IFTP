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

#include <fstream>

//------------------------------------------------------ Include personnel


//----------------------------------------------------------- Enumérations

/** L'ensemble des codes retours utilisées par les
*   méthodes de la classe MoteurES
*/
enum CodeRetourMoteurES
{
    FICHIER_OK, // L'ouverture du fichier à bien eu lieu
    FICHIER_ERR // L'ouverture du fichier à échouée.
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

    /** Tente d'ouvrir le fichier situé au <em>chemin</em>
    *   donné en paramètre.
    *   @param chemin La position du fichier sur le disque
    *   @return Un CodeRetourMoteurES qui vaut :
    *   <ul>
    *       <li> FICHIER_OK si l'ouverture du fichier s'est bien
                 déroulée <li>
            <li> FICHIER_ERR si l'ouverture du fichier s'est mal
                 déroulée <li>
    *   </ul>
    */
    CodeRetourMoteurES OuvrirFichierLog(string chemin);

    /** Tente de fermer le fichier log actuellement ouvert
    *   @return Un CodeRetourMoteurES qui vaut :
    *   <ul>
    *       <li> FICHIER_OK si la fermeture du fichier s'est bien
                 déroulée <li>
            <li> FICHIER_ERR si la fermeture du fichier s'est mal
                 déroulée <li>
    *   </ul>
    */
    CodeRetourMoteurES FermerFichierLog();

    /** Renvoie vrai si un fichier est actuellement ouvert par
    *   ce MoteurES.
    */
    inline bool FichierEstOuvert() const {return fichierLog.is_open();} ;

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

    ifstream fichierLog; /**Le fichier de log que l'on lit*/
};




// TODO : Voir si on doit bouger cette struct ...

/** Représente l'ensemble des données utiles (pour notre application)
*   d'une ligne de log apache.
*/
struct DonneesLog{
    public :
        //Note : L'ordre correspond à l'ordre des données dans le log apache

        string SiteDestination; /** Le site vers où l'on va */
        unsigned int CodeHttp;  /** Le code http correspondant à la */

        //TODO : Voir si on mets pas ça en enum ...
        string Protocole;       /** Le protocole qui à été utilisé pour la requête*/
        string SiteSource;      /** Le site d'où l'on vient */

        /** Constructeur qui initialise l'ensemble des
        *   données de la structure dans l'ordre dans
        *   lesquelles elles sont situés dans le
        *   log apache.
        */
        DonneesLog( string siteDestination, 
                    unsigned int codeHttp,
                    string protocole,
                    string siteSource ):
                    siteDestination(siteDestination),
                    codeHttp(codeHttp),
                    protocole(protocole),
                    siteSource(siteSource);
        {

        };
};

#endif // MOTEURES_H
