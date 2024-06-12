#include <vector>
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Celda.h"
#include <string>

Orientation ConvertOrientation(int input) {
    Orientation result = Orientation::unknown;
    if (input == 1) {
        result = Orientation::horizontal;
    } else if (input == 2) {
        result = Orientation::vertical;
    }
    return result;
}

std::pair<int, int> ConvertInputToCoordinates(const std::string& input) {
    if (input.length() < 2) {
        // Handle invalid input
        return { -1, -1 };
    }

    char xChar = std::toupper(input[0]);
    int x = xChar - 'A';
    int y = input[1] - '0';

    return { x, y };
}

void PromptNewShip(Player& player) {
    std::string ship_coordinate;
    int orientation;
    std::cout << player.GetName() << ", This is your map" << std::endl;
    player.PrintShipMap();
    std::cout << "Please place your next ship. Choose the Starting Coordinate (Example: A2 or B3)" << std::endl;
    std::cin >> ship_coordinate;
    std::cout << "Is the ship horizontal (1) or vertical (2)?" << std::endl;
    std::cin >> orientation;
    auto coords_x_y = ConvertInputToCoordinates(ship_coordinate);
    player.AddShip(coords_x_y.first, coords_x_y.second, ConvertOrientation(orientation), 3);
}

void PromptAttack(Player& player) {
    std::string attack_coordinate;
    player.PrintGameBoard();
    std::cout << "Please attack " << player.GetName() << ". Enter the coordinate to fire (Example: A2 or B3)" << std::endl;
    std::cin >> attack_coordinate;
    auto coords_x_y = ConvertInputToCoordinates(attack_coordinate);
    player.PlayNextMove(coords_x_y.first, coords_x_y.second);
}

int main() {
    Player player1("Player1");
    std::cout << "=====================================" << std::endl;
    std::cout << "WELCOME TO DD BATTLESHIP" << std::endl;
    std::cout << "=====================================" << std::endl;

    while (player1.GetShipCount() < 3) {
        PromptNewShip(player1);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    
    // Clear the screen (platform dependent)
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
    
    std::cout << "=============================================================================================" << std::endl;
    std::cout << "Now hand the computer to someone else, if you have friends. Otherwise, you can keep playing." << std::endl;
    std::cout << "=============================================================================================" << std::endl;

    int turns{0};
    while (player1.IsPlayerAlive()) {
        PromptAttack(player1);
        turns++;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Game Over! Took " << turns << " hits" << std::endl;

    return 0;
}
