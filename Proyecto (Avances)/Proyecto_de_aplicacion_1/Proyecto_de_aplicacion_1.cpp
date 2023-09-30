#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{    


    return 0;
}

void Lectura() {
    ifstream archivo;
    string texto;


    archivo.open("d:\\Users\\USUARIO\\Downloads\\Ejercicio lab progra avanzada.txt", ios::in);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof()) {
        getline(archivo, texto);
        cout << texto << endl;
    }

    archivo.close();
}