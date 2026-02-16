#pragma once 
#include <vector>
#include "Tile.h"

class Map 
{
    public:
     Map(int width,int height)
        :width(width), height(height)
        {
            tiles.resize(width * height);
        }

        Tile& GetTile(int x, int y)
    {
        return tiles[y * width + x];
    }

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }





     private:
     int width;
     int height;
     std::vector<Tile> tiles;
};