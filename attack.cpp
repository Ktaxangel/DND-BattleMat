#include <iostream>

struct attack{
    std::string type;
    int damage;

    attack(std::string t, int dmg):
    type(t), damage(dmg) {}
};
