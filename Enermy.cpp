#include "Enermy.h"
#include "raymath.h"

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

    speed = 3.f;
}

void Enermy::tick(float deltaTime)
{
        
    // get toTarget (= -screenspace of enermy + screenspace of knight )
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
    // normalise toTarget
    toTarget = Vector2Normalize(toTarget);
    // mutiply |toTarget| by speed
    toTarget = Vector2Scale(toTarget, speed);
    // move Enermy
    worldPos = Vector2Add(worldPos, toTarget);

    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    BaseCharacter::tick(deltaTime);
}

void Enermy::setTarget(Character* character)
{
    target = character;
}