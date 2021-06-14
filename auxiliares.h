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
tablero tableroActual (const posicion &p );

//Ejercicios


//5.2.1. Auxiliares
int aparicionesEnTablero(const tablero &t, casilla p);
int colorPieza(const tablero &t, coordenada c);
jugador contrincante(jugador j);
jugador jugadorDeTurno(posicion p);
int piezaEn(const tablero &t, coordenada c);
int jugadorEn(const tablero &t, coordenada c);
casilla setCasilla(pieza p, jugador j);

//5.2.2. Predicados
bool esJugadorValido(jugador j);
bool esTableroValido(const tablero &t);
bool casillasValidas(const tablero &t);
bool esCasillaVacia(casilla c);
bool esPiezaValida(pieza p);
bool esMatriz8(const tablero &t);
bool sinPeonesNoCoronados(const tablero &t);
bool cantidadValidaDePiezas(const tablero &t);
bool cantidadPeonesValidos(const tablero &t);
bool cantidadReyesValidos(const tablero &t);
bool cantidadAlfilesValidos(const tablero &t);
bool cantidadTorresValidas(const tablero &t);
tablero tableroInicial();
bool casillaAtacada(coordenada c, const tablero &t, jugador j);
bool ataca(const tablero &t, casilla c, casilla d);
bool movimientoPiezaValido(const tablero &t, coordenada c, coordenada d);
bool movimientoValidoPeon(jugador j, coordenada c, coordenada d);
bool movimientoValidoAlfil(const tablero &t, coordenada c, coordenada d);
bool noHayBloqueoAlfil(const tablero &t, casilla c, casilla d);
bool movimientoValidoTorre(const tablero &t, coordenada c, coordenada d);
bool movimientoValidoRey(coordenada c, coordenada d);
bool capturaPeonValida(const tablero &t, coordenada c, coordenada d);
casilla casillaEn(const tablero &t, coordenada c);

#endif //AJEDREZLITE_AUXILIARES_H
