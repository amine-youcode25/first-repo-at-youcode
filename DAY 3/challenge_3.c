#include <stdio.h>
int main(){
    char string1[99],string2[99];
    printf("entrez la premiere chaine de charactere===>");
    scanf("%s",string1);
    printf("entrez la deuxieme chaine de charactere===>");
    scanf("%s",string2);



    //determiner la longeur du string1
    int longeur1=0;
    for(int i=0;string1[i]!='\0';i++){
        longeur1++;
    }
    
    for(int i=0;string1[i]!=0;i++){
        string1[longeur1+i]=string2[i];
    }
    printf("%s",string1);

    

}