#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "../include/mylib/wordProcessor.h"
using namespace std;

class crackingEngine {

    private:
        string algorithm;
        vector<string> wordList;
    public:
    void setWordList(string filePath){ wordList = processFiles(filePath);}
    void setAlgorithm(string hashType){algorithm=hashType;}
};

string crackPassword(crackingEngine engine){
    cout << "Test" << endl;
}