#include "Enermy.h"

Enermy::Enermy(Vector2 pos,
               Texture2D idle_texture,
               Texture2D run_texture)
{
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    worldPos = pos;

    
    width = texture.width / MAX_FRAME;
    height = texture.height;
}

void Enermy::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);
}

void Enermy::setTarget(Character* character)
{
    target = character;
}