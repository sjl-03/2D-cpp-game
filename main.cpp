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

    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Texture2D knight = knight_idle;
    int numImageInSpriteKnight = 6;
    float scaleKnight = 4;
    Vector2 knightPos{
        (float)WINDOW_WIDTH/2.0f - scaleKnight*(0.5f* (float)knight.width / (float)numImageInSpriteKnight),
        (float)WINDOW_HEIGHT/2.f - scaleKnight*(0.5f* (float)knight.height)
    };
    // -1: facing left, 1: facing right
    float rightLeft{1.f};

    // Animation variables
    float runningTime{};
    int frame{};
    const int MAX_FRAME{6};
    const float UPDATE_TIME{1.f/15.f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        bool isMoving{false};
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;
        if (Vector2Length(direction) != 0.0)
        {
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f; // Check direction char is facing
            isMoving = true;
        }

        // Draw map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        
        // Update animation frame
        const float dT{GetFrameTime()}; // delta time = time since last frame
        runningTime += dT;
        if (runningTime >= UPDATE_TIME){
            frame++;
            runningTime = 0.f;
            if (frame > MAX_FRAME) frame = 0;
        }


        // Draw character
        isMoving ? knight = knight_run : knight = knight_idle;
        Rectangle knightSource{(float)knight.width/(float)numImageInSpriteKnight * frame, 0.f,  rightLeft*(float)knight.width/(float)numImageInSpriteKnight,  (float)knight.height};
        Rectangle knightDest{knightPos.x, knightPos.y, scaleKnight*(float)knightSource.width, scaleKnight*(float)knightSource.height};
        Vector2 knightOrigin {};
        DrawTexturePro(knight,knightSource, knightDest, knightOrigin, 0.f, WHITE);
        
        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}