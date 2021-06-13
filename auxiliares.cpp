#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}


bool esJugadorValido(jugador j){
    return j == NEGRO || j == BLANCO;
}

bool esTableroValido(tablero t){
    return esMatriz8(t) && casillasValidas(t) && sinPeonesNoCoronados(t) && cantidadValidaDePiezas(t);
}

bool esMatriz8(tablero t){
    int n = t.size();
    bool res = n == ANCHO_TABLERO;
    for (int i = 0; i < ANCHO_TABLERO && res; ++i) {
        res &= (t[i].size() == ANCHO_TABLERO);
    }
    return res;
}

bool casillasValidas(tablero t){
    int n = t.size();
    bool res = true;
    for (int i = 0; i < n && res; ++i) {
        for (int j = 0; j < n && res; ++j) {
            coordenada c = setCoord(i, j);
            res &= esCasillaVacia(t[i][j]) || (esPiezaValida(piezaEn(t, c))) && esJugadorValido(jugadorEn(t, c));
        }
    }
    return res;
}

bool esCasillaVacia(casilla c){
    return c == cVACIA;
}

bool esPiezaValida(pieza p){
    return PEON <= p && p <= REY;
}

pieza piezaEn(tablero t, coordenada c){
    return t[c.first][c.second].first;
}

jugador jugadorEn(tablero t, coordenada c){
    return t[c.first][c.second].second;
}

bool sinPeonesNoCoronados(tablero t){
    bool res = true;
    for (int i = 0; i < 8 && res; ++i) {
        res &= piezaEn(t, setCoord(0, i)) != PEON;
    }
    for (int i = 0; i < 8 && res; ++i) {
        res &= piezaEn(t, setCoord(7, i)) != PEON;
    }
    return res;
}

bool cantidadValidaDePiezas(tablero t){
    return cantidadPeonesValidos(t) && cantidadReyesValidos(t) && cantidadAlfilesValidos(t) && cantidadTorresValidas(t);
}

bool cantidadPeonesValidos(tablero t){
    return aparicionesEnTablero(t, cPEON_B) <= ANCHO_TABLERO &&
    aparicionesEnTablero(t, cPEON_N) <= ANCHO_TABLERO;
}

bool cantidadReyesValidos(tablero t){
    return aparicionesEnTablero(t, cREY_B) == 1 && aparicionesEnTablero(t, cREY_N) == 1;
}

bool cantidadAlfilesValidos(tablero t){
    return aparicionesEnTablero(t, cALFIL_B) <= 2 && aparicionesEnTablero(t, cALFIL_N) <= 2;
}

bool cantidadTorresValidas(tablero t){
    return aparicionesEnTablero(t, cTORRE_B) <= 2 + (ANCHO_TABLERO - aparicionesEnTablero(t, cPEON_B)) &&
    aparicionesEnTablero(t, cTORRE_N) <= 2 + (ANCHO_TABLERO - aparicionesEnTablero(t, cPEON_N));
}

int aparicionesEnTablero(tablero t, casilla p){
    int apariciones = 0;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int j = 0; j < ANCHO_TABLERO; ++j) {
            if(t[i][j] == p) apariciones++;
        }
    }
    return apariciones;
}