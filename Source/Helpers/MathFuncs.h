#pragma once

#include "Vector.h"

#define PI    3.14159265358979323846f
#define PI_2  1.57079632679489661923f

float randFloat(float min, float max);
int randInt(int min, int max);
float clamp(float value, float min, float max);
float degToRad(float degrees);
float radToDeg(float radians);

bool IsCircleOverlappingLine(vec2 lineStart, vec2 lineEnd, vec2 circlePos, float circleRadius);
vec2 getReflectedVector(vec2 lineStart, vec2 lineEnd, vec2 incomingVector);
