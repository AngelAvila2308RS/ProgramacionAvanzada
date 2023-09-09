#include <iostream>
using namespace std;

int Calculardias(int mes1, int a1);
bool bisiesto(int a);
int zeller(int ano, int mes, int dia);


int main()
{
    std::cout << "Anio: ";
    int a;
    cin >> a;
    string m[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};


    for (int mes = 1; mes <= 12;mes++) {
        cout << endl;
        std::cout << "Mes : " << endl;
        std::cout<< m[mes - 1] << endl;
        cout << "Dom Lun Mar Mie Jue Vie Sab" << endl;
        int x = zeller(a, mes, 1);
        for (int i = 0; i < x;i++) {
            cout << "    ";
        }

        int dia_mes_actual = Calculardias(mes, a);
        for (int dia = 1; dia <= dia_mes_actual; dia++) {
            if (dia < 10) cout << dia << "   ";
            else cout << dia << "  ";
            x++;
            if (x % 7 == 0)  cout << endl;


        }

        cout << endl;
    }


    return 0;
}


    //Esta funcion nos dira cuantos dias debe de tener cada mes
int Calculardias(int mes1, int a1) {
    if (mes1 == 1 || mes1 == 3 || mes1 == 5 || mes1 == 7 || mes1 == 8 || mes1 == 10 || mes1 == 12)
        return 31;
    if (mes1 == 2) {
        if (bisiesto(a1) == true) return 29;
        else return 28;
    }
    else return 30;
}
    //esta funcion nos dira si el año es bisiesto o no por medio de calculos matematicos
bool bisiesto(int a2) {
    if (a2 % 4 != 0) return false;
    else if (a2 % 100 != 0) return false;
    else if (a2 % 400 != 0) return false;
    return true;
}

int zeller(int ano, int mes, int dia) {
    int a = (14 - mes) / 12;
    int y = ano - a;
    int m = mes + 12 * a - 2;

    int d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return d;
}

    