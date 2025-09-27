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

void scan(char string[99]) { //instead of scanf
    scanf(" %[^\n]",string);
}

void show(struct contact person[], int i) { //affichage
    // printf("-------------------index-%03d------------------\n", i);
    // printf("le nom=======> %s\n", person[i].nom);
    // printf("le numero====> %s\n", person[i].phone);
    // printf("l'email======> %s\n", person[i].mail);
    printf("---------------------------------------------------------------------------------------\n");
    printf("index | %-20s | %-20s  | %-30s |\n","Nom","Numero","Email");
    printf(" %03d  | %-20s | 0%-20s | %-30s |\n",i,person[i].nom,person[i].phone,person[i].mail);
}


int find(struct contact person[], char keyword[], int y) { //search function
    if (strstr(person[y].nom, keyword) !=NULL ) {
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
        if (scanf(" %d", &a)!=1) {
            scanf("%*s");
            a=7; // 7 just to send it to default ...
        }

        switch (a) {
            case 1: //ad
            {
                nbr_contact++;
                printf("entrez le nom: ");
                //scanf(" %[^\n]", person[nbr_contact].nom);
                scan(person[nbr_contact].nom);
                printf("entrez le numero de telephone +212: ");
                // scanf(" %[^\n]", person[nbr_contact].phone);
                scan(person[nbr_contact].phone);
                printf("entrez l'email: ");
                // scanf(" %[^\n]", person[nbr_contact].mail);
                scan(person[nbr_contact].mail);
                printf("==========contact succesfully added================\n");
                show(person, nbr_contact);

                break;
            } //done
            case 3: //delete
            {
                char temp_nom[99];
                int index_store[99];
                int index=-1,bool=0;
                printf("entrez le contact que vous voulez medifier: ");
                scan(temp_nom);

                for (int i=0; i<= nbr_contact; i++) {
                    if (find(person, temp_nom,i) > -1) {
                        show(person, find(person, temp_nom,i)); //showing contact with this term search
                        index++;
                        index_store[index]=i;   //storing the indexs of contact with that term search in a new array
                        bool=1;
                    }
                }
                if (bool==0) printf("contact introuvable");
                printf("choisir l'index du contact que vous voulez medifier ");
                int input;
                scanf("%d",&input);
                if (input<=index) {
                    nbr_contact--;
                    for (int i=input;i<= nbr_contact;i++) {
                        person[i]=person[i+1];

                    }
                }
                else {
                    printf("le choix entrer est invalid!\n");
                }

                break;


            }

            case 2: //edit
            {
                
            }

            case 4: //show
            {
                int bool=0;
                for (int i = 0; i <= nbr_contact; i++) {
                    show(person, i);
                    bool=1;
                }
                if (bool==0) printf("ajouter un contact pour le trouver ici! \n");
                break;
            } //done

            case 5: //search
            {
                char temp_nom[99];
                int bool=0;
                printf("Enterez le nom ===> ");
                scan(temp_nom);
                for (int i=0; i<= nbr_contact; i++) {
                    if (find(person, temp_nom,i) > -1) {
                        show(person, find(person, temp_nom,i));
                        bool=1;
                    }
                }
                if (bool==0) printf("contact introuvable");
                break;
            } //done

            case 6: //quit
            {
                break;
            }

            default: {
                printf("vous devez choisir un choix !\n");

            }
        }
    } while (a != 0);
}
