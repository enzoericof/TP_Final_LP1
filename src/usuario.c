#include <stdio.h>
#include <stdlib.h>
#include <time.h> //librería necesaria para generar números aleatorios
#include "constantes.h"
extern int tablero[TAM_TABLERO][TAM_TABLERO];
extern int matrizcapturas[4][3];
extern int posiblescapturas;
extern int tableroposic[TAM_TABLERO][TAM_TABLERO];

//revisa si la casilla está libre para el usuario. 1 si está, 0 si no
int libreUsuario (int coordX, int coordY){
    if (tablero[(5-coordY)][coordX-1]==0)
        return 1;
    return 0;
}

//pide al usuario la jugada y valida que sea una posible jugada y que la casilla esté libre
int* pedirJugadaUsuario (void){
    static int usuarioJugada [2];
    int ret, ret2;
    do {
        printf("Indica la coordenada en X e Y del lugar donde deseas colocar tu dado: \n");
        ret=scanf("%d %d", &usuarioJugada[0], &usuarioJugada[1]);
        while (getchar() != '\n');
        ret2=libreUsuario(usuarioJugada[0], usuarioJugada[1]);
    } while ((ret!=2 || (usuarioJugada[0]<1 || usuarioJugada[0]>5) || (usuarioJugada[1]<1 || usuarioJugada[1]>5)) || ret2!=1);
    return usuarioJugada;
}

//turno del usuario
void turnoUsuario (int jugador, int color){
    if (color==1){
        RED;printf("\nTURNO DEL USUARIO\n");BLA;
    }
    if (color==2){
        BLUE;printf("\nTURNO DEL USUARIO\n");BLA;
    }
    int suma=0;
    int *punteroUsuario;
    punteroUsuario=pedirJugadaUsuario();
    if (*punteroUsuario==1 || *punteroUsuario==5 || *(punteroUsuario+1)==1 || *(punteroUsuario+1)==5)
        contadorCapturasLados(tablero, *punteroUsuario, *(punteroUsuario+1));
    if (*punteroUsuario!=1 && *punteroUsuario!=5 && *(punteroUsuario+1)!=1 && *(punteroUsuario+1)!=5)
       contadorCapturasMedio(tablero, *punteroUsuario, *(punteroUsuario+1));
    if ((*punteroUsuario==1 && *(punteroUsuario+1)==5) || (*punteroUsuario==5 && *(punteroUsuario+1)==5) || (*punteroUsuario==5 && *(punteroUsuario+1)==1) || (*punteroUsuario==1 && *(punteroUsuario+1)==1))
        contadorCapturasEsquinas(tablero, *punteroUsuario, *(punteroUsuario+1));
    if (posiblescapturas<2){
        tablero[5-*(punteroUsuario+1)][*punteroUsuario-1]=1;
    }
    if (posiblescapturas==2){
        for (int i=0;i<4;i++){
            if (matrizcapturas[i][0]==1){
                suma=suma+tablero[5-(matrizcapturas[i][2])][(matrizcapturas[i][1]-1)];
            }
        }
        if (suma>6){
            tablero[5-*(punteroUsuario+1)][*punteroUsuario-1]=1;
        }
        else{
            tablero[5-*(punteroUsuario+1)][*punteroUsuario-1]=suma;
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
                    scanf("%d", &ret2);
                    while (getchar() != '\n');
                    if (ret2==1){
                        matrizauxiliar[i][0]=2;
                        suma=suma+tablero[(5-matrizcapturas[i][2])][matrizcapturas[i][1]-1];
                    }
                }
            }
        } while (suma>6);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
            printf("%d\t", matrizauxiliar[i][j]);
        }
        printf("\n");}
        for (int l=0;l<4;l++){
            if (matrizauxiliar[l][0]==2){
                tablero[5-(matrizcapturas[l][2])][(matrizcapturas[l][1])-1]=0;
                tableroposic[5-(matrizcapturas[l][2])][(matrizcapturas[l][1])-1]=0;
            }
        tablero[5-*(punteroUsuario+1)][*punteroUsuario-1]=suma;
        }
    }
    tableroPosiciones(tableroposic,7, *punteroUsuario, *(punteroUsuario+1));
    imprimirTablero(color);
    if (color==1){
        RED;printf("\nFIN DEL TURNO\n");BLA;
    }
    if (color==2){
        BLUE;printf("\nFIN DEL TURNO\n");BLA;
    }
    //limpiarPantalla();
}
