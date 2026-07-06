#include "Drawing.h"

void drawLineStrip(vec2 position, float angle, std::vector<vec2> points, Color color)
{
    std::vector<Vector2> raylibShape;

    float angleRadians = angle * PI / 180.0f;

    for( const auto& point : points )
    {
        // Rotate the point based on the player's angle
        float rotatedX = point.X * cos(angleRadians) - point.Y * sin(angleRadians);
        float rotatedY = point.X * sin(angleRadians) + point.Y * cos(angleRadians);

        // Translate the point based on the player's position
        raylibShape.push_back( Vector2{ position.X + rotatedX, position.Y + rotatedY });
    }

    DrawLineStrip( raylibShape.data(), (int)raylibShape.size(), color );
}
