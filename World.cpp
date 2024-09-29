/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#include "World.h"

World::World(FileProcessor* fp) : fileProcessor(fp), koopa(), goomba(), boss() {
    numLevels = fileProcessor->getLevels();
    numDimensions = fileProcessor->getDimensions();
    worldOfLevels = nullptr;  // initializes the level array as null
    currentInteraction = 'X';
    // mario pointer member variable
    mario = new Mario();
    // add current level member variable
    currentLevel = 0;
}

World::~World() {
    // cleans up the allocated worldOfLevels array 
    delete[] worldOfLevels;  // calls each level's destructor
    delete mario;
}

void World::initializeLevels() {
    worldOfLevels = new Level[numLevels];  // allocates the memory for all the levels
    
    for (int i = 0; i < numLevels; ++i) {
        // generates each level and stores it in the worldOfLevels array
        worldOfLevels[i].generateLevel(fileProcessor);
    }
    warpPipeDelete();
}

void World::writeLevel() {
    std::ofstream logFile("output.txt", std::ios_base::app);
    if (logFile.is_open()) {
        for (int i = 0; i < numLevels; ++i) {
            logFile << "Level " << i + 1 << ":" << std::endl;
            char** levelData = worldOfLevels[i].getLevelData();  // get the stored level data
            
            int coinCount = 0;
            int goombaCount = 0;
            int nothingCount = 0;
            int koopaCount = 0;
            int mushroomCount = 0;
            
            for (int j = 0; j < numDimensions; ++j) {
                for (int k = 0; k < numDimensions; ++k) {
                    char element = levelData[j][k];
                    logFile << element << " ";  
                    
                    // count occurrences of certain characters
                    if (element == 'c') {
                        coinCount++;
                    } else if (element == 'g') {
                        goombaCount++;
                    } else if (element == 'x') {
                        nothingCount++;
                    } else if (element == 'k') {
                        koopaCount++;
                    } else if (element == 'm') {
                        mushroomCount++;
                    }
                }
                logFile << std::endl;  // new line after each row
            }
            logFile << "Coins: " << coinCount << std::endl;
            logFile << "Goombas: " << goombaCount << std::endl;
            logFile << "Nothing: " << nothingCount << std::endl;
            logFile << "Koopas: " << koopaCount << std::endl;
            logFile << "Mushrooms: " << mushroomCount << std::endl;
            logFile << std::endl;  // empty line between levels
        }
        logFile.close();
    } else {
        std::cout << "Log file is not open" << std::endl;
    }
}

void World::printLevelWithMario() {
    std::ofstream logFile("output.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << "============================\n";
        for (int level = 0; level < numLevels; ++level) {
            logFile << "Level " << level + 1 << ":" << std::endl;
            char** levelData = worldOfLevels[level].getLevelData();

            int coinCount = 0;
            int goombaCount = 0;
            int nothingCount = 0;
            int koopaCount = 0;
            int mushroomCount = 0;

            for (int j = 0; j < numDimensions; ++j) {
                for (int k = 0; k < numDimensions; ++k) {
                    char element = levelData[j][k];
                    // only print Mario's position in the current level
                    if (level == currentLevel && j == mario->getMarioRow() && k == mario->getMarioCol()) {
                        logFile << 'H' << " ";
                    } else {
                        logFile << element << " ";
                    }

                    // counts the occurrences of interactions happening (excluding Mario's temporary position)
                    if (element == 'c') coinCount++;
                    else if (element == 'g') goombaCount++;
                    else if (element == 'x') nothingCount++;
                    else if (element == 'k') koopaCount++;
                    else if (element == 'm') mushroomCount++;
                }
                logFile << std::endl;
            }

            // Log the counts
            logFile << "Coins: " << coinCount << std::endl;
            logFile << "Goombas: " << goombaCount << std::endl;
            logFile << "Nothing: " << nothingCount << std::endl;
            logFile << "Koopas: " << koopaCount << std::endl;
            logFile << "Mushrooms: " << mushroomCount << std::endl;

            logFile << std::endl;
        }
        logFile.close();
    } else {
        std::cout << "Log file is not open" << std::endl;
    }
}

void World::playGame() {
    srand((unsigned int)time(0)); // seed the random number generator

    std::ofstream logFile("output.txt", std::ios_base::app);

    if (logFile.is_open()) {
        if (mario != nullptr) {
            mario->fileProcessor = this->fileProcessor;
            mario->initialize(rand() % 100);

            bool gameOver = false;
            int randomNumber;

            while (!gameOver) {
                logFile << "============================\n";
                logFile << "Mario Lives: " << mario->getLives() 
                        << " || Mario Power Level: " << mario->getPowerLevel() 
                        << " || Mario Coins: " << mario->getCoinsNum() << std::endl
                        << "Mario Direction: " << mario->getDirection()
                        << " || Mario Position: " << mario->printCoords()
                        << " || Mario Current Level: " << currentLevel + 1 << std::endl;

                // gets the current interaction
                char currentInteraction = getElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol());

                // processes each interaction mario has with all of the enemies and items
                switch (currentInteraction) {
                    case 'x': // empty space
                        logFile << "Mario moved into an empty space." << std::endl;
                        break;
                    case 'c': // handles mario collecting coins
                        mario->addCoin();
                        setElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol(), 'x');
                        logFile << "Mario picked up a coin!" << std::endl;
                        if (mario->getCoinsNum() % 20 == 0) {
                            mario->gainLife();
                            mario->setCoinsNum(mario->getCoinsNum() - 20);
                        }
                        break;
                    case 'm': // handles the mushroom power level increase
                        if (mario->getPowerLevel() < 2) {
                            mario->increasePowerLevel();
                        }
                        setElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol(), 'x');
                        logFile << "Mario picked up a mushroom and increased his power level!" << std::endl;
                        break;
                    case 'g': // handles the goomba encounters
                        logFile << "Mario encountered a Goomba!" << std::endl;
                        randomNumber = rand() % 100;
                        if (goomba.goombaInteracts(randomNumber)) {
                            mario->killingEnemies();
                            setElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol(), 'x');
                            logFile << "Mario defeated a Goomba!" << std::endl;
                        } else {
                            if (mario->getPowerLevel() > 0) {
                                mario->setPowerLevel(mario->getPowerLevel() - 1);
                                logFile << "Mario lost to a Goomba! His power level has decreased." << std::endl;
                            } else {
                                mario->loseLife();
                                logFile << "Mario lost a life! Remaining lives: " << mario->getLives() << std::endl;
                                if (mario->getLives() <= 0) {
                                    gameOver = true;
                                    logFile << "Game Over! Mario lost all lives : ( )." << std::endl;
                                }
                            }
                        }
                        break;
                    case 'k': // handles the koopa encounters
                        logFile << "Mario encountered a Koopa!" << std::endl;
                        randomNumber = rand() % 100;
                        if (koopa.koopaInteracts(randomNumber)) {
                            mario->killingEnemies();
                            setElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol(), 'x');
                            logFile << "Mario defeated a Koopa!" << std::endl;
                        } else {
                            if (mario->getPowerLevel() > 0) {
                                mario->setPowerLevel(mario->getPowerLevel() - 1);
                                logFile << "Mario lost to a Koopa! His power level has decreased." << std::endl;
                            } else {
                                mario->loseLife();
                                logFile << "Mario lost a life! Remaining lives: " << mario->getLives() << std::endl;
                                if (mario->getLives() <= 0) {
                                    gameOver = true;
                                    logFile << "Game Over! Mario lost all lives : ()." << std::endl;
                                }
                            }
                        }
                        break;
                    case 'b': // handles boss encounters
                        logFile << "Mario encountered a Boss!" << std::endl;
                        while (true) { // continue fighting the boss until mario wins or game over
                            randomNumber = rand() % 100;
                            if (boss.bossInteracts(randomNumber)) {
                                logFile << "Mario defeated the Boss!" << std::endl;
                                setElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol(), 'b');
                                // check if this is the last level
                                if (currentLevel == numLevels - 1) {
                                    logFile << "Mario beat the game! Congratulations he saved Peach!" << std::endl;
                                    gameOver = true;
                                } else {
                                    currentLevel++;
                                    mario->moveMario(); // moves mario to the next position
                                    printLevelWithMario(); // prints out the next level
                                }
                                break; // exit boss fight loop
                            } else {
                                logFile << "Mario lost to the boss : (." << std::endl;

                                // if Mario is at power level 2, reduce to power level 0 but don't lose a life
                                if (mario->getPowerLevel() == 2) {
                                    mario->setPowerLevel(0);
                                    logFile << "Mario lost to the boss! His power level is reduced to 0." << std::endl;
                                }
                                // if Mario is at power level 1 or 0, lose a life
                                else if (mario->getPowerLevel() <= 1) {
                                    mario->loseLife();
                                    logFile << "Mario lost a life! Remaining lives: " << mario->getLives() << std::endl;

                                    // check if Mario still has lives 
                                    if (mario->getLives() <= 0) {
                                        logFile << "Game over! Mario lost all his lives : ()." << std::endl;
                                        gameOver = true;
                                        break; // exit loop
                                    }
                                    // logs mario is going to fight the boss again
                                logFile << "Mario fights the boss again!" << std::endl;
                                }
                            }
                            // randomize again for next interaction if Mario needs to fight again
                            randomNumber = rand() % 100;
                        }
                        break;
                    case 'w': // handles logic regarding warp pipe
                        logFile << "Mario entered a warp pipe!" << std::endl;
                        if (currentLevel < numLevels - 1) {
                            // removes mario from the previous level
                            setElementAt(currentLevel, mario->getMarioRow(), mario->getMarioCol(), 'x');
                            currentLevel++;
                            logFile << "Mario warped to level: " << currentLevel + 1 << std::endl;
                        } else {
                            logFile << "Warp failed! Already at the last level." << std::endl;
                        }
                        break;
                }

                if (!gameOver){
                    printLevelWithMario();
                }

                // moves mario to another position after he interacts
                mario->moveMario();
            }
        }
        logFile.close();
    } else {
        std::cout << "Unable to open log file." << std::endl;
    }
}

void World::warpPipeDelete() {
    int lastLevel = numLevels - 1;
    char** levelData = worldOfLevels[lastLevel].getLevelData();

    for (int i = 0; i < numDimensions; ++i) {
        for (int j = 0; j < numDimensions; ++j) {
            if (levelData[i][j] == 'w') {
                levelData[i][j] = 'x';
            }
        }
    }
}

char World::getElementAt(int level, int row, int col) const {
    if (level < 0 || level >= numLevels || row < 0 || row >= numDimensions || col < 0 || col >= numDimensions) {
        throw std::out_of_range("Invalid coordinates");
    }
    
    // access the existing level data 
    char** levelData = worldOfLevels[level].getLevelData();
    return levelData[row][col];  // returns requested element
}

int World::getCurrentLevel(){
    return currentLevel;
}

void World::setElementAt(int level, int row, int col, char positionType) {
    if (level < 0 || level >= numLevels || row < 0 || row >= numDimensions || col < 0 || col >= numDimensions) {
        throw std::out_of_range("Invalid coordinates");
    }
    
    // access the stored level data and set the new element value
    char** levelData = worldOfLevels[level].getLevelData();
    levelData[row][col] = positionType;
}