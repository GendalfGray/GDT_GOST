#include <iostream>
#include "shapes.hpp"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

float bar_scale;

// ===================================

Bar::Bar(int value, sf::Color color, bool isFirst) {
    
    _value = value;
    _color = color;
    _first = isFirst;
};

void Bar::drawBar(sf::RenderWindow& window) {
    
    sf::Vector2u WIN_SIZE = window.getSize();
    unsigned int WIN_HEIGHT = WIN_SIZE.y;
    unsigned int WIN_MIDDLE = WIN_HEIGHT / 2.f;
    float WIN_QUARTER = WIN_HEIGHT / 4.f;

    if (_first) {
        bar_scale = WIN_QUARTER / _value;

        _bar.setSize(sf::Vector2f(100.f, -WIN_QUARTER));
        _bar.setFillColor(sf::Color(0, 255, 0, 70));
        _bar.setPosition(sf::Vector2f(50.f, WIN_MIDDLE));
    }
    else {
        _bar.setSize(sf::Vector2f(100.f, -_value * bar_scale));
        _bar.setFillColor(sf::Color(255, 0, 0, 80));
        _bar.setPosition(sf::Vector2f(125.f, WIN_MIDDLE));
    }

    sf::Font dos;
    dos.loadFromFile("../fonts/dos.ttf");

    _barValue.setCharacterSize(30);
    _barValue.setOutlineColor(sf::Color::White);
    _barValue.setPosition(_bar.getPosition().x + 10, _bar.getPosition().y - _value * bar_scale - 35);
    _barValue.setFont(dos);
    _barValue.setString("+" + std::to_string(_value));

    window.draw(_bar);
    window.draw(_barValue);
};

void Bar::changeValue(int newValue) {

    _value = newValue;
};

// ===================================

void draw_grid(sf::RenderWindow& window) {

    unsigned int WIN_WIDTH = window.getSize().x;
    unsigned int WIN_HEIGHT = window.getSize().y;
    float WIN_MIDDLE = WIN_HEIGHT / 2.f;

    sf::RectangleShape zero_line(sf::Vector2f(WIN_WIDTH, 1.f));
    zero_line.setFillColor(sf::Color::White);
    zero_line.setPosition(sf::Vector2f(5.f, WIN_MIDDLE));

    sf::RectangleShape vertical_axis(sf::Vector2f(1.f, WIN_HEIGHT));
    vertical_axis.setFillColor(sf::Color::White);
    vertical_axis.setPosition(sf::Vector2f(5.f, 0.f));

    window.draw(zero_line);
    window.draw(vertical_axis);

    //std::cout << zero_line.getPosition().x << "\n";
}


   /* TextBox (sf::Color color, bool isSelected, sf::Font font) {
        textbox.setCharacterSize(14);
        textbox.setOutlineColor(sf::Color::White);
        textbox.setPosition(0.f, 0.f);
        textbox.setFont(font);

        if (isSelected) {
            textbox.setString("_");
        }
        else {
            textbox.setString("");
        }

        void drawTo(sf::RenderWindow & window) {
            window.draw(textbox);
        }
    }*/
    



    /*void typedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = input.text.unicode;
            if (charTyped < 120) {
                if (hasLimit) {
                    if (text.str().length() <= limit) {
                        inputLogic(charTyped);
                    }
                    else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                        deleteLastChar();
                    }
                }
                else {
                    inputLogic(charTyped);
                }
            }
        }
    }*/

    /*void setPosition(sf::Vector2f pos) {
        textbox.setPosition(pos);
    }

    std::string getText() {
        return text.str();
    }*/



    /*
    void inputLogic(int charTyped) {
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
            text << static_cast<char>(charTyped);
        }
        else if (charTyped == DELETE_KEY) {
            if (text.str().length() > 0) {
                deleteLastChar();
            }
        }
        textbox.setString(text.str() + "_");
    }

    void deleteLastChar() {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length() - 1; i++) {
            newT += t[i];
        }
        text.str("");
        text << newT;

        textbox.setString(text.str());
    }*/
//};


