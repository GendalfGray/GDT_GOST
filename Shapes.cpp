#include "Shapes.h"

void draw_grid(sf::RenderWindow& window) {

    sf::Vector2u WIN_SIZE = window.getSize();
    unsigned int WIN_WIDTH = WIN_SIZE.x;
    unsigned int WIN_HEIGHT = WIN_SIZE.y;
    unsigned int WIN_MIDDLE = WIN_HEIGHT / 2;

    sf::RectangleShape zero_line(sf::Vector2f(WIN_WIDTH, 5.f));
    zero_line.setFillColor(sf::Color::White);
    zero_line.setPosition(sf::Vector2f(0.f, WIN_MIDDLE));

    sf::RectangleShape vertical_axis(sf::Vector2f(5.f, WIN_HEIGHT));
    vertical_axis.setFillColor(sf::Color::White);

    window.draw(zero_line);
    window.draw(vertical_axis);
}

void draw_bar(sf::RenderWindow& window, int tolerance_value, double x, double y) {

}