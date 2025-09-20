#include "Character.h"
#include "raymath.h"

Character::Character(int windowWidth, int windowHeight)
{
    width = texture.width / MAX_FRAME;
    height = texture.height;
    screenPos = {
        (static_cast<float>(windowWidth) / 2.f) - (SCALE*(0.5f * width)),
        (static_cast<float>(windowHeight) / 2.f) - (SCALE*(0.5f * height))};
}


void Character::tick(float deltaTime) // shift+option+f to fix formatting
{
    BaseCharacter::tick(deltaTime);
    
    bool isMoving{false};
    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (Vector2Length(direction) != 0.0)
    {
        // worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // Check direction char is facing
        isMoving = true;
    }
    isMoving ? texture = run : texture = idle;

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
