#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


struct zoo {
   //date de creation
    
    int id;
    char nom[50];
    char espece[50];
    int age;
    char habitat[50];
    float poids;
    time_t date_arrive;
    char category[50];

};
struct zoo animal[200];
int animal_id=19;
int animal_nombre=19;

char user_char() {  //function for any typo from user in character inputs
    char newline_check;
    char choix;
    while (1) {
        if (scanf(" %c%c", &choix,&newline_check)==2 &&  newline_check =='\n') { //scanf the integer and the first character
            return choix;
        }
        else {
            while (getchar()!='\n') {
            }
            return 'a';
        }
    }
}
char user_int(); //function for any typo from user in integer inputs

char fgets_char(string[]);

int ajouter(int i);

int main(){
int choix; //utilisateur choix dans le menu.




do {
time_t now;
time(&now);
//menu
printf("===========================================\n");
printf("|            GESTION D'UN ZOO             |\n");
printf("===========================================\n");
printf("===========================================\n");
printf("| 1:Ajouter un Animal                     |\n");
printf("| 2:Afficher les Animaux                  |\n");
printf("| 3:Modifier un Animal                    |\n");
printf("| 4:Supprimer un Animal                   |\n");
printf("| 5:Rechercher un animal                  |\n");
printf("| 6:Statistiques                          |\n");
printf("===========================================\n");
printf("\n\n\nentrez votre choix================>");




choix=user_char();



switch(choix){
    case '1':{
        printf("")
        break;
    }
    case '2':{
        break;
    }
    case '3':{
        break;
    }
    case '4':{
        break;
    }
    case '5':{
        break;
    }
    case '6':{
        break;
    }
    case '7':{
        break;
    }
    case '8':{
        break;
    }

    default:
    {
    choix = '8';
    break;
    }
}
}
while (choix!='8');

return 0;
}


int ajouter(int i){
    time(animal[animal_nombre].date_arrive);
    animal[animal_nombre].id++;
    printf("entrez le nom: ");
    animal[animal_nombre].nom=fgets_char();
    printf("entrez l'espece: ");
    animal[animal_nombre].espece=fgets_char();
    printf("entrez le categorie d'animal: ");
    animal[animal_nombre].category=fgets_char();
    printf("entrez l'age: ");
    scanf("%d",&animal[animal_nombre].age);
    printf("entrez l'habitat: ");
    animal[animal_nombre].habitat;
    printf("entrez le poids: ");
    animal[animal_nombre].poids
}




char fgets_char(void){
    while (getchar()!='\n') {
            }
    char string[50]; //for clean user input and minice new line,the put 0 in the new line of the string 
    fgets(string,50,stdin);
    string[strlen(string)-1]='\0';
    return string[];
}

char user_int(){
   //function for any typo from user in integer inputs
    char newline_check;
    int choix;
    while (1) {
        if (scanf("%d%c", &choix,&newline_check)==2 && newline_check =='\n') { //scanf the integer and the first character
            return choix;
        }
        else {
            while (getchar()!='\n') {
            }
            printf("invalid input");
        }
    }
}

