#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Tile.h"

class TileMap
{
public:
    TileMap(int width, int height, int tileSize);

    void Draw(sf::RenderWindow& window);
    void PrintToConsole();

private:
    int width;
    int height;
    int tileSize;                   

    std::vector<Tile> tiles;
};
