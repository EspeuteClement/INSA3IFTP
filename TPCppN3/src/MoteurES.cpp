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

//----------------------------------------------------------- Constantes
const uint32_t NB_PREMIERS = 10;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
CodeRetourMoteurES MoteurES::OuvrirFichierLog(string const chemin)
{
	// Si il n'y a pas déjà un fichier ouvert.
	if (!FichierEstOuvert())
	{
		// On tente d'ouvrir le fichier.
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
	// Créer un DonneesRetour avec pour données le
	// cas où l'on a atteint la fin du fichier.
	DonneesLog DonneesRetour("",0,"","","",END_FILE);
	if (FichierEstOuvert())
	{
		string ligneLue;
		if(getline(fichierLog,ligneLue))
		{

			smatch matchLog;
			if (regex_search(ligneLue,matchLog,apacheLogRegex))
			{
				// Vérifier si l'extension du fichier visité n'est pas ignorée.
				string extension = std::string(matchLog[2].first, matchLog[2].second);
				if (blackListExtension.size()==0 || ! (blackListExtension.find(extension) != blackListExtension.end()))
				{
					//Extraire une par une toutes les données lues par la regex.
					DonneesRetour.FichierDestination = std::string(matchLog[1].first, matchLog[1].second);
					DonneesRetour.CodeHttp 			 = atoi(std::string(matchLog[3].first, matchLog[3].second).c_str());
					DonneesRetour.Protocole 	     = std::string(matchLog[4].first, matchLog[4].second);
					DonneesRetour.SiteSource 		 = std::string(matchLog[5].first, matchLog[5].second);
					DonneesRetour.FichierSource      = std::string(matchLog[6].first, matchLog[6].second);
					DonneesRetour.Etat = OK;
					// Si on est en mode verbose, afficher toutes les infos lues.
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
				// Si la regex n'a pas fait de match, dire qu'il n'y a pas
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
	if (leSite != NULL)
	{
		do
		{
			//On lit une par une les lignes du log.
			resultat = LireLigneLog();
			if(resultat.Etat == OK)
			{
				// Si lien interne.
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

		if (afficherFichiersPlusConsultes)
		{
			leSite->AfficherPremiers(NB_PREMIERS);
		}
	}
}

bool MoteurES::FaireGraphe() const
{
	// Si le chemin de sortie n'est pas vide.
	if (nomFichierSortie.compare("") != 0)
	{
		ofstream fichierSortie(nomFichierSortie);
		if(fichierSortie.is_open())
		{
			leSite->FaireGraphe(fichierSortie);

			fichierSortie.close();
			return true;
		}
		cerr << "Erreur : Impossible d'écrire le fichier " << nomFichierSortie;
	}
	return false;
}

void MoteurES::ModifierMatchs(int const heure)
{
	// Cette méthode construit la string Regex utilisé pour lire les lignes de
	// log Apache.

	/*
	Explications du REGEX :	(note dans le code c++ les \ ont du être échappés
	d'où le fait qu'on ait des \\ dans le code.)

	Lecture du timestamp :
	\[\d+\/\w+\/\d+:

	Lecture de l'heure d'arrivée du message : Note : il suffit de remplacer
	ce code par un nombre pour ignorer tous les logs qui ne sont pas arrivés
	à une heure donnée.
	\d+

	Lecture de la page demandée :
		:.*\"GET
		Groupe de captures :
	 	|		#1               |
		|	       	   |   #2  | |
		([^\s?;]*[/\. ]([^\s?;]*))
		Fin du block page demandée
		[ ?;].*\"

	Capture du code HTML (non utilisé mais peut être utile pour l'évolution
	du programme)
	 (\d+)

	Lecture de la page source :
		 |    4#   ||  #5  || #6|
	 .*\"(\w+:\/\/|)([^//]*)(\S+)\"

	Le reste du message (l'user agent ) est ignoré.

	Voici les différents champs captés par le regex :
		#1 : Site de destination
		#2 : Extension du site
		#3 : Code HTTP
		#4 : Protocole
		#5 : Site d'origine
		#6 : Fichier d'origine
	*/

	// La base du regex permet de s'assurer que chaque ligne commence par
	// la date.
	string constructeur = "\\[\\d+\\/\\w+\\/\\d+:";

	// Ensuite, si on a décidé d'exclure une heure, on la rajoute à la regex.
	if (heure >= 0 && heure <= 23)
	{
		if (heure/10 >= 1)
		{
			constructeur+=to_string(heure);
		}
		else
		{
			constructeur+="0"+to_string(heure);
		}
	}
	else
	{
		// Sinon on ajoute simplement le code pour n'importe quel chiffre.
		constructeur+="\\d+";
	}
	// Enfin, on ajoute le reste de la regex.
	constructeur+=":.*\"GET ([^\\s?;]*[/\\. ]([^\\s?;]*))[ ?;].*\" (\\d+).*\"(\\w+:\\/\\/|)([^//]*)(\\S+)\"";

	// On construit la regex avec la string que l'on a crée.
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
					case 'h': // Afficher l'aide.
	#ifdef MAP
		cout << "Argument h parsé" << endl;
	#endif
						return AIDE_ARG;
					break;

					case 'g': // Ajouter fichier de sortie.
					#ifdef MAP
						cout << "Argument g parsé" << endl;
					#endif
						i++;
						leSiteNom = string(arguments[i]);
					break;

					case 'e': // Exclure les extensions de fichier données.
					#ifdef MAP
						cout << "Argument e parsé" << endl;
					#endif
						blackListExtension.insert("png");
						blackListExtension.insert("gif");
						blackListExtension.insert("jpg");
						blackListExtension.insert("jpeg");
						blackListExtension.insert("ico");
						blackListExtension.insert("css");
						blackListExtension.insert("js");
					break;

					case 's':
						i++;
						leSiteNom = arguments[i];
					break;

					case 'v': // Mode verbose (pour les tests).
						verbose = true;
					break;

					case 'q':
						afficherFichiersPlusConsultes = false;
					break;
					case 'x': // Mode verbose (pour les tests).
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

		// On choisit le dernier argument comme étant le chemin à choisir,
		// peu importe les autres arguments lus (Le programme affichera une
		// erreur si le fichier n'existe pas).
		string chemin(arguments[nombreArguments-1]);
		#ifdef MAP
			cout << "Argument chemin parsé :" << chemin << endl;
		#endif

		// Si on arrive pas à ouvrir le fichier, erreur d'argument.
		if (OuvrirFichierLog(chemin) != FICHIER_OK)
		{
			cerr << "Erreur : Impossible d'ouvrir le fichier de log " << chemin << endl;
			return PAS_FICHIER;
		}

		// Enfin, on initialise l'heure choisie pour le filtrage
		// (par défaut -1, donc toutes les heures).
		ModifierMatchs(heure);
		leSite = new Site(leSiteNom);
		return OK_ARG;

	} // endif nombreArgument > 0

	cout << "Nombre d'arguments incorrect" << endl;
	return ERR_ARG;
}


void MoteurES::AfficherAide() const
{
	cout << endl;
	cout << "=== Aide ===\n" << endl;
	cout << "Analyse un fichier de log Apache pour faire la liste des liens \
entre les différentes pages." << endl;
	cout << "Usage : ./analog [options] nomfichier.log" << endl;
	cout << "Options :" << endl;
	cout << "-h : Affiche cette aide" << endl;
	cout << "-g nomfichier.dot : Crée un fichier GraphViz des liens entre les\
pages visitées dans le fichier fourni en argument" << endl;
	cout << "-e : Exclue les extensions de type .png, .jpg, .jpeg, .ico, .css,\
	 .js, .gif dans l'analyse du log." << endl;
	cout << "-t heure : Permet de ne prendre en compte que les visites qui \
ont eu lieu à l'heure donnée en paramètre." << endl;
	cout << "-v : (débug) affiche chaque information lue dans le log pour \
chaque ligne de celui-ci" << endl;
	cout << "-q : N'affiche pas la liste des 10 pages les plus visitées" << endl;
	cout << "-s nom_du_site : Change le nom du site à analyser" << endl;
}


//-------------------------------------------- Constructeurs - destructeur
MoteurES::MoteurES()
{
#ifdef MAP
    cout << "Appel au premier constructeur de <MoteurES>" << endl;
#endif
    ModifierMatchs();

		verbose = false;
		leSite = NULL;
		leSiteNom = "intranet-if.insa-lyon.fr";

		nomFichierSortie = "";
		afficherSiteExternes = false;

		afficherFichiersPlusConsultes = true;
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
