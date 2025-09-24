#include <stdio.h>
int main() {
    int n,f;

    printf("entrez le nombre d'elements\n");
    scanf("%d",&n);

    int tab[n];

    printf("entrez le facteur de multiplication\n");
    scanf("%d",&f);

    printf("saisie les elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&tab[i]);
        }
    

    for(int i=0;i<n;i++){
    tab[i]=tab[i]*f;
    printf("%d\n",tab[i]);
        }
    return 0;
}