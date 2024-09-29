/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#include "Mario.h"

const char HERO = 'H';        // Mario 
const char EMPTY = 'x';       // Empty
const char COIN = 'c';        // Coin
const char GOOMBA = 'g';      // Goomba
const char KOOPA = 'k';       // Koopa
const char MUSHROOM = 'm';    // Mushroom
const char BOSS = 'b';        // Boss
const char WARP_PIPE = 'w';   // Warp Pipe

// default constructor
Mario::Mario(){
    lives = 3;
    coinsNum = 0;
    enemyKillCount = 0;
    powerLevel = 0;
    marioRow = 0;
    marioCol = 0;
    direction = "STARTING POINT";
}

// deconstructor
Mario::~Mario(){}

// increases his number of coins
void Mario::addCoin(){
    coinsNum++;
}

// decreases a life
void Mario::loseLife(){
    if (lives > 0){
        lives--;
    }

    // game over
}

// increases a life
void Mario::gainLife(){
    lives++;
}

// increases power level
void Mario::increasePowerLevel(){
    powerLevel++;
}

void Mario::initialize(unsigned int randomSeed){
    // gets number of lives from fileProcessor
    lives = fileProcessor->getLives();

    // create a random seed
    srand(randomSeed);
    
    // use random seed to find startRow and startCol
    int maxRows = fileProcessor->getDimensions(); 
    int maxCols = fileProcessor->getDimensions(); 

    // generate a random row within the max number of rows
    marioRow = rand() % maxRows; 
    // generate a random column within the max number of columns
    marioCol = rand() % maxCols; 

}

// returns mario's location/coordinates
std::string Mario::printCoords(){
    return "Mario's Location: (" + std::to_string(marioCol + 1) + ", " + std::to_string(marioRow + 1) + ")";
}

// contains logic for killing enemies
void Mario::killingEnemies(){
    // if mario kills 7 enemies in the same life he gets a life
    enemyKillCount++;

    if (enemyKillCount == 7){
        gainLife();
        enemyKillCount = 0;
    }
}

// contains logic to move Mario
void Mario::moveMario() {
    int currentRow = marioRow;
    int currentCol = marioCol;
    int newRow = currentRow;
    int newCol = currentCol;
    
    int randomValueDirection = rand() % 4; // 0-3 for four directions
    
    switch(randomValueDirection) {
        case 0: // Right
            if (currentCol == fileProcessor->getDimensions() - 1) {
                newCol = 0; // wrap around to the left edge
            } else {
                newCol = currentCol + 1;
            }
            direction = "RIGHT";
            break;
        case 1: // Left
            if (currentCol == 0) {
                newCol = fileProcessor->getDimensions() - 1; // wrap around to the right edge
            } else {
                newCol = currentCol - 1;
            }
            direction = "LEFT";
            break;
        case 2: // Down
            if (currentRow == fileProcessor->getDimensions() - 1) {
                newRow = 0; // wrap around to the top edge
            } else {
                newRow = currentRow + 1;
            }
            direction = "DOWN";
            break;
        case 3: // Up
            if (currentRow == 0) {
                newRow = fileProcessor->getDimensions() - 1; // wrap around to the bottom edge
            } else {
                newRow = currentRow - 1;
            }
            direction = "UP";
            break;
    }
    
    // makes sure to only move if the new position is different than the current position
    if (newRow != currentRow || newCol != currentCol) {
        marioRow = newRow;
        marioCol = newCol;
    }
}

// getter methods
int Mario::getLives() const{
    return lives;
}

int Mario::getCoinsNum() const{
    return coinsNum;
}

int Mario::getEnemyKillCount() const{
    return enemyKillCount;
}

int Mario::getPowerLevel() const{
    return powerLevel;
}

int Mario::getMarioRow() const{
    return marioRow;
}

int Mario::getMarioCol() const{
    return marioCol;
}

std::string Mario::getDirection() const{
    return direction;
}

// setter methods
void Mario::setCoinsNum(int newCoinsNum){
    coinsNum = newCoinsNum;
}

void Mario::setPowerLevel(int newPowerLevel){
    powerLevel = newPowerLevel;
}

void Mario::setLives(int newLives){
    lives = newLives;
}
