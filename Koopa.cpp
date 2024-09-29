/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#include "Koopa.h"

Koopa::Koopa(){}

Koopa::~Koopa(){}

// takes a random number and checks to see if it is less than or greater than 65
bool Koopa::koopaInteracts(int randomNumber){
    if (randomNumber < 65){ 
        return true;
    } else {
        return false;
    }
}