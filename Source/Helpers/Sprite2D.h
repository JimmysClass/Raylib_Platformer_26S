#pragma once

#include "raylib.h"
#include "Helpers/Vector.h"

class Sprite2D
{
public:
    Sprite2D(Texture2D texture);
    ~Sprite2D();

    void draw(vec2 pos, float angle, vec2 scale);

    // Getters.
    vec2 getOrigin() const { return Origin; }

    // Setters.
    void setOrigin(vec2 origin) { Origin = origin; }

private:
    Texture2D Texture;
    vec2 Origin = { 0.5f, 0.5f };
};
