# 🐍 Classic Snake Game in Pure C

A classic Snake game implementation using C and SDL2 library with a clean grid-based interface.

## 🎮 Game Features

- **Responsive Controls**: Use arrow keys to control the snake
- **Grid-based Movement**: Clean 20x20 pixel cell movement system
- **Visual Elements**: 
  - White snake that moves smoothly across the grid
  - Red apple target positioned on the game board
  - Grid lines for clear visual guidance
- **Smooth Gameplay**: 50 FPS game loop for fluid movement
- **Proper Window Management**: Responsive close button and clean exit

## 🕹️ Controls

| Key | Action |
|-----|--------|
| ↑ | Move Up |
| ↓ | Move Down |
| ← | Move Left |
| → | Move Right |
| X | Close Window |

## 🛠️ Technical Details

### Built With
- **Language**: Pure C
- **Graphics Library**: SDL2 (Simple DirectMedia Layer)
- **Compiler**: GCC (via MSYS2)
- **Platform**: Windows (cross-platform compatible)

### Game Specifications
- **Window Size**: 900x600 pixels
- **Grid Size**: 45x30 cells (20px per cell)
- **Frame Rate**: 50 FPS (20ms delay)
- **Color Scheme**:
  - Grid Lines: Dark Gray (`0x1f1f1f1f`)
  - Snake: White (`0xffffffff`)
  - Apple: Red (`0xffff0000`)

## 🔧 Prerequisites

### Windows Setup (MSYS2)
1. Install MSYS2 from [https://www.msys2.org/](https://www.msys2.org/)
2. Install required packages:
   ```bash
   pacman -S mingw-w64-x86_64-toolchain
   pacman -S mingw-w64-x86_64-SDL2
   ```

### Linux Setup
```bash
# Ubuntu/Debian
sudo apt install build-essential libsdl2-dev

# Fedora
sudo dnf install gcc SDL2-devel

# Arch Linux
sudo pacman -S gcc sdl2
```

### macOS Setup
```bash
# Using Homebrew
brew install sdl2
```

## 🚀 How to Build and Run

### Windows (MSYS2 MINGW64 Terminal)
```bash
# Navigate to project directory
cd /c/path/to/snake-project

# Compile
gcc snake.c -lSDL2 -lSDL2main -o snake

# Run
./snake
```

### Windows (PowerShell with Full Paths)
```powershell
# Compile with full MSYS2 paths
C:\msys64\mingw64\bin\gcc.exe snake.c -IC:\msys64\mingw64\include\SDL2 -LC:\msys64\mingw64\lib -lSDL2 -lSDL2main -o snake

# Run
.\snake
```

### Linux/macOS
```bash
# Compile
gcc snake.c -lSDL2 -o snake

# Run
./snake
```

## 📁 Project Structure

```
snake-game/
├── snake.c          # Main game source code
├── snake.exe        # Compiled Windows executable
└── README.md        # This file
```

## 🎯 Current Implementation Status

### ✅ Completed Features
- [x] SDL2 window creation and management
- [x] Grid rendering system
- [x] Snake entity with position tracking
- [x] Arrow key input handling
- [x] Apple/food entity rendering
- [x] Smooth movement and rendering
- [x] Proper resource cleanup
- [x] Event handling (window close, keyboard input)

### 🚧 Planned Features
- [ ] Collision detection (snake-apple, snake-walls, snake-self)
- [ ] Snake growth mechanism when eating apples
- [ ] Score tracking and display
- [ ] Game over screen
- [ ] High score persistence
- [ ] Sound effects
- [ ] Menu system
- [ ] Difficulty levels

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 Code Structure

The game uses a simple but effective structure:

- **Macros**: Convenient drawing functions (`SNAKE`, `APPLE`, `DRAW_GRID`)
- **Drawing Functions**: `draw_grid()`, `fill_cell()` for rendering
- **Game Loop**: Event handling, game state updates, and rendering
- **Clean Architecture**: Separated concerns for easy maintenance

## 🐛 Known Issues

- Snake can move outside grid boundaries (collision detection needed)
- No snake growth or apple consumption logic yet
- Single-cell snake (needs body segments)

## 📜 License

This project is open source and available under the [MIT License](LICENSE).

## 👨‍💻 Author

**Dilshan2002104-cpu** - [GitHub Profile](https://github.com/Dilshan2002104-cpu)

---

### 🎮 Enjoy the game and happy coding! 🎮