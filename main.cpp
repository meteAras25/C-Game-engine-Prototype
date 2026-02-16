#include <iostream>
#include <chrono>
#include <thread>

#include "Entity.h"
#include "GridPositionComponent.h"
#include "MovementComponent.h"
#include "AIComponent.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// Harita boyutu
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
const int TILE_SIZE = 32;

// Harita verisi
int map[MAP_HEIGHT][MAP_WIDTH] =
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,1,1,1,0,0,0,1},
    {1,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,0,1,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

// Haritayı konsola yazdırma
void PrintMap()
{
    std::cout << "HARITA:\n\n";
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            std::cout << map[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

// Haritayı SFML ile çizme
void DrawMap(sf::RenderWindow& window)
{
    sf::RectangleShape tile(sf::Vector2f(TILE_SIZE, TILE_SIZE));

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (map[y][x] == 1)
                tile.setFillColor(sf::Color::Blue);  // Duvar
            else
                tile.setFillColor(sf::Color::Black); // Boşluk

            tile.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(tile);
        }
    }
}

int main()
{
    PrintMap(); // Konsola yazdır

    sf::RenderWindow window(
        sf::VideoMode(MAP_WIDTH * TILE_SIZE, MAP_HEIGHT * TILE_SIZE),
        "Tile Map"
    );

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        DrawMap(window);
        window.display();
    }

    return 0;
}

