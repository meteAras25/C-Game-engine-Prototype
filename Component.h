#pragma once

class Entity;

class Component
{
public:
    virtual ~Component() = default;

    virtual void Update(float deltaTime) = 0;

    void SetOwner(Entity* entity)
    {
        owner = entity;
    }

protected:
    Entity* owner = nullptr;
};
