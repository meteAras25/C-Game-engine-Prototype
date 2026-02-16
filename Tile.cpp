#include "Tile.h"

Tile::Tile(sf::Vector2f position, sf::Color color)
{
    shape.setSize({64.f, 32.f}); // izometrik temel
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Tile::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
