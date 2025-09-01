#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "../include/mylib/cracking.h"
#include "../include/mylib/wordProcessor.h"
using namespace std;

// Implementation of crackingEngine methods
void crackingEngine::setWordList(string filePath) {
    wordList = processFiles(filePath);
}

void crackingEngine::setAlgorithm(string hashType) {
    algorithm = hashType;
}

vector<string> crackingEngine::getWordList() const {
    return wordList;
}

string crackingEngine::getAlgorithm() const {
    return algorithm;
}

// Main cracking function
string crackPassword(crackingEngine engine) {
    cout << "Starting crack with " << engine.getWordList().size() << " words" << endl;
    // TODO: Add actual cracking logic
    return "";
}