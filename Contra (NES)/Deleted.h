#pragma once

#include "GameObject.h"

class Deleted : public CGameObject
{
public:
    int counter = 0;
    Deleted() : CGameObject() {}
    Deleted(float x, float y) : CGameObject(x, y) {}

    void GetBoundingBox(float& left, float& top, float& right, float& bottom) override {}

    void Update(DWORD dt) override 
    { 
        if (counter <= 100)
            counter++;
        else
            delete this;
    }

    void Render() override {}
};
