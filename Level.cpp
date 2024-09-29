/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#include "Level.h"

Level::Level() {
    columns = 0;
    rows = 0;
    // initalize the level grid
    levelData = nullptr;
    // initialize fileProcessor
    fileProcessor = nullptr;
}

Level::~Level() {
    // use a helper method to clean up/deallocate the level grid
    clearLevelData();
}

// a helper method that  cleans up/deallocates the level grid
void Level::clearLevelData() {
    // clean up/deallocate memory
    if (levelData) {
        for (int i = 0; i < rows; ++i) {
            delete[] levelData[i];
        }
        delete[] levelData;
        levelData = nullptr; 
    }
}

// places a specified number of chars in random empty slots, represented by 'X', on the level's grid until count is 0
void Level::placeObject(char objectType, int& count) {
    while (count > 0) {
        int row = rand() % rows;
        int col = rand() % columns;
        if (levelData[row][col] == 'x') { // only places the char into empty slots
            levelData[row][col] = objectType;
            --count; // decrements the count if the char was successfully placed
        }
    }
}

char** Level::generateLevel(FileProcessor* fileProcessor) {
    // initializes the fileProcessor pointer
    this->fileProcessor = fileProcessor;

    // reads the dimensions and number of levels from fileProcessor
    columns = fileProcessor->getDimensions();
    rows = fileProcessor->getDimensions();
    // reads the number of levels to generate from fileProcessor
    int numLevels = fileProcessor->getLevels();

        // clears previous level data
        clearLevelData();

        /* BEGINNING OF CODE FROM TUTORING WITH OWEN GLIDEWELL */
        /* He did not write code for me, we talked it through and came up with it together*/

        // creates a 2D array for level data
        levelData = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            levelData[i] = new char[columns];
            for (int j = 0; j < columns; ++j) {
                levelData[i][j] = 'x'; // Initialize with ' ' (empty spaces)
            }
        }
        /* END OF CODE FROM TUTORING WITH OWEN GLIDEWELL */

        // calculate the percentage of each object from fileProcessor
        int totalCells = columns * rows;
        int numCoins = (fileProcessor->getCoinsPercentage() * totalCells) / 100;
        int numNothing = (fileProcessor->getNothingPercentage() * totalCells) / 100;
        int numGoombas = (fileProcessor->getGoombaPercentage() * totalCells) / 100; 
        int numKoopas = (fileProcessor->getKoopaPercentage() * totalCells) / 100; 
        int numMushrooms = (fileProcessor->getMushroomPercentage() * totalCells) / 100; 
        int numBosses = 1; // Exactly one boss per level
        int numWarpPipes = 1;

        // place each object type
        placeObject('c', numCoins);  // Coins
        placeObject('x', numNothing);  // Empty 
        placeObject('g', numGoombas);  // Goombas
        placeObject('k', numKoopas);  // Koopas
        placeObject('m', numMushrooms);  // Mushrooms

        // place the boss in a random position as long as it's emtpy
        bool bossPlaced = false;
        while (!bossPlaced) {
            int bossRow = rand() % rows;
            int bossCol = rand() % columns;
            if (levelData[bossRow][bossCol] == 'x') { 
                levelData[bossRow][bossCol] = 'b';
                bossPlaced = true;
            }
        }

        // place the warp pipe in a random position as long as it's emtpy
        bool warpPlaced = false;
        while (!warpPlaced) {
            int warpRow = rand() % rows;
            int warpCol = rand() % columns;
            if (levelData[warpRow][warpCol] == 'x') {
                levelData[warpRow][warpCol] = 'w';
                warpPlaced = true;
            }
        }

    // returns the last generated level data
    return levelData;
}

// getter method
char** Level::getLevelData() {
    return levelData;
}
