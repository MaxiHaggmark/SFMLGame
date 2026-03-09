#include "Player.hpp"
#include <iostream>
#include <cctype>


Player::Player(std::string name_)
    : name{ name_ }, hp{ 100 }, isMoving { false }
{
    idleTexture.loadFromFile("idleplayer.png");
    attackingTexture.loadFromFile("attackingplayer.png");
    movingTexture.loadFromFile("movingplayer.png");
    texture.loadFromFile("idleplayer.png");
    direction = "down";
    spriteX = 19;
    spriteY = 20;
    sprite = sf::Sprite(texture, sf::IntRect({ spriteX, spriteY }, { 25, 25 }));
    sprite->setPosition({ 500.f, 500.f });
    sprite->setScale({3, 3});
    //Idleframes
    downFrames = {
    sf::IntRect({19,20},{20,28}),  sf::IntRect({83,20},{20,28}),
    sf::IntRect({147,20},{20,28}), sf::IntRect({211,20},{20,28}),
    sf::IntRect({275,20},{20,28}), sf::IntRect({340,20},{19,28}),
    sf::IntRect({404,20},{19,28}), sf::IntRect({468,20},{19,28}),
    sf::IntRect({532,20},{19,28}), sf::IntRect({596,20},{19,28}),
    sf::IntRect({660,20},{19,28}), sf::IntRect({724,20},{19,28}),
    };

    leftFrames = {
        sf::IntRect({22,83},{17,28}),  sf::IntRect({86,83},{17,28}),
        sf::IntRect({150,83},{17,28}), sf::IntRect({214,83},{17,28}),
        sf::IntRect({278,83},{17,28}), sf::IntRect({343,83},{16,28}),
        sf::IntRect({407,83},{16,28}), sf::IntRect({471,83},{16,28}),
        sf::IntRect({535,83},{16,28}), sf::IntRect({599,83},{16,28}),
        sf::IntRect({663,83},{16,28}), sf::IntRect({727,83},{16,28}),
    };

    rightFrames = {
        sf::IntRect({24,147},{16,28}),  sf::IntRect({88,147},{16,28}),
        sf::IntRect({152,147},{16,28}), sf::IntRect({216,147},{16,28}),
        sf::IntRect({280,147},{16,28}), sf::IntRect({344,147},{16,28}),
        sf::IntRect({408,147},{15,28}), sf::IntRect({472,147},{16,28}),
        sf::IntRect({536,147},{15,28}), sf::IntRect({600,147},{16,28}),
        sf::IntRect({664,147},{15,28}), sf::IntRect({728,147},{16,28}),
    };

    upFrames = {
        sf::IntRect({24,212},{20,27}), sf::IntRect({89,212},{19,27}),
        sf::IntRect({153,212},{19,27}), sf::IntRect({217,212},{19,27}),
    };

    //Move frames
    moveDownFrames = {
    sf::IntRect({20,19},{19,29}),  sf::IntRect({84,19},{19,29}),
    sf::IntRect({148,19},{19,29}), sf::IntRect({213,19},{19,29}),
    sf::IntRect({278,19},{18,29}), sf::IntRect({342,19},{18,29}),
    };
    moveLeftFrames = {
        sf::IntRect({24,81},{15,30}),  sf::IntRect({87,81},{16,30}),
        sf::IntRect({150,81},{17,30}), sf::IntRect({215,81},{16,30}),
        sf::IntRect({279,81},{16,30}), sf::IntRect({343,81},{16,30}),
    };
    moveRightFrames = {
        sf::IntRect({24,145},{16,30}), sf::IntRect({88,145},{17,30}),
        sf::IntRect({153,145},{17,30}),sf::IntRect({216,145},{17,30}),
        sf::IntRect({280,145},{17,30}),sf::IntRect({344,145},{17,30}),
    };
    moveUpFrames = {
        sf::IntRect({24,210},{18,29}), sf::IntRect({88,210},{19,29}),
        sf::IntRect({152,210},{19,29}),sf::IntRect({216,210},{20,29}),
        sf::IntRect({280,210},{20,29}),sf::IntRect({345,210},{18,29}),
    };

    //Walk attack
    attackDownFrames = {
    sf::IntRect({16,19},{23,37}),  sf::IntRect({80,19},{25,37}),
    sf::IntRect({145,19},{34,37}), sf::IntRect({209,19},{33,37}),
    sf::IntRect({279,19},{23,37}), sf::IntRect({345,19},{15,37}),
    };
    attackLeftFrames = {
        sf::IntRect({24,80},{16,32}),  sf::IntRect({83,80},{20,32}),
        sf::IntRect({137,80},{30,32}), sf::IntRect({201,80},{29,32}),
        sf::IntRect({271,80},{24,32}), sf::IntRect({340,80},{19,32}),
    };
    attackRightFrames = {
        sf::IntRect({16,144},{23,32}), sf::IntRect({79,144},{28,32}),
        sf::IntRect({152,144},{31,32}),sf::IntRect({216,144},{31,32}),
        sf::IntRect({280,144},{25,32}),sf::IntRect({338,144},{23,32}),
    };
    attackUpFrames = {
        sf::IntRect({23,204},{23,36}), sf::IntRect({88,204},{26,36}),
        sf::IntRect({140,204},{35,36}),sf::IntRect({208,204},{33,36}),
        sf::IntRect({274,204},{24,36}),sf::IntRect({345,204},{15,36}),
    };
}

void Player::draw(sf::RenderWindow& window)
{
    if (wasMoving != isMoving)
    {
        currentFrame = 0;
        wasMoving = isMoving;
    }

    if (clock.getElapsedTime().asSeconds() >= 0.15f)
    {
        std::vector<sf::IntRect>* frames;


        if (isAttacking)
        {
            if (sprite) sprite->setTexture(attackingTexture);
            if (direction == "right")       frames = &attackRightFrames;
            else if (direction == "left")   frames = &attackLeftFrames;
            else if (direction == "up")     frames = &attackUpFrames;
            else                            frames = &attackDownFrames;
        }
        else if (isMoving)
        {
            if (sprite) sprite->setTexture(movingTexture);
            if (direction == "right")       frames = &moveRightFrames;
            else if (direction == "left")   frames = &moveLeftFrames;
            else if (direction == "up")     frames = &moveUpFrames;
            else                            frames = &moveDownFrames;
        }
        else
        {
            if (sprite) sprite->setTexture(idleTexture);
            if (direction == "right")       frames = &rightFrames;
            else if (direction == "left")   frames = &leftFrames;
            else if (direction == "up")     frames = &upFrames;
            else                            frames = &downFrames;
        }

        currentFrame = (currentFrame + 1) % frames->size();
        if (isAttacking && currentFrame == 0)
            isAttacking = false;
        if (sprite) sprite->setTextureRect((*frames)[currentFrame]);
        clock.restart();

    }
    if (sprite) window.draw(*sprite);
}

void Player::attack()
{
    if (!isAttacking)
    {
        isAttacking = true;
        currentFrame = 0;
    }
}
void Player::move(float x, float y)
{
    if (x > 0) direction = "right";
    else if (x < 0) direction = "left";
    else if (y < 0) direction = "up";
    else if (y > 0) direction = "down";

    if (sprite) sprite->move({ x, y });
}

bool Player::setMoving(bool a)
{
    return isMoving = a;
}

bool Player::getMoving() const
{
    return isMoving;
}

bool Player::setAttacking(bool a)
{
    return isAttacking = a;
}