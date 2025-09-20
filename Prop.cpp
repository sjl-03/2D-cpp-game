#include "Prop.h"
#include "raymath.h"

// Initialise worldPos, no additional assignment step
Prop::Prop(Vector2 pos, Texture2D tex) : 
    worldPos(pos), 
    texture(tex)
{}

void Prop::Render(Vector2 characterPos)
{
    // Position of prop on current screen
    Vector2 screenPos{Vector2Subtract(worldPos, characterPos)};
    DrawTextureEx(texture, screenPos, 0.f, SCALE, WHITE);
}

Rectangle Prop::getCollisionRec(Vector2 characterPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, characterPos)};
    return Rectangle{
        screenPos.x,
        screenPos.y,
        texture.width * SCALE,
        texture.width * SCALE
    };
}