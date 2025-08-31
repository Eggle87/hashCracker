#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../include/mylib/wordProcessor.h"
using namespace std;

int main(){
    string fp="src/wordLists/test.txt";  // Relative to where we run the executable
    vector<string> lines = processFiles(fp);
    for(int i=0;i<lines.size();i++){
        cout << lines.at(i) << endl;
    }
    return 0;
}