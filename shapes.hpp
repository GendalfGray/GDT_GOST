#pragma once

#include <SFML/Graphics.hpp>

void draw_grid(sf::RenderWindow& window);

class Bar {
public:
    Bar(int value, sf::Color color, bool isFirst);
    void drawBar(sf::RenderWindow& window);
    void changeValue(int newValie);

private:
    sf::RectangleShape _bar;
    sf::Color _color;
    int _value;
    bool _first;

    sf::Text _barValue;
};