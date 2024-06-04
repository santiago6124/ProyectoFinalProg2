#include "Juego.h"

Juego::Juego(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2), turnoActual(&j1), estado("iniciado") {}

void Juego::iniciar() {
    jugador1.colocarBarcos();
    jugador2.colocarBarcos();
}

void Juego::turno() {
    int x, y;
    std::cout << "Turno de " << turnoActual->getNombre() << ". Ingresa las coordenadas para disparar (x y): ";
    std::cin >> x >> y;
    std::string resultado = turnoActual->realizarDisparo(x, y);
    std::cout << resultado << std::endl;
    if (resultado == "¡Hundido!") {
        if (turnoActual->todosBarcosHundidos()) {
            estado = "terminado";
        }
    }
    turnoActual = (turnoActual == &jugador1) ? &jugador2 : &jugador1;
}

Jugador* Juego::comprobarVictoria() {
    if (estado == "terminado") {
        return turnoActual;
    }
    return nullptr;
}
