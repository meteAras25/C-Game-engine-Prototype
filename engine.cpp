#include "Entity.h"
#include "MovementComponent.h"
#include <vector>
#include <memory>

int main()
{
    std::vector<std::unique_ptr<Entity>> entities;

    auto unit = std::make_unique<Entity>(1);
    unit->AddComponent<MovementComponent>();

    entities.push_back(std::move(unit));

    float deltaTime = 0.016f; 
    while (true)
    {
        for (auto& e : entities)
        {
            e->Update(deltaTime);
        }
    }

    return 0;
}
