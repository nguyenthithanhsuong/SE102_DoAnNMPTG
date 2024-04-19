#include "MapRead.h"

#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

Stage::Stage()
{
    ifstream inputFile("MAPstage1.txt");

    inputFile >> ScreenWidth >> ScreenHeight >> LevelLength;

    inputFile >> Billx >> ws >> Billy;
    inputFile >> Lancex >> ws >> Lancey;

    inputFile >> MobCount;

    for (int i = 0; i < MobCount; ++i) {
        inputFile >> Mobs[i].type >> ws >> Mobs[i].x >> ws >> Mobs[i].y;
    }
}
