#pragma once

class Tile
{
public:
    int x;
    int y;
    int type; // 0 = çimen, 1 = su, 2 = orman, 3 = taş

    Tile(int xPos, int yPos, int tileType)
        : x(xPos), y(yPos), type(tileType)
    {
    }
};
