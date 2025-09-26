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

void show(struct contact person[],int i){
        printf("-------------------%d------------------\n",i);
        printf("le nom=======>%s\n",person[i].nom);
        printf("le numero====>%s\n",person[i].phone);
        printf("l'email======>%s\n",person[i].mail);
}


int find(struct contact person[],char keyword[],int i){
    int find_at_least_one=0;
    if(strstr(person[i].nom,keyword)!='\0'){
            find_at_least_one=1;
            return i;
        }

    if (find_at_least_one==0) return (-1);
}






int main() {
    struct contact person[100];
    int a;
    int nbr_contact=-1;
    do {
        printf("\n\n\n1. Ajouter un Contact\n");
        printf("2. Modifier un Contact\n");
        printf("3. Supprimer un Contact\n");
        printf("4. Afficher Tous les Contacts\n");
        printf("5. Rechercher un Contact\n");
        printf("6. exit\n");
        printf("====> ");
        scanf("%d",&a);

        switch (a) {

            case 1: //ad
            {
                nbr_contact++;
                printf("entrez le nom: ");
                scanf(" %[^\n]",person[nbr_contact].nom);
                printf("entrez le numero de telephone +212: ");
                scanf(" %[^\n]",person[nbr_contact].phone);
                printf("entrez l'email: ");
                scanf(" %[^\n]",person[nbr_contact].mail);
                printf("==========contact succesfully added================\n");
                show(person,nbr_contact);

                break;
            }

            case 2://edit
            {
                printf("entrez le nom du contact que tu veux medifier: ");

            }

            case 3://delete
            {

            }

            case 4://show
            {
                for (int i=0;i<=nbr_contact;i++){
                    show(person,i);
                }
                break;
            }

            case 5://search
            {
                char temp_nom[99];
                printf("Enterez le nom ===> ");
                scanf(" %[^\n]",temp_nom);
                for (int i;i<=nbr_contact;i++){
                if (find(person,temp_nom,nbr_contact)>-1){
                    show(person,find(person,temp_nom,nbr_contact));
                }
            }
                else {
                    ("le contact est introuvable:\n");
                }
                break;
            }

            case 6://quit
            {
                break;
            }

            default:
                printf("vous devez choisir un choix !\n");
                break;
        }




    } while (a!=0);
}             
