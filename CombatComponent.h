#pragma once

#include "component.h"
#include "HealthComponent.h"
#include "Entity.h"

class CombatComponent : public Component
{
    public:

    int damage = 10;
    float attackCooldown = 1.0f;
    float timer = 1.0f;

    Entity* target = nullptr;

    void Update (float deltaTime) override 

    {
        if(!target) return;;
        
        timer += deltaTime;
        if(timer >= attackCooldown)
        {
            timer = 0.0f;
            Attack();
        }
    }

     void Attack()
    {
        auto* health = target->GetComponent<HealthComponent>();
        if (health)
        {
            health->TakeDamage(damage);
        }
    }
};

