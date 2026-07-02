#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player {
private:
    string name;
    int score;
    int wrongGuesses;

public:
    Player();
    void inputName();
    char inputChar();
    int inputInt();

    void addScore(int points);
    void addWrong(int count = 1);
    void reset();          
    void resetRound();     
    void showScore() const;

    string getName() const;
    int getScore() const;
    int getWrongGuesses() const;

    friend ostream& operator<<(ostream& os, const Player& player);
};



