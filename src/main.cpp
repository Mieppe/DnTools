#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Encounter.hpp"

int main(int argc, char const *argv[])
{
    std::cout<<"Hello World !!"<<std::endl;

    MonsterList mList(std::vector<Monster>{Monster("Moche", 10),
                                        Monster("moche2", 50),
                                        Monster("jf", 3), 
                                        Monster("hfhf", 4), 
                                        Monster("k", 5), 
                                        Monster("hh", 6), 
                                        Monster("hh", 7),
                                        Monster("hh", 8),
                                        Monster("h", 9),
                                        Monster("jj", 10),
                                        Monster("k", 11),
                                        Monster("kkj", 12),
                                        Monster("k", 13),
                                        Monster("kk", 14),
                                        Monster("kk", 15)});
    std::cout<<mList.computeMonstersPxMulti(4)<<std::endl;
    return 0;
}
