#pragma once

class Tilemap
{
public:
    int row;
    int column;
    int** tilemaparray; 
    Tilemap();
    void FetchTilemap();
};

