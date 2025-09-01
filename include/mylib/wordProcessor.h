#ifndef WORDPROCESSOR_H
#define WORDPROCESSOR_H

#include <string>
#include <vector>

using namespace std;



/**
 * @brief Reads a file and returns each line as a vector of strings
 * @param filePath Path to the file to process
 * @return Vector containing each line from the file
 */
vector<string> processFiles(string filePath);


/**
 * @brief Apply a given ruleset to a word
 * @param input The given word to apply the ruleset to
 * @return Vector contianing all of the outputted strings
 */
vector<string> applyRuleset(string input, string filePath){
    
}
/**
 * @brief Apply a given mask to a word
 * @param input Given word to apply the mask to
 * @param mask Mask to apply
 * @returns Vector containing all of the ouputted strings
 */
vector<string> hybridProcessor(string input, string mask){
    
}
#endif // WORDPROCESSOR_H

