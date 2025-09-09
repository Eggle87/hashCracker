#include "../include/mylib/wordProcessor.h"
#include <fstream>
#include <iostream>
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

vector<string> generateCombinations(vector<vector<char>> charsets){
    if(charsets.empty()) return {""};

    // Calculate total combinations to pre-allocate
    size_t totalCombinations = 1;
    for(const auto& charset : charsets) {
        totalCombinations *= charset.size();
    }
    
    vector<string> results;
    results.reserve(totalCombinations); // Pre-allocate memory
    
    vector<int> indices(charsets.size(),0);
    
    while(true){
        string combination;
        combination.reserve(charsets.size()); // Reserve string size
        for (int i=0;i<charsets.size();i++){
            combination+=charsets[i][indices[i]];
        }
        results.push_back(std::move(combination));
        
        int pos = charsets.size() -1; 
        while(pos >=0){
            indices[pos]++;
            if(indices[pos] < charsets[pos].size()){
                break;
            }
            indices[pos] = 0;
            pos--;
        }
        if(pos<0) break;
    }
    return results;
}


vector<string> maskProcessor(string mask) {
    // Decode mask to get character sets
    vector<vector<char>> decodedMask;
    for (int i = 1; i < mask.length(); i += 2) {
        decodedMask.push_back(getCharsetForMask(mask[i]));
    }
  
    // Generate and return all combinations
    return generateCombinations(decodedMask);
}

vector<string> hybridProcessor(string input, string mask, int position) {
    // Output vector
    vector<string> transformedWords;
    
    // Generate all mask combinations using the modular maskProcessor
    vector<string> maskCombinations = maskProcessor(mask);
    int combNum = maskCombinations.size();
    
    if(position==0){
        // Append mask to input (input + mask)
        for(int i=0;i<combNum;i++){
            transformedWords.push_back(input + maskCombinations.at(i));
        }
    } else{
        // Prepend mask to input (mask + input)
        for(int i=0;i<combNum; i++){
            transformedWords.push_back(maskCombinations.at(i) + input);
        }
    }
    return transformedWords;
}

