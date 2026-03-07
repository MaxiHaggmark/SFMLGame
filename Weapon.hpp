#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon
{
public:
    Weapon(std::string name, int damage);
    void swing();

private:
    std::string name;
    int damage;
};

#endif