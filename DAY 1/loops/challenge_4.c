#include <stdio.h>
int main () {
    int n,odd=0;
    printf("entrez le nombre entier\n");
    scanf("%d",&n);
    int i=1;
    while (odd<n) {
        if (i%2==1) {
            odd++;
            printf("%d .",i);
        }
        i++;
}
}