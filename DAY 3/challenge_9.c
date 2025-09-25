#include <stdio.h>
int main(){
    char string1[99];
    printf("entrez la  chaine de charactere===>");
    scanf("%[^\n]",string1);
    int length=0;

    while(string1[length]!='\0'){
        length++;
    }
    int i=0;
    char cup;
    while(i<length){
        //while is working but if is not //

        if(string1[i]==32){
            int j=i;
//dkhlat lfor had hna 
            while (j<length){
                cup=string1[j];
                string1[j]=string1[j+1];
                string1[j+1]=cup;
                j++;
            }
        }
        i++;
    }
    printf("%s",string1);
}




    