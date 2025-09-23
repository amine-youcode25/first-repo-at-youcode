#include <stdio.h>
int main () {
    int n,even=0;
    printf("entrez le nombre entier\n");
    scanf("%d",&n);
    int i=1;
    while (even<n) {
        if (i%2==0) {
            even++;
            printf("%d.",i);
        }
        i++;
}
}