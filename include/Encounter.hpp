#ifndef ENCOUNTER_HPP
#define ENCOUNTER_HPP

#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct EncounterMulti{
    int _monsterNb;
    float _multiplicator;
    EncounterMulti(int monsterNb, float multiplicator) : _monsterNb(monsterNb), _multiplicator(multiplicator) {};
};

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