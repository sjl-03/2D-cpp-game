# 2D Action RPG Game

A top-down action RPG game built from scratch in C++ using the Raylib graphics library. Features simple real-time combat, enemy AI, collision detection, and tile-based world exploration

## Technologies Used

- **Language**: C++ (with modern C++ features)
- **Graphics Library**: [Raylib](https://www.raylib.com/) - Simple and easy-to-use game programming library
- **Level Editor**: [Tiled](https://www.mapeditor.org/) - 2D level editor for creating tile-based game maps

## Controls

| Key/Input | Action |
|-----------|--------|
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |
| `Left Mouse Button` | Attack with sword |

### Key Classes

**BaseCharacter**
- Manages sprite rendering, animation, movement, and collision
- Implements delta-time based movement for frame-rate independence
- Provides virtual `tick()` and `getScreenPos()` for polymorphic behavior

**Character**
- Handles player input (WASD keys)
- Manages weapon rendering and collision detection
- Centers character on screen while world scrolls

**Enermy**
- AI movement targeting player position
- Damage dealing on collision
- Supports multiple enemy types via texture parameters

**Prop**
- Static world objects with collision
- World-space to screen-space coordinate transformation