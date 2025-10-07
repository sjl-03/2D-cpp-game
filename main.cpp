#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enermy.h"
#include <string>

int main(void)
{
    const int WINDOW_WIDTH = 384;
    const int WINDOW_HEIGHT = 384;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Top down");

    Texture2D map = LoadTexture("nature_tileset/mymap.png");
    Vector2 mapPos{0.0, 0.0};
    const float SCALE_MAP{4.0};

    Character knight{WINDOW_WIDTH, WINDOW_HEIGHT};

    Prop props[3]{
        Prop{Vector2{300.f, 1000.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

    Enermy goblin{Vector2{600.f, 500.f},
                  LoadTexture("characters/goblin_idle_spritesheet.png"),
                  LoadTexture("characters/goblin_run_spritesheet.png")};

    goblin.setTarget(&knight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw map
        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);
        DrawTextureEx(map, mapPos, 0.0, SCALE_MAP, WHITE);

        // Draw props
        for (auto prop : props)
        {
            prop.Render(knight.getWorldPos());
        }
        
        knight.tick(GetFrameTime());

        // Check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x > map.width * SCALE_MAP - WINDOW_WIDTH ||
            knight.getWorldPos().y > map.height * SCALE_MAP - WINDOW_HEIGHT)
        {
            knight.undoMovement();
        }

        // Check collision with prop
        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()),
                                   knight.getCollisionRec()))
            {
                knight.undoMovement();
            }
        }

        if (!knight.isAlive()){
             DrawText("Game Over", 55.f, 45.f, 40, RED);
             EndDrawing();
             continue;
        }
        else {
            std::string knightHealth {"Health: "};
            knightHealth.append(std::to_string(knight.getHealth()), 0, 5);
            DrawText(knightHealth.c_str(), 55.f, 45.f, 40, WHITE);
        }

        goblin.tick(GetFrameTime());

        // Check collision with weapon
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            if (CheckCollisionRecs(knight.getWeaponCollisionRec(), 
            goblin.getCollisionRec())){
                goblin.setAlive(false);
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}