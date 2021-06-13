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
    for (int i = 0; i < ANCHO_TABLERO && res; ++i) {
        res &= piezaEn(t, setCoord(0, i)) != PEON;
    }
    for (int i = 0; i < ANCHO_TABLERO && res; ++i) {
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

tablero tableroInicial(){
    return {
            {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
            {cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA, cALFIL_B, cVACIA, cREY_B, cALFIL_B, cVACIA, cTORRE_B},
    };
}

bool casillaAtacada(casilla c, tablero t, jugador j){
    bool estaAtacada = false;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int k = 0; k < ANCHO_TABLERO; ++k) {
            coordenada target = setCoord(i, k);
            if((target != c) && (jugadorEn(t, target) == j)){
                estaAtacada |= ataca(t, setCoord(i, k), c);
            }
        }
    }
    return estaAtacada;
}

bool ataca(tablero t, casilla c, casilla d){
    return (c != cVACIA) &&
           ((piezaEn(t, c) != PEON && movimientoPiezaValido(t, c, d)) ||
            (piezaEn(t, c) == PEON && capturaPeonValida(t, jugadorEn(t, c), c, d)));
}

bool movimientoPiezaValido(tablero t, coordenada c, coordenada d){
    return  (piezaEn(t, c) == PEON && movimientoValidoPeon(jugadorEn(t, c), c, d)) ||
            (piezaEn(t, c) == ALFIL && movimientoValidoAlfil(t, c, d)) ||
            (piezaEn(t, c) == TORRE && movimientoValidoTorre(t, c, d)) ||
            (piezaEn(t, c) == REY && movimientoValidoRey(c, d));
}

bool movimientoValidoPeon(jugador j, coordenada c, coordenada d) {
    return (c.first == d.first) &&
           ((j == BLANCO && c.first == d.first -1) ||
            (j == NEGRO && c.first == d.first + 1));
}

bool movimientoValidoAlfil(tablero t, coordenada c, coordenada d){
    return abs(c.first - d.first) == abs(c.second - d.second) && noHayBloqueoAlfil(t, c, d);
}

bool noHayBloqueoAlfil(tablero t, casilla c, casilla d){
    bool res = false;
    int i = min(c.first, d.first);
    int hastai = max(c.first, d.first);
    int j = min(c.second, d.second);
    int hastaj = max(c.second, d.second);

    while (i < hastai && !res) {
        res &= esCasillaVacia(casillaEn(t, setCoord(i, j)));
        i++;
        j++;
    }
    return res;
}

bool movimientoValidoTorre(tablero t, coordenada c, coordenada d){
    bool res = true;
    int desdeFila = c.first;
    int hastaFila = d.first;
    int desdeColumna = c.second;
    int hastaColumna = d.second;

    if(desdeFila == hastaFila){
        int mod = (desdeColumna < hastaColumna ? 1 : -1);
        for (int i = desdeColumna + mod; i != hastaColumna && res; i += mod) {
            if(piezaEn(t, setCoord(desdeFila, i)) != 0){
                res = false;
            }
        }
    } else if (desdeColumna == hastaColumna){
        int mod = (desdeFila < hastaFila ? 1 : -1);
        for (int i = desdeFila + mod; i != hastaFila && res; i += mod) {
            if(piezaEn(t, setCoord(i, desdeColumna)) != 0){
                res = false;
            }
        }
    } else {
        res = false;
    }

    return res;
}

bool movimientoValidoRey(coordenada c, coordenada d){
    int a = c.first;
    int b = c.second;

    int j = d.first;
    int k = d.second;

    return (abs(a - j) == 0 && abs(b - k) == 1) || (abs(a - j) == 1 && abs(b - k) == 1) || (abs(a - j) == 1 && abs(b - k) == 0);
}

bool capturaPeonValida(tablero t, jugador j, coordenada c, coordenada d){
    return (jugadorEn(t, c) == BLANCO && c.second == d.second - 1) || (jugadorEn(t, c) == NEGRO && c.second == d.second +1);
}

casilla casillaEn(tablero t, coordenada c){
    return t[c.first][c.second];
}