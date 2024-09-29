/*
 * Full names: Hemi Shah & Irene Ichwan
 * Student IDs: 2443456 & 2452538
 * Chapman emails: heshah@chapman.edu & ichwan@chapman.edu
 * Course number and section: CPSC-350_03
 * Assignment or exercise number: PA2: Not So Super Mario Bros.
 */

#ifndef KOOPA_H
#define KOOPA_H

#include <iostream>
#include <ctime>
#include <random>
#include "Mario.h"

class Koopa {
    private:

    public:
        Koopa();
        ~Koopa();
        bool koopaInteracts(int randomNumber);
};

#endif