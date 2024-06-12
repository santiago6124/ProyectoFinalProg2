#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <Celda.h>
#include <iostream>
#include <Ship.h>
#include <string>

class Board {
public:
    Board();

    void ShowMap();
    void PrintTopBorder();
    void DisplayBoard();
    bool AddShip(Ship& ship);
    void HandleShipSunk(int x, int y, int ship_id);
    void FireAway(int x, int y);
    bool EvaluateShot(int x, int y);
    bool AllShipsSunk();

private:
    int board_size;
    int max_ship_count;
    std::vector<Ship> ship_ids; // ship ID corresponding to the actual ship object
    std::vector<std::vector<EstadoCelda>> board; // represents the display status of each cell
    std::vector<std::vector<int>> ship_map; // represents the location of each ship, using ship ID
};

#endif
