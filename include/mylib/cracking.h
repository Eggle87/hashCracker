#ifndef CRACKING_H
#define CRACKING_H

#include <string>
#include <vector>
using namespace std;

/**
 * @brief Password cracking engine class
 */
class crackingEngine {
private:
    string algorithm;        // Hash algorithm to use
    vector<string> wordList; // Word list for dictionary attacks
    
public:
    /** @brief Load word list from file */
    void setWordList(string filePath);
    
    /** @brief Set hash algorithm */
    void setAlgorithm(string hashType);
    
    /** @brief Get current word list */
    vector<string> getWordList() const;
    
    /** @brief Get current algorithm */
    string getAlgorithm() const;
};

/** @brief Attempt to crack password using engine */
string crackPassword(crackingEngine engine);

#endif // CRACKING_H
