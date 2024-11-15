# Variables
CC = gcc
CFLAGS = -Wall -Wextra -g3
LDFLAGS = -lregex
SRC = main.c repertoire.c
OBJDIR = output/obj
OBJ = $(SRC:.c=.o)
EXEC = output/main.exe

# Créer le répertoire de sortie si nécessaire
$(shell mkdir -p $(OBJDIR))

# Règle par défaut
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) $(LDFLAGS)

# Règle pour compiler les fichiers .c en .o dans le répertoire output/obj
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour nettoyer les fichiers objets uniquement
clean_obj:
	rm -f $(OBJ)

# Règle pour exécuter l'exécutable
run: $(EXEC)
	chcp 65001
	./$(EXEC)

# Règle pour la reconstruction complète
rebuild: clean all
