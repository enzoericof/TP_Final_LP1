#include <stdio.h>
#include <stdlib.h>
#include <time.h> //librería necesaria para generar números aleatorios
#include "constantes.h"

//Pide al usuario que decida quien inicia el juego (1 usuario, 2 computadora o 3 aleatorio) y retorna ese valor
int PrimerJugador()
{
    int inicia, ret;
    do {
        GREEN;printf("ELIGE QUIEN INICIA\n");
        BLA;printf("1 si inicia el usuario, 2 si inicia la computadora o 3 si quieres al azar: ");
        ret=scanf("%d", &inicia);
        while (getchar() != '\n');
    } while ( ret != 1 || (inicia < 1 || inicia > 3));
    if (inicia==3){
        srand(time(NULL));
        inicia=1+rand()%2-1+1;
    }
    return inicia;
}

//pide al usuario que decida el color del dado (1 rojo, 2 azul o 3 aleatorio) y retorna ese valor
int ColorDado()
{
    int color, ret;
    do {
        GREEN;printf("ELIGE COLOR DE DADO\n");
        BLA;printf("1 si quieres ");RED;printf("ROJO");
        BLA;printf(", 2 si quieres ");BLUE;printf("AZUL");
        BLA;printf(", 3 si quieres al azar: ");
        ret=scanf("%d", &color);
        while (getchar() != '\n');
    } while ( ret!=1 || (color < 1 || color > 3));
    if (color==3){
        srand(time(NULL));
        color=1+rand()%2-1+1;
    }
    return color;
}

//condicionales previas
void mensajesPrevios (int inicia, int color){
    GREEN;printf("\nCONFIGURACIÓN DEL JUEGO\n");BLA;
    if (inicia==1)
    {
        printf("Inicia el usuario");
    }
    else
    {
        printf("Inicia la computadora");
    }
    if(color==1)
    {
        BLA;printf("\nEl usuario juega con el dado ");RED;printf("ROJO");
        BLA;printf("\nY la computadora con el dado ");BLUE;printf("AZUL");
    }
    else
    {
        BLA;printf("\nEl usuario juega con el dado ");BLUE;printf("AZUL");
        BLA;printf("\nY la computadora con el dado ");RED;printf("ROJO");
    }
    BLA;printf("\n \nPresione enter para iniciar el juego\n");
    getchar();
    //while (getchar() != '\n');
}





