#pragma once

#include "Helpers/Vector.h"

class AABB
{
public:
    AABB() : X(0), Y(0), W(0), H(0) {}
    AABB(float x, float y, float width, float height) : X(x), Y(y), W(width), H(height) {}

    bool isPointInside(vec2 p) const
    {
        if( p.X < X || p.X >= X + W ||
            p.Y < Y || p.Y >= Y + H )
        {
            return false;
        }

        return true;
    }

public:
    float X, Y, W, H;
};
