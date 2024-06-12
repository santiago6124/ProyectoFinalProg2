#include "Player.h"

Player::Player(std::string name) : name(name) {}

std::string Player::GetName() {
    return this->name;
}

bool Player::IsPlayerAlive() {
    return !board.AllShipsSunk();
}

bool Player::PlayNextMove(int x, int y) {
    if(board.EvaluateShot(x, y)) {
        return true;
    } else {
        std::cout << "Not a Valid Shot" << std::endl;
        return false;
    }
}

bool Player::AddShip(int start_x, int start_y, int end_x, int end_y, Orientation orientation) {
    auto ship = Ship(start_x, start_y, end_x, end_y, orientation);
    bool success = board.AddShip(ship);
    if(success) {
        std::cout << "Ship Added!" << std::endl;
        ship_count++;
    } else {
        std::cout << "Unable to Add Ship" << std::endl;
    }
    return success;
}

bool Player::AddShip(int start_x, int start_y, Orientation orientation, int length) {
    auto ship = Ship(start_x, start_y, orientation, length);
    bool success = board.AddShip(ship);
    if(success) {
        std::cout << "Ship Added!" << std::endl;
        ship_count++;
    } else {
        std::cout << "Unable to Add Ship" << std::endl;
    }
    return success;
}

int Player::GetShipCount() {
    return ship_count;
}

void Player::PrintGameBoard() {
    board.DisplayBoard();
}

void Player::PrintShipMap() {
    board.ShowMap();
}
