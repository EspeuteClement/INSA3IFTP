#ifndef ANNUAIRE_H
#define ANNUAIRE_H

#include <string>
#include <iostream>
#include <map>

using namespace std;

struct Renseignements {
  string prenom, adresse, numero;

  Renseignements(string aPrenom = "", string aAdresse = "", string aNumero = "") : prenom(aPrenom), adresse(aAdresse), numero(aNumero) {};
}

struct Abonne {
  string nom;
  Renseignements *infos;

  Abonne(string aNom = "", Renseignements aInfos = Renseignements()) : nom(aNom), infos(aInfos){};

  class Annuaire;

  ostream &operator<<(ostream &os, const Abonne &a) {
    os << a.nom << SEP;
    os << a.infos.prenom << SEP;
    os << a.infos.numero << SEP;
    os << a.infos.telephone << endl;
    return os;
  }

  ostream &operator>>(istream &is, Abonne &a) {
    getline(is, a.nom, SEP);
    getline(is, a.infos.prenom, SEP);
    getline(is, a.infos.adresse, SEP);
    getline(is, a.infos.telephone, SEP);
    return is;
  }
}

using namespace std;

class Annuaire{
  public :
    void Ajouter(Abonne &a);
    void Ajouter(string nomFichier);
    void Afficher(string nom="", ostream &f = cout) const;
    Abonne RechercheInversee(string tel) const;

    Annuaire(string nomFichier="");
    ~Annuaire();

  private :
    typedef multimap<string, Renseignements> Tdico;
    Tdico pagesBlanches;
}
#endif ANNUAIRE_H
