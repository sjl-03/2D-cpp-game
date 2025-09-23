#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) :
    windowWidth(winWidth), windowHeight(winHeight)
{
    width = texture.width / MAX_FRAME;
    height = texture.height;
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        (static_cast<float>(windowWidth) / 2.f) - (SCALE*(0.5f * width)),
        (static_cast<float>(windowHeight) / 2.f) - (SCALE*(0.5f * height))
    };
}

void Character::tick(float deltaTime) // shift+option+f to fix formatting
{
    if (IsKeyDown(KEY_A))
        velocity.x -= 1.0;
    if (IsKeyDown(KEY_D))
        velocity.x += 1.0;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1.0;
    if (IsKeyDown(KEY_S))
        velocity.y += 1.0;
    
    BaseCharacter::tick(deltaTime);
}



