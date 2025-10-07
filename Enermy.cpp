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

    speed = 2.f;
}

void Enermy::tick(float deltaTime)
{
    if (!isAlive()) return;

    // get toTarget (= -screenspace of enermy + screenspace of knight )
    velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
    // normalise toTarget
    // mutiply |toTarget| by speed
    // move Enermy

    if (Vector2Length(velocity) < radius) velocity = {};

    BaseCharacter::tick(deltaTime);

    if (CheckCollisionRecs(getCollisionRec(), target->getCollisionRec())){
        target->takeDamage(damagePerSec * deltaTime);
    }
}

Vector2 Enermy::getScreenPos()
{
    return Vector2Subtract(worldPos, target->getWorldPos());
}

void Enermy::setTarget(Character* character)
{
    target = character;
}

