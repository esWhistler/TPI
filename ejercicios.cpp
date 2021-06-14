#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( posicion const &p ) {
    return esJugadorValido(p.second) && esTableroValido(p.first);
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    //assert(posicionValida(p));
    tablero tabInicial = tableroInicial();
    posicion posInicial = make_pair(tabInicial, BLANCO);
    return posInicial == p;
}
// EJERCICIO 3
// a revisar si hay tiempo
vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    tablero tablero = p.first;
    vector<coordenada> cA;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int k = 0; k < ANCHO_TABLERO; ++k) {
            if(casillaAtacada(setCoord(i, k), tablero, j)){
                cA.push_back(setCoord(i, k));
            }
        }
    }
    return cA;
}


// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    jugador j1 = p1.second;
    jugador j2 = p2.second;

    tablero t1 = p1.first;
    tablero t2 = p2.first;

    bool resp = j1 != j2;

    for (int i = 0; i < ANCHO_TABLERO && resp; ++i) {
        for (int j = 0; j < ANCHO_TABLERO && resp; ++j) {
            coordenada coord = setCoord(i, j);
            if(coord != o && coord != d){
                resp &= casillaEn(t1, coord) == casillaEn(t2, coord);
            }
        }
    }

    resp &= jugadorEn(t1, o) == j1;
    resp &= jugadorEn(t1, d) != j1;
    resp &= casillaEn(t2, o) == cVACIA;
    resp &= jugadorEn(t2, d) == j1;
    resp &= jugadaValida(t1, t2, o, d);

    return resp;
}
// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    tablero &t = p.first;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        vector<casilla> piezasEnFila;
        for (int j = 0; j < ANCHO_TABLERO; ++j) {
            if(t[i][j] != cVACIA){
                piezasEnFila.push_back(t[i][j]);
            }
        }
        ordenarVector(piezasEnFila);
        modificarFilaPor(t, i, piezasEnFila);
    }
    return;
}

// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool resp = false;
    // completar codigo
    return resp;
}
// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    bool resp = false;
    // completar codigo
    return resp;
}
// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    // completar codigo
    return;
}
// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int resp = -1;
    // completar codigo
    return resp;
}
