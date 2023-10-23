#include <stdio.h>
#include <stdlib.h>
#include <time.h> //librería necesaria para generar números aleatorios
#include "constantes.h"
#include "tablero.h"
#include "preparacion.h"
#include "usuario.h"
#include "computadora.h"

//declaración de variables globales, debido a que se necesita que varias funciones las modifiquen
int posiblescapturas;
int matrizcapturas[4][3];
int tablero[TAM_TABLERO][TAM_TABLERO];
int tableroposic[TAM_TABLERO][TAM_TABLERO];

//desarrolla el juego si comienza el usuario
void empiezaUsuario (int color){
    turnoUsuario(7,color);
    turnoCompu(8,color);
}

//desarrolla el juego si comienza la compu
void empiezaCompu (int color){
    turnoCompu(8,color);
    turnoUsuario(7,color);
}

int main(){
    //inicializaciones
    InicializarTablero(tablero);
    InicializarTablero(tableroposic);
    int inicia=PrimerJugador();
    int color=ColorDado();
    int flag;
    int termina;

    //configuraciones previas al inicio del juego
    mensajesPrevios(inicia,color);
    GREEN;printf("\n\nINICIA EL JUEGO\n");BLA;

    //desarrollo del juego
    do{
        if (inicia==1){
            empiezaUsuario(color);
            printf("\nPresione 0 para terminar el juego o 1 para continuar: ");
            scanf("%d",&termina);
            if (termina==0){
                break;
            }
        }
        if (inicia==2){
            empiezaCompu(color);
            printf("\nPresione 0 para terminar el juego o 1 para continuar: ");
            scanf("%d",&termina);
            if (termina==0){
                break;
            }
        }
        flag=FindelJuego();
    } while (flag!=1);
    GREEN;printf("\n\nFIN DEL JUEGO\n");BLA;
    Ganador();
    return 0;
}
