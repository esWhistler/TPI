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

tablero inicializarTablero() {
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

jugador contrincante(jugador j) {
    return (j == 1 ? 2 : 1);
}


bool esJugadorValido(jugador j) {
    return j == NEGRO || j == BLANCO;
}

bool esTableroValido(const tablero &t) {
    return esMatriz8(t) && casillasValidas(t) && sinPeonesNoCoronados(t) && cantidadValidaDePiezas(t);
}

bool esMatriz8(const tablero &t) {
    int n = t.size();
    bool res = n == ANCHO_TABLERO;
    for (int i = 0; i < ANCHO_TABLERO && res; ++i) {
        res &= (t[i].size() == ANCHO_TABLERO);
    }
    return res;
}

bool casillasValidas(const tablero &t) {
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

bool esCasillaVacia(casilla c) {
    return c == cVACIA;
}

bool esPiezaValida(pieza p) {
    return PEON <= p && p <= REY;
}

pieza piezaEn(const tablero &t, coordenada c) {
    return t[c.first][c.second].first;
}

jugador jugadorEn(const tablero &t, coordenada c) {
    return t[c.first][c.second].second;
}

bool sinPeonesNoCoronados(const tablero &t) {
    bool res = true;
    for (int i = 0; i < ANCHO_TABLERO && res; ++i) {
        res &= piezaEn(t, setCoord(0, i)) != PEON;
    }
    for (int i = 0; i < ANCHO_TABLERO && res; ++i) {
        res &= piezaEn(t, setCoord(7, i)) != PEON;
    }
    return res;
}

bool cantidadValidaDePiezas(const tablero &t) {
    return cantidadPeonesValidos(t) && cantidadReyesValidos(t) && cantidadAlfilesValidos(t) && cantidadTorresValidas(t);
}

bool cantidadPeonesValidos(const tablero &t) {
    return aparicionesEnTablero(t, cPEON_B) <= ANCHO_TABLERO &&
    aparicionesEnTablero(t, cPEON_N) <= ANCHO_TABLERO;
}

bool cantidadReyesValidos(const tablero &t) {
    return aparicionesEnTablero(t, cREY_B) == 1 && aparicionesEnTablero(t, cREY_N) == 1;
}

bool cantidadAlfilesValidos(const tablero &t) {
    return aparicionesEnTablero(t, cALFIL_B) <= 2 && aparicionesEnTablero(t, cALFIL_N) <= 2;
}

bool cantidadTorresValidas(const tablero &t) {
    return aparicionesEnTablero(t, cTORRE_B) <= 2 + (ANCHO_TABLERO - aparicionesEnTablero(t, cPEON_B)) &&
    aparicionesEnTablero(t, cTORRE_N) <= 2 + (ANCHO_TABLERO - aparicionesEnTablero(t, cPEON_N));
}

int aparicionesEnTablero(const tablero &t, casilla p) {
    int apariciones = 0;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int j = 0; j < ANCHO_TABLERO; ++j) {
            if(t[i][j] == p) apariciones++;
        }
    }
    return apariciones;
}

tablero tableroInicial() {
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

bool casillaAtacada(coordenada c, const tablero &t, jugador j) {
    bool estaAtacada = false;
    for (int i = 0; i < ANCHO_TABLERO && !estaAtacada; ++i) {
        for (int k = 0; k < ANCHO_TABLERO && !estaAtacada; ++k) {
            coordenada target = setCoord(i, k);
            if((target != c) && (jugadorEn(t, target) == j)){
                estaAtacada |= ataca(t, target, c); //(4,5) (3, 4)
            }
        }
    }
    return estaAtacada;
}

bool ataca(const tablero &t, coordenada c, coordenada d) {
    return (c != cVACIA) &&
           ((piezaEn(t, c) != PEON && movimientoPiezaValido(t, c, d)) ||
            (piezaEn(t, c) == PEON && capturaPeonValida(t, c, d)));
}

bool movimientoPiezaValido(const tablero &t, coordenada c, coordenada d) {
    return  (piezaEn(t, c) == PEON && movimientoValidoPeon(jugadorEn(t, c), c, d)) ||
            (piezaEn(t, c) == ALFIL && movimientoValidoAlfil(t, c, d)) ||
            (piezaEn(t, c) == TORRE && movimientoValidoTorre(t, c, d)) ||
            (piezaEn(t, c) == REY && movimientoValidoRey(c, d));
}

bool movimientoValidoPeon(jugador j, coordenada c, coordenada d) {
    return (c.second == d.second) &&
           ((j == BLANCO && c.first == d.first + 1) ||
            (j == NEGRO && c.first == d.first - 1));
}

bool movimientoValidoAlfil(const tablero &t, coordenada c, coordenada d) {
    return abs(c.first - d.first) == abs(c.second - d.second) && !hayBloqueoAlfil(t, c, d);
}

bool hayBloqueoAlfil(const tablero &t, coordenada c, coordenada d) {
    bool hayBloqueo = false;

    int desdei = c.first;
    int desdej = c.second;

    int hastai = d.first;
    int hastaj = d.second;

    int modi = (desdei - hastai > 0 ? -1 : +1);
    int modj = (desdej - hastaj > 0 ? -1 : +1);

    desdei += modi;
    desdej += modj;

    while(desdei != hastai && !hayBloqueo) {
        hayBloqueo |= t[desdei][desdej] != cVACIA;
        desdei += modi;
        desdej += modj;
    }

    return hayBloqueo;
}

bool movimientoValidoTorre(const tablero &t, coordenada c, coordenada d) {
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

bool movimientoValidoRey(coordenada c, coordenada d) {
    int a = c.first;
    int b = c.second;

    int j = d.first;
    int k = d.second;

    return (abs(a - j) == 0 && abs(b - k) == 1) || (abs(a - j) == 1 && abs(b - k) == 1) || (abs(a - j) == 1 && abs(b - k) == 0);
}

bool capturaPeonValida(const tablero &t, coordenada c, coordenada d) {
    return abs(c.second - d.second) == 1 && //(4,5) (3, 4)
        ((jugadorEn(t, c) == BLANCO && c.first == d.first + 1) ||
        (jugadorEn(t, c) == NEGRO && c.first == d.first - 1));
}

casilla casillaEn(const tablero &t, coordenada c) {
    return t[c.first][c.second];
}

bool jugadaValida(const tablero &t1, const tablero &t2, coordenada o, coordenada d) {
    pieza piezaMovida = piezaEn(t1, o);
    pieza piezaDestino = piezaEn(t2, d);

    return (piezaMovida == piezaDestino && movimientoPiezaValido(t1, o, d)) ||
    (piezaMovida == PEON && piezaDestino == TORRE && esMovDePeonCoronado(t1, o, d));
}

bool esMovDePeonCoronado(const tablero &t, coordenada o, coordenada d) {
    return ((jugadorEn(t, o) == BLANCO && o.first == 1 && d.first == 0) ||
            (jugadorEn(t, o) == NEGRO && o.first == 6 && d.first == 7)) &&
            (movimientoValidoPeon(jugadorEn(t, o), o, d) || capturaPeonValida(t, o, d));
}

bool capturaValida(const tablero &t, coordenada c, coordenada d) {
    return (contrincante(piezaEn(t, c)) == piezaEn(t, d)) &&
        ((piezaEn(t, c) != PEON && movimientoPiezaValido(t, c, d)) ||
        (piezaEn(t, c) == PEON && capturaPeonValida(t, c, d)));
}

bool hayJaque(const posicion &p) {
    tablero const &t = p.first;
    coordenada coordDelRey = coordenadaDelReyDeTurno(p);
    bool res = false;
    for (int i = 0; i < ANCHO_TABLERO && !res; ++i) {
        for (int j = 0; j < ANCHO_TABLERO && !res; ++j) {
            coordenada potencialAtacante = setCoord(i, j);
            res &= capturaValida(t, potencialAtacante, coordDelRey);
        }
    }
    return res;
}

/*bool hayJaqueMate(const posicion &p) {
    return hayJaque(p) && !reyPuedeMoverse(p) && !esJaqueMultiple(p)
    // esJaqueMultiple existe porque si mas de una pieza da jaque a la vez nunca se puede bloquear o comer ambas, asi que habria que mover el rey, pero ya vimos que no es posible
    && !sePuedeBloquear(p) && !sePuedeComer(p);
}*/

bool reyPuedeMoverse(const posicion &p) {
    vector<coordenada> movimientosDelRey = movimientosRey(p);
}

vector<coordenada> movimientosRey(const posicion &p) {
    vector<coordenada> movimientos;

    coordenada coordenadaRey = coordenadaDelReyDeTurno(p);
    int reyI = coordenadaRey.first;
    int reyJ = coordenadaRey.second;

    tablero const &t = p.first;
    jugador j = p.second;

    for (int i = reyI - 1; i <= reyI + 1; ++i) {
        for (int j = reyJ - 1; j <= reyJ + 1; ++j) {
            coordenada c = setCoord(i, j);
            if(coordenadaValida(c) && !estaAtacadaPorJ(t, c, contrincante(j)) && jugadorEn(t, c) != j) movimientos.push_back(c);
        }
    }
    return movimientos;
}

bool coordenadaValida(coordenada c) {
    return 0 <= c.first && c.first < ANCHO_TABLERO && 0 <= c.second && c.second < ANCHO_TABLERO;
}

bool estaAtacadaPorJ(const tablero &t, coordenada c, jugador j) {
    bool estaAtacada = false;

    for (int i = 0; i < ANCHO_TABLERO && !estaAtacada; ++i) {
        for (int k = 0; k < ANCHO_TABLERO && !estaAtacada; ++k) {
            coordenada potencialAtacante = setCoord(i, k);
            if(jugadorEn(t, potencialAtacante) == j){
                estaAtacada &= capturaValida(t, potencialAtacante, c);
            }
        }
    }

    return estaAtacada;
}

/*bool sePuedeBloquear(const posicion &p) {
    coordenada coordRey = coordenadaDelReyDeTurno(p);
    vector<casilla> casillasEntreAtacanteYRey = casillasEntre(coordRey, coordDelAtacanteDe(p, coordRey));
    int cantCasillasEntre = casillasEntreAtacanteYRey.size();
    tablero const &t = p.first;
    jugador j = p.second;

    bool res = false;

    for (int i = 0; i < cantCasillasEntre && !res; ++i) {
        res |= estaAtacadaPorJ(t, casillasEntreAtacanteYRey[i], j);
    }

    return res;
}*/

coordenada coordenadaDelReyDeTurno(const posicion &p) {
    coordenada coordRey;
    tablero const &t = p.first;
    jugador const &j = p.second;
    bool encontreLaCoordenada = false;
    for (int i = 0; i < ANCHO_TABLERO && !encontreLaCoordenada; ++i) {
        for (int j = 0; j < ANCHO_TABLERO && !encontreLaCoordenada; ++j) {
            if((t[i][j] == cREY_N && j == 2) || (t[i][j] == cREY_B && j == 1)) {
                coordRey = setCoord(i, j);
                encontreLaCoordenada = true;
            }
        }
    }
    return coordRey;
}

secuencia movimientosDelJugador(const posicion &p, jugador j) {

}