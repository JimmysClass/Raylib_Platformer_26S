#include <assert.h>
#include "Helpers/Sprite2D.h"
#include "Helpers/Vector.h"

Sprite2D::Sprite2D(Texture2D texture)
    : Texture( texture )
{
}

Sprite2D::~Sprite2D()
{
}

void Sprite2D::draw(vec2 pos, float angle, vec2 scale)
{
    // Adjust position based on origin.
    vec2 scaledSize = { Texture.width * scale.X, Texture.height * scale.Y };
    vec2 adjustedPos = pos;

    Rectangle sourceRect = { 0, 0, (float)Texture.width, (float)Texture.height };
    Rectangle destRect = { adjustedPos.X, adjustedPos.Y, scaledSize.X, scaledSize.Y };
    vec2 origin = scaledSize * Origin;

    DrawTexturePro( Texture, sourceRect, destRect, origin, angle, WHITE );
}
