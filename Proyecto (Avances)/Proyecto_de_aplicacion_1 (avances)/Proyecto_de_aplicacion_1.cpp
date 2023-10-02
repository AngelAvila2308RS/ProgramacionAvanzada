#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

void Cargar_Espacios() {

}

void Reproductor_de_Canciones() {

}

void Agregar_Cancion() {

}

void Cola_de_reproduccion() {

}

void Reproduccion_Actual() {
    string programmar;

    if (programmar == "Reproducida") {
        cout << "Franchouchou" << "||Sakura minamoto" << "||4,25" << endl;
    }
    else {
        cout << "Reproduccion en pausa" << endl;
    }
}

void Reproducir_siguiente() {

}

void Ordenar() {

}

void Lectura() {
    ifstream archivo;
    string nombreArchivo, texto;

    cout << "Digite el nombre o la ubicacion del archivo o fichero: ";
    getline(cin, nombreArchivo);

    archivo.open(nombreArchivo.c_str(), ios::in);

    if (archivo.fail()) {
        cout << "No se puede abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        cout << texto << endl;
    }

    archivo.close();
    {

    }
}

int main()
{   
    string CD[1][1][8];

    CD[0][0][0] = "Date a Live Season 2";
    CD[0][0][1] = "Tohka";
    CD[0][0][2] = "4,41";

    CD[0][0][3] = "Ultimate Battle Theme";
    CD[0][0][4] = "Dragon ball";
    CD[0][0][5] = "4,01";

    CD[0][0][6] = "Hikari Are";
    CD[0][0][7] = "Elizabeth";
    CD[0][0][8] = "3,45";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0;j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                std::cout << CD[i][j][k] << endl;
                cout << endl;
            }
        }
    }

    Lectura();

    return 0;
}