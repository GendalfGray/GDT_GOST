#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>


void draw_grid(sf::RenderWindow& window);


class TextBox {
public:
	
	TextBox(float pos_x, float pos_y, float size_x, float sixe_y);
    void drawTo(sf::RenderWindow& window);
    void selectForm(sf::Vector2i mousePos);
    void typeIn(int simbol);

private:
	
	sf::RectangleShape m_body;
    bool m_isSelected = false;

    float m_posx2;
    float m_posy2;
};


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