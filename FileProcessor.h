/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>

class FileProcessor{
    public:
    FileProcessor(int levels, int dimensions, int lives, float coinsPercentage, float nothingPercentage, float goombaPercentage, float koopaPercentage, float mushroomPercentage);
    void processFile(std::string inputFile, std::string outputFile);
    int getLevels() const;
    int getDimensions() const;
    int getLives() const;
    float getCoinsPercentage() const;
    float getNothingPercentage() const;
    float getGoombaPercentage() const;
    float getKoopaPercentage() const;
    float getMushroomPercentage() const;

private:
    int levels;
    int dimensions;
    int lives;
    float coinsPercentage;
    float nothingPercentage;
    float goombaPercentage;
    float koopaPercentage;
    float mushroomPercentage;
};

#endif