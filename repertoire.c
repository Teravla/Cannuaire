#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <regex.h>

#define MAX_PERSONNES_MAIN 100
#define TAILLE_MAX 40

// Définition de la structure Personne
typedef struct {
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    char numero[TAILLE_MAX];
    char email[TAILLE_MAX];
} Personne;

// Fonction pour vérifier que la chaîne contient uniquement des lettres
int est_alpha(const char *str) {
    while (*str) {
        if (!isalpha(*str) && *str != ' ') { // Permet les espaces dans le nom
            return 0; // Si un caractère non alphabétique est trouvé
        }
        str++;
    }
    return 1;
}

// Fonction pour vérifier le format de l'email
int est_email_valide(const char *email) {
    regex_t regex;
    int ret;

    // Expression régulière simple pour vérifier l'email
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        return 0; // Expression régulière invalide
    }

    ret = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    return ret == 0; // Retourne vrai si l'email correspond à l'expression régulière
}

// Fonction pour vérifier que le numéro de téléphone est valide
int est_numero_valide(const char *numero) {
    int longueur = 0; // Compteur pour les chiffres

    // Parcourt chaque caractère du numéro
    while (*numero) {
        if (isdigit(*numero)) {
            longueur++; // Incrémente pour chaque chiffre
        } else if (*numero != ' ' && *numero != '-') {
            return 0; // Retourne 0 si un caractère invalide est trouvé
        }
        numero++;
    }

    // Vérifie si le nombre de chiffres est exactement 10
    return longueur == 10;
}

// Création d'un enregistrement (ajout d'une nouvelle personne)
void Creer_Enregistrement(Personne *repertoire, int *nb_personnes) {
    if (*nb_personnes >= MAX_PERSONNES_MAIN) {
        printf("Le répertoire est plein !\n");
        return;
    }

    // Validation du nom
    while (1) {
        printf("Entrez le nom : ");
        scanf("%s", repertoire[*nb_personnes].nom);
        if (strlen(repertoire[*nb_personnes].nom) == 0 || !est_alpha(repertoire[*nb_personnes].nom)) {
            printf("Nom invalide. Veuillez entrer un nom valide (lettres uniquement).\n");
        } else {
            break;
        }
    }

    // Validation du prénom
    while (1) {
        printf("Entrez le prénom : ");
        scanf("%s", repertoire[*nb_personnes].prenom);
        if (strlen(repertoire[*nb_personnes].prenom) == 0 || !est_alpha(repertoire[*nb_personnes].prenom)) {
            printf("Prénom invalide. Veuillez entrer un prénom valide (lettres uniquement).\n");
        } else {
            break;
        }
    }

    // Validation du numéro de téléphone
    while (1) {
        printf("Entrez le numéro de téléphone : ");
        scanf("%s", repertoire[*nb_personnes].numero);
        if (strlen(repertoire[*nb_personnes].numero) == 0 || !est_numero_valide(repertoire[*nb_personnes].numero)) {
            printf("Numéro de téléphone invalide. Veuillez entrer un numéro valide (chiffres, espaces ou tirets uniquement).\n");
        } else {
            break;
        }
    }

    // Validation de l'email
    while (1) {
        printf("Entrez l'adresse mail : ");
        scanf("%s", repertoire[*nb_personnes].email);
        if (strlen(repertoire[*nb_personnes].email) == 0 || !est_email_valide(repertoire[*nb_personnes].email)) {
            printf("Adresse mail invalide. Veuillez entrer une adresse email valide.\n");
        } else {
            break;
        }
    }

    (*nb_personnes)++;
    printf("Personne ajoutée avec succès !\n");
}


// Affichage du répertoire
void Affiche_Repertoire(const Personne *repertoire, int nb_personnes) {
    if (nb_personnes == 0) {
        printf("Le répertoire est vide.\n");
        return;
    }

    for (int i = 0; i < nb_personnes; i++) {
        printf("Personne %d:\n", i + 1);
        printf("Nom: %s\n", repertoire[i].nom);
        printf("Prénom: %s\n", repertoire[i].prenom);
        printf("Numéro de téléphone: %s\n", repertoire[i].numero);
        printf("Adresse mail: %s\n\n", repertoire[i].email);
    }
}

// Recherche d'une personne par son nom
void Recherche(const Personne *repertoire, int nb_personnes) {
    char nom_recherche[TAILLE_MAX];
    printf("Entrez le nom à rechercher : ");
    scanf("%s", nom_recherche);

    for (int i = 0; i < nb_personnes; i++) {
        if (strcmp(repertoire[i].nom, nom_recherche) == 0) {
            printf("Personne trouvée :\n");
            printf("Nom: %s\n", repertoire[i].nom);
            printf("Prénom: %s\n", repertoire[i].prenom);
            printf("Numéro de téléphone: %s\n", repertoire[i].numero);
            printf("Adresse mail: %s\n", repertoire[i].email);
            return;
        }
    }
    printf("Personne non trouvée.\n");
}

// Suppression d'une personne par son nom
void Supprimer(Personne *repertoire, int *nb_personnes) {
    char nom_supprimer[TAILLE_MAX];
    printf("Entrez le nom de la personne à supprimer : ");
    scanf("%s", nom_supprimer);

    for (int i = 0; i < *nb_personnes; i++) {
        if (strcmp(repertoire[i].nom, nom_supprimer) == 0) {
            for (int j = i; j < *nb_personnes - 1; j++) {
                repertoire[j] = repertoire[j + 1];
            }
            (*nb_personnes)--; // Réduction du nombre de personnes
            printf("Personne supprimée avec succès.\n");
            return;
        }
    }
    printf("Personne non trouvée.\n");
}

// Sauvegarde du répertoire dans un fichier binaire
void Sauvegarder(const Personne *repertoire, int nb_personnes) {
    FILE *file = fopen("repertoire.dat", "wb");
    if (file) {
        fwrite(&nb_personnes, sizeof(int), 1, file);
        fwrite(repertoire, sizeof(Personne), nb_personnes, file);
        fclose(file);
    } else {
        printf("Erreur de sauvegarde.\n");
    }
}

// Chargement du répertoire depuis un fichier binaire
void Charger(Personne *repertoire, int *nb_personnes) {
    FILE *file = fopen("repertoire.dat", "rb");
    if (file) {
        fread(nb_personnes, sizeof(int), 1, file);
        fread(repertoire, sizeof(Personne), *nb_personnes, file);
        fclose(file);
    } else {
        printf("Aucune sauvegarde trouvée.\n");
    }
}

// Comparaison de deux personnes par leur nom
int comparer_personnes(const void *a, const void *b) {
    return strcmp(((Personne *)a)->nom, ((Personne *)b)->nom);
}

// Trie le répertoire par nom
void Trier_Repertoire(Personne *repertoire, int nb_personnes) {
    qsort(repertoire, nb_personnes, sizeof(Personne), comparer_personnes);
}

// Recherche améliorée par nom partiel
void Recherche_Amelioree(Personne *repertoire, int nb_personnes) {
    char nom_recherche[TAILLE_MAX];
    printf("Entrez le nom à rechercher (partiellement) : ");
    scanf("%s", nom_recherche);

    int trouve = 0;
    for (int i = 0; i < nb_personnes; i++) {
        if (strstr(repertoire[i].nom, nom_recherche)) {
            printf("Personne trouvée :\n");
            printf("Nom: %s\n", repertoire[i].nom);
            printf("Prénom: %s\n", repertoire[i].prenom);
            printf("Numéro de téléphone: %s\n", repertoire[i].numero);
            printf("Adresse mail: %s\n", repertoire[i].email);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune personne ne correspond à la recherche.\n");
    }
}
