/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 2015/10/09
    copyright            : (C) 2015 par cespeute & brenault
*************************************************************************/

//---------- Realisation de la classe <Collection> (fichier Collection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques
// type Collection::Methode ( liste de parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


//------------------------------------------------- Surcharge d'operateurs
Collection & Collection::operator = ( const Collection & uneCollection )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Collection::Collection ( const Collection & uneCollection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Collection>" << endl;
#endif
} //----- Fin de Collection (constructeur de copie)


Collection::Collection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif
} //----- Fin de Collection


Collection::~Collection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees
