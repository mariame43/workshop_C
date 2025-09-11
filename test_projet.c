#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct joueur {
    int id, numeroMaillot, age, buts, date_inscription;
    char nom[50];
    char prenom[50];
    char poste[50];
    char statut[50];
};

struct joueur joueurs[100];  // Tableau nommé "joueurs" comprend 100 joueurs
int nbjoueurs = 0;
int id = 1;

                                 //   ********* Ajouter un joueur *************
void Ajouter_joueur() {
    struct joueur Nv;  // Déclarer une nouvelle variable "Nv" contenant les informations

    Nv.id = id;
    id = id + 1;
    int choix2 = 0;

    printf("1. Ajouter un nouveau joueur\n");
    printf("2. Ajouter plusieurs joueurs en une seule opération\n");
    scanf("%d", &choix2);

    if (choix2 == 1) {
                          // ********************** Ajouter un Joueur *************
        printf("Nom: ");
        scanf("%s", Nv.nom);
        printf("Prenom: ");
        scanf("%s", Nv.prenom);
        printf("NumeroMaillot: ");
        scanf("%d", &Nv.numeroMaillot);
        printf("Age: ");
        scanf("%d", &Nv.age);
        printf("Poste (gardien/defenseur/milieu/attaquant): ");
        scanf("%s", Nv.poste);
        printf("Statut(titulaire/remplacement): ");
        scanf("%s", Nv.statut);
        printf("Date_inscription: ");
        scanf("%d", &Nv.date_inscription);
        printf("Buts: ");
        scanf("%d", &Nv.buts);

        joueurs[nbjoueurs] = Nv;
        nbjoueurs++;
        printf("Le Joueur a été ajouté avec succès\n");

    } else if (choix2 == 2) {
                             // ******Ajouter Plusieurs Joueurs *******
        int n;
        printf("Entrer le nombre de joueurs à ajouter: ");
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            Nv.id = id;
            id = id + 1;
            printf("Joueur numéro %d\n", i + 1);

            printf("Nom: ");
            scanf("%s", Nv.nom);
            printf("Prenom: ");
            scanf("%s", Nv.prenom);
            printf("NumeroMaillot: ");
            scanf("%d", &Nv.numeroMaillot);
            printf("Age: ");
            scanf("%d", &Nv.age);
            printf("Poste (gardien/defenseur/milieu/attaquant): ");
            scanf("%s", Nv.poste);
            printf("Statut(titulaire/remplacement): ");
            scanf("%s", Nv.statut);
            printf("Date_inscription: ");
            scanf("%d", &Nv.date_inscription);
            printf("Buts: ");
            scanf("%d", &Nv.buts);

            joueurs[nbjoueurs] = Nv;
            nbjoueurs++;
            printf("Le joueur a été ajouté avec succès\n");
        }
    }
}

                                                     // ********** Afficher les joueurs *******
void Afficher_joueur() {
    int choix;

    printf("1. Trier les joueurs par ordre alphabétique (nom)\n");
    printf("2. Trier les joueurs par age\n");
    printf("3. Afficher les joueurs par poste\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
                                           // **************trier Par Nom ***************
            struct joueur change;
            for (int i = 0; i < nbjoueurs - 1; i++) {
                for (int j = i + 1; j < nbjoueurs; j++) {
                    if (strcmp(joueurs[i].nom, joueurs[j].nom) > 0) {
                        change = joueurs[i];
                        joueurs[i] = joueurs[j];
                        joueurs[j] = change;
                    }
                }
            }
            printf("Les joueurs triés par nom:\n");
            for (int i = 0; i < nbjoueurs; i++) {
                printf("%s %s\n", joueurs[i].nom, joueurs[i].prenom);
            }
            break;
        case 2:
                                         // **********Trier Par Age***********
            for (int i = 0; i < nbjoueurs - 1; i++) {
                for (int j = i + 1; j < nbjoueurs; j++) {
                    if (joueurs[i].age > joueurs[j].age) {
                        change = joueurs[i];
                        joueurs[i] = joueurs[j];
                        joueurs[j] = change;
                    }
                }
            }
            printf("Les joueurs triés par âge:\n");
            for (int i = 0; i < nbjoueurs; i++) {
                printf("%s %s, Age: %d\n", joueurs[i].nom, joueurs[i].prenom, joueurs[i].age);
            }
            break;
        case 3:
                                          //******** Afficher Par Poste**********
            char posteRecherche[20];
            printf("Entrez le poste à afficher (gardien/defenseur/milieu/attaquant): ");
            scanf("%s", posteRecherche);

            int trouve = 0;
            for (int i = 0; i < nbjoueurs; i++) {
                if (strcmp(joueurs[i].poste, posteRecherche) == 0) {
                    printf("ID: %d | %s %s | Maillot: %d | Âge: %d | Buts: %d | Statut: %s | Poste : %s | Date_inscreption : %d\n ",
                           joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                           joueurs[i].age, joueurs[i].buts, joueurs[i].statut,joueurs[i].poste,joueurs[i].date_inscription);
                    trouve = 1;
                }
            }
            if (trouve == 0) {
                printf("Aucun joueur trouvé pour le poste \"%s\".\n", posteRecherche);
            }
            break;
    }
}

                                       // ************** Recherche un joueur*************
void Recherche_joueur() {
    int choix;
    printf("1. Rechercher un joueur par Identifiant\n");
    printf("2. Rechercher un joueur par Nom\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    if (choix == 1) {
                                         // ********* Cherche par ID******************
        int id;
        printf("ID du joueur: ");
        scanf("%d", &id);

        for (int i = 0; i < nbjoueurs; i++) {
            if (joueurs[i].id == id) {
                printf("ID: %d | %s %s | Maillot: %d | Âge: %d | Buts: %d | Statut: %s\n",
                       joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                       joueurs[i].age, joueurs[i].buts, joueurs[i].statut);
                return;
            }
        }
        printf("Aucun joueur trouvé avec cet ID.\n");

    } else if (choix == 2) {
                                        // ********** Cherche par Nom*********
        char nom[50];
        printf("Nom du joueur: ");
        scanf("%s", nom);

        int trouve = 0;
        for (int i = 0; i < nbjoueurs; i++) {
            if (strcmp(joueurs[i].nom, nom) == 0) {
                printf("ID: %d | %s %s | Maillot: %d | Âge: %d | Buts: %d | Statut: %s\n",
                       joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                       joueurs[i].age, joueurs[i].buts, joueurs[i].statut);
                trouve = 1;
            }
        }
        if (!trouve) {
            printf("Aucun joueur trouvé avec ce nom.\n");
        }
    }
}

                                   // ********* Supprimer un joueur********
void Supprimer_joueur() {
    int id;
    int trouve = 0;
    printf("Entrer ID de joueur pour supprimer: ");
    scanf("%d", &id);

    for (int i = 0; i < nbjoueurs; i++) {
        if (joueurs[i].id == id) {
            for (int j = i; j < nbjoueurs - 1; j++) {
                joueurs[j] = joueurs[j + 1];
            }
            nbjoueurs--;
            printf("Le joueur a été supprimé\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun joueur trouvé avec cet ID.\n");
    }
}

int main() {
    int choix = 0;

    do {
        printf("******* Menu *******\n");
        printf("1. Ajouter un joueur.\n");
        printf("2. Afficher la liste de tous les joueurs.\n");
        printf("3. Modifier un joueur.\n");
        printf("4. Supprimer un joueur.\n");
        printf("5. Recherche un joueur.\n");
        printf("6. Statistiques.\n");
        printf("7. Quitter.\n");

        printf("Votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                Ajouter_joueur();
                break;
            case 2:
                Afficher_joueur();
                break;
            case 3:
                break;
            case 4:
                Supprimer_joueur();
                break;
            case 5:
                Recherche_joueur();
                break;
            case 6:
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }

        printf("\nAppuyez sur Entrée pour continuer...");
        getchar();  // Pour consommer le caractère '\n' restant après scanf
        getchar();  // Attendre l'utilisateur appuie sur Entrée
        system("clear");

    } while (choix != 7);

    return 0;
}
