#include <iostream>
#include "isPalindrom.h"


int main(void) {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;
    if (isPalindrom(word)) {
        std::cout << word << " is a palindrome." << std::endl;
    } else {
        std::cout << word << " is not a palindrome." << std::endl;
    }
}