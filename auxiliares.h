//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

//Ejercicios


//5.2.1. Auxiliares
int aparicionesEnTablero(tablero t, casilla p);
int colorPieza(tablero t, coordenada c);
jugador contrincante(jugador j);
jugador jugadorDeTurno(posicion p);
int piezaEn(tablero t, coordenada c);
int jugadorEn(tablero t, coordenada c);
casilla setCasilla(int, int);

//5.2.2. Predicados
bool esJugadorValido(jugador);
bool esTableroValido(tablero);
bool casillasValidas(tablero t);
bool esCasillaVacia(casilla c);
bool esPiezaValida(pieza p);
bool esMatriz8(tablero t);
bool sinPeonesNoCoronados(tablero t);
bool cantidadValidaDePiezas(tablero t);
bool cantidadPeonesValidos(tablero t);
bool cantidadReyesValidos(tablero t);
bool cantidadAlfilesValidos(tablero t);
bool cantidadTorresValidas(tablero t);


#endif //AJEDREZLITE_AUXILIARES_H
