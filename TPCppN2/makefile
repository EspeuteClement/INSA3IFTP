### COMPILATION
# Le compilateur a utiliser
CC = g++
# L'editeur de lien à utiliser
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
EXEC = out/executable.out
# Nom des fichiers sources
SRC = Main.cpp BinaryTree.cpp Node.cpp Sensor.cpp
# Nom du dossier avec les fichiers sources
SRC_FOLDER = src/
# Le dossier où metre les fichiers objs
OBJS_FOLDER = build/
# Le dossier où metre l'exec
EXEC_FOLDER = out/

### CLEAN
CLEAN = clean
# La commande pour clean
CLEAN_COMMAND = rm
# Les flags pour clean
CLEAN_FLAG = -f
# Les fichier à clean lors d'un clean
ADDITIONAL_CLEAN = core $(OBJS) $(EXEC)

# Création de dépendences
DEP_TARGET = dep

DEP_CMD = lua makedep.lua $(SRC)

DEP_FILE = dep/Deps.dep


### TARGET POUR LE DEBUGAGE
DEBUG = debug

### TARGET POUR LANCER LE PROGRAME APRES LE MAKE
RUN = run

### TARGET POUR LANCER LE PROGRAMME ET STOCKER LA SORTIE DANS UN FICHIER
RUN_AND_SAVE = runSave
# Destination de la sauvegarde
RUNSAVE_FILE = utils/dispTree/data.lua


### AFFICHER DU GRAS :
BOLD = \033[1m
RESET_BOLD = \033[21m

### VARIABLES ADDITIONELLES CREES AUTOMATIQUEMENT
#TRUE_SRC = $(addprefix SRC_FOLDER,SRC)
OBJS = $(subst .cpp,.o,$(addprefix $(OBJS_FOLDER),$(SRC)))

##########################################################################
############################LES CIBLES : #################################
##########################################################################



# CIBLE ALL POUR TOUT BUILD
.PHONY : all
all : directories $(EXEC) 



# CIBLE OPTIONNELE POUR LANCER LE PROGRAMME APRES LE BUILD
$(RUN) : all
	$(PRINT) "$(BOLD)EXECUTION DE $(EXEC)\n$(RESET_BOLD)------------------\n"
	@./$(EXEC)

$(RUN_AND_SAVE) : all
	$(PRINT) "$(BOLD)EXECUTION DE $(EXEC)\n$(RESET_BOLD)------------------\n"
	@./$(EXEC) > $(RUNSAVE_FILE)

.PHONY : $(DEP_TARGET)
$(DEP_TARGET) : $(DEP_FILE)

.PHONY : $(DEP_FILE)
$(DEP_FILE) :
	$(DEP_CMD)
	

# EDITION DES LIENS :
$(EXEC) : $(OBJS)
	$(PRINT) "$(BOLD)EDITION DES LIENS\n\t$(RESET_BOLD)"
	$(LINK) $(CC_OUTPUT_FLAG) $(EXEC) $(OBJS) $(LINK_FLAG)

# CREER LES DOSSIERS MANQUANTS
.PHONY : directories
directories : $(OBJS_FOLDER) $(EXEC_FOLDER)

$(OBJS_FOLDER) :
	$(PRINT) "$(BOLD)CREATION DU REPERTOIRE $@\n\t$(RESET_BOLD)"
	mkdir -p $(OBJS_FOLDER)

$(EXEC_FOLDER) :
	$(PRINT) "$(BOLD)CREATION DU REPERTOIRE $@\n\t$(RESET_BOLD)"
	mkdir -p $(EXEC_FOLDER)

# CREER LES FICHERS OBJETS
$(OBJS_FOLDER)%.o : $(SRC_FOLDER)%.cpp $(SRC_FOLDER)%.h
	$(PRINT) "$(BOLD)COMPILATION DE $<\n\t$(RESET_BOLD)"
	$(CC) $(CC_OUTPUT_FLAG) $@ $< $(CC_COMP_FLAG)

# BinaryTree.o
#$(OBJS_FOLDER)BinaryTree.o : $(SRC_FOLDER)BinaryTree.cpp $(SRC_FOLDER)BinaryTree.h $(SRC_FOLDER)Node.h $(SRC_FOLDER)Sensor.h $(SRC_FOLDER)Node.cpp $(SRC_FOLDER)Sensor.cpp 
#	$(PRINT) "$(BOLD)COMPILATION DE $<\n\t$(RESET_BOLD)"
#	$(CC) $(CC_OUTPUT_FLAG) $@ $< $(CC_COMP_FLAG)

include $(DEP_FILE)

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

