#pragma once
#include <iostream>
#include "CD.h"
#include <string>
#include <algorithm>
#include <queue>

class CD;

class PlayList
{
public:
    void agregarCancion(const Song& song);
    void verColaReproduccion();
    void reproduccionActualdetallada() const;
    void reproducirSiguiente();
    void ordenarColaReproduccion(const string& opcionOrden, bool ascendente);
    void agregarCancionDesdeCD(const CD& cd);
    void ordenarColaPermanente(const string& opcionOrden, bool ascendente);


private:
    static const int MAXSONGCOUNT = 100;

    int colaReproduccionSize;
    Song colaReproduccion[MAXSONGCOUNT];
    Song reproduccionActual;
    queue<Song> colaReproduccion;
    static bool comparadorDuracion(const Song& a, const Song& b);
};

