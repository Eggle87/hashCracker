#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "../include/mylib/wordProcessor.h"
using namespace std;

vector<string> processFiles(string filePath) {
    vector<string> wordList;
    string lineText;
    
    // Open file and read line by line
    ifstream readWL(filePath);
    while (getline(readWL, lineText)) {
        wordList.push_back(lineText);
    }
    
    return wordList;
}


vector<string> applyRuleset(string input, string filePath){

}

vector<string> hybridProcessor(string input, string mask){
    //Check mask validity

    // Default charsets
    vector<char> lowercase = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    vector<char> uppercase = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<char> numbers = {'0','1','2','3','4','5','6','7','8','9'};
    vector<char> hChars = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    vector<char> Hchars = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    vector<char> specialChars = {' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[',']','^','_','`','{','|','}','~'};

    //Output vector
    vector<string> transformedWords;

    // Loop through inputted mask

    int maskLen = mask.length();
    for(int i=1;i<maskLen;i+=2){
        // Identify desired charset

        //Loop through charset
        //For each,
    }

}