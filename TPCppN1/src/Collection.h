/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 2015/10/09
    copyright            : (C) 2015/10/092015 par cespeute & brenault
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if ! defined ( COLLECTION_H )
#define COLLECTION_H
//#define MAP
#define DEBUG


//----------------------------------------------------------- Enumérations
enum CodesRetour
{   ERR_TAILLE  = 0,    // Erreur de retour si la nouvelle taille est 
                        //plus petite que le nombre d'élements du tableau
    PAS_ERR     = 1     // Si la fonction s'est correctement exécutée
};
// Enumération des codes de retour pour la fonction Ajuster

//------------------------------------------------------------------------
// Role de la classe <Collection>
//
//
//------------------------------------------------------------------------

class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    void Afficher () const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter (int valeur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Retirer (int valeur, int occurencesNb);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Ajuster (int uneTaille);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Reunir (const Collection &Collection);
    // Mode d'emploi :
    //
    // Contrat :
    //

    

//-------------------------------------------- Constructeurs - destructeur
    Collection (int uneTaille);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Collection (int uneTaille, int *unTableau);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Collection ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    




//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs prives
    int nbElements;
    int alloue;
    int *tableau;


    /////// CLASSES NON DEMANDEES MAIS UTILES POUR LE TEST /////////////
    void printNbElements () const;
    // Affiche le nombre d'élements du Collection
    
    void printAlloue () const;
    //Affiche la taille Allouee de la Collection


//---------------------------------------------------------- Classes amies
    // On a besion que Test soit ami pour
};

#endif // COLLECTION_H
