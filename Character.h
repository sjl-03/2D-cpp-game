#include "raylib.h"

class Character
{
public:
    Character();
    Vector2 getWorldPos() { return worldPos; }
    void setScreenPos(int windowWidth, int windowHeight);
    void tick(float deltaTiem);
    void undoMovement();

private:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // -1: facing left, 1: facing right
    float rightLeft{1.f};
    // Animation variables
    float scaleTexture{4.f};
    float runningTime{};
    int frame{};
    static constexpr int MAX_FRAME{6};
    static constexpr float UPDATE_TIME{1.f / 15.f};
    static constexpr float speed{4.f};
    float width{};
    float height{};
};