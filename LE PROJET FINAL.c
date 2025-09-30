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
int animal_id = 19;
int animal_nombre = 19;
char user_char(); //function for any typo from user in char inputs
int user_int(); //function for any typo from user in integer inputs
void fgets_char(char string[]);
int ajouter(int i);

int main() {
    char choix; //utilisateur choix dans le menu.
    do {
        time_t now;
        time(&now);
        //menu
        printf("===========================================\n");
        printf("|            GESTION D'UN ZOO             |\n");
        printf("===========================================\n");
        printf("%s", ctime(&now));
        printf("===========================================\n");
        printf("| 1:Ajouter un Animal                     |\n");
        printf("| 2:Afficher les Animaux                  |\n");
        printf("| 3:Modifier un Animal                    |\n");
        printf("| 4:Supprimer un Animal                   |\n");
        printf("| 5:Rechercher un animal                  |\n");
        printf("| 6:Statistiques                          |\n");
        printf("===========================================\n");
        printf("\n\n\nentrez votre choix================>");


        choix = user_char();


        switch (choix) {

            case '1': {
                printf("1:Ajouter un Animal.\n");
                printf("2:Ajouter multiple animaux.\n");
                printf("2:retour a menu.\n");
                int user_choix = user_int();
                if (user_choix == 1) {
                    ajouter(++animal_nombre);
                } else if (user_choix == 2) {
                    printf("entrez combien des animaux vous voulez ajouter: ");
                    int multiple = user_int();
                    for (int i = animal_nombre; i <= multiple; i++) {
                        ajouter(++animal_nombre);
                    }
                } else if (user_choix == 3) {
                    break;
                }
                break;
            } //ajouter finished

            case '2': {
                printf("1:Afficher la liste complete.\n");
                printf("2:Afficher la liste trier par Nom.\n");
                printf("3.Afficher la liste trier par Age.\n");
                printf("4.Affichage par Habitat.\n");
                int user_choix = user_int();
                if (user_choix == 1) {}
                else if (user_choix == 2) {}
                else if (user_choix == 3) {}
                else if (user_choix == 4) {}
                break;
            }
            case '3': {
                break;
            }
            case '4': {
                break;
            }
            case '5': {
                break;
            }
            case '6': {
                break;
            }
            case '7': {
                break;
            }
            case '8': {
                break;
            }

            default: {
                choix = '8';
                break;
            }
        }
    } while (choix != '8');

    return 0;
}


int ajouter(int i) {
    time(animal[animal_nombre].date_arrive);
    animal[animal_nombre].id++;
    printf("entrez le nom: ");
    fgets_char(animal[animal_nombre].nom);
    printf("entrez l'espece: ");
    fgets_char(animal[animal_nombre].espece);
    while (1) {
        printf("entrez le categorie d'animal:\n");
        printf("1:carnivores:\n2:herbivores\n3:omnivores\n");
        int ncategory=user_int();
        if (ncategory == 1) {
            break;
        }
        else if (ncategory == 2) {
            break;
        }
        else if (ncategory == 3) {
            break;
        }
        else {
            printf("choix incorrecte! \n");
        }
    }
    printf("entrez l'age: ");
    scanf("%d", &animal[animal_nombre].age);
    getchar();
    printf("entrez l'habitat: ");
    fgets_char(animal[animal_nombre].habitat);
    printf("entrez le poids: ");
    scanf("%f", &animal[animal_nombre].poids);
    getchar();
    return i; //return the i which the indice of the animal so we can do l'affichage function
}


void affichage(int i) {
    printf("| %-10s |  %-20s | %-20s  | %-5s |  %-20s | %-5s   |\n","ID","NOM","ESPECE","AGE","HABITAT","POIDS");
    printf("| %-10d |  %-20s | %-20s  | %-5d |  %-20s | %-5.2f |\n\n\n",animal[i].id,animal[i].nom,animal[i].espece,animal[i].age,animal[i].habitat,animal[i].poids);
}

void fgets_char(char string[]) {
    //for clean user input and mince new line,the put 0 in the new line of the string
    fgets(string, 50,stdin);
    string[strlen(string) - 1] = '\0';
}


char user_char() {
    //function for any typo from user in character inputs
    char newline_check;
    char choix;
    while (1) {
        if (scanf("%c%c", &choix, &newline_check) == 2 && newline_check == '\n') {
            //scanf the integer and the first character
            return choix;
        } else {
            while (getchar() != '\n') {
            }
            return 'a';
        }
    }
}

int user_int() {
    //function for any typo from user in integer inputs
    char newline_check;
    int choix;
    while (1) {
        if (scanf("%d%c", &choix, &newline_check) == 2 && newline_check == '\n') {
            //scanf the integer and the first character
            return choix;
        } else {
            while (getchar() != '\n') {
            }
            printf("invalid input");
        }
    }
}
