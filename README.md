# Slot-MachineGame
SFML Slot-Machine Game
# Slot-Machine-Demo
SFML Slot -Machine-Demo

# SFML Slot Machine Game



![Slot Machine](SFML%20SLOTS/gameplay/spinning.gif)

Welcome to the SFML Slot Machine Game! This is a simple slot machine game implemented using the Simple and Fast Multimedia Library (SFML). Test your luck and see if you can win big in this virtual slot machine.

## Table of Contents

- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Gameplay](#gameplay)
- [Controls](#controls)
- [Features](#features)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

These instructions will help you set up and play the SFML Slot Machine Game on your local machine.

### Prerequisites

Before you begin, ensure you have the following installed:

- [SFML](https://www.sfml-dev.org/download.php): The Simple and Fast Multimedia Library.
- C++ Compiler: Compatible with your system.

### Installation

1. Clone this repository to your local machine using:

   ```bash
    git clone https://github.com/drenchew/Slot-MachineGame.git
   ```

2. Navigate to the project directory:

   ```bash
   cd sfml-slot-machine
   ```

3. Compile the game using your preferred C++ compiler. For example, using g++:

   ```bash
   g++ -o slot_machine Main.cpp Reel.cpp Game.cpp Symbol.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```

4. Run the game:

   ```bash
   ./slot_machine
   ```

## How to Play

- Play with your virtual coins and spin the slot machine. Try to match the symbols to win.
- The game consists of 5 reels, each displaying different symbols.
- Payouts are determined based on the specific symbol combinations you land on the reels.

## Gameplay

- Start the game by clicking on the specified amout button.
- If the symbols align according to the payout table, you win!
- Your current balance and any winnings are displayed on-screen.

## Controls

- **Spin**: Buttons on the screen
- **Quit**: Close the game window

## Features

- Realistic slot machine simulation.
- Betting options.
- Interactive buttons for intuitive gameplay.
- Engaging sound effects and visual elements.

## Screenshots

![Screenshot 1](screenshots/screenshot1.png)
![Screenshot 2](screenshots/screenshot2.png)

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to submit a pull request. For major changes, please open an issue first to discuss the proposed changes.

## License

This project is licensed under the [MIT License](LICENSE).

---

Have fun playing the SFML Slot Machine Game! Remember, it's all about luck. Good luck, and may the reels be ever in your favor! 🎰🎉
