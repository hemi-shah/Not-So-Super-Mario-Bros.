/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include <random>
#include <ctime>
#include "FileProcessor.h"
#include "Level.h"

class Mario{
    public:
        Mario();
        ~Mario();

        FileProcessor* fileProcessor;

        int lives;
        int coinsNum;
        int enemyKillCount;
        int powerLevel;
        int marioRow;
        int marioCol;
        std::string direction;

        int getLives() const;
        int getCoinsNum() const;
        int getEnemyKillCount() const;
        int getPowerLevel() const;
        int getMarioRow() const;
        int getMarioCol() const;
        std::string getDirection() const;

        void addCoin();
        void loseLife();
        void gainLife();
        void increasePowerLevel();
        void initialize(unsigned int randomSeed); 
        void killingEnemies();
        void moveMario();
        std::string printCoords();

        void setCoinsNum(int newCoinsNum);
        void setPowerLevel(int newPowerLevel);
        void setLives(int newLives);

    private:

};

#endif