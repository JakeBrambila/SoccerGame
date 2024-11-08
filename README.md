

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

[Opponent Name],[Our Score]-[Opponent Score] [Shots] [Shots on Target] [Possession] [Passes] [Pass Accuracy] [Fouls] [Yellow Cards] [Red Cards] [Offsides] [Corners]
[Player 1],[Player 2],[Player 3],…,[Player 11]

# Example of `input.dat`:

Manchester City,1-1 8 3 40 414 81 11 3 0 4 6
Diogo Jota,Darwin Nunez,Mohammed Salah,Curtis Jones,Alexis Mac Allister,Dominik Szoboszlai,Kostas Tsimikas,Virgil Van Dijk,Joel Matip,Trent Alexander-Arnold,Alisson Becker
Brentford,3-0 17 10 59 504 83 16 1 0 2 6
Diogo Jota,Darwin Nunez,Mohammed Salah,Wataru Endo,Cody Gakpo,Dominik Szoboszlai,Kostas Tsimikas,Virgil Van Dijk,Joel Matip,Trent Alexander-Arnold,Alisson Becker

## 🔧 How to Use

1.	Compile the Program:
	•	Use a C++ compiler to build the program. For example, with g++:
g++ main.cpp library.cpp -o LiverpoolStats

2.	Run the Program:
	•	Execute the program:
./LiverpoolStats

3.	Input the Filename:
	•	Enter the name of the input file (e.g., input.dat) when prompted.
	4.	Choose from the Menu Options:
	•	The program displays a menu with options to view, search, sort, and modify the game data.

Example Menu
1. Display all games.
2. Search for a game.
3. Sort by Possession.
4. Display passes completed in a game.
5. Display games a specific player played in.
6. Display games with less than a certain amount of fouls.
7. Remove a game.
8. Exit.

## 🛠 Dependencies

•	Standard C++ Libraries (iostream, fstream, iomanip): For basic I/O operations.
•	Custom Header File (library.h): Contains declarations for functions used in library.cpp.


## 📌 Notes

•	File Validation: The program will prompt for a valid filename if the entered file cannot be opened.
•	Error Handling: The program validates user inputs and provides feedback for incorrect entries.

## 📄 License

This project is open-source and available for educational use.

Happy Coding!




