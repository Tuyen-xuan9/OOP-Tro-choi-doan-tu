#pragma once
#include <string>
#include <set>
#include "WordList.h"
#include "Player.h"
#include "Utils.h"
using namespace std;

class Game {
private:
    WordList wordList;
    Player player;
    string originalWord;
    string hiddenWord;
    int difficulty;

    set<char> guessedLetters;
    Timer gameTimer;

    bool useHint();                   

public:
    Game();
    bool init(const string& file);
    void setDifficulty();
    void start();
    void update();
    void draw();
    bool isWin();

    void run();
};


