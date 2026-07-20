#include "Ball.h"
#include "PlatformerGame.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"

CBall::CBall(CPlatformerGame* game)
    : Game( game )
{
    Active = true;

    Radius = 20.0f;
    Scale = 1.0f;

    Sprite = new Sprite2D( Game->getTexture("SoccerBall") );
}

CBall::~CBall()
{
    delete Sprite;
}

void CBall::reset()
{
    setActive( false );
}

void CBall::update(float deltaTime)
{
    float speed = 200.0f;
    vec2 gravity = { 0.0f, 200.0f };

    vec2 dir = Controls.getNormalized();
    vec2 forces = gravity + dir * speed;

    Velocity += forces * deltaTime;

    Position.X += Velocity.X * deltaTime;
    Position.Y += Velocity.Y * deltaTime;

    Angle += deltaTime * Velocity.X;

    // Lock to edges.
    if( Position.X < 32.0f )
    {
        Position.X = 32.0f;
        Velocity.X *= -0.95f; // Bounce off the left edge.
    }
    if( Position.X >= GetScreenWidth()-32.0f )
    {
        Position.X = GetScreenWidth()-32.0f;
        Velocity.X *= -0.95f; // Bounce off the right edge.
    }
    if( Position.Y < 32.0f )
    {
        Position.Y = 32.0f;
        Velocity.X *= 0.95f; // Slow down horizontal velocity.
        Velocity.Y *= -0.95f; // Bounce off the top.
    }
    if( Position.Y >= GetScreenHeight()-32.0f )
    {
        Position.Y = GetScreenHeight()-32.0f;
        Velocity.X *= 0.95f; // Slow down horizontal velocity.
        Velocity.Y *= -0.95f; // Bounce off the bottom.
    }
}

void CBall::draw()
{
    Sprite->draw( Position, Angle, Scale );
}

void CBall::onKey(int keyCode, KeyState keyState)
{
    if( IsWindowFocused() == false )
        Controls = 0;

    if( keyState == KeyState::Pressed )
    {
        if( keyCode == KEY_UP || keyCode == 'W' )
            Controls.Y -= 1;
        if( keyCode == KEY_DOWN || keyCode == 'S' )
            Controls.Y += 1;
        if( keyCode == KEY_LEFT || keyCode == 'A' )
            Controls.X -= 1;
        if( keyCode == KEY_RIGHT || keyCode == 'D' )
            Controls.X += 1;
    }

    if( keyState == KeyState::Released )
    {
        if( keyCode == KEY_UP || keyCode == 'W' )
            Controls.Y += 1;
        if( keyCode == KEY_DOWN || keyCode == 'S' )
            Controls.Y -= 1;
        if( keyCode == KEY_LEFT || keyCode == 'A' )
            Controls.X += 1;
        if( keyCode == KEY_RIGHT || keyCode == 'D' )
            Controls.X -= 1;
    }
}
