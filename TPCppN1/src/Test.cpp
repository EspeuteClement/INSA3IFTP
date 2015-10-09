/*************************************************************************
                           Test  -  description
                             -------------------
    début                : 2015/10/09
    copyright            : (C) 2015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <Test> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Test.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Test::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Test & Test::operator = ( const Test & unTest )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Test::Test ( const Test & unTest )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Test>" << endl;
#endif
} //----- Fin de Test (constructeur de copie)


Test::Test ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Test>" << endl;
#endif
} //----- Fin de Test


Test::~Test ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Test>" << endl;
#endif
} //----- Fin de ~Test


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
