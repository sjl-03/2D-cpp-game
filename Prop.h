#include "raylib.h"

class Prop 
{
    public:
    Prop(Vector2 pos, Texture2D tex);
    void Render(Vector2 characterPos);
    private:
    Vector2 worldPos{};
    Texture2D texture{};
    static constexpr float SCALE{4.f};
};