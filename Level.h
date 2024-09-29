/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#ifndef LEVEL_H
#define LEVEL_H

#include "FileProcessor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Mario.h"

class Level {
public:

    Level();              
    ~Level();                       

    char** generateLevel(FileProcessor* fileProcessor); 
    char** getLevelData();        

private:
    void placeObject(char objectType, int& count); // Function to place an object in the level
    void clearLevelData();          // Function to clear allocated memory for level data

    int columns;                
    int rows;                   
    char** levelData;             
    FileProcessor* fileProcessor; 
};

#endif // LEVEL_H
