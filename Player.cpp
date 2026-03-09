#include "Player.hpp"
#include <iostream>


Player::Player(std::string name_)
    : name{ name_ }, hp{ 100 }, isMoving{ false }
{
    texture.loadFromFile("idleplayer.png");
    spriteX = 19;
    spriteY = 20;
    sprite = sf::Sprite(texture, sf::IntRect({ spriteX, spriteY }, { 25, 25 }));
    sprite->setPosition({ 500.f, 500.f });
    sprite->setScale({3, 3});

}

void Player::draw(sf::RenderWindow& window)
{
    if (clock.getElapsedTime().asSeconds() >= 0.5f)
    {
        if (spriteX == 788)
        {
            spriteX = 19;
        }
        if (sprite) sprite->setTextureRect(sf::IntRect({ spriteX, spriteY }, { 25, 25 }));
        spriteX += 64;
        clock.restart();
    }
    if (sprite) window.draw(*sprite);
}

void Player::move(float x, float y)
{
    if (sprite) sprite->move({ x, y });
}