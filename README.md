# Liverpool Game Statistics Tracker

This project is a console-based C++ application for managing and displaying game statistics for Liverpool FC. Users can load game data from a file, view all games, search for specific games, sort games by possession, and display statistics based on different criteria. The project demonstrates data structures, file I/O, sorting, and searching in C++.

## 📋 Project Structure

The project consists of two main files:

- **`main.cpp`**: Contains the main function which handles user interaction and calls functions from `library.cpp` based on the user's choices.
- **`library.cpp`**: Implements the core functionality, including loading data from a file, displaying game statistics, searching, sorting, and filtering games.

## 🚀 Features

1. **Load Game Data**: 
   - Loads game data from an external file `input.dat`, including stats such as score, shots, possession, passes, fouls, and lineups.
2. **Display All Games**: 
   - Shows statistics for all loaded games.
3. **Search for a Game**: 
   - Allows the user to search for a game by opponent's name and displays the relevant statistics.
4. **Sort Games by Possession**: 
   - Sorts games by possession percentage in descending order.
5. **Calculate Passes Completed**: 
   - Calculates and displays passes completed for a specific game based on passing accuracy.
6. **List Games Played by a Player**: 
   - Displays all games a specific player participated in.
7. **Filter Games by Fouls**: 
   - Displays games with fewer than a specified number of fouls.
8. **Remove a Game**: 
   - Permanently removes a game from the list by opponent’s name.

## 📝 Input File Format

The application reads data from an `input.dat` file, where each line represents a game with comma-separated values. The format for each game is as follows:



