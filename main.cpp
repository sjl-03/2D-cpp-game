#include "raylib.h"
#include "raymath.h"

class Character
{
public:
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int windowWidth, int windowHeight);
    void tick(float deltaTiem);

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    // -1: facing left, 1: facing right
    float rightLeft{1.f};
    // Animation variables
    float scaleTexture{4.f};
    float runningTime{};
    int frame{};
    const int MAX_FRAME{6};
    const float UPDATE_TIME{1.f / 15.f};
    const float speed{4.f};
};

void Character::setScreenPos(int windowWidth, int windowHeight)
{
    screenPos = {
        (float)windowWidth / 2.0f - scaleTexture * (0.5f * (float)texture.width / (float)MAX_FRAME),
        (float)windowHeight / 2.f - scaleTexture * (0.5f * (float)texture.height)};
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
    Rectangle source{(float)texture.width / (float)MAX_FRAME * frame, 0.f,
                     rightLeft * (float)texture.width / (float)MAX_FRAME,
                     (float)texture.height};
    Rectangle dest{screenPos.x, screenPos.y,
                   scaleTexture * (float)source.width,
                   scaleTexture * (float)source.height};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0.f, WHITE);
}

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