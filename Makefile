# Variables générales
CC = gcc
CFLAGS = -Wall -Wextra -g3
SRC = main.c repertoire.c
OBJ = $(SRC:.c=.o)
EXEC = output/main
RM = rm -f

# Règle par défaut
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
	mkdir -p output
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Règle pour compiler les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	$(RM) $(OBJ) $(EXEC)

# Règle pour exécuter l'exécutable
run: $(EXEC)
	$(EXEC)
