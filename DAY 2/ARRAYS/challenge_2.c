#include <stdio.h>
int main() {
    int n;
    printf("entrez le nombre d'elements\n");
    scanf("%d",&n);
    int tab[n];
    printf("saisie les elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
        }
    for(int i=0;i<n;i++){
        printf("%d\n",tab[i]);
        }
        return 0;

}