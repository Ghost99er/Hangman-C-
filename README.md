Hangman Game

This is a command-line Hangman game implemented in C++. The game allows players to guess a hidden word, with each incorrect guess resulting in the progressive drawing of a hangman. The game also features a detailed background illustration to make it more visually engaging.

Features
Interactive command-line interface.
Word guessing with a limited number of attempts.
Enhanced background illustration including hangman and some environmental details.
Option to play again or exit after the game ends.
Demonstrates C++ concepts such as classes, inheritance, virtual functions, and STL containers.
Handles both uppercase and lowercase letter guesses.

Installation

Clone the Repository:

git clone https://github.com/yourusername/hangman-game.git
cd hangman-game

Compile the Program:

g++ -o hangman HangmanGame.cpp

Run the Game:

./hangman

Gameplay Instructions:

The game will display a series of underscores representing the hidden word.
Guess letters one at a time by entering a character and pressing Enter.
Each correct guess reveals the positions of the letter in the word.
Each incorrect guess progresses the hangman drawing.
The game ends when the word is guessed correctly or the hangman is fully drawn.
After the game ends, you have the option to play again or exit.
Game Mechanics
Attempts: Players have 6 incorrect guesses before the game ends.
Letters: Both uppercase and lowercase letters are accepted.
Win Condition: The game is won by guessing all letters in the word.
Lose Condition: The game is lost if the player makes 6 incorrect guesses.

Dependencies
Compiler: GCC or any C++ compiler supporting C++11 or later.

Contributing
Fork the repository.
Create a new branch: git checkout -b feature-branch.
Make your changes and commit them: git commit -m 'Add new feature'.
Push to the branch: git push origin feature-branch.
Submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.
