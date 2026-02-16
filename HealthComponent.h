#pragma once 
#include "Component.h"
#include <iostream>

class HealthComponent : public Component

{
    public:

        int maxHealth = 100;
        int currentHealth = 100;

        void Update(float) override 
        {
            if(currentHealth <= 0)
            {
                std::cout << "unit öldü!  \n";
            }
        }

        void TakeDamage(int damage)
        {
            currentHealth -= damage;
            if(currentHealth < 0)
                currentHealth = 0;
        }
};