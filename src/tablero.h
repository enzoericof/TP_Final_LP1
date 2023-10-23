/*
 * tablero.h
 *
 *  Created on: 21 oct. 2023
 *      Author: lp1-2023
 */

#ifndef TABLERO_H_
#define TABLERO_H_
void limpiarPantalla();
void InicializarTablero(int tablero [TAM_TABLERO][TAM_TABLERO]);
void contadorCapturasLados (int tablero[TAM_TABLERO][TAM_TABLERO], int x, int y);
void contadorCapturasMedio (int tablero[TAM_TABLERO][TAM_TABLERO], int x, int y);
void contadorCapturasEsquinas (int tablero[TAM_TABLERO][TAM_TABLERO], int x, int y);
void tableroPosiciones (int tableroposic[TAM_TABLERO][TAM_TABLERO], int jugador, int x, int y );
void imprimirTablero(int color);
void Ganador();
int FindelJuego();

#endif /* TABLERO_H_ */
