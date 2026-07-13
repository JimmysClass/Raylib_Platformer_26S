#pragma once

#include "Helpers/Vector.h"

class CPlatformerGame;

class CPlayer
{
public:
    CPlayer(CPlatformerGame* game);
    ~CPlayer();

    void update(float deltaTime);
    void draw();
    void drawDebugVisuals();

    void setPosition(vec2 pos);

private:
    CPlatformerGame* Game;

    vec2 Position;
    vec2 Scale;
    vec2 Velocity;

    vec2 ColliderFootOffset;
};
