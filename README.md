# cub3d

Minimal raycasting project inspired by Wolfenstein 3D. Renders a 2.5D view from a grid map using MiniLibX on Linux.

## Prerequisites
- GNU make
- GCC or Clang
- X11 development headers (Xlib/Xext) for MiniLibX

## Build
```
make
```
Artifacts: `cub3d` binary at the project root.

## Run
Provide a `.cub` map file:
```
./cub3d maps/wow.cub
```

## Maps
Sample maps live in `maps/`. Textures should be under `maps/textures/`.

## Controls
Default 42-school scheme (common):
- Movement: W / A / S / D
- Look left/right: Left / Right arrows
- Close: ESC or window close button

## Project Structure
- `srcs/` – gameplay, rendering, raycasting
- `includes/` – headers and libft
- `maps/` – sample map files and textures
- `minilibx-linux/` – bundled MiniLibX (inside `includes/libft/minilibx-linux/`)

## License
See included licenses for MiniLibX; project-specific license not declared.
