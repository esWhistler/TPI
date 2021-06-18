#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(seVieneElJaqueEnTEST, hayMateEn2) {
    tablero t = { // tablero de ejercicio 17 del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn1) {
    tablero t = {
            {cTORRE_N, cVACIA, cALFIL_N, cVACIA, cREY_N, cALFIL_N, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cPEON_B, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cREY_B},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 1;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn3) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cPEON_N, cVACIA},
            {cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA},
            {cPEON_B, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 3;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn3_2) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_B, cVACIA},
            {cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 3;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn2_2) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cALFIL_B},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn2DemuchasManeras) { //después del primer mov cualquier manera que mueva la torre el jaque descubierto es mate
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cPEON_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA},
            {cPEON_B, cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}