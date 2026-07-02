#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include <set>
#include <vector>
using namespace std;

Game::Game() {
    srand((unsigned)time(NULL));
    difficulty = 1;
}

bool Game::init(const string& file) {
    Utils::PrintOpeningScreen();  
    player.inputName();            
    cout << "Nhan Enter de vao menu do kho...";
    cin.get();                    
    return wordList.loadFromFile(file);
}


void Game::setDifficulty() {
    Utils::PrintDifficultyScreen();  
    difficulty = player.inputInt();
    if (difficulty < 1 || difficulty > 3) difficulty = 1;
}

void Game::start() {
    originalWord = wordList.getRandomWord();
    if (originalWord.empty()) {
        cout << "Loi: Khong con tu nao de doan!\n";
        return;
    }
    hiddenWord = Utils::hideCharacters(originalWord, difficulty);
    guessedLetters.clear();
}

bool Game::useHint() {
    if (player.getScore() < 5) {
        cout << "\n❗ Ban chua du 5 diem de dung hint!\n";
        cout << "   (Moi lan dung hint se tru 5 diem.)\n";
        system("pause");
        return false;
    }
    vector<int> hiddenIdx;
    for (int i = 0; i < (int)hiddenWord.size(); ++i)
        if (hiddenWord[i] == '_') hiddenIdx.push_back(i);

    if (hiddenIdx.empty()) {
        cout << "Khong con ky tu nao de goi y!\n";
        return false;
    }

    int pick = Utils::GetRandomNumber(0, (int)hiddenIdx.size() - 1);
    int pos = hiddenIdx[pick];
    char revealed = originalWord[pos];
    hiddenWord[pos] = revealed;

    guessedLetters.insert(Utils::toUpper(revealed));

    player.addScore(-5);   
    cout << "Hint: da mo ky tu o vi tri " << (pos + 1) << " -> '" << revealed << "' (-5 diem)\n";
    return true;
}

void Game::update() {
    cout << "(Nhap '?' de dung HINT, -5 diem)\n";
    char guess = player.inputChar();
    guess = Utils::toUpper(guess);

    if (guess == '?') {           
        useHint();
        return;
    }

    if (guessedLetters.count(guess)) {
        cout << "Ban da doan ky tu '" << guess << "' roi!\n";
        return;
    }
    guessedLetters.insert(guess);

    int matchedCount = 0;
    string newHidden = Utils::revealByGuess(originalWord, hiddenWord, guess, matchedCount);

    if (matchedCount > 0) {
        cout << "Chinh xac! Tim thay " << matchedCount << " ky tu.\n";
        player.addScore(matchedCount * 5);
        hiddenWord = newHidden;
    }
    else {
        cout << "Rat tiec, khong co ky tu '" << guess << "'!\n";
        player.addWrong(1);
    }
}

void Game::draw() {
    system("cls");
    cout << "***********************************\n";
    cout << "           TRO CHOI DOAN TU        \n";
    cout << "***********************************\n";

    cout << "Nguoi choi: " << player.getName() << "\n";
    cout << "\nTu can doan:\n   " << hiddenWord << "\n\n";
    player.showScore();

    cout << "Da doan: ";
    if (guessedLetters.empty()) cout << "(Chua doan ky tu nao)";
    else for (char c : guessedLetters) cout << c << ' ';
    cout << "\n-----------------------------------\n";
}

bool Game::isWin() { return Utils::isCompleted(hiddenWord); }

void Game::run() {
    if (!init("input.txt")) {
        cout << "Khong load duoc file input.txt!\n";
        return;
    }

    player.reset();           

    bool playAgain = true;
    while (playAgain) {
        setDifficulty();
        player.resetRound();  
        start();

        gameTimer.start();    

        while (!isWin()) {
            draw();
            update();
            if (player.getWrongGuesses() >= 7) {
                gameTimer.pause();
                Utils::PrintGameOverScreen(
                    originalWord,
                    player.getScore(),
                    player.getWrongGuesses(),
                    gameTimer.getElapsedSeconds()           
                );
                break;
            }
        }

        if (isWin()) {
            gameTimer.pause();
            Utils::PrintWinScreen(
                player.getScore(),
                player.getWrongGuesses(),
                gameTimer.getElapsedSeconds()                
            );
        }

        cout << "\nBan co muon choi tiep? (nhap 'c' de tiep tuc, phim khac de ket thuc): ";
        char choice = player.inputChar();
        playAgain = (choice == 'c' || choice == 'C');
    }

    Utils::PrintEndGameScreen(player.getScore(), player.getWrongGuesses());
    player.reset(); 
}

