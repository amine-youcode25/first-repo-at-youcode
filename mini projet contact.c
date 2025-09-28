#include <stdio.h>
#include <string.h>

struct contact {
    char nom[99];
    char phone[99];
    char mail[99];
};
struct contact person[100];

void scan(char string[99]) { //instead of scanf
    scanf(" %[^\n]",string);
}

int user_input() {  //function for any typo from user in integer inputs
    char newline_check;
    int choix;
    while (1) {
        if (scanf("%d%c", &choix,&newline_check)==2 && newline_check =='\n') { //scanf the integer and the first character
            return choix;
        }
        else {
            while (getchar()!='\n') {

            }
            return -1;
        }
    }
}

void fgets_char(char string[],int size) {
    fgets(string,size,stdin);
    string[strlen(string)-1]='\0';
}

void show( int i) { //affichage
    // printf("-------------------index-%03d------------------\n", i);
    // printf("le nom=======> %s\n", person[i].nom);
    // printf("le numero====> %s\n", person[i].phone);
    // printf("l'email======> %s\n", person[i].mail);
    // printf("---------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s  | %-30s \n","Nom","Numero","Email");
    printf("| %-20s | 0%-20s | %-30s \n",person[i].nom,person[i].phone,person[i].mail);
}


int find(char keyword[],int y) { //search function
    if (strstr(person[y].nom, keyword) !=NULL ) {
        return y;
        }
    else {
        return (-1);
    }
}


int main() {

    int choix , nbr_contact= -1;
    do {
        printf("\n\n\n1. Ajouter un Contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un Contact\n");
        printf("4. Afficher Tous les Contacts\n");
        printf("5. Rechercher un Contact\n");
        printf("6. exit\n");
        printf("====> ");
        choix = user_input();
        // if (scanf("%d%c", &choix,&newline)==2 && newline =='\n') { //scanf the integer and the first character
        // }
        // else {
        //     scanf(" %*[^\n]");
        //     choix=7;
        // }

        switch (choix) {
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
                show(nbr_contact);

                break;
            } //done
            case 3: //delete
            {
                char temp_nom[99];
                int index_store[99];
                int index=-1,bool=0;
                printf("entrez le contact que vous voulez supprimer: ");
                scan(temp_nom);

                for (int i=0; i<= nbr_contact; i++) {
                    if (find(temp_nom,i) > -1) {

                        index++;
                        index_store[index]=i;   //storing the indexs of contact with that term search in a new array
                        bool=1;
                        printf("Contact:%d\n",index);
                        show(find(temp_nom,i)); //showing contact with this term search
                    }
                }
                if (bool==0) {
                    printf("contact introuvable");
                    break;//si tas pas trouve le contact quitte  la choix.
                }
                printf("choisir l'index du contact que vous voulez supprimer==> ");
                int input=user_input();
                // scanf("%d",&input);

                int temp=index_store[input]; //i got the the index where we will start shifting
                if (input >= 0 && input<=index) {
                    nbr_contact--;
                    for (int i=temp;i<= nbr_contact;i++) {
                        person[i]=person[i+1];

                    }
                    printf("le contact a ete supprimer! \n");
                }
                else {
                    printf("le choix entrer est invalid!\n");
                }
                break;


            }

            case 2: //edit
            {
                char temp_nom[3][99];
                int index_store[99];
                int index=-1,bool=0;
                printf("entrez le contact que vous voulez modifier : ");
                scan(temp_nom[0]);

                for (int i=0; i<= nbr_contact; i++) {
                    if (find(temp_nom,i) > -1) {

                        index++;
                        index_store[index]=i;   //storing the indexs of contact with that term search in a new array
                        bool=1;
                        printf("Contact:%d\n",index);
                        show(find(temp_nom,i)); //showing contact with this term search
                    }
                }
                if (bool==0) {
                    printf("contact introuvable");
                    break;//si tas pas trouve le contact quitte  la choix.
                }
                printf("choisir l'index du contact que vous voulez modifier==> ");
                int input=user_input();
                // scanf("%d",&input);

                int temp=index_store[input]; //i got the the index where we will start shifting
                if (input >= 0 && input<=index) {
                    printf("entrez le nouveau nom ( click entrez si vous navez rien a changer ) ===>");
                    fgets_char(temp_nom[0],99);
                    printf("entrez le nouveau numero ( click entrez si vous navez rien a changer ) ===>");
                    fgets_char(temp_nom[1],99);
                    printf("entrez le nouveau email ( click entrez si vous navez rien a changer ) ===>");
                    fgets_char(temp_nom[2],99);
                    if (temp_nom[0][0]!= '\n') strcpy(person[temp].nom,temp_nom[0]);
                    if (temp_nom[1][0]!= '\n') strcpy(person[temp].phone,temp_nom[1]);
                    if (temp_nom[2][0]!= '\n') strcpy(person[temp].mail,temp_nom[2]);
                    printf("le contact a ete modifier! \n");
                    show(temp);
                }
                else {
                    printf("le choix entrer est invalid!\n");
                }
                break;
            }

            case 4: //show
            {
                int bool=0;
                for (int i = 0; i <= nbr_contact; i++) {
                    printf("---------------------------------------------------------------------------------\n");
                    show(i);
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
                    if (find(temp_nom,i) > -1) {
                        show(find(temp_nom,i));
                        bool=1;
                    }
                }
                if (bool==0) printf("contact introuvable");
                break;
            }
            default: {
                if (choix==6) {
                    printf("Au revoir");
                }
                else {
                    printf("vous devez choisir un choix !\n");
                    break;
                }
            }
        }
    } while (choix != 6);
}
