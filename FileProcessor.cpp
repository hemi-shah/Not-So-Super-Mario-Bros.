#include "FileProcessor.h"

// default constructor, sets all member variable values to 0
FileProcessor::FileProcessor(int levels, int dimensions, int lives, float coinsPercentage, float nothingPercentage, float goombaPercentage, float koopaPercentage, float mushroomPercentage) {
    this->levels = levels; // Assigning constructor parameters to member variables
    this->dimensions = dimensions;
    this->lives = lives;
    this->coinsPercentage = coinsPercentage;
    this->nothingPercentage = nothingPercentage;
    this->goombaPercentage = goombaPercentage;
    this->koopaPercentage = koopaPercentage;
    this->mushroomPercentage = mushroomPercentage;
}

void FileProcessor::processFile(std::string inputFile, std::string outputFile) {
    // creates an input file stream object named inFile with inputFile being the file to read from
    std::ifstream inFile(inputFile);

    // checks to see if the input file is open
    if (inFile.is_open()) {
        // creates an output file stream object named outFile with outputFile being the file to output to, truncating the file
        std::ofstream outFile(outputFile, std::ios::trunc); 
        
        // checks to see if outFile is open and reads all of the variables accordingly
        if (outFile.is_open()) {
            std::string line;

            // reads the first line, converts it to an int, and stores it in the levels variable
            if (std::getline(inFile, line)) {
                levels = std::stoi(line);
            }

            // reads the second line, converts it to an int, and stores it in the dimensions variable
            if (std::getline(inFile, line)) {
                dimensions = std::stoi(line);
            }

            // reads the third line, converts it to an int, and stores it in the lives variable
            if (std::getline(inFile, line)) {
                lives = std::stoi(line); 
            }

            // reads the fourth line, converts it to a float, and stores it in the coinsPercentage variable
            if (std::getline(inFile, line)) {
                coinsPercentage = std::stof(line);
            }

            // reads the fifth line, converts it to a float, and stores it in the nothingPercentage variable
            if (std::getline(inFile, line)) {
                nothingPercentage = std::stof(line); 
            }

            // reads the sixth line, converts it to a float, and stores it in the goombaPercentage variable
            if (std::getline(inFile, line)) {
                goombaPercentage = std::stof(line);
            }

            // reads the seventh line, converts it to a float, and stores it in the koopaPercentage variable
            if (std::getline(inFile, line)) {
                koopaPercentage = std::stof(line);
            }

            // reads the eighth line, converts it to a float, and stores it in the mushroomPercentage variable
            if (std::getline(inFile, line)) {
                mushroomPercentage = std::stof(line);
            }

            // checks to see if the total percentages add up to 100%
            float totalPercentage = coinsPercentage + nothingPercentage + goombaPercentage + koopaPercentage + mushroomPercentage;
            if (totalPercentage != 100.0) {
                outFile << "The percentages MUST sum up to 100%!" << std::endl;
                return;
            }

            // closes the output file
            outFile.close();

        } else {
            std::cout << "Unable to open output file" << std::endl;
        }

        // closes the input file
        inFile.close(); // Close the input file
    } else {
        std::cout << "Unable to open input file" << std::endl;
    }
}

// getter methods to access the stored values
int FileProcessor::getLevels() const {
    return levels;
}

int FileProcessor::getDimensions() const {
    return dimensions;
}

int FileProcessor::getLives() const {
    return lives;
}

float FileProcessor::getCoinsPercentage() const {
    return coinsPercentage;
}

float FileProcessor::getNothingPercentage() const {
    return nothingPercentage;
}

float FileProcessor::getGoombaPercentage() const {
    return goombaPercentage;
}

float FileProcessor::getKoopaPercentage() const {
    return koopaPercentage;
}

float FileProcessor::getMushroomPercentage() const {
    return mushroomPercentage;
}
