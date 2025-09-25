#include <stdio.h>
int main () {
    int base,exposant,pow=1;
    printf("entrez le base:\n");
    scanf("%d",&base);
    printf("entrez le exposant:\n");
    scanf("%d",&exposant);
    for (int i=1;i<=exposant;i++){
        pow*=base;
    }
    printf("la puissance de %d base eleve a un exposant %d est %d",base,exposant,pow);

}