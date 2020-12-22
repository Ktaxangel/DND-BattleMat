#include <iostream>
#include <stdlib.h>
#include <vector>
#include <enemy.cpp>

void lineBreak(){
    std::cout << "-------------------------------" << std::endl;
}

int main(){


    player p(1, 1, "Player"); // default player
    int xRange = 25; // x range where actors can be randomly placed
    int yRange = 25; // y range where actors can be randomly placed
    int option = -1;
    std::vector<enemy> enArr; // holds all enemies in combat
    std::vector<player> plArr; // holds all players in combat
    std::vector<attack> attackStr = {}; // a universal carrier of all attacks

    plArr.push_back(p);
    for(int i = 0; i < 1; i++){ // will later read from a txt file with attributes of diffrent monsters, then will randomly assign them into the enemy array
        enArr.push_back(enemy(rand()%xRange+1, rand()%yRange+1, "testEnemy " + std::to_string(i)));
    }

    attackStr.push_back(attack("Slashing Attack", 1));
    attackStr.push_back(attack("Ranged Attack", 2));
    p.attacks.push_back(&attackStr[rand()%2]);

    int turnNum(0); // turn counter
    bool turn(false);
    bool combat = true; // start and ender of combat

    while(combat){
        /*
         * The turn should be displayed
         * (later) A grid will be draw with the enemies and players at their positions
         * (now) The enemies and players position are printed to the console
         *
         * (later) check initiatives then sort who goes first and continue
         *
         * (later) List out options for player to take
         * Option 1: Move
         * Option 2: Attack
         * Option 3: Defend
         *
         * (later) Turns play out
         */
        std::cout << "-------------turn " << turnNum << "-------------" << std::endl;
        turnNum++;

        for(int i = 0; i < (int)enArr.size(); i++){
            std::cout << enArr[i].name << " at x: " << enArr[i].xPos << " , y: " << enArr[i].yPos << std::endl;
        }

        /*
         * Print character options
         * Option 1: Move
         * * Ask for direction (ex. +- x, +- y).
         * *    If the absolute value of x+y added together is greater then the actors move speed then return a message saying so.
         * *    Also if the added value of the actors x passes further then the battle mat border return a message saying so.
         * * Modify players x and y pos
         * Option 2: Attack
         * * Check the enemies who are 1 away from you
         * Option 3: Defend
         */

        turn = true;
        while(turn){
            std::cout << "\nOptions:"
                         "\nOption 1: Move"
                         "\nOption 2: Attack"
                         "\nOption 3: Defend"
                         "\nOption 4: End Turn"
                         "\n:> ";
            std::cin >> option;

            switch(option) {
            case 1:{
                int x(0);
                int y(0);
                std::cout << "Enter x and y change" << std::endl;
                std::cout << "X + ";
                std::cin >> x;
                std::cout << "Y + ";
                std::cin >> y;
                while(!p.move(x,y,xRange,yRange)){
                    std::cout << "Enter new x and y change";
                    std::cout << "X + ";
                    std::cin >> x;
                    std::cout << "Y + ";
                    std::cin >> y;
                }
                std::cout << p.name << " now at x: "
                          << p.xPos << " \ty: "
                          << p.yPos << std::endl;
            }break;

            case 2:{
                if(p.attacked == false){
                    /*
                     * List of attacks the player has is displayed
                     * User chooses attack
                     * If no enemies are withing attacks range
                     * send to console "no enemies in attack reach"
                     * Send to console "attack who?"
                     * then display enemies that are within attack range
                     * User then chooses enemy
                     *
                    */
                    p.attacked = true;
                }
                else{std::cout << "You've already attacked!" << std::endl;}

            }break;

            case 3:{

            }break;

            case 4:{
                std::cout << p.name << " Ended thier turn";
                turn = false;
                p.turnEnd();
            }break;

            default:{
                turn = false;
            }
            }
        }

        std::cout << "\nEnter option: \n:> ";
        std::cin >> option;

        switch (option) {
        case 1:{
            enArr[0].attacked(*p.attacks[0], p);
            enArr[0].attacked(attack("test attack", 1), p);
        }break;
        default:{
            std::cout << "You decide to defend\n" << std::endl;
        }break;
        }

        // Check if all enemies are dead, if one is alive combat continues
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


// have a static int that will add a number to the end of each enemy that way i can find where they belong in the array
