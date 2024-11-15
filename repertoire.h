#ifndef REPERTOIRE_H
#define REPERTOIRE_H

#define MAX_PERSONNES_MAIN 100
#define TAILLE_MAX 100

// Définition de la structure Personne
typedef struct {
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    char numero[TAILLE_MAX];
    char email[TAILLE_MAX];
    int age;
    char adresse[TAILLE_MAX];
} Personne;

// Déclarations des fonctions
void Creer_Enregistrement(Personne *repertoire, int *nb_personnes);
void Affiche_Repertoire(const Personne *repertoire, int nb_personnes);
void Recherche(const Personne *repertoire, int nb_personnes);
void Supprimer(Personne *repertoire, int *nb_personnes);
void Sauvegarder(const Personne *repertoire, int nb_personnes);
void Charger(Personne *repertoire, int *nb_personnes);
void Trier_Repertoire(Personne *repertoire, int nb_personnes);
void Recherche_Amelioree(Personne *repertoire, int nb_personnes);

// Fonction pour comparer deux personnes (utilisée par qsort)
int comparer_personnes(const void *a, const void *b);

#endif // REPERTOIRE_H
