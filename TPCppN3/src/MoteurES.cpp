/*************************************************************************
                           MoteurES  -  description
                             -------------------
    début                : 2015/11/27
    copyright            : (C) 2015/27/092015 par cespeute & brenault
*************************************************************************/

//---------- Réalisation de la classe <MoteurES> (fichier MoteurES.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "MoteurES.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void MoteurES::Afficher10Premiers ()
{
}

void MoteurES::FaireGraphe (string nomDuFichier) const
{
}

CodeRetourMoteurES MoteurES::OuvrirFichierLog(string chemin)
{
	// Si il n'y à pas déjà un fichier ouvert
	if (!FichierEstOuvert())
	{
		// On tente d'ouvrir le fichier
		fichierLog.open(chemin,ifstream::in);

		// Messages de retour en fonction de si on à réussi ou pas
		// à ouvrir le fichier.
		if (FichierEstOuvert())
		{
#ifdef MAP
			cout << "L'ouverture du fichier " << chemin << " à réussie" << endl;
#endif
		return FICHIER_OK;
		}


	}

#ifdef MAP
		cout << "L'ouverture du fichier " << chemin << " à échouée" << endl;
#endif
	return FICHIER_ERR;	
}

CodeRetourMoteurES MoteurES::FermerFichierLog()
{
	if (FichierEstOuvert())
	{
		fichierLog.close();
		if (!FichierEstOuvert())
		{	
#ifdef MAP
			cout << "La fermeture du fichier à réussie" << endl;
#endif
			return FICHIER_OK;
		}
	} 

#ifdef MAP
		cout << "La fermeture du fichier à échouée" << endl;
#endif

	return FICHIER_ERR;
}

DonneesLog MoteurES::LireLigneLog()
{
	// Créer un Données Retour avec pour données le
	// cas où l'on a atteint la fin du fichier
	DonneesLog DonneesRetour("",0,"","","",END_FILE);
	if (FichierEstOuvert())
	{
		string ligneLue;
		if(getline(fichierLog,ligneLue))
		{
			
			smatch matchLog;
			if (regex_search(ligneLue,matchLog,apacheLogRegex))
			{
				// Vérifier si l'extension du fichier visité n'est pas ignorée
				string extension = std::string(matchLog[2].first, matchLog[2].second);
				if (blackListExtension.size()==0 || ! (find(blackListExtension.begin(), blackListExtension.end(), extension ) != blackListExtension.end()))
				{
					DonneesRetour.FichierDestination = std::string(matchLog[1].first, matchLog[1].second);
					DonneesRetour.CodeHttp 			 = atoi(std::string(matchLog[3].first, matchLog[3].second).c_str());
					DonneesRetour.Protocole 	     = std::string(matchLog[4].first, matchLog[4].second);
					DonneesRetour.SiteSource 		 = std::string(matchLog[5].first, matchLog[5].second);
					DonneesRetour.FichierSource      = std::string(matchLog[6].first, matchLog[6].second);
					DonneesRetour.Etat = OK;
				}
				else
				{
					DonneesRetour.Etat = NON_MATCH;
				}
				
			}
			else
			{
				// Si le regex n'a pas fait de match, dire qu'il n'y à pas
				// eu de match.
				DonneesRetour.Etat = NON_MATCH;
			}
		}
	}
	return DonneesRetour;
}


void MoteurES::ModifierMatchs(vector<string> extensions, int heure)
{
	string constructeur = "\\[\\d+\\/\\w+\\/\\d+:";
	if (heure >= 0 && heure <= 23)
	{
		constructeur+=to_string(heure);
	}
	else
	{
		constructeur+="\\d+";
	}
	constructeur+=":.*\"GET (\\S*[/.](\\w*))[ ?].*\" (\\d+).*\"(\\w+:\\/\\/|)([^//]*)(\\S+)\"";

	blackListExtension = extensions;

	apacheLogRegex = regex(constructeur);
}


//-------------------------------------------- Constructeurs - destructeur
MoteurES::MoteurES ()
{
#ifdef MAP
    cout << "Appel au premier constructeur de <MoteurES>" << endl;
#endif
    ModifierMatchs();
}

MoteurES::~MoteurES ()
{
#ifdef MAP
    cout << "Appel au destructeur de <MoteurES>" << endl;
#endif
}
