#include <stdio.h>

int main(){
    char string1[99];
    printf("entrez la  chaine de charactere===>");
    scanf("%s",string1);
    int j=0;
    while(string1[j]!='\0'){
        j++;
    }
    j--;
    while(j>=0){
        if(string1[j]<123 && string1[j]>96 ) string1[j]=string1[j]-32;
        j--;
    }
    printf("%s",string1);
}