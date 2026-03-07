#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Weapon.hpp"

class Game
{
public:
    Game() :
        window(sf::VideoMode({ 1920,1200 }), "Game")
    {
        window.setVerticalSyncEnabled(true);
    }

    void run()
    {
        while (window.isOpen())
        {
            handleEvents();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    Player player {"bert"};
    Weapon sword{ "Iron sword", 10 };

    void handleEvents()
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
    }

    void update()
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            // left mouse button is pressed: swing sword
            sword.swing();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
        {
            // right key is pressed: move our character
            player.move(1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
        {
            // left key is pressed: move our character
            player.move(-1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
        {
            // up key is pressed: move our character
            player.move(0.f, -1.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
        {
            // down key is pressed: move our character
            player.move(0.f, 1.f);
        }
    }

    void render()
    {
        window.clear();
        player.draw(window);
        window.display();
    }
};