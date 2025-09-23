#include <stdio.h>
int main () {
    int n;
    printf("entrez le chiffre:");
    scanf("%d",&n);
    while(n>0){
        printf("%d",n%10);
        n/=10;
    }
}