#include <iostream>
#include <vector>
#include <attack.cpp>
#include <cmath>

struct player{
    /*
     * After some testing I think I should add temps to some of these.
     * Like moveSpeed so they can't infinitly move and then I can reset the temp move speed after his turn.
     */
    std::string name;
    int health;
    int bHealth;
    int ac;
    int moveSpeed;
    int tempMS;
    int initiative;
    int xPos;
    int yPos;
    bool attacked = false;
    std::vector<attack*> attacks = {};

    player(int x = 1, int y = 1, std::string n = " ", int h = 10, int a = 18, int mS = 6, int i = 0) :
        name(n), health(h), ac(a), moveSpeed(mS), initiative(i), xPos(x), yPos(y) {bHealth = health; tempMS = moveSpeed;}

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
        if(x == y){
            tempMS -= (abs(x) + abs(y))/2;
        }else {tempMS -= (abs(x) + abs(y));}

        std::cout << "You have " << tempMS << " Spaces of movement left" << std::endl;
        return true;
    }

    void turnEnd(){
        tempMS = moveSpeed;
    }
};
