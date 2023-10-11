#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Jugador{
char Nombre[50];
int Vida;
};

struct Carta{
char Name[50];
char Type[50];
int LP;
int AP;
int DP;
};

struct Historial{

};

int main()
{
    int Select;
    int Retry = 1;
    while (Retry == 1){
        printf("Welcome to The clash of the guardians!\n What would like to do?\n 1) Play.\n 2) Create a new card.\n 3) See the battle record.\n 4) Exit the game.");
        scanf("%d" ,&Select);
        if(Select == 1){
            printf("Entering the game...\n");
            Retry = 0;
        }
        if(Select == 2){
            printf("Entering the card creator...\n");

        }
        if(Select == 3){
            printf("Now showing past outcomes...\n");

        }
        if(Select == 4){
            printf("Goodbye, Player!\n");
            exit(0);
        }
        else{
            printf("That's not a valid option!");
        }

    }
    FILE *file = fopen("Cartas.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Carta cartas[100];

    int NumeroCartas = 0;

    while (fscanf(file, "%s %s %d %d %d", cartas[NumeroCartas].Name,
    cartas[NumeroCartas].Type,&cartas[NumeroCartas].AP,&cartas[NumeroCartas].LP,&cartas[NumeroCartas].DP) == 5) {

        NumeroCartas++;

        if (NumeroCartas >= 60) {
            printf("Cantidad de prueba excedidad (60).\n");
            break;
        }
    }

    fclose(file);

    printf("List of cards\n");
    for (int i = 0; i < NumeroCartas; i++) {
        printf("Name: %s, Type: %s, Life: %d, Attack: %d, Defense: %d\n", cartas[i].Name,
        cartas[i].Type, cartas[i].LP, cartas[i].AP, cartas[i].DP);
    }
    return 0;
}