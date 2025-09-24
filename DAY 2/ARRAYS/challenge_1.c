#include <stdio.h>
int main () {

    int tab[]={4,7,9,3,5};
    printf("entrez les valeurs\n");
    for (int i=0;i<5;i++) {
        scanf("%d",&tab[i]);
    }

    for(int i=0;i<5;i++){
        printf("%d",tab[i]);
    }

    return 0;
}