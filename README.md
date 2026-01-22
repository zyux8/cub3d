# cub3d
This project has been created as part of the 42 curriculum by ohaker and pbarthol
Minimal raycasting project inspired by Wolfenstein 3D. Renders a 2.5D view from a grid map using MiniLibX on Linux.

## Prerequisites
- GNU make
- GCC or Clang
- X11 development headers (Xlib/Xext) for MiniLibX

## Discription
Cub3d is a simple 3D raycasting engine inspired by early first-person games like Wolfenstein 3D.
The project is written in C and built using MiniLibX, with a focus on low-level graphics rendering, real-time input handling, and clean resource management.

The engine parses a .cub map file to generate a 3D environment, renders walls using raycasting, and supports player movement, rotation, textures, and overlays.
The project emphasizes performance, correctness, and robustness, including proper handling of partial initialization and safe cleanup on errors.

## Build

make

Artifacts: `cub3d` or `cub3d_bonus` binary at the project root.

## Run
Provide a `.cub` map file:

./cub3d maps/wow.cub


## Maps
Sample maps live in `maps/`. Textures should be under `maps/textures/`.

## Controls
For mandatory:
- Movement: W / A / S / D
- Look left/right: Left / Right arrows
- Close: ESC or window close button

For Bonus:
- Movement: W / A / S / D
- Look left/right: Left / Right arrows or mouse
- Close: ESC or window close button

## Project Structure
- `mandatory/` all files for compiling mandatory part
- `bonus/` all files for compiling bonus part
- `srcs/` – gameplay, rendering, raycasting
- `includes/` – headers and libft
- `maps/` – sample map files and textures
- `minilibx-linux/` – bundled MiniLibX (inside `includes/libft/minilibx-linux/`)

## Resources
https://hackmd.io/@nszl/H1LXByIE2#Map-parsing-and-validating
https://lodev.org/cgtutor/raycasting.html
https://harm-smits.github.io/42docs/projects/cub3d

## License
See included licenses for MiniLibX; project-specific license not declared.
