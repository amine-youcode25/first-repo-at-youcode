#include <stdio.h>
int main() {
    int n,sum=0;
    printf("entrez le nombre d'elements\n");
    scanf("%d",&n);
    int tab[n];
    printf("saisie les elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
        }
    for(int i=0;i<n;i++){
        sum+=tab[i];
        }
    printf("la somme des elements de tableau est %d",sum);
        return 0;

}