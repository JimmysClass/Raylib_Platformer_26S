#pragma once

#include "raylib.h"
#include <cmath>

class vec2
{
public:
    vec2() {}
    vec2(float nxy) : X(nxy), Y(nxy) {}
    vec2(float nx, float ny) : X(nx), Y(ny) {}

    void set(float nx, float ny) { X = nx; Y = ny; }

    vec2 operator+(vec2 o) { return vec2(X + o.X, Y + o.Y); }
    vec2 operator-(vec2 o) { return vec2(X - o.X, Y - o.Y); }
    vec2 operator*(vec2 o) { return vec2(X * o.X, Y * o.Y); }
    void operator+=(vec2 o) { X += o.X; Y += o.Y; }

    vec2 operator*(float o) { return vec2(X * o, Y * o); }
    vec2 operator/(float o) { return vec2(X / o, Y / o); }

    operator Vector2() const
    {
        Vector2 v = { X, Y };
        return v;
    }

    float length() { return sqrtf( X*X + Y*Y ); }
    float dot(vec2 o) { return X*o.X + Y*o.Y; }

    void normalize()
    {
        float len = length();
        if( len == 0 )
            return;
        X /= len;
        Y /= len;
    }

    vec2 getNormalized() const
    {
        vec2 v = *this;
        v.normalize();
        return v;
    }

public:
    float X = 0;
    float Y = 0;
};
