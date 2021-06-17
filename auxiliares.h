//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;

//DEFINICIONES DE TIPO
typedef int jugador;
typedef int pieza;

// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual (const posicion &p );

//5.2.1. Auxiliares
int aparicionesEnTablero(const tablero &t, casilla p);
int colorPieza(const tablero &t, coordenada c);
jugador contrincante(jugador j);
int piezaEn(const tablero &t, coordenada c);
int jugadorEn(const tablero &t, coordenada c);
void setCasilla(tablero &t, coordenada c, casilla x);

//Ej1
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

//Ej2
tablero tableroInicial();

//Ej3
bool casillaAtacada(const tablero &t, coordenada c, jugador j);
bool capturaPiezaValida(const tablero &t, casilla c, casilla d);
bool movimientoPiezaValido(const tablero &t, coordenada c, coordenada d);
bool movimientoValidoPeon(jugador j, coordenada c, coordenada d);
bool movimientoValidoAlfil(const tablero &t, coordenada c, coordenada d);
bool hayBloqueoAlfil(const tablero &t, casilla c, casilla d);
bool movimientoValidoTorre(const tablero &t, coordenada c, coordenada d);
bool movimientoValidoRey(coordenada c, coordenada d);
bool capturaPeonValida(const tablero &t, coordenada c, coordenada d);
casilla casillaEn(const tablero &t, coordenada c);

//Ej4
bool jugadaValida(const tablero &t1, const tablero &t2, coordenada o, coordenada d);
bool esMovDePeonCoronado(const tablero &t, coordenada o, coordenada d);

//Ej6
bool hayJaque(const posicion &p);
bool hayJaqueMate(const posicion &p);
bool reyPuedeMoverse(const posicion &p);
vector<coordenada> movimientosRey(const posicion &p);
bool coordenadaValida(coordenada c);
bool esJaqueMultiple(const posicion &p);
int cantidadAtacantes(const tablero &t, coordenada c, jugador j);
bool sePuedeBloquear(const posicion &p);
bool sePuedeComer(const posicion &p);
vector<casilla> coordenadasEntre(coordenada c, coordenada d);
coordenada coordenadaDelReyDeTurno(const posicion &p);
coordenada coordDelAtacanteDe(const posicion &p, coordenada c);
bool empate(const posicion &p);
bool soloReyes(const posicion &p);
bool ahogado(const posicion &p);
secuencia movimientosDelJugador(const posicion &p, jugador j);
secuencia movimientosDeLaPiezaEn(const posicion &p, coordenada c);
posicion ejecutarMovimiento(const posicion &p, coordenada c, coordenada d);
bool movimientoMeDejaEnJaque(const posicion &p, coordenada c, coordenada d);

//Ej7
bool piezaMovidaNoDioJaque(coordenada piezaMovida, const posicion &p);

#endif //AJEDREZLITE_AUXILIARES_H
