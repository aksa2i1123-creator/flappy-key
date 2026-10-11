# 🐦 Flappy Key

**Flappy Bird, but you can only jump using the correct arrow key!**

Flappy Key is a small C++ game inspired by Flappy Bird, built with [raylib](https://www.raylib.com/). Dodge obstacles, react to changing controls, and try to survive as long as possible!

## 🎮 Features

* 🐦 Four different bird sprites: Up, Down, Left, and Right
* 🎲 Randomized controls that change when you jump
* 🧱 Moving obstacles with randomly generated gaps
* 💥 Collision detection and a Game Over screen
* ⏸️ Pause and resume gameplay
* 🔄 Restart after losing
* ⚡ Lightweight C++ and raylib project

## 🕹️ Controls

| Key            | Action                                   |
| -------------- | ---------------------------------------- |
| ⬆️ Up Arrow    | Jump when Up is the correct direction    |
| ⬇️ Down Arrow  | Jump when Down is the correct direction  |
| ⬅️ Left Arrow  | Jump when Left is the correct direction  |
| ➡️ Right Arrow | Jump when Right is the correct direction |
| `P`            | Pause / Resume                           |
| `R`            | Restart after Game Over                  |
| `ESC`          | Close the game                           |

**Tip:** Pay attention to the bird's direction! The correct arrow key changes after each jump.

## 🛠️ Built With

* **Language:** C++
* **Graphics Library:** [raylib](https://www.raylib.com/)
* **Randomization:** C++ standard library

## 📦 Installation

### Requirements

* A C++ compiler that supports C++17 or newer
* [raylib](https://www.raylib.com/) installed and configured
* Git (optional, for cloning the repository)

### 1. Clone the repository

```bash
git clone https://github.com/aksa2i1123-creator/flappy-key.git
cd flappy-key
```

### 2. Build the game

Make sure raylib is installed and available to your compiler.

On macOS with raylib installed through Homebrew, try:

```bash
clang++ -std=c++17 main.cpp -o flappy-key $(pkg-config --cflags --libs raylib)
```

If your system cannot find raylib, configure the compiler's include and library paths for your installation.

### 3. Run the game

```bash
./flappy-key
```

Keep the image assets in the same working directory as the game when running it.

## 📁 Project Structure

```text
flappy-key/
├── main.cpp
├── system.h
├── up_bird.png
├── down_bird.png
├── left_bird.png
├── right_bird.png
├── cable.png
├── logo.png
├── game/
└── README.md
```

## 🚀 Goal

Survive for as long as you can by jumping through the gaps and adapting to the changing controls.

## 📌 Project Status

This is an experimental game project that can be expanded with new mechanics, scoring, sound effects, menus, and more.

## 👨‍💻 Author

Created by [aksa2i1123-creator](https://github.com/aksa2i1123-creator).

If you like the project, consider giving the repository a ⭐!

---

*Made with C++ and raylib. Inspired by Flappy Bird, with a four-direction twist.*
