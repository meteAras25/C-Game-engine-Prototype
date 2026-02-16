#include "TileMap.h"
#include <iostream>

TileMap::TileMap(int w, int h, int size)
{
    width = w;
    height = h;
    tileSize = size;

    // Harita oluştur
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)                                                 
        {
            int type = 0;

            // Kenarları su yapalım örnek olarak
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
                type = 1;

            tiles.emplace_back(x, y, type);
        }
    }
}

void TileMap::PrintToConsole()
{
    std::cout << "HARITA:\n\n";

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = y * width + x;
            std::cout << tiles[index].type << " ";
        }
        std::cout << std::endl;
    }
}

void TileMap::Draw(sf::RenderWindow& window)
{
    sf::RectangleShape tileShape(sf::Vector2f(tileSize, tileSize));

    for (const auto& tile : tiles)
    {
        if (tile.type == 0)
            tileShape.setFillColor(sf::Color(34, 139, 34)); // çimen
        else if (tile.type == 1)
            tileShape.setFillColor(sf::Color::Blue); // su
        else
            tileShape.setFillColor(sf::Color::White);

        tileShape.setPosition(tile.x * tileSize, tile.y * tileSize);
        window.draw(tileShape);
    }
}
