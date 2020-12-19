#include <iostream>
#include <stdlib.h>
#include <vector>

struct attack{
    std::string type;
    int damage;

    attack(std::string t, int dmg):
    type(t), damage(dmg) {}
};

struct player{
    std::string name;
    int health;
    int ac;
    int moveSpeed;
    int initiative;
    int xPos;
    int yPos;

    player(int x = 1, int y = 1, std::string n = " ", int h = 10, int a = 18, int mS = 6, int i = 0) :
        name(n), health(h), ac(a), moveSpeed(mS), initiative(i), xPos(x), yPos(y) {}
};

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

void lineBreak(){
    std::cout << "-------------------------------" << std::endl;
}

int main(){
    player p(1, 1, "Player");
    int xRange = 25;
    int yRange = 25;
    bool combat = true;
    int option = -1;
    std::vector<enemy> enArr;
    for(int i = 0; i < 1; i++){
        enArr.push_back(enemy(rand()%xRange+1, rand()%yRange+1, "testEnemy " + std::to_string(i)));
    }
    int turn(0);
    while(combat){
        std::cout << "-------------turn " << turn << "-------------" << std::endl;
        turn++;
        for(int i = 0; i < (int)enArr.size(); i++){
            std::cout << enArr[i].name << " at x: " << enArr[i].xPos << " , y: " << enArr[i].yPos << std::endl;
        }
        std::cout << "\nEnter option: ";
        std::cin >> option;
        switch (option) {
        case 1:{
            enArr[0].attacked(attack("Melee Attack", 2), p);
        }break;
        default:{
            std::cout << "You decide to defend\n" << std::endl;
        }break;
        }
        combat = false;
        for(int i = 0; i < (int)enArr.size(); i++){
            if(enArr[i].health > 0){
                combat = true;
                break;
            }
        }
        lineBreak();
    }

}


/*
 * PLAN!
 * Create battle field give x and y lenght
 * Array to hold enemies in battle
 * for loop how many enemies I want (edit later to take in data from txt randomly)
 * Create while with bool combat
 *      if(all enemies health is below 0) combat ends
 *      display enemies
 *      enemies take action
 *      enemies react to player action
*/
