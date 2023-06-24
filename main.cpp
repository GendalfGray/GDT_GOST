#include <SFML/Graphics.hpp>
#include "Shapes.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(420, 380), "SFML works!");

    /*std::cout << "Pixels in bar: " << WIN_QUARTER << std::endl;
    std::cout << "Hole tolerance value: " << holeToleranceValue << std::endl;
    std::cout << "Shaft tolerance value: " << shaftToleranceValue << std::endl;
    std::cout << "Bar scale: " << bar_scale << std::endl;*/
   
    Bar bar1{ 30, sf::Color::Red, true };
    Bar bar2{ 40, sf::Color::Blue, false };

    TextBox textField1{20.f, 20.f, 100.f, 50.f};

    while (window.isOpen())
    {
        sf::Event event;
        int a;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    textField1.selectForm(sf::Mouse::getPosition(window));
                }
                break;

            case sf::Event::TextEntered:

                a = event.text.unicode;

                textField1.typeIn(a);
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

        //window.draw(textbox);
        //tex.drawTo(window);
        
        draw_grid(window);

        bar1.drawBar(window);
        bar2.drawBar(window);

        textField1.drawTo(window);

        //draw_bar(window, 90, true);
        //draw_bar(window, 85, false);

        //textbox1.drawTo(window);

        window.display();
    }

    return 0;
}