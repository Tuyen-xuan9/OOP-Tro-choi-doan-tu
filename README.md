# Word Guessing Game
A Hangman-style word guessing game written in **C++**, running in the terminal. Players guess letters one at a time to fill in a hidden word, with scoring, a wrong-guess counter, a timer, and hint support.

---

## 📁 Project Structure
```
├── main.cpp          # Program entry point
├── Game.h / .cpp      # Main game loop / gameplay flow controller
├── Player.h / .cpp   # Player management class (name, score, wrong guesses)
├── WordList.h / .cpp # Word list management class, reads from file
├── Utils.h / .cpp     # Utility class: screen printing, string handling, timer
└── input.txt          # List of words used in the game
```

## How to Play
1. Enter your name when prompted.
2. Press **Enter** to go to the difficulty selection menu.
3. Choose a difficulty level (`1`, `2`, or `3`).
4. On each turn, enter **1 character** to guess, or enter `?` to use a hint.
5. Guess all the letters in the word correctly to win; 7 wrong guesses means you lose.
6. After each round, enter `c` to keep playing or any other key to quit.

## Compile & Run
The project only uses the C++ standard library (STL), no external libraries required. Requires a compiler supporting C++11 or later (due to the use of `<chrono>`).

**Windows (uses `system("cls")` / `system("pause")`):**
```bash
g++ -std=c++11 main.cpp Game.cpp Player.cpp Utils.cpp WordList.cpp -o WordGuess.exe
WordGuess.exe
```
Go to the folder, click on WordGuess.exe, and start playing.

## System Requirements
- C++ compiler supporting **C++11** or later
- Operating System: **Windows**
