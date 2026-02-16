#pragma once
#include "Component.h"

class GridPositionComponent : public Component
{
    public:
     int x = 0;
     int y = 0;
     
     void Update(float deltaTime) override {}
};