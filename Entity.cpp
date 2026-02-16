#include "Entity.h"
#include "Component.h"

Entity::Entity() = default;



Entity::~Entity() = default;

void Entity::Update(float deltaTime)
{
    for (auto& component : components)
    {
        component->Update(deltaTime);
    }
}
