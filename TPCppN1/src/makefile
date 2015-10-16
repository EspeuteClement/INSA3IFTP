# VARIABLE MADNESS !!!

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

PRINT = @printf

### FICHIERS
# Nom du fichier de sortie
EXEC = executable
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

### DEBUG
DEBUG = debug

### RUN TARGET
RUN = run

### VARIABLES ADDITIONELLES CREES AUTOMATIQUEMENT
#TRUE_SRC = $(addprefix SRC_FOLDER,SRC)
OBJS = $(subst .cpp,.o,$(addprefix $(OBJS_FOLDER),$(SRC)))

# CIBLE ALL POUR TOUT BUILD
.PHONY : all
all : directories $(EXEC) 

# CIBLE OPTIONNELE POUR LANCER LE PROGRAMME APRES LE BUILD
$(RUN) : all
	$(PRINT) "\033[1mEXECUTION DE $(EXEC)\n\033[21m------------------\n"
	@./$(EXEC)

# EDITION DES LIENS :
$(EXEC) : $(OBJS)
	$(PRINT) "\033[1mEDITION DES LIENS\n\t\033[21m"
	$(LINK) $(CC_OUTPUT_FLAG) $(EXEC) $(OBJS) $(LINK_FLAG)

# CREER LES DOSSIERS MANQUANTS
.PHONY : createObjsFolder
directories : $(OBJS_FOLDER)

$(OBJS_FOLDER) :
	$(PRINT) "\033[1mCREATION DU REPERTOIRE $@\n\t\033[21m"
	mkdir -p $(OBJS_FOLDER)

# CREER LES FICHERS OBJETS
$(OBJS_FOLDER)%.o : %.cpp %.h
	$(PRINT) "\033[1mCOMPILATION DE $<\n\t\033[21m"
	$(CC) $(CC_OUTPUT_FLAG) $@ $< $(CC_COMP_FLAG)

# PARTIE NETOYAGE
.PHONY : $(CLEAN)
$(CLEAN) : 
	$(PRINT) "\033[1mCLEAN$<\n\t\033[21m"
	$(CLEAN_COMMAND) $(CLEAN_FLAG) $(ADDITIONAL_CLEAN)
	$(PRINT) "\t"
	$(CLEAN_COMMAND) -fd $(OBJS_FOLDER)

# PARTIE DEBUG
.PHONY : $(DEBUG)
$(DEBUG) : 
	$(PRINT) "\033[35;1mCOUCOU\n"

