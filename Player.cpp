#include "Player.h"
#include <iostream>
#include <limits>   
using namespace std;

Player::Player() {
    name = "Player 1"; 
    score = 0;
    wrongGuesses = 0;
}

void Player::inputName() {
    cout << "Nhap ten cua ban: ";
    string line;
    getline(cin >> ws, line);       
    name = line.empty() ? "Player 1" : line;
}

char Player::inputChar() {
    cout << "\n>>> Doan 1 ky tu: ";
    char c;
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return c;
}

int Player::inputInt() {
    int value;
    while (!(cin >> value)) {
        cout << "Vui long nhap mot SO: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    return value;
}

void Player::addScore(int points) {
    this->score += points;
}

void Player::addWrong(int count) {
    this->wrongGuesses += count;
}

void Player::showScore() const {
    cout << "Diem: " << score << " | So lan doan sai: " << wrongGuesses << endl;
}

string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

int Player::getWrongGuesses() const {
    return wrongGuesses;
}

void Player::reset() {
    score = 0;
    wrongGuesses = 0;
}
void Player::resetRound() {          
    wrongGuesses = 0;
}

ostream& operator<<(ostream& os, const Player& player) {
    os << "Nguoi choi: " << player.name
        << " | Diem: " << player.score
        << " | Sai: " << player.wrongGuesses;
    return os;
}


