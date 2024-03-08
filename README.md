# TETRIS-Game
This project is a Tetris game implemented in C++ using the SFML library for graphics. It was developed as part of the Programming Fundamentals project.
The game is not complete and may contain some logical errors, but the code is runnable.
Use the arrow keys to move the falling blocks left, right, or down.
Press the Up arrow key to rotate the falling block.
Press the Escape key to pause the game.
In the pause screen, use the Up and Down arrow keys to select options and Enter to confirm.
Contributions to improve the game, fix bugs, or add new features are welcome. Please fork the repository, make your changes, and submit a pull request.

To download and install SFML on Ubuntu, you can follow these steps:

Update Package List: Before installing any new software, it's a good idea to update the package list to ensure you're installing the latest versions.
sudo apt update
Install SFML Libraries: SFML provides precompiled packages for Ubuntu that you can install using the package manager.
sudo apt install libsfml-dev

Compile and Run: Compile the program using g++ and link against the SFML libraries.
g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

Run the compiled executable:
./sfml-app
