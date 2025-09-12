#include <stdio.h>
#include <string.h>
#include <stdlib.h>           


struct joueur {
    int id, numeroMaillot, age, buts;
    char nom[50];
    char prenom[50];
    char poste[50];
    char statut[50];
};
// Tableau nommé "joueurs" comprend 100 joueurs
struct joueur joueurs[100] = { 
    {1, 10,22,15, "hakime" , "ziach" , "attaquant","titulaire"},
    {2, 5, 25, 5, "achraf" , "hakimi", "défenseur","titulaire"},
    {3, 9, 30, 8,"ibrahime","diaz"   , "milieu"   ,"remplacement"},
    {4, 1, 27, 3,"soufiane","mourabit","gardien"  ,"titulaire"},
    {5,11, 23,12, "yassine","bono"   , "attaquant","titulaire"},
    {6,14, 33, 6, "azedine","ounahi" , "attaquant","titulaire"},
    {7, 6, 24, 9, "yousef" ,"nasiri" , "défenseur","titulaire"},
    {8, 7, 40,18, "bilal"  ,"khanose", "milieu"   ,"remplacement"},
    {9, 8, 26,13, "ayoub"  ,"kaebi"  , "gardien"  ,"titulaire"},
    {10,2, 27,10, "adam"   ,"massina", "attaquant","titulaire"},
}; 
int nbjoueurs = 10;
int id = 10;

                                    //   ********* Ajouter un joueur *************
void Ajouter_joueur() {
    struct joueur Nv;  // Déclarer une nouvelle variable "Nv" 

    Nv.id = id;
    id = id + 1;
    int choix2;

    printf("1. Ajouter un nouveau joueur\n");
    printf("2. Ajouter plusieurs joueurs en une seule opération\n");
    printf("Votre choix est :");
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
            printf("Joueur numéro %d:\n", i + 1);

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
                    printf("ID: %d | %s %s | Maillot: %d | Âge: %d | Buts: %d | Statut: %s | Poste : %s |\n ",
                           joueurs[i].id, joueurs[i].nom, joueurs[i].prenom, joueurs[i].numeroMaillot,
                           joueurs[i].age, joueurs[i].buts, joueurs[i].statut,joueurs[i].poste);
                    trouve = 1;
                
                }
            }
            if (trouve == 0) {
                printf("Aucun joueur trouvé pour le poste \"%s\".\n", posteRecherche);
            }
            break;
            default:
                printf("Choix invalide.\n");
                break;
    }
}
// Modifier un joueur
void Modifier_joueur() {
    char nom[50];
    printf("Entrer le nom du joueur à modifier: \n");
    scanf("%s", nom);
        
    int trouve = 0;
    for (int i = 0; i < nbjoueurs; i++) {
        if (strcmp(joueurs[i].nom, nom) == 0) {
            printf("Joueur trouvé : %s %s\n", joueurs[i].nom, joueurs[i].prenom);
            trouve = 1;
            printf("1. Modifier le poste\n");
            printf("2. Modifier l'âge\n");
            printf("3. Modifier le nombre de buts\n");
            int choixModif;
            printf("Votre choix : ");
            scanf("%d", &choixModif);

            switch (choixModif) {
                case 1: {
                    // Modifier le poste
                    printf("Entrez le nouveau poste (gardien/defenseur/milieu/attaquant) : ");
                    scanf("%s", joueurs[i].poste);
                    printf("Le poste a été modifié avec succès !\n");
                    break;
                }
                case 2: {
                    // Modifier l'âge
                    printf("Entrez le nouvel âge : ");
                    scanf("%d", &joueurs[i].age);
                    printf("L'âge a été modifié avec succès !\n");
                    break;
                }
                case 3: {
                    // Modifier le nombre de buts
                    printf("Entrez le nouveau nombre de buts : ");
                    scanf("%d", &joueurs[i].buts);
                    printf("Le nombre de buts a été modifié avec succès !\n");
                    break;
                }
                default:
                    printf("Choix invalide.\n");
                    break;
            }
            break;   //  On arrête la boucle une fois le joueur trouvé 
        }
    }

    if (!trouve) {
        printf("Aucun joueur trouvé avec ce nom.\n");
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
            printf("Le joueur trouve : %s %s\n",joueurs[i].nom,joueurs[i].prenom);
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
void Statistiques(){
    int choix4;
      printf("1.Afficher le nombre total de joueurs dans équipe.\n");
      printf("2.Afficher age moyen des joueurs.\n");
      printf("3.Afficher les joueurs ayant marqué plus de X buts .\n");
      printf("4.Afficher le meilleur buteur (joueur avec le maximum de buts).\n");
      printf("5.Afficher le joueur le plus jeune et le plus âgé.\n");
            printf("votre choix\n");
            scanf("%d",&choix4);
            switch (choix4)
            {
            case 1:
              printf("Le nombre total de joueurs est :%d\n",nbjoueurs);
                break;
            case 2:
           int SommeAge =0;
           double moyen;
           for (int i = 0; i < nbjoueurs; i++)
           {
            SommeAge = SommeAge + joueurs[i].age;
           }
           moyen = SommeAge / nbjoueurs ;
           printf ("Age moyen des joueurs est : %.2f\n",moyen);
           break;
           case 3:
            int x, trouve =0;          // declarer nouvelle variable nommee "trouve" pour savoir si un joueur a ete trouve ou non 
            printf("Entre le nombre de but x :\n");
            scanf("%d",&x);
            for (int i = 0; i < nbjoueurs; i++)
         {
            if (joueurs[i].buts>x)
            {
              printf("%s %s :%d ",joueurs[i].nom,joueurs[i].prenom,joueurs[i].buts);
              trouve=1;
            }
        
            }
            if (trouve==0){
            printf("Aucun joueur avec plus de %d buts\n ",x);
            }
         break;
            case 4:
            int maxButs = joueurs[0].buts;
            int index=0;
            for (int i = 1; i < nbjoueurs; i++)
            {
                if (joueurs[i].buts>maxButs)
                {
                    maxButs = joueurs[i].buts;
                    index = i ;
                }
                
            }
            printf("Le Meilleur Buteur est : %s %s _ %d\n",joueurs[index].nom,joueurs[index].prenom,joueurs[index].buts);
            break;
            case 5:
            //Pour stocker l'âge le plus petit et le plus grand trouvé dans l'équipe.
        int minAge = joueurs[0].age;
        int maxAge = joueurs[0].age;
        int minIndex = 0, maxIndex = 0;    //Pour stocker les indices des joueurs avec l'âge 
    for (int i = 1; i < nbjoueurs; i++) {
        if (joueurs[i].age < minAge) {
            minAge = joueurs[i].age;
            minIndex = i;
        }
        if (joueurs[i].age > maxAge) {
            maxAge = joueurs[i].age;
            maxIndex = i;
        }
    }
    printf("Le joueur le plus jeune est : %s %s, Âge: %d\n", joueurs[minIndex].nom, joueurs[minIndex].prenom, joueurs[minIndex].age);
    printf("Le joueur le plus âgé est : %s %s, Âge: %d\n", joueurs[maxIndex].nom, joueurs[maxIndex].prenom, joueurs[maxIndex].age);
    break;
            default:
                printf("Choix invalide.\n");
                break;
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
                Modifier_joueur();
                break;
            case 4:
                Supprimer_joueur();
                break;
            case 5:
                Recherche_joueur();
                break;
            case 6:
                Statistiques();
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
