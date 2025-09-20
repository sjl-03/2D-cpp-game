#include "raylib.h"
#include "raymath.h"

int main(void)
{
    const int WINDOW_WIDTH = 384;
    const int WINDOW_HEIGHT = 384;
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top down");

    Texture2D map = LoadTexture("nature_tileset/mymap.png");
    Vector2 mapPos {0.0, 0.0};
    float speed {4.0};

    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    int numImageInSpriteKnight = 6;
    float scaleKnight = 4;
    Vector2 knightPos{
        (float)WINDOW_WIDTH/2.0f - scaleKnight*(0.5f* (float)knight.width / (float)numImageInSpriteKnight),
        (float)WINDOW_HEIGHT/2.f - scaleKnight*(0.5f* (float)knight.height)
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }

        // Draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        // Draw character
        Rectangle knightSource{0.f, 0.f,  (float)knight.width/(float)numImageInSpriteKnight,  (float)knight.height};
        Rectangle knightDest{knightPos.x, knightPos.y, scaleKnight*(float)knightSource.width, scaleKnight*(float)knightSource.height};
        Vector2 knightOrigin {};
        DrawTexturePro(knight,knightSource, knightDest, knightOrigin, 0.f, WHITE);
        
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}