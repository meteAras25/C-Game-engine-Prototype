#pragma once
#include <vector>
#include <memory>

#include "Entity.h"

class EntityManager
{
public:
    Entity& CreateEntity()
    {
        entities.push_back(std::make_unique<Entity>());
        return *entities.back();
    }

    void Update(float deltaTime)
    {
        for (auto& entity : entities)
        {
            entity->Update(deltaTime);
        }
    }

private:
    std::vector<std::unique_ptr<Entity>> entities;
};
