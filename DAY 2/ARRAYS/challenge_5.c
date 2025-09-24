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
    int min=tab[0];
    for(int i=0;i<n;i++){
        if (min>tab[i]) min = tab[i];
    }
    printf("le minimum nombre %d",min);
    return 0;
}