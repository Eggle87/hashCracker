#ifndef CRACKING_H
#define CRACKING_H

#include <string>
#include <vector>
using namespace std;

class crackingEngine {
private:
    string algorithm;
    vector<string> wordList;
    
public:
    void setWordList(string filePath);
    void setAlgorithm(string hashType);
    vector<string> getWordList() const;
    string getAlgorithm() const;
};
string crackPassword(crackingEngine engine);

#endif // CRACKING_H
