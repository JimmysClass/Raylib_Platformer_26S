#include "raylib.h"
#include <random>
#include <float.h>

#include "PlatformerGame.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"
#include "PlayerObject.h"

PlatformerGame::PlatformerGame()
{
    std::random_device rd;
    srand( rd() );

    Textures["SoccerBall"] = LoadTexture( "Data/Textures/SoccerBall.png" );

    Player = new PlayerObject( this );

    reset();
}

PlatformerGame::~PlatformerGame()
{
    for( auto texturePair : Textures )
    {
        UnloadTexture( texturePair.second );
    }
}

void PlatformerGame::reset()
{
}

void PlatformerGame::update(float deltaTime)
{
    Player->update( deltaTime );
}

void PlatformerGame::draw()
{
    ClearBackground( WHITE );

    DrawCircle( 400, 300, 50, RED );
    DrawTexture( getTexture("SoccerBall"), 500, 300, WHITE );
    DrawText( "Hello", 600, 300, 50, DARKGRAY );

    Player->draw();
}

void PlatformerGame::onKey(int keyCode, KeyState keyState)
{
    if( keyCode == 'R' && keyState == KeyState::Pressed )
    {
        reset();
    }
}

void PlatformerGame::onMouseButton(int button, KeyState keyState)
{
}

void PlatformerGame::onMouseMove(int x, int y)
{
}

Texture2D PlatformerGame::getTexture(const char* textureName) const
{
    auto it = Textures.find( textureName );
    if( it != Textures.end() )
    {
        return it->second;
    }

    // Return an empty texture if not found.
    assert( false );
    return Texture2D();
}
