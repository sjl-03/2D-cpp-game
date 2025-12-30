# 2D Action RPG Game

A top-down action RPG game built from scratch in C++ using the Raylib graphics library. Features simple real-time combat, enemy AI, collision detection, and tile-based world exploration

<p align="left">
  <img src="https://github.com/user-attachments/assets/747bb624-9447-43b2-8944-c38a0c0348a3" width="300" alt="idle">
  <img src="https://github.com/user-attachments/assets/90a214ef-2e93-4ce5-ba60-0013f2c54e9c" width="300" alt="run">
  <img src="https://github.com/user-attachments/assets/74d1cb91-a309-4b18-a8b2-bdeb200b56bf" width="300" alt="attack">
</p>



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
