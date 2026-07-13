#include "raylib.h"
#include <random>
#include <float.h>

#include "PlatformerGame.h"
#include "Player.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"

CPlatformerGame::CPlatformerGame()
{
    std::random_device rd;
    srand( rd() );

    Textures["SoccerBall"] = LoadTexture( "Data/Textures/SoccerBall.png" );

    Player = new CPlayer( this );

    reset();
}

CPlatformerGame::~CPlatformerGame()
{
    for( auto texturePair : Textures )
    {
        UnloadTexture( texturePair.second );
    }
}

void CPlatformerGame::reset()
{
    Player->setPosition( {200,300} );
    //Player->setVelocity( {0,0} );
}

void CPlatformerGame::update(float deltaTime)
{
    Player->update( deltaTime );
}

void CPlatformerGame::draw()
{
    ClearBackground( WHITE );

    DrawCircle( 400, 300, 50, RED );
    DrawTexture( getTexture("SoccerBall"), 500, 300, WHITE );
    DrawText( "Hello", 600, 300, 50, DARKGRAY );

    Player->draw();

    if( DebugVisualsEnabled )
    {
        Player->drawDebugVisuals();
    }
}

void CPlatformerGame::onKey(int keyCode, KeyState keyState)
{
    if( keyCode == 'R' && keyState == KeyState::Pressed )
    {
        reset();
    }

    if( keyCode == KEY_TAB && keyState == KeyState::Pressed )
    {
        DebugVisualsEnabled = !DebugVisualsEnabled;
    }
}

void CPlatformerGame::onMouseButton(int button, KeyState keyState)
{
}

void CPlatformerGame::onMouseMove(int x, int y)
{
}

Texture2D CPlatformerGame::getTexture(const char* textureName) const
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
