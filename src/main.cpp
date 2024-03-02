#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Encounter.hpp"

int main(int argc, char const *argv[])
{
    Encounter Combat;

    Member Zelie("Zélie", 5);
    Combat.addMember(Zelie);
    Member Tristepin("Tristepin", 5);
    Combat.addMember(Tristepin);
    
    
    Monster Pixie("Pixie", 50);
    Combat.addMonster(Pixie);
    Combat.addMonster(Pixie);
    Combat.addMonster(Pixie);
    Combat.addMonster(Pixie);
    Combat.addMonster(Pixie);
    Monster Quasit("Quasit", 200);
    Combat.addMonster(Quasit);

    std::cout<<"Members Px thresholds : "<<std::endl;
    std::vector<int> thresholds = Combat.getMemberList().computeAllMembersPx();
    std::cout<<thresholds[0]<<" "<<thresholds[1]<<" "<<thresholds[2]<<" "<<thresholds[3]<<std::endl;
    std::cout<<"Monsters Px : "<<Combat.getMonsterList().computeMonstersPx(Combat.getMemberList().getSize())<<std::endl;
    DifficType diffic = Combat.computeDifficulty();
    std::cout<<diffic._difficultyName<<std::endl;
    
    return 0;
}
