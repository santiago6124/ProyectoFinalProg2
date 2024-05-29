#include "Juego.h"

Juego::Juego(const Jugador& j1, const Jugador& j2) 
    : jugador1(j1), jugador2(j2), turnoActual(&jugador1), estado("En curso") {}

void Juego::iniciar() {
    // Implementar la lógica para iniciar el juego
}

void Juego::turno() {
    // Implementar la lógica para manejar los turnos del juego
}

Jugador Juego::comprobarVictoria() const {
    // Implementar la lógica para comprobar si hay un ganador
    return *turnoActual;
}