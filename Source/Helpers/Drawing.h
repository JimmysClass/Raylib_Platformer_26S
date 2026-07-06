#pragma once

#include <vector>
#include "raylib.h"

#include "Vector.h"

void drawLineStrip(vec2 position, float angle, std::vector<vec2> points, Color color);
