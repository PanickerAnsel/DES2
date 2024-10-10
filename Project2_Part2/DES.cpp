#include "DES.h"
#include "permutation.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string permute(const string& input, const int* table, int tableSize) {
    string output = "";
    for(int i = 0; i < tableSize; ++i){
        output += input[table[i]-1]; // table indices start at 1
    }
    return output;
}

string encryption(string plaintext, vector<string> keys) {
    string permutedInput = permute(plaintext, IP, 64);
    string leftBlock = permutedInput.substr(0,32);
    string rightBlock = permutedInput.substr(32,32);

    for (int i = 0; i < keys.size(); i++){
        string newLeft = rightBlock;
        string expanded = expansion(rightBlock); 
        string xOred = XOR(expanded, keys[i], 48);
        string sBoxed = sBox(xOred);
        string pBoxed = pBox(sBoxed);
        string newRight = XOR(pBoxed, leftBlock, 32);
        rightBlock = newRight;
        leftBlock = newLeft;
    }
    
    string finalEncryption = rightBlock + leftBlock;
    string finalPermutation = permute(finalEncryption, FP, 64);
    return finalPermutation;
}

string decryption(string encrypted, vector<string> keys) {
    return " ";
}
