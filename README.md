# Retro C Game Engine

**WARNING — EARLY DEVELOPMENT**

This project is currently in early development. APIs, features, and file structures are unstable and may change without notice.

A compact, C-only game engine for building retro-styled 2D and low-poly 3D games. Designed for clarity, small binary size, and predictable behavior so hobbyists, educators, and jam teams can prototype classic-feeling games quickly.

## Key Points

- **Language:** C (no C++ required)
- **Focus:** Retro aesthetics — pixel-perfect 2D and palette/flat-shaded low-poly 3D
- **Goals:** Minimal dependencies, deterministic updates, easy-to-read codebase, and modular subsystems

## Features

- Lightweight 2D renderer with tilemap, sprites, layering, and palette management
- Simple 3D pipeline: vertex transforms, indexed meshes, basic lighting/flat shading, and palette-driven colors
- Fixed-step game loop for deterministic updates and easier debugging
- Audio playback tailored for chiptune-style sound and simple mixing
- Small asset pipeline for importing tiles, sprites, palettes, and meshes
- Utility tools: simple level editor and asset importers (kept minimal and optional)

## Design Principles

- Keep core systems minimal and portable so the engine is easy to understand and modify
- Deterministic simulation to support replay, debugging, and consistent behavior across platforms
- Modular APIs to allow swapping or replacing subsystems (render, input, audio, physics)
- Prioritize predictable performance on modest hardware and small file sizes

## Use Cases

- Rapid prototyping of retro-styled games
- Educational resource to learn classic engine techniques in plain C
- Game jams and hobby projects that value small binaries and retro aesthetics


## Contributing

Contributions are welcome — keep changes focused, small, and C-only. Prefer clarity over cleverness when expanding core systems.

## TODO

All core engine modules and example content are currently in progress. 


---

Created as a concise foundation for making retro 2D and 3D games in plain C.
