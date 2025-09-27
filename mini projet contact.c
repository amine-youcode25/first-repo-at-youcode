#include <stdio.h>
#include <string.h>

struct contact {
    char nom[99];
    char phone[99];
    char mail[99];
};

// int search(char keyword[],char list[]){
//     if(strstr(search[],list[])==true){
//         return 1;
//     }
//     else {
//         return 0;
//     }

// }
void scan() {
    scanf(" %[^\n]");
}
void show(struct contact person[], int i) {
    printf("-------------------%d------------------\n", i);
    printf("le nom=======> %s\n", person[i].nom);
    printf("le numero====> %s\n", person[i].phone);
    printf("l'email======> %s\n", person[i].mail);
}


int find(struct contact person[], char keyword[], int y) {
    if (strstr(person[y].nom, keyword) != '\0') {
        return y;
        }
    else {
        return (-1);
    }
}

int main() {
    struct contact person[100];
    int a;
    int nbr_contact = -1;
    do {
        printf("\n\n\n1. Ajouter un Contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un Contact\n");
        printf("4. Afficher Tous les Contacts\n");
        printf("5. Rechercher un Contact\n");
        printf("6. exit\n");
        printf("====> ");
        scanf("%d", &a);

        switch (a) {
            case 1: //ad
            {
                nbr_contact++;
                printf("entrez le nom: ");
                scanf(" %[^\n]", person[nbr_contact].nom);
                printf("entrez le numero de telephone +212: ");
                scanf(" %[^\n]", person[nbr_contact].phone);
                printf("entrez l'email: ");
                scanf(" %[^\n]", person[nbr_contact].mail);
                printf("==========contact succesfully added================\n");
                show(person, nbr_contact);

                break;
            }

            case 2: //edit
            {
                printf("entrez le nom du contact que tu veux medifier: ");
            }

            case 3: //delete
            {
                scan();
            }

            case 4: //show
            {
                for (int i = 0; i <= nbr_contact; i++) {
                    show(person, i);
                }
                break;
            }

            case 5: //search
            {
                char temp_nom[99];
                int bool=0;
                printf("Enterez le nom ===> ");
                scanf(" %[^\n]", temp_nom);
                for (int i=0; i<= nbr_contact; i++) {
                    if (find(person, temp_nom,i) > -1) {
                        show(person, find(person, temp_nom,i));
                        bool=1;
                    }
                }
                if (bool==0) printf("contact introuvable");
                break;
            }

            case 6: //quit
            {
                break;
            }

            default:
                printf("vous devez choisir un choix !\n");
                break;
        }
    } while (a != 0);
}
