#include <stdio.h>
#include <string.h>
int main() {
    int menubool=1,menu;
    char titre[99][50],auteur[99][30];
    int qte[99],nbr_livre=0;
    float prix[99];

    do {
        //menu=======================================================================
        printf("===========================================================\n");
        printf("1.Ajouter un livre au stock.\n");
        printf("2.Afficher tous les livres disponibles.\n");
        printf("3.Rechercher un livre par son titre.\n");
        printf("4.Mettre a jour la quantite d'un livre.\n");
        printf("5.Supprimer un Livre du Stock\n");
        printf("6.Afficher le nombre total de livres en stock.\n");
        printf("7.quitter le programe\n\n");
        scanf("%d",&menu);



        //commands
    
        switch (menu) {



            //add books
            case 1:
    
                    printf("entrez le titre du livre\n");
                    scanf("%s",titre[nbr_livre]);
                    printf("entrez l'auteur du livre\n");
                    scanf("%s",auteur[nbr_livre]);
                    printf("entrez le prix du livre\n");
                    scanf("%f",&prix[nbr_livre]);
                    printf("entrez la qte du livre en stock\n");
                    scanf("%d",&qte[nbr_livre]);
                    printf("le livre ete ajouter avec succes\n\n");

                nbr_livre++;
                break;


                //show books
            case 2:
            {
                for (int i=0;i<nbr_livre;i++) {
                    printf("=====REF-%d=====\n",i+1);
                    printf("Titre du livre: %s\n",titre[i]);
                    printf("Auteur du livre: %s\n",auteur[i]);
                    printf("prix du livre: %.2f\n",prix[i]);
                    printf("Qte en stock: %d\n",qte[i]);
                }
                printf("\n\n");
                break;
            }
            case 3:
            {
            char title[1][99];
                printf("entrez le titre du livre:\n");
                scanf("%s",title[0]);
                for (int i=0;i<=nbr_livre;i++) {
                    if (strcmp(title[0],titre[i])==0) {
                    printf("=====REF-%d=====\n",i+1);
                    printf("Titre du livre: %s\n",titre[i]);
                    printf("Auteur du livre: %s\n",auteur[i]);
                    printf("prix du livre: %.2f\n",prix[i]);
                    printf("Qte en stock: %d\n",qte[i]);
                    }
                    else {
                        printf("le livre nexsite pas\n");
                    }
                }
                break;
            }
                //change qte
            case 4:
            {
                char title[1][50];
                int many,done=0;
                printf("entrez le titre du livre:\n");
                scanf("%s",title[0]);
                printf("entrez la nouvelle Qte:\n");
                scanf("%d",&many);
                for (int i=0;i<=nbr_livre;i++) {
                    if (strcmp(title[0],titre[i])==0) {
                        qte[i]=many;
                        done=1;
                        break;
                    }
                }
                if (done) printf("la qte ete medifiee\n");
                else {
                    printf(" le livre n'existe pas\n");
                }
                break;
            }
                //delete
            case 5:
            {
            char delete[1][99];
            int done=0;
            printf("entrez le titre du livre:\n");
            scanf("%s",delete[0]);
            for(int i=0;i<nbr_livre;i++){
                if(strcmp(delete[0],titre[i])==0){
                    nbr_livre--;
                    for (int j=i;j<=nbr_livre;j++){
                    strcpy(titre[j],titre[j+1]);
                    strcpy(auteur[j],auteur[j+1]);
                    prix[i]=prix[j+1];
                    qte[i]=qte[j+1];
                    }
                    printf("le livre a ete supprimer\n");              
                                }
                                else {
                                    printf("le livre n'existe pas\n");
                                }
            }
            break;
            }
        
            case 6:
            {
                int sum_qte=0;
                for(int i=0;i<nbr_livre;i++){
                    sum_qte+=qte[i];
                }
                printf("QTE total: %d\n",sum_qte);
            }
                break;
            case 7:
                menubool=0;
                break;
            default:
                printf("typo\n");
                break;
        }
    }while (menubool);
}

