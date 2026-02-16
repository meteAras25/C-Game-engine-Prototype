#pragma once 
#include "Component.h"
#include <windows.h>

class InputComponent : public Component {

    public:
        void Update(float deltaTime) override {
            horizontal = 0.0f;
            vertical = 0.0f;

            if(GetAsyncKeyState('W') & 0x8000) horizontal -= 1.0f;
            if(GetAsyncKeyState('S') & 0x8000) horizontal += 1.0f;
            if(GetAsyncKeyState('A') & 0x8000) vertical -= 1.0f;
            if(GetAsyncKeyState('D') & 0x8000) vertical += 1.0f;
        }

    float horizontal = 0.0f;
    float vertical = 0.0f;
};