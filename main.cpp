#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(420, 380), "SFML works!");

    sf::Vector2u WIN_SIZE = window.getSize();
    unsigned int WIN_WIDTH = WIN_SIZE.x;
    unsigned int WIN_HEIGHT = WIN_SIZE.y;
    unsigned int WIN_MIDDLE = WIN_HEIGHT / 2;
    int WIN_QUARTER = WIN_MIDDLE / 2;
    
    float holeToleranceValue = 90.f;
    float shaftToleranceValue = 89.f;

    double bar_scale = WIN_QUARTER / holeToleranceValue;

    // HOLE
    sf::RectangleShape hole_tolerance_column(sf::Vector2f(50.f, -WIN_QUARTER));
    hole_tolerance_column.setFillColor(sf::Color::Red);
    hole_tolerance_column.setPosition(sf::Vector2f(50.f, WIN_MIDDLE));

    float shaftScaledValue = shaftToleranceValue * bar_scale;

    // SHAFT
    sf::RectangleShape shaft_tolerance_column(sf::Vector2f(50.f, -shaftScaledValue));
    shaft_tolerance_column.setFillColor(sf::Color::Blue);
    shaft_tolerance_column.setPosition(sf::Vector2f(75.f, WIN_MIDDLE));

    std::cout << "Pixels in bar: " << WIN_QUARTER << std::endl;
    std::cout << "Hole tolerance value: " << holeToleranceValue << std::endl;
    std::cout << "Shaft tolerance value: " << shaftToleranceValue << std::endl;
    std::cout << "Bar scale: " << bar_scale << std::endl;

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        draw_grid(window);

        window.draw(hole_tolerance_column);
        window.draw(shaft_tolerance_column);

        window.display();
    }

    return 0;
}