#pragma once

#include "Component.h"
#include "Entity.h"
#include "PositionComponent.h"
#include "MovementComponent.h"

class AIComponent : public Component
{
public:
    Entity* target = nullptr;
    float stopDistance = 1.0f;

    void Update(float deltaTime) override
    {
        if (!target) return;

        auto* myPos = owner->GetComponent<PositionComponent>();
        auto* targetPos = target->GetComponent<PositionComponent>();
        auto* move = owner->GetComponent<MovementComponent>();

        if (!myPos || !targetPos || !move) return;

        float dx = targetPos->x - myPos->x;
        float dy = targetPos->y - myPos->y;

        float distanceSq = dx * dx + dy * dy;

        if (distanceSq > stopDistance * stopDistance)
        {
            move->directionX = dx;
            move->directionY = dy;
        }
        else
        {
            move->directionX = 0.0f;
            move->directionY = 0.0f;
        }
    }
};
