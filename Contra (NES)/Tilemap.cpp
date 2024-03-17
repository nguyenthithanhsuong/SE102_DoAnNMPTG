#include "Tilemap.h"

#include <iostream>
#include <fstream>
#include <cstdlib> 

using namespace std;

Tilemap::Tilemap() : row(0), column(0), tilemaparray(nullptr)
{
}

void Tilemap::FetchTilemap()
{
    ifstream inputFile("Tilemap.txt");

    inputFile >> row >> column;

    tilemaparray = new int* [row];

    for (int i = 0; i < row; ++i) {
        tilemaparray[i] = new int[column]; 
        for (int j = 0; j < column; ++j) {
            inputFile >> ws >> tilemaparray[i][j]; 
        }
    }
}