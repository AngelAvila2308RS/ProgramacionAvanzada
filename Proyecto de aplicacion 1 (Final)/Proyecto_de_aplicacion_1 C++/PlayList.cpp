#include "PlayList.h"
#include <iostream>
#include <algorithm>
#include <queue>




void PlayList::agregarCancion(const Song& song) {
    if (colaReproduccionSize < MAXSONGCOUNT) {
        colaReproduccion.push(song);
        cout << "Cancion agregada a la cola de reproduccion." << endl;
        colaReproduccionSize++;
    }
    else {
        cerr << "Error: La cola de reproduccion esta llena." << endl;
    }
}

void PlayList::agregarCancionDesdeCD(const CD& cd) {
    cout << "Seleccione un CD para agregar canciones:" << endl;

    for (int i = 0; i < cd.getSongCount(); ++i) {
        cout << i + 1 << ". " << cd.getSong(i).titulo << " - " << cd.getSong(i).artista << endl;
    }

    int indiceCancion;
    cout << "Seleccione una cancion para agregar a la cola de reproduccion (1-" << cd.getSongCount() << "): ";
    cin >> indiceCancion;

    if (indiceCancion >= 1 && indiceCancion <= cd.getSongCount()) {
        const Song& cancionElegida = cd.getSong(indiceCancion - 1);

        agregarCancion(cancionElegida);
        cout << "Cancion '" << cancionElegida.titulo << "' agregada a la cola de reproduccion." << endl;
    }
    else {
        cerr << "Opcion invalida. Seleccion incorrecta." << endl;
    }
}

void PlayList::verColaReproduccion() {
    cout << "¿Como desea ver la cola de reproduccion?" << endl;
    cout << "1. Tal como fue llenada" << endl
        << "2. Ordenada por nombre del artista" << endl
        << "3. Ordenada por nombre de la canción" << endl
        << "4. Ordenada por duracion de la canción" << endl
        << "Ingrese su opción: " << endl;

    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
        break;
    case 2:
        ordenarColaReproduccion("artista", true);
        break;
    case 3:
        ordenarColaReproduccion("cancion", true);
        break;
    case 4:
        ordenarColaReproduccion("duracion", true);
        break;
    default:
        cerr << "Opción inválida." << endl;
        break;
    }
}

void PlayList::reproduccionActualdetallada() const{
    if (reproduccionActual.titulo.empty()) {
        cout << "Reproducción en Pausa." << endl;
    }
    else {
        cout << "Reproducción Actual:"
            << "Nombre: " << reproduccionActual.titulo << "  "
            << "Artista: " << reproduccionActual.artista << "  "  
            << "Duracion: " << reproduccionActual.tiempo << " segundos  "
            << "Nombre del CD: " << reproduccionActual.cdName << endl;
    }
}

void PlayList::reproducirSiguiente() {
    if (colaReproduccionSize > 0) {
        
        colaReproduccion.push(reproduccionActual);
        reproduccionActual = colaReproduccion.front();
        colaReproduccion.pop();

        cout << "Reproduciendo siguiente:" << endl
            << "Nombre: " << reproduccionActual.titulo << "  " << endl
            << "Artista: " << reproduccionActual.artista << "  " << endl
            << "Duracion: " << reproduccionActual.tiempo << " segundos  " << endl
            << "Nombre del CD: " << reproduccionActual.cdName << endl;
    }
    else {
        cout << "La cola de reproduccion esta vacia." << endl;
    }
}

void PlayList::ordenarColaReproduccion(const string& opcionOrden, bool ascendente) {
    vector<Song> vectorAuxiliar;
    while (!colaReproduccion.empty()) {
        vectorAuxiliar.push_back(colaReproduccion.front());
        colaReproduccion.pop();
    }

    if (opcionOrden == "artista") {
        sort(vectorAuxiliar.begin(), vectorAuxiliar.end(),
            [ascendente](const Song& a, const Song& b) {
                return ascendente ? a.artista < b.artista : a.artista > b.artista;
            });
    }
    else if (opcionOrden == "cancion") {
        sort(vectorAuxiliar.begin(), vectorAuxiliar.end(),
            [ascendente](const Song& a, const Song& b) {
                return ascendente ? a.titulo < b.titulo : a.titulo > b.titulo;
            });
    }
    else if (opcionOrden == "duracion") {
        sort(vectorAuxiliar.begin(), vectorAuxiliar.end(), comparadorDuracion);
    }
    else {
        cerr << "Opcion de orden no valida." << endl;
        return;
    }

    for (const auto& song : vectorAuxiliar) {
        colaReproduccion.push(song);
    }
}

bool PlayList::comparadorDuracion(const Song& a, const Song& b) {
    return a.tiempo < b.tiempo;
}

void PlayList::ordenarColaPermanente(const string& opcionOrden, bool ascendente) {
    ordenarColaReproduccion(opcionOrden, ascendente);

    queue<Song> nuevaColaReproduccion;
    while (!colaReproduccion.empty()) {
        nuevaColaReproduccion.push(colaReproduccion.front());
        colaReproduccion.pop();
    }

    colaReproduccion = nuevaColaReproduccion;
}