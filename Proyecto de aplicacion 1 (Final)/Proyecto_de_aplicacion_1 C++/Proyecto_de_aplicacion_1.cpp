#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <sstream>
#include "CD.h"
#include "PlayList.h"


using namespace std;




const int MAXCDCOUNT = 100;
const int MAXSONGCOUNT = 100;

class CD;

void cargarRespaldos(CD listaCDs[], int& cdCount) {
    cdCount = 0;

    string rutaCarpeta;
    cout << "Ingrese la ruta de la carpeta con los respaldos: ";
    getline(cin, rutaCarpeta);

    for (const auto& archivo : filesystem::directory_iterator(rutaCarpeta)) {
        if (archivo.is_regular_file() && archivo.path().extension() == ".txt") {
            ifstream file(archivo.path());
            if (file.is_open()) {
                CD cd;
                cd.setName(archivo.path().stem().string());

                string linea;
                while (getline(file, linea)) {
                    if (linea.empty()) {
                        cerr << "Error en archivo " << archivo.path().filename() << ": Archivo vacio." << endl;
                        file.close();
                        return;
                    }

                    stringstream ss(linea);
                    string nombre, artista, duracionStr;

                    getline(ss, nombre, '|');
                    getline(ss, artista, '|');
                    getline(ss, duracionStr, '|');

                    try {
                        int duracion = stoi(duracionStr);

                        Song nuevaCancion{ nombre, artista, duracion };
                        cd.addSong(nuevaCancion);
                    }
                    catch (const std::invalid_argument& e) {
                        cerr << "Error en archivo " << archivo.path().filename() << ": Formato de linea incorrecto." << endl;
                        file.close();
                        return;
                    }
                }

                listaCDs[cdCount++] = cd;

                file.close();
            }
            else {
                cerr << "Error al abrir archivo " << archivo.path().filename() << endl;
            }
        }
    }

    cout << "Respaldos cargados exitosamente." << endl;
}

int main() {

    CD listaCDs[MAXCDCOUNT];
    int cdCount = 0;

    PlayList playlist;
    CD miCD;


    int opcion;

    do {
        cout << "--- Menú de Reproductor de Musica ---";
        cout << "1. Cargar Respaldos";
        cout << "2. Agregar cancion desde CD";
        cout << "3. Ver cola de reproducción";
        cout << "4. Reproducir siguiente";
        cout << "5. Ver reproduccion actual";
        cout << "6. Salir";

        cout << "Ingrese el número de la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            void cargarRespaldos(CD listaCDs[], int& cdCount);
            break;
        case 2:
            if (cdCount > 0) {
                playlist.agregarCancionDesdeCD(listaCDs[cdCount - 1]);
            }
            else {
                cerr << "No hay CDs cargados. Cargue al menos un CD antes de agregar canciones." << endl;
            }
            break;
        case 3:
            if (cdCount > 0) {
                playlist.verColaReproduccion();
            }
            else {
                cerr << "No hay CDs cargados. Cargue al menos un CD antes de agregar canciones." << endl;
            }            break;
        case 4:
            if (cdCount > 0) {
                playlist.reproducirSiguiente();
            }
            else {
                cerr << "No hay CDs cargados. Cargue al menos un CD antes de agregar canciones." << endl;
            }            break;
        case 5:
            if (cdCount > 0) {
                playlist.reproduccionActualdetallada();
            }
            break;
        case 6:
            cout << "Saliendo del programa. ¡Hasta luego!";
            break;
        default:
            cout << "Opción inválida. Intente nuevamente.";
        }

    } while (opcion != 6);



    cout << "¿Desea ordenar la cola permanentemente? (S/N): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 'S' || respuesta == 's') {
        cout << "Seleccione una opción de orden:" << endl
            << "1. Nombre del artista" << endl
            << "2. Nombre de la cancion" << endl
            << "3. Duracion" << endl;

        int opcion;
        cin >> opcion;

        bool ascendente;
        cout << "¿Orden ascendente? (1: Sí, 0: No): ";
        cin >> ascendente;

        switch (opcion) {
        case 1:
            playlist.ordenarColaPermanente("artista", ascendente);
            break;
        case 2:
            playlist.ordenarColaPermanente("cancion", ascendente);
            break;
        case 3:
            playlist.ordenarColaPermanente("duracion", ascendente);
            break;
        default:
            cerr << "Opción inválida." << endl;
            break;
        }
    }
    playlist.agregarCancionDesdeCD(listaCDs[0]);


    return 0;
}






//string nombrearchivo;
    //string nombrearchivo = "C:\\Users\\USUARIO\\Downloads\\Archivos de Prueba-20230930\\100 Greatest Hits of All Time.txt";
    //cout << "Ingresa el nombre de la ubicacion del archivo de forma exacta (utiliza el \\\\ para dividir cada carpeta)"<<endl;    
    //cin >> nombrearchivo;
    //ifstream archivoEntrada(nombrearchivo);
    //if (!archivoEntrada) {
    //    cerr << "No se pudo abrir el archivo: " << nombrearchivo << endl;
    //    return 1;
    //}
    //string linea;
    //while (getline(archivoEntrada, linea)) {
    //    cout << linea << endl;
    //}

    //archivoEntrada.close();