#pragma once

struct MobInfo
{
    int type;
    float x;
    float y;
};

class Stage
{
public:
    float ScreenWidth;
    float ScreenHeight;
    float LevelLength;
    float Billx, Billy;
    float Lancex, Lancey;
    int MobCount;
    MobInfo Mobs[100];
    Stage();
};

