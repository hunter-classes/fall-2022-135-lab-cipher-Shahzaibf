#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <cfloat>
#include "funcs.h"

// add functions here
double distanceformula(double arr[26], double stagnant[26]) {
	double total = 0;
	for (int i = 0;i < 26;i++) {
		total += pow((arr[i]-stagnant[i]),2);
	}
	return sqrt(total);
}

char shiftChar(char c, int rshift){
    int shiftedc = c + rshift;
    if(c >= 65 && c <= 90){
        if(shiftedc < 65){
            return shiftedc + 26;
        }
        if(shiftedc > 90){
            return shiftedc - 26;
        }
        return shiftedc;
    }
    if(c >= 97 && c <= 122){
        if(shiftedc < 97){
            return shiftedc + 26;
        }
        if(shiftedc > 122){
            return shiftedc - 26;
        }
        return shiftedc;
    }
    return c;
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string result;
    for (int i = 0; i < plaintext.length();i++){
        result += shiftChar(plaintext[i],rshift);
    }
    return result;
}

std::string decryptCaesar(std::string ciphertext, int rshift) {
    std::string result;
    for(int i = 0;i < ciphertext.length(); i++){
        result+= shiftChar(ciphertext[i], rshift * -1);
    }
    return result;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
    std::string result;
    char letters[keyword.length()];
    for(int i = 0; i < keyword.length(); i++){
        letters[i] = keyword[i];
    }
    int count = -1;
    for(int i = 0; i < ciphertext.length();i++){
        if(isalpha(ciphertext[i])){
            count++;
            result += shiftChar(ciphertext[i], (((int)letters[count % keyword.length()] - 97) * -1));
        } else{
            result += ciphertext[i];
        }
    }
    return result;
}

std::string encryptVigenere(std::string plaintext, std::string keyword) {
    int count = 0;
    std::string result;
    for(int i = 0; i < plaintext.size(); i++) {
        char letter;
        char current = plaintext[i];
        if(isalpha(current)) {
            char key = keyword[count];
            letter = shiftChar(current, key-'a');
            count++;
            count = count % keyword.size();
        } else {
            letter = current;
        }
        result += letter;
      }
    return result;
}
void helper(double instances[][26], std::string input) {
	for (int i = 0; i < 26; i++) {
		int count = 0;
		std::string test = encryptCaesar(input,i);
		for (char c: test) {
			if ((!isspace(c))&&(isalpha(c))) {
				instances[i][tolower(c)-'a']++;
				count++;
			} 
            }
		for (int j = 0; j < 26; j++) {
			instances[i][j]=instances[i][j]/count;
		}
	}
}
std::string solve(std::string encrypted_string) {
	double freq[26]={0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};
	double arr[26][26];
	for (int a = 0; a <26; a++){
        for (int b = 0; b < 26; b++){
            arr[a][b]=0;
        }
    }	
	helper(arr, encrypted_string);
	double min = distanceformula(arr[0],freq);
	int rot = 0;
	for (int i = 1; i < 26; i++) {
		double result = distanceformula(arr[i],freq);
		if (min > result) {
			min = result;
			rot = i;
		}
	}
	return encryptCaesar(encrypted_string,rot);
}