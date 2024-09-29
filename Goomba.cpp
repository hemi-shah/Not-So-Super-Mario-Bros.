/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#include "Goomba.h"

Goomba::Goomba(){}

Goomba::~Goomba(){}

// takes a random number and checks to see if it is less than or greater than 80
bool Goomba::goombaInteracts(int randomNumber){
    if (randomNumber < 80){
        return true;
    } else { 
        return false;
    }
}