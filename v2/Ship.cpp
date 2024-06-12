#include "Ship.h"
#include <iostream>

Ship::Ship(int start_x, int start_y, int end_x, int end_y, Orientation orientation) :
    start_x(start_x), start_y(start_y), end_x(end_x), end_y(end_y),
    orientation(orientation) {
    int delta_x = std::abs(start_x - end_x);
    int delta_y = std::abs(start_y - end_y);
    ship_length = std::max(delta_x, delta_y) + 1;
}

Ship::Ship(int start_x, int start_y, Orientation orientation, int length) : 
    start_x(start_x), start_y(start_y), orientation(orientation), ship_length(length) {
    if (orientation == Orientation::horizontal) {
        end_x = start_x;
        end_y = start_y + ship_length - 1;
    } else if (orientation == Orientation::vertical) {
        end_x = start_x + ship_length - 1;
        end_y = start_y;
    } else {
        end_x = -1;
        start_x = -1;
    }
}

bool Ship::IsAlive() {
    return alive;
}

int Ship::GetStartX() {
    return start_x;
}

int Ship::GetStartY() {
    return start_y;
}

int Ship::GetEndX() {
    return end_x;
}

int Ship::GetEndY() {
    return end_y;
}

bool Ship::EvaluateShot(int attempt_x, int attempt_y) {
    bool landed_shot = false;
    if (attempt_x == start_x) {
        if (attempt_y >= start_y && attempt_y <= end_y) {
            landed_shot = true;
        }
    } else if (attempt_y == start_y) {
        if (attempt_x >= start_x && attempt_x <= end_x) {
            landed_shot = true;
        }
    }
    if (landed_shot) {
        RegisterLandedShot();
    }
    return landed_shot;
}

void Ship::RegisterLandedShot() {
    strike_count++;
    if (ship_length == strike_count) {
        std::cout << "ship sunk" << std::endl;
        alive = false;
    }
}

Orientation Ship::GetOrientation() {
    return orientation;
}

int Ship::GetLength() { 
    return ship_length;
}
