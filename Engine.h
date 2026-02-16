#ifndef AETHER_ENGINE_H
#define AETHER_ENGINE_H

#include "EntityManager.h"
#include "TileMap.h"

class Engine {  
public:
    Engine();
    void Run();

private:
    bool isRunning;
    EntityManager entityManager;

    void Update(float deltaTime);

    TileMap map;
};

#endif
