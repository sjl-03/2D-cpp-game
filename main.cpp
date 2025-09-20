#include "raylib.h"
#include "raymath.h"
#include "Character.h"


int main(void)
{
    const int WINDOW_WIDTH = 384;
    const int WINDOW_HEIGHT = 384;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top down");

    Texture2D map = LoadTexture("nature_tileset/mymap.png");
    Vector2 mapPos{0.0, 0.0};

    Character knight{};
    knight.setScreenPos(WINDOW_WIDTH, WINDOW_HEIGHT);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw map
        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        knight.tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}