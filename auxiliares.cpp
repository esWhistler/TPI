#include "definiciones.h"
#include "auxiliares.h"

using namespace std;


//Auxiliares y predicados generales

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

jugador contrincante(jugador j) {
    return (j == VACIO ? VACIO : (j == BLANCO ? NEGRO : BLANCO));
}

pieza piezaEn(const tablero &t, coordenada c) {
    return t[c.first][c.second].first;
}

jugador jugadorEn(const tablero &t, coordenada c) {
    return t[c.first][c.second].second;
}

casilla casillaEn(const tablero &t, coordenada c) {
    return t[c.first][c.second];
}

void setCasilla(tablero &t, coordenada c, casilla x) {
    t[c.first][c.second] = x;
}


//Ej1

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

bool esJugadorValido(jugador j) {
    return j == NEGRO || j == BLANCO;
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


//Ej2

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


//Ej3

//j es el atacante
bool casillaAtacada(const tablero &t, coordenada c, jugador j) {
    bool estaAtacada = false;
    for (int i = 0; i < ANCHO_TABLERO && !estaAtacada; ++i) {
        for (int k = 0; k < ANCHO_TABLERO && !estaAtacada; ++k) {
            coordenada target = setCoord(i, k);
            if((target != c) && (jugadorEn(t, target) == j)){
                estaAtacada |= capturaPiezaValida(t, target, c);
            }
        }
    }
    return estaAtacada;
}

bool capturaPiezaValida(const tablero &t, coordenada c, coordenada d) {
    return c != d &&
           ((piezaEn(t, c) != PEON && movimientoPiezaValido(t, c, d)) ||
           (piezaEn(t, c) == PEON && capturaPeonValida(t, c, d)));
}

bool movimientoPiezaValido(const tablero &t, coordenada c, coordenada d) {
    return  c != d &&
            ((piezaEn(t, c) == PEON && movimientoValidoPeon(jugadorEn(t, c), c, d)) ||
            (piezaEn(t, c) == ALFIL && movimientoValidoAlfil(t, c, d)) ||
            (piezaEn(t, c) == TORRE && movimientoValidoTorre(t, c, d)) ||
            (piezaEn(t, c) == REY && movimientoValidoRey(c, d)));
}

bool movimientoValidoPeon(jugador j, coordenada c, coordenada d) {
    return (c.second == d.second) &&
           ((j == BLANCO && c.first == d.first + 1) ||
           (j == NEGRO && c.first == d.first - 1));
}

bool movimientoValidoAlfil(const tablero &t, coordenada c, coordenada d) {
    return c != d && abs(c.first - d.first) == abs(c.second - d.second) && !hayBloqueoAlfil(t, c, d);
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
        coordenada e = setCoord(desdei, desdej);
        hayBloqueo |= casillaEn(t, e) != cVACIA;
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


//Ej4

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

//Ej6

// Revisa si el jugador de turno está en jaque.
bool hayJaque(const posicion &p) {
    const tablero &t = p.first;
    jugador j = p.second;
    coordenada coordDelRey = coordenadaDelRey(p, p.second);
    bool res = false;
    for (int i = 0; i < ANCHO_TABLERO && !res; ++i) {
        for (int k = 0; k < ANCHO_TABLERO && !res; ++k) {
            coordenada potencialAtacante = setCoord(i, k);
            res |= (jugadorEn(t, potencialAtacante) == contrincante(j)) && capturaPiezaValida(t, potencialAtacante, coordDelRey);
        }
    }
    return res;
}

bool hayJaqueMate(const posicion &p) {
    const tablero &t = p.first;
    jugador j = p.second;
    return hayJaque(p) && jugadasDelJugador(t, j).empty();
}

// cuantas veces j ataca c
int cantidadAtacantes(const tablero &t, coordenada d, jugador j) {
    int atacantes = 0;

    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int k = 0; k < ANCHO_TABLERO; ++k) {
            coordenada c = setCoord(i, k);
            if(jugadorEn(t, c) == j && capturaPiezaValida(t, c, d)) atacantes++;
        }
    }

    return atacantes;
}

coordenada coordenadaDelRey(const posicion &p, jugador j) {
    coordenada coordRey;

    const tablero &t = p.first;

    bool encontreLaCoordenada = false;
    for (int i = 0; i < ANCHO_TABLERO && !encontreLaCoordenada; ++i) {
        for (int k = 0; k < ANCHO_TABLERO && !encontreLaCoordenada; ++k) {
            coordenada c = setCoord(i, k);
            if((casillaEn(t, c) == cREY_N && j == NEGRO) || (casillaEn(t, c) == cREY_B && j == BLANCO)) {
                coordRey = c;
                encontreLaCoordenada = true;
            }
        }
    }

    return coordRey;
}

coordenada coordDelAtacanteDe(const posicion &p, coordenada c) {
    coordenada resultado = setCoord(-1, -1);
    const tablero &t = p.first;
    for (int i = 0; i < ANCHO_TABLERO && resultado == setCoord(-1, -1); ++i) {
        for (int k = 0; k < ANCHO_TABLERO && resultado == setCoord(-1, -1); ++k) {
            coordenada potencialAtacante = setCoord(i, k);
            if(jugadorEn(t, potencialAtacante) == contrincante(jugadorEn(t, c)) && capturaPiezaValida(t, potencialAtacante, c)) {
                resultado = potencialAtacante;
            }
        }
    }

    return resultado;
}

bool empate(const posicion &p){
    return soloReyes(p) || ahogado(p);
}

bool soloReyes(const posicion &p) {
    const tablero &t = p.first;
    bool empataron = true;

    for (int i = 0; i < ANCHO_TABLERO && empataron; ++i) {
        for (int k = 0; k < ANCHO_TABLERO && empataron; ++k) {
            coordenada c = setCoord(i, k);
            if(casillaEn(t, c) != cVACIA && piezaEn(t, c) != REY) empataron = false;
        }
    }

    return empataron;
}

bool ahogado(const posicion &p) {
    const tablero &t = p.first;
    jugador j = p.second;
    return jugadasDelJugador(t, j).empty() && !hayJaque(p);
}

vector< pair<pieza, coordenada> > piezasDelJugador(const tablero &t, jugador j) {
    vector< pair<pieza, coordenada> > piezas;

    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int k = 0; k < ANCHO_TABLERO; ++k) {
            coordenada c = setCoord(i, k);
            if (jugadorEn(t, c) == j) {
                piezas.emplace_back(piezaEn(t, c), c);
            }
        }
    }

    return piezas;
}

secuencia jugadasDelJugador(const tablero &t, jugador j) {
    secuencia jugadas;

    auto piezas = piezasDelJugador(t, j);

    for (auto pieza : piezas) {
        coordenada c = pieza.second;
        secuencia jugadasPieza = jugadasDeLaPiezaEn(t, c);
        jugadas.insert(jugadas.end(), jugadasPieza.begin(), jugadasPieza.end());
    }

    return jugadas;
}

secuencia jugadasDeLaPiezaEn(const tablero &t, coordenada c) {
    secuencia jugadas;
    jugador j = jugadorEn(t, c);

    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int k = 0; k < ANCHO_TABLERO; ++k) {
            coordenada d = setCoord(i, k);
            if (esJugadaLegal(t, c, d)) {
                jugadas.emplace_back(c, d);
            }
        }
    }

    return jugadas;
}

bool esJugadaLegal(const tablero &t, coordenada c, coordenada d) {
    bool movimientoValido = movimientoPiezaValido(t, c, d) && casillaEn(t, d) == cVACIA;
    bool capturaValida = capturaPiezaValida(t, c, d) && jugadorEn(t, d) == contrincante(jugadorEn(t, c));
    return (movimientoValido || capturaValida) && !movimientoMeDejaEnJaque(t, c, d);
}

bool movimientoMeDejaEnJaque(const tablero &t, coordenada c, coordenada d) {
    jugador j = jugadorEn(t, c);
    posicion p = make_pair(t, j);
    posicion pSiguiente = ejecutarMovimiento(p, c, d);
    pSiguiente.second = j; // Cambiamos el jugador de turno para que hayJaque revise por j.
    return hayJaque(pSiguiente);
}

posicion ejecutarMovimiento(const posicion &p, coordenada c, coordenada d) {
    const tablero &t1 = p.first;
    jugador j = p.second;

    posicion pSiguiente = make_pair(t1, contrincante(j));
    tablero &t2 = pSiguiente.first;

    if (piezaEn(t2, c) == PEON && d.first == 0) {
        setCasilla(t2, d, cTORRE_B);
    } else if (piezaEn(t2, c) == PEON && d.first == 7) {
        setCasilla(t2, d, cTORRE_N);
    } else {
        setCasilla(t2, d, casillaEn(t2, c));
    }
    setCasilla(t2, c, cVACIA);

    return pSiguiente;
}


//Ej7

bool piezaMovidaNoDioJaque(coordenada piezaMovida, const posicion &p) {
    return coordDelAtacanteDe(p, coordenadaDelRey(p, p.second)) != piezaMovida;
}


//Ej9

bool hayMovimientosQueImplicanMate(const posicion &p) {
    secuencia listaMovimientos = jugadasDelJugador(p.first, p.second);
    bool encontreMate = false;
    for (int i = 0; i < listaMovimientos.size() && !encontreMate; ++i){
        posicion q = ejecutarMovimiento(p, listaMovimientos[i].first, listaMovimientos[i].second);
        if(hayJaqueMate(q)) encontreMate = true;
    }
    return encontreMate;
}

vector<pair<coordenada, coordenada>> listaMovimientosForzantes(const posicion &p) {
    vector<pair<coordenada, coordenada>> movimientosForzantes;
    jugador j = p.second;

    auto piezas = piezasDelJugador(p.first, j);
    for (auto & pieza : piezas) {

        coordenada desde = pieza.second;

        secuencia jugadasPermitidas = jugadasDeLaPiezaEn(p.first, desde);
        int n_jugadasPermitidas = jugadasPermitidas.size();

        for(int m = 0; m < n_jugadasPermitidas; m++){// m es el par coordenada coordenada que describe una jugada, la first es desde donde y la second es hasta donde{
            coordenada hasta = jugadasPermitidas[m].second;
            posicion posSig = ejecutarMovimiento(p, desde, hasta);
            if(cantidadJugadasLegales(posSig) == 1)
                movimientosForzantes.emplace_back(desde, hasta);
        }
    }
    return movimientosForzantes;
}

int cantidadJugadasLegales(const posicion &p) {
    return jugadasDelJugador(p.first, p.second).size();
}


