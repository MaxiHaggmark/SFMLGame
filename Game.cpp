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
    std::string direction{"down"};

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
        bool moved = false;


        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            player.attack();

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
        {
            player.move(1.f, 0.f);  moved = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
        {
            player.move(-1.f, 0.f); moved = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
        {
            player.move(0.f, -1.f); moved = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S))
        {
            player.move(0.f, 1.f);  moved = true;
        }

        player.setMoving(moved);

        
    }

    void render()
    {
        window.clear();
        player.draw(window);
        window.display();
    }
};