#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include "Ship.h"
#include <string>
#include <iostream>

class Player {
public:
    Player(std::string name);

    std::string GetName();

    bool IsPlayerAlive();
    bool PlayNextMove(int x, int y);
    bool AddShip(int start_x, int start_y, int end_x, int end_y, Orientation orientation);
    bool AddShip(int start_x, int start_y, Orientation orientation, int length);

    int GetShipCount();

    void PrintGameBoard();
    void PrintShipMap();

private:
    int ship_count = 0;
    Board board;
    std::string name;
};

#endif
