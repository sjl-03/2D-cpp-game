#include "Enermy.h"

Enermy::Enermy(Vector2 pos,
               Texture2D idle_texture,
               Texture2D run_texture) : texture(idle_texture),
                                        worldPos(pos),
                                        idle(idle_texture),
                                        run(run_texture)
{
    width = texture.width / MAX_FRAME;
    height = texture.height;
}

void Enermy::tick(float deltaTiem)
{
    worldPosLastFrame = worldPos;

    // Update animation frame
    runningTime += deltaTiem; // delta time = time since last frame
    if (runningTime >= UPDATE_TIME)
    {
        frame++;
        runningTime = 0.f;
        if (frame > MAX_FRAME)
            frame = 0;
    }

    // Draw character
    Rectangle source{width * frame, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, SCALE * width, SCALE * height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}

void Enermy::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Enermy::getCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * SCALE,
        height * SCALE};
}