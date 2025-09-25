#include <stdio.h>
int main () {
    int n,somme=0;
    printf("entrez le nombre entier\n");
    scanf("%d",&n);
    for (int i=0;i<=n;i++){
        somme+=i;
    }
    printf("la somme des %d premiers nombres naturels est %d",n,somme);
    return 0;

}