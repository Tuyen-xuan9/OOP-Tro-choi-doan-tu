#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

class Timer {
private:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point pausedTime;
    chrono::steady_clock::duration pausedDuration;
    bool isPaused;

public:
    Timer();
    void start();
    void pause();
    void resume();
    long long getElapsedSeconds() const;   
};

class Utils {
public:
    static void PrintOpeningScreen();
    static void PrintDifficultyScreen();   
    static void PrintWinScreen(int score, int wrong, long long seconds);        
    static void PrintGameOverScreen(const string& word, int score, int wrong, long long seconds); 
    static void PrintEndGameScreen(int score, int wrongGuesses);

    template<class T>
    static T GetRandomNumber(const T& min, const T& max) {
        return (T)(rand() % (max - min + 1) + min);
    }
    static char toUpper(char c);
    static string hideCharacters(const string& word, int difficulty);
    static string revealByGuess(const string& original, string hidden, char guess, int& matchedCount);
    static bool isCompleted(const string& hiddenWord);
};



