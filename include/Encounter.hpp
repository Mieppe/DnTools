#ifndef ENCOUNTER_HPP
#define ENCOUNTER_HPP

#include <vector>
#include <string>

enum Difficulty {Easy = 1, Medium, Hard, Mortal};

struct EncounterMulti{
    int _monsterNb;
    float _multiplicator;
    EncounterMulti(int monsterNb, int multiplicator) : _monsterNb(monsterNb), _multiplicator(multiplicator) {};
};

std::vector<int> easyThresholds{0, 25, 50, 75, 125, 250, 300, 350, 450, 550, 600, 800, 1000, 1000, 1250, 1400, 1600, 2000, 2100, 2400, 2800};
std::vector<int> mediumThresholds{0, 50, 100, 150, 250, 500, 600, 750, 900, 1100, 1200, 1600, 2000, 2200, 2500, 2800, 3200, 2900, 4200, 4900, 5700};
std::vector<int> hardThresholds{0, 75, 150, 225, 375, 750, 900, 1100, 1400, 1600, 1900, 2400, 3000, 3400, 3800, 4300, 4800, 5900, 6300, 7300, 8500};
std::vector<int> mortalThresholds{0, 100, 200, 400, 500, 1100, 1400, 1700, 2100, 2400, 2800, 3600, 4500, 5100, 5700, 6400, 7200, 8800, 9500, 10900, 12700};
std::vector<EncounterMulti> encounterMultiTable{EncounterMulti(0, 0.5),
                                                EncounterMulti(1, 1), 
                                                EncounterMulti(2, 1.5), 
                                                EncounterMulti(3,2), 
                                                EncounterMulti(7, 2.5), 
                                                EncounterMulti(11, 3), 
                                                EncounterMulti(15, 4),
                                                EncounterMulti(999, 5)};

class Member{

    private:

        std::string _name;
        int _level;

    public:

        Member() : _name(" "), _level(0) {};
        Member(std::string name, int level) : _name(name), _level(level) {};
        int computePxThreshold(int difficulty) const;
};

class Monster{

    private:

        std::string _name;
        int _pxValue;

    public:

        Monster() : _name(" "), _pxValue(0) {};
        Monster(std::string name, int pxValue) : _name(name), _pxValue(pxValue) {};
        int getPxValue() const { return _pxValue; }
};

class MemberList{

    private:

        std::vector<Member> _members;

    public:

        MemberList() : _members(std::vector<Member>()) {};
        MemberList(std::vector<Member> list) : _members(list) {};
        void addMember(Member const member);
        int computeMembersPx(int difficulty) const;
};

class MonsterList{

    private:

        std::vector<Monster> _monsters;

    public:

        MonsterList() : _monsters(std::vector<Monster>()) {};
        MonsterList(std::vector<Monster> list): _monsters(list) {};
        void addMonster(Monster const monster);
        float computeMonstersPxMulti(int adventurerNb) const;
        float computeMonstersPx(int adventurerNb) const;
};

class Encounter{
    
    private:

        MemberList _memberList;
        MonsterList _monsterList;
    
    public:

        Encounter() : _memberList(MemberList()), _monsterList(MonsterList()) {};
        Encounter(MemberList memberList, MonsterList monsterList) : _memberList(memberList), _monsterList(monsterList) {};
        void setMemberList(MemberList const memberList) { _memberList = memberList; };
        void setMonsterList(MonsterList const monsterList) { _monsterList = monsterList; };
        void addMember(Member member);
        void addMonster(Monster monster);
        int computeDifficulty() const;
};


#endif