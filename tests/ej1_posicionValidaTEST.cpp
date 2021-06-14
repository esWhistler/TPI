#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;


TEST(posicionValidaTEST, tableroVacio) {
    tablero t = {{}};
    posicion p = make_pair(t,1);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, tableroSinPiezas) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,1);
    EXPECT_FALSE(posicionValida(p));
}

TEST(posicionValidaTEST, tableroSoloReyes) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,1);
    EXPECT_TRUE(posicionValida(p));
}

TEST(posicionValidaTEST, posicionInicial) {
    tablero t = {
            {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
            {cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA, cALFIL_B, cVACIA, cREY_B, cALFIL_B, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t,1);
    EXPECT_TRUE(posicionValida(p));
}

TEST(posicionValidaTEST, peonesConvertidos) {
    tablero t = {
            {cVACIA, cVACIA, cALFIL_N, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA},
            {cPEON_N, cREY_N, cPEON_N, cVACIA, cVACIA, cVACIA, cPEON_N, cPEON_N},
            {cTORRE_N, cPEON_N, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA},
            {cVACIA, cALFIL_N, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cPEON_B, cPEON_B, cVACIA, cALFIL_B, cALFIL_B, cVACIA, cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cREY_B, cVACIA},
    };
    posicion p = make_pair(t,1);
    EXPECT_TRUE(posicionValida(p));
}

TEST(posicionValidaTEST, torresDeSobra) {
    tablero t = {
            {cVACIA, cVACIA, cALFIL_N, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA},
            {cPEON_N, cREY_N, cPEON_N, cVACIA, cVACIA, cVACIA, cPEON_N, cPEON_N},
            {cTORRE_N, cPEON_N, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N, cVACIA},
            {cVACIA, cALFIL_N, cTORRE_B, cPEON_B, cVACIA, cVACIA, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA},
            {cPEON_B, cPEON_B, cVACIA, cALFIL_B, cALFIL_B, cVACIA, cPEON_B, cPEON_B},
            {cTORRE_B, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cREY_B, cVACIA},
    };
    posicion p = make_pair(t,1);
    EXPECT_FALSE(posicionValida(p));
}