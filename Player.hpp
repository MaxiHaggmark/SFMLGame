#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML\System.hpp>

class Player
{
public:
    Player(std::string name);
    bool setMoving(bool a);
	bool getMoving() const;
    std::optional<sf::Sprite> getSprite() const;
    sf::Sprite* getSpritePtr();
    const sf::Sprite* getSpritePtr() const;
    bool setAttacking(bool a);
    void move(float x, float y);
    void draw(sf::RenderWindow& window);
    void attack();
    void setHp(int dmg);
    sf::IntRect calculateHealthBar();

private:
    std::vector<sf::IntRect> rightFrames;
    std::vector<sf::IntRect> leftFrames;
    std::vector<sf::IntRect> upFrames;
    std::vector<sf::IntRect> downFrames;
    std::vector<sf::IntRect> moveDownFrames;
    std::vector<sf::IntRect> moveLeftFrames;
    std::vector<sf::IntRect> moveRightFrames;
    std::vector<sf::IntRect> moveUpFrames;
    std::vector<sf::IntRect> attackDownFrames;
    std::vector<sf::IntRect> attackLeftFrames;
    std::vector<sf::IntRect> attackRightFrames;
    std::vector<sf::IntRect> attackUpFrames;

    int currentFrame = 0;
    int spriteX;
    std::string direction;
    int spriteY;
    sf::Clock clock;
    sf::Texture texture;
    sf::Texture healthBarTexture;
    sf::Texture attackingTexture;
    sf::Texture movingTexture;
    sf::Texture idleTexture;
    std::optional<sf::Sprite> healthBar;
    std::optional<sf::Sprite> sprite;
    std::string name;
    int hp = 100;
    bool isAttacking = false;
    bool isMoving;
    bool wasMoving = false;
};
#endif