#include "Jugador.h"
#include <fstream>

Jugador::Jugador(const std::string& nombre, int filas, int columnas) 
    : nombre(nombre), tableroPropio(filas, columnas), tableroRival(filas, columnas) {}

void Jugador::colocarBarcos() {
    // Example placement, modify to include user input for a more interactive experience
    Barco barco4(4);
    tableroPropio.colocarBarco(barco4, 0, 0, 'H');
    barcos.push_back(barco4);

    Barco barco3_1(3);
    tableroPropio.colocarBarco(barco3_1, 2, 2, 'V');
    barcos.push_back(barco3_1);

    Barco barco3_2(3);
    tableroPropio.colocarBarco(barco3_2, 5, 5, 'H');
    barcos.push_back(barco3_2);

    Barco barco2_1(2);
    tableroPropio.colocarBarco(barco2_1, 7, 7, 'V');
    barcos.push_back(barco2_1);

    Barco barco2_2(2);
    tableroPropio.colocarBarco(barco2_2, 9, 9, 'H');
    barcos.push_back(barco2_2);

    Barco barco2_3(2);
    tableroPropio.colocarBarco(barco2_3, 3, 3, 'V');
    barcos.push_back(barco2_3);

    Barco barco1_1(1);
    tableroPropio.colocarBarco(barco1_1, 6, 6, 'H');
    barcos.push_back(barco1_1);

    Barco barco1_2(1);
    tableroPropio.colocarBarco(barco1_2, 1, 8, 'H');
    barcos.push_back(barco1_2);

    Barco barco1_3(1);
    tableroPropio.colocarBarco(barco1_3, 0, 9, 'V');
    barcos.push_back(barco1_3);

    Barco barco1_4(1);
    tableroPropio.colocarBarco(barco1_4, 8, 1, 'H');
    barcos.push_back(barco1_4);
}

std::string Jugador::realizarDisparo(int x, int y) {
    return tableroRival.recibirDisparo(x, y);
}

bool Jugador::todosBarcosHundidos() const {
    for (const auto& barco : barcos) {
        if (!barco.isHundido()) {
            return false;
        }
    }
    return true;
}

std::string Jugador::getNombre() const {
    return nombre;
}

void Jugador::guardarEstado(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << nombre << std::endl;
        // Guardar estado del tablero y barcos (simplificado)
        for (const auto& barco : barcos) {
            file << barco.getTamaño() << std::endl;
        }
        file.close();
    }
}

void Jugador::cargarEstado(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> nombre;
        // Cargar estado del tablero y barcos (simplificado)
        barcos.clear();
        int tamaño;
        while (file >> tamaño) {
            Barco barco(tamaño);
            barcos.push_back(barco);
        }
        file.close();
    }
}
