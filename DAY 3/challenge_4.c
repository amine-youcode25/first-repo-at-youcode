#include <stdio.h>
int main() {
    char string1[99],string2[99];
    printf("enter\n");
    scanf("%s",string1);
    printf("enter\n");
    scanf("%s",string2);
    int i=0,j=0,cmp=0;


    //lengthof1
    while(string1[i]!='\0'){
        i++;
    }

    //lengthof2
    while(string2[j]!='\0'){
        j++;
    }
    //condition if they have equal size

    if(i==j){
        
    while(i>0){
        if(string1[i]==string2[i]){
            cmp=1;
        }
        i--;
    }

        if (cmp==1) printf("les chainces sont egals");
    }
    else {
        printf("les chaines sont differentes");
    }
    return 0;
}