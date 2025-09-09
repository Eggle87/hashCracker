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
 * @brief Get the character set for a given mask character
 * @param maskChar The mask character (l, u, d, h, H, s, a, b)
 * @return Vector containing the characters for the specified mask
 */
vector<char> getCharsetForMask(char maskChar);

/**
 * @brief Apply a given ruleset to a word
 * @param input The given word to apply the ruleset to
 * @param filePath Path to the ruleset file
 * @return Vector containing all of the outputted strings
 */
vector<string> applyRuleset(string input, string filePath);

/**
 * @brief Apply a given mask to a word
 * @param input Given word to apply the mask to
 * @param mask Mask to apply
 * @param position Position of the mask 1=Before input 0=After
 * @return Vector containing all of the outputted strings
 */
vector<string> hybridProcessor(string input, string mask, int position);

/**
 * @brief Generate candidates based on a mask
 * @param mask The mask to use
 * @returns Vector containing generated candidates
*/
vector<string> maskProcessor(string mask);

#endif // WORDPROCESSOR_H

