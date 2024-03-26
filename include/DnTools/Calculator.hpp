#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Encounter.hpp"

class Calculator{
    
    private:

        Encounter _encounter;
        // two lists used to store possible members and monster
        MemberList _memberStorage;
        MonsterList _monsterStorage;
    
    public:

        // todo : create constructor, run loop, add windows... ADD TO MAKEFILE, (switch to cmake ?)
        void run(); // launch main loop
};


#endif