#include "PlatformerGame.h"
#include "Helpers/MathFuncs.h"
#include "Helpers/Sprite2D.h"
#include "Block.h"

CBlock::CBlock(float x, float y, float width, float height)
    : Position( x, y )
    , Scale( width, height )
{
    BoundingBox.X = x;
    BoundingBox.Y = y;
    BoundingBox.W = width;
    BoundingBox.H = height;

    ObjectColor = RED;
}

CBlock::~CBlock()
{
}

void CBlock::draw()
{
    DrawRectangle( (int)Position.X, (int)Position.Y, (int)Scale.X, (int)Scale.Y, ObjectColor );
}

void CBlock::drawDebugVisuals()
{
    DrawRectangleLines( (int)Position.X, (int)Position.Y, (int)Scale.X, (int)Scale.Y, GREEN );
}
