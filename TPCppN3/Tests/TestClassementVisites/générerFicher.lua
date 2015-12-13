math.randomseed( os.time() )

banHeure = tonumber(banHeure)

if configBanned == "false" then
	configBanned = false;
else
	configBanned = true;
end

fin = io.open("fichier.txt", "w")
fout = io.open("std.out","w")
frun = io.open("run","w")

frun:write("../../out/executable.out fichier.txt")

-- Génere une liste de nbre nombres et la trie, puis génère une liste de
-- nbre noms aléatoires
nbre = ...
nbre = tonumber(nbre)
liste = {}
for i=1,nbre do
	table.insert(liste,math.random(5000))
end
table.sort(liste)

i = 1
while i <= nbre do
	if (liste[i] == liste[i+1]) then
		table[i+1] = i + 1
	else
		i = i + 1	
	end
end

listeNom = {}
for i=1,nbre do
	str = ""
	for i = 1, 10 do
		str = str .. string.char(math.random(65,90))
	end
	table.insert(listeNom,str)
end

-- Créer les logs

for i=nbre,1,-1 do

		for j=1,liste[i] do
			log = "192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] \"GET /"
			.. listeNom[i] ..  ".html HTTP/1.1\" 200 12106 \"http://intranet-if.insa-lyon.fr/"
			.. listeNom[math.random(nbre)] .. ".html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"\n";
			fin:write(log)
		end
		if(nbre - i < 10) then
				fout:write("/"..listeNom[i] .. ".html ("..liste[i].." hits)\n")
		end

end