#include <iostream>

struct attack{
    std::string type;
    int damage;
    int atkRange = 0;

    attack(std::string t, int dmg):
    type(t), damage(dmg) {}
};
