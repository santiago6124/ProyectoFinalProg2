// Juego.cpp
#include "Juego.h"
#include "Usuario.h"
#include "Maquina.h"
#include <iostream>
#include <cctype>
#include <sstream>
#include "util.h"
Juego::Juego(const std::string& nombreJugador1, const std::string& nombreJugador2, int size)
    : ranking("ranking.txt"), ataquesJugador1(0), ataquesJugador2(0) {
    
    int modo = 0;

    // Repetir el input hasta que se ingrese un modo de juego válido
    while (modo != 1 && modo != 2) {
        std::cout << "Selecciona el modo de juego: (1) Usuario vs Usuario (2) Usuario vs Maquina: ";
        std::cin >> modo;

        if (modo != 1 && modo != 2) {
            std::cout << "Modo de juego no valido. Por favor, ingresa 1 o 2." << std::endl;
        }
    }

    std::string nombre1 = nombreJugador1;
    std::string nombre2 = nombreJugador2;

    if (modo == 1) {
        std::cout << "Ingresa el nombre del Jugador 1: ";
        std::cin >> nombre1;
        std::cout << "Ingresa el nombre del Jugador 2: ";
        std::cin >> nombre2;
        jugador1 = std::make_unique<Usuario>(nombre1, size);
        jugador2 = std::make_unique<Usuario>(nombre2, size);
    } else if (modo == 2) {
        std::cout << "Ingresa el nombre del Jugador 1: ";
        std::cin >> nombre1;
        nombre2 = "Maquina";
        jugador1 = std::make_unique<Usuario>(nombre1, size);
        jugador2 = std::make_unique<Maquina>(nombre2, size);
    }
}

void Juego::jugar() {
    // Crear barcos para los jugadores
    std::vector<Barco> barcosJugador1 = {Barco(4, true), Barco(3, true), Barco(3, true),
                                         Barco(2, true), Barco(2, true), Barco(2, true),
                                         Barco(1, true), Barco(1, true), Barco(1, true), Barco(1, true)};
    std::vector<Barco> barcosJugador2 = barcosJugador1;

    // Colocar barcos para los jugadores
    for (Barco& barco : barcosJugador1) {
        while (!jugador1->colocarBarco(0, 0, barco));
    }
    for (Barco& barco : barcosJugador2) {
        while (!jugador2->colocarBarco(0, 0, barco));
    }

    // Mostrar tableros iniciales
    std::cout << "Tablero " << jugador1->getNombre() << ":" << std::endl;
    jugador1->getTablero().mostrarTablero();
    std::cout << std::endl;

    std::cout << "Tablero " << jugador2->getNombre() << ":" << std::endl;
    jugador2->getTablero().mostrarTablero();
    std::cout << std::endl;

    bool juegoTerminado = false;
    while (!juegoTerminado) {
        std::string entrada;
        int x, y;

        // Turno del jugador 1
        bool ataqueValido = false;
        while (!ataqueValido) {
            std::cout << jugador1->getNombre() << ", ingresa las coordenadas para atacar (Ej. A1, B3): ";
            std::cin >> entrada;
            if (parsearEntrada(entrada, x, y)) {
                ataqueValido = jugador1->atacar(jugador2->getTablero(), x, y);
                if (ataqueValido) ataquesJugador1++;
                if (!ataqueValido) {
                    std::cout << "Coordenada ya atacada o no valida. Intenta de nuevo." << std::endl;
                }
            } else {
                std::cout << "Formato de entrada no valido. Intenta de nuevo." << std::endl;
            }
        }
        std::cout << "Tablero " << jugador2->getNombre() << " despues del ataque:" << std::endl;
        jugador2->getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador2 estan hundidos
        if (jugador2->todosBarcosHundidos()) {
            std::cout << jugador1->getNombre() << " ha ganado!" << std::endl;
            ranking.agregarJugador(jugador1->getNombre(), ataquesJugador1);
            ranking.guardar();
            ranking.mostrar();
            juegoTerminado = true;
            break;
        }

        // Turno del jugador 2
        ataqueValido = false;
        while (!ataqueValido) {
            if (dynamic_cast<Usuario*>(jugador2.get())) {
                std::cout << jugador2->getNombre() << ", ingresa las coordenadas para atacar (Ej. A1, B3): ";
                std::cin >> entrada;
                if (parsearEntrada(entrada, x, y)) {
                    ataqueValido = jugador2->atacar(jugador1->getTablero(), x, y);
                    if (ataqueValido) ataquesJugador2++;
                    if (!ataqueValido) {
                        std::cout << "Coordenada ya atacada o no valida. Intenta de nuevo." << std::endl;
                    }
                } else {
                    std::cout << "Formato de entrada no valido. Intenta de nuevo." << std::endl;
                }
            } else if (dynamic_cast<Maquina*>(jugador2.get())) {
                ataqueValido = dynamic_cast<Maquina*>(jugador2.get())->atacar(jugador1->getTablero(), x, y);
                if (ataqueValido) ataquesJugador2++;
            }
        }
        std::cout << "Tablero " << jugador1->getNombre() << " despues del ataque:" << std::endl;
        jugador1->getTablero().mostrarTablero();
        std::cout << std::endl;

        // Verificar si todos los barcos del jugador1 estan hundidos
        if (jugador1->todosBarcosHundidos()) {
            std::cout << jugador2->getNombre() << " ha ganado!" << std::endl;
            ranking.agregarJugador(jugador2->getNombre(), ataquesJugador2);
            ranking.guardar();
            ranking.mostrar();
            juegoTerminado = true;
            break;
        }
    }
}
