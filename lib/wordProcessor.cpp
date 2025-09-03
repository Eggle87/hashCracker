#include "../include/mylib/wordProcessor.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
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

vector<string> applyRuleset(string input, string filePath) {}

vector<char> getCharsetForMask(char maskChar) {
    // Default charsets (hashcat compatible)
    vector<char> lowercase = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                              'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                              's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> uppercase = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                              'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                              'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<char> hChars = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    vector<char> Hchars = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    vector<char> specialChars = {' ', '!', '"', '#', '$', '%', '&',  '\'', '(',
                                 ')', '*', '+', ',', '-', '.', '/',  ':',  ';',
                                 '<', '=', '>', '?', '@', '[', '\\', ']',  '^',
                                 '_', '`', '{', '|', '}', '~'};

    // Combined charset for ?a (all printable)
    vector<char> allPrintable;
    allPrintable.insert(allPrintable.end(), lowercase.begin(), lowercase.end());
    allPrintable.insert(allPrintable.end(), uppercase.begin(), uppercase.end());
    allPrintable.insert(allPrintable.end(), numbers.begin(), numbers.end());
    allPrintable.insert(allPrintable.end(), specialChars.begin(),
                        specialChars.end());

    // Byte charset for ?b (0x00 - 0xff)
    vector<char> byteChars;
    for (int i = 0; i <= 255; i++) {
        byteChars.push_back((char)i);
    }

    // Identify desired charset
    switch (maskChar) {
    case ('l'):
        return lowercase;
    case ('u'):
        return uppercase;
    case ('d'):
        return numbers;
    case ('h'):
        return hChars;
    case ('H'):
        return Hchars;
    case ('s'):
        return specialChars;
    case ('a'):
        return allPrintable;
    case ('b'):
        return byteChars;
    default:
        // Handle unknown mask characters
        return lowercase;
    }
}

vector<string> generateCombinations(vector<vector<char>> charsets) {
    if (charsets.empty()) return {""};
    
    vector<string> results;
    vector<int> indices(charsets.size(), 0);  // Start all at 0
    
    while (true) {
        // Build current combination
        string combination = "";
        for (int i = 0; i < charsets.size(); i++) {
            combination += charsets[i][indices[i]];
        }
        results.push_back(combination);
        
        // Increment indices 
        int pos = charsets.size() - 1;
        while (pos >= 0) {
            indices[pos]++;
            if (indices[pos] < charsets[pos].size()) {
                break;  // No carry needed
            }
            indices[pos] = 0;  // Reset and carry
            pos--;
        }
        
        if (pos < 0) break;  // All combinations generated
    }
    
    return results;
}


vector<string> hybridProcessor(string input, string mask, int position) {
    // Check mask validity

    // Output vector
    vector<string> transformedWords;
    transformedWords.push_back(input);
    // Loop through inputted mask
    int maskLen = mask.length();
    vector<vector<char>> decodedMask;
    for (int i = 1; i < maskLen; i += 2) {
        // Get charset
        decodedMask.push_back(getCharsetForMask(mask[i]));
    }
    vector<string> maskCombonations = generateCombinations(decodedMask);
    int combNum = maskCombonations.size();
    if(position=0){
        for(int i=0;i<combNum;i++)
        transformedWords.push_back(input+=maskCombonations.at(0));
    } else{
        transformedWords.push_back(maskCombonations.at(0)+=input);
    }

}