#include "Disco.h"
#include <fstream>
#include <filesystem>
#include <iostream>


void Disco::cargarRespaldos(const string& rutaCarpeta, vector<Disco>& listaDisco) {
	for (const auto& entry : fs::directory_iterator(rutaCarpeta)) {
		if (entry.is_regular_file() && entry.path().extension() == ".txt") {
				ifstream archivo(entry.path());

				if (archivo.is_open()) {
					string nombreDisco = entry.path().stem().string();
					int cantidadcanciones = 0;

					string linea;
					while (getline(archivo, linea)) {
						cantidadcanciones++;
					}

					listaDisco.emplace_back(nombreDisco, cantidadcanciones);

					archivo.close();
				}
				else {
					cout << "No se pudo abrir el archivo: " << entry.path() << endl;
				}
			}
	}
}

