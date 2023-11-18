#include "ListaDoble.h"
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <iomanip>
#include <sstream>

using namespace std;


int main() {
    string fileName;
    string nombreArchivo;

    cout << "Bienvenido, con este programa se podra hacer la carga de diferentes archivos de texto" << endl;
    cout << "Ingrese el nombre del archivo: ";
    cin >> fileName;

    fileName = R"(C:\Users\USUARIO\Downloads\Listas\)" + fileName + ".txt";

    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    ListaDoble dataList;
    string line;

    while (getline(inputFile, line)) {
        dataList.addNode(line);
    }
    inputFile.close();


    //dataList.printList();

    //dataList.deleteList();

    cout << "Datos almacenados." << endl;
    cout << "------------------" << endl;
    cout << "------------------" << endl;
    cout << " " << endl;
    int opcion;

    do {
        cout << "Menu:" << endl;
        cout << "1) Cargar mas datos a memoria" << endl;
        cout << "2) Busqueda de datos por llave" << endl;
        cout << "3) Busqueda de datos por valor" << endl;
        cout << "4) Salir" << endl;

        cout << "Ingrese el numero de la opcion que desea: ";
        cin >> opcion;
        Node* resultado = dataList.buscarPorLlave(nombreArchivo);


        switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del archivo a cargar: ";
            cin >> fileName;
            fileName = R"(C:\Users\USUARIO\Downloads\Listas\)" + fileName + ".txt";

            inputFile.open(fileName);

            while (getline(inputFile, line)) {
                dataList.addNode(line);
            }
            inputFile.close();
            cout << "Datos almacenados." << endl;
            cout << "------------------" << endl;
            cout << "------------------" << endl;
            cout << " " << endl;


            //dataList.printList();
            break;
        case 2:
            cout << "Ingrese la llave de busqueda: ";
            cin >> nombreArchivo;


            dataList.searchByKey(nombreArchivo);
            break;
        case 3:
            cout << "Ingrese el valor de busqueda: ";
            cin >> nombreArchivo;
            dataList.searchByValue(nombreArchivo);
            break;
        case 4:
            cout << "Saliendo del programa. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, ingrese un numero valido." << endl;
        }

    } while (opcion != 4);
    return 0;
}