#include <stdio.h>
#include <string.h>
#include <time.h>

struct zoo {
    //time_t now;
    int id;
    char nom[50];
    char espece[50];
    int age;
    char habitat[50];
    float poids;
    char category[50];
};


struct count{
    char name[50];
    int count;
};

int espece_count_for_struct=15;
struct count espece[200]={
    {"Lion",4},
    {"Tigre",1},
    {"Ours",1},
    {"Elephant",2},
    {"Zebre",1},
    {"Hippopotame",1},
    {"Lemurien",1},
    {"Girafe",1},
    {"Suricate",1},
    {"Phacochere",1},
    {"Serpent",1},
    {"Perroquet",1},
    {"Chien sauvage",1},
    {"Tortue",1},
    {"Oiseau",1},
    {"Gorille",1}
};


struct zoo animal[200] = {
    {0, "Simba", "Lion", 5, "Savane", 190.5,"Carnivores"},
    {1, "Nala", "Lion", 4, "Savane", 175.0,"Carnivores"},
    {2, "ShereKhan", "Tigre", 8, "Jungle", 220.3,"Carnivores"},
    {3, "Baloo", "Ours", 12, "Foret", 310.0,"Carnivores"},
    {4, "Raja", "Elephant", 15, "Savane", 540.7,"Herbivores"},
    {5, "Marty", "Zebre", 6, "Savane", 300.2,"Herbivores"},
    {6, "Gloria", "Hippopotame", 10, "Riviere", 450.0,"Herbivores"},
    {7, "Alex", "Lion", 7, "Savane", 200.0,"Carnivores"},
    {8, "Julien", "Lemurien", 3, "Jungle", 12.5,"Herbivores"},
    {9, "Melman", "Girafe", 9, "Savane", 390.8,"Herbivores"},
    {10, "Timon", "Suricate", 2, "Desert", 1.2,"Omnivores"},
    {11, "Pumbaa", "Phacochere", 5, "Savane", 120.0,"Herbivores"},
    {12, "Scar", "Lion", 11, "Savane", 210.4,"Carnivores"},
    {13, "Kaa", "Serpent", 6, "Jungle", 45.0,"Carnivores"},
    {14, "Iko", "Perroquet", 4, "Jungle", 2.1,"Herbivores"},
    {15, "Dumbo", "Elephant", 3, "Savane", 320.0,"Herbivores"},
    {16, "Kiki", "Chien sauvage", 7, "Savane", 25.0,"Carnivores"},
    {17, "Donatello", "Tortue", 40, "Riviere", 90.5,"Herbivores"},
    {18, "Polly", "Oiseau", 5, "Jungle", 1.5,"Herbivores"},
    {19, "Kong", "Gorille", 13, "Jungle", 180.0,"Omnivores"}
};



int animal_id = 19;
int animal_nombre = 19;
char user_char(); //function for any typo from user in char inputs
float read_poids();
int user_int(); //function for any typo from user in integer inputs
void fgets_char(char string[]);
int ajouter(int i);
void affichage(int i);



int recherche(char keyword1[],char keyword2[],int y) { //search function
    if (strstr(keyword1, keyword2) !=NULL ) {
        return y;
        }
    else {
        return (-1);
    }
}

int int_search(int b){
    for(int i=0;i<=animal_nombre;i++){
        if(animal[i].id==b) return i;
    }
        return -1;

}




int main() {
    char choix; //utilisateur choix dans le menu.
    do {
        time_t now;
        time(&now);
        //menu
        printf("===========================================\n");
        printf("|            GESTION D'UN ZOO             |\n");
        printf("===========================================\n");
        printf("         %s", ctime(&now));
        printf("===========================================\n");
        printf("| 1:Ajouter un Animal                     |\n");
        printf("| 2:Afficher les Animaux                  |\n");
        printf("| 3:Modifier un Animal                    |\n");
        printf("| 4:Supprimer un Animal                   |\n");
        printf("| 5:Rechercher un animal                  |\n");
        printf("| 6:Statistiques                          |\n");
        printf("| 7:Quitter le program                    |\n");
        printf("===========================================\n");
        printf("\n\n\nentrez votre choix================>");


        choix = user_char();


        switch (choix) {

            case '1': {
                printf("1:Ajouter un Animal.\n");
                printf("2:Ajouter multiple animaux.\n");
                printf("3:retour a menu.\n");
                int user_choix = user_int();
                if (user_choix == 1) {
                    animal_nombre++;
                    ajouter(animal_nombre);
                } else if (user_choix == 2) { //for multiple
                    printf("entrez combien des animaux vous voulez ajouter: ");
                    int multiple = user_int();
                    for (int i = 0; i < multiple; i++) {
                        animal_nombre++;
                        ajouter(animal_nombre);
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
                printf("4.Affichage par Habitat.\n===>");
                int user_choix = user_int();
                if (user_choix == 1) { //affiche la liste
                    for(int i=0;i<=animal_nombre;i++){
                        affichage(i);
                    }
                }
                else if (user_choix == 2) { //trier avec le nom

                    int arrayx[animal_nombre+1],temp;
                    for(int i=0;i<=animal_nombre;i++){
                        arrayx[i]=i;
                    } //array d'indices


                    for(int i=0;i<=animal_nombre;i++){
                        for(int j=0;j<animal_nombre;j++){

                            if( strcmp(animal[arrayx[j]].nom,animal[arrayx[j+1]].nom)> 0){
                                temp=arrayx[j+1];
                                arrayx[j+1]=arrayx[j];
                                arrayx[j]=temp;
                            }
                        }
                    } //storing indices trier


                    for(int i=0;i<=animal_nombre;i++){
                        affichage(arrayx[i]);
                    }//affiachage avec array alraedy with indexs trier

                }

                else if (user_choix == 3) { //trier avec age

                    int array_age[animal_nombre+1];
                    for(int i=0;i<=animal_nombre;i++){
                        array_age[i]=i;
                    }

                    for(int i=0;i<=animal_nombre;i++){
                        for(int j=0;j<animal_nombre;j++){
                            if(animal[array_age[j]].age > animal[array_age[j+1]].age){
                                int temp=array_age[j+1];
                                array_age[j+1]=array_age[j];
                                array_age[j]=temp;
                            }
                        }
                    }

                    for(int i=0;i<=animal_nombre;i++){
                        affichage(array_age[i]);
                    }

                }
                else if (user_choix == 4) { //recherche par habitat
                    char habitat_temp[50];
                    int ahla=0;
                    printf("entrez l'habitat:\n==>");
                    fgets_char(habitat_temp);
                    for(int i=0;i<=animal_nombre;i++){
                    if(recherche(animal[i].habitat,habitat_temp,i)>-1){
                     affichage( recherche(animal[i].habitat,habitat_temp,i));
                     ahla=1;
                    }
                    }

                    if (ahla==0){
                        printf("y a pas d'animal avec cette habitat:\n");
                    }


                }
                break;
            }
            case '3': { //modifier un animal sulement l'habitat and l'age

                char temp_input[3][50]; //thought i can medify more than one string.
                int store_index[100];
                int index=-1,ahla=0;
                int new_age=0;

                printf("entrez l'animal que vous voulez modifier:\n==>");
                fgets_char(temp_input[0]);
                for(int i=0;i<=animal_nombre;i++){
                    if(recherche(animal[i].nom,temp_input[0],i)>-1){
                        index++;
                        store_index[index]=i;
                        ahla=1;
                    }
                }
                if (ahla==0){
                    printf("animal introuvable\n");
                    break;
                }
                int choix=0;
                for(int i=0;i<=index;i++){
                    printf(":____________________________________________%d____________________________________________\n",i);
                    affichage(store_index[i]);
                }
                printf("entrez le nombre d'animal:(pas le ID)");
                scanf("%d",&choix);
                getchar();
                if(choix > -1 && choix <=index){
                    printf("entrez le nouveau habitat (appuyez sur entrez si vous navez rien a changer)\n==>");
                    fgets(temp_input[1],50,stdin);

                    if(temp_input[1][0]!='\n') {
                        temp_input[1][strlen(temp_input[1])-1]='\0';
                        strcpy(animal[store_index[choix]].habitat,temp_input[1]);
                    }

                    printf("entrez le nouveau age d'animal (entrez 0 si vous n'avez rien a changer))\n==>");
                    scanf("%d",&new_age);
                    getchar();
                    if(new_age!=0) animal[store_index[choix]].age=new_age;
                    printf("la modification a ete enregistrer!\n");
                    affichage(store_index[choix]);
                }


                else {
                    printf("invalid choix\n");
                }


                break;
            }
            case '4': { //supprimer un animal. par id ez



                for(int i=0;i<=animal_nombre;i++){ //affichage dla liste bach user ykhtar id en cas nsa...
                        affichage(i);
                    }
                printf("entrez l'id d'animal:\n==>");
                int dele_choix=user_int();
                int dele;

                if (dele_choix>-1 && dele_choix <= animal_id){ //kbar mn 0 o sghar mn akhir id we assigned
                    affichage(int_search(dele_choix)); //int search return i of ID
                    printf("vous etes sur que vous voulez supprimer cette animal(0:non/1:oui) ?\n==>");
                    scanf("%d",&dele);
                    getchar();
                    if(dele==0) break;
                    else if(dele==1){
                        if (int_search(dele_choix)>=0){ //return -1 si msa7na xi id meme daz f satement lwla hna maghadix ydoz
                        for(int i =int_search(dele_choix);i<animal_nombre;i++){
                            animal[i]=animal[i+1];  //shift
                        }
                        animal_nombre--;
                        printf("   l'animal a ete supprimer avec succes!\n");
                        }
                        else {
                            printf("id introuvable!\n"); //cad tmsa7
                            break;
                        }
                    }
                    else{
                        printf("choix invalid!\n");
                        break;
                    }
                }
                else{
                    printf("id introuvable!\n");
                }


                break;
            }
            case '5': { //recherch par id nom et espece :
                //recherche par id
                printf("1:rechercher par ID\n");
                printf("2:rechercher par Nom\n");
                printf("3:rechercher par espece\n");
                printf("4:retour a la menu principale\n==>");
                int search_menu=user_int();
                if (search_menu==1){
                printf("entrez l'id d'animal:\n==>");
                int search_id=user_int();
                if ( int_search(search_id)> -1){
                    affichage(int_search(search_id));
                }
                else {
                    printf("id introuvable!\n");
                }
            }
                else if (search_menu==2){
                printf("entrez le nom d'animal:\n==>");
                char temp_input[50];
                fgets_char(temp_input);
                int ahla=0;
                for(int i=0;i<=animal_nombre;i++){
                    if (recherche(animal[i].nom,temp_input,i)>-1){
                    affichage(recherche(animal[i].nom,temp_input,i));
                    ahla=1;
                }}
                if (ahla==0) printf("le nom introuvable!\n");

            }

                else if(search_menu==3){
                printf("entrez l'espece d'animal:\n==>");
                char temp_input[50];
                fgets_char(temp_input);
                int ahla=0;
                for(int i=0;i<=animal_nombre;i++){
                    if (recherche(animal[i].espece,temp_input,i)>-1){
                    affichage(recherche(animal[i].espece,temp_input,i));
                    ahla=1;
                }
            }
                if (ahla==0) printf("l'espece introuvable!\n");
            }

                else if(search_menu==4){
                break;
            }

                else {
                printf("choix invalid!\n");
                break;
            }

                break;
            }
            case '6': {
                printf("le nombre total d'animaux dans le zoo est : %d\n",animal_nombre+1);



                //----------------------------------------------------------- 1
                int sum=0;
                for(int i=0;i<=animal_nombre;i++){
                    sum+=animal[i].age;
                }

                printf("l'age moyen des animaux:%d\n",sum/(animal_nombre+1));
                //-----------------------------------------------------------------2



                int min=animal[0].age,max=animal[0].age,index_store1,index_store2;
                    for(int i=0;i<=animal_nombre;i++){
                        if (min>animal[i].age){
                            min = animal[i].age;
                            index_store1=i;
                        }
                    }
                    for (int i=0;i<=animal_nombre;i++){
                        if(max<animal[i].age){
                            max=animal[i].age;
                            index_store2=i;
                        }
                    }

                    printf("le plus jeune animal est %s\n",animal[index_store1].nom);
                    affichage(index_store1);
                    printf("le plus vieux animal est %s\n",animal[index_store2].nom);
                    affichage(index_store2);


                    //as always indice f array--------------------------------------------------------3

                    int array_tosort_forespece[espece_count_for_struct+1];
                    for(int i=0;i<=espece_count_for_struct;i++){
                        array_tosort_forespece[i]=i;
                    }

                    for(int i=0;i<=espece_count_for_struct;i++){ //tri but just the indices to affiche in a good sort
                        for(int j=0;j<espece_count_for_struct;j++){
                        if(espece[array_tosort_forespece[j]].count>espece[array_tosort_forespece[j+1]].count){
                            int temp=array_tosort_forespece[j+1];
                            array_tosort_forespece[j+1]=array_tosort_forespece[j];
                            array_tosort_forespece[j]=temp;
                        }
                    }
                }
                printf("les especes les plus representes sont:\n"); // les 3 especes dans le sort
                for(int i=espece_count_for_struct;i>espece_count_for_struct-3;i--){
                    printf("=======   %-10s-   %-5d=======\n",espece[array_tosort_forespece[i]].name,espece[array_tosort_forespece[i]].count);
                }
                break;
            }
            case '7': {
                choix='8';
                break;
            }

            default: {
                choix = 'a';
                break;
            }
        }
    } while (choix != '8');

    return 0;
}


int ajouter(int i) {//return i for affichage
    // time(&animal[animal_nombre].date_arrive);
    animal_id++;
    animal[animal_nombre].id=animal_id;
    printf("entrez le nom: ");
    fgets_char(animal[animal_nombre].nom);
    printf("entrez l'espece: ");
    fgets_char(animal[animal_nombre].espece);


    int ahla_espece=1; //to know deja inclus ou pas
    for(int i=0;i<=espece_count_for_struct;i++){ //verify wach deja espece inclus ou non
        if(strcmp(animal[animal_nombre].espece,espece[i].name)==0){
            ahla_espece=0;
            espece[i].count++; //cad deja inclus et on va ajouter 1 dans le count ( pour les plus representes )
            break;
        }
        else {
            ahla_espece=1;
        }
    }

    if(ahla_espece==1){ // si il arrive la cad que mkynach fmon liste et je dois lajoute
        espece_count_for_struct++;
        strcpy(espece[espece_count_for_struct].name,animal[animal_nombre].espece); //copy the new espece to my struct
        espece[espece_count_for_struct].count=1; //done
    }



        // boucle with 1 pour forcer user d'entrer un chiffre.
    while (1) {
        printf("entrez le categorie d'animal:\n");
        printf("1:Carnivores:\n2:Herbivores\n3:Omnivores\n===>");
        int ncategory=user_int();
        if (ncategory == 1) {
            strcpy(animal[animal_nombre].category,"Carnivores");
            break;
        }
        else if (ncategory == 2) {
            strcpy(animal[animal_nombre].category,"Herbivores");
            break;
        }
        else if (ncategory == 3) {
            strcpy(animal[animal_nombre].category,"Omnivores");
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
    fgets_char(animal[animal_nombre].habitat); //jai besoin najouter les habitat li machi deja endi f struct


    //for optionnel poid
    printf("vous voulez entrez le poids (0:Non/1:Yes) ?\n==>");
    int option = user_int();
    if (option == 1) {
        printf("entrez le poids: \n==>");
        scanf("%f", &animal[animal_nombre].poids);
        getchar();
    }

    // animal[animal_nombre].poids= read_poids(); //ill hundle -1 flaffichage can'tttt
    printf("\nL'animal a ete ajoute avec succes!\n");
    affichage(animal_nombre);
    printf("\n\n");
    return i; //return the i which the indice of the animal so we can do l'affichage function
}


void affichage(int i) {
    char message[]="!!!";
    if(animal[i].age<20){
        strcpy(message,"   ");
    }

    printf("________________________________________________________________________________________________________________\n");
    printf("| %-5s |  %-20s | %-20s  | %-5s  |  %-15s | %-6s  |  %-15s|\n","ID","NOM","ESPECE","AGE","HABITAT","POIDS","categorie");
    // printf("| %-5d |  %-20s | %-20s  | %-3d%s |  %-15s | %-7.2f |  %-15s|\n",animal[i].id,animal[i].nom,animal[i].espece,animal[i].age,message,animal[i].habitat,animal[i].poids,animal[i].category);
    printf("| %-5d |  %-20s | %-20s  | %-3d%s |  %-15s |",animal[i].id,animal[i].nom,animal[i].espece,animal[i].age,message,animal[i].habitat);
    if (animal[i].poids>0) printf(" %-7.2f ",animal[i].poids);
    else {
        printf(" %-6s  ","____");
    }
    printf("|  %-15s|\n",animal[i].category);
    printf("----------------------------------------------------------------------------------------------------------------\n");
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
        if (scanf("%c%c", &choix, &newline_check) == 2 && newline_check == '\n') {
            //scanf the integer and the first character
            return choix;
        } else {
            while (getchar() != '\n') {
            }
            return 'a';
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
            printf("invalid input\n");
        }
    }
}
