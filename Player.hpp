#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML\System.hpp>

class Player
{
public:
    Player(std::string name);

    void move(float x, float y);
    void draw(sf::RenderWindow& window);

private:
    int spriteX;
    int spriteY;
    sf::Clock clock;
    sf::Texture texture;
    std::optional<sf::Sprite> sprite;
    std::string name;
    int hp;
    bool isMoving;
};
#endif