/*************************************************************************
                           Test  -  description
                             -------------------
    d�but                : 2015/10/09
    copyright            : (C) 2015 par cespeute & brenault
*************************************************************************/

//---------- R�alisation de la classe <Test> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Test.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type Test::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
