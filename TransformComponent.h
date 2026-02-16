#pragma once
#include "Component.h"

class TransformComponent : public Component {
    public: 
      float x = 0;
      float y = 0;

      void Update(float deltaTime) override;
};