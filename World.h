#include "Map.h"
#include "EntityManager.h"

class World
{
public:
    World()
        : map(64, 64) 
    {
    }

    void Update(float deltaTime)
    {
        entityManager.Update(deltaTime);
    }

    Map& GetMap()
    {
        return map;
    }

private:
    Map map;
    EntityManager entityManager;
};
