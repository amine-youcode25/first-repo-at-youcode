#include <stdio.h>
int main(){
    char string1[99];
    printf("entrez la  chaine de charactere===>");
    scanf("%s",string1);
    int i=0,j=i;
    char cup;
    
    while(string1[j]!='\0'){
        j++;
    }

    j--;

    while(i!=j){
        cup=string1[i];
        string1[i]=string1[j];
        string1[j]=cup;
        i++;
        j--;
    }
    printf("%s",string1);
}