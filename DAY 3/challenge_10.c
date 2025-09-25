//Challenge 10 : Trouver un Sous-String
//Écrivez un programme C qui lit une chaîne de caractères principale
//et une sous-chaîne, puis vérifie si la sous-chaîne est présente
//dans la chaîne principal/
//affichez un message indiquant si la sous-chaîne est trouvée ou non.
#include <stdio.h>
int main () {
    char string1[99],understring[99];
    printf("enter the string\n");
    scanf("%s",string1);
    printf("enter the the sous chaine\n");
    scanf("%s",understring);
    int L1=0,L2=0;
    while(string1[L1]!='\0')
        {
            L1++;
        }
    while(understring[L2]!='\0')
        {
             L2++;
        }


    int i=0;
    int in=0;

    while(i<L1){
        //
        if(string1[i]==understring[0]){
            int j=i;
            int y=0;
            
            while(y<L2){

                if(string1[j]==understring[y]) {
                    in=1;
                }
                else {
                    in=0;
                    break;
                }
                j++;
                y++;
            }
        //
            if(in==1){
            break;
            }
        }
        i++;
    }    

    if(in==1) {
        printf("its working, its in");
    }
    else {
        printf(":(");
    }


}