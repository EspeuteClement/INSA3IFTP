/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 2015/10/09
    copyright            : (C) 2015/10/092015 par cespeute & brenault
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    void Afficher ();
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

    void Ajuster (int uneTaille);
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
    int taille;
    int *tableau;
};

#endif // COLLECTION_H
