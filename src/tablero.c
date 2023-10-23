#include <stdio.h>
#include <stdlib.h>
#include <time.h> //librería necesaria para generar números aleatorios
#include "constantes.h"
extern int tablero[TAM_TABLERO][TAM_TABLERO];
extern int matrizcapturas[4][3];
extern int posiblescapturas;
extern int tableroposic[TAM_TABLERO][TAM_TABLERO];


//limpia la terminal
void limpiarPantalla()
{
    getchar();
    printf("\033[H\033[J");
}

//Inicializa el tablero con ceros
void InicializarTablero(int tablero [TAM_TABLERO][TAM_TABLERO])
{
	for (int i=0; i<TAM_TABLERO; i++)
    {
        for (int j=0; j<TAM_TABLERO; j++)
        {
            tablero[i][j]=0;
        }
    }
}

//cuenta la cantidad de posibles capturas y ordena en una matriz de 4x3 las posiciones de las posibles capturas
//pero solo de las celdas que estan en el perimetro y que no son esquinas
void contadorCapturasLados (int tablero[TAM_TABLERO][TAM_TABLERO], int x, int y){
    posiblescapturas=0;
    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            matrizcapturas[fila][columna] = 0;
        }
    }
    if (x==1 && y!=1 && y!=5){ //comparamos los tres elementos del medio de la primera columna
        if (tablero[4-y][x-1]!=0 && tablero[4-y][x-1]!=6 && (tablero[4-y][x-1]+tablero[5-y][x]<7 || tablero[4-y][x-1]+tablero[6-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[0][0]=1;
            matrizcapturas[0][1]=x;
            matrizcapturas[0][2]=y+1;
        }
        if (tablero[5-y][x]!=0 && tablero[5-y][x]!=6 && (tablero[5-y][x]+tablero[4-y][x-1]<7 || tablero[5-y][x]+tablero[6-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[1][0]=1;
            matrizcapturas[1][1]=x+1;
            matrizcapturas[1][2]=y;
        }
        if (tablero[6-y][x-1]!=0 && tablero[6-y][x-1]!=6 && (tablero[6-y][x-1]+tablero[5-y][x]<7 || tablero[6-y][x-1]+tablero[4-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[2][0]=1;
            matrizcapturas[2][1]=x;
            matrizcapturas[2][2]=y-1;
        }
    }
    if (y==5 && x!=1 && x!=5){ //comparamos los tres elementos del medio de la primera fila
        if (tablero[5-y][x]!=0 && tablero[5-y][x]!=6 && (tablero[5-y][x]+tablero[5-y][x-2]<7 || tablero[5-y][x]+tablero[6-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[1][0]=1;
            matrizcapturas[1][1]=x+1;
            matrizcapturas[1][2]=y;
        }
        if (tablero[6-y][x-1]!=0 && tablero[6-y][x-1]!=6 && (tablero[6-y][x-1]+tablero[5-y][x]<7 || tablero[6-y][x-1]+tablero[5-y][x-2]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[2][0]=1;
            matrizcapturas[2][1]=x;
            matrizcapturas[2][2]=y-1;
        }
        if (tablero[5-y][x-2]!=0 && tablero[5-y][x-2]!=6 && (tablero[5-y][x-2]+tablero[5-y][x]<7 || tablero[5-y][x-2]+tablero[6-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[3][0]=1;
            matrizcapturas[3][1]=x-1;
            matrizcapturas[3][2]=y;
        }
    }
    if (x==5 && y!=1 && y!=5){ //comparamos los tres elementos del medio de la última columna
        if (tablero[6-y][x-1]!=0 && tablero[6-y][x-1]!=6 && (tablero[6-y][x-1]+tablero[5-y][x-2]<7 || tablero[6-y][x-1]+tablero[4-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[2][0]=1;
            matrizcapturas[2][1]=x;
            matrizcapturas[2][2]=y-1;
        }
        if (tablero[5-y][x-2]!=0 && tablero[5-y][x-2]!=6 && (tablero[5-y][x-2]+tablero[6-y][x-2]<7 || tablero[5-y][x-2]+tablero[4-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[3][0]=1;
            matrizcapturas[3][1]=x-1;
            matrizcapturas[3][2]=y;
        }
        if (tablero[4-y][x-1]!=0 && tablero[4-y][x-1]!=6 && (tablero[4-y][x-1]+tablero[5-y][x-2]<7 || tablero[4-y][x-1]+tablero[6-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[0][0]=1;
            matrizcapturas[0][1]=x;
            matrizcapturas[0][2]=y+1;
        }
    }
    if (y==1 && x!=1 && x!=5){ //comparamos los tres elementos del medio de la última fila
        if (tablero[5-y][x-2]!=0 && tablero[5-y][x-2]!=6 && (tablero[5-y][x-2]+tablero[4-y][x-1]<7 || tablero[5-y][x-2]+tablero[5-y][x]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[3][0]=1;
            matrizcapturas[3][1]=x-1;
            matrizcapturas[3][2]=y;
        }
        if (tablero[4-y][x-1]!=0 && tablero[4-y][x-1]!=6 && (tablero[4-y][x-1]+tablero[5-y][x-2]<7 || tablero[4-y][x-1]+tablero[5-y][x]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[0][0]=1;
            matrizcapturas[0][1]=x;
            matrizcapturas[0][2]=y+1;
        }
        if (tablero[5-y][x]!=0 && tablero[5-y][x]!=6 && (tablero[5-y][x]+tablero[5-y][x-2]<7 || tablero[5-y][x]+tablero[4-y][x-1]<7)){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[1][0]=1;
            matrizcapturas[1][1]=x+1;
            matrizcapturas[1][2]=y;
        }
    }
}

//cuenta la cantidad de posibles capturas y ordena en una matriz de 4x3 las posiciones de las posibles capturas
//pero solo de las celdas que están en el medio
void contadorCapturasMedio (int tablero[TAM_TABLERO][TAM_TABLERO], int x, int y){
    posiblescapturas=0;
    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            matrizcapturas[fila][columna] = 0;
        }
    }
    if (tablero[4-y][x-1]!=0 && tablero[4-y][x-1]!=6 && (tablero[4-y][x-1]+tablero[5-y][x]<7 || tablero[4-y][x-1]+tablero[6-y][x-1]<7 || tablero[4-y][x-1]+tablero[5-y][x-2]<7)){
        posiblescapturas=posiblescapturas+1;
        matrizcapturas[0][0]=1;
        matrizcapturas[0][1]=x;
        matrizcapturas[0][2]=y+1;
    }
    if (tablero[5-y][x]!=0 && tablero[5-y][x]!=6 && (tablero[5-y][x]+tablero[4-y][x-1]<7 || tablero[5-y][x]+tablero[6-y][x-1]<7 || tablero[5-y][x]+tablero[5-y][x-2]<7)){
        posiblescapturas=posiblescapturas+1;
        matrizcapturas[1][0]=1;
        matrizcapturas[1][1]=x+1;
        matrizcapturas[1][2]=y;
    }
    if (tablero[6-y][x-1]!=0 && tablero[6-y][x-1]!=6 && (tablero[6-y][x-1]+tablero[5-y][x]<7 || tablero[6-y][x-1]+tablero[4-y][x-1]<7|| tablero[6-y][x-1]+tablero[5-y][x-2]<7)){
        posiblescapturas=posiblescapturas+1;
        matrizcapturas[2][0]=1;
        matrizcapturas[2][1]=x;
        matrizcapturas[2][2]=y-1;
    }
    if (tablero[5-y][x-2]!=0 && tablero[5-y][x-2]!=6 && (tablero[5-y][x-2]+tablero[4-y][x-1]<7 || tablero[5-y][x-2]+tablero[5-y][x]<7|| tablero[5-y][x-2]+tablero[6-y][x-1]<7)){
        posiblescapturas=posiblescapturas+1;
        matrizcapturas[3][0]=1;
        matrizcapturas[3][1]=x-1;
        matrizcapturas[3][2]=y;
    }
}

//cuenta la cantidad de posibles capturas y ordena en una matriz de 4x3 las posiciones de las posibles capturas
//pero solo de las celdas que están en las esquinas
void contadorCapturasEsquinas (int tablero[TAM_TABLERO][TAM_TABLERO], int x, int y){
    posiblescapturas=0;
    for (int fila = 0; fila < 4; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            matrizcapturas[fila][columna] = 0;
        }
    }
    if (x==1 && y==5){ //esquina superior izquierda
        if (tablero[5-y][x]!=0 && tablero[5-y][x]!=6 && tablero[5-y][x]+tablero[6-y][x-1]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[1][0]=1;
            matrizcapturas[1][1]=x+1;
            matrizcapturas[1][2]=y;
        }
        if (tablero[6-y][x-1]!=0 && tablero[6-y][x-1]!=6 && tablero[6-y][x-1]+tablero[5-y][x]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[2][0]=1;
            matrizcapturas[2][1]=x;
            matrizcapturas[2][2]=y-1;
        }
    }
    if (x==5 && y==5){ //esquina superior derecha
        if (tablero[6-y][x-1]!=0 && tablero[6-y][x-1]!=6 && tablero[6-y][x-1]+tablero[5-y][x-2]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[2][0]=1;
            matrizcapturas[2][1]=x;
            matrizcapturas[2][2]=y-1;
        }
        if (tablero[5-y][x-2]!=0 && tablero[5-y][x-2]!=6 && tablero[5-y][x-2]+tablero[6-y][x-1]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[3][0]=1;
            matrizcapturas[3][1]=x-1;
            matrizcapturas[3][2]=y;
        }
    }
    if (x==5 && y==1){ //esquina inferior derecha
        if (tablero[4-y][x-1]!=0 && tablero[4-y][x-1]!=6 && tablero[4-y][x-1]+tablero[5-y][x-2]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[0][0]=1;
            matrizcapturas[0][1]=x;
            matrizcapturas[0][2]=y+1;
        }
        if (tablero[5-y][x-2]!=0 && tablero[5-y][x-2]!=6 && tablero[5-y][x-2]+tablero[4-y][x-1]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[3][0]=1;
            matrizcapturas[3][1]=x-1;
            matrizcapturas[3][2]=y;
        }
    }
    if (x==1 && y==1){ //esquina inferior izquierda
        if (tablero[4-y][x-1]!=0 && tablero[4-y][x-1]!=6 && tablero[4-y][x-1]+tablero[5-y][x]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[0][0]=1;
            matrizcapturas[0][1]=x;
            matrizcapturas[0][2]=y+1;
        }
        if (tablero[5-y][x]!=0 && tablero[5-y][x]!=6 && tablero[5-y][x]+tablero[4-y][x-1]<7){
            posiblescapturas=posiblescapturas+1;
            matrizcapturas[1][0]=1;
            matrizcapturas[1][1]=x+1;
            matrizcapturas[1][2]=y;
        }
    }
}

//funcion que guarda a quien pertenece cada dado
void tableroPosiciones (int tableroposic[TAM_TABLERO][TAM_TABLERO], int jugador, int x, int y )
{
    printf("La jugada realizada fue: %d,%d", x,y);

    tableroposic[(5-y)][x-1]=jugador;
	/*int columnas = 5;
	printf("\n     1   2   3   4   5\n");
	printf("   +---+---+---+---+---+\n");
	for(int i = 0; i < TAM_TABLERO; i++)
	{
	    printf(" %d ", columnas--);
		for(int j = 0; j < TAM_TABLERO; j++)
		{

			printf("| %d ", tableroposic[i][j]);

		}
		printf("|");
		printf("\n   +---+---+---+---+---+\n");
	}*/
}

//imprime el tablero con colores
void imprimirTablero(int color)
{
    int columnas = 5;
    printf("\n");
    printf("\n     1   2   3   4   5\n");
    printf("   +---+---+---+---+---+\n");

    for (int i = 0; i < TAM_TABLERO; i++) {
        printf(" %d ", columnas--);
        for (int j = 0; j < TAM_TABLERO; j++) {
            if (color == 1) {
                if (tableroposic[i][j] == 7) {
                    BLA; printf("|"); RED; printf(" %d ", tablero[i][j]);
                    BLA;
                } else if (tableroposic[i][j] == 8) {
                    BLA; printf("|"); BLUE; printf(" %d ", tablero[i][j]);
                    BLA;
                } else if (tablero[i][j] == 0) {
                    BLA; printf("|   "); // Imprime espacio en blanco
                    BLA;
                } else {
                    BLA; printf("| %d ", tablero[i][j]);
                }
            } else if (color == 2) {
                if (tableroposic[i][j] == 7) {
                    BLA; printf("|"); BLUE; printf(" %d ", tablero[i][j]);
                    BLA;
                } else if (tableroposic[i][j] == 8) {
                    BLA; printf("|"); RED; printf(" %d ", tablero[i][j]);
                    BLA;
                } else if (tablero[i][j] == 0) {
                    BLA; printf("|   "); // Imprime espacio en blanco
                    BLA;
                } else {
                    BLA; printf("| %d ", tablero[i][j]);
                }
            }
        }
        printf("|");
        printf("\n   +---+---+---+---+---+\n");
    }
}

//verifica si se puede seguir jugando                                                                                                                                               int FindelJuego(int tablero[TAM_TABLERO][TAM_TABLERO])
    int FindelJuego(){
        int cont=0;
        for (int i=0; i<TAM_TABLERO; i++)
        {
            for(int j=0; j<TAM_TABLERO; j++)
            {
                if (tablero[i][j]!=0)
                {
                    cont++;
                }
            }
        }
        if (cont==25)
        {
            return 1; //tablero lleno
        }
        else
        {
            return 0;
        }
    }

//verifica quien gana                                                                                                                                                    //Recorre el taberoposic y cuenta los dados de la compu y el usuario (ochos y sietes), el ganador es el que tiene mayor cantidad
void Ganador()
{
    GREEN;printf("\nRESULTADO");BLA;
    int contcompu=0, contusuario=0;
    for (int i=0; i<TAM_TABLERO; i++ )
    {
        for (int j=0; j<TAM_TABLERO; j++)
        {
            if(tableroposic[i][j]==8)
            {
                contcompu++;
            }
            else if (tableroposic[i][j]==7)
            {
                contusuario++;
            }
        }
    }
    if (contcompu>contusuario)
    {
        printf("\n¡La computadora ha ganado!");
    }
    else if(contcompu<contusuario)
    {
        printf("\n¡Eres el ganador!");
    }
    if (contcompu==contusuario)
        printf("\nEmpate parcial, partida inconclusa");
}

