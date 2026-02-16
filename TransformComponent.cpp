#include "TransformComponent.h"
#include <iostream>

void TransformComponent::Update(float deltaTime) {
    std::cout << "TransformComponent Update: x=" << x << ", y=" << y << std::endl;
}