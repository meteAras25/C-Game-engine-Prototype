#pragma once
#include <vector>
#include <memory>

class Component;

class Entity
{
public:
    Entity();
    
    ~Entity();

    void Update(float deltaTime);

    template<typename T, typename... Args>
    T* AddComponent(Args&&... args)
    {
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T* rawPtr = component.get();
        rawPtr->SetOwner(this);
        components.push_back(std::move(component));
        return rawPtr;
    }

    template<typename T>
    T* GetComponent()
    {
        for (auto& component : components)
        {
            if (auto casted = dynamic_cast<T*>(component.get()))
                return casted;
        }
        return nullptr;
    }

private:
    std::vector<std::unique_ptr<Component>> components;
};
