#include "WordList.h"
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

WordList::WordList() {
    srand((unsigned int)time(0));
}

bool WordList::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) return false;

    words.clear();
    string word;
    while (fin >> word) {
        words.push_back(word);
    }
    fin.close();
    return true;
}

string WordList::getRandomWord() const {
    if (words.empty()) return "";
    int index = rand() % words.size();
    return words[index];
}

void WordList::addWord(const string& w) {
    words.push_back(w);
}

void WordList::removeWord(const string& w) {
    auto it = find(words.begin(), words.end(), w);
    if (it != words.end()) {
        words.erase(it);
    }
}

void WordList::showAll() const {
    for (const auto& w : words) {
        cout << w << endl;
    }
}

int WordList::getSize() const {
    return static_cast<int>(words.size());
}
