#pragma once

#include "Helpers/Vector.h"

class PlatformerGame;

class PlayerObject
{
public:
    PlayerObject(PlatformerGame* game);
    ~PlayerObject();

    void update(float deltaTime);
    void draw();

    void setPosition(vec2 pos);

private:
    PlatformerGame* GameInstance;

    vec2 Position;
    vec2 Scale;
    vec2 Velocity;
};
