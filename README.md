

# C++ Minesweeper Game

A command-line implementation of the classic Minesweeper game using C++ and object-oriented programming principles.

## Overview

This project is a text-based version of the classic Minesweeper game where players must uncover tiles while avoiding hidden mines. The game features colorful console output, multiple difficulty levels, and implements all four pillars of object-oriented programming.

## Features

- **Multiple Difficulty Levels:**
  - Beginner: 9x9 grid with 10 mines
  - Expert: 16x16 grid with 40 mines

- **Game Controls:**
  - Make moves by selecting row and column coordinates
  - Place flags to mark potential mine locations

- **Visual Feedback:**
  - Colorful console interface using Windows Console API
  - Blue background for the game board
  - Red background for mines
  - Green background for flags
  - Number indicators showing adjacent mines

- **Game Logic:**
  - First-move protection (you'll never hit a mine on your first move)
  - Recursive tile revealing when empty spaces are selected
  - Win/loss detection with option to play again

## Object-Oriented Design

The project demonstrates all four pillars of object-oriented programming:

1. **Abstraction:** Using an abstract Minesweeper class with pure virtual functions
2. **Encapsulation:** Protected member variables and methods for data hiding
3. **Inheritance:** Beginner and Expert classes inherit from the Minesweeper base class
4. **Polymorphism:** Override of virtual functions for different difficulty implementations

## Requirements

- Windows operating system (uses Windows.h for console colors)
- C++ compiler with C++11 or later support
- Standard C++ libraries

## How to Compile and Run

1. Compile the source code using your preferred C++ compiler:
   ```
   g++ minesweeper.cpp -o minesweeper
   ```
   
2. Run the executable:
   ```
   ./minesweeper
   ```

## How to Play

1. **Starting the Game:**
   - Press any key to open the menu screen
   - Select difficulty level:
     - Press 'B' for Beginner (9x9 grid with 10 mines)
     - Press 'E' for Expert (16x16 grid with 40 mines)
     - Press 'L' to exit the game

2. **Game Controls:**
   - Enter 'M' to make a move
   - Enter 'F' to place a flag
   - When making a move, enter the row and column numbers (0-8 for Beginner, 0-15 for Expert)

3. **Game Rules:**
   - Numbers indicate how many mines are adjacent to that tile
   - Use flags to mark potential mine locations
   - Uncover all non-mine tiles to win
   - If you uncover a mine, you lose
   - Upon running the code enter any key and a menu will appear for game movements, specify row then press enter and then column.
When you select a level you will see two boards, one is where mines are randomly generated and the other is the board you play on
you can choose not to display the MINE BOARD by commenting out code on line 420 that is :

		```
		cout << endl << endl;
		cout << "data board:" << endl;
		showMines(dataBoard);
		cout << endl << endl;
   		```	
4. **End of Game:**
   - When you win or lose, you'll be asked if you want to play again
   - Enter 'Y' to play again or 'N' to exit

## Code Structure

- **Minesweeper (Abstract Base Class):**
  - Contains common game logic and board management
  - Includes pure virtual function for setting mines

- **Beginner Class:**
  - Implements beginner difficulty-specific logic
  - 9x9 grid with 10 mines

- **Expert Class:**
  - Implements expert difficulty-specific logic
  - 16x16 grid with 40 mines

## Future Improvements

- Add intermediate difficulty level
- Implement timer functionality
- Save game statistics
- Add mouse support for tile selection
- Implement a graphical user interface

## License

This project is open for educational purposes. Feel free to modify and distribute it according to your needs.
# Minesweeper-



