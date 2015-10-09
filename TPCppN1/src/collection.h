/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 2015/10/09
    copyright            : (C) 2015/10/092015 par cespeute & brenault
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ------
#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Collection>
//
//
//------------------------------------------------------------------------

class Collection : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'operateurs
    Collection & operator = ( const Collection & uneCollection );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Collection ( const Collection & uneCollection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Collection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Collection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Collection>

#endif // COLLECTION_H
