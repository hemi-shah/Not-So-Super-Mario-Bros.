/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#include <iostream>
#include "FileProcessor.h"
#include "World.h"
#include "Mario.h"
#include "Level.h"

int main() {
    // initializes a fileProcessor with default values
    FileProcessor fileProcessor(0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0);
    
    // takes "spec.txt" as the inputFile to be processed
    std::string inputFile = "spec.txt";
    // takes "output.txt" as the inputFile to be processed
    std::string outputFile = "output.txt";
    fileProcessor.processFile(inputFile, outputFile);
    
    // initializes a world object with the processed data
    World world(&fileProcessor);
    
    // initializese the levels in world
    world.initializeLevels();
    
    // writes the levels in world
    world.writeLevel();
    
    // invokes playGame which starts the game
    world.playGame();

    return 0;
}