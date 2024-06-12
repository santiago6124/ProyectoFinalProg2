#ifndef SHIP_H
#define SHIP_H

#include <cmath>
#include <algorithm>
#include "Celda.h"

class Ship {
    private:
        int start_x;
        int start_y;
        int end_x;
        int end_y;
        int strike_count{0};
        int ship_length;
        bool alive{true};
        Orientation orientation;

    public:
        Ship(int start_x, int start_y, int end_x, int end_y, Orientation orientation);
        Ship(int start_x, int start_y, Orientation orientation, int length);

        bool IsAlive();
        int GetStartX();
        int GetStartY();
        int GetEndX();
        int GetEndY();
        bool EvaluateShot(int attempt_x, int attempt_y);
        void RegisterLandedShot();
        Orientation GetOrientation();
        int GetLength();
};

#endif
