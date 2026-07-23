#pragma once

#include "raylib.h"

#include "AABB.h"
#include "Helpers/InputTypes.h"

class CPlatformerGame;
class Sprite2D;

class CBlock
{
public:
    CBlock(float x, float y, float width, float height);
    virtual ~CBlock();

    virtual void draw();
    virtual void drawDebugVisuals();

    // Getters.
    vec2 getPosition()    { return Position; }
    float getAngle()      { return Angle; }
    vec2 getScale()       { return Scale; }
    AABB getBoundingBox() { return BoundingBox; }
    float getRadius()     { return Radius; }
    Color getColor()      { return ObjectColor; }

    // Setters.
    void setPosition(vec2 pos)    { Position = pos; }
    void setAngle(float angle)    { Angle = angle; }
    void setScale(vec2 scale)     { Scale = scale; }
    void setBoundingBox(AABB box) { BoundingBox = box; }
    void setRadius(float radius)  { Radius = radius; }
    void setColor(Color color)    { ObjectColor = color; }

protected:
    vec2 Position = 0;
    float Angle = 0;
    vec2 Scale = 1;

    AABB BoundingBox;
    float Radius = 0;
    Color ObjectColor = WHITE;
};
