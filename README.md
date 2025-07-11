<p align="center">
  <img src="https://github.com/b1sted-labs/rock-paper-scissors/blob/main/.github/assets/logo.png" width="160" alt="Rock, Paper, Scissors">
</p>
<p align="center">
<p align="center">
  <strong>
    Rock, Paper, Scissors
  </strong>
</p>
<h2></h2>
<p align="center">
  <a href="#features"><img
    src="https://img.shields.io/badge/features-core_gameplay-brightgreen"
    alt="Features"
  /></a>
  <a href="https://github.com/b1sted-labs/rock-paper-scissors/actions"><img
    src="https://github.com/b1sted-labs/rock-paper-scissors/workflows/build/badge.svg"
    alt="Build"
  /></a>
  <a href="#prerequisites"><img
    src="https://img.shields.io/badge/prerequisites-GCC_&_Make-orange"
    alt="Prerequisites"
  /></a>
  <a href="#license"><img
    src="https://img.shields.io/badge/license-MIT-green"
    alt="License"
  /></a>
</p>
<p align="center">
  <img src="https://github.com/b1sted-labs/rock-paper-scissors/blob/main/.github/assets/screenshot.png" width="700" alt="Screenshot of the game in action" />
</p>
<p align="center">
  <a href="#introduction">Introduction</a> •
  <a href="#game-rules">Game Rules</a> •
  <a href="#features">Features</a> •
  <a href="#prerequisites">Prerequisites</a> •
  <a href="#installation--building">Installation & Building</a> •
  <a href="#usage">Usage</a> •
  <a href="#project-structure">Project Structure</a> •
  <a href="#license">License</a>
</p>
<h2></h2>

## Introduction

This is a classic game of **Rock, Paper, Scissors**, implemented as a command-line application in C with a focus on a modular code structure. The player competes against a computer opponent that makes a random choice. The project demonstrates a clean separation of concerns between game logic, user interface, and utility functions.

## Game Rules

The goal is to choose a move that defeats the opponent's move.

*   🗿 **Rock** beats **Scissors** (by breaking them).
*   ✂️ **Scissors** beats **Paper** (by cutting it).
*   📄 **Paper** beats **Rock** (by covering it).

If both players choose the same move, the round is a draw.

## Features

*   **Classic Gameplay:** A complete implementation of the core Rock, Paper, Scissors rules.
*   **Player vs. AI:** Compete against a computer opponent with a randomized move selection.
*   **Score Tracking:** The game keeps track of the score throughout the session.
*   **Replayable Rounds:** The ability to play again and again without restarting the program.
*   **Modular Design:** The source code is well-structured and separated into:
    *   `game_logic`: Handles the core game rules.
    *   `ui`: Manages all user input and output.
    *   `utils`: Provides helper functions (e.g., parsing "yes/no" responses).
*   **Localized UI:** The user interface is presented in Russian, demonstrating how localization can be implemented.
*   **Robust Input:** User input is validated to prevent errors.

## Prerequisites

To build and run this project, you will need:

*   A C compiler (e.g., **GCC**)
*   The **Make** utility

## Installation & Building

The installation and build process is straightforward:

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/b1sted/rock-paper-scissors.git
    cd rock-paper-scissors
    ```

2.  **Compile the code:**
    ```bash
    make
    ```
    This command will:
    *   Compile all source files from the `src/` directory.
    *   Place the intermediate object files (`.o`) in the `obj/` directory.
    *   Create the final executable `rps_game` in the `bin/` directory.

3.  **Clean the project (optional):**
    ```bash
    make clean
    ```
    This command removes the `obj/` and `bin/` directories along with all build artifacts.

## Usage

After a successful build, run the game using the following command:

```bash
./bin/rps_game
```

The program will display a welcome message and the rules. You will then be prompted to make your move by entering the corresponding number.

```
Сделайте ваш выбор: 
1 - Камень
2 - Ножницы
3 - Бумага
0 - Выход

Ваш ход: 
```

After each round, the result and updated score will be displayed, and you will be asked if you want to play again. To exit the game, enter `0` at the move selection menu or answer "no" when asked to continue.

## Project Structure

```
rock-paper-scissors/
├── bin/                   # Executables (created by make)
│   └── rps_game
├── obj/                   # Intermediate object files (.o) (created by make)
├── include/               # C header files (.h)
│   ├── game_logic.h       # Interface for the game logic module
│   ├── rps.h              # Core types (Choice) and string representations
│   ├── ui.h               # Interface for the user interface module
│   └── utils.h            # Interface for the utility module
├── src/                   # C source files (.c)
│   ├── main.c             # Entry point and main game loop
│   ├── game_logic.c       # Implementation of the game logic
│   ├── rps.c              # Implementation of functions for the Choice type
│   ├── ui.c               # Implementation of all I/O functions
│   └── utils.c            # Implementation of utility functions
├── .github/               # GitHub specific files
│   └── assets/
│       ├── logo.png
│       └── screenshot.png 
├── .gitignore             # Git ignore file
├── LICENSE                # MIT License file
├── Makefile               # Build script for make
└── README.md              # This file
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
