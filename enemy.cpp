#include <player.cpp>

struct enemy{
    std::string name;
    int health;
    int ac;
    int moveSpeed;
    int initiative;
    int xPos;
    int yPos;

    enemy(int x = 1, int y = 1, std::string n = " ", int h = 4, int a = 10, int mS = 6, int i = 0) :
        name(n), health(h), ac(a), moveSpeed(mS), initiative(i), xPos(x), yPos(y) {}

    void attacked(attack a, player p){
        std::cout << name << " attacked by " << p.name << " with a " << a.type << std::endl;
        health -= a.damage;
        std::cout << name << " received " << a.damage << " damage\n" << name << " HP: " << health << std::endl << std::endl;
    }
};
