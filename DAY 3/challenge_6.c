#include <stdio.h>
int main(){
    char string1[99],cup;
    int count=0;
    printf("entrez la  chaine de charactere===>");
    scanf("%s",string1);
    printf("entrez la  chaine de charactere===>");
    scanf(" %c",&cup);
    int i=0,j=i;

    while(string1[j]!='\0'){
        j++;
    }

    while(i<j){
        if(string1[i]==cup){
            count++;
        }
        i++;
    }

    printf("le caractere apparait %d fois dans la chaine",count);
}