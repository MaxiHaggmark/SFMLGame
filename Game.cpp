#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Weapon.hpp"
#include "Enemy.hpp"

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
    Enemy enemy{ "hej", 10};
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
        if (player.getSprite()->getPosition().x == enemy.getSprite()->getPosition().x - 2 && player.getSprite()->getPosition().y == enemy.getSprite()->getPosition().y - 2)
        {
            enemy.attack(player);
        }
        

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
        const float margin = 100.f;
        const float dx = player.getSprite()->getPosition().x - enemy.getSprite()->getPosition().x;
        const float dy = player.getSprite()->getPosition().y - enemy.getSprite()->getPosition().y;
        const float dist2 = dx * dx + dy * dy;

        if (!(dist2 <= margin * margin)) {
            enemy.move(player);
        }

        player.setMoving(moved);

        
    }

    void render()
    {
        window.clear();
        player.draw(window);
        enemy.draw(window);
        window.display();
    }
};