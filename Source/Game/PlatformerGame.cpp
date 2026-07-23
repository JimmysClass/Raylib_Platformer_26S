#include "raylib.h"
#include <random>
#include <float.h>

#include "Ball.h"
#include "Block.h"
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

    Ball = new CBall( this );
    Ball->setVelocity({ 50,0 });

    Blocks.push_back( new CBlock( 100,500, 200,50 ) );
    Blocks.push_back( new CBlock( 400,400, 200,50 ) );
    Blocks.push_back( new CBlock( 700,300, 200,50 ) );
    Blocks.push_back( new CBlock( 1000,200, 200,50 ) );

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
    Ball->update( deltaTime );
}

void CPlatformerGame::draw()
{
    ClearBackground( WHITE );

    //DrawCircle( 400, 300, 50, RED );
    //DrawTexture( getTexture("SoccerBall"), 500, 300, WHITE );
    //DrawText( "Hello", 600, 300, 50, DARKGRAY );

    Player->draw();
    Ball->draw();

    for( auto block : Blocks )
    {
        block->draw();
    }

    if( DebugVisualsEnabled )
    {
        Player->drawDebugVisuals();
    }

    // Temp code to prototype circle/line collision
    LineStart = { 300,600 };
    LineEnd = { 1000,600 };
    CircleRadius = 60;

    bool isOverlapping = IsCircleOverlappingLine( LineStart, LineEnd, CirclePos, CircleRadius );

    DrawLine( LineStart.X, LineStart.Y, LineEnd.X, LineEnd.Y, isOverlapping ? GREEN : RED );
    DrawCircle( CirclePos.X, CirclePos.Y, CircleRadius, isOverlapping ? GREEN : BLUE );
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
    CirclePos.set(x, y);
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
