#include "Character.h"
#include "raymath.h"

Character::Character()
{
    width = texture.width / MAX_FRAME;
    height = texture.height;
}

void Character::setScreenPos(int windowWidth, int windowHeight)
{
    screenPos = {
        (float)windowWidth / 2.0f - scaleTexture * (0.5f * width),
        (float)windowHeight / 2.f - scaleTexture * (0.5f * height)};
}

void Character::tick(float deltaTiem) // shift+option+f to fix formatting
{
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

    // Update nimation frame
    runningTime += deltaTiem; // delta time = time since last frame
    if (runningTime >= UPDATE_TIME)
    {
        frame++;
        runningTime = 0.f;
        if (frame > MAX_FRAME)
            frame = 0;
    }

    // Draw character
    Rectangle source{width * frame, 0.f,
                     rightLeft * width,
                     height};
    Rectangle dest{screenPos.x, screenPos.y,
                   scaleTexture * width,
                   scaleTexture * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}