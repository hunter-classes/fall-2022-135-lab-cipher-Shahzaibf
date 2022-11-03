#include <iostream>
#include "funcs.h"

// add functions here

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

std::string solve(std::string encrypted_string) {
    
}