#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{

}

void BaseCharacter::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollisionRec()
{
    return Rectangle{
        getScreenPos().x,
        getScreenPos().y,
        width * SCALE,
        height * SCALE
    };
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    
    // Update animation frame
    runningTime += deltaTime; // delta time = time since last frame
    if (runningTime >= UPDATE_TIME)
    {
        frame++;
        runningTime = 0.f;
        if (frame > MAX_FRAME)
            frame = 0;
    }

    // Update movement
    if (Vector2Length(velocity) != 0.0)
    {
        // worldPos = worldPos + velocity
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        velocity.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // Check direction char is facing
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // Draw character
    Rectangle source{width * frame, 0.f,rightLeft * width, height};
    Rectangle dest{getScreenPos().x, getScreenPos().y,SCALE * width,SCALE * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);

}