# Gestionnaire de Répertoire

Ce projet est une application C qui permet de gérer un répertoire de contacts. L'application permet d'ajouter, de rechercher, de supprimer et d'afficher des contacts, ainsi que de sauvegarder et charger des données à partir d'un fichier binaire. Les contacts sont stockés dans une structure contenant le nom, le prénom, le numéro de téléphone et l'adresse email de chaque personne.

## Fonctionnalités

- **Ajouter une personne** : Permet à l'utilisateur d'entrer les détails d'une nouvelle personne, en vérifiant la validité des entrées (nom, prénom, numéro de téléphone, adresse email).
- **Afficher le répertoire** : Affiche tous les contacts présents dans le répertoire.
- **Rechercher une personne** : Recherche un contact par son nom. Une recherche améliorée permet de rechercher par nom partiel.
- **Supprimer une personne** : Supprime un contact du répertoire en fonction du nom.
- **Sauvegarder et charger** : Sauvegarde les contacts dans un fichier binaire (`repertoire.dat`) et charge les contacts depuis ce fichier à l'ouverture du programme.

## Installation

1. **Compiler le programme :**

   Installer `make` pour compiler le programme. Assurez-vous d'avoir `gcc` installé.

   ```bash
   sudo apt install make
   ```

## Utilisation

1. **Exécuter le programme :**

   Après la compilation, tu peux exécuter le programme en utilisant la commande suivante :

   ```bash
   make run
   ```

2. **Interagir avec le menu :**

   Le programme affiche un menu avec les options suivantes :

   - **1** : Ajouter une personne
   - **2** : Afficher le répertoire
   - **3** : Rechercher une personne
   - **4** : Supprimer une personne
   - **5** : Sauvegarder et quitter

   Saisis le numéro correspondant à l'option souhaitée, puis suis les instructions à l'écran.

## Détails de Fonctionnement

- **Structure Personne** : Chaque contact est représenté par une structure `Personne`, qui contient les champs pour le nom, le prénom, le numéro de téléphone et l'adresse email.
- **Validation des Entrées** :
  - Les noms et prénoms ne peuvent contenir que des lettres et des espaces.
  - Les numéros de téléphone peuvent contenir uniquement des chiffres, des espaces et des tirets.
  - Les adresses email sont validées à l'aide d'une expression régulière.
  
- **Sauvegarde des Données** : Lorsqu'un utilisateur quitte le programme, les contacts sont sauvegardés dans un fichier binaire pour une utilisation future. Les données sont chargées à l'ouverture du programme.

## Aide et Support

Pour toute question ou problème, veuillez ouvrir une issue sur le dépôt GitHub.

## Contribuer

Les contributions sont les bienvenues. N'hésitez pas à soumettre une pull request ou à ouvrir une issue pour des suggestions ou des problèmes.

## License

Ce projet est sous licence CC BY-SA 4.0. Consultez le fichier `LICENSE` pour plus de détails.

## Auteur

MASSINOND Matéo <mateo.massinond@efrei.net> ~ @Etsu7
MENON Valentin <valentin.menon@efrei.net> ~ @Teravla