#include "Board.h"

Board::Board() : board_size(5), max_ship_count(3),
    board(board_size, std::vector<EstadoCelda>(board_size, EstadoCelda::unknown)),
    ship_map(board_size, std::vector<int>(board_size, -1)) {
}

void Board::ShowMap() {
    PrintTopBorder();
    // ASCII "A" is 65
    int row_count = 65;
    for (auto curr_row : ship_map) {
        std::cout << static_cast<char>(row_count) << "|";
        for (auto curr_cell : curr_row) {
            if (curr_cell == -1) {
                std::cout << "   |";
            } else {
                std::cout << " " << curr_cell << " |";
            }
        }
        row_count++;
        std::cout << std::endl;
    }
}

void Board::PrintTopBorder() {
    std::cout << "  ";
    for (int i = 0; i < board_size; i++) {
        std::cout << " " << i << " |";
    }
    std::cout << std::endl;
    std::cout << "--";
    for (int i = 0; i < board_size; i++) {
        std::cout << "----";
    }
    std::cout << std::endl;
}

void Board::DisplayBoard() {
    PrintTopBorder();
    // ASCII "A" is 65
    int row_count = 65;
    for (auto curr_row : board) {
        std::cout << static_cast<char>(row_count) << "|";
        for (auto curr_cell : curr_row) {
            if (curr_cell == EstadoCelda::unknown) {
                std::cout << "   |";
            } else if (curr_cell == EstadoCelda::hit) {
                std::cout << " □ |";
            } else if (curr_cell == EstadoCelda::sink) {
                std::cout << " ■ |";
            } else if (curr_cell == EstadoCelda::miss) {
                std::cout << " X |";
            }
        }
        row_count++;
        std::cout << std::endl;
    }
}

bool Board::AddShip(Ship& ship) {
    if (ship_ids.size() == max_ship_count) {
        return false;
    }

    int start_x = ship.GetStartX();
    int start_y = ship.GetStartY();
    std::vector<std::pair<int, int>> coords;

    if (ship.GetOrientation() == Orientation::horizontal) {
        for (int i = 0; i < ship.GetLength(); i++) {
            coords.push_back(std::make_pair(start_x, start_y + i));
        }
    } else if (ship.GetOrientation() == Orientation::vertical) {
        for (int i = 0; i < ship.GetLength(); i++) {
            coords.push_back(std::make_pair(start_x + i, start_y));
        }
    } else {
        return false;
    }

    int ship_id = ship_ids.size();
    bool ShipPlaceable = true;

    for (auto coord : coords) {
        int x = coord.first;
        int y = coord.second;
        if (x < 0 || y < 0 || x >= board_size || y >= board_size) {
            // if out of bounds
            ShipPlaceable = false;
        } else {
            if (ship_map[x][y] != -1) {
                // or spot is already taken by another ship
                ShipPlaceable = false;
            }
        }
    }

    if (ShipPlaceable) {
        ship_ids.push_back(ship);
        for (auto coord : coords) {
            ship_map[coord.first][coord.second] = ship_id;
        }
        return true;
    } else {
        return false;
    }
}

void Board::HandleShipSunk(int x, int y, int ship_id) {
    int start_x = ship_ids[ship_id].GetStartX();
    int start_y = ship_ids[ship_id].GetStartY();
    int end_x = ship_ids[ship_id].GetEndX();
    int end_y = ship_ids[ship_id].GetEndY();
    if (start_x == end_x) {
        for (int i = start_y; i <= end_y; i++) {
            board[start_x][i] = EstadoCelda::sink;
        }
    } else {
        for (int i = start_x; i <= end_x; i++) {
            board[i][start_y] = EstadoCelda::sink;
        }
    }
}

void Board::FireAway(int x, int y) {
    // if lands on nothing
    if (ship_map[x][y] == -1) {
        board[x][y] = EstadoCelda::miss;
        std::cout << "MISS!" << std::endl;
    }
    // if lands on empty land
    else {
        int ship_id = ship_map[x][y];
        ship_ids[ship_id].RegisterLandedShot();
        if (ship_ids[ship_id].IsAlive()) {
            board[x][y] = EstadoCelda::hit;
            std::cout << "HIT!" << std::endl;
        } else {
            HandleShipSunk(x, y, ship_id);
            std::cout << "HIT AND SINK!" << std::endl;
        }
    }
}

bool Board::EvaluateShot(int x, int y) {
    bool IsValidShot = false;
    if (x < 0 || y < 0 || x >= board_size || y >= board_size) {
        IsValidShot = false;
    } else {
        if (board[x][y] == EstadoCelda::unknown) {
            IsValidShot = true;
        }
    }

    if (IsValidShot) {
        FireAway(x, y);
    }

    return IsValidShot;
}

bool Board::AllShipsSunk() {
    bool result = true;
    for (auto n : ship_ids) {
        if (n.IsAlive() == true) {
            result = false;
            break;
        }
    }
    return result;
}
