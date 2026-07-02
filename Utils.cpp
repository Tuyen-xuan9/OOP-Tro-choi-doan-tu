#include "Utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cctype>
using namespace std;

Timer::Timer() : isPaused(false), pausedDuration(chrono::steady_clock::duration::zero()) {}

void Timer::start() {
    startTime = chrono::steady_clock::now();
    isPaused = false;
    pausedDuration = chrono::steady_clock::duration::zero();
}

void Timer::pause() {
    if (!isPaused) {
        pausedTime = chrono::steady_clock::now();
        isPaused = true;
    }
}

void Timer::resume() {
    if (isPaused) {
        pausedDuration += (chrono::steady_clock::now() - pausedTime);
        isPaused = false;
    }
}

long long Timer::getElapsedSeconds() const {        
    auto endPoint = isPaused ? pausedTime : chrono::steady_clock::now();
    auto effective = (endPoint - startTime) - pausedDuration;
    return chrono::duration_cast<chrono::seconds>(effective).count();
}

void Utils::PrintOpeningScreen() {
    system("cls");
    cout << "***********************************\n";
    cout << "*       CHAO MUNG DEN VOI GAME    *\n";
    cout << "*             DOAN TU             *\n";
    cout << "***********************************\n";
}

void Utils::PrintDifficultyScreen() {                
    system("cls");
    cout << "***********************************\n";
    cout << "            CHON DO KHO            \n";
    cout << "***********************************\n";
    cout << "1. De (30%)\n";
    cout << "2. Trung binh (50%)\n";
    cout << "3. Kho (70%)\n";
    cout << "Lua chon: ";
}

void Utils::PrintWinScreen(int score, int wrong, long long seconds) {  
    system("cls");
    cout << "***********************************\n";
    cout << "      CHUC MUNG! BAN DA THANG!     \n";
    cout << "***********************************\n";
    cout << "Tong thoi gian choi: " << seconds << " giay.\n";
    cout << "Diem cua ban: " << score << "\n";
    cout << "So lan doan sai: " << wrong << "\n";
}

void Utils::PrintGameOverScreen(const string& word, int score, int wrong, long long seconds) { 
    system("cls");
    cout << "***********************************\n";
    cout << "             GAME OVER             \n";
    cout << "***********************************\n";
    cout << "Tu dung la: " << word << "\n";
    cout << "Tong thoi gian choi: " << seconds << " giay.\n";
    cout << "Diem cua ban: " << score << "\n";
    cout << "So lan doan sai: " << wrong << "\n";
}

void Utils::PrintEndGameScreen(int score, int wrongGuesses) {
    system("cls");
    cout << "***********************************\n";
    cout << "*            KET THUC GAME         *\n";
    cout << "***********************************\n";
    cout << "Diem so cuoi cung: " << score << endl;
    cout << "So lan doan sai: " << wrongGuesses << endl;
    cout << "Cam on ban da choi!\n";
}

char Utils::toUpper(char c) { return (char)toupper(c); }

string Utils::hideCharacters(const string& word, int difficulty) {
    int len = (int)word.length();
    if (len == 0) return "";

    float hideRate = 0.3f;
    if (difficulty == 2) hideRate = 0.5f;
    if (difficulty == 3) hideRate = 0.7f;

    int hideCount = max(1, (int)(len * hideRate));
    string hidden = word;
    vector<int> idx(len);
    for (int i = 0; i < len; ++i) idx[i] = i;

    random_shuffle(idx.begin(), idx.end());
    for (int i = 0; i < hideCount; ++i) hidden[idx[i]] = '_';
    return hidden;
}

string Utils::revealByGuess(const string& original, string hidden, char guess, int& matchedCount) {
    matchedCount = 0;
    char upperGuess = toUpper(guess);
    for (size_t i = 0; i < original.length(); ++i)
        if (hidden[i] == '_' && toUpper(original[i]) == upperGuess)
            hidden[i] = original[i], matchedCount++;
    return hidden;
}

bool Utils::isCompleted(const string& hiddenWord) {
    return hiddenWord.find('_') == string::npos;
}


