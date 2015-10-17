/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : 2015/10/09
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
                        //plus petite que le nombre d'éléments du tableau
    PAS_ERR     = 1     // Si la fonction s'est correctement exécutée
};
// Enumération des codes de retour pour la fonction Ajuster

//------------------------------------------------------------------------
// Rôle de la classe <Collection>
// Gère le stockage, la modification et l'affichage d'un ensemble de nombres
// entiers. Le stockage est réalisé dans un tableau d'entiers (int) géré de
// façon dynamique simple. Les redondances sont acceptées. Les valeurs ne sont
// pas triées.
//------------------------------------------------------------------------
class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher () const;
    // Mode d'emploi :
    // Imprime dans un terminal chaque élément de la Collection un a un, dans l'
    // ordre de leur apparition dans le tabelau, suivis par un saut de ligne. Si
    // DEBUG est déclaré, alors le nombre d'éléments et la taille allouée sont
    // affichés après.

    void Ajouter (int valeur);
    // Mode d'emploi :
    // Ajoute la valeur entière donnée à l'extrêmité du tableau contenant la
    // Collection et ajuste celle-ci si nécessaire.

    void Retirer (int valeur, int occurencesNb);
    // Mode d'emploi :
    // Supprime au plus un nombre occurencesNb d'occurences de la valeur donnée
    // en paramètre si elle est présente, et ajuste a chaque fois la quantité de
    // mémoire utilisée. Si occurencesNb < 0, alors toutes les occurences sont
    // supprimées.

    int Ajuster (unsigned int uneTaille);
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
    // Mode d'emploi : Ajoute les éléments de la collection donnée après ceux de
    // la courante en réajustant la taille du tableau de la courante si
    // nécessaire.

//-------------------------------------------- Constructeurs - destructeur
    Collection (unsigned int uneTaille);
    // Mode d'emploi : Créé une collection pouvant accueillir uneTaille éléments
    // sans avoir besoin d'être redimensionnée. Affiche "Appel au premier
    // constructeur de <Collection>" si MAP est définie.

    Collection (unsigned int uneTaille, int *unTableau);
    // Mode d'emploi : Crée une collection pouvant accueillir uneTaille éléments
    // sans avoir besoin d'etre redimensionnée, et lui ajoute chacun des
    // elements du tableau donné. Affiche "Appel au second constructeur de
    // <Collection>" si MAP est définie.
    // Contrat : On assume que la taille donnée en paramètre est égale à la
    // taille réelle du tableau donné.

    virtual ~Collection ();
    // Mode d'emploi : Détruit la collection courante. Affiche "Appel au
    // destructeur de <Collection>" si MAP est définie.

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Attributs privés
    unsigned int nbElements;
    unsigned int alloue;
    int *tableau;

    /////// CLASSES NON DEMANDEES MAIS UTILES POUR LE TEST /////////////
    void printNbElements () const;
    // Affiche le nombre d'éléments de la Collection

    void printAlloue () const;
    //Affiche la taille allouée de la Collection
};

#endif // COLLECTION_H
