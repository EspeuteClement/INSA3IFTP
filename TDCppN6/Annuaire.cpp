#include "Annuaire.h"

const char SEP='|';

void Annuaire::Ajouter(Abonne &a) {
  if (!a.nom.empty()) {
    pagesBlanches.insert(make_pair(a.nom, a.infos));
  }
}

void Annuaire::Ajouter(string nomFichier) {
  ifstream file(nomFichier.c_str());
  if (file) {
    Abonne a;
    while (file >> a) {
      Ajouter(a);
    }
  }
  else {
    cerr << "Probleme d'ouverture" << endl;
  }
}

void Annuaire::Afficher(string nom, ostream &f) const {
  Tdico::const_iterator debut, fin;
  if (nom.empty()) {
    debut = pagesBlanches.begin();
    fin = pagesBlanches.end();
  }
  else {
    debut = pagesBlanches.lower.bound(nom);
    fin = pagesBlanches.upper.bound(nom);
  }
  for (debut; debut != fin; debut++) {
    f << Abonne(debut->first, debut->second);
  }
}

Abonnne Annuaire::RechercheInversee(string tel)const {
  Tdico::const_iterator debut, fin;
  debut = pagesBlanches.begin();
  fin = pagesBlanches.end();

  while (debut != fin && debut->second.numero != tel) {
    debut++;
  }
  if (debut == fin) {
    return Abonnne();
  }
  else {
    return (Abonne(debut->first, debut->second));
  }
}

Annuaire::Annuaire() {
  monAnnuaire = new Tdico();
}
Annuaire::Annuaire() {
  delete monAnnuaire;
}
