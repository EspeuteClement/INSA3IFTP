### COPILATION
# Le compilateur a utiliser
CC = g++
# L'editeur de lien à uttiliser
LINK = g++
# Argument pour changer le nom de la sortie du compilo
CC_OUTPUT_FLAG = -o
# Arguments pour le stade d'édition des liens
LINK_FLAG =
# Arguments pour le stade de compilation
CC_COMP_FLAG = -c -Wall
# Commande d'affichage
PRINT = @printf

### FICHIERS
# Nom du fichier de sortie
EXEC = executable.out
# Nom des fichiers sources
SRC = main.cpp Collection.cpp
# Nom du dossier avec les fichiers sources
SRC_FOLDER = ./
# Le dossier où metre les fichiers objs
OBJS_FOLDER = ./objs/newFolder/

### CLEAN
CLEAN = clean
# La commande pour clean
CLEAN_COMMAND = rm
# Les flags pour clean
CLEAN_FLAG = -f
# Les fichier a clean lors d'un clean
ADDITIONAL_CLEAN = core $(OBJS) $(EXEC)

### TARGET POUR LE DEBUGAGE
DEBUG = debug

### TARGET POUR LANCER LE PROGRAME APRES LE MAKE
RUN = run

### AFFICHER DU GRAS :
BOLD = \033[1m
RESET_BOLD = \033[21m

### VARIABLES ADDITIONELLES CREES AUTOMATIQUEMENT
#TRUE_SRC = $(addprefix SRC_FOLDER,SRC)
OBJS = $(subst .cpp,.o,$(addprefix $(OBJS_FOLDER),$(SRC)))

##########################################################################
############################LES CILBES : #################################
##########################################################################

# CIBLE ALL POUR TOUT BUILD
.PHONY : all
all : directories $(EXEC) 

# CIBLE OPTIONNELE POUR LANCER LE PROGRAMME APRES LE BUILD
$(RUN) : all
	$(PRINT) "$(BOLD)EXECUTION DE $(EXEC)\n$(RESET_BOLD)------------------\n"
	@./$(EXEC)

# EDITION DES LIENS :
$(EXEC) : $(OBJS)
	$(PRINT) "$(BOLD)EDITION DES LIENS\n\t$(RESET_BOLD)"
	$(LINK) $(CC_OUTPUT_FLAG) $(EXEC) $(OBJS) $(LINK_FLAG)

# CREER LES DOSSIERS MANQUANTS
.PHONY : createObjsFolder
directories : $(OBJS_FOLDER)

$(OBJS_FOLDER) :
	$(PRINT) "$(BOLD)CREATION DU REPERTOIRE $@\n\t$(RESET_BOLD)"
	mkdir -p $(OBJS_FOLDER)

# CREER LES FICHERS OBJETS
$(OBJS_FOLDER)%.o : %.cpp %.h
	$(PRINT) "$(BOLD)COMPILATION DE $<\n\t$(RESET_BOLD)"
	$(CC) $(CC_OUTPUT_FLAG) $@ $< $(CC_COMP_FLAG)

# PARTIE NETOYAGE
.PHONY : $(CLEAN)
$(CLEAN) : 
	$(PRINT) "$(BOLD)CLEAN$<\n\t$(RESET_BOLD)"
	$(CLEAN_COMMAND) $(CLEAN_FLAG) $(ADDITIONAL_CLEAN)
	$(PRINT) "\t"
	$(CLEAN_COMMAND) -fd $(OBJS_FOLDER)

# PARTIE DEBUG
.PHONY : $(DEBUG)
$(DEBUG) : 
	$(PRINT) "\033[35;1mCible de debug\n"

