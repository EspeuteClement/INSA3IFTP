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
#define MAP

//----------------------------------------------------------- Enumérations
enum CodesRetour
{   ERR_TAILLE  = 0,    // Erreur de retour si la nouvelle taille est
                        //plus petite que le nombre d'élements du tableau
    PAS_ERR     = 1     // Si la fonction s'est correctement exécutée
};
// Enumération des codes de retour pour la fonction Ajuster

//------------------------------------------------------------------------
// Role de la classe <Collection>
// Gere le stockage, la modification et l'affichage d'un ensemble de nombres
// entiers. Le stockage est realise dans un tableau d'entiers (int) gere de
// facon dynamique simple. Les redondances sont acceptées. Les valeurs ne sont
// pas triees.
//------------------------------------------------------------------------
class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    void Afficher () const;
    // Mode d'emploi :
    // Imprime dans un terminal chaque element de la Collection un a un, suivis
    // par un saut de ligne. Si DEBUG est declare, alors le nombre d'elements et
    // la taille allouee apres.

    void Ajouter (int valeur);
    // Mode d'emploi :
    // Ajoute la valeur entiere a l'extremite du tableau contenant la Collection
    // et ajuste celle-ci si necessaire.

    void Retirer (int valeur, int occurencesNb);
    // Mode d'emploi :
    // Supprime au plus un nombre occurencesNb d'occurences de la valeur donnee
    // en parametre si elle est presente, et ajuste a chaque fois la quantite de
    // memoire utilisee. Si occurencesNb < 0, alors toutes les occurences sont
    // supprimees.

    int Ajuster (unsigned long int uneTaille);
    // Mode d'emploi :
    // Réajuste le tableau pour que sa taille soit égale à uneTaille.
    // Si la nouvelle taille est plus petite que le nombre d'éléments
    // présents dans le tableau, l'ajustement n'a pas lieu et la fonction
    // retourne ERR_TAILLE.
    // Si l'ajustement du tableau s'est bien déroulée, la fonction renvoie
    // PAS_ERR (Equivalent à vrai).
    // Contrat :
    // La nouvelle taille ne doit pas être trop grande (sinon création d'une
    // exception non gérée)

    void Reunir (const Collection &Collection);
    // Mode d'emploi : Ajoute les elements de la collection donnee apres ceux de
    // la courante en reajustant la taille du tableau de la courante si
    // necessaire.

//-------------------------------------------- Constructeurs - destructeur
    Collection (unsigned int uneTaille);
    // Mode d'emploi : Cree une collection pouvant accueillir uneTaille elements
    // sans avoir besoin d'etre redimensionnee. Affiche "Appel au premier
    // constructeur de <Collection>" si MAP est definie.

    Collection (unsigned int uneTaille, int *unTableau);
    // Mode d'emploi : Cree une collection pouvant accueillir uneTaille elements
    // sans avoir besoin d'etre redimensionnee, et lui ajoute chacun des
    // elements du tableau donne. Affiche "Appel au second constructeur de
    // <Collection>" si MAP est definie.
    // Contrat : On assume que la taille donnee en parametre est egale a la
    // taille reelle du tableau donne.

    virtual ~Collection ();
    // Mode d'emploi : Detruit la collection courante. Affiche "Appel au
    // destructeur de <Collection>" si MAP est definie.

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
};

#endif // COLLECTION_H
