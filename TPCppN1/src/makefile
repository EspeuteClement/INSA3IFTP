#Youpi, on va compiler des lamas ! :D 
OBJS = objs/main.o objs/Collection.o

executable : $(OBJS)
	g++ -o executable $(OBJS)

objs/%.o : %.cpp
	@echo "\tBuilding $@"
	g++ -c -o $@ $<
	
clean :
	rm -f $(OBJS) executable core






# # Makefile TP C++
# # collection.cpp test.cpp

# # Compilateur utilisé
# COMP = g++

# # Flags de compilation pour la phase d'édiition des liens
# # de la compilation
# TFLAGS = 

# # Flags de compilation pour la phase de compilation
# CFLAGS = -c

# # Liste des fichiers .cpp à compiler
# FILES = main.cpp 

# OBJSPATH = objs/
# TMP = $(addprefix $(OBJSPATH),$(FILES))
# OBJS = $(TMP:.cpp=.o)
# EXEC = executable

# $(EXEC) : $(OBJS)
# 	@echo "PATATE $(OBJS)"
# 	$(COMP) -o executable $(OBJS) $(TFLAGS)

# %.o : %.cpp %.h
# 	echo "Building $<"
# 	$(COMP) $(CFLAGS) -o $@ $< 

# .PHONY : clean

# clean :
# 	rm -f $(OBJS) $(EXEC) core

