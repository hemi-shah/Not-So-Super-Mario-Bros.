# Not-So-Super-Mario-Bros.
A complex Super Mario simulation built using data structures where Mario navigates through 3D levels, interacting with the game world and completing objectives.

## Identifying Information: 
Full name: Hemi Shah & Irene Ichwan
Student ID: 2443456 & 2452538
Chapman Email: heshah@chapman.edu & ichwan@chapman.edu
Course number and section: CPSC-350-03
Assignment or exercise number: PA2: Not So Super Mario Bros.

## Project Description
This project demonstrates my proficiency in data structures and algorithms, with a focus on arrays, as well as my ability to develop a program in C++. 
The simulation of Super Mario involves reading from an input file, processing the data, and executing the game’s functionalities, with results written to an output file. 
Mario navigates through each level of the world, represented by the depth of a 3D array, interacting with his surroundings based on various conditions and cases. 
The objective is for Mario to complete all levels and save the Princess, thereby concluding the game.

## Key Features
- File Input/Output: Reads game data from an input file to set up the world and outputs results and game progress to a specified output file.
- 3D World Representation: Levels of the game are structured in a 3D array, where each depth represents a new level for Mario to navigate.
- Mario’s Movement: Mario moves through levels and interacts with the game environment based on conditions, including item collection and enemy encounters.
- Health and Damage System: Tracks Mario’s health and damage when interacting with enemies, affecting his ability to progress through levels.
- Level Completion: The player guides Mario through each level until all levels are completed and the Princess is saved.
- Dynamic Game Elements: Mario’s state and the game world update in real-time as Mario interacts with enemies, items, and level hazards.

## Files
1. Boss.cpp
2. Boss.h
3. FileProcessor.cpp
4. FileProcessor.h
5. Goomba.cpp
6. Goomba.h
7. Koopa.cpp
8. Koopa.h
9. Level.cpp
10. Level.h
11. Main.cpp
12. main.exe
13. Mario.cpp
14. Mario.h
15. World.cpp
16. World.h
17. output.txt
18. spec.txt
19. README.md

## Known Error 
- There are no known errors in this program.

## References
- Co-developed this project with Irene Ichwan
- Received debugging help from Owen Glidewell and Annika Brown from the Chapman TLC
- Received additional debugging help from Dr.EEL

## Running Instructions
- To compile:     g++ *.cpp -o ./main.exe
- To run:         ./main.exe
