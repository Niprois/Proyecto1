#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Jugador{
char Nombre[50];
int Vida;
};

typedef struct Carta{
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
        if(Select == 2){ //Crear una carta
            printf("Entering the card creator...\n");
            struct Carta ncarta;
            FILE *file;

            printf("Welcome to the card creator!\n Please enter the values of the cards.\n");
            
            printf("Name: ");
            scanf("%s", &ncarta.Name);

            printf("Type: ");
            scanf("%s", &ncarta.Type);

            printf("Life points: ");
            scanf("%d", &ncarta.LP);

            printf("Attack points: ");
            scanf("%d", &ncarta.AP);

            printf("Defense points: ");
            scanf("%d", &ncarta.DP);
            file = fopen("Cartas.txt", "a");
            if(file ==NULL){
                printf("Error while opening the file");
            }
            fprintf(file, "%s %s %d %d %d\n", ncarta.Name, ncarta.Type, ncarta.LP, ncarta.AP, ncarta.DP);

            fclose(file);

        printf("Card created and saved in 'Cartas.txt'!\n");
        
            continue;
        }
        if(Select == 3){ //Mostrar historial
            printf("Now showing past outcomes...\n");

            continue;
        }
        if(Select == 4){ //Salir del juego
            printf("Goodbye, Player!\n");
            exit(0);
        }
        else{ //Si se introduce cualquier otro valor
            printf("That's not a valid option!");
            continue;
        }

    }

    struct Carta cartas[80]; //Baraja principal
    struct Carta cartasJugador[15]; //Baraja del jugador
    struct Carta cartasMaquina[15]; //Baraja de la maquina
    
    
    int NumeroCartas = 0; //Contador de cartas

    while (fscanf(file, "%s %s %d %d %d", cartas[NumeroCartas].Name, //Leer cartas desde archivo
    cartas[NumeroCartas].Type,&cartas[NumeroCartas].AP,&cartas[NumeroCartas].LP,&cartas[NumeroCartas].DP) == 5) {

        NumeroCartas++;

        if (NumeroCartas >= 60) {
            printf("Cantidad de prueba excedidad (60).\n");
            break;
        }
    }


    fclose(file);

    //Sistema de pelea




    printf("List of cards\n");//Imprimir las cartas existentes
    for (int i = 0; i < NumeroCartas; i++) {
        printf("Name: %s, Type: %s, Life: %d, Attack: %d, Defense: %d\n", cartas[i].Name,
        cartas[i].Type, cartas[i].LP, cartas[i].AP, cartas[i].DP);
    }
    return 0;
}