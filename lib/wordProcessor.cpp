#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<string> processFiles(string filePath){
    vector<string> wordList;
    string lineText;
    ifstream readWL(filePath);
    while(getline(readWL,lineText)){
        wordList.push_back(lineText);
    }
    return wordList;
}
