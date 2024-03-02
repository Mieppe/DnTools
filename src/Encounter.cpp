#include "Encounter.hpp"

// ****************************************************************************
//                              tools
// **************************************************************************** 

enum Difficulty {Easy = 1, Medium, Hard, Mortal};
std::vector<int> easyThresholds{0, 25, 50, 75, 125, 250, 300, 350, 450, 550, 600, 800, 1000, 1000, 1250, 1400, 1600, 2000, 2100, 2400, 2800};
std::vector<int> mediumThresholds{0, 50, 100, 150, 250, 500, 600, 750, 900, 1100, 1200, 1600, 2000, 2200, 2500, 2800, 3200, 2900, 4200, 4900, 5700};
std::vector<int> hardThresholds{0, 75, 150, 225, 375, 750, 900, 1100, 1400, 1600, 1900, 2400, 3000, 3400, 3800, 4300, 4800, 5900, 6300, 7300, 8500};
std::vector<int> mortalThresholds{0, 100, 200, 400, 500, 1100, 1400, 1700, 2100, 2400, 2800, 3600, 4500, 5100, 5700, 6400, 7200, 8800, 9500, 10900, 12700};
std::vector<EncounterMulti> encounterMultiTable{EncounterMulti(0, 0.5),
                                                EncounterMulti(1, 1), 
                                                EncounterMulti(2, 1.5), 
                                                EncounterMulti(3, 2), 
                                                EncounterMulti(7, 2.5), 
                                                EncounterMulti(11, 3), 
                                                EncounterMulti(15, 4),
                                                EncounterMulti(999, 5)};

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
    if(adventurerNb <3){
        multOffset = 1;
        std::cout<<"multoffset : "<<multOffset<<std::endl;
    }
    else if(adventurerNb >= 6) multOffset = -1;
    int monsterNb = _monsters.size();
    if(monsterNb == 0) return 0;
    for(int i = 0; i < int(encounterMultiTable.size()); i++){
        if(monsterNb >= encounterMultiTable[i]._monsterNb){
            std::cout<<" i : "<<i<<" multoffset : "<<multOffset<<std::endl;
            std::cout<<"encountertable : "<<encounterMultiTable[i]._multiplicator<<std::endl;
            std::cout<<"encountertableoffeted : "<<encounterMultiTable[i + multOffset]._multiplicator<<std::endl;
            std::cout<<"encounter monster number "<<encounterMultiTable[i]._monsterNb<<std::endl;
            std::cout<<"encounter monster number offseted "<<encounterMultiTable[i + multOffset]._monsterNb<<std::endl;
            multiplicator = encounterMultiTable[i + multOffset]._multiplicator;
        }
    }
    return multiplicator;
}

float MonsterList::computeMonstersPx(int adventurerNb) const{
    float multiplicator = computeMonstersPxMulti(adventurerNb);
    // WIP
    return multiplicator; // to delete, only to compile
}

// ****************************************************************************
//                              ENCOUNTER
// **************************************************************************** 

void Encounter::addMember(Member member){
    return; // wip
}

void Encounter::addMonster(Monster monster){
    return; // wip
}

int Encounter::computeDifficulty() const{
    return 0; // wip
}