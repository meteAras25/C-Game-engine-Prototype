#pragma once

#include "Component.h"
#include "PositionComponent.h"
#include "Entity.h"

class MovementComponent : public Component
{
public:
    float speed = 2.0f;

    
    float directionX = 0.0f;
    float directionY = 0.0f;

    void Update(float deltaTime) override
    {
        auto* pos = owner->GetComponent<PositionComponent>();
        if (!pos) return;

        pos->x += directionX * speed * deltaTime;
        pos->y += directionY * speed * deltaTime;
    }
};
