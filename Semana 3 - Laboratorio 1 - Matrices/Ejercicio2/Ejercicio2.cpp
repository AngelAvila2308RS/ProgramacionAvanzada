#include <iostream>
#include <stdio.h>

using namespace std;

void Matriztranspuesta(int** Matriz, int columnas, int filas) {

    cout << "Matriz Transpuesta " << endl;

    for (int i = 0;i < filas;i++) {
        for (int j = 0;j < columnas;j++) {
            cout << Matriz[j][i] << "  ";
        }
        cout << endl;
    }
}

int main()
{
        //Crear la definicion
    int** numero = new int* [2];


    //Formar la matriz con las filas
    for (int j = 0;j < 3;++j) {
        *(numero + j) = new int[3];
    }


        //Ingresar datos
    for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 2; ++i) {
        cout << "Ingrese el valor de la posicion [" << j << "] ["<< i <<"] :" << endl;
        std::cin >> numero[j][i];
        }
    }

        //numero[0][0] = 3;
        //numero[0][1] = 7;
        //numero[1][0] = 9;
        //numero[1][1] = 5;
        //numero[2][0] = 1;
        //numero[2][1] = 4;

        Matriztranspuesta(numero,3,2);

 
        //Matriz original
    cout << "Matriz Original " << endl;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 2;j++) {
            cout << numero[i][j]<<"  ";
        }
        cout << endl;
    ;}
    
    Matriztranspuesta(numero, 3,2);


    return 0;
}



