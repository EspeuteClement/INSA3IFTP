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
CodeRetourMoteurES MoteurES::OuvrirFichierLog(string const chemin)
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
				cout << "L'ouverture du fichier " << chemin << " a réussi" << endl;
	#endif
		return FICHIER_OK;
		}


	}

	#ifdef MAP
			cout << "L'ouverture du fichier " << chemin << " a échoué" << endl;
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
				cout << "La fermeture du fichier a réussi" << endl;
	#endif
			return FICHIER_OK;
		}
	}

	#ifdef MAP
			cout << "La fermeture du fichier a échoué" << endl;
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
					// Si on est en mode verbose, afficher toutes les infos lues
					if (verbose)
					{
						cout <<
						DonneesRetour.FichierDestination << " " <<
						DonneesRetour.CodeHttp << " " <<
						DonneesRetour.Protocole << " " <<
						DonneesRetour.SiteSource << " " <<
						DonneesRetour.FichierSource << endl;
					}
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

void MoteurES::ParserLog()
{
	DonneesLog resultat("",0,"","","",END_FILE);
	do
	{
		resultat = LireLigneLog();
		if(resultat.Etat == OK)
		{
			// Si lien interne
			if(0==resultat.SiteSource.compare(leSite->GetAdresse()))
			{
				leSite->AjouterVisite(resultat.FichierSource,resultat.FichierDestination);
			}
			else
			{
				if (!afficherSiteExternes)
				{
					leSite->AjouterVisite(resultat.FichierDestination);
				}
				else
				{
					string source = "externe : "+resultat.SiteSource+resultat.FichierSource;
					leSite->AjouterVisite(source,resultat.FichierDestination);
				}
			}
		}


	} while(resultat.Etat != END_FILE);

	if (afficher10)
	{
		leSite->AfficherPremiers(NB_PREMIERS);
	}
	
}

void MoteurES::FaireGraphe() const
{
	// Si le chemin de sortie n'est pas vide
	if (nomFichierSortie.compare("") != 0)
	{
		ofstream fichierSortie(nomFichierSortie);
		if(fichierSortie.is_open())
		{
			leSite->FaireGraphe(fichierSortie);

			fichierSortie.close();
		}

	}
}

void MoteurES::ModifierMatchs(int const heure)
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
	constructeur+=":.*\"GET ([^\\s?;]*[/.]([^\\s?;]*))[ ?;].*\" (\\d+).*\"(\\w+:\\/\\/|)([^//]*)(\\S+)\"";

	apacheLogRegex = regex(constructeur);
}

CodeRetourArgument MoteurES::GestionArguments(int const nombreArguments, char* const arguments[])
{

	#ifdef MAP
		cout << "Nombre d'arguments : " << nombreArguments << endl;
	#endif

	if (nombreArguments > 1)
	{

		vector<string> blackList = vector<string>();
		int heure = -1;
		int i;
		for (i = 0; i<nombreArguments; i++)
		{
			if (arguments[i][0] == '-')
			{
				switch (arguments[i][1]){
					case 'h': // Afficher l'aide
	#ifdef MAP
		cout << "Argument h parsé" << endl;
	#endif
						return AIDE_ARG;
					break;

					case 'g': // Ajouter fichier de sortie
					#ifdef MAP
						cout << "Argument g parsé" << endl;
					#endif
						i++;
						leSiteNom = string(arguments[i]);
					break;

					case 'e': // Exclure les fichiers donnés
					#ifdef MAP
						cout << "Argument e parsé" << endl;
					#endif
						blackListExtension.push_back("png");
						blackListExtension.push_back("gif");
						blackListExtension.push_back("jpg");
						blackListExtension.push_back("jpeg");
						blackListExtension.push_back("ico");
						blackListExtension.push_back("css");
						blackListExtension.push_back("js");
					break;

					case 's':
						i++;
						leSiteNom = arguments[i];
					break;

					case 'v': // Mode verbose (pour les tests)
						verbose = true;
					break;

					case 'q':
						afficher10 = false;
					break;
					case 'x': // Mode verbose (pour les tests)
						afficherSiteExternes = true;
					break;

					case 't': // Prendre en compte une heure donnée.
					#ifdef MAP
						cout << "Argument t parsé" << endl;
					#endif
						i++;
						heure = atoi(arguments[i]);
					break;
				}
			}
		}

		// On choisis le dernier argument comme étant le chemin à choisir,
		// peu importe les autres arguments lu (Le programme affichera une)
		// erreur si le fichier n'existe pas.
		string chemin(arguments[nombreArguments-1]);
		#ifdef MAP
			cout << "Argument chemin parsé :" << chemin << endl;
		#endif

		// Si on arrive pas à ouvrir le fichier, erreur d'argument
		if (OuvrirFichierLog(chemin) != FICHIER_OK)
		{
			cout << "Erreur : Fichier " << chemin << " introuvable." << endl;
			return ERR_ARG;
		}

		// Enfin, on initialise l'heure choisie pour le filtrage
		// (par défaut -1 donc toutes les heures)
		ModifierMatchs(heure);
		leSite = new Site(leSiteNom);
		return OK_ARG;

	} // endif nombreArgument > 0

	cout << "Nombre d'arguments incorrect" << endl;
	return ERR_ARG;
}

void MoteurES::AfficherAide() const
{
	cout << "\
=== Aide ===\n\
Analyse un fichier de log Appache pour faire la liste des liens entre\
les différentes pages.\n\
Usage : ./analog [options] nomfichier.log\n\
\n\
Options :\n\
-h : Affiche cette aide\n\
-g nomfichier.dot : Crée un fichier GraphViz des liens entre les pages\
visitées dans le fichier fourni en argument\n\
-e : Exclus les extensions de type .png, .jpg, .jpeg, .ico, .css, .js \
dans l'analyse du log.\
-t heure : Permets de ne prendre en compte que les visites qui ont eu lieu \
à l'heure donnée en paramètre.\n\
-v : affiche chaque information lue dans le log pour chaque ligne de celui ci\n";

}


//-------------------------------------------- Constructeurs - destructeur
MoteurES::MoteurES()
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
    if (leSite != NULL)
    {
    	delete leSite;
    }
    
}
