#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Player{ //Creacion de estructura del jugador y la maquina
char Nombre[50];
int Vida;
};

typedef struct Carta{ // Creacion de estructura de la carta
char Name[50];
char Type[50];
int LP;
int AP;
int DP;
}Cartass;

struct Historial{

};


int main()
{
    int Select; //Permite seleccionar una opcion al inicio.
    int Retry = 1; //Si esta activa, se repite el menu.
    FILE *file = fopen("Cartas.txt", "r");//Abrir archivo.
    if (file == NULL) { //Si el archivo no esta.
        perror("Error opening file");
        return 1;
    }
    while (Retry == 1){//Menu de inicio
        printf("Welcome to The clash of the guardians!\n What would like to do?\n 1) Play.\n 2) Create a new card.\n 3) See the battle record.\n 4) Exit the game.\n");
        scanf("%d" ,&Select);
        
        if(Select == 1){ //Empezar juego.
            printf("Entering the game...\n");
            Retry = 0;
            break;
        }
        else
        if(Select == 2){ //Crear una carta
            printf("Entering the card creator...\n");
            struct Carta ncarta;
            FILE *file;

            printf("Welcome to the card creator!\n Please enter the values of the cards.\n");
            
            printf("Name: "); //Nombre de carta
            scanf("%s", &ncarta.Name);

            printf("Type: "); //Tipo de carta
            scanf("%s", &ncarta.Type);

            printf("Life points: "); // Puntos de vida
            scanf("%d", &ncarta.LP);

            printf("Attack points: "); //Puntos de ataque
            scanf("%d", &ncarta.AP);

            printf("Defense points: "); // Puntos de defensa
            scanf("%d", &ncarta.DP);
            file = fopen("Cartas.txt", "a");
            if(file ==NULL){ //En caso de no encontrar el .txt
                printf("Error while opening the file");
            }
            fprintf(file, "%s,%s,%d,%d,%d\n", ncarta.Name, ncarta.Type, ncarta.LP, ncarta.AP, ncarta.DP); //Se pone la carta en el .txt

            fclose(file); //Cerrar archivo .txt

        printf("Card created and saved in 'Cartas.txt'!\n");
        
            continue;
        }
        else
        if(Select == 3){ //Mostrar historial
            printf("Now showing past outcomes...\n");

            continue;
        }
        else
        if(Select == 4){ //Salir del juego
            printf("Goodbye, Player!\n");
            exit(0);
        }
        else{ //Si se introduce cualquier otro valor
            printf("That's not a valid option!");
            continue;
        }
    }

    struct Carta cartas[60]; //Baraja principal
    struct Carta cartasJugador[15]; //Baraja del jugador
    struct Carta cartasMaquina[15]; //Baraja de la maquina
    
    int NumeroCartas = 0; //Contador de cartas

    char line[100];
    while (fgets(line, 100, file) != NULL)
        {
            if(NumeroCartas >= 100){
                printf("\nMax deck size reached! (100)");
                break;
            }

            char *token;
            
            token = strtok(line, ",");
            char _name[50];
            strcpy(_name, token);

            token = strtok(NULL, ",");
            char _type[50];
            strcpy(_type, token);
            
            int LP = atoi(strtok(NULL, ","));
            int AP = atoi(strtok(NULL, ","));
            int DP = atoi(strtok(NULL, ","));
        }

    fclose(file);
    return 0;
}