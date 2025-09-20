#include "BaseCharacter.h"

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
        screenPos.x,
        screenPos.y,
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

    // Draw character
    Rectangle source{width * frame, 0.f,rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y,SCALE * width,SCALE * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);

}