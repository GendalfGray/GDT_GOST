#include <iostream>

#include <SFML/Graphics.hpp>
#include "shapes.hpp"
#include "ui.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(420, 380), "SFML works!");

    std::vector<char> input_chars;

    /*std::cout << "Pixels in bar: " << WIN_QUARTER << std::endl;
    std::cout << "Hole tolerance value: " << holeToleranceValue << std::endl;
    std::cout << "Shaft tolerance value: " << shaftToleranceValue << std::endl;
    std::cout << "Bar scale: " << bar_scale << std::endl;*/
   
    //Bar bar1{ 30, sf::Color::Red, true };
    //Bar bar2{ 40, sf::Color::Blue, false };

    //TextBox textField1{20.f, 20.f, 100.f, 50.f};

    while (window.isOpen())
    {
        sf::Event event;
        int a;


        while (window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                std::cout << std::string(input_chars.begin(), input_chars.end()) << '\n';
                input_chars.clear();
            }
            
            switch (event.type)
            {
            case sf::Event::TextEntered:
                std::cout << static_cast <char>(event.text.unicode) << '\n';
                input_chars.push_back(event.text.unicode);
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //stextField1.selectForm(sf::Mouse::getPosition(window));
                }
                break;
            
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::Resized:
                sf::FloatRect view(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(view));
                break;
            }
        }

        window.clear();

        sf::Font font;
        font.loadFromFile("../fonts/dos.ttf");

        sf::Text txt;
        txt.setFont(font);
        
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        std::string mousePosStr = std::to_string(mousePos.x) + " : " + std::to_string(mousePos.y);

        txt.setString(mousePosStr);
        txt.setCharacterSize(24);

        

        txt.setPosition(10, 10);
        //txt.setColor(sf::Color::White);
        //window.draw(textbox);
        //tex.drawTo(window);
        
        //draw_grid(window);

        //bar1.drawBar(window);
        //bar2.drawBar(window);

        //textField1.drawTo(window);
        //textField1.selectForm(mousePos);

        //draw_bar(window, 90, true);
        //draw_bar(window, 85, false);

        //textbox1.drawTo(window);

        window.draw(txt);

        window.display();
    }

    return 0;
}