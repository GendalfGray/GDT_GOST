#pragma once

#include <SFML/Graphics.hpp>


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
