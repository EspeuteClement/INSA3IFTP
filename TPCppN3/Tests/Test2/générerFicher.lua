nombreLignes,banHeure,configBanned = ...

banHeure = tonumber(banHeure)

if configBanned == "false" then
	configBanned = false;
else
	configBanned = true;
end

-- Génére un fichier de log aléatoire, et crée le fichier de sortie équivalent

fin = io.open("fichier.txt", "w")
fout = io.open("std.out","w")
frun = io.open("run","w")

--nombreLignes = 200;
--banHeure = 15;

--configBanned = false;

mois = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Nov","Dec"}

fichiers = {"/temps/4IF16.html/","/temps/4IF17","/temps/4IF18","/temps/4IF19","/temps/4IF20","/temps/3IF38","/temps/","/temps/style_emploi_du_temps.css","/temps/InsaIF.ico","/temps/FondInsa.jpg","/temps/3IF37","/temps/precedent.gif","/temps/choix.gif","/temps/suivant.gif","/temps/3IF38","/favicon.ico","/temps/3IF39","/SiteWebIF/Intranet-etudiant.php","/SiteWebIF/Intranet-etudiant.phpticketlNEzic9e5btb4JQ1Nw-dsi-vm03","/SiteWebIF/Intranet-etudiant.php","/stages/Listestage.php","/temps/3IF1.ics","/temps/","/temps/style_emploi_du_temps.css","/temps/FondInsa.jpg","/temps/InsaIF.ico","/","/favicon.ico","/temps/index","/temps/precedent.gif","/temps/3IF37","/temps/choix.gif","/temps/suivant.gif","/temps/3IF37","/temps/3IF38","/temps/3IF39","/temps/3IF38","/temps/3IF39","/temps/3IF40","/temps/3IF41","/temps/3IF42","/temps/3IF43","/temps/MK.ics","/","/favicon.ico","/temps/3IF44","/temps/3IF45","/SiteWebIF/Intranet-etudiant.php","/SiteWebIF/Intranet-etudiant.phpticket=ST-341682-RjfRTgziibddmotBJFlo-dsi-vm03","/SiteWebIF/Intranet-etudiant.php","/stages/style_pfe.css","/stages/InsaIF.ico","/stages/FondInsa.jpg","/stages/bandeauFinal.jpg","/notesif","/notesif/","/temps/3IF46","/temps/3IF47","/temps/3IF48","/temps/3IF49","/temps/3IF50","/temps/3IF51","/temps/3IF52","/temps/3IF1","/temps/3IF2","/temps/4IF3.ics","/notesif/RSS/RSS_4IF.xml","/temps/3IF3","/temps/3IF4","/temps/3IF5","/temps/3IF6","/temps/3IF7","/temps/3IF8","/temps/3IF9","/temps/3IF10","/temps/3IF11","/temps/3IF12","/temps/3IF13","/temps/3IF14","/temps/3IF15","/temps/3IF16","/temps/3IF17","/temps/3IF18","/temps/3IF19","/temps/3IF20","/temps/3IF21","/temps/3IF22","/notesif","/notesif/","/cas/themes/insa/media/favicon.ico","/notesif/RSS/RSS_3IF.xml","/stages/ListePFE.php","/SiteWebIF/Intranet-etudiant.php","/SiteWebIF/Intranet-etudiant.phpticket=ST-18983-qoy9blUTrJiM4PYIhncG-dsi-vm04","/SiteWebIF/Intranet-etudiant.php","/notesif/","/","/favicon.ico"};
--fichiers = {"/","/poulet.html","/poulet/"}

suffixList = {".html",".poulet",".php"}
suffixBanned = {".jpg",".css",".ico",".js"}

suffix2 = {"","",";sdifsjdf","?tests"}

frun:write("../../out/executable.out -v -t "..banHeure.." -q")
if (configBanned) then
	frun:write(" -e")
end
frun:write(" fichier.txt")
for i = 1, nombreLignes do

	-- Adresse IP :
	ip = "" .. math.random(0,255) .. "." .. math.random(0,255) .. "." .. math.random(0,255) .. "." .. math.random(0,255)
	randHeure = math.random(0,23);

	banned = false
	if (math.random(10) < 7) then
		suffix = suffixList[math.random(#suffixList)]
	else
		suffix = suffixBanned[math.random(#suffixBanned)]
		banned = configBanned
	end
	randAdresse = fichiers[math.random(#fichiers)]..suffix

	codeHttp = 200
	randSource = fichiers[(i%#fichiers)+1]
	agent = "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1";

	-- Date :

	fin:write(ip.." - - ")
	fin:write("["..math.random(1,31).."/"..mois[math.random(#mois)].."/2015:"..randHeure..":"..(math.random(60)-1)..":"..(math.random(60)-1).." +0200] ")
	
	

	fin:write("\"GET "..randAdresse..suffix2[math.random(#suffix2)].." HTTP/1.1\" ")
	fin:write(codeHttp .. " " .. math.random(50000) .. " ")
	

	fin:write("\"http://intranet-if.insa-lyon.fr"..randSource.."\" ")
	fin:write("\""..agent.."\"")

	if (i ~= nombreLignes) then
		fin:write("\r\n")
	end

	if (banHeure == -1 or randHeure == banHeure) and not banned then
		fout:write(randAdresse.." ")
		fout:write(codeHttp.." ")
		fout:write("http:// intranet-if.insa-lyon.fr ")
		fout:write(randSource)
		if (i ~= nombreLignes or true) then
			fout:write("\r\n")
		end
	end
end