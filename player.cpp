#include <iostream>
#include <vector>
#include <attack.cpp>
#include <cmath>

struct player{
    std::string name;
    int health;
    int ac;
    int moveSpeed;
    int initiative;
    int xPos;
    int yPos;
    std::vector<attack*> attacks = {};

    player(int x = 1, int y = 1, std::string n = " ", int h = 10, int a = 18, int mS = 6, int i = 0) :
        name(n), health(h), ac(a), moveSpeed(mS), initiative(i), xPos(x), yPos(y) {}

    bool move(int x, int y, int xRange, int yRange){
        // Maybe I should make a battle mat structure or just keep these range locations how they are
        if (abs(x) + abs(y) > moveSpeed){
            return false;
        }
        if (x + xPos > xRange || x + xPos < 0 || y + yPos > yRange || y + yPos < 0){
            return false;
        }
        xPos += x;
        yPos += y;
        return true;
    }
};
