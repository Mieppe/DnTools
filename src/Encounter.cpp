#include "Encounter.hpp"

// ****************************************************************************
//                              MEMBER
// ****************************************************************************                

int Member::computePxThreshold(int difficulty) const {
    std::vector<int> thresholds;
    switch(difficulty)
    {
    case Easy:
        thresholds = easyThresholds;
        break;
    case Medium:
        thresholds = mediumThresholds;
        break;
    case Hard:
        thresholds = hardThresholds;
        break;
    case Mortal:
        thresholds = mortalThresholds;
        break;
    default:
        thresholds = easyThresholds;
        break;
    }
    return thresholds[_level];
}

// ****************************************************************************
//                              MEMBER LIST
// ****************************************************************************     

void MemberList::addMember(Member const member){
    _members.push_back(member);
}

int MemberList::computeMembersPx(int difficulty) const {
    float groupTh = 0;
    for(auto member : _members){
        groupTh += member.computePxThreshold(difficulty);
    }
    return groupTh;
}

// ****************************************************************************
//                              MONSTER LIST
// **************************************************************************** 

void MonsterList::addMonster(Monster const monster){
    _monsters.push_back(monster);
}

float MonsterList::computeMonstersPxMulti(int adventurerNb) const{
    float multiplicator = 0;
    int multOffset = 0;
    if(adventurerNb <3) multOffset = -1;
    else if(adventurerNb >= 6) multOffset = 1;
    int monsterNb = _monsters.size();
    if(monsterNb == 0) return 0;
    for(int i = 0; i < encounterMultiTable.size(); i++){
        if(monsterNb >= encounterMultiTable[i]._monsterNb){
            multiplicator = encounterMultiTable[i + multOffset]._multiplicator;
        }
    }
    return multiplicator;
}

float MonsterList::computeMonstersPx(int adventurerNb) const{
    float multiplicator = computeMonstersPxMulti(adventurerNb);
    // WIP
}
