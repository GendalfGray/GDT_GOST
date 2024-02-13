#include <iostream>
#include "ui.hpp"

TextBox::TextBox(float pos_x, float pos_y, float size_x, float size_y) {

    m_posx2 = pos_x + size_x;
    m_posy2 = pos_y + size_y;
    
    m_body.setPosition(sf::Vector2f(pos_x, pos_y));
    m_body.setSize(sf::Vector2f(size_x, size_y));
};

void TextBox::drawTo(sf::RenderWindow &window) {
    
    window.draw(m_body);
};

void TextBox::selectForm(sf::Vector2i mousePos) {
    
    if (m_body.getGlobalBounds().contains((float)mousePos.x, (float)mousePos.y)) {
        //std::cout << "Mouse inside\n";
        m_isSelected = true;
        m_body.setFillColor(sf::Color::Green);
    }
    else {
        //std::cout << "Mouse outside\n";
        m_isSelected = false;
        m_body.setFillColor(sf::Color::White);
    };
};

void TextBox::typeIn(int simbol) {
    std::cout << simbol;
};
