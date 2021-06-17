#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(finDeLaPartidaTEST, partidaNoFinalizada) { // Tablero inicial
	tablero t = {
            {cTORRE_N,  cVACIA,     cALFIL_N,   cVACIA,     cREY_N,     cALFIL_N,   cVACIA,     cTORRE_N},
            {cPEON_N,   cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N,    cPEON_N},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cVACIA,    cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA,     cVACIA},
            {cPEON_B,   cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B,    cPEON_B},
            {cTORRE_B,  cVACIA,     cALFIL_B,   cVACIA,     cREY_B,     cALFIL_B,   cVACIA,     cTORRE_B},
    };
    posicion p = make_pair(t, BLANCO);
    int j = -1;

    EXPECT_FALSE(finDeLaPartida(p,j));
}

TEST(finDeLaPartidaTEST, jaqueMate) { // Figura 4a del enunciado del TPE
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_TRUE(finDeLaPartida(p,j));
    EXPECT_EQ(j, BLANCO);
}

TEST(finDeLaPartidaTEST, soloReyes) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_TRUE(finDeLaPartida(p,j));
    EXPECT_EQ(j, VACIO);
}

TEST(finDeLaPartidaTEST, reyAhogado) { // Rey ahogado por torre blanca en (5, 6)
    tablero t = {
            {cVACIA, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cPEON_N, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cPEON_N},
            {cVACIA, cTORRE_B, cPEON_N, cALFIL_B, cVACIA, cPEON_N, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_TRUE(finDeLaPartida(p,j));
    EXPECT_EQ(j, VACIO);
}

TEST(finDeLaPartidaTEST, jaqueMultiple) { // Jaque múltiple por torre blanca en (0, 4) y alfil blanco en (5, 2)
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_TRUE(finDeLaPartida(p,j));
    EXPECT_EQ(j, BLANCO);
}

TEST(finDeLaPartidaTEST, jaqueSePuedeBloquear) { // Jaque de torre blanca en (0, 4) puede bloquearse por alfil negro en (4, 2)
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_N, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_FALSE(finDeLaPartida(p,j));
}

TEST(finDeLaPartidaTEST, jaqueMultipleSePuedeComer) { // Jaque múltiple por torre blanca en (5, 5) y peón blanco en (1, 6). Rey puede comer peón.
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N, cREY_N, cVACIA, cTORRE_N},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cPEON_B, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_FALSE(finDeLaPartida(p,j));
}

TEST(finDeLaPartidaTEST, jaqueMultipleNoSePuedeComer) { // Jaque múltiple por torre blanca en (5, 5) y peón blanco en (1, 6). Rey no puede comer peón.
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N, cREY_N, cVACIA, cTORRE_N},
            {cPEON_N, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cPEON_B, cPEON_N},
            {cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cTORRE_B, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_TRUE(finDeLaPartida(p,j));
    EXPECT_EQ(j, BLANCO);
}

TEST(finDeLaPartidaTEST, jaqueSePuedeComer) { // Jaque por torre blanca en (4, 5), alfil puede comer.
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_N, cREY_N, cVACIA, cTORRE_N},
            {cVACIA, cVACIA, cALFIL_N, cPEON_N, cPEON_N, cVACIA, cPEON_N, cPEON_N},
            {cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_FALSE(finDeLaPartida(p,j));
}

TEST(finDeLaPartidaTEST, jaqueSePuedeBloquearPorPeon) { // Jaque por alfil blanco en (6, 2), peón puede bloquear.
    tablero t = {
            {cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cREY_N},
            {cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_N, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_FALSE(finDeLaPartida(p,j));
}

TEST(finDeLaPartidaTEST, jaqueSePuedeComerPorPeon) { // Jaque por alfil blanco en (6, 2), peón puede comer.
    tablero t = {
            {cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cVACIA, cVACIA, cALFIL_N, cREY_N},
            {cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cPEON_N, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cALFIL_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_FALSE(finDeLaPartida(p,j));
}

TEST(finDeLaPartidaTEST, jaqueMatePiezaPineada) { // Jaque mate por torre blanca en (7, 7), no puede bloquearse por pin.
    tablero t = {
            {cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cALFIL_N, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cTORRE_N, cVACIA, cTORRE_N, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t, NEGRO);
    int j = -1;

    EXPECT_TRUE(finDeLaPartida(p,j));
    EXPECT_EQ(j, BLANCO);
}