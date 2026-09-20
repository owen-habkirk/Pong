# Pong (C++ / SFML)

A classic 2D Pong recreation built with **C++** and **SFML 3.1.0** using Xcode on macOS.



---

## Features

- 2 player mode
- Single player mode with a custom built ai controller
- Custom sound effects for ball bounces and scoring.
- Bundled SFML binaries for hassle-free macOS setup.

---

## Prerequisites

- **macOS** (11 or later)
- **Xcode** 
- **C++17** compatible compiler

> **Note:** SFML 3.1.0 dynamic libraries and headers are pre-packaged in this repository, so no separate Homebrew or manual library installation is required.

---

## Getting Started

1. Clone or download this repository.
2. Open `pong.xcodeproj` in Xcode.
3. Select the **Pong** target and click **Run** (or press `Cmd + R`).

### First-Time macOS Security Warning
Because the project binaries are not notarized by Apple, macOS may block execution on first launch:
1. Locate the built executable in Finder (or Control-click `pong.xcodeproj`).
2. Select **Open** from the context menu.
3. Click **Open** again in the security dialog to confirm.

---

## Repository Layout

Please maintain the following folder structure so Xcode can resolve bundled SFML library headers and game assets correctly:

```text
Pong/<img width="1918" height="932" alt="Screenshot 2026-09-20 at 11 23 50 AM" src="https://github.com/user-attachments/assets/8cb02e27-fc72-4e1c-9c98-99babe056055" />

├── pong.xcodeproj/
├── pong/
│   ├── main.cpp
│   ├── ball.h
│   ├── engine.h
│   ├── paddle_controllers.h
│   ├── paddles.h
│   ├── play_area.h
│   ├── scoreboard.h
│   ├── sounds.h
│   └── pong_assets/
│       ├── bounce.wav
│       ├── score.wav
│       └── Orbitron/
│           └── orbitron_font.ttf
└── SFML-3.1.0/
    ├── include/
    └── lib/
