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

    player(int x = 1, int y = 1, std::string n = " ",
           int h = 10, int a = 18, int mS = 6, int i = 0) :
        name(n), health(h), ac(a), moveSpeed(mS), initiative(i),
        xPos(x), yPos(y) {bHealth = health; tempMS = moveSpeed;}

    bool move(int x, int y, int xRange, int yRange){
        // Maybe I should make a battle mat structure,
        // or just keep these range locations how they are
        int xHold(abs(x));
        int yHold(abs(y));
        int counter(0);

        bool checked = false;
        while(!checked){
            while(xHold > yHold){
                xHold--;
                counter++;
            }
            while(yHold > xHold){
                yHold--;
                counter++;
            }
            if(xHold == yHold){
                counter += (xHold + yHold) / 2;
                checked = true;
            }
        }
        if(counter > tempMS){
            std::cout << "Thats to far of a move!" << std::endl;
            return false;
        }

        if (x + xPos > xRange || x + xPos < 0 || y + yPos > yRange || y + yPos < 0){
            std::cout << "Moving out of comabat!" << std::endl;
            return false;
        }

        xPos += x;
        yPos += y;

        tempMS -= counter;

        std::cout << "You have " << tempMS << " Spaces of movement left" << std::endl;
        return true;
    }

    void turnEnd(){
        tempMS = moveSpeed;
    }
};
