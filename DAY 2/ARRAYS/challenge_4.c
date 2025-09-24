#include <stdio.h>
int main() {
    int n
    printf("entrez le nombre d'elements\n");
    scanf("%d",&n);
    int tab[n];
    printf("saisie les elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
        }
    int max=tab[0];
    for(int i=0;i<n;i++){
        if (max<tab[i]) max = tab[i];
    }
    printf("le maximum nombre %d",max);
    return 0;
}