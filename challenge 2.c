#include <stdio.h>
int main () {
    int n,factorielle=1;
    printf("entrez le nombre\n");
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        factorielle*=i;
    }
    printf("%d",factorielle);
}