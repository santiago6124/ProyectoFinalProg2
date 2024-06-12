#include <iostream>
#include "Board.h"
#include "Ship.h"
#include "Celda.h"

int main() {
    // Crear el tablero
    Board board;

    // Crear y agregar barcos al tablero
    Ship ship1(0, 0, Orientation::horizontal, 3);
    Ship ship2(2, 2, Orientation::vertical, 4);
    Ship ship3(4, 1, Orientation::horizontal, 2);

    if (!board.AddShip(ship1)) {
        std::cout << "No se pudo agregar el barco 1" << std::endl;
    }
    if (!board.AddShip(ship2)) {
        std::cout << "No se pudo agregar el barco 2" << std::endl;
    }
    if (!board.AddShip(ship3)) {
        std::cout << "No se pudo agregar el barco 3" << std::endl;
    }

    // Mostrar el mapa inicial
    std::cout << "Mapa inicial de barcos:" << std::endl;
    board.ShowMap();

    // Mostrar el tablero inicial
    std::cout << "\nTablero inicial:" << std::endl;
    board.DisplayBoard();

    // Disparar a algunas coordenadas
    std::cout << "\nDisparar a (0,0):" << std::endl;
    board.EvaluateShot(0, 0);

    std::cout << "\nDisparar a (0,1):" << std::endl;
    board.EvaluateShot(0, 1);

    std::cout << "\nDisparar a (0,2):" << std::endl;
    board.EvaluateShot(0, 2);

    std::cout << "\nDisparar a (2,2):" << std::endl;
    board.EvaluateShot(2, 2);

    std::cout << "\nDisparar a (3,2):" << std::endl;
    board.EvaluateShot(3, 2);

    std::cout << "\nDisparar a (4,2):" << std::endl;
    board.EvaluateShot(4, 2);

    // Mostrar el tablero después de los disparos
    std::cout << "\nTablero despues de los disparos:" << std::endl;
    board.DisplayBoard();

    // Comprobar si todos los barcos han sido hundidos
    if (board.AllShipsSunk()) {
        std::cout << "\n¡Todos los barcos han sido hundidos!" << std::endl;
    } else {
        std::cout << "\nAun quedan barcos por hundir." << std::endl;
    }

    return 0;
}
