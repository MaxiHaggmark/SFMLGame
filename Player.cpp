#include "Player.hpp"

Player::Player(std::string name_)
    : name{ name_ }, hp{ 100 }, isMoving{ false }
{
    texture.loadFromFile("player.png");
    sprite = sf::Sprite(texture, sf::IntRect({ 10, 10 }, { 32, 32 }));
    sprite->setPosition({ 500.f, 500.f });
}

void Player::draw(sf::RenderWindow& window)
{
    if (sprite) window.draw(*sprite);
}

void Player::move(float x, float y)
{
    if (sprite) sprite->move({ x, y });
}