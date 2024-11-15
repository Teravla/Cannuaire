#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "repertoire.h"

int main() {
    Personne repertoire[MAX_PERSONNES_MAIN];
    int nb_personnes = 0;
    int choix;

    // Chargement des données au démarrage
    Charger(repertoire, &nb_personnes);

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher le répertoire\n");
        printf("3. Rechercher une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Sauvegarder et quitter\n");
        printf("Entrez votre choix : ");

        // Validation de l'entrée utilisateur
        while (scanf("%d", &choix) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre entier : ");
            while (getchar() != '\n'); // Vider le buffer
        }

        switch (choix) {
            case 1:
                Creer_Enregistrement(repertoire, &nb_personnes);
                printf("Personne ajoutée avec succès!\n");
                break;
            case 2:
                Affiche_Repertoire(repertoire, nb_personnes);
                break;
            case 3:
                Recherche_Amelioree(repertoire, nb_personnes);
                break;
            case 4:
                Supprimer(repertoire, &nb_personnes);
                break;
            case 5:
                Sauvegarder(repertoire, nb_personnes);
                printf("Données sauvegardées. Au revoir!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
