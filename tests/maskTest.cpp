#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "../include/mylib/wordProcessor.h"
using namespace std;


// WARNING THE FILE THIS MAKES WILL BE HUGE
int main(){
    string mask = "?a?a?a?a";
    vector<string> output = maskProcessor(mask);
    ofstream outFile("words.txt");
    for(int i=0;i<output.size();i++){
        outFile << output[i] << endl;
    }
}