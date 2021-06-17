#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( posicion const &p ) {
    return esJugadorValido(p.second) && esTableroValido(p.first);
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    tablero tabInicial = tableroInicial();
    posicion posInicial = make_pair(tabInicial, BLANCO);
    return posInicial == p;
}

// EJERCICIO 3
vector <coordenada> casillasAtacadas ( posicion const &p, int j ) {
    tablero tablero = p.first;
    vector<coordenada> cA;
    for (int i = 0; i < ANCHO_TABLERO; ++i) {
        for (int k = 0; k < ANCHO_TABLERO; ++k) {
            coordenada c = setCoord(i, k);
            if(casillaAtacada(c, tablero, j)){
                cA.push_back(c);
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
    int n = t.size();
    for (int fila = 0; fila < ANCHO_TABLERO; ++fila) {
        for (int i = 0; i < n - 1; ++i) {
            int min_pos = i;
            for (int j = i + 1; j < n; ++j) {
                if(t[fila][j].first < t[fila][min_pos].first && t[fila][j] != cVACIA) min_pos = j;
            }
            swap(t[fila][min_pos], t[fila][i]);
        }
    }
}

// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool fin = false;
    if(hayJaqueMate(p)){
        j = contrincante(p.second);
        fin = true;
    }else if(ahogado(p)){
        j = 0;
        fin = true;
    }
    return fin;
}

// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
    secuencia listaMovimientos = movimientosDelJugador(p, p.second);
    bool hayDescubierto = false;

    for (int i = 0; i < listaMovimientos.size() && !hayDescubierto; ++i) {
        posicion siguiente = ejecutarMovimiento(p, listaMovimientos[i].first, listaMovimientos[i].second);
        if(hayJaque(siguiente)){
            hayDescubierto |= cantidadAtacantes(siguiente, coordenadaDelReyDeTurno(siguiente), p.second) > 1;
            hayDescubierto |= piezaMovidaNoDioJaque(listaMovimientos[i].second, siguiente);
        }
    }

    return hayDescubierto;
}

// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    for (int i = 0; i < s.size(); ++i) {
        p = ejecutarMovimiento(p, s[i].first, s[i].second);
        secuencia listaMovimientos = movimientosDelJugador(p, p.second);
        coordenada forzadoDe = listaMovimientos[0].first;
        coordenada forzadoHasta = listaMovimientos[0].second;
        p = ejecutarMovimiento(p, forzadoDe, forzadoHasta);
    }
}

// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int resp = -1;
    // completar codigo
    return resp;
}
