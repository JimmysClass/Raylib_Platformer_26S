#include <random>

#include "MathFuncs.h"

float randFloat(float min, float max)
{
    return min + (max-min) * rand()/(float)RAND_MAX;
}

int randInt(int min, int max)
{
    return min + rand() % (max-min+1);
}

float clamp(float value, float min, float max)
{
    if( value < min ) return min;
    if( value > max ) return max;
    return value;
}

float degToRad(float degrees)
{
    return degrees * (PI / 180.0f);
}

float radToDeg(float radians)
{
    return radians * (180.0f / PI);
}

bool IsCircleOverlappingLine(vec2 lineStart, vec2 lineEnd, vec2 circlePos, float circleRadius)
{
    vec2 circleDir = circlePos - lineStart;
    vec2 lineDir = lineEnd - lineStart;
    float lineLength = lineDir.length();
    lineDir.normalize();

    float n = circleDir.dot( lineDir );
    n = clamp( n, 0, lineLength );

    vec2 nearestPointOnLine = lineDir * n + lineStart;

    float distFromLine = (circlePos - nearestPointOnLine).length();

    if( distFromLine <= circleRadius )
        return true;

    return false;
}
