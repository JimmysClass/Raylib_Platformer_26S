#pragma once

#include <assert.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "raylib.h"
#include "Helpers/InputTypes.h"
#include "Helpers/Vector.h"

class PlatformerGame
{
public:
    PlatformerGame();
    virtual ~PlatformerGame();

    void reset();
    void update(float deltaTime);
    void draw();

    // Input event methods.
    void onKey(int keyCode, KeyState keyState);
    void onMouseButton(int button, KeyState keyState);
    void onMouseMove(int x, int y);

    // Getters.
    Texture2D getTexture(const char* textureName) const;

private:
    std::unordered_map<std::string, Texture2D> Textures;
};
