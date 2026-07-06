#include "PlayerObject.h"

PlayerObject::PlayerObject(PlatformerGame* game)
    : GameInstance( game )
{
    Position = { 200, 300 };
    Scale = { 50, 100 };
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::update(float deltaTime)
{
    vec2 gravity = { 0, 200 };

    Velocity += gravity * deltaTime;
    Position += Velocity * deltaTime;
}

void PlayerObject::draw()
{
    DrawRectangle(
        Position.X - Scale.X/2,
        Position.Y - Scale.Y/2,
        Scale.X, Scale.Y, YELLOW );
}

void PlayerObject::setPosition(vec2 pos)
{
    Position = pos;
}
