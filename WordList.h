#pragma once
#include <string>
#include <vector>
using namespace std;

class WordList {
private:
    vector<string> words;

public:
    WordList();
    bool loadFromFile(const string& filename);
    string getRandomWord() const;
    void addWord(const string& w);
    void removeWord(const string& w);
    void showAll() const;
    int getSize() const;
};