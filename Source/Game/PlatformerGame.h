#pragma once

#include <assert.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "raylib.h"
#include "Helpers/InputTypes.h"
#include "Helpers/Vector.h"

class CBall;
class CBlock;
class CPlayer;

class CPlatformerGame
{
public:
    CPlatformerGame();
    virtual ~CPlatformerGame();

    void reset();
    void update(float deltaTime);
    void draw();

    // Input event methods.
    void onKey(int keyCode, KeyState keyState);
    void onMouseButton(int button, KeyState keyState);
    void onMouseMove(int x, int y);

    // Getters.
    Texture2D getTexture(const char* textureName) const;
    std::vector<CBlock*>& getBlocks() { return Blocks; }

private:
    std::unordered_map<std::string, Texture2D> Textures;

    bool DebugVisualsEnabled = false;

    std::vector<CBlock*> Blocks;
    CPlayer* Player;
    CBall* Ball;

    // Temp variables to prototype circle/line collision
    vec2 LineStart;
    vec2 LineEnd;
    vec2 CirclePos;
    float CircleRadius;
};
