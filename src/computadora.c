#include <stdio.h>
#include <stdlib.h>
#include <time.h> //librería necesaria para generar números aleatorios
#include "constantes.h"
extern int tablero[TAM_TABLERO][TAM_TABLERO];
extern int matrizcapturas[4][3];
extern int posiblescapturas;
extern int tableroposic[TAM_TABLERO][TAM_TABLERO];

//revisa si la casilla está libre para la computadora. 1 si está, 0 si no
int libreCompu (int coordX, int coordY){
    if (tablero[(5-coordY)][coordX-1]==0){
        return 1;}
    return 0;
}

//pide a la computadora una jugada aleatoria y valida si la casilla está libre
int* pedirJugadaCompu (void){
    int ret;
    static int compuJugada [2];
    do {
    srand(time(NULL));
    compuJugada[0]=1+rand()%(5-1+1); //inferior + rand()%(superior+1-inferior)
    compuJugada[1]=1+rand()%(5-1+1);
    ret=libreCompu(compuJugada[0], compuJugada[1]);
    } while (ret!=1);
    return compuJugada;
}

//turno de la compu
void turnoCompu (int jugador, int color){
    if (color==2){
        RED;printf("\nTURNO DE LA COMPUTADORA\n");BLA;
    }
    if (color==1){
        BLUE;printf("\nTURNO DE LA COMPUTADORA\n");BLA;
    }
    int suma=0;
    int *punteroCompu;
    punteroCompu=pedirJugadaCompu();
    if (*punteroCompu==1 || *punteroCompu==5 || *(punteroCompu+1)==1 || *(punteroCompu+1)==5)
        contadorCapturasLados(tablero, *punteroCompu, *(punteroCompu+1));
    if (*punteroCompu!=1 && *punteroCompu!=5 && *(punteroCompu+1)!=1 && *(punteroCompu+1)!=5)
       contadorCapturasMedio(tablero, *punteroCompu, *(punteroCompu+1));
    if ((*punteroCompu==1 && *(punteroCompu+1)==5) || (*punteroCompu==5 && *(punteroCompu+1)==5) || (*punteroCompu==5 && *(punteroCompu+1)==1) || (*punteroCompu==1 && *(punteroCompu+1)==1))
        contadorCapturasEsquinas(tablero, *punteroCompu, *(punteroCompu+1));
    if (posiblescapturas<2){
        tablero[5-*(punteroCompu+1)][*punteroCompu-1]=1;
    }
    if (posiblescapturas==2){
        for (int i=0;i<4;i++){
            if (matrizcapturas[i][0]==1){
                suma=suma+tablero[5-(matrizcapturas[i][2])][(matrizcapturas[i][1]-1)];
            }
        }
        if (suma>6){
            tablero[5-*(punteroCompu+1)][*punteroCompu-1]=1;
        }
        else{
            tablero[5-*(punteroCompu+1)][*punteroCompu-1]=suma;
            for (int i=0;i<4;i++){
                if (matrizcapturas[i][0]==1){
                    tablero[5-(matrizcapturas[i][2])][(matrizcapturas[i][1]-1)]=0;
                    tableroposic[5-(matrizcapturas[i][2])][(matrizcapturas[i][1]-1)]=0;
                }
            }
        }
    }
    if (posiblescapturas>2){
        int ret2;
        int matrizauxiliar[4][3];
        printf("\nElige que dados capturar, siempre y cuando sumen menos de siete");
        do {
            suma=0;
            for (int j=0;j<4;j++){
                for (int k=0;k<3;k++){
                    matrizauxiliar[j][k]=matrizcapturas[j][k];
                }
            }
            for (int i=0;i<4;i++){
                if (matrizcapturas[i][0]==1){
                    printf("\nSi quieres capturar la casilla %d,%d presiona 1 y si no 0: ", matrizcapturas[i][1], matrizcapturas[i][2]);
                    srand(time(NULL));
                    ret2=0+rand()%1-0+1;
                    while (getchar() != '\n');
                    if (ret2==1){
                        matrizauxiliar[i][0]=2;
                        suma=suma+tablero[(5-matrizcapturas[i][2])][matrizcapturas[i][1]-1];
                    }
                }
            }
        } while (suma>6);
        for (int l=0;l<4;l++){
            if (matrizauxiliar[l][0]==2){
                tablero[5-(matrizcapturas[l][2])][(matrizcapturas[l][1])-1]=0;
                tableroposic[5-(matrizcapturas[l][2])][(matrizcapturas[l][1])-1]=0;
            }
        tablero[5-*(punteroCompu+1)][*punteroCompu-1]=suma;
        }
    }
    tableroPosiciones(tableroposic,8, *punteroCompu, *(punteroCompu+1));
    imprimirTablero(color);
    if (color==2){
        RED;printf("\nFIN DEL TURNO\n");BLA;
    }
    if (color==1){
        BLUE;printf("\nFIN DEL TURNO\n");BLA;
    }
    //limpiarPantalla();
}
