/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <fstream>
#include "Level.h"
#include "FileProcessor.h"
#include "Mario.h"
#include "Koopa.h"
#include "Goomba.h"
#include "Boss.h"

class World {
private:
// nothing private
public:
    int numLevels; //read from spec.txt file
    int numDimensions;
    Level* worldOfLevels; // 1D array of levels
    FileProcessor* fileProcessor; // 
    Mario* mario;
    char currentInteraction;
    int currentLevel;
    // objects
    Koopa koopa;
    Goomba goomba;
    Boss boss;
    // constructor that initializes world with fileprocessor object
    World(FileProcessor* fp);
    ~World();

    // initializes levels and populates world
    void initializeLevels();
    // writes level to file
    void writeLevel();
    // writes world to file
    void writeWorld();
    // prints level with mario's position
    void printLevelWithMario();
    // game loop where logic is executed for enemy and item interactions
    void playGame();
    // deletes the warp pipe once mario uses it
    void warpPipeDelete();
    // returns mario at his position
    char getElementAt(int level, int row, int col) const;
    // returns index of level mario is currently in
    int getCurrentLevel();
    // updates element at position in level
    void setElementAt(int level, int row, int col, char positionType);
};

#endif