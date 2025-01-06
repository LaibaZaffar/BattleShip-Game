# Battleship Game
This project is a console-based implementation of the classic Battleship game in C++. 
It allows two players to set up their fleets and take turns guessing the locations of each other's ships on a grid.

## Features

- **Two-Player Gameplay**: Supports gameplay between two human players.
- **Computer vs Player Gameplay**: Supports gameplay between computer and human.
- **Ship Placement**: Players can place ships of varying sizes on a 10x10 grid.
- **Turn-Based Mechanics**: Players alternate turns to guess the location of the opponent's ships.
- **Hit and Miss Indicators**: The game provides feedback on whether a guess is a hit or a miss.

## Game Rules

- **Grid Size**: The game is played on a 10x10 grid for each player.
- **Ships**: Each player has the following ships:
  - 1 Aircraft Carrier (5 cells)
  - 1 Battleship (4 cells)
  - 1 Destroyer (3 cells)
  - 1 Submarine (3 cells)
  - 1 Patrol Boat (2 cells)
- **Objective**: Sink all of the opponent's ships by correctly guessing their locations before they sink yours.

## Technologies Used

- **C++**: The game is developed using standard C++ for its core logic and structure.
- **Console I/O**: Utilizes standard input and output streams for user interaction in the console.
- **Data Structures**: Uses arrays and basic data structures to manage the game grid and player states.

## Getting Started

To compile and run the game locally:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/LaibaZaffar/BattleShip-Game.git
   ```
