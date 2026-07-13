#include "Player.h"

CPlayer::CPlayer(CPlatformerGame* game)
    : Game( game )
{
    Position = { 200, 300 };
    Scale = { 50, 100 };

    ColliderFootOffset = { 0, 50 };
}

CPlayer::~CPlayer()
{
}

void CPlayer::update(float deltaTime)
{
    vec2 gravity = { 0, 0 };

    Velocity += gravity * deltaTime;
    Position += Velocity * deltaTime;
}

void CPlayer::draw()
{
    DrawRectangle( Position.X - Scale.X/2, Position.Y - Scale.Y/2, Scale.X, Scale.Y, YELLOW );
}

void CPlayer::drawDebugVisuals()
{
    DrawCircle( Position.X+ColliderFootOffset.X, Position.Y+ColliderFootOffset.Y, 5, { 255, 109, 194, 200 } );
}

void CPlayer::setPosition(vec2 pos)
{
    Position = pos;
}
