#include "MovementComponent.h"
#include "Entity.h"
#include "GridPositionComponent.h"

void MovementComponent::Update(float /*deltaTime*/)
{
    if (!owner) return;

    auto* gridPos = owner->GetComponent<GridPositionComponent>();
    if (!gridPos) return;

    
    gridPos->x += directionX;
    gridPos->y += directionY;

   
    directionX = 0;
    directionY = 0;
}
