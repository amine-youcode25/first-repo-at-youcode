#include <stdio.h>
int main () {

    char string[99];
    printf("entrez le text====> ");
    scanf("%s",string);
    int length=0;
    for(int i=0;string[i]!='\0';i++){
        length++;
    }
    printf("%d",length);
}