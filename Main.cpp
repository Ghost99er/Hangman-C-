#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Game {
public:
    virtual bool isGameOver() = 0;
};

class HangmanGame : public Game {
private:
    std::string secretWord;
    std::vector<char> guessedLetters;
    int attemptsLeft;

    void initialize() {
        std::vector<std::string> words = { "hangman", "computer", "programming", "awesome", "gaming", "banana" };
        srand(static_cast<unsigned int>(time(0)));
        int randomIndex = rand() % words.size();
        secretWord = words[randomIndex];
        attemptsLeft = 6; // Number of attempts before game over
    }

    void displayWord() {
        for (char letter : secretWord) {
            if (std::find(guessedLetters.begin(), guessedLetters.end(), std::tolower(letter)) != guessedLetters.end()) {
                std::cout << letter << " ";
            }
            else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }

    void displayHangman(int attemptsLeft) {
        // Background
        std::cout << "   _____" << std::endl;
        std::cout << "  /     \\" << std::endl;
        std::cout << " |       |";
        if (attemptsLeft <= 6)
            std::cout << "   O";
        std::cout << std::endl;
        std::cout << " |      ";
        if (attemptsLeft <= 5)
            std::cout << "/";
        if (attemptsLeft <= 4)
            std::cout << "|";
        if (attemptsLeft <= 3)
            std::cout << "\\";
        std::cout << std::endl;
        std::cout << " |      ";
        if (attemptsLeft <= 2)
            std::cout << "/";
        if (attemptsLeft <= 1)
            std::cout << " \\";
        std::cout << std::endl;
        std::cout << " |" << std::endl;
        std::cout << "=========" << std::endl;
    }

public:
    HangmanGame() {
        initialize();
    }

    bool isGameOver() override {
        if (attemptsLeft <= 0) {
            std::cout << "Game over! The word was: " << secretWord << std::endl;
            return true;
        }
        for (char letter : secretWord) {
            if (std::find(guessedLetters.begin(), guessedLetters.end(), std::tolower(letter)) == guessedLetters.end()) {
                return false;
            }
        }
        std::cout << "Congratulations! You guessed the word: " << secretWord << std::endl;
        return true;
    }

    void play() {
        while (!isGameOver()) {
            std::cout << "Attempts left: " << attemptsLeft << std::endl;
            displayWord();
            displayHangman(attemptsLeft);
            std::cout << "Guess a letter: ";
            char guess;
            std::cin >> guess;
            guessedLetters.push_back(std::tolower(guess));
            if (secretWord.find(std::tolower(guess)) == std::string::npos) {
                std::cout << "Incorrect guess!" << std::endl;
                attemptsLeft--;
            }
        }
    }
};

int main() {
    bool playAgain = true;
    while (playAgain) {
        HangmanGame game;
        game.play();
        std::cout << "Do you want to play again? (yes/no): ";
        std::string choice;
        std::cin >> choice;
        if (choice != "yes") {
            playAgain = false;
        }
    }
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}