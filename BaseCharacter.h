#include "raylib.h"

#ifndef BASE_CHARACTER_H
// if the name "base character h" is not defined, include following
#define BASE_CHARACTER_H

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 getWorldPos() { return worldPos; };
    void undoMovement();
    Rectangle getCollisionRec();
    virtual void tick(float deltaTime);

protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // -1: facing left, 1: facing right
    float rightLeft{1.f};
    // Animation variables
    float runningTime{};
    int frame{};
    static constexpr float SCALE{4.f};
    static constexpr int MAX_FRAME{6};
    static constexpr float UPDATE_TIME{1.f / 15.f};
    float speed{4.f};
    float width{};
    float height{};
    Vector2 velocity{};
};

#endif