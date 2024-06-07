#include "Maquina.h"

Maquina::Maquina(const std::string& nombre, int filas, int columnas)
    : Jugador(nombre, filas, columnas) {}

void Maquina::colocarBarcosAleatoriamente() {
    Jugador::colocarBarcosAleatoriamente();
}
